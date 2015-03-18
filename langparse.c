/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 7 "lang.y"

#include <iostream>
#include "lex.h"

/* Line 371 of yacc.c  */
#line 73 "langparse.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "langparse.h".  */
#ifndef YY_YY_LANGPARSE_H_INCLUDED
# define YY_YY_LANGPARSE_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     TYPE_ID = 259,
     INT_VAL = 260,
     FLOAT_VAL = 261,
     SCAN = 262,
     PRINT = 263,
     ARRAY = 264,
     STRUCT = 265,
     WHILE = 266,
     IF = 267,
     ELSE = 268,
     RETURN = 269,
     JUNK_TOKEN = 270
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 14 "lang.y"

    int             int_val;
    double          float_val;
    cAstNode*       ast_node;
    cSymbol*        symbol;
    map<string,cSymbol*>*   sym_table;
    StmtsNode*     stmts_node;
    StmtNode*      stmt_node;
    BlockNode*     block_node;
    ExprNode*       expr_node;
    DeclsNode*     decls_node;
    DeclNode*      decl_node;
    ArraySpecNode*     ary_node;
    ArrayValNode*       ary_val;
    VarRefNode*        var_node;
    VarPartNode*        var_part;
    ParamNode*     param_node;
    ParamsNode*    params_node;
    ParamsSpecNode*    params_spec;
    ParamSpecNode*     param_spec;
    FuncCallNode*      func_node;
    

/* Line 387 of yacc.c  */
#line 155 "langparse.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;
extern YYLTYPE yylloc;
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

#endif /* !YY_YY_LANGPARSE_H_INCLUDED  */

/* Copy the second part of user declarations.  */
/* Line 390 of yacc.c  */
#line 37 "lang.y"

    int yyerror(const char *msg);
    void semantic_error(std::string msg);

    cAstNode *yyast_root;

