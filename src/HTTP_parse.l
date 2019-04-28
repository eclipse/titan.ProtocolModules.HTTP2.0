%option noyywrap case-insensitive nounput
%{
/******************************************************************************
* Copyright (c) 2000-2019 Ericsson Telecom AB AB
* All rights reserved. This program and the accompanying materials
* are made available under the terms of the Eclipse Public License v2.0
* which accompanies this distribution, and is available at
* https://www.eclipse.org/org/documents/epl-2.0/EPL-2.0.html
*
* Contributors:
*   Eszter Susanszky
******************************************************************************/
//
//  File:               HTTP.l
//  Rev:                R1D
//  Prodnr:             CNL113796
//  Contact:            http://ttcn.ericsson.se
//  Reference:          RFC7230 - RFC7235

#include "HTTP_parse.h"
#include "HTTP_parse_.tab.h"
#include <ctype.h>

using namespace HTTP__Types;

extern HTTP__Types::HTTP__Message* HTTP_parse_parsed_message;

extern int HTTP_parse_debug;
extern int HTTP_parse_parse();
int HTTP_PM_error_occured;
enum List {none, CHARLST, METHODLST};
List list;

int HTTP_parse_error(const char *s) {
  extern int HTTP_parse_lineno;
  HTTP_PM_error_occured = 1;
  TTCN_warning("Syntax error or unsupported expression: %s - %d\n",s, HTTP_parse_lineno);
  return 0;
}

%}

%x STATUSLINE
%x STATUSLINE2
%x STATUSCODE
%x STATUSCODE1
%x REASONPHRASE
%x REQUESTLINE1
%x REQUESTLINE_HTTP
%x REQUESTLINE2
%x REQUESTLINE3
%x HEADER
%x CHARSTRNG
%x METHODLIST
%x NUMBER
%x CHARWITHCOMMA
%x TF
%x UNDEFINED

