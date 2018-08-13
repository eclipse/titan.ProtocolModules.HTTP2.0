/******************************************************************************
* Copyright (c) 2000-2018 Ericsson Telecom AB AB
* All rights reserved. This program and the accompanying materials
* are made available under the terms of the Eclipse Public License v2.0
* which accompanies this distribution, and is available at
* https://www.eclipse.org/org/documents/epl-2.0/EPL-2.0.html
*
* Contributors:
******************************************************************************/
//
//  File:               HTTP_EncDec.cc
//  Rev:                R1D
//  Prodnr:             CNL113796
//  Contact:            http://ttcn.ericsson.se
//  Reference:          RFC7230 - RFC7235

#include "HTTP_Types.hh"
#include <string.h>

namespace HTTP__Types
{
  void f_Encode_Headers(const HTTP__Headers& pl_headers, TTCN_Buffer& pl_buff, const CHARSTRING& pl_content_length)
  {
    if(pl_headers.accept().ispresent())
    {
      int nr_of_fields = pl_headers.accept()().size_of();
      for(int i = 0; i < nr_of_fields; i++)
      {
        pl_buff.put_s(8,(const unsigned char*)"Accept: ");
        int nr_of_elems = pl_headers.accept()()[i].size_of();
        for(int j = 0; j < nr_of_elems; j++)
        {
          if(j > 0 ) pl_buff.put_s(2,(const unsigned char*)", ");
          pl_buff.put_string(pl_headers.accept()()[i][j]);
        }
        pl_buff.put_s(2,(const unsigned char*)"\r\n");
      }
    }
    
    if(pl_headers.accept__charset().ispresent())
    {      
      int nr_of_fields = pl_headers.accept__charset()().size_of();
      for(int i = 0; i < nr_of_fields; i++)
      {
        pl_buff.put_s(16,(const unsigned char*)"Accept-Charset: ");
        int nr_of_elems = pl_headers.accept__charset()()[i].size_of();
        for(int j = 0; j < nr_of_elems; j++)
        {
          if(j > 0 ) pl_buff.put_s(2,(const unsigned char*)", ");
          pl_buff.put_string(pl_headers.accept__charset()()[i][j]);
        }        
        pl_buff.put_s(2,(const unsigned char*)"\r\n");
      }
    }
    
    if(pl_headers.accept__encoding().ispresent())
    {
      int nr_of_fields = pl_headers.accept__encoding()().size_of();
      for(int i = 0; i < nr_of_fields; i++)
      {
        pl_buff.put_s(17,(const unsigned char*)"Accept-Encoding: ");
        int nr_of_elems = pl_headers.accept__encoding()()[i].size_of();
        for(int j = 0; j < nr_of_elems; j++)
        {
          if(j > 0 ) pl_buff.put_s(2,(const unsigned char*)", ");
          pl_buff.put_string(pl_headers.accept__encoding()()[i][j]);
        }
        pl_buff.put_s(2,(const unsigned char*)"\r\n");
      }
    }
    
    if(pl_headers.accept__language().ispresent())
    {
      int nr_of_fields = pl_headers.accept__language()().size_of();
      for(int i = 0; i < nr_of_fields; i++)
      {
        pl_buff.put_s(17,(const unsigned char*)"Accept-Language: ");
        int nr_of_elems = pl_headers.accept__language()()[i].size_of();
        for(int j = 0; j < nr_of_elems; j++)
        {
          if(j > 0 ) pl_buff.put_s(2,(const unsigned char*)", ");
          pl_buff.put_string(pl_headers.accept__language()()[i][j]);
        }
        pl_buff.put_s(2,(const unsigned char*)"\r\n");
      }
    }
    
    if(pl_headers.accept__ranges().ispresent())
    {
      int nr_of_fields = pl_headers.accept__ranges()().size_of();
      for(int i = 0; i < nr_of_fields; i++)
      {
        pl_buff.put_s(15,(const unsigned char*)"Accept-Ranges: ");
        int nr_of_elems = pl_headers.accept__ranges()()[i].size_of();
        for(int j = 0; j < nr_of_elems; j++)
        {
          if(j > 0 ) pl_buff.put_s(2,(const unsigned char*)", ");
          pl_buff.put_string(pl_headers.accept__ranges()()[i][j]);
        }
        pl_buff.put_s(2,(const unsigned char*)"\r\n");
      }
    }
    
    if(pl_headers.age().ispresent())
    {
      pl_buff.put_s(5,(const unsigned char*)"Age: ");
      pl_buff.put_string(int2str(pl_headers.age()()));
      pl_buff.put_s(2,(const unsigned char*)"\r\n");
    }
    
    if(pl_headers.allow().ispresent())
    {
      pl_buff.put_s(7,(const unsigned char*)"Allow: ");
     
      int nr_of_fields = pl_headers.allow()().size_of();
      for(int i = 0; i < nr_of_fields; i++)
      {
        if(i > 0 ) pl_buff.put_s(2,(const unsigned char*)", ");
        switch (pl_headers.allow()()[i])
        {
          case Method::GET: pl_buff.put_s(3,(const unsigned char*)"GET"); break;
          case Method::HEAD: pl_buff.put_s(4,(const unsigned char*)"HEAD"); break;
          case Method::POST: pl_buff.put_s(4,(const unsigned char*)"POST"); break;
          case Method::PUT: pl_buff.put_s(3,(const unsigned char*)"PUT"); break;
          case Method::DELETE: pl_buff.put_s(6,(const unsigned char*)"DELETE"); break;
          case Method::CONNECT: pl_buff.put_s(7,(const unsigned char*)"CONNECT"); break;
          case Method::OPTIONS: pl_buff.put_s(7,(const unsigned char*)"OPTIONS"); break;
          case Method::TRACE: pl_buff.put_s(5,(const unsigned char*)"TRACE"); break;
          default: break;
        }
      }
      
      pl_buff.put_s(2,(const unsigned char*)"\r\n");
    }
    
    if(pl_headers.authorization().ispresent())
    {
      pl_buff.put_s(15,(const unsigned char*)"Authorization: ");
      pl_buff.put_string(pl_headers.authorization()());
      pl_buff.put_s(2,(const unsigned char*)"\r\n");
    }
    
    if(pl_headers.cache__control().ispresent())
    {
      int nr_of_fields = pl_headers.cache__control()().size_of();
      for(int i = 0; i < nr_of_fields; i++)
      {
        pl_buff.put_s(15,(const unsigned char*)"Cache-Control: ");
        int nr_of_elems = pl_headers.cache__control()()[i].size_of();
        for(int j = 0; j < nr_of_elems; j++)
        {
          if(j > 0 ) pl_buff.put_s(2,(const unsigned char*)", ");
          pl_buff.put_string(pl_headers.cache__control()()[i][j]);
        }
        pl_buff.put_s(2,(const unsigned char*)"\r\n");
      }
    }
    
    if(pl_headers.connection().ispresent())
    {
      int nr_of_fields = pl_headers.connection()().size_of();
      for(int i = 0; i < nr_of_fields; i++)
      {
        pl_buff.put_s(12,(const unsigned char*)"Connection: ");
        int nr_of_elems = pl_headers.connection()()[i].size_of();
        for(int j = 0; j < nr_of_elems; j++)
        {
          if(j > 0 ) pl_buff.put_s(2,(const unsigned char*)", ");
          pl_buff.put_string(pl_headers.connection()()[i][j]);
        }
        pl_buff.put_s(2,(const unsigned char*)"\r\n");
      }
    }
    
    if(pl_headers.content__disposition().ispresent())
    {
      pl_buff.put_s(21,(const unsigned char*)"Content-Disposition: ");
      pl_buff.put_string(pl_headers.content__disposition()());
      pl_buff.put_s(2,(const unsigned char*)"\r\n");
    }
    
    if(pl_headers.content__encoding().ispresent())
    {
      int nr_of_fields = pl_headers.content__encoding()().size_of();
      for(int i = 0; i < nr_of_fields; i++)
      {
        pl_buff.put_s(18,(const unsigned char*)"Content-Encoding: ");
        int nr_of_elems = pl_headers.content__encoding()()[i].size_of();
        for(int j = 0; j < nr_of_elems; j++)
        {
          if(j > 0 ) pl_buff.put_s(2,(const unsigned char*)", ");
          pl_buff.put_string(pl_headers.content__encoding()()[i][j]);
        }
        pl_buff.put_s(2,(const unsigned char*)"\r\n");
      }
    }
    
    if(pl_headers.content__language().ispresent())
    {
      int nr_of_fields = pl_headers.content__language()().size_of();
      for(int i = 0; i < nr_of_fields; i++)
      {
        pl_buff.put_s(18,(const unsigned char*)"Content-Language: ");
        int nr_of_elems = pl_headers.content__language()()[i].size_of();
        for(int j = 0; j < nr_of_elems; j++)
        {
          if(j > 0 ) pl_buff.put_s(2,(const unsigned char*)", ");
          pl_buff.put_string(pl_headers.content__language()()[i][j]);
        }
        pl_buff.put_s(2,(const unsigned char*)"\r\n");
      }
    } 
    
    if(pl_headers.content__length().ispresent())
    {
        pl_buff.put_s(16,(const unsigned char*)"Content-Length: ");
        pl_buff.put_string(pl_content_length);
        pl_buff.put_s(2,(const unsigned char*)"\r\n");
    }
    
    if(pl_headers.content__location().ispresent())
    {
      pl_buff.put_s(18,(const unsigned char*)"Content-Location: ");
      pl_buff.put_string(pl_headers.content__location()());
      pl_buff.put_s(2,(const unsigned char*)"\r\n");
    }
    
    if(pl_headers.content__range().ispresent())
    {
      pl_buff.put_s(15,(const unsigned char*)"Content-Range: ");
      pl_buff.put_string(pl_headers.content__range()());
      pl_buff.put_s(2,(const unsigned char*)"\r\n");
    }
    
    if(pl_headers.content__type().ispresent())
    {
      pl_buff.put_s(14,(const unsigned char*)"Content-Type: ");
      pl_buff.put_string(pl_headers.content__type()());
      pl_buff.put_s(2,(const unsigned char*)"\r\n");
    }
    
    if(pl_headers.cookie().ispresent())
    {
      pl_buff.put_s(8,(const unsigned char*)"Cookie: ");
      pl_buff.put_string(pl_headers.cookie()());
      pl_buff.put_s(2,(const unsigned char*)"\r\n");
    }
    
    if(pl_headers.dasl().ispresent())
    {
      int nr_of_fields = pl_headers.dasl()().size_of();
      for(int i = 0; i < nr_of_fields; i++)
      {
        pl_buff.put_s(6,(const unsigned char*)"DASL: ");
        int nr_of_elems = pl_headers.dasl()()[i].size_of();
        for(int j = 0; j < nr_of_elems; j++)
        {
          if(j > 0 ) pl_buff.put_s(2,(const unsigned char*)", ");
          pl_buff.put_string(pl_headers.dasl()()[i][j]);
        }
        pl_buff.put_s(2,(const unsigned char*)"\r\n");
      }
    }
    
    if(pl_headers.dav().ispresent())
    {
      int nr_of_fields = pl_headers.dav()().size_of();
      for(int i = 0; i < nr_of_fields; i++)
      {
        pl_buff.put_s(5,(const unsigned char*)"DAV: ");
        int nr_of_elems = pl_headers.dav()()[i].size_of();
        for(int j = 0; j < nr_of_elems; j++)
        {
          if(j > 0 ) pl_buff.put_s(2,(const unsigned char*)", ");
          pl_buff.put_string(pl_headers.dav()()[i][j]);
        }
        pl_buff.put_s(2,(const unsigned char*)"\r\n");
      }
    }
    
    if(pl_headers.date().ispresent())
    {
      pl_buff.put_s(6,(const unsigned char*)"Date: ");
      pl_buff.put_string(pl_headers.date()());
      pl_buff.put_s(2,(const unsigned char*)"\r\n");
    }
    
    if(pl_headers.depth().ispresent())
    {
      pl_buff.put_s(7,(const unsigned char*)"Depth: ");
      pl_buff.put_string(pl_headers.depth()());
      pl_buff.put_s(2,(const unsigned char*)"\r\n");
    }
    
    if(pl_headers.destination().ispresent())
    {
      pl_buff.put_s(13,(const unsigned char*)"Destination: ");
      pl_buff.put_string(pl_headers.destination()());
      pl_buff.put_s(2,(const unsigned char*)"\r\n");
    }
    
    if(pl_headers.etag().ispresent())
    {
      pl_buff.put_s(6,(const unsigned char*)"ETag: ");
      pl_buff.put_string(pl_headers.etag()());
      pl_buff.put_s(2,(const unsigned char*)"\r\n");
    }
    
    if(pl_headers.expect().ispresent())
    {
      pl_buff.put_s(22,(const unsigned char*)"Expect: 100-continue\r\n");
    }
    
    if(pl_headers.expires().ispresent())
    {
      pl_buff.put_s(9,(const unsigned char*)"Expires: ");
      pl_buff.put_string(pl_headers.expires()());
      pl_buff.put_s(2,(const unsigned char*)"\r\n");
    }
    
    if(pl_headers.forwarded().ispresent())
    {
      int nr_of_fields = pl_headers.forwarded()().size_of();
      for(int i = 0; i < nr_of_fields; i++)
      {
        pl_buff.put_s(11,(const unsigned char*)"Forwarded: ");
        int nr_of_elems = pl_headers.forwarded()()[i].size_of();
        for(int j = 0; j < nr_of_elems; j++)
        {
          if(j > 0 ) pl_buff.put_s(2,(const unsigned char*)", ");
          pl_buff.put_string(pl_headers.forwarded()()[i][j]);
        }
        pl_buff.put_s(2,(const unsigned char*)"\r\n");
      }
    }
    
    if(pl_headers.fRom().ispresent())
    {
      pl_buff.put_s(6,(const unsigned char*)"From: ");
      pl_buff.put_string(pl_headers.fRom()());
      pl_buff.put_s(2,(const unsigned char*)"\r\n");
    }
    
    if(pl_headers.host().ispresent())
    {
      pl_buff.put_s(6,(const unsigned char*)"Host: ");
      pl_buff.put_string(pl_headers.host()());
      pl_buff.put_s(2,(const unsigned char*)"\r\n");
    }
    
    if(pl_headers.http2__settings().ispresent())
    {
      pl_buff.put_s(16,(const unsigned char*)"HTTP2-Settings: ");
      pl_buff.put_string(pl_headers.http2__settings()());
      pl_buff.put_s(2,(const unsigned char*)"\r\n");
    }
    
    if(pl_headers.iF().ispresent())
    {
      pl_buff.put_s(4,(const unsigned char*)"If: ");
      pl_buff.put_string(pl_headers.iF()());
      pl_buff.put_s(2,(const unsigned char*)"\r\n");
    }
    
    if(pl_headers.if__match().ispresent())
    {
      int nr_of_fields = pl_headers.if__match()().size_of();
      for(int i = 0; i < nr_of_fields; i++)
      {
        pl_buff.put_s(10,(const unsigned char*)"If-Match: ");
        int nr_of_elems = pl_headers.if__match()()[i].size_of();
        for(int j = 0; j < nr_of_elems; j++)
        {
          if(j > 0 ) pl_buff.put_s(2,(const unsigned char*)", ");
          pl_buff.put_string(pl_headers.if__match()()[i][j]);
        }
        pl_buff.put_s(2,(const unsigned char*)"\r\n");
      }
    }
    
    if(pl_headers.if__modified__since().ispresent())
    {
      pl_buff.put_s(19,(const unsigned char*)"If-Modified-Since: ");
      pl_buff.put_string(pl_headers.if__modified__since()());
      pl_buff.put_s(2,(const unsigned char*)"\r\n");
    }
    
    if(pl_headers.if__none__match().ispresent())
    {
      int nr_of_fields = pl_headers.if__none__match()().size_of();
      for(int i = 0; i < nr_of_fields; i++)
      {
        pl_buff.put_s(15,(const unsigned char*)"If-None-Match: ");
        int nr_of_elems = pl_headers.if__none__match()()[i].size_of();
        for(int j = 0; j < nr_of_elems; j++)
        {
          if(j > 0 ) pl_buff.put_s(2,(const unsigned char*)", ");
          pl_buff.put_string(pl_headers.if__none__match()()[i][j]);
        }
        pl_buff.put_s(2,(const unsigned char*)"\r\n");
      }
    }
    
    if(pl_headers.if__range().ispresent())
    {
      pl_buff.put_s(10,(const unsigned char*)"If-Range: ");
      pl_buff.put_string(pl_headers.if__range()());
      pl_buff.put_s(2,(const unsigned char*)"\r\n");
    }
    
    if(pl_headers.if__schedule__tag__match().ispresent())
    {
      pl_buff.put_s(23,(const unsigned char*)"If-Schedule-Tag-Match: ");
      pl_buff.put_string(pl_headers.if__schedule__tag__match()());
      pl_buff.put_s(2,(const unsigned char*)"\r\n");
    }
    
    if(pl_headers.if__unmodified__since().ispresent())
    {
      pl_buff.put_s(21,(const unsigned char*)"If-Unmodified-Since: ");
      pl_buff.put_string(pl_headers.if__unmodified__since()());
      pl_buff.put_s(2,(const unsigned char*)"\r\n");
    }
    
    if(pl_headers.last__modified().ispresent())
    {
      pl_buff.put_s(15,(const unsigned char*)"Last-Modified: ");
      pl_buff.put_string(pl_headers.last__modified()());
      pl_buff.put_s(2,(const unsigned char*)"\r\n");
    }
    
    if(pl_headers.location().ispresent())
    {
      pl_buff.put_s(10,(const unsigned char*)"Location: ");
      pl_buff.put_string(pl_headers.location()());
      pl_buff.put_s(2,(const unsigned char*)"\r\n");
    }
    
    if(pl_headers.lock__token().ispresent())
    {
      pl_buff.put_s(12,(const unsigned char*)"Lock-Token: ");
      pl_buff.put_string(pl_headers.lock__token()());
      pl_buff.put_s(2,(const unsigned char*)"\r\n");
    }
    
    if(pl_headers.max__forwards().ispresent())
    {
      pl_buff.put_s(14,(const unsigned char*)"Max-Forwards: ");
      pl_buff.put_string(int2str(pl_headers.max__forwards()()));
      pl_buff.put_s(2,(const unsigned char*)"\r\n");
    }
    
    if(pl_headers.mime__version().ispresent())
    {
      pl_buff.put_s(14,(const unsigned char*)"MIME-Version: ");
      pl_buff.put_string(pl_headers.mime__version()());
      pl_buff.put_s(2,(const unsigned char*)"\r\n");
    }
    
    if(pl_headers.ordering__type().ispresent())
    {
      pl_buff.put_s(15,(const unsigned char*)"Ordering-Type: ");
      pl_buff.put_string(pl_headers.ordering__type()());
      pl_buff.put_s(2,(const unsigned char*)"\r\n");
    }
    
    if(pl_headers.origin().ispresent())
    {
      pl_buff.put_s(8,(const unsigned char*)"Origin: ");
      pl_buff.put_string(pl_headers.origin()());
      pl_buff.put_s(2,(const unsigned char*)"\r\n");
    }

    if(pl_headers.overwrite().ispresent())
    {
      pl_buff.put_s(11,(const unsigned char*)"Overwrite: ");
      switch(pl_headers.overwrite()())
      {
        case TF::T: pl_buff.put_s(1,(const unsigned char*)"T"); break;
        case TF::F: pl_buff.put_s(1,(const unsigned char*)"F"); break;
        default: break;
      }
      pl_buff.put_s(2,(const unsigned char*)"\r\n");
    }
    
    if(pl_headers.position().ispresent())
    {
      pl_buff.put_s(10,(const unsigned char*)"Position: ");
      pl_buff.put_string(pl_headers.position()());
      pl_buff.put_s(2,(const unsigned char*)"\r\n");
    }
    
    if(pl_headers.pragma().ispresent())
    {
      int nr_of_fields = pl_headers.pragma()().size_of();
      for(int i = 0; i < nr_of_fields; i++)
      {
        pl_buff.put_s(8,(const unsigned char*)"Pragma: ");
        int nr_of_elems = pl_headers.pragma()()[i].size_of();
        for(int j = 0; j < nr_of_elems; j++)
        {
          if(j > 0 ) pl_buff.put_s(2,(const unsigned char*)", ");
          pl_buff.put_string(pl_headers.pragma()()[i][j]);
        }
        pl_buff.put_s(2,(const unsigned char*)"\r\n");
      }
    }
    
    if(pl_headers.prefer().ispresent())
    {
      int nr_of_fields = pl_headers.prefer()().size_of();
      for(int i = 0; i < nr_of_fields; i++)
      {
        pl_buff.put_s(8,(const unsigned char*)"Prefer: ");
        int nr_of_elems = pl_headers.prefer()()[i].size_of();
        for(int j = 0; j < nr_of_elems; j++)
        {
          if(j > 0 ) pl_buff.put_s(2,(const unsigned char*)", ");
          pl_buff.put_string(pl_headers.prefer()()[i][j]);
        }
        pl_buff.put_s(2,(const unsigned char*)"\r\n");
      }
    }
    
    if(pl_headers.preference__applied().ispresent())
    {
      int nr_of_fields = pl_headers.preference__applied()().size_of();
      for(int i = 0; i < nr_of_fields; i++)
      {
        pl_buff.put_s(20,(const unsigned char*)"Preference-Applied: ");
        int nr_of_elems = pl_headers.preference__applied()()[i].size_of();
        for(int j = 0; j < nr_of_elems; j++)
        {
          if(j > 0 ) pl_buff.put_s(2,(const unsigned char*)", ");
          pl_buff.put_string(pl_headers.preference__applied()()[i][j]);
        }
        pl_buff.put_s(2,(const unsigned char*)"\r\n");
      }
    }
    
    if(pl_headers.proxy__authenticate().ispresent())
    {
      pl_buff.put_s(20,(const unsigned char*)"Proxy-Authenticate: ");
      pl_buff.put_string(pl_headers.proxy__authenticate()());
      pl_buff.put_s(2,(const unsigned char*)"\r\n");
    }
    
    if(pl_headers.proxy__authorization().ispresent())
    {
      pl_buff.put_s(21,(const unsigned char*)"Proxy-Authorization: ");
      pl_buff.put_string(pl_headers.proxy__authorization()());
      pl_buff.put_s(2,(const unsigned char*)"\r\n");
    }
    
    if(pl_headers.range().ispresent())
    {
      pl_buff.put_s(7,(const unsigned char*)"Range: ");
      pl_buff.put_string(pl_headers.range()());
      pl_buff.put_s(2,(const unsigned char*)"\r\n");
    }
    
    if(pl_headers.referer().ispresent())
    {
      pl_buff.put_s(9,(const unsigned char*)"Referer: ");
      pl_buff.put_string(pl_headers.referer()());
      pl_buff.put_s(2,(const unsigned char*)"\r\n");
    }
    
    if(pl_headers.retry__after().ispresent())
    {
      pl_buff.put_s(13,(const unsigned char*)"Retry-After: ");
      pl_buff.put_string(pl_headers.retry__after()());
      pl_buff.put_s(2,(const unsigned char*)"\r\n");
    }
    
    if(pl_headers.schedule__reply().ispresent())
    {
      pl_buff.put_s(16,(const unsigned char*)"Schedule-Reply: ");
      switch(pl_headers.schedule__reply()())
      {
        case TF::T: pl_buff.put_s(1,(const unsigned char*)"T"); break;
        case TF::F: pl_buff.put_s(1,(const unsigned char*)"F"); break;
        default: break;
      }
      pl_buff.put_s(2,(const unsigned char*)"\r\n");
    }
    
    if(pl_headers.schedule__tag().ispresent())
    {
      pl_buff.put_s(14,(const unsigned char*)"Schedule-Tag: ");
      pl_buff.put_string(pl_headers.schedule__tag()());
      pl_buff.put_s(2,(const unsigned char*)"\r\n");
    }
    
    if(pl_headers.sec__websocket__accept().ispresent())
    {
      pl_buff.put_s(22,(const unsigned char*)"Sec-Websocket-Accept: ");
      pl_buff.put_string(pl_headers.sec__websocket__accept()());
      pl_buff.put_s(2,(const unsigned char*)"\r\n");
    }
    
    if(pl_headers.sec__websocket__extensions().ispresent())
    {
      pl_buff.put_s(26,(const unsigned char*)"Sec-Websocket-Extensions: ");
      pl_buff.put_string(pl_headers.sec__websocket__extensions()());
      pl_buff.put_s(2,(const unsigned char*)"\r\n");
    }
    
    if(pl_headers.sec__websocket__key().ispresent())
    {
      pl_buff.put_s(19,(const unsigned char*)"Sec-Websocket-Key: ");
      pl_buff.put_string(pl_headers.sec__websocket__key()());
      pl_buff.put_s(2,(const unsigned char*)"\r\n");
    }
    
    if(pl_headers.sec__websocket__protocol().ispresent())
    {
      pl_buff.put_s(24,(const unsigned char*)"Sec-Websocket-Protocol: ");
      pl_buff.put_string(pl_headers.sec__websocket__protocol()());
      pl_buff.put_s(2,(const unsigned char*)"\r\n");
    }
    
    if(pl_headers.sec__websocket__version().ispresent())
    {
      pl_buff.put_s(23,(const unsigned char*)"Sec-Websocket-Version: ");
      pl_buff.put_string(pl_headers.sec__websocket__version()());
      pl_buff.put_s(2,(const unsigned char*)"\r\n");
    }
    
    if(pl_headers.server().ispresent())
    {
      pl_buff.put_s(8,(const unsigned char*)"Server: ");
      pl_buff.put_string(pl_headers.server()());
      pl_buff.put_s(2,(const unsigned char*)"\r\n");
    }
    
    if(pl_headers.set__cookie().ispresent())
    {
      pl_buff.put_s(12,(const unsigned char*)"Set-Cookie: ");
      pl_buff.put_string(pl_headers.set__cookie()());
      pl_buff.put_s(2,(const unsigned char*)"\r\n");
    }
    
    if(pl_headers.slug().ispresent())
    {
      pl_buff.put_s(6,(const unsigned char*)"Slug: ");
      pl_buff.put_string(pl_headers.slug()());
      pl_buff.put_s(2,(const unsigned char*)"\r\n");
    }
    
    if(pl_headers.strict__transport__security().ispresent())
    {
      pl_buff.put_s(27,(const unsigned char*)"Strict-Transport-Security: ");
      pl_buff.put_string(pl_headers.strict__transport__security()());
      pl_buff.put_s(2,(const unsigned char*)"\r\n");
    }
    
    if(pl_headers.tE().ispresent())
    {
      pl_buff.put_s(4,(const unsigned char*)"TE: ");
      pl_buff.put_string(pl_headers.tE()());
      pl_buff.put_s(2,(const unsigned char*)"\r\n");
    }
    
    if(pl_headers.tImeout().ispresent())
    {
      int nr_of_fields = pl_headers.tImeout()().size_of();
      for(int i = 0; i < nr_of_fields; i++)
      {
        pl_buff.put_s(9,(const unsigned char*)"Timeout: ");
        int nr_of_elems = pl_headers.tImeout()()[i].size_of();
        for(int j = 0; j < nr_of_elems; j++)
        {
          if(j > 0 ) pl_buff.put_s(2,(const unsigned char*)", ");
          pl_buff.put_string(pl_headers.tImeout()()[i][j]);
        }
        pl_buff.put_s(2,(const unsigned char*)"\r\n");
      }
    }
    
    if(pl_headers.trailer().ispresent())
    {
      int nr_of_fields = pl_headers.trailer()().size_of();
      for(int i = 0; i < nr_of_fields; i++)
      {
        pl_buff.put_s(9,(const unsigned char*)"Trailer: ");
        int nr_of_elems = pl_headers.trailer()()[i].size_of();
        for(int j = 0; j < nr_of_elems; j++)
        {
          if(j > 0 ) pl_buff.put_s(2,(const unsigned char*)", ");
          pl_buff.put_string(pl_headers.trailer()()[i][j]);
        }
        pl_buff.put_s(2,(const unsigned char*)"\r\n");
      }
    }
    
    if(pl_headers.transfer__encoding().ispresent())
    {
      int nr_of_fields = pl_headers.transfer__encoding()().size_of();
      for(int i = 0; i < nr_of_fields; i++)
      {
        pl_buff.put_s(19,(const unsigned char*)"Transfer-Encoding: ");
        int nr_of_elems = pl_headers.transfer__encoding()()[i].size_of();
        for(int j = 0; j < nr_of_elems; j++)
        {
          if(j > 0 ) pl_buff.put_s(2,(const unsigned char*)", ");
          pl_buff.put_string(pl_headers.transfer__encoding()()[i][j]);
        }
        pl_buff.put_s(2,(const unsigned char*)"\r\n");
      }
    }
    
    if(pl_headers.upgrade().ispresent())
    {
      int nr_of_fields = pl_headers.upgrade()().size_of();
      for(int i = 0; i < nr_of_fields; i++)
      {
        pl_buff.put_s(9,(const unsigned char*)"Upgrade: ");
        int nr_of_elems = pl_headers.upgrade()()[i].size_of();
        for(int j = 0; j < nr_of_elems; j++)
        {
          if(j > 0 ) pl_buff.put_s(2,(const unsigned char*)", ");
          pl_buff.put_string(pl_headers.upgrade()()[i][j]);
        }
        pl_buff.put_s(2,(const unsigned char*)"\r\n");
      }
    }
    
    if(pl_headers.user__agent().ispresent())
    {
      pl_buff.put_s(12,(const unsigned char*)"User-Agent: ");
      pl_buff.put_string(pl_headers.user__agent()());
      pl_buff.put_s(2,(const unsigned char*)"\r\n");
    }
    
    if(pl_headers.vary().ispresent())
    {
      int nr_of_fields = pl_headers.vary()().size_of();
      for(int i = 0; i < nr_of_fields; i++)
      {
        pl_buff.put_s(6,(const unsigned char*)"Vary: ");
        int nr_of_elems = pl_headers.vary()()[i].size_of();
        for(int j = 0; j < nr_of_elems; j++)
        {
          if(j > 0 ) pl_buff.put_s(2,(const unsigned char*)", ");
          pl_buff.put_string(pl_headers.vary()()[i][j]);
        }
        pl_buff.put_s(2,(const unsigned char*)"\r\n");
      }
    }
    
    if(pl_headers.via().ispresent())
    {
      int nr_of_fields = pl_headers.via()().size_of();
      for(int i = 0; i < nr_of_fields; i++)
      {
        pl_buff.put_s(5,(const unsigned char*)"Via: ");
        int nr_of_elems = pl_headers.via()()[i].size_of();
        for(int j = 0; j < nr_of_elems; j++)
        {
          if(j > 0 ) pl_buff.put_s(2,(const unsigned char*)", ");
          pl_buff.put_string(pl_headers.via()()[i][j]);
        }
        pl_buff.put_s(2,(const unsigned char*)"\r\n");
      }
    }
    
    if(pl_headers.www__authenticate().ispresent())
    {
      int nr_of_fields = pl_headers.www__authenticate()().size_of();
      for(int i = 0; i < nr_of_fields; i++)
      {
        pl_buff.put_s(18,(const unsigned char*)"WWW-Authenticate: ");
        int nr_of_elems = pl_headers.www__authenticate()()[i].size_of();
        for(int j = 0; j < nr_of_elems; j++)
        {
          if(j > 0 ) pl_buff.put_s(2,(const unsigned char*)", ");
          pl_buff.put_string(pl_headers.www__authenticate()()[i][j]);
        }
        pl_buff.put_s(2,(const unsigned char*)"\r\n");
      }
    }
    
    if(pl_headers.warning().ispresent())
    {
      int nr_of_fields = pl_headers.warning()().size_of();
      for(int i = 0; i < nr_of_fields; i++)
      {
        pl_buff.put_s(9,(const unsigned char*)"Warning: ");
        int nr_of_elems = pl_headers.warning()()[i].size_of();
        for(int j = 0; j < nr_of_elems; j++)
        {
          if(j > 0 ) pl_buff.put_s(2,(const unsigned char*)", ");
          pl_buff.put_string(pl_headers.warning()()[i][j]);
        }
        pl_buff.put_s(2,(const unsigned char*)"\r\n");
      }
    }
    
    if(pl_headers.undefined__header__list().ispresent())
    {
      int nr_of_fields = pl_headers.undefined__header__list()().size_of();
      for(int i = 0; i < nr_of_fields; i++)
      {
        pl_buff.put_string(pl_headers.undefined__header__list()()[i].headerName());
        pl_buff.put_s(2,(const unsigned char*)": ");
        pl_buff.put_string(pl_headers.undefined__header__list()()[i].headerValue());
        pl_buff.put_s(2,(const unsigned char*)"\r\n");
      }
    }
  }

