/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     REASON_PHRASE = 258,
     URI = 259,
     CHARSTR = 260,
     UNDEFINED_HEADERNAME = 261,
     VERSION = 262,
     STATUS_CODE = 263,
     NUM = 264,
     HTTP = 265,
     DOT = 266,
     SP = 267,
     CRLF = 268,
     CRLFCRLF = 269,
     GET = 270,
     HEAD = 271,
     POST = 272,
     PUT = 273,
     DELETE = 274,
     CONNECT = 275,
     OPTIONS = 276,
     TRACE = 277,
     COMMA = 278,
     COLON = 279,
     ACCEPT = 280,
     ACCEPT_CHARSET = 281,
     ACCEPT_ENCODING = 282,
     ACCEPT_LANGUAGE = 283,
     ACCEPT_RANGES = 284,
     AGE = 285,
     ALLOW = 286,
     AUTHORIZATION = 287,
     CACHE_CONTROL = 288,
     CONNECTION = 289,
     CONTENT_DISPOSITION = 290,
     CONTENT_ENCODING = 291,
     CONTENT_LANGUAGE = 292,
     CONTENT_LENGTH = 293,
     CONTENT_LOCATION = 294,
     CONTENT_RANGE = 295,
     CONTENT_TYPE = 296,
     COOKIE = 297,
     DASL = 298,
     DAV = 299,
     DATE = 300,
     DEPTH = 301,
     DESTINATION = 302,
     ETAG = 303,
     EXPECT = 304,
     EXPIRES = 305,
     FORWARDED = 306,
     FROM = 307,
     HOST = 308,
     HTTP2_SETTINGS = 309,
     IF = 310,
     IF_MATCH = 311,
     IF_MODIFIED_SINCE = 312,
     IF_NONE_MATCH = 313,
     IF_RANGE = 314,
     IF_SCHEDULE_TAG_MATCH = 315,
     IF_UNMODIFIED_SINCE = 316,
     LAST_MODIFIED = 317,
     LOCATION = 318,
     LOCK_TOKEN = 319,
     MAX_FORWARDS = 320,
     MIME_VERSION = 321,
     ORDERING_TYPE = 322,
     ORIGIN = 323,
     OVERWRITE = 324,
     T = 325,
     F = 326,
     POSITION = 327,
     PRAGMA = 328,
     PREFER = 329,
     PREFERENCE_APPLIED = 330,
     PROXY_AUTHENTICATE = 331,
     PROXY_AUTHORIZATION = 332,
     RANGE = 333,
     REFERER = 334,
     RETRY_AFTER = 335,
     SCHEDULE_REPLY = 336,
     SCHEDULE_TAG = 337,
     SEC_WEBSOCKET_ACCEPT = 338,
     SEC_WEBSOCKET_EXTENSIONS = 339,
     SEC_WEBSOCKET_KEY = 340,
     SEC_WEBSOCKET_PROTOCOL = 341,
     SEC_WEBSOCKET_VERSION = 342,
     SERVER = 343,
     SET_COOKIE = 344,
     SLUG = 345,
     STRICT_TRANSPORT_SECURITY = 346,
     TE = 347,
     TIMEOUT = 348,
     TRAILER = 349,
     TRANSFER_ENCODING = 350,
     UPGRADE = 351,
     USER_AGENT = 352,
     VARY = 353,
     VIA = 354,
     WWW_AUTHENTICATE = 355,
     WARNING = 356
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 34 "HTTP_parse.y"

  CHARSTRING*                   charstring;
  INTEGER*                      integer;
  HTTP__Types::Method*          method;
  General__Types::CharstringList*  charstring_list;
  HTTP__Types::Method__List*    methodlist;
  HTTP__Types::TF*              tf;



/* Line 2068 of yacc.c  */
#line 162 "HTTP_parse_.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE HTTP_parse_lval;


