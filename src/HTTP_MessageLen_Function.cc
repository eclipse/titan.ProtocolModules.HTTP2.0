/******************************************************************************
* Copyright (c) 2015  Ericsson AB
* All rights reserved. This program and the accompanying materials
* are made available under the terms of the Eclipse Public License v1.0
* which accompanies this distribution, and is available at
* http://www.eclipse.org/legal/epl-v10.html
*
* Contributors:
*   Eszter Susanszky
******************************************************************************/
//
//  File:               HTTP_MessageLen_Function.cc
//  Rev:                R1C
//  Prodnr:             CNL113796
//  Contact:            http://ttcn.ericsson.se

#include "HTTP_Types.hh"
#include "HTTP_MessageLen.hh"
//#include <stdlib.h>

using namespace HTTP__Types;

namespace HTTP__MessageLen {
  
  enum ReqResp {request, response, def};
  enum Transfer_Encoding {chunked, notchunked, none};
  
  INTEGER ef__HTTPMessage__len(const OCTETSTRING& pl__stream)
  {
    int stream_length = pl__stream.lengthof();
    if(stream_length < 0) return -1;

    int content_length = 0;
    int end_of_startline = 0;
    int end_of_headers = 0;
    int end_of_te = 0;
    int end_of_msg = 0;
    int end_of_chunklngth = 0;

    ReqResp reqresp = def;
    Transfer_Encoding te = none;
    
    const unsigned char* streamptr = pl__stream;
    const unsigned char* ptr = pl__stream;
    const CHARSTRING crlf = "\r\n";
    const CHARSTRING crlfcrlf = "\r\n\r\n";
    
    // go to the end of stream, stop if end of startline found
    while(ptr-streamptr + 2 <= stream_length && end_of_startline == 0)      
    {
      if(memcmp(ptr, (const char*)crlf, 2) == 0) end_of_startline = 1;
      else ptr++;
    }
    
    // startline hasn't arrived
    if(end_of_startline == 0) return -1;
    else ptr += 2;
    
    //check if request or response
    if(memcmp(streamptr, "HTTP/", 5) == 0 ) reqresp = response; else reqresp = request;
    
    // \r\n\r\n -> empty header list, return -1
    if(memcmp(ptr, (const char*)crlf, 2) == 0 ) return -1;
    
    while(ptr-streamptr + 4 <= stream_length && end_of_headers == 0)
    {
      if(memcmp(ptr, (const char*)crlfcrlf, 4) == 0 ) {end_of_headers = 1;}
      else
      {
        if(ptr-streamptr + 15 <= stream_length && strncasecmp((const char*)ptr, "Content-Length:", 15) == 0)
        {
          ptr+= 15;
          content_length = (int)strtol((const char*)ptr, NULL, 10); 
        } else if(ptr-streamptr + 18 <= stream_length && strncasecmp((const char*)ptr, "Transfer-Encoding:", 18) == 0)
        {
          te = notchunked;
          ptr += 18;
          
          while(end_of_te == 0)
          {
            if(ptr-streamptr + 2 <= stream_length && memcmp(ptr, (const char*)crlf, 2) == 0 ) {end_of_te = 1; ptr += 2;}
            else if(ptr-streamptr + 9 <= stream_length && !strncasecmp((const char*)ptr, "chunked\r\n", 9)) {te = chunked; end_of_te = 1; ptr += 9;}   //chunked/r/n (last encoding is chunked)
            else { ptr++; }
          }
        
          if(end_of_te == 0) return -1;
        } else ptr++;
      }
    }
    
    if(end_of_headers == 0) return -1;
    else ptr += 4;
    
    if( te == none) {
    
      if(content_length > 0) return ptr-streamptr + content_length;
      else if( reqresp == request ) return ptr-streamptr;
      else if( reqresp == response ) return -1;
      
    } else if(te == notchunked) {
    
      if( reqresp == request ) return ptr-streamptr;
      else return -1;
      
    } else if(te == chunked) {
      
      const unsigned char* chunksize_ptr = ptr;
      while(ptr-streamptr + 2 <= stream_length && end_of_chunklngth == 0)
      {
        if(memcmp(ptr, (const char*)crlf, 2) == 0) end_of_chunklngth = 1;
        else ptr++;
      }
      if(end_of_chunklngth == 0) return 0;
      
      int chunk_length = (int)strtol((const char*)chunksize_ptr, NULL, 16);
      
      while(chunk_length != 0 && ptr-streamptr <= stream_length)
      {
        end_of_chunklngth = 0;
        
        // chunksize + \r\n + next char
        ptr += chunk_length + 2 + 1;
        
        chunksize_ptr = ptr;
        while(ptr-streamptr + 2 <= stream_length && end_of_chunklngth == 0)
        {
          if(memcmp(ptr, (const char*)crlf, 2) == 0) end_of_chunklngth = 1;
          else ptr++;
        }
        if(end_of_chunklngth == 0) return -1;
        else chunk_length = (int)strtol((const char*)chunksize_ptr, NULL, 16);
      }
      if(chunk_length > 0) return -1;
      
      //find \r\n\r\n
      while(ptr-streamptr + 4 <= stream_length && end_of_msg == 0)
      {
        if( memcmp(ptr, (const char*)crlfcrlf, 4) == 0) end_of_msg = 1;
        else ptr++;
      }
      if(end_of_msg == 0) return -1;
      
      return ptr+4-streamptr;
    }
    
    return -1;
  }
}
