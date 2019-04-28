/******************************************************************************
* Copyright (c) 2000-2019 Ericsson Telecom AB AB
* All rights reserved. This program and the accompanying materials
* are made available under the terms of the Eclipse Public License v2.0
* which accompanies this distribution, and is available at
* https://www.eclipse.org/org/documents/epl-2.0/EPL-2.0.html
*
* Contributors:
*   Eduard Czimbalmos
*   Eszter Susanszky
******************************************************************************/
//
//  File:               HTTP_MessageLen_Function.cc
//  Rev:                R1D
//  Prodnr:             CNL113796
//  Contact:            http://ttcn.ericsson.se

#include "HTTP_Types.hh"
#include "HTTP_MessageLen.hh"
#include <string>
#include <stdio.h>
#include <strings.h>
#include <ctype.h>


using namespace HTTP__Types;

namespace HTTP__MessageLen {

  enum ReqResp {request, response, def};
  enum Transfer_Encoding {chunked, notchunked, none};

  // return the length of the first line in the buffer including the \r\n
  // So 2 is returned for empty line
  // -1 if there is no \r\n in the buffer
  // handles the line folding if needed

  int get_http_line(const char *buff, int length, bool folding=false){
    int ret_val=0;  // store the length of the line
    bool end_found=false; // is the line ending found? 
    while(length>0){
      ret_val++;
      length--;
      if(*buff == '\n'){
        if( !folding || !((length>0) && (buff[1] == ' ' || buff[1] == '\t')) ){  // not line folding. ie the \n is not followed with space or tab
          end_found=true;  // this is the end of the line
          break;
        }
      }
      buff++;
    }
    return end_found?ret_val:-1;
  }
  
  INTEGER f_HTTPMessage_len_common(
      const OCTETSTRING& pl__stream,
      const boolean connClosed,
      const boolean head_req,
      const boolean connect_req)
  {
    int stream_length = pl__stream.lengthof();
    if(stream_length < 16) return -1;  
    // The smallest syntatically correct HTTP message is:
    // A / HTTP/0.0\r\n\r\n
    // Which is 16 octet
    
    const char *stream=(const char *)(const unsigned char *)pl__stream;
    int line_length=-1;
    int resp_code=0;
    bool is_request=false;
    bool is_chunked=false;
    int content_length=-1;
    
    // skeep leading /r/n
    // there should'n be any but be conservative
    while((line_length=get_http_line(stream,stream_length))==2){
      stream+=line_length;
      stream_length-=line_length;
    }
    if(line_length==-1){ // there is no whole line in the buffer
      return -1;
    }
    // parse the header line
    {
      std::string str(stream,line_length);
      if(sscanf(str.c_str(),"HTTP/%*d.%*d %d ",&resp_code)==1){
        // response received
        is_request=false;
      } else {
        // it should be a request
        is_request=true;
      }
    }
    stream+=line_length;
    stream_length-=line_length;

    // search for the end of the headers
    while((line_length=get_http_line(stream,stream_length,true))!=2){
      if(line_length==-1){ // there is no whole line in the buffer
        return -1;
      }
      // check for specific headers
      // Content-Length
      if((line_length>17) && (strncasecmp(stream, "Content-Length:", 15) == 0) ){ // the minimum length of the Content-Length is 18: 15 (Content-Length:) + at least 1 digit + crlf
        content_length = (int)strtol(stream+15, NULL, 10);
      }
      if((line_length>26) && (strncasecmp(stream, "Transfer-Encoding:", 18) == 0) ){ // the minimum length 27: 18 (Transfer-Encoding:) + 7 (chunked) + crlf
        std::string str(stream+18,line_length-18); // just the data part
        if(str.find("chunked")!=std::string::npos){
          is_chunked=true;
        }
      }
      stream+=line_length;
      stream_length-=line_length;
    }
    
    // skip the empty line
    stream+=line_length;
    stream_length-=line_length;
    
    // See RFC7230 3.3.3
    if( !is_request && ( head_req || (resp_code==204) || (resp_code==304)  || (resp_code>=100  && resp_code<=199))){ // See RFC7230 3.3.3 1.
      // no body
      const char *stream_begin=(const char *)(const unsigned char *)pl__stream;
      return stream-stream_begin;
    } else if(!is_request && connect_req && (resp_code>=200  && resp_code<=299)){ // See RFC7230 3.3.3 2.
      // no body
      const char *stream_begin=(const char *)(const unsigned char *)pl__stream;
      return stream-stream_begin;
    } else if(is_chunked){ // See RFC7230 3.3.3 3.
      int chunk_length=-1;
      if((line_length=get_http_line(stream,stream_length))==-1){
        return -1;
      }
      chunk_length=(int)strtol(stream, NULL, 16);
      stream+=line_length;
      stream_length-=line_length;
      while(chunk_length>0){
        if(chunk_length<=stream_length){ // skip the chunk data
          stream+=chunk_length;
          stream_length-=chunk_length;
        }
        // read the CRLF
        if((line_length=get_http_line(stream,stream_length))!=2){
          return -1;
        }
        stream+=line_length;
        stream_length-=line_length;
        // read the next chunk size
        if((line_length=get_http_line(stream,stream_length))==-1){
          return -1;
        }
        chunk_length=(int)strtol(stream, NULL, 16);
        stream+=line_length;
        stream_length-=line_length;
      }
      // skip trailers
      while((line_length=get_http_line(stream,stream_length))!=2){
        if(line_length==-1){ // there is no whole line in the buffer
          return -1;
        }
        stream+=line_length;
        stream_length-=line_length;
      }
      // skip the final CRLF
      stream+=line_length;
      stream_length-=line_length;
      const char *stream_begin=(const char *)(const unsigned char *)pl__stream;
      return stream-stream_begin;
    } else if(content_length>=0){ // See RFC7230 3.3.3 5.
      const char *stream_begin=(const char *)(const unsigned char *)pl__stream;
      return stream-stream_begin+content_length;
    } else if(is_request){ // See RFC7230 3.3.3 6.
      const char *stream_begin=(const char *)(const unsigned char *)pl__stream;
      return stream-stream_begin;
    } else if(connClosed){ // See RFC7230 3.3.3 7.
      return pl__stream.lengthof();
    }
    
    return -1;

  }

  INTEGER ef__HTTPMessage__len(const OCTETSTRING& pl__stream)
  {
    return(f_HTTPMessage_len_common(pl__stream, false,false,false));
  }

  INTEGER ef__HTTPMessage__len__forConnectResp(const OCTETSTRING& pl__stream)
  {
    return(f_HTTPMessage_len_common(pl__stream, false,false,true));
  }

  INTEGER ef__HTTPMessage__len__forHeadResp(const OCTETSTRING& pl__stream)
  {
    return(f_HTTPMessage_len_common(pl__stream, false,true,false));
  }

  INTEGER ef__HTTPMessage__len__forConnClosed(const OCTETSTRING& pl__stream)
  {
    return(f_HTTPMessage_len_common(pl__stream, true,false,false));
  }

}