/* Line 390 of yacc.c  */
#line 203 "langparse.c"

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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
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
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
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
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   180

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNRULES -- Number of states.  */
#define YYNSTATES  131

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   270

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    30,     2,     2,
      20,    19,    28,    26,    21,    27,    25,    29,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    18,
       2,    24,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    22,     2,    23,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    16,     2,    17,     2,     2,     2,     2,
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
      15
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,    10,    14,    16,    18,    21,    23,
      26,    29,    31,    34,    37,    40,    45,    51,    54,    60,
      65,    69,    72,    76,    80,    82,    84,    89,    90,    93,
      95,   101,   109,   115,   121,   127,   132,   137,   140,   142,
     146,   149,   154,   158,   160,   163,   165,   170,   171,   175,
     177,   179,   180,   184,   188,   190,   194,   198,   202,   204,
     208,   210,   212
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      32,     0,    -1,    33,    -1,    34,    36,    47,    35,    -1,
      34,    47,    35,    -1,    16,    -1,    17,    -1,    36,    37,
      -1,    37,    -1,    38,    18,    -1,    40,    18,    -1,    41,
      -1,    39,    18,    -1,     1,    18,    -1,     4,     3,    -1,
       9,     4,     3,    46,    -1,    10,    34,    36,    35,     3,
      -1,    42,    18,    -1,    42,    16,    36,    47,    17,    -1,
      42,    16,    47,    17,    -1,    43,    44,    19,    -1,    43,
      19,    -1,     4,     3,    20,    -1,    44,    21,    45,    -1,
      45,    -1,    38,    -1,    46,    22,     5,    23,    -1,    -1,
      47,    48,    -1,    48,    -1,    12,    20,    56,    19,    48,
      -1,    12,    20,    56,    19,    48,    13,    48,    -1,    11,
      20,    56,    19,    48,    -1,     8,    20,    56,    19,    18,
      -1,     7,    20,    52,    19,    18,    -1,    52,    24,    56,
      18,    -1,    52,    24,    49,    18,    -1,    49,    18,    -1,
      33,    -1,    14,    56,    18,    -1,     1,    18,    -1,     3,
      20,    54,    19,    -1,    50,    25,    51,    -1,    51,    -1,
       3,    53,    -1,    50,    -1,    53,    22,    56,    23,    -1,
      -1,    54,    21,    55,    -1,    55,    -1,    56,    -1,    -1,
      56,    26,    57,    -1,    56,    27,    57,    -1,    57,    -1,
      57,    28,    58,    -1,    57,    29,    58,    -1,    57,    30,
      58,    -1,    58,    -1,    20,    56,    19,    -1,     5,    -1,
       6,    -1,    50,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    87,    87,    94,    98,   101,   104,   107,   111,   115,
     118,   121,   124,   127,   128,   148,   165,   183,   188,   196,
     202,   206,   209,   227,   234,   239,   243,   250,   254,   259,
     265,   269,   273,   277,   281,   285,   295,   305,   308,   311,
     314,   316,   320,   329,   339,   343,   346,   352,   356,   362,
     367,   370,   374,   377,   380,   384,   387,   390,   393,   397,
     400,   403,   406
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "TYPE_ID", "INT_VAL",
  "FLOAT_VAL", "SCAN", "PRINT", "ARRAY", "STRUCT", "WHILE", "IF", "ELSE",
  "RETURN", "JUNK_TOKEN", "'{'", "'}'", "';'", "')'", "'('", "','", "'['",
  "']'", "'='", "'.'", "'+'", "'-'", "'*'", "'/'", "'%'", "$accept",
  "program", "block", "open", "close", "decls", "decl", "var_decl",
  "array_decl", "struct_decl", "func_decl", "func_header", "func_prefix",
  "paramsspec", "paramspec", "arrayspec", "stmts", "stmt", "func_call",
  "varref", "varpart", "lval", "arrayval", "params", "param", "expr",
  "term", "fact", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   123,   125,    59,    41,
      40,    44,    91,    93,    61,    46,    43,    45,    42,    47,
      37
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    31,    32,    33,    33,    34,    35,    36,    36,    37,
      37,    37,    37,    37,    38,    39,    40,    41,    41,    41,
      42,    42,    43,    44,    44,    45,    46,    46,    47,    47,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    49,    50,    50,    51,    52,    53,    53,    54,    54,
      55,    55,    56,    56,    56,    57,    57,    57,    57,    58,
      58,    58,    58
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     4,     3,     1,     1,     2,     1,     2,
       2,     1,     2,     2,     2,     4,     5,     2,     5,     4,
       3,     2,     3,     3,     1,     1,     4,     0,     2,     1,
       5,     7,     5,     5,     5,     4,     4,     2,     1,     3,
       2,     4,     3,     1,     2,     1,     4,     0,     3,     1,
       1,     0,     3,     3,     1,     3,     3,     3,     1,     3,
       1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,     0,     2,     0,     1,     0,    47,     0,     0,
       0,     0,     0,     0,     0,     0,    38,     0,     8,     0,
       0,     0,    11,     0,     0,     0,    29,     0,    45,    43,
       0,    13,    51,    44,    14,     0,     0,     0,     0,     0,
       0,    47,    60,    61,     0,    62,     0,    54,    58,     7,
       0,     9,    12,    10,     0,    17,     0,    21,    25,     0,
      24,     0,     6,     4,    28,    37,     0,     0,     0,    49,
      50,     0,    22,     0,     0,    27,     0,     0,     0,     0,
       0,    39,     0,     0,     0,     0,     0,     3,     0,     0,
      14,    20,     0,    40,    42,     0,     0,    41,    51,     0,
       0,     0,    15,    13,     0,     0,     0,    59,    52,    53,
      55,    56,    57,     0,    19,    23,    36,    35,    48,    46,
      34,    33,     0,    16,    32,    30,    18,     0,     0,    26,
      31
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    16,     4,    63,    17,    18,    19,    20,    21,
      22,    23,    24,    59,    60,   102,    25,    26,    27,    45,
      29,    30,    33,    68,    69,    70,    47,    48
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -44
static const yytype_int16 yypact[] =
{
      -6,   -44,    16,   -44,   151,   -44,     5,    15,    39,    32,
      37,    59,    -6,    55,    56,    19,   -44,   151,   -44,    53,
      62,    72,   -44,    20,    11,   104,   -44,    75,    58,   -44,
      76,    86,    19,    88,    97,   116,    19,   119,    44,    19,
      19,   -44,   -44,   -44,    19,    58,    -9,    66,   -44,   -44,
     104,   -44,   -44,   -44,   151,   -44,   123,   -44,   -44,    30,
     -44,   109,   -44,   -44,   -44,   -44,   116,    38,    87,   -44,
     -21,    19,   -44,   112,    40,   -44,   110,    10,    42,    51,
      60,   -44,    19,    19,    19,    19,    19,   -44,   151,   122,
     -44,   -44,   128,   -44,   -44,   125,    29,   -44,    19,    65,
     126,   129,   118,   -44,   146,   163,   163,   -44,    66,    66,
     -44,   -44,   -44,   134,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,   -44,   148,   -44,   -44,   143,   -44,   145,   163,   -44,
     -44
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -44,   -44,   157,   160,   -43,   -26,   -15,   -20,   -44,   -44,
     -44,   -44,   -44,   -44,    77,   -44,   -14,   -24,   106,    -4,
     114,   141,   -44,   -44,    80,    -7,    31,    13
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -41
static const yytype_int16 yytable[] =
{
      28,    64,    49,    50,    58,    82,    83,    87,    46,    81,
       1,    76,    77,    28,     8,    56,     5,    82,    83,    11,
      12,    28,    41,    31,    42,    43,    64,    62,    88,    74,
      57,    28,    78,    79,   104,    32,    54,    80,    55,    44,
      89,     7,    34,    42,    43,    76,    28,   117,     8,    91,
      28,    92,    35,    11,    12,    82,    83,    36,    44,   101,
      96,   105,    49,    37,    99,    64,    82,    83,    82,    83,
     106,    51,    58,    49,   113,    39,    40,    82,    83,   107,
      52,   124,   125,    66,    28,    28,    82,    83,   119,    64,
      53,    82,    83,    65,    84,    85,    86,   110,   111,   112,
      67,    28,    28,   -40,   130,    61,    97,     7,    98,    28,
      71,     9,    10,   108,   109,    13,    14,    72,    15,    41,
       1,    62,    75,    61,    28,     7,    90,    93,   103,     9,
      10,   100,    56,    13,    14,    61,    15,     7,     1,   114,
     122,     9,    10,   116,   120,    13,    14,   121,    15,   123,
       1,   126,     6,   127,     7,     8,   128,     3,     9,    10,
      11,    12,    13,    14,    61,    15,     7,     1,   129,   115,
       9,    10,    38,    95,    13,    14,    73,    15,   118,     1,
      94
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-44)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_uint8 yycheck[] =
{
       4,    25,    17,    17,    24,    26,    27,    50,    15,    18,
      16,     1,    38,    17,     4,     4,     0,    26,    27,     9,
      10,    25,     3,    18,     5,     6,    50,    17,    54,    36,
      19,    35,    39,    40,    77,    20,    16,    44,    18,    20,
      54,     3,     3,     5,     6,     1,    50,    18,     4,    19,
      54,    21,    20,     9,    10,    26,    27,    20,    20,    19,
      67,    19,    77,     4,    71,    89,    26,    27,    26,    27,
      19,    18,    92,    88,    88,    20,    20,    26,    27,    19,
      18,   105,   106,    25,    88,    89,    26,    27,    23,   113,
      18,    26,    27,    18,    28,    29,    30,    84,    85,    86,
      24,   105,   106,    17,   128,     1,    19,     3,    21,   113,
      22,     7,     8,    82,    83,    11,    12,    20,    14,     3,
      16,    17,     3,     1,   128,     3,     3,    18,    18,     7,
       8,    19,     4,    11,    12,     1,    14,     3,    16,    17,
      22,     7,     8,    18,    18,    11,    12,    18,    14,     3,
      16,    17,     1,     5,     3,     4,    13,     0,     7,     8,
       9,    10,    11,    12,     1,    14,     3,    16,    23,    92,
       7,     8,    12,    67,    11,    12,    35,    14,    98,    16,
      66
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    16,    32,    33,    34,     0,     1,     3,     4,     7,
       8,     9,    10,    11,    12,    14,    33,    36,    37,    38,
      39,    40,    41,    42,    43,    47,    48,    49,    50,    51,
      52,    18,    20,    53,     3,    20,    20,     4,    34,    20,
      20,     3,     5,     6,    20,    50,    56,    57,    58,    37,
      47,    18,    18,    18,    16,    18,     4,    19,    38,    44,
      45,     1,    17,    35,    48,    18,    25,    24,    54,    55,
      56,    22,    20,    52,    56,     3,     1,    36,    56,    56,
      56,    18,    26,    27,    28,    29,    30,    35,    36,    47,
       3,    19,    21,    18,    51,    49,    56,    19,    21,    56,
      19,    19,    46,    18,    35,    19,    19,    19,    57,    57,
      58,    58,    58,    47,    17,    45,    18,    18,    55,    23,
      18,    18,    22,     3,    48,    48,    17,     5,    13,    23,
      48
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

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (YYID (N))                                                     \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (YYID (0))
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

__attribute__((__unused__))
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
#else
static unsigned
yy_location_print_ (yyo, yylocp)
    FILE *yyo;
    YYLTYPE const * const yylocp;
#endif
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += fprintf (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += fprintf (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += fprintf (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += fprintf (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += fprintf (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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
		  Type, Value, Location); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
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
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
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
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
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

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;


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
       `yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1792 of yacc.c  */
#line 87 "lang.y"
    { (yyval.ast_node) = (yyvsp[(1) - (1)].block_node);
                                  yyast_root = (yyval.ast_node);
                                  if (yynerrs == 0) 
                                      YYACCEPT;
                                  else
                                      YYABORT;
                                }
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 94 "lang.y"
    {
                                    (yyval.block_node) = new BlockNode((yyvsp[(1) - (4)].sym_table), (yyvsp[(2) - (4)].decls_node), (yyvsp[(3) - (4)].stmts_node));
                                    
                                }
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 98 "lang.y"
    {
                                    (yyval.block_node) = new BlockNode((yyvsp[(1) - (3)].sym_table), nullptr, (yyvsp[(2) - (3)].stmts_node));
                                }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 101 "lang.y"
    {
                                    (yyval.sym_table) = symbolTableRoot->IncreaseScope();
                                }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 104 "lang.y"
    {
                                    symbolTableRoot->DecreaseScope();
                                }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 107 "lang.y"
    {
                                    (yyval.decls_node) = (yyvsp[(1) - (2)].decls_node);
                                    (yyval.decls_node)->Add((yyvsp[(2) - (2)].decl_node));
                                }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 111 "lang.y"
    {
                                    (yyval.decls_node) = new DeclsNode();
                                    (yyval.decls_node)->Add((yyvsp[(1) - (1)].decl_node));
                                }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 115 "lang.y"
    {
                                    (yyval.decl_node) = (yyvsp[(1) - (2)].decl_node);
                                }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 118 "lang.y"
    {
                                    (yyval.decl_node) = (yyvsp[(1) - (2)].decl_node);
                                }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 121 "lang.y"
    {
                                    (yyval.decl_node) = (yyvsp[(1) - (1)].decl_node);
                                }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 124 "lang.y"
    {
                                    (yyval.decl_node) = (yyvsp[(1) - (2)].decl_node);          
                                }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 127 "lang.y"
    {}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 129 "lang.y"
    {
                                    if(symbolTableRoot->LocalLookUp((yyvsp[(2) - (2)].symbol)->GetSymbol()) && (yyvsp[(2) - (2)].symbol)->IsDeclared())
                                    {
                                        (yyval.decl_node) = nullptr;
                                        semantic_error("Symbol " + (yyvsp[(2) - (2)].symbol)->GetSymbol() + " already defined in current scope");
                                        YYERROR;
                                    }
                                    else
                                    {
                                        (yyvsp[(2) - (2)].symbol) = symbolTableRoot->InsertSymbol((yyvsp[(2) - (2)].symbol)->GetSymbol());
                                        (yyvsp[(2) - (2)].symbol)->SetDeclared();
										(yyvsp[(2) - (2)].symbol)->InitializeSize((yyvsp[(1) - (2)].symbol)->GetSize());
                                        (yyval.decl_node) = new VarNode((yyvsp[(1) - (2)].symbol), (yyvsp[(2) - (2)].symbol));
										DeclNode* decl = (yyvsp[(1) - (2)].symbol)->GetRef();
                                        if(decl == nullptr)
                                            decl = (yyval.decl_node);
                                        (yyvsp[(2) - (2)].symbol)->SetTypeRef((yyvsp[(1) - (2)].symbol)->GetType(), (yyvsp[(1) - (2)].symbol)->GetBaseType(), decl);
                                    }
                                }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 149 "lang.y"
    {
                                    if(symbolTableRoot->LocalLookUp((yyvsp[(3) - (4)].symbol)->GetSymbol()) && (yyvsp[(3) - (4)].symbol)->IsDeclared())
                                    {
                                        (yyval.decl_node) = nullptr;
                                        semantic_error("Symbol " + (yyvsp[(3) - (4)].symbol)->GetSymbol() + " already defined in current scope");
                                        YYERROR;
                                    }
                                    else
                                    {
                                        (yyvsp[(3) - (4)].symbol) = symbolTableRoot->InsertSymbol((yyvsp[(3) - (4)].symbol)->GetSymbol());
                                        (yyvsp[(3) - (4)].symbol)->SetTypeFlag();
                                        (yyvsp[(3) - (4)].symbol)->SetDeclared();
                                        (yyval.decl_node) = new ArrayDeclNode((yyvsp[(2) - (4)].symbol), (yyvsp[(3) - (4)].symbol), (yyvsp[(4) - (4)].ary_node));
                                        (yyvsp[(3) - (4)].symbol)->SetTypeRef((yyvsp[(3) - (4)].symbol)->GetSymbol(), (yyvsp[(2) - (4)].symbol)->GetSymbol(), (yyval.decl_node));
                                    }
                                }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 166 "lang.y"
    {
                                    if(symbolTableRoot->LocalLookUp((yyvsp[(5) - (5)].symbol)->GetSymbol()) && (yyvsp[(5) - (5)].symbol)->IsDeclared())
                                    {
                                        (yyval.decl_node) = nullptr;
                                        semantic_error("Symbol " + (yyvsp[(5) - (5)].symbol)->GetSymbol() + " already defined in current scope");
                                        YYERROR;
                                    }
                                    else
                                    {
                                        (yyvsp[(5) - (5)].symbol) = symbolTableRoot->InsertSymbol((yyvsp[(5) - (5)].symbol)->GetSymbol());
                                        (yyvsp[(5) - (5)].symbol)->SetTypeFlag();
                                        (yyvsp[(5) - (5)].symbol)->SetDeclared();
                                        (yyval.decl_node) = new StructDeclNode((yyvsp[(2) - (5)].sym_table), (yyvsp[(3) - (5)].decls_node), (yyvsp[(5) - (5)].symbol));
                                        (yyvsp[(5) - (5)].symbol)->SetTypeRef((yyvsp[(5) - (5)].symbol)->GetSymbol(), (yyvsp[(5) - (5)].symbol)->GetSymbol(), (yyval.decl_node));
                                    }
                                    
                                }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 184 "lang.y"
    {
                                    (yyval.decl_node) = (yyvsp[(1) - (2)].decl_node);
                                    symbolTableRoot->DecreaseScope();
                                }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 189 "lang.y"
    {
                                    (yyval.decl_node) = (yyvsp[(1) - (5)].decl_node);
                                    FuncDeclNode* node = dynamic_cast<FuncDeclNode*>((yyval.decl_node));
                                    node->SetDecls((yyvsp[(3) - (5)].decls_node));
                                    node->SetStmts((yyvsp[(4) - (5)].stmts_node));
                                    symbolTableRoot->DecreaseScope();
                                }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 197 "lang.y"
    {
                                    (yyval.decl_node) = (yyvsp[(1) - (4)].decl_node);
                                    ((FuncDeclNode*)(yyval.decl_node))->SetStmts((yyvsp[(3) - (4)].stmts_node));
                                    symbolTableRoot->DecreaseScope();
                                }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 203 "lang.y"
    {
                                    (yyval.decl_node) = new FuncDeclNode((yyvsp[(1) - (3)].symbol), (yyvsp[(2) - (3)].params_spec));
                                }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 206 "lang.y"
    {
                                    (yyval.decl_node) = new FuncDeclNode((yyvsp[(1) - (2)].symbol));
                                }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 210 "lang.y"
    {
                                    if(symbolTableRoot->LocalLookUp((yyvsp[(2) - (3)].symbol)->GetSymbol()) && (yyvsp[(2) - (3)].symbol)->IsDeclared())
                                    {
                                        (yyval.symbol) = nullptr;
                                        semantic_error("Symbol " + (yyvsp[(2) - (3)].symbol)->GetSymbol() + " already defined in current scope");
                                        YYERROR;
                                    }
                                    else
                                    {
                                        (yyval.symbol) = symbolTableRoot->InsertSymbol((yyvsp[(2) - (3)].symbol)->GetSymbol());
                                        (yyval.symbol)->SetDeclared();
										(yyval.symbol)->InitializeSize((yyvsp[(1) - (3)].symbol)->GetSize());
                                        (yyval.symbol)->SetTypeRef((yyvsp[(1) - (3)].symbol)->GetSymbol(), (yyvsp[(1) - (3)].symbol)->GetSymbol(), (yyvsp[(1) - (3)].symbol)->GetRef());
                                        symbolTableRoot->IncreaseScope();
                                    }
                                }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 228 "lang.y"
    {
                                    if((yyvsp[(1) - (3)].params_spec) == nullptr)
                                        (yyvsp[(1) - (3)].params_spec) = new ParamsSpecNode();
                                    (yyval.params_spec) = (yyvsp[(1) - (3)].params_spec);
                                    (yyval.params_spec)->Add((yyvsp[(3) - (3)].param_spec));
                                }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 234 "lang.y"
    {
                                    (yyval.params_spec) = new ParamsSpecNode();
                                    (yyval.params_spec)->Add((yyvsp[(1) - (1)].param_spec));
                                }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 239 "lang.y"
    {
                                    (yyval.param_spec) = new ParamSpecNode((VarNode*)(yyvsp[(1) - (1)].decl_node));
                                }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 244 "lang.y"
    {
                                    if((yyvsp[(1) - (4)].ary_node) == NULL)
                                        (yyvsp[(1) - (4)].ary_node) = new ArraySpecNode();
                                    (yyval.ary_node) = (yyvsp[(1) - (4)].ary_node);
                                    (yyval.ary_node)->Add((yyvsp[(3) - (4)].int_val));
                                }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 250 "lang.y"
    {
                                    (yyval.ary_node) = NULL;
                                }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 254 "lang.y"
    {
                                    (yyval.stmts_node) = (yyvsp[(1) - (2)].stmts_node);
                                    if((yyvsp[(2) - (2)].stmt_node) != nullptr)
                                        (yyval.stmts_node)->Add((yyvsp[(2) - (2)].stmt_node));
                                }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 259 "lang.y"
    {
                                    (yyval.stmts_node) = new StmtsNode();
                                    if((yyvsp[(1) - (1)].stmt_node) != nullptr)
                                        (yyval.stmts_node)->Add((yyvsp[(1) - (1)].stmt_node));
                                }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 266 "lang.y"
    {
                                    (yyval.stmt_node) = new IfNode((yyvsp[(3) - (5)].expr_node), (yyvsp[(5) - (5)].stmt_node));
                                }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 270 "lang.y"
    {
                                    (yyval.stmt_node) = new IfNode((yyvsp[(3) - (7)].expr_node), (yyvsp[(5) - (7)].stmt_node), (yyvsp[(7) - (7)].stmt_node));
                                }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 274 "lang.y"
    {
                                    (yyval.stmt_node) = new WhileNode((yyvsp[(3) - (5)].expr_node), (yyvsp[(5) - (5)].stmt_node));
                                }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 278 "lang.y"
    {
                                    (yyval.stmt_node) = new PrintNode((yyvsp[(3) - (5)].expr_node));
                                }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 282 "lang.y"
    {
                                    (yyval.stmt_node) = new ScanNode((yyvsp[(3) - (5)].expr_node));
                                }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 285 "lang.y"
    {
                                    (yyval.stmt_node) = new AssignmentNode((VarRefNode*)(yyvsp[(1) - (4)].expr_node), (yyvsp[(3) - (4)].expr_node));
                                    
                                    if((yyval.stmt_node)->SemanticError())
                                    {
                                        (yyval.stmt_node) = nullptr;
                                        semantic_error("Cannot assign " + (yyvsp[(3) - (4)].expr_node)->GetBaseType() + " to " + (yyvsp[(1) - (4)].expr_node)->GetBaseType());
                                    }
                                    
                                }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 296 "lang.y"
    {
                                    (yyval.stmt_node) = new AssignmentNode((VarRefNode*)(yyvsp[(1) - (4)].expr_node), (yyvsp[(3) - (4)].func_node));
                                    
                                    if((yyval.stmt_node)->SemanticError())
                                    {
                                        (yyval.stmt_node) = nullptr;
                                        semantic_error("Cannot assign\n");
                                    }
                                }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 305 "lang.y"
    {
                                   (yyval.stmt_node) = (yyvsp[(1) - (2)].func_node);
                                }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 308 "lang.y"
    {
                                    (yyval.stmt_node) = (yyvsp[(1) - (1)].block_node);
                                }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 311 "lang.y"
    {
                                    (yyval.stmt_node) = new ReturnNode((yyvsp[(2) - (3)].expr_node));
                                }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 314 "lang.y"
    {}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 317 "lang.y"
    {
                                    (yyval.func_node) = new FuncCallNode((yyvsp[(1) - (4)].symbol), (yyvsp[(3) - (4)].params_node));                              
                                }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 320 "lang.y"
    {
                                    (yyval.var_node) = (yyvsp[(1) - (3)].var_node);
                                    (yyval.var_node)->Add((yyvsp[(3) - (3)].var_part));
                                    if((yyval.var_node)->SemanticError())
                                    {
                                        semantic_error((yyval.var_node)->GetErrorMsg());
                                        YYERROR;
                                    }
                                }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 329 "lang.y"
    {
                                    (yyval.var_node) = new VarRefNode();
                                    (yyval.var_node)->Add((yyvsp[(1) - (1)].var_part));
                                    if((yyval.var_node)->SemanticError())
                                    {
                                        semantic_error((yyval.var_node)->GetErrorMsg());
                                        YYERROR;
                                    }
                                }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 339 "lang.y"
    {
                                    (yyval.var_part) = new VarPartNode((yyvsp[(1) - (2)].symbol),(yyvsp[(2) - (2)].ary_val));
                                }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 343 "lang.y"
    {
                                    (yyval.expr_node) = (yyvsp[(1) - (1)].var_node);
                                }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 346 "lang.y"
    {
                                    if((yyvsp[(1) - (4)].ary_val) == nullptr)
                                        (yyvsp[(1) - (4)].ary_val) = new ArrayValNode();
                                    (yyval.ary_val) = (yyvsp[(1) - (4)].ary_val);
                                    (yyval.ary_val)->Add((yyvsp[(3) - (4)].expr_node));
                                }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 352 "lang.y"
    {
                                    (yyval.ary_val) = NULL;
                                }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 356 "lang.y"
    {
                                    if((yyvsp[(1) - (3)].params_node) == nullptr)
                                        (yyvsp[(1) - (3)].params_node) = new ParamsNode();
                                    (yyval.params_node) = (yyvsp[(1) - (3)].params_node);
                                    (yyval.params_node)->Add((yyvsp[(3) - (3)].param_node));
                                }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 362 "lang.y"
    {
                                    (yyval.params_node) = new ParamsNode();
                                    (yyval.params_node)->Add((yyvsp[(1) - (1)].param_node));
                                }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 367 "lang.y"
    {
                                    (yyval.param_node) = new ParamNode((yyvsp[(1) - (1)].expr_node));
                                }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 370 "lang.y"
    {
                                    (yyval.param_node) = NULL;
                                }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 374 "lang.y"
    {
                                    (yyval.expr_node) = new BinaryExprNode((yyvsp[(1) - (3)].expr_node), '+', (yyvsp[(3) - (3)].expr_node));
                                }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 377 "lang.y"
    {
                                    (yyval.expr_node) = new BinaryExprNode((yyvsp[(1) - (3)].expr_node), '-', (yyvsp[(3) - (3)].expr_node));
                                }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 380 "lang.y"
    {
                                    (yyval.expr_node) = (yyvsp[(1) - (1)].expr_node);
                                }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 384 "lang.y"
    {
                                    (yyval.expr_node) = new BinaryExprNode((yyvsp[(1) - (3)].expr_node), '*', (yyvsp[(3) - (3)].expr_node));
                                }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 387 "lang.y"
    {
                                    (yyval.expr_node) = new BinaryExprNode((yyvsp[(1) - (3)].expr_node), '/', (yyvsp[(3) - (3)].expr_node));
                                }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 390 "lang.y"
    {
                                    (yyval.expr_node) = new BinaryExprNode((yyvsp[(1) - (3)].expr_node), '%', (yyvsp[(3) - (3)].expr_node));
                                }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 393 "lang.y"
    {
                                    (yyval.expr_node) = (yyvsp[(1) - (1)].expr_node);
                                }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 397 "lang.y"
    {
                                    (yyval.expr_node) = (yyvsp[(2) - (3)].expr_node);
                                }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 400 "lang.y"
    {
                                   (yyval.expr_node) = new IntExprNode((yyvsp[(1) - (1)].int_val));
                                }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 403 "lang.y"
    {
                                   (yyval.expr_node) = new FloatExprNode((yyvsp[(1) - (1)].float_val));
                                }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 406 "lang.y"
    {
                                   (yyval.expr_node) = (yyvsp[(1) - (1)].var_node);
                                }
    break;


/* Line 1792 of yacc.c  */
#line 2220 "langparse.c"
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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;

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
		      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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

#if !defined yyoverflow || YYERROR_VERBOSE
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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
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


/* Line 2055 of yacc.c  */
#line 411 "lang.y"


int yyerror(const char *msg)
{
    std::cerr << "ERROR: " << msg << " at symbol "
        << yytext << " on line " << yylineno << "\n";

    return 0;
}

void semantic_error(std::string msg)
{
    std::cout << "ERROR: " << msg <<
                 " on line " << yylineno << std::endl;
    
    yynerrs++;
}