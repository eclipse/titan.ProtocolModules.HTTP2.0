%{
/******************************************************************************
* Copyright (c) 2000-2018 Ericsson Telecom AB AB
* All rights reserved. This program and the accompanying materials
* are made available under the terms of the Eclipse Public License v2.0
* which accompanies this distribution, and is available at
* https://www.eclipse.org/org/documents/epl-2.0/EPL-2.0.html
*
* Contributors:
*   Eszter Susanszky
******************************************************************************/
//
//  File:               HTTP_parse.y
//  Rev:                R1C
//  Prodnr:             CNL113796
//  Contact:            http://ttcn.ericsson.se
//  Reference:          RFC7230 - RFC7235

#include "HTTP_parse.h"
#define YYDEBUG 0

using namespace HTTP__Types;

extern int HTTP_parse_lex();
extern int HTTP_PM_error_occured;

int yyerror(const char *s);

HTTP__Message*        HTTP_parse_parsed_message;

%}

%union
{
  CHARSTRING*                   charstring;
  INTEGER*                      integer;
  HTTP__Types::Method*          method;
  General__Types::CharstringList*  charstring_list;
  HTTP__Types::Method__List*    methodlist;
  HTTP__Types::TF*              tf;
}
%destructor { delete $$;} <*>

%token <charstring> REASON_PHRASE URI CHARSTR UNDEFINED_HEADERNAME
%token <integer> VERSION STATUS_CODE NUM
%token HTTP DOT SP CRLF CRLFCRLF GET HEAD POST PUT DELETE CONNECT OPTIONS TRACE COMMA COLON
%token ACCEPT ACCEPT_CHARSET ACCEPT_ENCODING ACCEPT_LANGUAGE ACCEPT_RANGES AGE ALLOW AUTHORIZATION CACHE_CONTROL
%token CONNECTION CONTENT_DISPOSITION CONTENT_ENCODING CONTENT_LANGUAGE CONTENT_LENGTH CONTENT_LOCATION CONTENT_RANGE CONTENT_TYPE
%token COOKIE DASL DAV DATE DEPTH DESTINATION ETAG EXPECT EXPIRES FORWARDED FROM HOST HTTP2_SETTINGS IF IF_MATCH IF_MODIFIED_SINCE IF_NONE_MATCH
%token IF_RANGE IF_SCHEDULE_TAG_MATCH IF_UNMODIFIED_SINCE LAST_MODIFIED LOCATION LOCK_TOKEN MAX_FORWARDS MIME_VERSION ORDERING_TYPE
%token ORIGIN OVERWRITE T F POSITION PRAGMA PREFER PREFERENCE_APPLIED PROXY_AUTHENTICATE PROXY_AUTHORIZATION RANGE REFERER RETRY_AFTER
%token SCHEDULE_REPLY SCHEDULE_TAG SEC_WEBSOCKET_ACCEPT SEC_WEBSOCKET_EXTENSIONS SEC_WEBSOCKET_KEY SEC_WEBSOCKET_PROTOCOL SEC_WEBSOCKET_VERSION
%token SERVER SET_COOKIE SLUG STRICT_TRANSPORT_SECURITY TE TIMEOUT TRAILER TRANSFER_ENCODING UPGRADE USER_AGENT VARY VIA WWW_AUTHENTICATE WARNING

%type <method> Method
%type <charstring_list> Charstring_List
%type <methodlist> Method_List
%type <tf> TF
%type <charstring> CharString

%start http_message

%%
http_message: request{YYACCEPT;}
             |response{YYACCEPT;}

request: RequestLine HTTP_Headers
         {  
           HTTP_parse_parsed_message->msg().body() = OMIT_VALUE;
         }

RequestLine: Method SP URI SP HTTP VERSION DOT VERSION
             {
               HTTP_parse_parsed_message->msg().start__line().request__line().method() = *$1;
               HTTP_parse_parsed_message->msg().start__line().request__line().request__target() = *$3;
               HTTP_parse_parsed_message->msg().start__line().request__line().version__major() =  *$6;
               HTTP_parse_parsed_message->msg().start__line().request__line().version__minor() =  *$8;
               
               delete $1;
               delete $3;
               delete $6;
               delete $8;
             }

Method: 
  GET { $$=new Method(0); }