  TTCN_Buffer f_HTTP_Msg_To_Buffer(const HTTP__Message& pl__msg)
  {
    TTCN_Buffer buff;
    
    if(pl__msg.ischosen(HTTP__Message::ALT_raw__message)){
      // raw charstring
      buff.put_string(pl__msg.raw__message());
      return buff;
      
    } else if(pl__msg.msg().start__line().ischosen(StartLine::ALT_status__line))
    {
      // Status line
      buff.put_s(5,(const unsigned char*)"HTTP/");                            // HTTP
      buff.put_string(int2str(pl__msg.msg().start__line().status__line().version__major()));          // 1
      buff.put_s(1,(const unsigned char*)".");                                // .
      buff.put_string(int2str(pl__msg.msg().start__line().status__line().version__minor()));          // 0
      buff.put_s(1,(const unsigned char*)" ");                                // " "
      buff.put_string(int2str(pl__msg.msg().start__line().status__line().status__code()));            // 200
      buff.put_s(1,(const unsigned char*)" ");                         // " "
      buff.put_string(pl__msg.msg().start__line().status__line().reason__phrase());                   // OK
      buff.put_s(2,(const unsigned char*)"\r\n");
      
    }else if(pl__msg.msg().start__line().ischosen(StartLine::ALT_request__line))
    {
      // Request line
      switch (pl__msg.msg().start__line().request__line().method())
      {
        case Method::GET: buff.put_s(4,(const unsigned char*)"GET "); break;
        case Method::HEAD: buff.put_s(5,(const unsigned char*)"HEAD "); break;
        case Method::POST: buff.put_s(5,(const unsigned char*)"POST "); break;
        case Method::PUT: buff.put_s(4,(const unsigned char*)"PUT "); break;
        case Method::DELETE: buff.put_s(7,(const unsigned char*)"DELETE "); break;
        case Method::CONNECT: buff.put_s(8,(const unsigned char*)"CONNECT "); break;
        case Method::OPTIONS: buff.put_s(8,(const unsigned char*)"OPTIONS "); break;
        case Method::TRACE: buff.put_s(6,(const unsigned char*)"TRACE "); break;
        default: break;
      }
      
      buff.put_string(pl__msg.msg().start__line().request__line().request__target());
      buff.put_s(1,(const unsigned char*)" ");                               // " "
      buff.put_s(5,(const unsigned char*)"HTTP/");                           // HTTP
      buff.put_string(int2str(pl__msg.msg().start__line().request__line().version__major()));          // 1
      buff.put_s(1,(const unsigned char*)".");                               // .
      buff.put_string(int2str(pl__msg.msg().start__line().request__line().version__minor()));          // 0
      buff.put_s(2,(const unsigned char*)"\r\n");
    }
    
    if(pl__msg.msg().headers().ispresent())
    {
      CHARSTRING vl_content_length = "0";
      if(pl__msg.msg().body().ispresent())
      {
        vl_content_length = int2str(pl__msg.msg().body()().lengthof());
      }
      
      f_Encode_Headers(pl__msg.msg().headers(), buff, vl_content_length);
    }
    buff.put_s(2,(const unsigned char*)"\r\n");
    
    if(pl__msg.msg().body().ispresent())
    {
      buff.put_string(pl__msg.msg().body());
    }

    return buff;
  }
  
  OCTETSTRING ef__HTTP__Encode(const HTTP__Message& pl__msg)
  {
    TTCN_Buffer buff = f_HTTP_Msg_To_Buffer(pl__msg);
    return OCTETSTRING(buff.get_len(), buff.get_data());
  };
  
}
