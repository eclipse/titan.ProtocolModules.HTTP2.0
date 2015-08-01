/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse         HTTP_parse_parse
#define yylex           HTTP_parse_lex
#define yyerror         HTTP_parse_error
#define yylval          HTTP_parse_lval
#define yychar          HTTP_parse_char
#define yydebug         HTTP_parse_debug
#define yynerrs         HTTP_parse_nerrs


/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "HTTP_parse.y"

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



/* Line 268 of yacc.c  */
#line 112 "HTTP_parse_.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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

/* Line 293 of yacc.c  */
#line 34 "HTTP_parse.y"

  CHARSTRING*                   charstring;
  INTEGER*                      integer;
  HTTP__Types::Method*          method;
  General__Types::CharstringList*  charstring_list;
  HTTP__Types::Method__List*    methodlist;
  HTTP__Types::TF*              tf;



/* Line 293 of yacc.c  */
#line 260 "HTTP_parse_.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 272 "HTTP_parse_.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  17
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   240

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  102
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNRULES -- Number of states.  */
#define YYNSTATES  202

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   356

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    19,    21,    23,    25,
      27,    29,    31,    33,    35,    38,    47,    51,    53,    55,
      59,    62,    65,    68,    71,    74,    77,    80,    83,    86,
      89,    92,    95,    98,   101,   104,   107,   110,   113,   116,
     119,   122,   125,   128,   131,   134,   137,   140,   143,   146,
     149,   152,   155,   158,   161,   164,   167,   170,   173,   176,
     179,   182,   185,   188,   191,   194,   197,   200,   203,   206,
     209,   212,   215,   218,   221,   224,   227,   230,   233,   236,
     239,   242,   245,   248,   251,   254,   257,   260,   263,   266,
     269,   272,   275,   278,   281,   284,   288,   289,   291,   295,
     296,   298,   300,   304,   306
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
     103,     0,    -1,   104,    -1,   107,    -1,   105,   109,    -1,
     106,    12,     4,    12,    10,     7,    11,     7,    -1,    15,
      -1,    16,    -1,    17,    -1,    18,    -1,    19,    -1,    20,
      -1,    21,    -1,    22,    -1,   108,   109,    -1,    10,     7,
      11,     7,    12,     8,    12,     3,    -1,    13,   110,    14,
      -1,    14,    -1,   111,    -1,   110,    13,   111,    -1,    25,
     112,    -1,    26,   112,    -1,    27,   112,    -1,    28,   112,
      -1,    29,   112,    -1,    30,     9,    -1,    31,   114,    -1,
      32,   113,    -1,    33,   112,    -1,    34,   112,    -1,    35,
     113,    -1,    36,   112,    -1,    37,   112,    -1,    38,     9,
      -1,    39,   113,    -1,    40,   113,    -1,    41,   113,    -1,
      42,   113,    -1,    43,   112,    -1,    44,   112,    -1,    45,
     113,    -1,    46,   113,    -1,    47,   113,    -1,    48,   113,
      -1,    49,   113,    -1,    50,   113,    -1,    51,   112,    -1,
      52,   113,    -1,    53,   113,    -1,    54,   113,    -1,    55,
     113,    -1,    56,   112,    -1,    57,   113,    -1,    58,   112,
      -1,    59,   113,    -1,    60,   113,    -1,    61,   113,    -1,
      62,   113,    -1,    63,   113,    -1,    64,   113,    -1,    65,
       9,    -1,    66,   113,    -1,    67,   113,    -1,    68,   113,
      -1,    69,   115,    -1,    72,   113,    -1,    73,   112,    -1,
      74,   112,    -1,    75,   112,    -1,    76,   113,    -1,    77,
     113,    -1,    78,   113,    -1,    79,   113,    -1,    80,   113,
      -1,    81,   115,    -1,    82,   113,    -1,    83,   113,    -1,
      84,   113,    -1,    85,   113,    -1,    86,   113,    -1,    87,
     113,    -1,    88,   113,    -1,    89,   113,    -1,    90,   113,
      -1,    91,   113,    -1,    92,   113,    -1,    93,   112,    -1,
      94,   112,    -1,    95,   112,    -1,    96,   112,    -1,    97,
     113,    -1,    98,   112,    -1,    99,   112,    -1,   100,   112,
      -1,   101,   112,    -1,     6,    24,   113,    -1,    -1,     5,
      -1,   112,    23,     5,    -1,    -1,     5,    -1,   106,    -1,
     114,    23,   106,    -1,    70,    -1,    71,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    64,    64,    65,    67,    72,    86,    87,    88,    89,
      90,    91,    92,    93,    95,   100,   113,   114,   116,   117,
     119,   126,   133,   140,   147,   154,   158,   162,   167,   174,
     181,   186,   193,   200,   204,   209,   214,   219,   224,   231,
     238,   243,   248,   253,   258,   263,   268,   275,   280,   285,
     290,   295,   302,   307,   314,   319,   324,   329,   334,   339,
     344,   348,   353,   358,   363,   367,   372,   379,   386,   393,
     398,   403,   408,   413,   418,   422,   427,   432,   437,   442,
     447,   452,   457,   462,   467,   472,   477,   484,   491,   498,
     505,   510,   517,   524,   531,   538,   551,   552,   557,   564,
     565,   570,   575,   582,   583
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "REASON_PHRASE", "URI", "CHARSTR",
  "UNDEFINED_HEADERNAME", "VERSION", "STATUS_CODE", "NUM", "HTTP", "DOT",
  "SP", "CRLF", "CRLFCRLF", "GET", "HEAD", "POST", "PUT", "DELETE",
  "CONNECT", "OPTIONS", "TRACE", "COMMA", "COLON", "ACCEPT",
  "ACCEPT_CHARSET", "ACCEPT_ENCODING", "ACCEPT_LANGUAGE", "ACCEPT_RANGES",
  "AGE", "ALLOW", "AUTHORIZATION", "CACHE_CONTROL", "CONNECTION",
  "CONTENT_DISPOSITION", "CONTENT_ENCODING", "CONTENT_LANGUAGE",
  "CONTENT_LENGTH", "CONTENT_LOCATION", "CONTENT_RANGE", "CONTENT_TYPE",
  "COOKIE", "DASL", "DAV", "DATE", "DEPTH", "DESTINATION", "ETAG",
  "EXPECT", "EXPIRES", "FORWARDED", "FROM", "HOST", "HTTP2_SETTINGS", "IF",
  "IF_MATCH", "IF_MODIFIED_SINCE", "IF_NONE_MATCH", "IF_RANGE",
  "IF_SCHEDULE_TAG_MATCH", "IF_UNMODIFIED_SINCE", "LAST_MODIFIED",
  "LOCATION", "LOCK_TOKEN", "MAX_FORWARDS", "MIME_VERSION",
  "ORDERING_TYPE", "ORIGIN", "OVERWRITE", "T", "F", "POSITION", "PRAGMA",
  "PREFER", "PREFERENCE_APPLIED", "PROXY_AUTHENTICATE",
  "PROXY_AUTHORIZATION", "RANGE", "REFERER", "RETRY_AFTER",
  "SCHEDULE_REPLY", "SCHEDULE_TAG", "SEC_WEBSOCKET_ACCEPT",
  "SEC_WEBSOCKET_EXTENSIONS", "SEC_WEBSOCKET_KEY",
  "SEC_WEBSOCKET_PROTOCOL", "SEC_WEBSOCKET_VERSION", "SERVER",
  "SET_COOKIE", "SLUG", "STRICT_TRANSPORT_SECURITY", "TE", "TIMEOUT",
  "TRAILER", "TRANSFER_ENCODING", "UPGRADE", "USER_AGENT", "VARY", "VIA",
  "WWW_AUTHENTICATE", "WARNING", "$accept", "http_message", "request",
  "RequestLine", "Method", "response", "StatusLine", "HTTP_Headers",
  "HTTP_Header_list", "HTTP_Header", "Charstring_List", "CharString",
  "Method_List", "TF", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   102,   103,   103,   104,   105,   106,   106,   106,   106,
     106,   106,   106,   106,   107,   108,   109,   109,   110,   110,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   112,   112,   112,   113,
     113,   114,   114,   115,   115
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     8,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     8,     3,     1,     1,     3,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     3,     0,     1,     3,     0,
       1,     1,     3,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     6,     7,     8,     9,    10,    11,    12,    13,
       0,     2,     0,     0,     3,     0,     0,     1,     0,    17,
       4,     0,    14,     0,     0,    96,    96,    96,    96,    96,
       0,     0,    99,    96,    96,    99,    96,    96,     0,    99,
      99,    99,    99,    96,    96,    99,    99,    99,    99,    99,
      99,    96,    99,    99,    99,    99,    96,    99,    96,    99,
      99,    99,    99,    99,    99,     0,    99,    99,    99,     0,
      99,    96,    96,    96,    99,    99,    99,    99,    99,     0,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    96,    96,    96,    96,    99,    96,    96,    96,    96,
       0,    18,     0,     0,    99,    97,    20,    21,    22,    23,
      24,    25,   101,    26,   100,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,   103,   104,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,     0,    16,     0,     0,    95,
       0,     0,    19,     0,     0,    98,   102,     0,     0,     0,
      15,     5
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    10,    11,    12,    13,    14,    15,    20,   100,   101,
     106,   115,   113,   154
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -66
static const yytype_int8 yypact[] =
{
      -8,    10,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,
      18,   -66,   -10,     7,   -66,   -10,    54,   -66,    -5,   -66,
     -66,    62,   -66,    94,    78,    98,    98,    98,    98,    98,
      97,   115,   104,    98,    98,   104,    98,    98,   101,   104,
     104,   104,   104,    98,    98,   104,   104,   104,   104,   104,
     104,    98,   104,   104,   104,   104,    98,   104,    98,   104,
     104,   104,   104,   104,   104,   102,   104,   104,   104,   -65,
     104,    98,    98,    98,   104,   104,   104,   104,   104,   -65,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,    98,    98,    98,    98,   104,    98,    98,    98,    98,
       2,   -66,   100,   105,   104,   -66,    90,    90,    90,    90,
      90,   -66,   -66,    93,   -66,   -66,    90,    90,   -66,    90,
      90,   -66,   -66,   -66,   -66,   -66,    90,    90,   -66,   -66,
     -66,   -66,   -66,   -66,    90,   -66,   -66,   -66,   -66,    90,
     -66,    90,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,
     -66,   -66,   -66,   -66,   -66,   -66,    90,    90,    90,   -66,
     -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,
     -66,   -66,   -66,   -66,   -66,   -66,    90,    90,    90,    90,
     -66,    90,    90,    90,    90,    -5,   -66,   108,   111,   -66,
     116,   115,   -66,   113,   112,   -66,   -66,   114,   120,   119,
     -66,   -66
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -66,   -66,   -66,   -66,   -31,   -66,   -66,   123,   -66,   -57,
      71,   136,   -66,    60
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
     112,    24,     1,    18,    19,   152,   153,     2,     3,     4,
       5,     6,     7,     8,     9,   185,   186,    16,    17,    21,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    23,   102,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   107,   108,   109,
     110,   103,   104,   105,   116,   117,   111,   119,   120,   114,
     121,   148,   187,   190,   126,   127,   191,   188,   193,   194,
     197,   195,   134,   200,   198,   199,   201,   139,   192,   141,
       2,     3,     4,     5,     6,     7,     8,     9,    22,   164,
       0,     0,   156,   157,   158,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     196,     0,   176,   177,   178,   179,     0,   181,   182,   183,
     184,   118,     0,     0,     0,   122,   123,   124,   125,     0,
       0,   128,   129,   130,   131,   132,   133,     0,   135,   136,
     137,   138,     0,   140,     0,   142,   143,   144,   145,   146,
     147,     0,   149,   150,   151,     0,   155,     0,     0,     0,
     159,   160,   161,   162,   163,     0,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,     0,     0,     0,
       0,   180,     0,     0,     0,     0,     0,     0,     0,     0,
     189
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-66))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      31,     6,    10,    13,    14,    70,    71,    15,    16,    17,
      18,    19,    20,    21,    22,    13,    14,     7,     0,    12,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    11,     4,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,    26,    27,    28,
      29,     7,    24,     5,    33,    34,     9,    36,    37,     5,
       9,     9,    12,    23,    43,    44,    23,    12,    10,     8,
       7,     5,    51,     3,    12,    11,     7,    56,   185,    58,
      15,    16,    17,    18,    19,    20,    21,    22,    15,    79,
      -1,    -1,    71,    72,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     191,    -1,    91,    92,    93,    94,    -1,    96,    97,    98,
      99,    35,    -1,    -1,    -1,    39,    40,    41,    42,    -1,
      -1,    45,    46,    47,    48,    49,    50,    -1,    52,    53,
      54,    55,    -1,    57,    -1,    59,    60,    61,    62,    63,
      64,    -1,    66,    67,    68,    -1,    70,    -1,    -1,    -1,
      74,    75,    76,    77,    78,    -1,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    -1,    -1,    -1,
      -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     104
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    10,    15,    16,    17,    18,    19,    20,    21,    22,
     103,   104,   105,   106,   107,   108,     7,     0,    13,    14,
     109,    12,   109,    11,     6,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     110,   111,     4,     7,    24,     5,   112,   112,   112,   112,
     112,     9,   106,   114,     5,   113,   112,   112,   113,   112,
     112,     9,   113,   113,   113,   113,   112,   112,   113,   113,
     113,   113,   113,   113,   112,   113,   113,   113,   113,   112,
     113,   112,   113,   113,   113,   113,   113,   113,     9,   113,
     113,   113,    70,    71,   115,   113,   112,   112,   112,   113,
     113,   113,   113,   113,   115,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   112,   112,   112,   112,
     113,   112,   112,   112,   112,    13,    14,    12,    12,   113,
      23,    23,   111,    10,     8,     5,   106,     7,    12,    11,
       3,     7
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {
      case 3: /* "REASON_PHRASE" */

/* Line 1391 of yacc.c  */
#line 42 "HTTP_parse.y"
	{ delete (yyvaluep->charstring);};

/* Line 1391 of yacc.c  */
#line 1410 "HTTP_parse_.tab.c"
	break;
      case 4: /* "URI" */

/* Line 1391 of yacc.c  */
#line 42 "HTTP_parse.y"
	{ delete (yyvaluep->charstring);};

/* Line 1391 of yacc.c  */
#line 1419 "HTTP_parse_.tab.c"
	break;
      case 5: /* "CHARSTR" */

/* Line 1391 of yacc.c  */
#line 42 "HTTP_parse.y"
	{ delete (yyvaluep->charstring);};

/* Line 1391 of yacc.c  */
#line 1428 "HTTP_parse_.tab.c"
	break;
      case 6: /* "UNDEFINED_HEADERNAME" */

/* Line 1391 of yacc.c  */
#line 42 "HTTP_parse.y"
	{ delete (yyvaluep->charstring);};

/* Line 1391 of yacc.c  */
#line 1437 "HTTP_parse_.tab.c"
	break;
      case 7: /* "VERSION" */

/* Line 1391 of yacc.c  */
#line 42 "HTTP_parse.y"
	{ delete (yyvaluep->integer);};

/* Line 1391 of yacc.c  */
#line 1446 "HTTP_parse_.tab.c"
	break;
      case 8: /* "STATUS_CODE" */

/* Line 1391 of yacc.c  */
#line 42 "HTTP_parse.y"
	{ delete (yyvaluep->integer);};

/* Line 1391 of yacc.c  */
#line 1455 "HTTP_parse_.tab.c"
	break;
      case 9: /* "NUM" */

/* Line 1391 of yacc.c  */
#line 42 "HTTP_parse.y"
	{ delete (yyvaluep->integer);};

/* Line 1391 of yacc.c  */
#line 1464 "HTTP_parse_.tab.c"
	break;
      case 106: /* "Method" */

/* Line 1391 of yacc.c  */
#line 42 "HTTP_parse.y"
	{ delete (yyvaluep->method);};

/* Line 1391 of yacc.c  */
#line 1473 "HTTP_parse_.tab.c"
	break;
      case 112: /* "Charstring_List" */

/* Line 1391 of yacc.c  */
#line 42 "HTTP_parse.y"
	{ delete (yyvaluep->charstring_list);};

/* Line 1391 of yacc.c  */
#line 1482 "HTTP_parse_.tab.c"
	break;
      case 113: /* "CharString" */

/* Line 1391 of yacc.c  */
#line 42 "HTTP_parse.y"
	{ delete (yyvaluep->charstring);};

/* Line 1391 of yacc.c  */
#line 1491 "HTTP_parse_.tab.c"
	break;
      case 114: /* "Method_List" */

/* Line 1391 of yacc.c  */
#line 42 "HTTP_parse.y"
	{ delete (yyvaluep->methodlist);};

/* Line 1391 of yacc.c  */
#line 1500 "HTTP_parse_.tab.c"
	break;
      case 115: /* "TF" */

/* Line 1391 of yacc.c  */
#line 42 "HTTP_parse.y"
	{ delete (yyvaluep->tf);};

/* Line 1391 of yacc.c  */
#line 1509 "HTTP_parse_.tab.c"
	break;

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1806 of yacc.c  */
#line 64 "HTTP_parse.y"
    {YYACCEPT;}
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 65 "HTTP_parse.y"
    {YYACCEPT;}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 68 "HTTP_parse.y"
    {  
           HTTP_parse_parsed_message->msg().body() = OMIT_VALUE;
         }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 73 "HTTP_parse.y"
    {
               HTTP_parse_parsed_message->msg().start__line().request__line().method() = *(yyvsp[(1) - (8)].method);
               HTTP_parse_parsed_message->msg().start__line().request__line().request__target() = *(yyvsp[(3) - (8)].charstring);
               HTTP_parse_parsed_message->msg().start__line().request__line().version__major() =  *(yyvsp[(6) - (8)].integer);
               HTTP_parse_parsed_message->msg().start__line().request__line().version__minor() =  *(yyvsp[(8) - (8)].integer);
               
               delete (yyvsp[(1) - (8)].method);
               delete (yyvsp[(3) - (8)].charstring);
               delete (yyvsp[(6) - (8)].integer);
               delete (yyvsp[(8) - (8)].integer);
             }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 86 "HTTP_parse.y"
    { (yyval.method)=new Method(0); }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 87 "HTTP_parse.y"
    { (yyval.method)=new Method(1); }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 88 "HTTP_parse.y"
    { (yyval.method)=new Method(2); }
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 89 "HTTP_parse.y"
    { (yyval.method)=new Method(3); }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 90 "HTTP_parse.y"
    { (yyval.method)=new Method(4); }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 91 "HTTP_parse.y"
    { (yyval.method)=new Method(5); }
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 92 "HTTP_parse.y"
    { (yyval.method)=new Method(6); }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 93 "HTTP_parse.y"
    { (yyval.method)=new Method(7); }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 96 "HTTP_parse.y"
    {
            HTTP_parse_parsed_message->msg().body() = OMIT_VALUE;
          }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 101 "HTTP_parse.y"
    {
              HTTP_parse_parsed_message->msg().start__line().status__line().version__major() =  *(yyvsp[(2) - (8)].integer);
              HTTP_parse_parsed_message->msg().start__line().status__line().version__minor() =  *(yyvsp[(4) - (8)].integer);
              HTTP_parse_parsed_message->msg().start__line().status__line().status__code() =  *(yyvsp[(6) - (8)].integer);
              HTTP_parse_parsed_message->msg().start__line().status__line().reason__phrase() =  *(yyvsp[(8) - (8)].charstring);
              
              delete (yyvsp[(2) - (8)].integer);
              delete (yyvsp[(4) - (8)].integer);
              delete (yyvsp[(6) - (8)].integer);
              delete (yyvsp[(8) - (8)].charstring);
            }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 113 "HTTP_parse.y"
    { /* empty */ }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 114 "HTTP_parse.y"
    { HTTP_parse_parsed_message->msg().headers() = OMIT_VALUE; }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 116 "HTTP_parse.y"
    { /* empty */ }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 117 "HTTP_parse.y"
    { /* empty */ }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 119 "HTTP_parse.y"
    {
               int i = 0;
               if(HTTP_parse_parsed_message->msg().headers()().accept().ispresent()) i = HTTP_parse_parsed_message->msg().headers()().accept()().size_of();
               if((yyvsp[(2) - (2)].charstring_list)) HTTP_parse_parsed_message->msg().headers()().accept()()[i] = *(yyvsp[(2) - (2)].charstring_list);
               else HTTP_parse_parsed_message->msg().headers()().accept()()[i][0] = "";
               delete (yyvsp[(2) - (2)].charstring_list);
             }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 126 "HTTP_parse.y"
    {
               int i = 0;
               if(HTTP_parse_parsed_message->msg().headers()().accept__charset().ispresent()) i = HTTP_parse_parsed_message->msg().headers()().accept__charset()().size_of();
               if((yyvsp[(2) - (2)].charstring_list)) HTTP_parse_parsed_message->msg().headers()().accept__charset()()[i] = *(yyvsp[(2) - (2)].charstring_list);
               else HTTP_parse_parsed_message->msg().headers()().accept__charset()()[i][0] = "";
               delete (yyvsp[(2) - (2)].charstring_list);
             }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 133 "HTTP_parse.y"
    {
               int i = 0;
               if(HTTP_parse_parsed_message->msg().headers()().accept__encoding().ispresent()) i = HTTP_parse_parsed_message->msg().headers()().accept__encoding()().size_of();
               if((yyvsp[(2) - (2)].charstring_list)) HTTP_parse_parsed_message->msg().headers()().accept__encoding()()[i] = *(yyvsp[(2) - (2)].charstring_list);
               else HTTP_parse_parsed_message->msg().headers()().accept__encoding()()[i][0] = "";
               delete (yyvsp[(2) - (2)].charstring_list);
             }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 140 "HTTP_parse.y"
    {
               int i = 0;
               if(HTTP_parse_parsed_message->msg().headers()().accept__language().ispresent()) i = HTTP_parse_parsed_message->msg().headers()().accept__language()().size_of();
               if((yyvsp[(2) - (2)].charstring_list)) HTTP_parse_parsed_message->msg().headers()().accept__language()()[i] = *(yyvsp[(2) - (2)].charstring_list);
               else HTTP_parse_parsed_message->msg().headers()().accept__language()()[i][0] = "";
               delete (yyvsp[(2) - (2)].charstring_list);
             }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 147 "HTTP_parse.y"
    {
               int i = 0;
               if(HTTP_parse_parsed_message->msg().headers()().accept__ranges().ispresent()) i = HTTP_parse_parsed_message->msg().headers()().accept__ranges()().size_of();
               if((yyvsp[(2) - (2)].charstring_list)) HTTP_parse_parsed_message->msg().headers()().accept__ranges()()[i] = *(yyvsp[(2) - (2)].charstring_list);
               else HTTP_parse_parsed_message->msg().headers()().accept__ranges()()[i][0] = "";
               delete (yyvsp[(2) - (2)].charstring_list);
             }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 154 "HTTP_parse.y"
    {
               HTTP_parse_parsed_message->msg().headers()().age()() = *(yyvsp[(2) - (2)].integer);
               delete (yyvsp[(2) - (2)].integer);
             }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 158 "HTTP_parse.y"
    {
               HTTP_parse_parsed_message->msg().headers()().allow()() = *(yyvsp[(2) - (2)].methodlist);
               delete (yyvsp[(2) - (2)].methodlist);
             }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 162 "HTTP_parse.y"
    {
               if((yyvsp[(2) - (2)].charstring)) HTTP_parse_parsed_message->msg().headers()().authorization()() = *(yyvsp[(2) - (2)].charstring);
               else HTTP_parse_parsed_message->msg().headers()().authorization()() = "";
               delete (yyvsp[(2) - (2)].charstring);
             }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 167 "HTTP_parse.y"
    {
               int i = 0;
               if(HTTP_parse_parsed_message->msg().headers()().cache__control().ispresent()) i = HTTP_parse_parsed_message->msg().headers()().cache__control()().size_of();
               if((yyvsp[(2) - (2)].charstring_list)) HTTP_parse_parsed_message->msg().headers()().cache__control()()[i] = *(yyvsp[(2) - (2)].charstring_list);
               else HTTP_parse_parsed_message->msg().headers()().cache__control()()[i][0] = "";
               delete (yyvsp[(2) - (2)].charstring_list);
             }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 174 "HTTP_parse.y"
    {
               int i = 0;
               if(HTTP_parse_parsed_message->msg().headers()().connection().ispresent()) i = HTTP_parse_parsed_message->msg().headers()().connection()().size_of();
               if((yyvsp[(2) - (2)].charstring_list)) HTTP_parse_parsed_message->msg().headers()().connection()()[i] = *(yyvsp[(2) - (2)].charstring_list);
               else HTTP_parse_parsed_message->msg().headers()().connection()()[i][0] = "";
               delete (yyvsp[(2) - (2)].charstring_list);
             }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 181 "HTTP_parse.y"
    {
               if((yyvsp[(2) - (2)].charstring)) HTTP_parse_parsed_message->msg().headers()().content__disposition()() = *(yyvsp[(2) - (2)].charstring);
               else HTTP_parse_parsed_message->msg().headers()().content__disposition()() = "";
               delete (yyvsp[(2) - (2)].charstring);
             }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 186 "HTTP_parse.y"
    {
               int i = 0;
               if(HTTP_parse_parsed_message->msg().headers()().content__encoding().ispresent()) i = HTTP_parse_parsed_message->msg().headers()().content__encoding()().size_of();
               if((yyvsp[(2) - (2)].charstring_list)) HTTP_parse_parsed_message->msg().headers()().content__encoding()()[i] = *(yyvsp[(2) - (2)].charstring_list);
               else HTTP_parse_parsed_message->msg().headers()().content__encoding()()[i][0] = "";
               delete (yyvsp[(2) - (2)].charstring_list);
             }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 193 "HTTP_parse.y"
    {
               int i = 0;
               if(HTTP_parse_parsed_message->msg().headers()().content__language().ispresent()) i = HTTP_parse_parsed_message->msg().headers()().content__language()().size_of();
               if((yyvsp[(2) - (2)].charstring_list)) HTTP_parse_parsed_message->msg().headers()().content__language()()[i] = *(yyvsp[(2) - (2)].charstring_list);
               else HTTP_parse_parsed_message->msg().headers()().content__language()()[i][0] = "";
               delete (yyvsp[(2) - (2)].charstring_list);
             }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 200 "HTTP_parse.y"
    {
               HTTP_parse_parsed_message->msg().headers()().content__length()() = *(yyvsp[(2) - (2)].integer);
               delete (yyvsp[(2) - (2)].integer);
             }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 204 "HTTP_parse.y"
    {
               if((yyvsp[(2) - (2)].charstring)) HTTP_parse_parsed_message->msg().headers()().content__location()() = *(yyvsp[(2) - (2)].charstring);
               else HTTP_parse_parsed_message->msg().headers()().content__location()() = "";
               delete (yyvsp[(2) - (2)].charstring);
             }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 209 "HTTP_parse.y"
    {
               if((yyvsp[(2) - (2)].charstring)) HTTP_parse_parsed_message->msg().headers()().content__range()() = *(yyvsp[(2) - (2)].charstring);
               else HTTP_parse_parsed_message->msg().headers()().content__range()() = "";
               delete (yyvsp[(2) - (2)].charstring);
             }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 214 "HTTP_parse.y"
    {
               if((yyvsp[(2) - (2)].charstring)) HTTP_parse_parsed_message->msg().headers()().content__type()() = *(yyvsp[(2) - (2)].charstring);
               else HTTP_parse_parsed_message->msg().headers()().content__type()() = "";
               delete (yyvsp[(2) - (2)].charstring);
             }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 219 "HTTP_parse.y"
    {
               if((yyvsp[(2) - (2)].charstring)) HTTP_parse_parsed_message->msg().headers()().cookie()() = *(yyvsp[(2) - (2)].charstring);
               else HTTP_parse_parsed_message->msg().headers()().cookie()() = "";
               delete (yyvsp[(2) - (2)].charstring);
             }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 224 "HTTP_parse.y"
    {
               int i = 0;
               if(HTTP_parse_parsed_message->msg().headers()().dasl().ispresent()) i = HTTP_parse_parsed_message->msg().headers()().dasl()().size_of();
               if((yyvsp[(2) - (2)].charstring_list)) HTTP_parse_parsed_message->msg().headers()().dasl()()[i] = *(yyvsp[(2) - (2)].charstring_list);
               else HTTP_parse_parsed_message->msg().headers()().dasl()()[i][0] = "";
               delete (yyvsp[(2) - (2)].charstring_list);
             }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 231 "HTTP_parse.y"
    {
               int i = 0;
               if(HTTP_parse_parsed_message->msg().headers()().dav().ispresent()) i = HTTP_parse_parsed_message->msg().headers()().dav()().size_of();
               if((yyvsp[(2) - (2)].charstring_list)) HTTP_parse_parsed_message->msg().headers()().dav()()[i] = *(yyvsp[(2) - (2)].charstring_list);
               else HTTP_parse_parsed_message->msg().headers()().dav()()[i][0] = "";
               delete (yyvsp[(2) - (2)].charstring_list);
             }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 238 "HTTP_parse.y"
    {
               if((yyvsp[(2) - (2)].charstring)) HTTP_parse_parsed_message->msg().headers()().date()() = *(yyvsp[(2) - (2)].charstring);
               else HTTP_parse_parsed_message->msg().headers()().date()() = "";
               delete (yyvsp[(2) - (2)].charstring);
             }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 243 "HTTP_parse.y"
    {
               if((yyvsp[(2) - (2)].charstring)) HTTP_parse_parsed_message->msg().headers()().depth()() = *(yyvsp[(2) - (2)].charstring);
               else HTTP_parse_parsed_message->msg().headers()().depth()() = "";
               delete (yyvsp[(2) - (2)].charstring);
             }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 248 "HTTP_parse.y"
    {
               if((yyvsp[(2) - (2)].charstring)) HTTP_parse_parsed_message->msg().headers()().destination()() = *(yyvsp[(2) - (2)].charstring);
               else HTTP_parse_parsed_message->msg().headers()().destination()() = "";
               delete (yyvsp[(2) - (2)].charstring);
             }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 253 "HTTP_parse.y"
    {
               if((yyvsp[(2) - (2)].charstring)) HTTP_parse_parsed_message->msg().headers()().etag()() = *(yyvsp[(2) - (2)].charstring);
               else HTTP_parse_parsed_message->msg().headers()().etag()() = "";
               delete (yyvsp[(2) - (2)].charstring);
             }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 258 "HTTP_parse.y"
    {
               if((yyvsp[(2) - (2)].charstring)) HTTP_parse_parsed_message->msg().headers()().expect()() = *(yyvsp[(2) - (2)].charstring);
               else HTTP_parse_parsed_message->msg().headers()().expect()() = "";
               delete (yyvsp[(2) - (2)].charstring);
             }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 263 "HTTP_parse.y"
    {
               if((yyvsp[(2) - (2)].charstring)) HTTP_parse_parsed_message->msg().headers()().expires()() = *(yyvsp[(2) - (2)].charstring);
               else HTTP_parse_parsed_message->msg().headers()().expires()() = "";
               delete (yyvsp[(2) - (2)].charstring);
             }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 268 "HTTP_parse.y"
    {
               int i = 0;
               if(HTTP_parse_parsed_message->msg().headers()().forwarded().ispresent()) i = HTTP_parse_parsed_message->msg().headers()().forwarded()().size_of();
               if((yyvsp[(2) - (2)].charstring_list)) HTTP_parse_parsed_message->msg().headers()().forwarded()()[i] = *(yyvsp[(2) - (2)].charstring_list);
               else HTTP_parse_parsed_message->msg().headers()().forwarded()()[i][0] = "";
               delete (yyvsp[(2) - (2)].charstring_list);
             }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 275 "HTTP_parse.y"
    {
               if((yyvsp[(2) - (2)].charstring)) HTTP_parse_parsed_message->msg().headers()().fRom()() = *(yyvsp[(2) - (2)].charstring);
               else HTTP_parse_parsed_message->msg().headers()().fRom()() = "";
               delete (yyvsp[(2) - (2)].charstring);
             }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 280 "HTTP_parse.y"
    {
               if((yyvsp[(2) - (2)].charstring)) HTTP_parse_parsed_message->msg().headers()().host()() = *(yyvsp[(2) - (2)].charstring);
               else HTTP_parse_parsed_message->msg().headers()().host()() = "";
               delete (yyvsp[(2) - (2)].charstring);
             }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 285 "HTTP_parse.y"
    {
               if((yyvsp[(2) - (2)].charstring)) HTTP_parse_parsed_message->msg().headers()().http2__settings()() = *(yyvsp[(2) - (2)].charstring);
               else HTTP_parse_parsed_message->msg().headers()().http2__settings()() = "";
               delete (yyvsp[(2) - (2)].charstring);
             }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 290 "HTTP_parse.y"
    {
               if((yyvsp[(2) - (2)].charstring)) HTTP_parse_parsed_message->msg().headers()().iF()() = *(yyvsp[(2) - (2)].charstring);
               else HTTP_parse_parsed_message->msg().headers()().iF()() = "";
               delete (yyvsp[(2) - (2)].charstring);
             }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 295 "HTTP_parse.y"
    {
               int i = 0;
               if(HTTP_parse_parsed_message->msg().headers()().if__match().ispresent()) i = HTTP_parse_parsed_message->msg().headers()().if__match()().size_of();
               if((yyvsp[(2) - (2)].charstring_list)) HTTP_parse_parsed_message->msg().headers()().if__match()()[i] = *(yyvsp[(2) - (2)].charstring_list);
               else HTTP_parse_parsed_message->msg().headers()().if__match()()[i][0] = "";
               delete (yyvsp[(2) - (2)].charstring_list);
             }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 302 "HTTP_parse.y"
    {
               if((yyvsp[(2) - (2)].charstring)) HTTP_parse_parsed_message->msg().headers()().if__modified__since()() = *(yyvsp[(2) - (2)].charstring);
               else HTTP_parse_parsed_message->msg().headers()().if__modified__since()() = "";
               delete (yyvsp[(2) - (2)].charstring);
             }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 307 "HTTP_parse.y"
    {
               int i = 0;
               if(HTTP_parse_parsed_message->msg().headers()().if__none__match().ispresent()) i = HTTP_parse_parsed_message->msg().headers()().if__none__match()().size_of();
               if((yyvsp[(2) - (2)].charstring_list)) HTTP_parse_parsed_message->msg().headers()().if__none__match()()[i] = *(yyvsp[(2) - (2)].charstring_list);
               else HTTP_parse_parsed_message->msg().headers()().if__none__match()()[i][0] = "";
               delete (yyvsp[(2) - (2)].charstring_list);
             }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 314 "HTTP_parse.y"
    {
               if((yyvsp[(2) - (2)].charstring)) HTTP_parse_parsed_message->msg().headers()().if__range()() = *(yyvsp[(2) - (2)].charstring);
               else HTTP_parse_parsed_message->msg().headers()().if__range()() = "";
               delete (yyvsp[(2) - (2)].charstring);
             }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 319 "HTTP_parse.y"
    {
               if((yyvsp[(2) - (2)].charstring)) HTTP_parse_parsed_message->msg().headers()().if__schedule__tag__match()() = *(yyvsp[(2) - (2)].charstring);
               else HTTP_parse_parsed_message->msg().headers()().if__schedule__tag__match()() = "";
               delete (yyvsp[(2) - (2)].charstring);
             }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 324 "HTTP_parse.y"
    {
               if((yyvsp[(2) - (2)].charstring)) HTTP_parse_parsed_message->msg().headers()().if__unmodified__since()() = *(yyvsp[(2) - (2)].charstring);
               else HTTP_parse_parsed_message->msg().headers()().if__unmodified__since()() = "";
               delete (yyvsp[(2) - (2)].charstring);
             }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 329 "HTTP_parse.y"
    {
               if((yyvsp[(2) - (2)].charstring)) HTTP_parse_parsed_message->msg().headers()().last__modified()() = *(yyvsp[(2) - (2)].charstring);
               else HTTP_parse_parsed_message->msg().headers()().last__modified()() = "";
               delete (yyvsp[(2) - (2)].charstring);
             }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 334 "HTTP_parse.y"
    {
               if((yyvsp[(2) - (2)].charstring)) HTTP_parse_parsed_message->msg().headers()().location()() = *(yyvsp[(2) - (2)].charstring);
               else HTTP_parse_parsed_message->msg().headers()().location()() = "";
               delete (yyvsp[(2) - (2)].charstring);
             }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 339 "HTTP_parse.y"
    {
               if((yyvsp[(2) - (2)].charstring)) HTTP_parse_parsed_message->msg().headers()().lock__token()() = *(yyvsp[(2) - (2)].charstring);
               else HTTP_parse_parsed_message->msg().headers()().lock__token()() = "";
               delete (yyvsp[(2) - (2)].charstring);
             }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 344 "HTTP_parse.y"
    {
               HTTP_parse_parsed_message->msg().headers()().max__forwards()() = *(yyvsp[(2) - (2)].integer);
               delete (yyvsp[(2) - (2)].integer);
             }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 348 "HTTP_parse.y"
    {
               if((yyvsp[(2) - (2)].charstring)) HTTP_parse_parsed_message->msg().headers()().mime__version()() = *(yyvsp[(2) - (2)].charstring);
               else HTTP_parse_parsed_message->msg().headers()().mime__version()() = "";
               delete (yyvsp[(2) - (2)].charstring);
             }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 353 "HTTP_parse.y"
    {
               if((yyvsp[(2) - (2)].charstring)) HTTP_parse_parsed_message->msg().headers()().ordering__type()() = *(yyvsp[(2) - (2)].charstring);
               else HTTP_parse_parsed_message->msg().headers()().ordering__type()() = "";
               delete (yyvsp[(2) - (2)].charstring);
             }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 358 "HTTP_parse.y"
    {
               if((yyvsp[(2) - (2)].charstring)) HTTP_parse_parsed_message->msg().headers()().origin()() = *(yyvsp[(2) - (2)].charstring);
               else HTTP_parse_parsed_message->msg().headers()().origin()() = "";
               delete (yyvsp[(2) - (2)].charstring);
             }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 363 "HTTP_parse.y"
    {
               HTTP_parse_parsed_message->msg().headers()().overwrite()() = *(yyvsp[(2) - (2)].tf);
               delete (yyvsp[(2) - (2)].tf);
             }
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 367 "HTTP_parse.y"
    {
               if((yyvsp[(2) - (2)].charstring)) HTTP_parse_parsed_message->msg().headers()().position()() = *(yyvsp[(2) - (2)].charstring);
               else HTTP_parse_parsed_message->msg().headers()().position()() = "";
               delete (yyvsp[(2) - (2)].charstring);
             }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 372 "HTTP_parse.y"
    {
               int i = 0;
               if(HTTP_parse_parsed_message->msg().headers()().pragma().ispresent()) i = HTTP_parse_parsed_message->msg().headers()().pragma()().size_of();
               if((yyvsp[(2) - (2)].charstring_list)) HTTP_parse_parsed_message->msg().headers()().pragma()()[i] = *(yyvsp[(2) - (2)].charstring_list);
               else HTTP_parse_parsed_message->msg().headers()().pragma()()[i][0] = "";
               delete (yyvsp[(2) - (2)].charstring_list);
             }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 379 "HTTP_parse.y"
    {
               int i = 0;
               if(HTTP_parse_parsed_message->msg().headers()().prefer().ispresent()) i = HTTP_parse_parsed_message->msg().headers()().prefer()().size_of();
               if((yyvsp[(2) - (2)].charstring_list)) HTTP_parse_parsed_message->msg().headers()().prefer()()[i] = *(yyvsp[(2) - (2)].charstring_list);
               else HTTP_parse_parsed_message->msg().headers()().prefer()()[i][0] = "";
               delete (yyvsp[(2) - (2)].charstring_list);
             }
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 386 "HTTP_parse.y"
    {
               int i = 0;
               if(HTTP_parse_parsed_message->msg().headers()().preference__applied().ispresent()) i = HTTP_parse_parsed_message->msg().headers()().preference__applied()().size_of();
               if((yyvsp[(2) - (2)].charstring_list)) HTTP_parse_parsed_message->msg().headers()().preference__applied()()[i] = *(yyvsp[(2) - (2)].charstring_list);
               else HTTP_parse_parsed_message->msg().headers()().preference__applied()()[i][0] = "";
               delete (yyvsp[(2) - (2)].charstring_list);
             }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 393 "HTTP_parse.y"
    {
               if((yyvsp[(2) - (2)].charstring)) HTTP_parse_parsed_message->msg().headers()().proxy__authenticate()() = *(yyvsp[(2) - (2)].charstring);
               else HTTP_parse_parsed_message->msg().headers()().proxy__authenticate()() = "";
               delete (yyvsp[(2) - (2)].charstring);
             }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 398 "HTTP_parse.y"
    {
               if((yyvsp[(2) - (2)].charstring)) HTTP_parse_parsed_message->msg().headers()().proxy__authorization()() = *(yyvsp[(2) - (2)].charstring);
               else HTTP_parse_parsed_message->msg().headers()().proxy__authorization()() = "";
               delete (yyvsp[(2) - (2)].charstring);
             }
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 403 "HTTP_parse.y"
    {
               if((yyvsp[(2) - (2)].charstring)) HTTP_parse_parsed_message->msg().headers()().range()() = *(yyvsp[(2) - (2)].charstring);
               else HTTP_parse_parsed_message->msg().headers()().range()() = "";
               delete (yyvsp[(2) - (2)].charstring);
             }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 408 "HTTP_parse.y"
    {
               if((yyvsp[(2) - (2)].charstring)) HTTP_parse_parsed_message->msg().headers()().referer()() = *(yyvsp[(2) - (2)].charstring);
               else HTTP_parse_parsed_message->msg().headers()().referer()() = "";
               delete (yyvsp[(2) - (2)].charstring);
             }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 413 "HTTP_parse.y"
    {
               if((yyvsp[(2) - (2)].charstring)) HTTP_parse_parsed_message->msg().headers()().retry__after()() = *(yyvsp[(2) - (2)].charstring);
               else HTTP_parse_parsed_message->msg().headers()().retry__after()() = "";
               delete (yyvsp[(2) - (2)].charstring);
             }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 418 "HTTP_parse.y"
    {
               HTTP_parse_parsed_message->msg().headers()().schedule__reply()() = *(yyvsp[(2) - (2)].tf);
               delete (yyvsp[(2) - (2)].tf);
             }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 422 "HTTP_parse.y"
    {
               if((yyvsp[(2) - (2)].charstring)) HTTP_parse_parsed_message->msg().headers()().schedule__tag()() = *(yyvsp[(2) - (2)].charstring);
               else HTTP_parse_parsed_message->msg().headers()().schedule__tag()() = "";
               delete (yyvsp[(2) - (2)].charstring);
             }
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 427 "HTTP_parse.y"
    {
               if((yyvsp[(2) - (2)].charstring)) HTTP_parse_parsed_message->msg().headers()().sec__websocket__accept()() = *(yyvsp[(2) - (2)].charstring);
               else HTTP_parse_parsed_message->msg().headers()().sec__websocket__accept()() = "";
               delete (yyvsp[(2) - (2)].charstring);
             }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 432 "HTTP_parse.y"
    {
               if((yyvsp[(2) - (2)].charstring)) HTTP_parse_parsed_message->msg().headers()().sec__websocket__extensions()() = *(yyvsp[(2) - (2)].charstring);
               else HTTP_parse_parsed_message->msg().headers()().sec__websocket__extensions()() = "";
               delete (yyvsp[(2) - (2)].charstring);
             }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 437 "HTTP_parse.y"
    {
               if((yyvsp[(2) - (2)].charstring)) HTTP_parse_parsed_message->msg().headers()().sec__websocket__key()() = *(yyvsp[(2) - (2)].charstring);
               else HTTP_parse_parsed_message->msg().headers()().sec__websocket__key()() = "";
               delete (yyvsp[(2) - (2)].charstring);
             }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 442 "HTTP_parse.y"
    {
               if((yyvsp[(2) - (2)].charstring)) HTTP_parse_parsed_message->msg().headers()().sec__websocket__protocol()() = *(yyvsp[(2) - (2)].charstring);
               else HTTP_parse_parsed_message->msg().headers()().sec__websocket__protocol()() = "";
               delete (yyvsp[(2) - (2)].charstring);
             }
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 447 "HTTP_parse.y"
    {
               if((yyvsp[(2) - (2)].charstring)) HTTP_parse_parsed_message->msg().headers()().sec__websocket__version()() = *(yyvsp[(2) - (2)].charstring);
               else HTTP_parse_parsed_message->msg().headers()().sec__websocket__version()() = "";
               delete (yyvsp[(2) - (2)].charstring);
             }
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 452 "HTTP_parse.y"
    {
               if((yyvsp[(2) - (2)].charstring)) HTTP_parse_parsed_message->msg().headers()().server()() = *(yyvsp[(2) - (2)].charstring);
               else HTTP_parse_parsed_message->msg().headers()().server()() = "";
               delete (yyvsp[(2) - (2)].charstring);
             }
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 457 "HTTP_parse.y"
    {
               if((yyvsp[(2) - (2)].charstring)) HTTP_parse_parsed_message->msg().headers()().set__cookie()() = *(yyvsp[(2) - (2)].charstring);
               else HTTP_parse_parsed_message->msg().headers()().set__cookie()() = "";
               delete (yyvsp[(2) - (2)].charstring);
             }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 462 "HTTP_parse.y"
    {
               if((yyvsp[(2) - (2)].charstring)) HTTP_parse_parsed_message->msg().headers()().slug()() = *(yyvsp[(2) - (2)].charstring);
               else HTTP_parse_parsed_message->msg().headers()().slug()() = "";
               delete (yyvsp[(2) - (2)].charstring);
             }
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 467 "HTTP_parse.y"
    {
               if((yyvsp[(2) - (2)].charstring)) HTTP_parse_parsed_message->msg().headers()().strict__transport__security()() = *(yyvsp[(2) - (2)].charstring);
               else HTTP_parse_parsed_message->msg().headers()().strict__transport__security()() = "";
               delete (yyvsp[(2) - (2)].charstring);
             }
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 472 "HTTP_parse.y"
    {
               if((yyvsp[(2) - (2)].charstring)) HTTP_parse_parsed_message->msg().headers()().tE()() = *(yyvsp[(2) - (2)].charstring);
               else HTTP_parse_parsed_message->msg().headers()().tE()() = "";
               delete (yyvsp[(2) - (2)].charstring);
             }
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 477 "HTTP_parse.y"
    {
               int i = 0;
               if(HTTP_parse_parsed_message->msg().headers()().tImeout().ispresent()) i = HTTP_parse_parsed_message->msg().headers()().tImeout()().size_of();
               if((yyvsp[(2) - (2)].charstring_list)) HTTP_parse_parsed_message->msg().headers()().tImeout()()[i] = *(yyvsp[(2) - (2)].charstring_list);
               else HTTP_parse_parsed_message->msg().headers()().tImeout()()[i][0] = "";
               delete (yyvsp[(2) - (2)].charstring_list);
             }
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 484 "HTTP_parse.y"
    {
               int i = 0;
               if(HTTP_parse_parsed_message->msg().headers()().trailer().ispresent()) i = HTTP_parse_parsed_message->msg().headers()().trailer()().size_of();
               if((yyvsp[(2) - (2)].charstring_list)) HTTP_parse_parsed_message->msg().headers()().trailer()()[i] = *(yyvsp[(2) - (2)].charstring_list);
               else HTTP_parse_parsed_message->msg().headers()().trailer()()[i][0] = "";
               delete (yyvsp[(2) - (2)].charstring_list);
             }
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 491 "HTTP_parse.y"
    {
               int i = 0;
               if(HTTP_parse_parsed_message->msg().headers()().transfer__encoding().ispresent()) i = HTTP_parse_parsed_message->msg().headers()().transfer__encoding()().size_of();
               if((yyvsp[(2) - (2)].charstring_list)) HTTP_parse_parsed_message->msg().headers()().transfer__encoding()()[i] = *(yyvsp[(2) - (2)].charstring_list);
               else HTTP_parse_parsed_message->msg().headers()().transfer__encoding()()[i][0] = "";
               delete (yyvsp[(2) - (2)].charstring_list);
             }
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 498 "HTTP_parse.y"
    {
               int i = 0;
               if(HTTP_parse_parsed_message->msg().headers()().upgrade().ispresent()) i = HTTP_parse_parsed_message->msg().headers()().upgrade()().size_of();
               if((yyvsp[(2) - (2)].charstring_list)) HTTP_parse_parsed_message->msg().headers()().upgrade()()[i] = *(yyvsp[(2) - (2)].charstring_list);
               else HTTP_parse_parsed_message->msg().headers()().upgrade()()[i][0] = "";
               delete (yyvsp[(2) - (2)].charstring_list);
             }
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 505 "HTTP_parse.y"
    {
               if((yyvsp[(2) - (2)].charstring)) HTTP_parse_parsed_message->msg().headers()().user__agent()() = *(yyvsp[(2) - (2)].charstring);
               else HTTP_parse_parsed_message->msg().headers()().user__agent()() = "";
               delete (yyvsp[(2) - (2)].charstring);
             }
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 510 "HTTP_parse.y"
    {
               int i = 0;
               if(HTTP_parse_parsed_message->msg().headers()().vary().ispresent()) i = HTTP_parse_parsed_message->msg().headers()().vary()().size_of();
               if((yyvsp[(2) - (2)].charstring_list)) HTTP_parse_parsed_message->msg().headers()().vary()()[i] = *(yyvsp[(2) - (2)].charstring_list);
               else HTTP_parse_parsed_message->msg().headers()().vary()()[i][0] = "";
               delete (yyvsp[(2) - (2)].charstring_list);
             }
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 517 "HTTP_parse.y"
    {
               int i = 0;
               if(HTTP_parse_parsed_message->msg().headers()().via().ispresent()) i = HTTP_parse_parsed_message->msg().headers()().via()().size_of();
               if((yyvsp[(2) - (2)].charstring_list)) HTTP_parse_parsed_message->msg().headers()().via()()[i] = *(yyvsp[(2) - (2)].charstring_list);
               else HTTP_parse_parsed_message->msg().headers()().via()()[i][0] = "";
               delete (yyvsp[(2) - (2)].charstring_list);
             }
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 524 "HTTP_parse.y"
    {
               int i = 0;
               if(HTTP_parse_parsed_message->msg().headers()().www__authenticate().ispresent()) i = HTTP_parse_parsed_message->msg().headers()().www__authenticate()().size_of();
               if((yyvsp[(2) - (2)].charstring_list)) HTTP_parse_parsed_message->msg().headers()().www__authenticate()()[i] = *(yyvsp[(2) - (2)].charstring_list);
               else HTTP_parse_parsed_message->msg().headers()().www__authenticate()()[i][0] = "";
               delete (yyvsp[(2) - (2)].charstring_list);
             }
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 531 "HTTP_parse.y"
    {
               int i = 0;
               if(HTTP_parse_parsed_message->msg().headers()().warning().ispresent()) i = HTTP_parse_parsed_message->msg().headers()().warning()().size_of();
               if((yyvsp[(2) - (2)].charstring_list)) HTTP_parse_parsed_message->msg().headers()().warning()()[i] = *(yyvsp[(2) - (2)].charstring_list);
               else HTTP_parse_parsed_message->msg().headers()().warning()()[i][0] = "";
               delete (yyvsp[(2) - (2)].charstring_list);
             }
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 538 "HTTP_parse.y"
    {
               int i = 0;
               if(HTTP_parse_parsed_message->msg().headers()().undefined__header__list().ispresent()) i = HTTP_parse_parsed_message->msg().headers()().undefined__header__list()().size_of();
               
               HTTP_parse_parsed_message->msg().headers()().undefined__header__list()()[i].headerName() = *(yyvsp[(1) - (3)].charstring);
               
               if((yyvsp[(3) - (3)].charstring)) HTTP_parse_parsed_message->msg().headers()().undefined__header__list()()[i].headerValue() = *(yyvsp[(3) - (3)].charstring);
               else HTTP_parse_parsed_message->msg().headers()().undefined__header__list()()[i].headerValue() = "";
               
               delete (yyvsp[(1) - (3)].charstring);
               delete (yyvsp[(3) - (3)].charstring);
             }
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 551 "HTTP_parse.y"
    { (yyval.charstring_list) = NULL; }
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 552 "HTTP_parse.y"
    {
                   (yyval.charstring_list) = new General__Types::CharstringList;
                   (*(yyval.charstring_list))[0] = *(yyvsp[(1) - (1)].charstring);
                   delete (yyvsp[(1) - (1)].charstring);
                 }
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 557 "HTTP_parse.y"
    {
                   int a = (yyvsp[(1) - (3)].charstring_list)->size_of();
                   (yyval.charstring_list) = (yyvsp[(1) - (3)].charstring_list);
                   (*(yyval.charstring_list))[a] = *(yyvsp[(3) - (3)].charstring);
                   delete (yyvsp[(3) - (3)].charstring);
                 }
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 564 "HTTP_parse.y"
    { (yyval.charstring) = NULL; }
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 565 "HTTP_parse.y"
    {
            (yyval.charstring) = new CHARSTRING(*(yyvsp[(1) - (1)].charstring));
            delete (yyvsp[(1) - (1)].charstring);
          }
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 570 "HTTP_parse.y"
    {
                  (yyval.methodlist) = new Method__List;
                  (*(yyval.methodlist))[0] = *(yyvsp[(1) - (1)].method);
                  delete (yyvsp[(1) - (1)].method);
                }
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 575 "HTTP_parse.y"
    {
                  int a = (yyvsp[(1) - (3)].methodlist)->size_of();
                  (yyval.methodlist) = (yyvsp[(1) - (3)].methodlist);
                  (*(yyval.methodlist))[a] = *(yyvsp[(3) - (3)].method);
                  delete (yyvsp[(3) - (3)].method);
                }
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 582 "HTTP_parse.y"
    { (yyval.tf) = new TF(0); }
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 583 "HTTP_parse.y"
    { (yyval.tf) = new TF(1); }
    break;



/* Line 1806 of yacc.c  */
#line 2933 "HTTP_parse_.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