| HEAD { $$=new Method(1); }
| POST { $$=new Method(2); }
| PUT { $$=new Method(3); }
| DELETE { $$=new Method(4); }
| CONNECT { $$=new Method(5); }
| OPTIONS { $$=new Method(6); }
| TRACE { $$=new Method(7); }

response: StatusLine HTTP_Headers
          {
            HTTP_parse_parsed_message->msg().body() = OMIT_VALUE;
          }

StatusLine: HTTP VERSION DOT VERSION SP STATUS_CODE SP REASON_PHRASE
            {
              HTTP_parse_parsed_message->msg().start__line().status__line().version__major() =  *$2;
              HTTP_parse_parsed_message->msg().start__line().status__line().version__minor() =  *$4;
              HTTP_parse_parsed_message->msg().start__line().status__line().status__code() =  *$6;
              HTTP_parse_parsed_message->msg().start__line().status__line().reason__phrase() =  *$8;
              
              delete $2;
              delete $4;
              delete $6;
              delete $8;
            }
                
HTTP_Headers: CRLF HTTP_Header_list CRLFCRLF { /* empty */ }
            | CRLFCRLF { HTTP_parse_parsed_message->msg().headers() = OMIT_VALUE; }

HTTP_Header_list: HTTP_Header { /* empty */ }
                | HTTP_Header_list CRLF HTTP_Header { /* empty */ }