TOKEN         ([[:alnum:]]|[!]|[#]|[$]|[%]|[&]|[']|[\*]|[\+]|[-]|[.]|[\^]|[_]|[`]|[\|]|[~])+
DQUOTE        ([\"]({QTEXT}|{QPAIR})[\"])
QTEXT         ([[:alnum:]]|[\x21]|[\x23-\x2f]|[\x3a-\x40]|[\x5d-\x60]|[\x7b-\x7e]|[ ]|[\t])*
QPAIR         ([\\]({VCHAR}|[,])*)
CHAR          ({TOKEN}|[(]|[)]|[/]|[:]|[;]|[<]|[=]|[>]|[?]|[@]|[[]|[]]|[\\][{]|[}]|[\"])+
VCHAR         ({CHAR}([ ]|{CHAR})*)
CHARCOMMA     ({CHAR}([ ]|{CHAR}|[,])*)
OBS_FOLD      ({CRLF}{1}([ ]|\t)+)
CRLF          ("\r\n")

%%

<INITIAL>"HTTP/"               {BEGIN(STATUSLINE); return HTTP;}

<STATUSLINE>[0-9]+             {HTTP_parse_lval.integer = new INTEGER(yytext); return VERSION;}
<STATUSLINE>[.]                {BEGIN(STATUSLINE2); return DOT;}
<STATUSLINE2>[0-9]+            {BEGIN(STATUSCODE); HTTP_parse_lval.integer =  new INTEGER(yytext); return VERSION;}

<STATUSCODE>" "                {return SP;}
<STATUSCODE>[0-9]{3}           {BEGIN(STATUSCODE1); HTTP_parse_lval.integer = new INTEGER(yytext);return STATUS_CODE;}
<STATUSCODE1>" "               {BEGIN(REASONPHRASE); return SP;}

<REASONPHRASE>{VCHAR}          {BEGIN(HEADER); HTTP_parse_lval.charstring = new CHARSTRING(HTTP_parse_leng, yytext); return REASON_PHRASE;}

<INITIAL>GET                   {BEGIN(REQUESTLINE1); return GET;}
<INITIAL>HEAD                  {BEGIN(REQUESTLINE1); return HEAD;}
<INITIAL>POST                  {BEGIN(REQUESTLINE1); return POST;}
<INITIAL>PUT                   {BEGIN(REQUESTLINE1); return PUT;}
<INITIAL>DELETE                {BEGIN(REQUESTLINE1); return DELETE;}
<INITIAL>CONNECT               {BEGIN(REQUESTLINE1); return CONNECT;}
<INITIAL>OPTIONS               {BEGIN(REQUESTLINE1); return OPTIONS;}
<INITIAL>TRACE                 {BEGIN(REQUESTLINE1); return TRACE;}

<REQUESTLINE1>" "              {return SP;}
<REQUESTLINE1>{CHAR}           {BEGIN(REQUESTLINE_HTTP); HTTP_parse_lval.charstring = new CHARSTRING(HTTP_parse_leng, yytext); return URI;}
<REQUESTLINE_HTTP>" "          {return SP;}
<REQUESTLINE_HTTP>"HTTP/"      {BEGIN(REQUESTLINE2);  return HTTP;}
<REQUESTLINE2>[0-9]+           {HTTP_parse_lval.integer = new INTEGER(yytext); return VERSION;}
<REQUESTLINE2>[.]              {BEGIN(REQUESTLINE3); return DOT;}
<REQUESTLINE3>[0-9]+           {BEGIN(HEADER); HTTP_parse_lval.integer = new INTEGER(yytext); return VERSION;}

<HEADER>{CRLF}{2}              {return CRLFCRLF;}

<HEADER>Accept:                {BEGIN(CHARSTRNG); list = CHARLST; return ACCEPT;}
<HEADER>Accept-Charset:        {BEGIN(CHARSTRNG); list = CHARLST; return ACCEPT_CHARSET;}
<HEADER>Accept-Encoding:       {BEGIN(CHARSTRNG); list = CHARLST; return ACCEPT_ENCODING;}
<HEADER>Accept-Language:       {BEGIN(CHARSTRNG); list = CHARLST; return ACCEPT_LANGUAGE;}
<HEADER>Accept-Ranges:         {BEGIN(CHARSTRNG); list = CHARLST; return ACCEPT_RANGES;}
<HEADER>Age:                   {BEGIN(NUMBER); return AGE;}
<HEADER>Allow:                 {BEGIN(METHODLIST); list = METHODLST; return ALLOW;}
<HEADER>Authorization:         {BEGIN(CHARWITHCOMMA); return AUTHORIZATION;}
<HEADER>Cache-Control:         {BEGIN(CHARSTRNG); list = CHARLST; return CACHE_CONTROL;}
<HEADER>Connection:            {BEGIN(CHARSTRNG); list = CHARLST; return CONNECTION;}
<HEADER>Content-Disposition:   {BEGIN(CHARWITHCOMMA); return CONTENT_DISPOSITION;}
<HEADER>Content-Encoding:      {BEGIN(CHARSTRNG); list = CHARLST; return CONTENT_ENCODING;}
<HEADER>Content-Language:      {BEGIN(CHARSTRNG); list = CHARLST; return CONTENT_LANGUAGE;}
<HEADER>Content-Length:        {BEGIN(NUMBER); return CONTENT_LENGTH;}
<HEADER>Content-Location:      {BEGIN(CHARWITHCOMMA); return CONTENT_LOCATION;}
<HEADER>Content-Range:         {BEGIN(CHARWITHCOMMA); return CONTENT_RANGE;}
<HEADER>Content-Type:          {BEGIN(CHARWITHCOMMA); return CONTENT_TYPE;}
<HEADER>Cookie:                {BEGIN(CHARWITHCOMMA); return COOKIE;}
<HEADER>DASL:                  {BEGIN(CHARSTRNG); list = CHARLST; return DASL;}
<HEADER>DAV:                   {BEGIN(CHARSTRNG); list = CHARLST; return DAV;}
<HEADER>Date:                  {BEGIN(CHARWITHCOMMA); return DATE;}
<HEADER>Depth:                 {BEGIN(CHARWITHCOMMA); return DEPTH;}
<HEADER>Destination:           {BEGIN(CHARWITHCOMMA); return DESTINATION;}
<HEADER>ETag:                  {BEGIN(CHARWITHCOMMA); return ETAG;}
<HEADER>Expect:                {BEGIN(CHARWITHCOMMA); return EXPECT;}
<HEADER>Expires:               {BEGIN(CHARWITHCOMMA); return EXPIRES;}
<HEADER>Forwarded:             {BEGIN(CHARSTRNG); list = CHARLST; return FORWARDED;}
<HEADER>From:                  {BEGIN(CHARWITHCOMMA); return FROM;}
<HEADER>Host:                  {BEGIN(CHARWITHCOMMA); return HOST;}
<HEADER>HTTP2-Settings:        {BEGIN(CHARWITHCOMMA); return HTTP2_SETTINGS;}
<HEADER>If:                    {BEGIN(CHARWITHCOMMA); return IF;}
<HEADER>If-Match:              {BEGIN(CHARSTRNG); list = CHARLST; return IF_MATCH;}
<HEADER>If-Modified-Since:     {BEGIN(CHARWITHCOMMA); return IF_MODIFIED_SINCE;}
<HEADER>If-None-Match:         {BEGIN(CHARSTRNG); list = CHARLST; return IF_NONE_MATCH;}
<HEADER>If-Range:              {BEGIN(CHARWITHCOMMA); return IF_RANGE;}
<HEADER>If-Schedule-Tag-Match: {BEGIN(CHARWITHCOMMA); return IF_SCHEDULE_TAG_MATCH;}
<HEADER>If-Unmodified-Since:   {BEGIN(CHARWITHCOMMA); return IF_UNMODIFIED_SINCE;}
<HEADER>Last-Modified:         {BEGIN(CHARWITHCOMMA); return LAST_MODIFIED;}
<HEADER>Location:              {BEGIN(CHARWITHCOMMA); return LOCATION;}
<HEADER>Lock-Token:            {BEGIN(CHARWITHCOMMA); return LOCK_TOKEN;}
<HEADER>Max-Forwards:          {BEGIN(NUMBER); return MAX_FORWARDS;}
<HEADER>MIME-Version:          {BEGIN(CHARWITHCOMMA); return MIME_VERSION;}
<HEADER>Ordering-Type:         {BEGIN(CHARWITHCOMMA); return ORDERING_TYPE;}
<HEADER>Origin:                {BEGIN(CHARWITHCOMMA); return ORIGIN;}
<HEADER>Overwrite:             {BEGIN(TF); return OVERWRITE;}
<HEADER>Position:              {BEGIN(CHARWITHCOMMA); return POSITION;}
<HEADER>Pragma:                {BEGIN(CHARSTRNG); list = CHARLST; return PRAGMA;}
<HEADER>Prefer:                {BEGIN(CHARSTRNG); list = CHARLST; return PREFER;}
<HEADER>Preference-Applied:    {BEGIN(CHARSTRNG); list = CHARLST; return PREFERENCE_APPLIED;}
<HEADER>Proxy-Authenticate:    {BEGIN(CHARWITHCOMMA); return PROXY_AUTHENTICATE;}
<HEADER>Proxy-Authorization:   {BEGIN(CHARWITHCOMMA); return PROXY_AUTHORIZATION;}
<HEADER>Range:                 {BEGIN(CHARWITHCOMMA); return RANGE;}
<HEADER>Referer:               {BEGIN(CHARWITHCOMMA); return REFERER;}
<HEADER>Retry-After:           {BEGIN(CHARWITHCOMMA); return RETRY_AFTER;}
<HEADER>Schedule-Reply:        {BEGIN(TF); return SCHEDULE_REPLY;}
<HEADER>Schedule-Tag:          {BEGIN(CHARSTRNG); return SCHEDULE_TAG;}
<HEADER>Sec-Websocket-Accept:     {BEGIN(CHARWITHCOMMA); return SEC_WEBSOCKET_ACCEPT;}
<HEADER>Sec-Websocket-Extensions: {BEGIN(CHARWITHCOMMA); return SEC_WEBSOCKET_EXTENSIONS;}
<HEADER>Sec-Websocket-Key:        {BEGIN(CHARWITHCOMMA); return SEC_WEBSOCKET_KEY;}
<HEADER>Sec-Websocket-Protocol:   {BEGIN(CHARWITHCOMMA); return SEC_WEBSOCKET_PROTOCOL;}
<HEADER>Sec-Websocket-Version:    {BEGIN(CHARWITHCOMMA); return SEC_WEBSOCKET_VERSION;}
<HEADER>Server:                {BEGIN(CHARWITHCOMMA); return SERVER;}
<HEADER>Set-Cookie:            {BEGIN(CHARWITHCOMMA); return SET_COOKIE;}
<HEADER>Slug:                  {BEGIN(CHARWITHCOMMA); return SLUG;}
<HEADER>Strict-Transport-Security: {BEGIN(CHARWITHCOMMA); return STRICT_TRANSPORT_SECURITY;}
<HEADER>TE:                    {BEGIN(CHARWITHCOMMA); return TE;}
<HEADER>Timeout:               {BEGIN(CHARSTRNG); list = CHARLST; return TIMEOUT;}
<HEADER>Trailer:               {BEGIN(CHARSTRNG); list = CHARLST; return TRAILER;}
<HEADER>Transfer-Encoding:     {BEGIN(CHARSTRNG); list = CHARLST; return TRANSFER_ENCODING;}
<HEADER>Upgrade:               {BEGIN(CHARSTRNG); list = CHARLST; return UPGRADE;}
<HEADER>User-Agent:            {BEGIN(CHARWITHCOMMA); return USER_AGENT;}
<HEADER>Vary:                  {BEGIN(CHARSTRNG); list = CHARLST; return VARY;}
<HEADER>Via:                   {BEGIN(CHARSTRNG); list = CHARLST; return VIA;}
<HEADER>Warning:               {BEGIN(CHARSTRNG); list = CHARLST; return WARNING;}
<HEADER>WWW-Authenticate:      {BEGIN(CHARSTRNG); list = CHARLST; return WWW_AUTHENTICATE;}
<HEADER>{CHAR}/":"             {BEGIN(UNDEFINED); HTTP_parse_lval.charstring = new CHARSTRING(HTTP_parse_leng, yytext); return UNDEFINED_HEADERNAME;}

<HEADER>","[ ]{0,1}            {
                                 if(list==CHARLST) BEGIN(CHARSTRNG);
                                 else if(list==METHODLST) BEGIN(METHODLIST);
                                 return COMMA;
                               }

<UNDEFINED>":"[ ]*             {BEGIN(CHARWITHCOMMA); return COLON;}

<NUMBER>[0-9]+                 {BEGIN(HEADER); HTTP_parse_lval.integer = new INTEGER(yytext); return NUM;}

<CHARSTRNG>{OBS_FOLD}          {BEGIN(HEADER); HTTP_parse_lval.charstring = new CHARSTRING(HTTP_parse_leng, yytext); return CHARSTR; }
<CHARSTRNG>{DQUOTE}            {BEGIN(HEADER); HTTP_parse_lval.charstring = new CHARSTRING(HTTP_parse_leng, yytext); return CHARSTR; }
<CHARSTRNG>{VCHAR}             {BEGIN(HEADER); HTTP_parse_lval.charstring = new CHARSTRING(HTTP_parse_leng, yytext); return CHARSTR; }
<CHARSTRNG>{CRLF}{2}           {return CRLFCRLF;}

<CHARWITHCOMMA>{CHARCOMMA}     {BEGIN(HEADER); HTTP_parse_lval.charstring = new CHARSTRING(HTTP_parse_leng, yytext); return CHARSTR; }
<CHARWITHCOMMA>{CRLF}{2}       {return CRLFCRLF;}

<METHODLIST>GET                {BEGIN(HEADER); return GET;}
<METHODLIST>HEAD               {BEGIN(HEADER); return HEAD;}
<METHODLIST>POST               {BEGIN(HEADER); return POST;}
<METHODLIST>PUT                {BEGIN(HEADER); return PUT;}
<METHODLIST>DELETE             {BEGIN(HEADER); return DELETE;}
<METHODLIST>CONNECT            {BEGIN(HEADER); return CONNECT;}
<METHODLIST>OPTIONS            {BEGIN(HEADER); return OPTIONS;}
<METHODLIST>TRACE              {BEGIN(HEADER); return TRACE;}


<TF>T                          {BEGIN(HEADER); return T;}
<TF>F                          {BEGIN(HEADER); return F;}

<*>" "                         {}   
<*>{CRLF}                      {BEGIN(HEADER); list = none; return CRLF;}

%%


HTTP__Message HTTP__Types::ef__HTTP__Decode(const OCTETSTRING& pl__stream, const BOOLEAN& pl__assemble__chunked)
{
  HTTP_PM_error_occured = 0;
  list = none;
 
  HTTP__Message retv;
  HTTP_parse_parsed_message = &retv;
  
  retv.msg().headers()() = HTTP__Types::HTTP__Headers( OMIT_VALUE, OMIT_VALUE, OMIT_VALUE, OMIT_VALUE, OMIT_VALUE, OMIT_VALUE, OMIT_VALUE, OMIT_VALUE, OMIT_VALUE, OMIT_VALUE, OMIT_VALUE,
                                                        OMIT_VALUE, OMIT_VALUE, OMIT_VALUE, OMIT_VALUE, OMIT_VALUE, OMIT_VALUE, OMIT_VALUE, OMIT_VALUE, OMIT_VALUE, OMIT_VALUE,
                                                        OMIT_VALUE, OMIT_VALUE, OMIT_VALUE, OMIT_VALUE, OMIT_VALUE, OMIT_VALUE, OMIT_VALUE, OMIT_VALUE, OMIT_VALUE, OMIT_VALUE,
                                                        OMIT_VALUE, OMIT_VALUE, OMIT_VALUE, OMIT_VALUE, OMIT_VALUE, OMIT_VALUE, OMIT_VALUE, OMIT_VALUE, OMIT_VALUE, OMIT_VALUE,
                                                        OMIT_VALUE, OMIT_VALUE, OMIT_VALUE, OMIT_VALUE, OMIT_VALUE, OMIT_VALUE, OMIT_VALUE, OMIT_VALUE, OMIT_VALUE, OMIT_VALUE,
                                                        OMIT_VALUE, OMIT_VALUE, OMIT_VALUE, OMIT_VALUE, OMIT_VALUE, OMIT_VALUE, OMIT_VALUE, OMIT_VALUE, OMIT_VALUE, OMIT_VALUE,
                                                        OMIT_VALUE, OMIT_VALUE, OMIT_VALUE, OMIT_VALUE, OMIT_VALUE, OMIT_VALUE, OMIT_VALUE, OMIT_VALUE, OMIT_VALUE, OMIT_VALUE,
                                                        OMIT_VALUE, OMIT_VALUE, OMIT_VALUE, OMIT_VALUE, OMIT_VALUE);
  
  const unsigned char* ptr = (const unsigned char*)pl__stream;
  int stream_length = pl__stream.lengthof();

  const unsigned char* end_ptr=ptr+stream_length-3;  // the header ends with 4 octet \r\n\r\n, the end pointer should point to after the last possible position of \r\n\r\n
  
  while(ptr<end_ptr){
    if( ptr[0]== '\r' && ptr[1]== '\n'&& ptr[2]== '\r'&& ptr[3]== '\n'){break;}
    ptr++;
  }
  
  if(ptr==end_ptr){  // the end of the header was not found
    retv.raw__message()=(const char*)(const unsigned char*)pl__stream; 
    return retv;
  }
  ptr += 4;
  
  int header_length = ptr - (const unsigned char*)pl__stream;

  HTTP_parse__scan_bytes ((const char*)(const unsigned char*)pl__stream, header_length);
  HTTP_parse_parse();
  HTTP_parse_lex_destroy();
  
  if(stream_length > header_length) { 
    if(pl__assemble__chunked && retv.msg().headers()().transfer__encoding().ispresent() ){
      // try to assemble the chunked body
      retv.msg().body()() =OCTETSTRING(0, NULL);
      end_ptr=((const unsigned char*)pl__stream)+stream_length;
      const unsigned char* data_start=ptr;
      unsigned int chunk_len=0;
      bool last_chunk_found=false;
      while(ptr<end_ptr){
        if( ptr[0] >='0' && ptr[0] <='9'){
          chunk_len<<=4;
          chunk_len+= ptr[0] - '0';
        } else if( ptr[0] >='a' && ptr[0] <='f'){
          chunk_len<<=4;
          chunk_len+= ptr[0] - 'a' + 10; 
        } else if( ptr[0] >='A' && ptr[0] <='F'){
          chunk_len<<=4;
          chunk_len+= ptr[0] - 'A' + 10;
        } else if(ptr[0] == '\n'){
          if(chunk_len==0){
            last_chunk_found=true;
            break;
          }
          unsigned int rem_length=end_ptr-ptr-1;  // the ptr is smaller than the end_ptr
          if(rem_length < chunk_len + 2 + 5){ // something went wrong, not enough octets in the buffer
                             // there should be at least chunk_len + 2 (the CRLF after the data) + 5 (last chunk (0CRLF)+ closing CRLF ) octets
            break;
          }
          // add the data
          retv.msg().body()() = retv.msg().body()() + OCTETSTRING(chunk_len, ptr+1); // data 
          ptr+=chunk_len + 2; // advance the data + CRLF
          chunk_len=0;
        }
        ptr++;
      }
      if(!last_chunk_found){
        retv.msg().body()() = OCTETSTRING(stream_length - header_length, data_start);
      }
    } else {
      retv.msg().body()() = OCTETSTRING(stream_length - header_length, ptr);
    }
  }
  
  if(HTTP_PM_error_occured) { retv.raw__message()=(const char*)(const unsigned char*)pl__stream; };
  
  return retv;
}