HTTP_Header: ACCEPT Charstring_List {
               int i = 0;
               if(HTTP_parse_parsed_message->msg().headers()().accept().ispresent()) i = HTTP_parse_parsed_message->msg().headers()().accept()().size_of();
               if($2) HTTP_parse_parsed_message->msg().headers()().accept()()[i] = *$2;
               else HTTP_parse_parsed_message->msg().headers()().accept()()[i][0] = "";
               delete $2;
             }
            |ACCEPT_CHARSET Charstring_List  {
               int i = 0;
               if(HTTP_parse_parsed_message->msg().headers()().accept__charset().ispresent()) i = HTTP_parse_parsed_message->msg().headers()().accept__charset()().size_of();
               if($2) HTTP_parse_parsed_message->msg().headers()().accept__charset()()[i] = *$2;
               else HTTP_parse_parsed_message->msg().headers()().accept__charset()()[i][0] = "";
               delete $2;
             }
            |ACCEPT_ENCODING Charstring_List  {
               int i = 0;
               if(HTTP_parse_parsed_message->msg().headers()().accept__encoding().ispresent()) i = HTTP_parse_parsed_message->msg().headers()().accept__encoding()().size_of();
               if($2) HTTP_parse_parsed_message->msg().headers()().accept__encoding()()[i] = *$2;
               else HTTP_parse_parsed_message->msg().headers()().accept__encoding()()[i][0] = "";
               delete $2;
             }
            |ACCEPT_LANGUAGE Charstring_List  {
               int i = 0;
               if(HTTP_parse_parsed_message->msg().headers()().accept__language().ispresent()) i = HTTP_parse_parsed_message->msg().headers()().accept__language()().size_of();
               if($2) HTTP_parse_parsed_message->msg().headers()().accept__language()()[i] = *$2;
               else HTTP_parse_parsed_message->msg().headers()().accept__language()()[i][0] = "";
               delete $2;
             }
            |ACCEPT_RANGES Charstring_List  {
               int i = 0;
               if(HTTP_parse_parsed_message->msg().headers()().accept__ranges().ispresent()) i = HTTP_parse_parsed_message->msg().headers()().accept__ranges()().size_of();
               if($2) HTTP_parse_parsed_message->msg().headers()().accept__ranges()()[i] = *$2;
               else HTTP_parse_parsed_message->msg().headers()().accept__ranges()()[i][0] = "";
               delete $2;
             }
            |AGE NUM  {
               HTTP_parse_parsed_message->msg().headers()().age()() = *$2;
               delete $2;
             }
             |ALLOW Method_List  {
               HTTP_parse_parsed_message->msg().headers()().allow()() = *$2;
               delete $2;
             }
             |AUTHORIZATION CharString  {
               if($2) HTTP_parse_parsed_message->msg().headers()().authorization()() = *$2;
               else HTTP_parse_parsed_message->msg().headers()().authorization()() = "";
               delete $2;
             }
             |CACHE_CONTROL Charstring_List  {
               int i = 0;
               if(HTTP_parse_parsed_message->msg().headers()().cache__control().ispresent()) i = HTTP_parse_parsed_message->msg().headers()().cache__control()().size_of();
               if($2) HTTP_parse_parsed_message->msg().headers()().cache__control()()[i] = *$2;
               else HTTP_parse_parsed_message->msg().headers()().cache__control()()[i][0] = "";
               delete $2;
             }
             |CONNECTION Charstring_List  {
               int i = 0;
               if(HTTP_parse_parsed_message->msg().headers()().connection().ispresent()) i = HTTP_parse_parsed_message->msg().headers()().connection()().size_of();
               if($2) HTTP_parse_parsed_message->msg().headers()().connection()()[i] = *$2;
               else HTTP_parse_parsed_message->msg().headers()().connection()()[i][0] = "";
               delete $2;
             }
             |CONTENT_DISPOSITION CharString  {
               if($2) HTTP_parse_parsed_message->msg().headers()().content__disposition()() = *$2;
               else HTTP_parse_parsed_message->msg().headers()().content__disposition()() = "";
               delete $2;
             }
             |CONTENT_ENCODING Charstring_List  {
               int i = 0;
               if(HTTP_parse_parsed_message->msg().headers()().content__encoding().ispresent()) i = HTTP_parse_parsed_message->msg().headers()().content__encoding()().size_of();
               if($2) HTTP_parse_parsed_message->msg().headers()().content__encoding()()[i] = *$2;
               else HTTP_parse_parsed_message->msg().headers()().content__encoding()()[i][0] = "";
               delete $2;
             }
             |CONTENT_LANGUAGE Charstring_List  {
               int i = 0;
               if(HTTP_parse_parsed_message->msg().headers()().content__language().ispresent()) i = HTTP_parse_parsed_message->msg().headers()().content__language()().size_of();
               if($2) HTTP_parse_parsed_message->msg().headers()().content__language()()[i] = *$2;
               else HTTP_parse_parsed_message->msg().headers()().content__language()()[i][0] = "";
               delete $2;
             }
             |CONTENT_LENGTH NUM  {
               HTTP_parse_parsed_message->msg().headers()().content__length()() = *$2;
               delete $2;
             }
             |CONTENT_LOCATION CharString  {
               if($2) HTTP_parse_parsed_message->msg().headers()().content__location()() = *$2;
               else HTTP_parse_parsed_message->msg().headers()().content__location()() = "";
               delete $2;
             }
             |CONTENT_RANGE CharString  {
               if($2) HTTP_parse_parsed_message->msg().headers()().content__range()() = *$2;
               else HTTP_parse_parsed_message->msg().headers()().content__range()() = "";
               delete $2;
             }
             |CONTENT_TYPE CharString  {
               if($2) HTTP_parse_parsed_message->msg().headers()().content__type()() = *$2;
               else HTTP_parse_parsed_message->msg().headers()().content__type()() = "";
               delete $2;
             }
             |COOKIE CharString  {
               if($2) HTTP_parse_parsed_message->msg().headers()().cookie()() = *$2;
               else HTTP_parse_parsed_message->msg().headers()().cookie()() = "";
               delete $2;
             }
             |DASL Charstring_List  {
               int i = 0;
               if(HTTP_parse_parsed_message->msg().headers()().dasl().ispresent()) i = HTTP_parse_parsed_message->msg().headers()().dasl()().size_of();
               if($2) HTTP_parse_parsed_message->msg().headers()().dasl()()[i] = *$2;
               else HTTP_parse_parsed_message->msg().headers()().dasl()()[i][0] = "";
               delete $2;
             }
             |DAV Charstring_List  {
               int i = 0;
               if(HTTP_parse_parsed_message->msg().headers()().dav().ispresent()) i = HTTP_parse_parsed_message->msg().headers()().dav()().size_of();
               if($2) HTTP_parse_parsed_message->msg().headers()().dav()()[i] = *$2;
               else HTTP_parse_parsed_message->msg().headers()().dav()()[i][0] = "";
               delete $2;
             }
             |DATE CharString  {
               if($2) HTTP_parse_parsed_message->msg().headers()().date()() = *$2;
               else HTTP_parse_parsed_message->msg().headers()().date()() = "";
               delete $2;
             }
             |DEPTH CharString  {
               if($2) HTTP_parse_parsed_message->msg().headers()().depth()() = *$2;
               else HTTP_parse_parsed_message->msg().headers()().depth()() = "";
               delete $2;
             }
             |DESTINATION CharString  {
               if($2) HTTP_parse_parsed_message->msg().headers()().destination()() = *$2;
               else HTTP_parse_parsed_message->msg().headers()().destination()() = "";
               delete $2;
             }
             |ETAG CharString  {
               if($2) HTTP_parse_parsed_message->msg().headers()().etag()() = *$2;
               else HTTP_parse_parsed_message->msg().headers()().etag()() = "";
               delete $2;
             }
             |EXPECT CharString  {
               if($2) HTTP_parse_parsed_message->msg().headers()().expect()() = *$2;
               else HTTP_parse_parsed_message->msg().headers()().expect()() = "";
               delete $2;
             }
             |EXPIRES CharString  {
               if($2) HTTP_parse_parsed_message->msg().headers()().expires()() = *$2;
               else HTTP_parse_parsed_message->msg().headers()().expires()() = "";
               delete $2;
             }
             |FORWARDED Charstring_List {
               int i = 0;
               if(HTTP_parse_parsed_message->msg().headers()().forwarded().ispresent()) i = HTTP_parse_parsed_message->msg().headers()().forwarded()().size_of();
               if($2) HTTP_parse_parsed_message->msg().headers()().forwarded()()[i] = *$2;
               else HTTP_parse_parsed_message->msg().headers()().forwarded()()[i][0] = "";
               delete $2;
             }
             |FROM CharString  {
               if($2) HTTP_parse_parsed_message->msg().headers()().fRom()() = *$2;
               else HTTP_parse_parsed_message->msg().headers()().fRom()() = "";
               delete $2;
             }
             |HOST CharString  {
               if($2) HTTP_parse_parsed_message->msg().headers()().host()() = *$2;
               else HTTP_parse_parsed_message->msg().headers()().host()() = "";
               delete $2;
             }
             |HTTP2_SETTINGS CharString  {
               if($2) HTTP_parse_parsed_message->msg().headers()().http2__settings()() = *$2;
               else HTTP_parse_parsed_message->msg().headers()().http2__settings()() = "";
               delete $2;
             }
             |IF CharString  {
               if($2) HTTP_parse_parsed_message->msg().headers()().iF()() = *$2;
               else HTTP_parse_parsed_message->msg().headers()().iF()() = "";
               delete $2;
             }
             |IF_MATCH Charstring_List  {
               int i = 0;
               if(HTTP_parse_parsed_message->msg().headers()().if__match().ispresent()) i = HTTP_parse_parsed_message->msg().headers()().if__match()().size_of();
               if($2) HTTP_parse_parsed_message->msg().headers()().if__match()()[i] = *$2;
               else HTTP_parse_parsed_message->msg().headers()().if__match()()[i][0] = "";
               delete $2;
             }
             |IF_MODIFIED_SINCE CharString  {
               if($2) HTTP_parse_parsed_message->msg().headers()().if__modified__since()() = *$2;
               else HTTP_parse_parsed_message->msg().headers()().if__modified__since()() = "";
               delete $2;
             }
             |IF_NONE_MATCH Charstring_List  {
               int i = 0;
               if(HTTP_parse_parsed_message->msg().headers()().if__none__match().ispresent()) i = HTTP_parse_parsed_message->msg().headers()().if__none__match()().size_of();
               if($2) HTTP_parse_parsed_message->msg().headers()().if__none__match()()[i] = *$2;
               else HTTP_parse_parsed_message->msg().headers()().if__none__match()()[i][0] = "";
               delete $2;
             }
             |IF_RANGE CharString  {
               if($2) HTTP_parse_parsed_message->msg().headers()().if__range()() = *$2;
               else HTTP_parse_parsed_message->msg().headers()().if__range()() = "";
               delete $2;
             }
             |IF_SCHEDULE_TAG_MATCH CharString  {
               if($2) HTTP_parse_parsed_message->msg().headers()().if__schedule__tag__match()() = *$2;
               else HTTP_parse_parsed_message->msg().headers()().if__schedule__tag__match()() = "";
               delete $2;
             }
             |IF_UNMODIFIED_SINCE CharString  {
               if($2) HTTP_parse_parsed_message->msg().headers()().if__unmodified__since()() = *$2;
               else HTTP_parse_parsed_message->msg().headers()().if__unmodified__since()() = "";
               delete $2;
             }
             |LAST_MODIFIED CharString  {
               if($2) HTTP_parse_parsed_message->msg().headers()().last__modified()() = *$2;
               else HTTP_parse_parsed_message->msg().headers()().last__modified()() = "";
               delete $2;
             }
             |LOCATION CharString  {
               if($2) HTTP_parse_parsed_message->msg().headers()().location()() = *$2;
               else HTTP_parse_parsed_message->msg().headers()().location()() = "";
               delete $2;
             }
             |LOCK_TOKEN CharString  {
               if($2) HTTP_parse_parsed_message->msg().headers()().lock__token()() = *$2;
               else HTTP_parse_parsed_message->msg().headers()().lock__token()() = "";
               delete $2;
             }
             |MAX_FORWARDS NUM  {
               HTTP_parse_parsed_message->msg().headers()().max__forwards()() = *$2;
               delete $2;
             }
             |MIME_VERSION CharString  {
               if($2) HTTP_parse_parsed_message->msg().headers()().mime__version()() = *$2;
               else HTTP_parse_parsed_message->msg().headers()().mime__version()() = "";
               delete $2;
             }
             |ORDERING_TYPE CharString  {
               if($2) HTTP_parse_parsed_message->msg().headers()().ordering__type()() = *$2;
               else HTTP_parse_parsed_message->msg().headers()().ordering__type()() = "";
               delete $2;
             }
             |ORIGIN CharString  {
               if($2) HTTP_parse_parsed_message->msg().headers()().origin()() = *$2;
               else HTTP_parse_parsed_message->msg().headers()().origin()() = "";
               delete $2;
             }
             |OVERWRITE TF  {
               HTTP_parse_parsed_message->msg().headers()().overwrite()() = *$2;
               delete $2;
             }
             |POSITION CharString  {
               if($2) HTTP_parse_parsed_message->msg().headers()().position()() = *$2;
               else HTTP_parse_parsed_message->msg().headers()().position()() = "";
               delete $2;
             }
             |PRAGMA Charstring_List  {
               int i = 0;
               if(HTTP_parse_parsed_message->msg().headers()().pragma().ispresent()) i = HTTP_parse_parsed_message->msg().headers()().pragma()().size_of();
               if($2) HTTP_parse_parsed_message->msg().headers()().pragma()()[i] = *$2;
               else HTTP_parse_parsed_message->msg().headers()().pragma()()[i][0] = "";
               delete $2;
             }
             |PREFER Charstring_List  {
               int i = 0;
               if(HTTP_parse_parsed_message->msg().headers()().prefer().ispresent()) i = HTTP_parse_parsed_message->msg().headers()().prefer()().size_of();
               if($2) HTTP_parse_parsed_message->msg().headers()().prefer()()[i] = *$2;
               else HTTP_parse_parsed_message->msg().headers()().prefer()()[i][0] = "";
               delete $2;
             }
             |PREFERENCE_APPLIED Charstring_List  {
               int i = 0;
               if(HTTP_parse_parsed_message->msg().headers()().preference__applied().ispresent()) i = HTTP_parse_parsed_message->msg().headers()().preference__applied()().size_of();
               if($2) HTTP_parse_parsed_message->msg().headers()().preference__applied()()[i] = *$2;
               else HTTP_parse_parsed_message->msg().headers()().preference__applied()()[i][0] = "";
               delete $2;
             }
             |PROXY_AUTHENTICATE CharString  {
               if($2) HTTP_parse_parsed_message->msg().headers()().proxy__authenticate()() = *$2;
               else HTTP_parse_parsed_message->msg().headers()().proxy__authenticate()() = "";
               delete $2;
             }
             |PROXY_AUTHORIZATION CharString  {
               if($2) HTTP_parse_parsed_message->msg().headers()().proxy__authorization()() = *$2;
               else HTTP_parse_parsed_message->msg().headers()().proxy__authorization()() = "";
               delete $2;
             }
             |RANGE CharString  {
               if($2) HTTP_parse_parsed_message->msg().headers()().range()() = *$2;
               else HTTP_parse_parsed_message->msg().headers()().range()() = "";
               delete $2;
             }
             |REFERER CharString  {
               if($2) HTTP_parse_parsed_message->msg().headers()().referer()() = *$2;
               else HTTP_parse_parsed_message->msg().headers()().referer()() = "";
               delete $2;
             }
             |RETRY_AFTER CharString  {
               if($2) HTTP_parse_parsed_message->msg().headers()().retry__after()() = *$2;
               else HTTP_parse_parsed_message->msg().headers()().retry__after()() = "";
               delete $2;
             }
             |SCHEDULE_REPLY TF  {
               HTTP_parse_parsed_message->msg().headers()().schedule__reply()() = *$2;
               delete $2;
             }
             |SCHEDULE_TAG CharString  {
               if($2) HTTP_parse_parsed_message->msg().headers()().schedule__tag()() = *$2;
               else HTTP_parse_parsed_message->msg().headers()().schedule__tag()() = "";
               delete $2;
             }
             |SEC_WEBSOCKET_ACCEPT CharString  {
               if($2) HTTP_parse_parsed_message->msg().headers()().sec__websocket__accept()() = *$2;
               else HTTP_parse_parsed_message->msg().headers()().sec__websocket__accept()() = "";
               delete $2;
             }
             |SEC_WEBSOCKET_EXTENSIONS CharString  {
               if($2) HTTP_parse_parsed_message->msg().headers()().sec__websocket__extensions()() = *$2;
               else HTTP_parse_parsed_message->msg().headers()().sec__websocket__extensions()() = "";
               delete $2;
             }
             |SEC_WEBSOCKET_KEY CharString  {
               if($2) HTTP_parse_parsed_message->msg().headers()().sec__websocket__key()() = *$2;
               else HTTP_parse_parsed_message->msg().headers()().sec__websocket__key()() = "";
               delete $2;
             }
             |SEC_WEBSOCKET_PROTOCOL CharString  {
               if($2) HTTP_parse_parsed_message->msg().headers()().sec__websocket__protocol()() = *$2;
               else HTTP_parse_parsed_message->msg().headers()().sec__websocket__protocol()() = "";
               delete $2;
             }
             |SEC_WEBSOCKET_VERSION CharString  {
               if($2) HTTP_parse_parsed_message->msg().headers()().sec__websocket__version()() = *$2;
               else HTTP_parse_parsed_message->msg().headers()().sec__websocket__version()() = "";
               delete $2;
             }
             |SERVER CharString  {
               if($2) HTTP_parse_parsed_message->msg().headers()().server()() = *$2;
               else HTTP_parse_parsed_message->msg().headers()().server()() = "";
               delete $2;
             }
             |SET_COOKIE CharString  {
               if($2) HTTP_parse_parsed_message->msg().headers()().set__cookie()() = *$2;
               else HTTP_parse_parsed_message->msg().headers()().set__cookie()() = "";
               delete $2;
             }
             |SLUG CharString  {
               if($2) HTTP_parse_parsed_message->msg().headers()().slug()() = *$2;
               else HTTP_parse_parsed_message->msg().headers()().slug()() = "";
               delete $2;
             }
             |STRICT_TRANSPORT_SECURITY CharString  {
               if($2) HTTP_parse_parsed_message->msg().headers()().strict__transport__security()() = *$2;
               else HTTP_parse_parsed_message->msg().headers()().strict__transport__security()() = "";
               delete $2;
             }
             |TE CharString  {
               if($2) HTTP_parse_parsed_message->msg().headers()().tE()() = *$2;
               else HTTP_parse_parsed_message->msg().headers()().tE()() = "";
               delete $2;
             }
             |TIMEOUT Charstring_List  {
               int i = 0;
               if(HTTP_parse_parsed_message->msg().headers()().tImeout().ispresent()) i = HTTP_parse_parsed_message->msg().headers()().tImeout()().size_of();
               if($2) HTTP_parse_parsed_message->msg().headers()().tImeout()()[i] = *$2;
               else HTTP_parse_parsed_message->msg().headers()().tImeout()()[i][0] = "";
               delete $2;
             }
             |TRAILER Charstring_List  {
               int i = 0;
               if(HTTP_parse_parsed_message->msg().headers()().trailer().ispresent()) i = HTTP_parse_parsed_message->msg().headers()().trailer()().size_of();
               if($2) HTTP_parse_parsed_message->msg().headers()().trailer()()[i] = *$2;
               else HTTP_parse_parsed_message->msg().headers()().trailer()()[i][0] = "";
               delete $2;
             }
             |TRANSFER_ENCODING Charstring_List  {
               int i = 0;
               if(HTTP_parse_parsed_message->msg().headers()().transfer__encoding().ispresent()) i = HTTP_parse_parsed_message->msg().headers()().transfer__encoding()().size_of();
               if($2) HTTP_parse_parsed_message->msg().headers()().transfer__encoding()()[i] = *$2;
               else HTTP_parse_parsed_message->msg().headers()().transfer__encoding()()[i][0] = "";
               delete $2;
             }
             |UPGRADE Charstring_List  {
               int i = 0;
               if(HTTP_parse_parsed_message->msg().headers()().upgrade().ispresent()) i = HTTP_parse_parsed_message->msg().headers()().upgrade()().size_of();
               if($2) HTTP_parse_parsed_message->msg().headers()().upgrade()()[i] = *$2;
               else HTTP_parse_parsed_message->msg().headers()().upgrade()()[i][0] = "";
               delete $2;
             }
             |USER_AGENT CharString  {
               if($2) HTTP_parse_parsed_message->msg().headers()().user__agent()() = *$2;
               else HTTP_parse_parsed_message->msg().headers()().user__agent()() = "";
               delete $2;
             }
             |VARY Charstring_List  {
               int i = 0;
               if(HTTP_parse_parsed_message->msg().headers()().vary().ispresent()) i = HTTP_parse_parsed_message->msg().headers()().vary()().size_of();
               if($2) HTTP_parse_parsed_message->msg().headers()().vary()()[i] = *$2;
               else HTTP_parse_parsed_message->msg().headers()().vary()()[i][0] = "";
               delete $2;
             }
             |VIA Charstring_List {
               int i = 0;
               if(HTTP_parse_parsed_message->msg().headers()().via().ispresent()) i = HTTP_parse_parsed_message->msg().headers()().via()().size_of();
               if($2) HTTP_parse_parsed_message->msg().headers()().via()()[i] = *$2;
               else HTTP_parse_parsed_message->msg().headers()().via()()[i][0] = "";
               delete $2;
             }
             |WWW_AUTHENTICATE Charstring_List  {
               int i = 0;
               if(HTTP_parse_parsed_message->msg().headers()().www__authenticate().ispresent()) i = HTTP_parse_parsed_message->msg().headers()().www__authenticate()().size_of();
               if($2) HTTP_parse_parsed_message->msg().headers()().www__authenticate()()[i] = *$2;
               else HTTP_parse_parsed_message->msg().headers()().www__authenticate()()[i][0] = "";
               delete $2;
             }
             |WARNING Charstring_List  {
               int i = 0;
               if(HTTP_parse_parsed_message->msg().headers()().warning().ispresent()) i = HTTP_parse_parsed_message->msg().headers()().warning()().size_of();
               if($2) HTTP_parse_parsed_message->msg().headers()().warning()()[i] = *$2;
               else HTTP_parse_parsed_message->msg().headers()().warning()()[i][0] = "";
               delete $2;
             }
             |UNDEFINED_HEADERNAME COLON CharString  {
               int i = 0;
               if(HTTP_parse_parsed_message->msg().headers()().undefined__header__list().ispresent()) i = HTTP_parse_parsed_message->msg().headers()().undefined__header__list()().size_of();
               
               HTTP_parse_parsed_message->msg().headers()().undefined__header__list()()[i].headerName() = *$1;
               
               if($3) HTTP_parse_parsed_message->msg().headers()().undefined__header__list()()[i].headerValue() = *$3;
               else HTTP_parse_parsed_message->msg().headers()().undefined__header__list()()[i].headerValue() = "";
               
               delete $1;
               delete $3;
             }

Charstring_List: /* empty */ { $$ = NULL; } 
               | CHARSTR {
                   $$ = new General__Types::CharstringList;
                   (*$$)[0] = *$1;
                   delete $1;
                 }
               | Charstring_List COMMA CHARSTR {
                   int a = $1->size_of();
                   $$ = $1;
                   (*$$)[a] = *$3;
                   delete $3;
                 }
                 
CharString: /* empty */ { $$ = NULL; }
          | CHARSTR {
            $$ = new CHARSTRING(*$1);
            delete $1;
          }

Method_List: Method {
                  $$ = new Method__List;
                  (*$$)[0] = *$1;
                  delete $1;
                }
              | Method_List COMMA Method {
                  int a = $1->size_of();
                  $$ = $1;
                  (*$$)[a] = *$3;
                  delete $3;
                }

TF: T { $$ = new TF(0); }
  | F { $$ = new TF(1); }





