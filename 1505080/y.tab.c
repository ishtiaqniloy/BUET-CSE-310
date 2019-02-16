/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "1505080.y" /* yacc.c:339  */

//Bison offline by 1505080
#include "1505080_SymbolTable.h"
#include <vector>

//#define YYSTYPE SymbolInfo*

using namespace std;

int yyparse(void);
int yylex(void);
extern FILE *yyin;

SymbolTable* symbolTable;

extern int line_count;
extern int lex_error;
int sem_error = 0;

char* varType = new char[20];

int argNo = 0;
int parNo = 0;
int fParNo = 0;
SymbolInfo** parList;
SymbolInfo** argList;

class ArrayType{
public:
    char* arrName;
    int arrSize;

    ArrayType(){
        arrName = new char[20];
        arrSize = 0;
    }

 };
vector<ArrayType*> arrays;

vector<char*> variables;

int labelCount=0;
int tempCount=0;

char *newLabel()
{
	char *lb= new char[10];
	sprintf(lb,"LB%d", labelCount);
	labelCount++;
	return lb;
}

char *newTempVar()
{
	char *tv= new char[10];
	sprintf(tv,"TV%d", tempCount);
	tempCount++;

	variables.push_back(tv);

	return tv;
}



FILE *parseout;
FILE *logout;
FILE *errorout;
FILE *codeout;
FILE *codeLog;


void yyerror(const char *s)
{
	//write your code
	printf("Syntex error at Line %d : %s\n", line_count, s);
	fprintf(logout, "Syntex error at Line %d : %s\n", line_count, s);

}



#line 150 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    MULOP = 258,
    BITOP = 259,
    RELOP = 260,
    ADDOP = 261,
    LOGICOP = 262,
    CONST_CHAR = 263,
    ID = 264,
    CONST_INT = 265,
    CONST_FLOAT = 266,
    STRING = 267,
    IF = 268,
    ELSE = 269,
    FOR = 270,
    WHILE = 271,
    DO = 272,
    BREAK = 273,
    INT = 274,
    CHAR = 275,
    FLOAT = 276,
    DOUBLE = 277,
    VOID = 278,
    RETURN = 279,
    SWITCH = 280,
    CASE = 281,
    DEFAULT = 282,
    CONTINUE = 283,
    LPAREN = 284,
    RPAREN = 285,
    LCURL = 286,
    RCURL = 287,
    LTHIRD = 288,
    RTHIRD = 289,
    COMMA = 290,
    SEMICOLON = 291,
    INCOP = 292,
    DECOP = 293,
    ASSIGNOP = 294,
    NOT = 295,
    PRINTLN = 296,
    LOWER_THAN_ELSE = 297
  };
#endif
/* Tokens.  */
#define MULOP 258
#define BITOP 259
#define RELOP 260
#define ADDOP 261
#define LOGICOP 262
#define CONST_CHAR 263
#define ID 264
#define CONST_INT 265
#define CONST_FLOAT 266
#define STRING 267
#define IF 268
#define ELSE 269
#define FOR 270
#define WHILE 271
#define DO 272
#define BREAK 273
#define INT 274
#define CHAR 275
#define FLOAT 276
#define DOUBLE 277
#define VOID 278
#define RETURN 279
#define SWITCH 280
#define CASE 281
#define DEFAULT 282
#define CONTINUE 283
#define LPAREN 284
#define RPAREN 285
#define LCURL 286
#define RCURL 287
#define LTHIRD 288
#define RTHIRD 289
#define COMMA 290
#define SEMICOLON 291
#define INCOP 292
#define DECOP 293
#define ASSIGNOP 294
#define NOT 295
#define PRINTLN 296
#define LOWER_THAN_ELSE 297

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 85 "1505080.y" /* yacc.c:355  */

	SymbolInfo *symbolInfoVar;

#line 278 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 295 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
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
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

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
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   145

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  119

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   115,   115,   164,   187,   203,   216,   228,   243,   301,
     354,   480,   564,   599,   634,   672,   704,   704,   754,   770,
     791,   806,   819,   834,   893,   965,  1023,  1096,  1109,  1136,
    1148,  1160,  1172,  1208,  1244,  1280,  1316,  1344,  1380,  1392,
    1412,  1459,  1530,  1542,  1678,  1690,  1768,  1780,  1881,  1894,
    1969,  1981,  2072,  2118,  2172,  2187,  2220,  2326,  2346,  2369,
    2392,  2512,  2635,  2648,  2662,  2703
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MULOP", "BITOP", "RELOP", "ADDOP",
  "LOGICOP", "CONST_CHAR", "ID", "CONST_INT", "CONST_FLOAT", "STRING",
  "IF", "ELSE", "FOR", "WHILE", "DO", "BREAK", "INT", "CHAR", "FLOAT",
  "DOUBLE", "VOID", "RETURN", "SWITCH", "CASE", "DEFAULT", "CONTINUE",
  "LPAREN", "RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", "COMMA",
  "SEMICOLON", "INCOP", "DECOP", "ASSIGNOP", "NOT", "PRINTLN",
  "LOWER_THAN_ELSE", "$accept", "start", "program", "unit",
  "func_declaration", "func_definition", "parameter_list",
  "compound_statement", "$@1", "var_declaration", "type_specifier",
  "declaration_list", "statements", "statement", "expression_statement",
  "variable", "expression", "logic_expression", "rel_expression",
  "simple_expression", "term", "unary_expression", "factor",
  "argument_list", "arguments", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297
};
# endif

#define YYPACT_NINF -69

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-69)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      76,   -69,   -69,   -69,    17,    76,   -69,   -69,   -69,   -69,
      11,   -69,   -69,    55,   -29,     8,    18,    34,   -69,   -10,
      20,    53,    27,    43,    47,   -69,   -69,    29,    76,   -69,
     -69,    72,   -69,    95,   -69,   -69,    78,    56,    13,    63,
     -69,   -69,    60,    71,    80,    13,    13,   -69,    13,    84,
     -69,   -69,    98,    62,   -69,   -69,    83,    79,   -69,   105,
      31,   114,   -69,   -69,   -69,   -69,    21,   -69,    13,    13,
      13,     5,    13,    87,    97,   -69,    13,    92,   -69,   -69,
     -69,   -69,    13,   -69,    13,    13,    13,    13,   -69,    99,
      93,    96,   102,     5,   103,   -69,   -69,   104,   -69,   -69,
     131,   114,   -69,   -69,    13,   -69,    95,    13,    95,   106,
     -69,   124,   109,   -69,   -69,    95,    95,   -69,   -69
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    20,    21,    22,     0,     2,     4,     6,     7,     5,
       0,     1,     3,    25,     0,     0,     0,     0,    19,     0,
       0,    15,     0,    23,    16,     9,    11,     0,     0,    14,
      26,     0,    18,     0,     8,    10,    13,     0,     0,    40,
      58,    59,     0,     0,     0,     0,     0,    38,     0,     0,
      31,    29,     0,     0,    27,    30,    55,     0,    42,    44,
      46,    48,    50,    54,    12,    24,    55,    52,    63,     0,
       0,     0,     0,     0,     0,    53,     0,    25,    17,    28,
      60,    61,     0,    39,     0,     0,     0,     0,    65,     0,
      62,     0,     0,     0,     0,    37,    57,     0,    43,    45,
      47,    49,    51,    56,     0,    41,     0,     0,     0,     0,
      64,    33,     0,    35,    36,     0,     0,    34,    32
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -69,   -69,   -69,   135,   -69,   -69,   -69,   -14,   -69,    69,
      52,   -69,   -69,   -52,   -68,   -38,   -37,   -64,    57,    58,
      59,   -36,   -69,   -69,   -69
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    20,    50,    33,    51,
      52,    14,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    89,    90
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      66,    79,    67,    93,    88,    26,    17,    18,    73,    74,
      66,    38,    75,    35,    39,    40,    41,    11,    98,    38,
      13,    24,    39,    40,    41,   107,    25,     1,    22,     2,
      66,     3,    91,    92,    46,    94,    85,    86,    19,    97,
     110,    47,    46,    23,    66,    48,    66,    66,    66,    66,
      27,   102,    10,    48,   111,    28,   113,    10,    80,    81,
      24,    30,    29,   117,   118,    34,    66,    21,    38,     9,
     112,    39,    40,    41,     9,    42,    31,    43,    44,    32,
      36,     1,    37,     2,    15,     3,    45,    64,    16,    70,
      65,    46,    68,    24,    78,     1,    69,     2,    47,     3,
      71,    38,    48,    49,    39,    40,    41,    77,    42,    72,
      43,    44,    84,    76,     1,    83,     2,    87,     3,    45,
      80,    81,    82,    95,    46,    16,    24,    96,   104,   103,
     105,    47,   106,   108,   109,    48,    49,    86,   115,   116,
      12,    99,   114,   100,     0,   101
};

static const yytype_int8 yycheck[] =
{
      38,    53,    38,    71,    68,    19,    35,    36,    45,    46,
      48,     6,    48,    27,     9,    10,    11,     0,    82,     6,
       9,    31,     9,    10,    11,    93,    36,    19,    10,    21,
      68,    23,    69,    70,    29,    72,     5,     6,    30,    76,
     104,    36,    29,     9,    82,    40,    84,    85,    86,    87,
      30,    87,     0,    40,   106,    35,   108,     5,    37,    38,
      31,    34,     9,   115,   116,    36,   104,    15,     6,     0,
     107,     9,    10,    11,     5,    13,    33,    15,    16,    32,
      28,    19,    10,    21,    29,    23,    24,     9,    33,    29,
      34,    29,    29,    31,    32,    19,    33,    21,    36,    23,
      29,     6,    40,    41,     9,    10,    11,     9,    13,    29,
      15,    16,     7,    29,    19,    36,    21,     3,    23,    24,
      37,    38,    39,    36,    29,    33,    31,    30,    35,    30,
      34,    36,    30,    30,    30,    40,    41,     6,    14,    30,
       5,    84,    36,    85,    -1,    86
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    19,    21,    23,    44,    45,    46,    47,    48,    52,
      53,     0,    46,     9,    54,    29,    33,    35,    36,    30,
      49,    53,    10,     9,    31,    36,    50,    30,    35,     9,
      34,    33,    32,    51,    36,    50,    53,    10,     6,     9,
      10,    11,    13,    15,    16,    24,    29,    36,    40,    41,
      50,    52,    53,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,     9,    34,    58,    64,    29,    33,
      29,    29,    29,    59,    59,    64,    29,     9,    32,    56,
      37,    38,    39,    36,     7,     5,     6,     3,    60,    66,
      67,    59,    59,    57,    59,    36,    30,    59,    60,    61,
      62,    63,    64,    30,    35,    34,    30,    57,    30,    30,
      60,    56,    59,    56,    36,    14,    30,    56,    56
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    46,    46,    47,    47,
      48,    48,    49,    49,    49,    49,    51,    50,    50,    52,
      53,    53,    53,    54,    54,    54,    54,    55,    55,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    57,    57,
      58,    58,    59,    59,    60,    60,    61,    61,    62,    62,
      63,    63,    64,    64,    64,    65,    65,    65,    65,    65,
      65,    65,    66,    66,    67,    67
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     5,
       6,     5,     4,     3,     2,     1,     0,     4,     2,     3,
       1,     1,     1,     3,     6,     1,     4,     1,     2,     1,
       1,     1,     7,     5,     7,     5,     5,     3,     1,     2,
       1,     4,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     2,     2,     1,     1,     4,     3,     1,     1,
       2,     2,     1,     0,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
      yychar = yylex ();
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
     '$$ = $1'.

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
#line 116 "1505080.y" /* yacc.c:1646  */
    {	     			          
			//write your code in this block in all the similar blocks below
			fprintf(parseout, "start : program\n");
			fprintf(logout, "Line No %d -> start : program\n", line_count);
			fprintf(codeLog, "Line No %d -> start : program\n", line_count);

			(yyval.symbolInfoVar) = (yyvsp[0].symbolInfoVar);
			(yyval.symbolInfoVar)->setType("start");
			fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());

			char *tempVar = newTempVar();
			char* returnAddress = newTempVar();

			fprintf(codeout, ".MODEL SMALL\n\n");
			fprintf(codeout, ".STACK 100h\n\n");

			fprintf(codeout, ".DATA\n");

			for(int i=0; i<variables.size(); i++){
				fprintf(codeout, "%s DW 0\n", variables[i]);
			}

			for(int i=0; i<arrays.size(); i++){
				fprintf(codeout, "%s DW %d DUP (0)\n", arrays[i]->arrName, arrays[i]->arrSize);
			}

			fprintf(codeout, "\n.CODE\n\n");


			fprintf(codeout, "ASMOUT PROC \nPOP %s\nPOP %s \nPUSH AX \nPUSH BX \nPUSH CX \nPUSH DX \nPUSH SP \nPUSH BP \nPUSH SI \nPUSH DI \
			 \nPUSHF \nCMP %s, 0 \nJGE NOT_NEG3 \nMOV AH, 2 \nMOV DL, '-' \nINT 21h \nNEG %s \nNOT_NEG3: \nCMP %s , 0 \nJNE NOT_ZERO \
			  \nMOV AH, 2 \nMOV DL, '0' \nINT 21h \nNOT_ZERO: \nMOV AX, '#' \nPUSH AX \nOUTPUT_LOOP1: \nCMP %s , 0 \
			   \nJE END_OUTPUT_LOOP1 \nMOV BX, 10 \nMOV DX, 0 \nMOV AX, %s  \nIDIV BX \nPUSH DX \nMOV %s , AX \nJMP OUTPUT_LOOP1 \
			    \nEND_OUTPUT_LOOP1: \nOUTPUT_LOOP2: \nPOP BX \nCMP BX, '#' \nJE END_OUTPUT_LOOP2 \nADD BX, '0' \nMOV AH, 2 \
			     \nMOV DL, BL \nINT 21h \nJMP OUTPUT_LOOP2 \nEND_OUTPUT_LOOP2: \nMOV AH, 2 \nMOV DL, 0Dh \nINT 21h \nMOV DL, 0Ah \
			      \nINT 21h \n\nPOPF \nPOP DI \nPOP SI \nPOP BP \nPOP SP \nPOP DX \nPOP CX \nPOP BX \nPOP AX \nPUSH %s \nRET \nASMOUT ENDP \n", 
			       returnAddress, tempVar, tempVar, tempVar, tempVar, tempVar, tempVar, tempVar, returnAddress);

			fprintf(codeout, "\n%s\n\n", (yyvsp[0].symbolInfoVar)->getCode());

			fprintf(codeout, "END MAIN\n");

				fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());

	
		}
#line 1507 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 165 "1505080.y" /* yacc.c:1646  */
    {	    		//done	           
			fprintf(parseout, "program : program unit\n");
			fprintf(logout, "Line No %d -> program : program unit\n", line_count);
			fprintf(codeLog, "Line No %d -> program : program unit\n", line_count);

			char* str = new char[strlen((yyvsp[-1].symbolInfoVar)->getKey()) + strlen((yyvsp[0].symbolInfoVar)->getKey()) + 200];
			sprintf(str, "%s%s", (yyvsp[-1].symbolInfoVar)->getKey(), (yyvsp[0].symbolInfoVar)->getKey());


			(yyval.symbolInfoVar) = new SymbolInfo(str, "program");

			char *tempCode = new char[strlen((yyvsp[-1].symbolInfoVar)->getCode()) + strlen((yyvsp[0].symbolInfoVar)->getCode()) + 100];
			sprintf(tempCode, "%s \n%s \n", (yyvsp[-1].symbolInfoVar)->getCode(), (yyvsp[0].symbolInfoVar)->getCode());
			(yyval.symbolInfoVar)->setCode(tempCode);         
			delete[] tempCode;

			fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
				fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());

			delete[] str;

		}
#line 1534 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 188 "1505080.y" /* yacc.c:1646  */
    {	   //done 			//NOTHING TO DO	
			fprintf(parseout, "program : unit\n");
			fprintf(logout, "Line No %d -> program : unit\n", line_count);
			fprintf(codeLog, "Line No %d -> program : unit\n", line_count);
			

			
			(yyval.symbolInfoVar) = (yyvsp[0].symbolInfoVar);
			(yyval.symbolInfoVar)->setType("program");
			fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
				fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());

		}
#line 1552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 204 "1505080.y" /* yacc.c:1646  */
    {	    //done 				//ALL DONE
			fprintf(parseout, "unit : var_declaration\n");
			fprintf(logout, "Line No %d -> unit : var_declaration\n", line_count);
			fprintf(codeLog, "Line No %d -> unit : var_declaration\n", line_count);
			
			(yyval.symbolInfoVar) = (yyvsp[0].symbolInfoVar);
			(yyval.symbolInfoVar)->setType("unit");
			fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
				fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());


		}
#line 1569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 217 "1505080.y" /* yacc.c:1646  */
    {	    //done
			fprintf(parseout, "unit : func_declaration\n");
			fprintf(logout, "Line No %d -> unit : func_declaration\n", line_count);
			fprintf(codeLog, "Line No %d -> unit : func_declaration\n", line_count);
			
			(yyval.symbolInfoVar) = (yyvsp[0].symbolInfoVar);
			(yyval.symbolInfoVar)->setType("unit");
			fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
				fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());

		}
#line 1585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 229 "1505080.y" /* yacc.c:1646  */
    {	    //done
			fprintf(parseout, "unit : func_definition\n");
			fprintf(logout, "Line No %d -> unit : func_definition\n", line_count);
			fprintf(codeLog, "Line No %d -> unit : func_definition\n", line_count);
			
			(yyval.symbolInfoVar) = (yyvsp[0].symbolInfoVar);
			(yyval.symbolInfoVar)->setType("unit");

			fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
				fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());
		
		}
#line 1602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 244 "1505080.y" /* yacc.c:1646  */
    {	   //done  			 //NOTING TO DO         
						fprintf(parseout, "func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n");
						fprintf(logout, "Line No %d -> func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n", line_count);
						fprintf(codeLog, "Line No %d -> func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n", line_count);

						char* str = new char[strlen((yyvsp[-4].symbolInfoVar)->getKey())+strlen((yyvsp[-2].symbolInfoVar)->getKey())+200];
						char* retType = (yyvsp[-5].symbolInfoVar)->getKey();

										
						sprintf(str, "%s %s(%s);\n",retType, (yyvsp[-4].symbolInfoVar)->getKey(), (yyvsp[-2].symbolInfoVar)->getKey());

						(yyval.symbolInfoVar) = new SymbolInfo(str, "func_declaration");

						fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
									
						//symbolTable->printAllScopeTable(logout);

						delete[] str;

						char *key = (yyvsp[-4].symbolInfoVar)->getKey();

						if(strcmp(key, "main")==0){
							sprintf(key, "MAIN");							
						}

						SymbolInfo *sInfo = symbolTable->lookUpCurrent(key);
						if(sInfo!=NULL){
							fprintf(errorout, "Semantic Error : Line No %d -> Identifier %s already declared in  this scope\n", line_count, key);
							sem_error++;
						}
						else{
							bool flag = symbolTable->insert(key, "ID");
							if(flag){
								sInfo = symbolTable->lookUp(key);

								sInfo->setIDType("FUNC");
								sInfo->setFuncRetType(retType);
								sInfo->setFuncIsDefined(false);

								sInfo->setParamNo(fParNo);

								for(int i=0; i<parNo; i++){
									sInfo->paramList[i] = parList[i];
								}

								parNo = 0;

								//sInfo = symbolTable->lookUp(key);
								//fprintf(logout, "%s %s %s %s\n", sInfo->getKey(), sInfo->getType(), sInfo->getIDType(), sInfo->getVarType());	

							}
							//symbolTable->printAllScopeTable(logout);
						}

						fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());

					}
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 302 "1505080.y" /* yacc.c:1646  */
    {	    //done  			 //NOTING TO DO   
						fprintf(parseout, "func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n");
						fprintf(logout, "Line No %d -> func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n", line_count);
						fprintf(codeLog, "Line No %d -> func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n", line_count);

						char* str = new char[strlen((yyvsp[-3].symbolInfoVar)->getKey())+200];
						char* retType = (yyvsp[-4].symbolInfoVar)->getKey();

										
						sprintf(str, "%s %s();\n",retType, (yyvsp[-3].symbolInfoVar)->getKey() );

						(yyval.symbolInfoVar) = new SymbolInfo(str, "func_declaration");

						fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
									
						//symbolTable->printAllScopeTable(logout);

						delete[] str;

						char *key = (yyvsp[-3].symbolInfoVar)->getKey();
						if(strcmp(key, "main")==0){
							sprintf(key, "MAIN");							
						}

						SymbolInfo *sInfo = symbolTable->lookUpCurrent(key);
						if(sInfo!=NULL){
							fprintf(errorout, "Semantic Error : Line No %d -> Identifier %s already declared in  this scope\n", line_count, key);
							sem_error++;
						}
						else{
							bool flag = symbolTable->insert(key, "ID");
							if(flag){
								sInfo = symbolTable->lookUp(key);
								
								sInfo->setIDType("FUNC");
								sInfo->setFuncRetType(retType);
								sInfo->setFuncIsDefined(false);

								sInfo->setParamNo(0);

								//sInfo = symbolTable->lookUp(key);
								//fprintf(logout, "%s %s %s %s\n", sInfo->getKey(), sInfo->getType(), sInfo->getIDType(), sInfo->getVarType());	

							}
							//symbolTable->printAllScopeTable(logout);
						}

						fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());

					}
#line 1719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 355 "1505080.y" /* yacc.c:1646  */
    {	     		//done 	          
					fprintf(parseout, "func_definition : type_specifier ID LPAREN parameter_list RPAREN\n");
					fprintf(logout, "Line No %d -> func_definition : type_specifier ID LPAREN parameter_list RPAREN\n", line_count);
					fprintf(codeLog, "Line No %d -> func_definition : type_specifier ID LPAREN parameter_list RPAREN\n", line_count);
		
						char* str = new char[strlen((yyvsp[-4].symbolInfoVar)->getKey())+strlen((yyvsp[-2].symbolInfoVar)->getKey())+strlen((yyvsp[0].symbolInfoVar)->getKey())+200];
						char* retType = (yyvsp[-5].symbolInfoVar)->getKey();

						sprintf(str, "%s %s(%s)%s",retType, (yyvsp[-4].symbolInfoVar)->getKey(), (yyvsp[-2].symbolInfoVar)->getKey(), (yyvsp[0].symbolInfoVar)->getKey());

						(yyval.symbolInfoVar) = new SymbolInfo(str, "func_definition");

						fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
									
						//symbolTable->printAllScopeTable(logout);

						delete[] str;

						char *key = (yyvsp[-4].symbolInfoVar)->getKey();
						if(strcmp(key, "main")==0){
							sprintf(key, "MAIN");							
						}
						
						SymbolInfo *sInfo = symbolTable->lookUpCurrent(key);

						if(sInfo!=NULL && strcmp(sInfo->getIDType(), "FUNC")!=0){	//variable or array already declared
							fprintf(errorout, "Semantic Error : Line No %d -> Identifier %s already declared in  this scope\n", line_count, key);
							sem_error++;
						}
						else if(sInfo!=NULL && sInfo->getFuncIsDefined()){	//function already defined
							fprintf(errorout, "Semantic Error : Line No %d -> Function %s() already defined in  this scope\n", line_count, key);
							sem_error++;
						}
						else if(sInfo!=NULL && strcmp(sInfo->getFuncRetType(), retType)!=0){	//return type mismatch
							fprintf(errorout, "Semantic Error : Line No %d -> Function %s() return type mismatch\n", line_count, key);
							sem_error++;
						}
						else if(sInfo!=NULL && sInfo->getParamNo()!=fParNo){	//parameter number mismatch
							fprintf(errorout, "Semantic Error : Line No %d -> Function %s() parameter number mismatch\n", line_count, key);
							sem_error++;
						}
						else{
							//fprintf(errorout, "HERE\n");
							bool flag = true;
							if(sInfo!=NULL && sInfo->paramList!=NULL && fParNo>0){	//parameter type mismatch check
								for(int i=0; i<fParNo; i++){
									SymbolInfo *temp = sInfo->paramList[i];
									SymbolInfo *temp2 = parList[i];
									if(temp==NULL || temp2==NULL){
										fprintf(errorout, "Semantic Error : Line No %d -> Function %s() parameter type mismatch\n", line_count, key);
										sem_error++;
										flag = false;
										break;
									}
									else if(strcmp(temp->getVarType(), temp2->getVarType() ) ){
										fprintf(errorout, "Semantic Error : Line No %d -> Function %s() parameter type mismatch\n", line_count, key);
										sem_error++;
										flag = false;
										break;
									}
								}
							}
							if(flag){
								flag = symbolTable->insert(key, "ID");
								sInfo = symbolTable->lookUp(key);

								sInfo->setIDType("FUNC");
								sInfo->setFuncRetType(retType);
								sInfo->setFuncIsDefined(true);

								sInfo->setParamNo(fParNo);

								for(int i=0; i<parNo; i++){
									sInfo->paramList[i] = parList[i];
								}

								parNo = 0;

								sInfo->setScopeNo(symbolTable->getNumberOfScopes());

								char* tempCode = new char[strlen((yyvsp[0].symbolInfoVar)->getCode())+500];

								if(strcmp(key, "MAIN")==0){
									sprintf(tempCode, "MAIN PROC \nMOV DX, @DATA \nMOV DS, DX \n%s \nMOV AH, 4Ch \nINT 21h \nMAIN ENDP ", (yyvsp[0].symbolInfoVar)->getCode());
								}
								else{
									int np = sInfo->getParamNo();

									char *popParam = new char[200];
									sprintf(popParam, "");

									for(int i=np-1; i>=0; i--){
											char* varName  = new char[25];
											sprintf(varName, "%s%d", parList[i]->getKey(), sInfo->getScopeNo());
											sprintf(popParam, "%sPOP %s\n", popParam, varName);
									}						

									char *returnAddress = newTempVar();
									char *dummy = newTempVar();

									//DX is used for returning values
									
									sprintf(tempCode, "%s PROC \nPOP %s \n%s \nPUSH AX \nPUSH BX \nPUSH CX \nPUSH DX \nPUSH SP \nPUSH BP \
										\nPUSH SI \nPUSH DI \nPUSHF \nPUSH %s \n%s \nRET \n%s ENDP", 
										 key, returnAddress, popParam, returnAddress, (yyvsp[0].symbolInfoVar)->getCode(), key);


								}

								(yyval.symbolInfoVar)->setCode(tempCode);         
								delete[] tempCode;



								//sInfo = symbolTable->lookUp(key);
								//fprintf(logout, "%s %s %s %s\n", sInfo->getKey(), sInfo->getType(), sInfo->getIDType(), sInfo->getVarType());	

								//symbolTable->printAllScopeTable(logout);
							}

							fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());
							
						}

				}
#line 1849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 481 "1505080.y" /* yacc.c:1646  */
    {	     //done
					fprintf(parseout, "func_definition : type_specifier ID LPAREN RPAREN compound_statement\n");
					fprintf(logout, "Line No %d -> func_definition : type_specifier ID LPAREN RPAREN compound_statement\n", line_count);
					fprintf(codeLog, "Line No %d -> func_definition : type_specifier ID LPAREN RPAREN compound_statement\n", line_count);


					char* str = new char[strlen((yyvsp[-3].symbolInfoVar)->getKey())+strlen((yyvsp[0].symbolInfoVar)->getKey())+200];
						char* retType = (yyvsp[-4].symbolInfoVar)->getKey();

										
						sprintf(str, "%s %s()%s",retType, (yyvsp[-3].symbolInfoVar)->getKey(), (yyvsp[0].symbolInfoVar)->getKey());

						(yyval.symbolInfoVar) = new SymbolInfo(str, "func_definition");

						fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
									
						//symbolTable->printAllScopeTable(logout);

						delete[] str;

						char *key = (yyvsp[-3].symbolInfoVar)->getKey();
						if(strcmp(key, "main")==0){
							sprintf(key, "MAIN");							
						}
						
						SymbolInfo *sInfo = symbolTable->lookUpCurrent(key);

						if(sInfo!=NULL && strcmp(sInfo->getIDType(), "FUNC")!=0){	//variable or array already declared
							fprintf(errorout, "Semantic Error : Line No %d -> Identifier %s already declared in  this scope\n", line_count, key);
							sem_error++;
						}
						else if(sInfo!=NULL && sInfo->getFuncIsDefined()){	//function already defined
							fprintf(errorout, "Semantic Error : Line No %d -> Function %s() already defined in  this scope\n", line_count, key);
							sem_error++;
						}
						else if(sInfo!=NULL && strcmp(sInfo->getFuncRetType(), retType)!=0){	//return type mismatch
							fprintf(errorout, "Semantic Error : Line No %d -> Function %s() return type mismatch\n", line_count, key);
							sem_error++;
						}
						else if(sInfo!=NULL && sInfo->getParamNo()!=0){	//parameter number mismatch
							fprintf(errorout, "Semantic Error : Line No %d -> Function %s() parameter number mismatch\n", line_count, key);
							sem_error++;
						}
						else{
							bool flag = symbolTable->insert(key, "ID");
							sInfo = symbolTable->lookUp(key);
								
							sInfo->setIDType("FUNC");
							sInfo->setFuncRetType(retType);
							sInfo->setFuncIsDefined(true);

							sInfo->setParamNo(0);

							sInfo->setScopeNo(symbolTable->getNumberOfScopes());

								char* tempCode = new char[strlen((yyvsp[0].symbolInfoVar)->getCode())+300];

								if(strcmp(key, "MAIN")==0){
									sprintf(tempCode, "MAIN PROC \nMOV DX, @DATA \nMOV DS, DX \n%s \nMOV AH, 4Ch \nINT 21h \nMAIN ENDP ", (yyvsp[0].symbolInfoVar)->getCode());
								}
								else{
									char *returnAddress = newTempVar();
									//DX is used for returning values
									sprintf(tempCode, "%s PROC \nPOP %s \nPUSH AX \nPUSH BX \nPUSH CX \nPUSH DX \
										\nPUSH SP \nPUSH BP \nPUSH SI \nPUSH DI \nPUSHF \nPUSH %s \n%s \nRET \n%s ENDP", 
										 key, returnAddress, returnAddress, (yyvsp[0].symbolInfoVar)->getCode(), key);
								}

								(yyval.symbolInfoVar)->setCode(tempCode);         
								delete[] tempCode;

							//sInfo = symbolTable->lookUp(key);
							//fprintf(logout, "%s %s %s %s\n", sInfo->getKey(), sInfo->getType(), sInfo->getIDType(), sInfo->getVarType());	

							//symbolTable->printAllScopeTable(logout);
						}
				fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());


				}
#line 1934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 565 "1505080.y" /* yacc.c:1646  */
    {	     			          //done  			 //NOTING TO DO   
					fprintf(parseout, "parameter_list : parameter_list COMMA type_specifier ID\n");
					fprintf(logout, "Line No %d -> parameter_list : parameter_list COMMA type_specifier ID\n", line_count);
					fprintf(codeLog, "Line No %d -> parameter_list : parameter_list COMMA type_specifier ID\n", line_count);

					parList[parNo] = new SymbolInfo((yyvsp[0].symbolInfoVar)->getKey(),"PARAMETER");
					
					char* str = new char[strlen((yyvsp[-3].symbolInfoVar)->getKey()) + strlen((yyvsp[0].symbolInfoVar)->getKey()) +200];			
						
					if(strcmp((yyvsp[-1].symbolInfoVar)->getKey(),"int")==0){
						sprintf(str, "%s, int %s", (yyvsp[-3].symbolInfoVar)->getKey(), (yyvsp[0].symbolInfoVar)->getKey());
						parList[parNo]->setVarType("INT");
					}
					else if(strcmp((yyvsp[-1].symbolInfoVar)->getKey(),"float")==0){
						sprintf(str, "%s, float %s", (yyvsp[-3].symbolInfoVar)->getKey(), (yyvsp[0].symbolInfoVar)->getKey());
						parList[parNo]->setVarType("FLOAT");
					}
					else if(strcmp((yyvsp[-1].symbolInfoVar)->getKey(),"void")==0){
						sprintf(str, "%s, void %s", (yyvsp[-3].symbolInfoVar)->getKey(), (yyvsp[0].symbolInfoVar)->getKey());
						parList[parNo]->setVarType("VOID");
					}

					parNo++;
					fParNo = parNo;

					(yyval.symbolInfoVar) = new SymbolInfo(str, "parameter_list");
						
					fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
				fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());

					delete[] str;


				}
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 600 "1505080.y" /* yacc.c:1646  */
    {	    //done  			 //NOTING TO DO   
					fprintf(parseout, "parameter_list : parameter_list COMMA type_specifier\n");
					fprintf(logout, "Line No %d -> parameter_list : parameter_list COMMA type_specifier\n", line_count);
					fprintf(codeLog, "Line No %d -> parameter_list : parameter_list COMMA type_specifier\n", line_count);

					parList[parNo] = new SymbolInfo("","PARAMETER");

					char* str = new char[strlen((yyvsp[-2].symbolInfoVar)->getKey())+200];			
						
					if(strcmp((yyvsp[0].symbolInfoVar)->getKey(),"int")==0){
						sprintf(str, "%s, int", (yyvsp[-2].symbolInfoVar)->getKey());
						parList[parNo]->setVarType("INT");
					}
					else if(strcmp((yyvsp[0].symbolInfoVar)->getKey(),"float")==0){
						sprintf(str, "%s, float", (yyvsp[-2].symbolInfoVar)->getKey());
						parList[parNo]->setVarType("FLOAT");
					}
					else if(strcmp((yyvsp[0].symbolInfoVar)->getKey(),"void")==0){
						sprintf(str, "%s, void", (yyvsp[-2].symbolInfoVar)->getKey());
						parList[parNo]->setVarType("VOID");
					}
					
					parNo++;
					fParNo = parNo;

					(yyval.symbolInfoVar) = new SymbolInfo(str, "parameter_list");
						
					fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
				fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());


					delete[] str;

		 		}
#line 2012 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 635 "1505080.y" /* yacc.c:1646  */
    {	    //done  			 //NOTING TO DO   
					fprintf(parseout, "parameter_list : type_specifier ID\n");
					fprintf(logout, "Line No %d -> parameter_list : type_specifier ID\n", line_count);
					fprintf(codeLog, "Line No %d -> parameter_list : type_specifier ID\n", line_count);

					parNo=0;
					parList[parNo] = new SymbolInfo((yyvsp[0].symbolInfoVar)->getKey(),"PARAMETER");

					char* str = new char[strlen((yyvsp[0].symbolInfoVar)->getKey())+200];			
						
					if(strcmp((yyvsp[-1].symbolInfoVar)->getKey(),"int")==0){
						sprintf(str, "int %s", (yyvsp[0].symbolInfoVar)->getKey());
						parList[parNo]->setVarType("INT");
					}
					else if(strcmp((yyvsp[-1].symbolInfoVar)->getKey(),"float")==0){
						sprintf(str, "float %s", (yyvsp[0].symbolInfoVar)->getKey());
						parList[parNo]->setVarType("FLOAT");
					}
					else if(strcmp((yyvsp[-1].symbolInfoVar)->getKey(),"void")==0){
						fprintf(errorout, "Semantic Error : Line No %d -> Parameter type cannot be VOID\n", line_count);
						sem_error++;
						sprintf(str, "void %s", (yyvsp[0].symbolInfoVar)->getKey());
					}

					parNo++;
					fParNo = parNo;

					(yyval.symbolInfoVar) = new SymbolInfo(str, "parameter_list");
						
					fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
				fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());


					delete[] str;


				}
#line 2054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 673 "1505080.y" /* yacc.c:1646  */
    {	    //done  			 //NOTING TO DO   
					fprintf(parseout, "parameter_list : type_specifier\n");
					fprintf(logout, "Line No %d -> parameter_list : type_specifier\n", line_count);
					fprintf(codeLog, "Line No %d -> parameter_list : type_specifier\n", line_count);

					parNo=0;
					parList[parNo] = new SymbolInfo("","PARAMETER");

					if(strcmp((yyvsp[0].symbolInfoVar)->getKey(),"int")==0){
						(yyval.symbolInfoVar) = new SymbolInfo("int", "parameter_list");
						parList[parNo]->setVarType("INT");
					}
					else if(strcmp((yyvsp[0].symbolInfoVar)->getKey(),"float")==0){
						(yyval.symbolInfoVar) = new SymbolInfo("float", "parameter_list");
						parList[parNo]->setVarType("FLOAT");
					}
					else if(strcmp((yyvsp[0].symbolInfoVar)->getKey(),"void")==0){
						(yyval.symbolInfoVar) = new SymbolInfo("void", "parameter_list");
						parList[parNo]->setVarType("VOID");
					} 
					parNo++;
					fParNo = parNo;

					fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
				fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());

		 		}
#line 2086 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 704 "1505080.y" /* yacc.c:1646  */
    {	 //done 	//ALL DONE        
								symbolTable->enterScope();
								fprintf(logout, "Line No %d -> ENTERED NEW SCOPE NO : %d\n", line_count, symbolTable->getScopeNum());
								for(int i=0; i<parNo; i++){
									SymbolInfo* temp = parList[i];
									if(temp!=NULL){
										symbolTable->insert(temp->getKey(), "ID");	
										SymbolInfo* temp2 = symbolTable->lookUpCurrent(temp->getKey());
										if(temp2!=NULL){
											temp2->setIDType("VAR");
											temp2->setVarType(temp->getVarType());
											temp2->setScopeNo(symbolTable->getScopeNum());

											char* varName  = new char[25];
											sprintf(varName, "%s%d", temp2->getKey(), symbolTable->getScopeNum());

											variables.push_back(varName);


										}
									}
									

								}
								parNo = 0;
							}
#line 2117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 731 "1505080.y" /* yacc.c:1646  */
    {
						fprintf(parseout, "compound_statement : LCURL statements RCURL\n");
						fprintf(logout, "Line No %d -> compound_statement : LCURL statements RCURL\n", line_count);
						fprintf(codeLog, "Line No %d -> compound_statement : LCURL statements RCURL\n", line_count);

						char* str = new char[strlen((yyvsp[-1].symbolInfoVar)->getKey())+200];
						sprintf(str, "{\n%s}\n", (yyvsp[-1].symbolInfoVar)->getKey());

						(yyval.symbolInfoVar) = new SymbolInfo(str, "compound_statement");

						(yyval.symbolInfoVar)->setCode((yyvsp[-1].symbolInfoVar)->getCode());

						fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
				fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());
									
						//symbolTable->printAllScopeTable(logout);

						delete[] str;

						symbolTable->printAllScopeTable(logout);
						symbolTable->exitScope();

		 		    }
#line 2145 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 755 "1505080.y" /* yacc.c:1646  */
    {	    //done
						fprintf(parseout, "compound_statement : LCURL RCURL\n");
						fprintf(logout, "Line No %d -> compound_statement : LCURL RCURL\n", line_count);
						fprintf(codeLog, "Line No %d -> compound_statement : LCURL RCURL\n", line_count);


						(yyval.symbolInfoVar) = new SymbolInfo("{}\n", "compound_statement");
						fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
				fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());
									
						//symbolTable->printAllScopeTable(logout);

		 		    }
#line 2163 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 771 "1505080.y" /* yacc.c:1646  */
    {	     			         //done  			 //NOTING TO DO   //ALL DONE
					fprintf(parseout, "var_declaration : type_specifier declaration_list SEMICOLON\n");
					fprintf(logout, "Line No %d -> var_declaration : type_specifier declaration_list SEMICOLON\n", line_count);
					fprintf(codeLog, "Line No %d -> var_declaration : type_specifier declaration_list SEMICOLON\n", line_count);

					char* str = new char[strlen((yyvsp[-1].symbolInfoVar)->getKey())+200];
					sprintf(str, "%s %s;\n", (yyvsp[-2].symbolInfoVar)->getKey(), (yyvsp[-1].symbolInfoVar)->getKey() );

					(yyval.symbolInfoVar) = new SymbolInfo(str, "var_declaration");
					fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
				fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());
								
					//symbolTable->printAllScopeTable(logout);

					delete[] str;


				}
#line 2186 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 792 "1505080.y" /* yacc.c:1646  */
    {		//done  			 //NOTING TO DO        //ALL DONE   
					fprintf(parseout, "type_specifier : INT\n");
					fprintf(logout, "Line No %d -> type_specifier : INT\n", line_count);
					fprintf(codeLog, "Line No %d -> type_specifier : INT\n", line_count);

					strcpy(varType, "INT");
					(yyval.symbolInfoVar) = new SymbolInfo("int", "type_specifier");

					fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
				fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());



				}
#line 2205 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 807 "1505080.y" /* yacc.c:1646  */
    {	    //done  			 //NOTING TO DO   
					fprintf(parseout, "type_specifier : FLOAT\n");
					fprintf(logout, "Line No %d -> type_specifier : FLOAT\n", line_count);
					fprintf(codeLog, "Line No %d -> type_specifier : FLOAT\n", line_count);

					strcpy(varType, "FLOAT");
					(yyval.symbolInfoVar) = new SymbolInfo("float", "type_specifier");

					fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
				fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());

		 		}
#line 2222 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 820 "1505080.y" /* yacc.c:1646  */
    {	    //done  			 //NOTING TO DO   
					fprintf(parseout, "type_specifier : VOID\n");
					fprintf(logout, "Line No %d -> type_specifier : VOID\n", line_count);
					fprintf(codeLog, "Line No %d -> type_specifier : VOID\n", line_count);

					strcpy(varType, "VOID");
					(yyval.symbolInfoVar) = new SymbolInfo("void", "type_specifier");

					fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
				fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());

		 		}
#line 2239 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 835 "1505080.y" /* yacc.c:1646  */
    {	     	//DONE 			//ALL DONE	          
						fprintf(parseout, "declaration_list : declaration_list COMMA ID\n");
						fprintf(logout, "Line No %d -> declaration_list : declaration_list COMMA ID\n", line_count);
						fprintf(codeLog, "Line No %d -> declaration_list : declaration_list COMMA ID\n", line_count);

						char* s1 = (yyvsp[-2].symbolInfoVar)->getKey();
						char* s2 = (yyvsp[0].symbolInfoVar)->getKey();

						strcat(s1,",");
						strcat(s1,s2);

						(yyval.symbolInfoVar)->setKey(s1);

						fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());

						if(strcmp(varType,"VOID")==0){
							fprintf(errorout, "Semantic Error : Line No %d -> Variable type cannot be VOID\n", line_count);
							sem_error++;
						}
						else{
							char *key = s2;
							SymbolInfo *sInfo = symbolTable->lookUpCurrent(key);

							if(sInfo!=NULL){
								fprintf(errorout, "Semantic Error : Line No %d -> Identifier %s already declared in  this scope\n",line_count, key);
								sem_error++;

							}
							else{
								bool flag = symbolTable->insert(key, "ID");

								if(flag){
									sInfo = symbolTable->lookUp(key);

									sInfo->setIDType("VAR");
									sInfo->setVarType(varType);
									sInfo->setScopeNo(symbolTable->getScopeNum());

									char* varName  = new char[25];
									sprintf(varName, "%s%d", sInfo->getKey(), symbolTable->getScopeNum());

									variables.push_back(varName);

									//sInfo = symbolTable->lookUp(key);
									//fprintf(logout, "%s %s %s %s\n", sInfo->getKey(), sInfo->getType(), sInfo->getIDType(), sInfo->getVarType());	

								}
								//symbolTable->printAllScopeTable(logout);

							}

						}
				fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());




 		  			}
#line 2302 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 894 "1505080.y" /* yacc.c:1646  */
    {	    //done
						fprintf(parseout, "declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n");
						fprintf(logout, "Line No %d -> declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n", line_count);
						fprintf(codeLog, "Line No %d -> declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n", line_count);

			 		
						char* s = (yyvsp[-3].symbolInfoVar)->getKey();
						char* size = (yyvsp[-1].symbolInfoVar)->getKey();

						
						if(strcmp(varType,"VOID")==0){
							fprintf(errorout, "Semantic Error : Line No %d -> Variable type cannot be VOID\n", line_count);
							sem_error++;
						}
						else{
							char *key = s;
							SymbolInfo *sInfo = symbolTable->lookUpCurrent(key);

							if(sInfo!=NULL){
								fprintf(errorout, "Semantic Error : Line No %d -> Identifier %s already declared in  this scope\n", line_count, key);
								sem_error++;

							}
							else{
								bool flag = symbolTable->insert(key, "ID");

								if(flag){
									sInfo = symbolTable->lookUp(key);

									sInfo->setIDType("ARR");
									
									int arrSize = atoi(size);
									(yyvsp[-1].symbolInfoVar)->intVal = arrSize;
									sInfo->setArrSize(arrSize);
									//fprintf(logout, "%s %d %d\n", key, arrSize, sInfo->getArrSize());	

									sInfo->setVarType(varType);
									sInfo->setScopeNo(symbolTable->getScopeNum());

									char* arrName  = new char[25];
									sprintf(arrName, "%s%d", sInfo->getKey(), symbolTable->getScopeNum());

									ArrayType* arrT = new ArrayType();

									arrT->arrName = arrName;
									arrT->arrSize = arrSize;

									arrays.push_back(arrT);
									

									//sInfo = symbolTable->lookUp(key);
									//fprintf(logout, "%s %s %s %s %d\n", sInfo->getKey(), sInfo->getType(), sInfo->getIDType(), sInfo->getVarType(), sInfo->getArrSize());	

								}
								//symbolTable->printAllScopeTable(logout);

							}

						}

						char *str = new char[strlen(s)+200];

						sprintf(str, "%s,%s[%s]",(yyvsp[-5].symbolInfoVar)->getKey(), s ,size);

						(yyval.symbolInfoVar)->setKey(str);
						fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
						fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());

						delete[] str;

			 		}
#line 2378 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 966 "1505080.y" /* yacc.c:1646  */
    {	    //done
						fprintf(parseout, "declaration_list : ID\n");
						fprintf(logout, "Line No %d -> declaration_list : ID\n", line_count);
						fprintf(codeLog, "Line No %d -> declaration_list : ID\n", line_count);

						char* s = (yyvsp[0].symbolInfoVar)->getKey();
						//fprintf(logout, "%s\n\n", s);
						(yyval.symbolInfoVar)->setKey(s);

						fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());


						if(strcmp(varType,"VOID")==0){
							fprintf(errorout, "Semantic Error : Line No %d -> Variable type cannot be VOID\n", line_count);
							sem_error++;
						}
						else{
							char *key = (yyvsp[0].symbolInfoVar)->getKey();
							SymbolInfo *sInfo = symbolTable->lookUpCurrent(key);

							if(sInfo!=NULL){
								fprintf(errorout, "Semantic Error : Line No %d -> Identifier %s already declared in  this scope\n", line_count, key);
								sem_error++;

							}
							else{
								bool flag = symbolTable->insert(key, "ID");

								if(flag){
									sInfo = symbolTable->lookUp(key);

									sInfo->setIDType("VAR");
									sInfo->setVarType(varType);
									sInfo->setScopeNo(symbolTable->getScopeNum());

									char* varName  = new char[25];
									sprintf(varName, "%s%d", sInfo->getKey(), symbolTable->getScopeNum());

									variables.push_back(varName);

									//sInfo = symbolTable->lookUp(key);
									//fprintf(logout, "%s %s %s %s\n", sInfo->getKey(), sInfo->getType(), sInfo->getIDType(), sInfo->getVarType());	


								}
								//symbolTable->printAllScopeTable(logout);

							}

						}


				fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());



			 		}
#line 2440 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 1024 "1505080.y" /* yacc.c:1646  */
    {	    //done
						fprintf(parseout, "declaration_list : ID LTHIRD CONST_INT RTHIRD\n");
						fprintf(logout, "Line No %d -> declaration_list : ID LTHIRD CONST_INT RTHIRD\n", line_count);
						fprintf(codeLog, "Line No %d -> declaration_list : ID LTHIRD CONST_INT RTHIRD\n", line_count);

						char* s = (yyvsp[-3].symbolInfoVar)->getKey();
						char* size = (yyvsp[-1].symbolInfoVar)->getKey();

						
						if(strcmp(varType,"VOID")==0){
							fprintf(errorout, "Semantic Error : Line No %d -> Variable type cannot be VOID\n", line_count);
							sem_error++;
						}
						else{
							char *key = s;
							SymbolInfo *sInfo = symbolTable->lookUpCurrent(key);

							if(sInfo!=NULL){
								fprintf(errorout, "Semantic Error : Line No %d -> Identifier %s already declared in  this scope\n", line_count, key);
								sem_error++;

							}
							else{
								bool flag = symbolTable->insert(key, "ID");

								if(flag){
									sInfo = symbolTable->lookUp(key);

									sInfo->setIDType("ARR");
									
									int arrSize = atoi(size);
									(yyvsp[-1].symbolInfoVar)->intVal = arrSize;
									sInfo->setArrSize(arrSize);
									//fprintf(logout, "%s %d %d\n", key, arrSize, sInfo->getArrSize());	

									sInfo->setVarType(varType);
									sInfo->setScopeNo(symbolTable->getScopeNum());

									char* arrName  = new char[25];
									sprintf(arrName, "%s%d", sInfo->getKey(), symbolTable->getScopeNum());

									ArrayType* arrT = new ArrayType();

									arrT->arrName = arrName;
									arrT->arrSize = arrSize;

									arrays.push_back(arrT);

									//sInfo = symbolTable->lookUp(key);
									//fprintf(logout, " %s %s %s %s %d\n", sInfo->getKey(), sInfo->getType(), sInfo->getIDType(), sInfo->getVarType(), sInfo->getArrSize());	

								}
								//symbolTable->printAllScopeTable(logout);

							}

						}

						char *str = new char[strlen(s)+200];

						sprintf(str, "%s[%s]",s ,size);

						(yyval.symbolInfoVar)->setKey(str);
						fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
				fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());

						delete[] str;


			 		}
#line 2515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 1097 "1505080.y" /* yacc.c:1646  */
    {	     		//done	          
				fprintf(parseout, "statements : statement\n");
				fprintf(logout, "Line No %d -> statements : statement\n", line_count);
				fprintf(codeLog, "Line No %d -> statements : statement\n", line_count);


				(yyval.symbolInfoVar) = (yyvsp[0].symbolInfoVar);
				(yyval.symbolInfoVar)->setType("statements");
				fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
				fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());

		   	}
#line 2532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 1110 "1505080.y" /* yacc.c:1646  */
    {	    //done
				fprintf(parseout, "statements : statements statement\n");
				fprintf(logout, "Line No %d -> statements : statements statement\n", line_count);
				fprintf(codeLog, "Line No %d -> statements : statements statement\n", line_count);

				char* str = new char[strlen((yyvsp[-1].symbolInfoVar)->getKey())+strlen((yyvsp[0].symbolInfoVar)->getKey())+200];
				sprintf(str, "%s%s", (yyvsp[-1].symbolInfoVar)->getKey(), (yyvsp[0].symbolInfoVar)->getKey());

				(yyval.symbolInfoVar) = new SymbolInfo(str, "statements");
				fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());


				char *tempCode = new char[strlen((yyvsp[-1].symbolInfoVar)->getCode()) + strlen((yyvsp[0].symbolInfoVar)->getCode()) + 200];
				sprintf(tempCode, "%s \n%s \n", (yyvsp[-1].symbolInfoVar)->getCode(), (yyvsp[0].symbolInfoVar)->getCode());

				(yyval.symbolInfoVar)->setCode(tempCode);         
				delete[] tempCode;


				fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());
										
				delete[] str;

		   	}
#line 2561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 1137 "1505080.y" /* yacc.c:1646  */
    {	    		//done
				fprintf(parseout, "statement : var_declaration\n");
				fprintf(logout, "Line No %d -> statement : var_declaration\n", line_count);
				fprintf(codeLog, "Line No %d -> statement : var_declaration\n", line_count);

				(yyval.symbolInfoVar) = (yyvsp[0].symbolInfoVar);
				(yyval.symbolInfoVar)->setType("statement");
				fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
				fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());

		  	}
#line 2577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 1149 "1505080.y" /* yacc.c:1646  */
    {	    //done
				fprintf(parseout, "statement : expression_statement\n");
				fprintf(logout, "Line No %d -> statement : expression_statement\n", line_count);
				fprintf(codeLog, "Line No %d -> statement : expression_statement\n", line_count);

				(yyval.symbolInfoVar) = (yyvsp[0].symbolInfoVar);
				(yyval.symbolInfoVar)->setType("statement");
				fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
				fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());

		  	}
#line 2593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 1161 "1505080.y" /* yacc.c:1646  */
    {	    //done
				fprintf(parseout, "statement : compound_statement\n");
				fprintf(logout, "Line No %d -> statement : compound_statement\n", line_count);
				fprintf(codeLog, "Line No %d -> statement : compound_statement\n", line_count);

				(yyval.symbolInfoVar) = (yyvsp[0].symbolInfoVar);
				(yyval.symbolInfoVar)->setType("statement");
				fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
				fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());

		  	}
#line 2609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 1173 "1505080.y" /* yacc.c:1646  */
    {	    //done
				fprintf(parseout, "statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n");
				fprintf(logout, "Line No %d -> statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n", line_count);
				fprintf(codeLog, "Line No %d -> statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n", line_count);

				if( strcmp((yyvsp[-3].symbolInfoVar)->getVarType(), "VOID")==0 ){
					fprintf(errorout, "Semantic Error : Line No %d -> Expression cannot be VOID\n", line_count);

					sem_error++;
				}

		  		char* str = new char[strlen((yyvsp[-4].symbolInfoVar)->getKey()) + strlen((yyvsp[-3].symbolInfoVar)->getKey()) + strlen((yyvsp[-2].symbolInfoVar)->getKey()) + strlen((yyvsp[0].symbolInfoVar)->getKey()) + 200];
				sprintf(str, "for(%s;%s;%s)%s", (yyvsp[-4].symbolInfoVar)->getKey(), (yyvsp[-3].symbolInfoVar)->getKey(), (yyvsp[-2].symbolInfoVar)->getKey(), (yyvsp[0].symbolInfoVar)->getKey());

				(yyval.symbolInfoVar) = new SymbolInfo(str, "statement");


				char *tempCode = new char[strlen((yyvsp[-4].symbolInfoVar)->getCode()) + strlen((yyvsp[-3].symbolInfoVar)->getCode()) + strlen((yyvsp[-2].symbolInfoVar)->getCode()) + strlen((yyvsp[0].symbolInfoVar)->getCode()) + 200];

				char *startLabel = newLabel();
				char *endLabel = newLabel();

				sprintf(tempCode, "%s \n%s: \n%s \nCMP %s, 0 \nJZ %s \n%s \n%s \nJMP %s \n%s: \n",
					(yyvsp[-4].symbolInfoVar)->getCode(), startLabel, (yyvsp[-3].symbolInfoVar)->getCode(), (yyvsp[-3].symbolInfoVar)->getTempVar(), endLabel, (yyvsp[0].symbolInfoVar)->getCode(), (yyvsp[-2].symbolInfoVar)->getCode(),startLabel, endLabel);

				(yyval.symbolInfoVar)->setCode(tempCode);
				delete[] tempCode;


				fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
				fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());

				delete[] str;

		  	}
#line 2649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 1209 "1505080.y" /* yacc.c:1646  */
    {	    //done
				fprintf(parseout, "statement : IF LPAREN expression RPAREN statement\n");
				fprintf(logout, "Line No %d -> statement : IF LPAREN expression RPAREN statement\n", line_count);
				fprintf(codeLog, "Line No %d -> statement : IF LPAREN expression RPAREN statement\n", line_count);

				if( strcmp((yyvsp[-2].symbolInfoVar)->getVarType(), "VOID")==0 ){
					fprintf(errorout, "Semantic Error : Line No %d -> Expression cannot be VOID\n", line_count);

					sem_error++;
				}

				char* str = new char[strlen((yyvsp[-2].symbolInfoVar)->getKey()) + strlen((yyvsp[0].symbolInfoVar)->getKey()) + 200];
				sprintf(str, "if(%s)%s", (yyvsp[-2].symbolInfoVar)->getKey(), (yyvsp[0].symbolInfoVar)->getKey());


				char *tempCode = new char[strlen((yyvsp[-2].symbolInfoVar)->getCode())+strlen((yyvsp[0].symbolInfoVar)->getCode())+200];
				char *endLabel = newLabel();

				sprintf(tempCode, "%s \nCMP %s, 0 \nJE %s \n%s \n%s: \n", 
				 		(yyvsp[-2].symbolInfoVar)->getCode(), (yyvsp[-2].symbolInfoVar)->getTempVar(), endLabel, (yyvsp[0].symbolInfoVar)->getCode(), endLabel);




				(yyval.symbolInfoVar) = new SymbolInfo(str, "statement");
				(yyval.symbolInfoVar)->setCode(tempCode);

				delete[] tempCode;

				fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
				fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());

				delete[] str;

		  	}
#line 2689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 1245 "1505080.y" /* yacc.c:1646  */
    {	    //done
				fprintf(parseout, "statement : IF LPAREN expression RPAREN statement ELSE statement\n");
				fprintf(logout, "Line No %d -> statement : IF LPAREN expression RPAREN statement ELSE statement\n", line_count);
				fprintf(codeLog, "Line No %d -> statement : IF LPAREN expression RPAREN statement ELSE statement\n", line_count);

				if( strcmp((yyvsp[-4].symbolInfoVar)->getVarType(), "VOID")==0 ){
					fprintf(errorout, "Semantic Error : Line No %d -> Expression cannot be VOID\n", line_count);

					sem_error++;
				}

				char* str = new char[strlen((yyvsp[-4].symbolInfoVar)->getKey()) + strlen((yyvsp[-2].symbolInfoVar)->getKey()) + strlen((yyvsp[0].symbolInfoVar)->getKey()) + 200];
				sprintf(str, "if(%s)%selse%s", (yyvsp[-4].symbolInfoVar)->getKey(), (yyvsp[-2].symbolInfoVar)->getKey(), (yyvsp[0].symbolInfoVar)->getKey());


				char *tempCode = new char[strlen((yyvsp[-4].symbolInfoVar)->getCode())+strlen((yyvsp[-2].symbolInfoVar)->getCode())+strlen((yyvsp[0].symbolInfoVar)->getCode())+200];
				char *elseLabel = newLabel();
				char *endLabel = newLabel();


				sprintf(tempCode, "%s \nCMP %s, 0 \nJE %s \n%s \n JMP %s \n%s: \n%s \n %s: \n", 
				 		(yyvsp[-4].symbolInfoVar)->getCode(), (yyvsp[-4].symbolInfoVar)->getTempVar(), elseLabel, (yyvsp[-2].symbolInfoVar)->getCode(), endLabel, elseLabel, (yyvsp[0].symbolInfoVar)->getCode(), endLabel);

				(yyval.symbolInfoVar) = new SymbolInfo(str, "statement");
				
				(yyval.symbolInfoVar)->setCode(tempCode);
				delete[] tempCode;

				fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
				fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());

				delete[] str;


		  	}
#line 2729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 1281 "1505080.y" /* yacc.c:1646  */
    {	    //done
				fprintf(parseout, "statement : WHILE LPAREN expression RPAREN statement\n");
				fprintf(logout, "Line No %d -> statement : WHILE LPAREN expression RPAREN statement\n", line_count);
				fprintf(codeLog, "Line No %d -> statement : WHILE LPAREN expression RPAREN statement\n", line_count);

				if( strcmp((yyvsp[-2].symbolInfoVar)->getVarType(), "VOID")==0 ){
					fprintf(errorout, "Semantic Error : Line No %d -> Expression cannot be VOID\n", line_count);

					sem_error++;
				}

				char* str = new char[strlen((yyvsp[-2].symbolInfoVar)->getKey()) + strlen((yyvsp[0].symbolInfoVar)->getKey()) + 200];
				sprintf(str, "while(%s)%s", (yyvsp[-2].symbolInfoVar)->getKey(), (yyvsp[0].symbolInfoVar)->getKey());

				(yyval.symbolInfoVar) = new SymbolInfo(str, "statement");


				char *tempCode = new char[strlen((yyvsp[-2].symbolInfoVar)->getCode()) + strlen((yyvsp[0].symbolInfoVar)->getCode()) + 200];

				char *startLabel = newLabel();
				char *endLabel = newLabel();

				sprintf(tempCode, "%s: \n%s \nCMP %s, 0 \nJZ %s \n%s \nJMP %s \n%s: \n",
					startLabel, (yyvsp[-2].symbolInfoVar)->getCode(), (yyvsp[-2].symbolInfoVar)->getTempVar(), endLabel, (yyvsp[0].symbolInfoVar)->getCode(), startLabel, endLabel);

				(yyval.symbolInfoVar)->setCode(tempCode);
				delete[] tempCode;


				fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
				fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());

				delete[] str;

		  	}
#line 2769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 1317 "1505080.y" /* yacc.c:1646  */
    {	    //done
				fprintf(parseout, "statement : PRINTLN LPAREN expression RPAREN SEMICOLON\n");
				fprintf(logout, "Line No %d -> statement : PRINTLN LPAREN expression RPAREN SEMICOLON\n", line_count);
				fprintf(codeLog, "Line No %d -> statement : PRINTLN LPAREN expression RPAREN SEMICOLON\n", line_count);

				char* str = new char[strlen((yyvsp[-2].symbolInfoVar)->getKey()) + 200];
				sprintf(str, "println(%s);\n", (yyvsp[-2].symbolInfoVar)->getKey());

				(yyval.symbolInfoVar) = new SymbolInfo(str, "statement");

				char *tempCode = new char[strlen((yyvsp[-2].symbolInfoVar)->getCode()) +200];
				sprintf(tempCode, "%s \nPUSH %s \ncall ASMOUT \n", 
					(yyvsp[-2].symbolInfoVar)->getCode(), (yyvsp[-2].symbolInfoVar)->getTempVar());

				(yyval.symbolInfoVar)->setCode(tempCode);
				(yyval.symbolInfoVar)->setTempVar((yyvsp[-2].symbolInfoVar)->getTempVar());

				delete[] tempCode; 



				fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
				fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());

				delete[] str;

		  	}
#line 2801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 1345 "1505080.y" /* yacc.c:1646  */
    {	    //done?
				fprintf(parseout, "statement : RETURN expression SEMICOLON\n");
				fprintf(logout, "Line No %d -> statement : RETURN expression SEMICOLON\n", line_count);
				fprintf(codeLog, "Line No %d -> statement : RETURN expression SEMICOLON\n", line_count);

				if( strcmp((yyvsp[-1].symbolInfoVar)->getVarType(), "VOID")==0 ){
					fprintf(errorout, "Semantic Error : Line No %d -> Expression cannot be VOID\n", line_count);

					sem_error++;
				}

				char* str = new char[strlen((yyvsp[-1].symbolInfoVar)->getKey()) + 200];
				sprintf(str, "return %s;\n", (yyvsp[-1].symbolInfoVar)->getKey());

				(yyval.symbolInfoVar) = (yyvsp[-1].symbolInfoVar);
				(yyval.symbolInfoVar)->setKey(str);
				(yyval.symbolInfoVar)->setType("statement");

				char *tempCode = new char[strlen((yyvsp[-1].symbolInfoVar)->getCode()) + 200];

				sprintf(tempCode, "%s \nMOV DX, %s \nRET \n", 
					(yyvsp[-1].symbolInfoVar)->getCode(), (yyvsp[-1].symbolInfoVar)->getTempVar());

				(yyval.symbolInfoVar)->setCode(tempCode);
				delete[] tempCode;

				fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
				fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());

				delete[] str;


		  	}
#line 2839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 1381 "1505080.y" /* yacc.c:1646  */
    {	     	//done	 	//ALL DONE	          
							fprintf(parseout, "expression_statement : SEMICOLON\n");
							fprintf(logout, "Line No %d -> expression_statement : SEMICOLON\n", line_count);
							fprintf(codeLog, "Line No %d -> expression_statement : SEMICOLON\n", line_count);

							(yyval.symbolInfoVar) = new SymbolInfo(";\n", "expression_statement");
							fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
							fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());


						}
#line 2855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 1393 "1505080.y" /* yacc.c:1646  */
    {	    //done
							fprintf(parseout, "expression_statement : expression SEMICOLON\n");
							fprintf(logout, "Line No %d -> expression_statement : expression SEMICOLON\n", line_count);
							fprintf(codeLog, "Line No %d -> expression_statement : expression SEMICOLON\n", line_count);

							char* str = new char[strlen((yyvsp[-1].symbolInfoVar)->getKey())+200];
							sprintf(str, "%s;\n", (yyvsp[-1].symbolInfoVar)->getKey());

							(yyval.symbolInfoVar) = (yyvsp[-1].symbolInfoVar);
							(yyval.symbolInfoVar)->setKey(str);
							(yyval.symbolInfoVar)->setType("expression_statement");
							fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
							fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());
										
							delete[] str;

						}
#line 2877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 1413 "1505080.y" /* yacc.c:1646  */
    {	     //done         ///ALL DONE
				fprintf(parseout, "variable : ID\n");
				fprintf(logout, "Line No %d -> variable : ID\n", line_count);
				fprintf(codeLog, "Line No %d -> variable : ID\n", line_count);


				SymbolInfo *temp = symbolTable->lookUp((yyvsp[0].symbolInfoVar)->getKey());

				if(temp==NULL){
					//symbolTable->printAllScopeTable(errorout);
					fprintf(errorout, "Semantic Error : Line No %d -> Identifier %s not declared in this scope\n", line_count, (yyvsp[0].symbolInfoVar)->getKey());
					sem_error++;

					(yyval.symbolInfoVar)=(yyvsp[0].symbolInfoVar);

				}
				else if(strcmp (temp->getIDType(),"VAR")!=0){
					fprintf(errorout, "Semantic Error : Line No %d -> Identifier %s not a variable\n", line_count, (yyvsp[0].symbolInfoVar)->getKey());
					sem_error++;

					(yyval.symbolInfoVar)=(yyvsp[0].symbolInfoVar);
				}
				else{
					(yyval.symbolInfoVar) = new SymbolInfo();
					temp->copyInfoTo((yyval.symbolInfoVar));

					char* varName  = new char[25];
					//sprintf(varName, "%s%d", temp->getKey(), symbolTable->lookUpNo(temp->getKey()));
					sprintf(varName, "%s%d", temp->getKey(), temp->getScopeNo());

					(yyval.symbolInfoVar)->setTempVar(varName);


					//fprintf(logout, "%s %s %s %s %d %d %d %f\n", temp->getKey(), temp->getType(), temp->getIDType(), temp->getVarType(), temp->getArrSize(), temp->getArrIdx(), temp->intVal, temp->floatVal);	
					//fprintf(logout, "%s %s %s %s %d %d %d %f\n", $$->getKey(), $$->getType(), $$->getIDType(), $$->getVarType(), $$->getArrSize(), $$->getArrIdx(), $$->intVal, $$->floatVal);	

				}

				(yyval.symbolInfoVar)->setType("variable");
				fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
				fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());
				
				//fprintf(logout, "%s %s %s %s %d %d %d %f\n", $$->getKey(), $$->getType(), $$->getIDType(), $$->getVarType(), $$->getArrSize(), $$->getArrIdx(), $$->intVal, $$->floatVal);	


			}
#line 2928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 1460 "1505080.y" /* yacc.c:1646  */
    {	    						//done
				fprintf(parseout, "variable : ID LTHIRD expression RTHIRD\n");
				fprintf(logout, "Line No %d -> variable : ID LTHIRD expression RTHIRD\n", line_count);
				fprintf(codeLog, "Line No %d -> variable : ID LTHIRD expression RTHIRD\n", line_count);

				if( strcmp( (yyvsp[-1].symbolInfoVar)->getVarType(),"INT")!=0 ){
					//symbolTable->printAllScopeTable(errorout);
					fprintf(errorout, "Semantic Error : Line No %d -> Array index must be integer\n", line_count);
					sem_error++;

				}	


				int arrIdx = (yyvsp[-1].symbolInfoVar)->intVal;

				SymbolInfo *temp = symbolTable->lookUp((yyvsp[-3].symbolInfoVar)->getKey());

				if(temp==NULL){
					//symbolTable->printAllScopeTable(errorout);
					fprintf(errorout, "Semantic Error : Line No %d -> Variable %s not declared in this scope\n", line_count, (yyvsp[-3].symbolInfoVar)->getKey());
					sem_error++;

					(yyval.symbolInfoVar)=(yyvsp[-3].symbolInfoVar);

				}
				else if(strcmp (temp->getIDType(),"ARR")!=0){
					fprintf(errorout, "Semantic Error : Line No %d -> Identifier %s not an array\n", line_count, (yyvsp[-3].symbolInfoVar)->getKey());
					sem_error++;

					(yyval.symbolInfoVar)=(yyvsp[-3].symbolInfoVar);
				}
				else if(temp->getArrSize() <= arrIdx){
					fprintf(errorout, "Warning : Line No %d -> array index out of bound\n", line_count);
					//sem_error++;

					(yyval.symbolInfoVar)=(yyvsp[-3].symbolInfoVar);
				}
				else{
					(yyval.symbolInfoVar) = new SymbolInfo();
					temp->copyInfoTo((yyval.symbolInfoVar));
					//fprintf(logout, "%s %s %s %s %d %d %d %f\n", temp->getKey(), temp->getType(), temp->getIDType(), temp->getVarType(), temp->getArrSize(), temp->getArrIdx(), temp->intVal, temp->floatVal);	
					//fprintf(logout, "%s %s %s %s %d %d %d %f\n", $$->getKey(), $$->getType(), $$->getIDType(), $$->getVarType(), $$->getArrSize(), $$->getArrIdx(), $$->intVal, $$->floatVal);	

					char* varName  = new char[25];
					//sprintf(varName, "%s%d", temp->getKey(), symbolTable->lookUpNo(temp->getKey()));
					sprintf(varName, "%s%d", temp->getKey(), temp->getScopeNo());

					(yyval.symbolInfoVar)->setTempVar(varName);

				}

				char* str = new char[200];
				sprintf(str, "%s[%s]", (yyval.symbolInfoVar)->getKey(), (yyvsp[-1].symbolInfoVar)->getKey());

				(yyval.symbolInfoVar)->setType("variable");
				(yyval.symbolInfoVar)->setArrIdx(arrIdx);
				(yyval.symbolInfoVar)->setKey(str);



				delete[] str;

				fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
				fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());

				//fprintf(logout, "%s %s %s %s %d %d %d %f\n", $$->getKey(), $$->getType(), $$->getIDType(), $$->getVarType(), $$->getArrSize(), $$->getArrIdx(), $$->intVal, $$->floatVal);	

			}
#line 3001 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 1531 "1505080.y" /* yacc.c:1646  */
    {	     	//done		         //ALL DONE 
				fprintf(parseout, "expression : logic_expression\n");
				fprintf(logout, "Line No %d -> expression : logic_expression\n", line_count);
				fprintf(codeLog, "Line No %d -> expression : logic_expression\n", line_count);

				(yyval.symbolInfoVar) = (yyvsp[0].symbolInfoVar);
				(yyval.symbolInfoVar)->setType("expression");
				fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
				fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());

	   		}
#line 3017 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 1543 "1505080.y" /* yacc.c:1646  */
    {	    //done
				fprintf(parseout, "expression : variable ASSIGNOP logic_expression\n");
				fprintf(logout, "Line No %d -> expression : variable ASSIGNOP logic_expression\n", line_count);
				fprintf(codeLog, "Line No %d -> expression : variable ASSIGNOP logic_expression\n", line_count);

				if( strcmp((yyvsp[-2].symbolInfoVar)->getVarType(), "VOID")==0 || strcmp((yyvsp[0].symbolInfoVar)->getVarType(), "VOID")==0 ){
					fprintf(errorout, "Semantic Error : Line No %d -> Expression cannot be VOID\n", line_count);

					sem_error++;
				}

				if(strcmp((yyvsp[-2].symbolInfoVar)->getVarType(), (yyvsp[0].symbolInfoVar)->getVarType())==0){
					(yyvsp[-2].symbolInfoVar)->intVal = (yyvsp[0].symbolInfoVar)->intVal;
					(yyvsp[-2].symbolInfoVar)->floatVal = (yyvsp[0].symbolInfoVar)->floatVal;
				}
				else if(strcmp((yyvsp[-2].symbolInfoVar)->getVarType(), "INT")==0){
					fprintf(errorout, "Warning : Line No %d -> FLOAT assigned to INT\n", line_count);
					(yyvsp[-2].symbolInfoVar)->intVal = (yyvsp[0].symbolInfoVar)->floatVal;
				}
				else{
					fprintf(errorout, "Warning : Line No %d -> INT assigned to FLOAT\n", line_count);
					(yyvsp[-2].symbolInfoVar)->floatVal = (yyvsp[0].symbolInfoVar)->intVal;
				}


				char *tempCode = new char[strlen((yyvsp[0].symbolInfoVar)->getCode()) + 200];
				//assigning value into symbolTable
				if(strcmp((yyvsp[-2].symbolInfoVar)->getIDType(),"VAR")==0 ){
					//fprintf(logout, "Here\n");

					SymbolInfo *temp = symbolTable->lookUp((yyvsp[-2].symbolInfoVar)->getKey());
					if(temp==NULL){
						//symbolTable->printAllScopeTable(errorout);
						fprintf(errorout, "Semantic Error : Line No %d -> Variable %s not declared in this scope\n", line_count, (yyvsp[-2].symbolInfoVar)->getKey());
						sem_error++;

						(yyval.symbolInfoVar)=(yyvsp[-2].symbolInfoVar);

					}
					else{
						temp->intVal = (yyvsp[-2].symbolInfoVar)->intVal;
						temp->floatVal = (yyvsp[-2].symbolInfoVar)->floatVal;

						
						sprintf(tempCode, "%s \nMOV AX, %s \nMOV %s, AX \n", 
								(yyvsp[0].symbolInfoVar)->getCode(),  (yyvsp[0].symbolInfoVar)->getTempVar(), (yyvsp[-2].symbolInfoVar)->getTempVar());
					}

					/*temp = symbolTable->lookUp($1->getKey());
					if (temp!=NULL){
						fprintf(logout, "Here3\n");
						fprintf(logout, "%s %s %s %s %d %d %d %f\n", temp->getKey(), temp->getType(), temp->getIDType(), temp->getVarType(), temp->getArrSize(), $$->getArrIdx(), temp->intVal, temp->floatVal);	
					}*/


				}
				else if(strcmp((yyvsp[-2].symbolInfoVar)->getIDType(),"ARR")==0 ){
					//dont know yet

					//fprintf(logout, "HERE2\n");

					char *newKey = new char[200];
					strcpy(newKey, (yyvsp[-2].symbolInfoVar)->getKey());

					for(int i = strlen(newKey)-1; i>=0; i--){
						if(newKey[i]=='['){
							newKey[i]=0;
							break;
						}
					}

					SymbolInfo *temp = symbolTable->lookUp(newKey);
					if(temp==NULL){
						//symbolTable->printAllScopeTable(errorout);
						fprintf(errorout, "Semantic Error : Line No %d -> Variable %s not declared in this scope\n", line_count, (yyvsp[-2].symbolInfoVar)->getKey());
						sem_error++;

						(yyval.symbolInfoVar)=(yyvsp[-2].symbolInfoVar);

					}
					else{
						temp->intVal = (yyvsp[-2].symbolInfoVar)->intVal;
						temp->floatVal = (yyvsp[-2].symbolInfoVar)->floatVal;

						temp->setArrIdx((yyvsp[-2].symbolInfoVar)->getArrIdx());

						if(strcmp(temp->getVarType(), "INT")==0){
							temp->setIntListVal((yyvsp[-2].symbolInfoVar)->getArrIdx(), (yyvsp[0].symbolInfoVar)->intVal);	
						}
						else if(strcmp(temp->getVarType(), "FLOAT")==0){
							temp->setFloatListVal((yyvsp[-2].symbolInfoVar)->getArrIdx(), (yyvsp[0].symbolInfoVar)->floatVal);	
						}

						sprintf(tempCode, "%s \nLEA SI, %s \nMOV BX, %d \nADD BX, %d \nMOV CX, %s \nMOV SI[BX], CX\n", 
											(yyvsp[0].symbolInfoVar)->getCode(), (yyvsp[-2].symbolInfoVar)->getTempVar(), (yyvsp[-2].symbolInfoVar)->getArrIdx(), (yyvsp[-2].symbolInfoVar)->getArrIdx(), (yyvsp[0].symbolInfoVar)->getTempVar());
						


					}

					/*temp = symbolTable->lookUp(newKey);
					
					if (temp!=NULL){
						fprintf(logout, "Here4\n");
						fprintf(logout, "%s %s %s %s %d %d %d %f\n", temp->getKey(), temp->getType(), temp->getIDType(), temp->getVarType(), temp->getArrSize(), $$->getArrIdx(), temp->intVal, temp->floatVal);	
					
						fprintf(logout, "%d\n", temp->getIntListVal($1->getArrIdx()) );	
						
					}*/

				}


				(yyval.symbolInfoVar) = (yyvsp[-2].symbolInfoVar);
				(yyval.symbolInfoVar)->setType("expression");
				(yyval.symbolInfoVar)->intVal = (yyvsp[-2].symbolInfoVar)->intVal;
				(yyval.symbolInfoVar)->floatVal = (yyvsp[-2].symbolInfoVar)->floatVal;

				char *str = new char[strlen((yyvsp[-2].symbolInfoVar)->getKey()) + strlen((yyvsp[0].symbolInfoVar)->getKey()) + 50];
				sprintf(str, "%s=%s", (yyvsp[-2].symbolInfoVar)->getKey(), (yyvsp[0].symbolInfoVar)->getKey());

				(yyval.symbolInfoVar)->setKey(str);
				(yyval.symbolInfoVar)->setCode(tempCode);         
				delete[] tempCode;

				delete[] str;

				fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
				fprintf(logout, "Assigned values : %s %d %f\n\n", (yyval.symbolInfoVar)->getVarType(), (yyval.symbolInfoVar)->intVal, (yyval.symbolInfoVar)->floatVal);
				fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());
			

	   		}
#line 3155 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 1679 "1505080.y" /* yacc.c:1646  */
    {	     	//done		          
						fprintf(parseout, "logic_expression : rel_expression\n");
						fprintf(logout, "Line No %d -> logic_expression : rel_expression\n", line_count);
						fprintf(codeLog, "Line No %d -> logic_expression : rel_expression\n", line_count);

						(yyval.symbolInfoVar) = (yyvsp[0].symbolInfoVar);
						(yyval.symbolInfoVar)->setType("logic_expression");
						fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
						fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());

					}
#line 3171 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 1691 "1505080.y" /* yacc.c:1646  */
    {	    //done
						fprintf(parseout, "logic_expression : rel_expression LOGICOP rel_expression\n");
						fprintf(logout, "Line No %d -> logic_expression : rel_expression LOGICOP rel_expression\n", line_count);
						fprintf(codeLog, "Line No %d -> logic_expression : rel_expression LOGICOP rel_expression\n", line_count);

						if( strcmp((yyvsp[-2].symbolInfoVar)->getVarType(), "VOID")==0 || strcmp((yyvsp[0].symbolInfoVar)->getVarType(), "VOID")==0 ){
							fprintf(errorout, "Semantic Error : Line No %d -> Expression cannot be VOID\n", line_count);

							sem_error++;
						}

						float val1, val2;			
						if(strcmp((yyvsp[-2].symbolInfoVar)->getVarType(), "FLOAT")==0 ){
							val1 = (yyvsp[-2].symbolInfoVar)->floatVal;
						}
						else{
							val1 = (yyvsp[-2].symbolInfoVar)->intVal;
						}

						if(strcmp((yyvsp[0].symbolInfoVar)->getVarType(), "FLOAT")==0 ){
							val2 = (yyvsp[0].symbolInfoVar)->floatVal;
						}
						else{
							val2 = (yyvsp[0].symbolInfoVar)->intVal;	
						}


						char* str = new char[strlen((yyvsp[-2].symbolInfoVar)->getKey())+strlen((yyvsp[0].symbolInfoVar)->getKey())+200];
						(yyval.symbolInfoVar) = new SymbolInfo();

						char *tempCode = new char[strlen((yyvsp[-2].symbolInfoVar)->getCode())+strlen((yyvsp[0].symbolInfoVar)->getCode())+200];
						char *tempVar = newTempVar();

						char *zeroLabel = newLabel();
						char *oneLabel = newLabel();
						char *endLabel = newLabel();
						
						if(strcmp((yyvsp[-1].symbolInfoVar)->getKey(), "&&")==0){
							sprintf(str, "%s&&%s", (yyvsp[-2].symbolInfoVar)->getKey(), (yyvsp[0].symbolInfoVar)->getKey() );
							if(val1 && val2){(yyval.symbolInfoVar)->intVal = 1;}
							else{(yyval.symbolInfoVar)->intVal = 0;}

							sprintf(tempCode, "%s \n%s \nMOV AX, %s \nCMP AX, 0 \n JE %s \nMOV AX, %s \nCMP AX, 0 \n JE %s \nMOV AX, 1 \nJMP %s \n%s: \nMOV AX, 0 \n%s: \nMOV %s, AX \n",
								(yyvsp[-2].symbolInfoVar)->getCode(), (yyvsp[0].symbolInfoVar)->getCode(), (yyvsp[-2].symbolInfoVar)->getTempVar(), zeroLabel, (yyvsp[0].symbolInfoVar)->getTempVar(), zeroLabel, endLabel, zeroLabel, endLabel, tempVar);

						}
						else if(strcmp((yyvsp[-1].symbolInfoVar)->getKey(), "||")==0){
							sprintf(str, "%s||%s", (yyvsp[-2].symbolInfoVar)->getKey(), (yyvsp[0].symbolInfoVar)->getKey() );
							if(val1 || val2){(yyval.symbolInfoVar)->intVal = 1;}
							else{(yyval.symbolInfoVar)->intVal = 0;}

							sprintf(tempCode, "%s \n%s \nMOV AX, %s \nCMP AX, 0 \n JNE %s \nMOV AX, %s \nCMP AX, 0 \n JNE %s \nMOV AX, 0 \nJMP %s \n%s: \nMOV AX, 1 \n%s: \nMOV %s, AX \n",
								(yyvsp[-2].symbolInfoVar)->getCode(), (yyvsp[0].symbolInfoVar)->getCode(), (yyvsp[-2].symbolInfoVar)->getTempVar(), oneLabel, (yyvsp[0].symbolInfoVar)->getTempVar(), oneLabel, endLabel, oneLabel, endLabel, tempVar);

						}

						(yyval.symbolInfoVar)->setKey(str);
						(yyval.symbolInfoVar)->setType("logic_expression");
						(yyval.symbolInfoVar)->setVarType("INT");

						(yyval.symbolInfoVar)->setCode(tempCode);

						(yyval.symbolInfoVar)->setTempVar(tempVar);

						fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
						fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());
									
						//symbolTable->printAllScopeTable(logout);

						delete[] str;

						delete[] tempCode;


					}
#line 3251 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 1769 "1505080.y" /* yacc.c:1646  */
    {	     	//done		          //ALL DONE
					fprintf(parseout, "rel_expression : simple_expression\n");
					fprintf(logout, "Line No %d -> rel_expression : simple_expression\n", line_count);
					fprintf(codeLog, "Line No %d -> rel_expression : simple_expression\n", line_count);

					(yyval.symbolInfoVar) = (yyvsp[0].symbolInfoVar);
					(yyval.symbolInfoVar)->setType("rel_expression");
					fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
				fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());

				}
#line 3267 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 1781 "1505080.y" /* yacc.c:1646  */
    {	    //done 
					fprintf(parseout, "rel_expression : simple_expression RELOP simple_expression\n");
					fprintf(logout, "Line No %d -> rel_expression : simple_expression RELOP simple_expression\n", line_count);
					fprintf(codeLog, "Line No %d -> rel_expression : simple_expression RELOP simple_expression\n", line_count);
					
					if( strcmp((yyvsp[-2].symbolInfoVar)->getVarType(), "VOID")==0 || strcmp((yyvsp[0].symbolInfoVar)->getVarType(), "VOID")==0 ){
						fprintf(errorout, "Semantic Error : Line No %d -> Expression cannot be VOID\n", line_count);

						sem_error++;
					}

					float val1, val2;			
					if(strcmp((yyvsp[-2].symbolInfoVar)->getVarType(), "FLOAT")==0 ){
						val1 = (yyvsp[-2].symbolInfoVar)->floatVal;
					}
					else{
						val1 = (yyvsp[-2].symbolInfoVar)->intVal;
					}

					if(strcmp((yyvsp[0].symbolInfoVar)->getVarType(), "FLOAT")==0 ){
						val2 = (yyvsp[0].symbolInfoVar)->floatVal;
					}
					else{
						val2 = (yyvsp[0].symbolInfoVar)->intVal;	
					}


					char* str = new char[strlen((yyvsp[-2].symbolInfoVar)->getKey())+strlen((yyvsp[0].symbolInfoVar)->getKey())+200];
					(yyval.symbolInfoVar) = new SymbolInfo();

					
					char* condition = new char[10];
					
					if(strcmp((yyvsp[-1].symbolInfoVar)->getKey(), "<=")==0){
						sprintf(str, "%s<=%s", (yyvsp[-2].symbolInfoVar)->getKey(), (yyvsp[0].symbolInfoVar)->getKey() );
						if(val1 <= val2){(yyval.symbolInfoVar)->intVal = 1;}
						else{(yyval.symbolInfoVar)->intVal = 0;}

						sprintf(condition, "JLE");

					}
					else if(strcmp((yyvsp[-1].symbolInfoVar)->getKey(), "<")==0){
						sprintf(str, "%s<%s", (yyvsp[-2].symbolInfoVar)->getKey(), (yyvsp[0].symbolInfoVar)->getKey() );
						if(val1 < val2){(yyval.symbolInfoVar)->intVal = 1;}
						else{(yyval.symbolInfoVar)->intVal = 0;}
						sprintf(condition, "JL");
					}
					else if(strcmp((yyvsp[-1].symbolInfoVar)->getKey(), ">=")==0){
						sprintf(str, "%s>=%s", (yyvsp[-2].symbolInfoVar)->getKey(), (yyvsp[0].symbolInfoVar)->getKey() );
						if(val1 >= val2){(yyval.symbolInfoVar)->intVal = 1;}
						else{(yyval.symbolInfoVar)->intVal = 0;}
						sprintf(condition, "JGE");
					}
					else if(strcmp((yyvsp[-1].symbolInfoVar)->getKey(), ">")==0){
						sprintf(str, "%s>%s", (yyvsp[-2].symbolInfoVar)->getKey(), (yyvsp[0].symbolInfoVar)->getKey() );
						if(val1 > val2){(yyval.symbolInfoVar)->intVal = 1;}
						else{(yyval.symbolInfoVar)->intVal = 0;}
						sprintf(condition, "JG");
					}
					else if(strcmp((yyvsp[-1].symbolInfoVar)->getKey(), "==")==0){
						sprintf(str, "%s==%s", (yyvsp[-2].symbolInfoVar)->getKey(), (yyvsp[0].symbolInfoVar)->getKey() );
						if(val1 == val2){(yyval.symbolInfoVar)->intVal = 1;}
						else{(yyval.symbolInfoVar)->intVal = 0;}
						sprintf(condition, "JE");
					}
					else if(strcmp((yyvsp[-1].symbolInfoVar)->getKey(), "!=")==0){
						sprintf(str, "%s!=%s", (yyvsp[-2].symbolInfoVar)->getKey(), (yyvsp[0].symbolInfoVar)->getKey() );
						if(val1 != val2){(yyval.symbolInfoVar)->intVal = 1;}
						else{(yyval.symbolInfoVar)->intVal = 0;}
						sprintf(condition, "JNE");
					}

					char *tempCode = new char[strlen((yyvsp[-2].symbolInfoVar)->getCode())+strlen((yyvsp[0].symbolInfoVar)->getCode())+200];
					char *tempVar = newTempVar();
					char *ifLabel = newLabel(); 
					char *endLabel = newLabel();

					sprintf(tempCode, "%s \n%s \nMOV AX, %s \nCMP AX, %s \n%s %s \nMOV AX, 0 \nJMP %s\n%s: \nMOV AX, 1 \n%s: \nMOV %s, AX \n", 
							(yyvsp[-2].symbolInfoVar)->getCode(), (yyvsp[0].symbolInfoVar)->getCode(), (yyvsp[-2].symbolInfoVar)->getTempVar(), (yyvsp[0].symbolInfoVar)->getTempVar(), condition, ifLabel, endLabel, ifLabel, endLabel, tempVar);

					(yyval.symbolInfoVar)->setKey(str);
					(yyval.symbolInfoVar)->setType("rel_expression");
					(yyval.symbolInfoVar)->setVarType("INT");

					(yyval.symbolInfoVar)->setCode(tempCode);
					(yyval.symbolInfoVar)->setTempVar(tempVar);

					delete[] tempCode;

					fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
				fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());
								
					//symbolTable->printAllScopeTable(logout);

					delete[] str;
						

				}
#line 3370 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 1882 "1505080.y" /* yacc.c:1646  */
    {	     //done				//ALL DONE          
						fprintf(parseout, "simple_expression : term\n");
						fprintf(logout, "Line No %d -> simple_expression : term\n", line_count);
						fprintf(codeLog, "Line No %d -> simple_expression : term\n", line_count);

						(yyval.symbolInfoVar) = (yyvsp[0].symbolInfoVar);
						(yyval.symbolInfoVar)->setType("simple_expression");
						
						fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
						fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());

		  			}
#line 3387 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 1895 "1505080.y" /* yacc.c:1646  */
    {	    //done
						fprintf(parseout, "simple_expression : simple_expression ADDOP term\n");
						fprintf(logout, "Line No %d -> simple_expression : simple_expression ADDOP term\n", line_count);
						fprintf(codeLog, "Line No %d -> simple_expression : simple_expression ADDOP term\n", line_count);

						if( strcmp((yyvsp[-2].symbolInfoVar)->getVarType(), "VOID")==0 || strcmp((yyvsp[0].symbolInfoVar)->getVarType(), "VOID")==0 ){
							fprintf(errorout, "Semantic Error : Line No %d -> Expression cannot be VOID\n", line_count);

							sem_error++;
						}
									
						if(strcmp((yyvsp[-2].symbolInfoVar)->getVarType(), "FLOAT")==0 || strcmp((yyvsp[0].symbolInfoVar)->getVarType(), "FLOAT")==0 ){
							if( strcmp((yyvsp[-2].symbolInfoVar)->getVarType(), "INT")==0 ){
								//fprintf(logout, "HERE1\n");
								(yyvsp[-2].symbolInfoVar)->setFloatVal((yyvsp[-2].symbolInfoVar)->intVal);
								(yyvsp[-2].symbolInfoVar)->setVarType("FLOAT");
							} 

							if( strcmp((yyvsp[0].symbolInfoVar)->getVarType(), "INT")==0 ){
								//fprintf(logout, "HERE3\n");
								(yyvsp[0].symbolInfoVar)->setFloatVal((yyvsp[0].symbolInfoVar)->intVal);
								(yyvsp[0].symbolInfoVar)->setVarType("FLOAT");

							} 							

						}
						
						char *str = new char[strlen((yyvsp[-2].symbolInfoVar)->getKey()) + strlen((yyvsp[0].symbolInfoVar)->getKey()) + 50];
						(yyval.symbolInfoVar) = (yyvsp[-2].symbolInfoVar);
						
						char *tempCode = new char[strlen((yyvsp[-2].symbolInfoVar)->getCode()) + strlen((yyvsp[0].symbolInfoVar)->getCode()) + 200];
						char *tempVar = newTempVar();
						

						if(strcmp((yyvsp[-1].symbolInfoVar)->getKey(),"+")==0){
							//fprintf(logout, "PLUS\n");
							sprintf(str, "%s+%s", (yyvsp[-2].symbolInfoVar)->getKey(), (yyvsp[0].symbolInfoVar)->getKey());
							(yyval.symbolInfoVar)->intVal = (yyvsp[-2].symbolInfoVar)->intVal + (yyvsp[0].symbolInfoVar)->intVal;
							(yyval.symbolInfoVar)->floatVal = (yyvsp[-2].symbolInfoVar)->floatVal + (yyvsp[0].symbolInfoVar)->floatVal;

							sprintf(tempCode, "%s \n%s \nMOV BX, %s \nADD BX, %s \nMOV %s, BX \n",
								(yyvsp[-2].symbolInfoVar)->getCode(), (yyvsp[0].symbolInfoVar)->getCode(), (yyvsp[-2].symbolInfoVar)->getTempVar(), (yyvsp[0].symbolInfoVar)->getTempVar(), tempVar);

							//printf("%s\n", tempCode);


						}
						else{
							//fprintf(logout, "MINUS\n");
							sprintf(str, "%s-%s", (yyvsp[-2].symbolInfoVar)->getKey(), (yyvsp[0].symbolInfoVar)->getKey());
							(yyval.symbolInfoVar)->intVal = (yyvsp[-2].symbolInfoVar)->intVal - (yyvsp[0].symbolInfoVar)->intVal;
							(yyval.symbolInfoVar)->floatVal = (yyvsp[-2].symbolInfoVar)->floatVal - (yyvsp[0].symbolInfoVar)->floatVal;

							sprintf(tempCode, "%s \n%s \nMOV BX, %s \nSUB BX, %s \nMOV %s, BX \n",
								(yyvsp[-2].symbolInfoVar)->getCode(), (yyvsp[0].symbolInfoVar)->getCode(), (yyvsp[-2].symbolInfoVar)->getTempVar(), (yyvsp[0].symbolInfoVar)->getTempVar(), tempVar);
						}
						
						

						(yyval.symbolInfoVar)->setKey(str);

						(yyval.symbolInfoVar)->setCode(tempCode);
						(yyval.symbolInfoVar)->setTempVar(tempVar);

						delete[] tempCode;

						fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
						fprintf(logout, "Calculated values: %s %d %f\n\n", (yyval.symbolInfoVar)->getVarType(), (yyval.symbolInfoVar)->intVal, (yyval.symbolInfoVar)->floatVal);
						fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());


		  			}
#line 3464 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 1970 "1505080.y" /* yacc.c:1646  */
    {	    //done 				       //ALL DONE   
			fprintf(parseout, "term : unary_expression\n");
			fprintf(logout, "Line No %d -> term : unary_expression\n", line_count);
			fprintf(codeLog, "Line No %d -> term : unary_expression\n", line_count);

			(yyval.symbolInfoVar) = (yyvsp[0].symbolInfoVar);
			(yyval.symbolInfoVar)->setType("term");
			fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
				fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());

     	}
#line 3480 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 1982 "1505080.y" /* yacc.c:1646  */
    {	    //done
			fprintf(parseout, "term : term MULOP unary_expression\n");
			fprintf(logout, "Line No %d -> term : term MULOP unary_expression\n", line_count);
			fprintf(codeLog, "Line No %d -> term : term MULOP unary_expression\n", line_count);

			if( strcmp((yyvsp[-2].symbolInfoVar)->getVarType(), "VOID")==0 || strcmp((yyvsp[0].symbolInfoVar)->getVarType(), "VOID")==0 ){
				fprintf(errorout, "Semantic Error : Line No %d -> Expression cannot be VOID\n", line_count);

				sem_error++;
			}


			if( strcmp((yyvsp[-2].symbolInfoVar)->getVarType(), "FLOAT")==0 || strcmp((yyvsp[0].symbolInfoVar)->getVarType(), "FLOAT")==0 ){
				if( strcmp((yyvsp[-2].symbolInfoVar)->getVarType(), "INT")==0 ){
					//fprintf(logout, "HERE1\n");
					(yyvsp[-2].symbolInfoVar)->setFloatVal((yyvsp[-2].symbolInfoVar)->intVal);
					(yyvsp[-2].symbolInfoVar)->setVarType("FLOAT");
				} 

				if( strcmp((yyvsp[0].symbolInfoVar)->getVarType(), "INT")==0 ){
					//fprintf(logout, "HERE3\n");
					(yyvsp[0].symbolInfoVar)->setFloatVal((yyvsp[0].symbolInfoVar)->intVal);
					(yyvsp[0].symbolInfoVar)->setVarType("FLOAT");

				} 							

			}
						
			char *str = new char[strlen((yyvsp[-2].symbolInfoVar)->getKey()) + strlen((yyvsp[0].symbolInfoVar)->getKey()) + 50];
			(yyval.symbolInfoVar) = (yyvsp[-2].symbolInfoVar);

			char *tempCode = new char[strlen((yyvsp[-2].symbolInfoVar)->getCode()) + strlen((yyvsp[0].symbolInfoVar)->getCode()) + 100];
			char *tempVar = newTempVar();

			if(strcmp((yyvsp[-1].symbolInfoVar)->getKey(),"*")==0){	//done
				
				sprintf(str, "%s*%s", (yyvsp[-2].symbolInfoVar)->getKey(), (yyvsp[0].symbolInfoVar)->getKey());
				(yyval.symbolInfoVar)->intVal = (yyvsp[-2].symbolInfoVar)->intVal * (yyvsp[0].symbolInfoVar)->intVal;
				(yyval.symbolInfoVar)->floatVal = (yyvsp[-2].symbolInfoVar)->floatVal * (yyvsp[0].symbolInfoVar)->floatVal;

				sprintf(tempCode, "%s \n%s \nMOV AX, %s \nMUL %s\nMOV %s, AX \n",
					(yyvsp[-2].symbolInfoVar)->getCode(), (yyvsp[0].symbolInfoVar)->getCode(), (yyvsp[-2].symbolInfoVar)->getTempVar(), (yyvsp[0].symbolInfoVar)->getTempVar(), tempVar);

			}
			else if(strcmp((yyvsp[-1].symbolInfoVar)->getKey(),"/")==0){	//done
				
				sprintf(str, "%s/%s", (yyvsp[-2].symbolInfoVar)->getKey(), (yyvsp[0].symbolInfoVar)->getKey());
				if((yyvsp[0].symbolInfoVar)->intVal)
					(yyval.symbolInfoVar)->intVal = (yyvsp[-2].symbolInfoVar)->intVal / (yyvsp[0].symbolInfoVar)->intVal;
				if((yyvsp[0].symbolInfoVar)->floatVal)
					(yyval.symbolInfoVar)->floatVal = (yyvsp[-2].symbolInfoVar)->floatVal / (yyvsp[0].symbolInfoVar)->floatVal;

				sprintf(tempCode, "%s \n%s \nMOV AX, %s \nMOV BX, %s \nDIV BL\nXOR AH, AH \nMOV %s, AX \n",
					(yyvsp[-2].symbolInfoVar)->getCode(), (yyvsp[0].symbolInfoVar)->getCode(), (yyvsp[-2].symbolInfoVar)->getTempVar(), (yyvsp[0].symbolInfoVar)->getTempVar(), tempVar);

			}
			else{	//done
				
				sprintf(str, "%s\%%%s", (yyvsp[-2].symbolInfoVar)->getKey(), (yyvsp[0].symbolInfoVar)->getKey());
				if((yyvsp[0].symbolInfoVar)->intVal)
					(yyval.symbolInfoVar)->intVal = (yyvsp[-2].symbolInfoVar)->intVal % (yyvsp[0].symbolInfoVar)->intVal;
				//$$->floatVal = $1->floatVal - $3->floatVal;
				
				if( strcmp((yyval.symbolInfoVar)->getVarType(), "FLOAT")==0){
					fprintf(errorout, "Semantic Error : Line No %d -> FLOAT MODULUS NOT COMPATIBLE\n", line_count);
					sem_error++;
				}

				sprintf(tempCode, "%s \n%s \nMOV AX, %s \nMOV BX, %s \nDIV BL\nMOV AL, AH \nXOR AH, AH \nMOV %s, AX \n",
					(yyvsp[-2].symbolInfoVar)->getCode(), (yyvsp[0].symbolInfoVar)->getCode(), (yyvsp[-2].symbolInfoVar)->getTempVar(), (yyvsp[0].symbolInfoVar)->getTempVar(), tempVar);

			}
				
			
			(yyval.symbolInfoVar)->setKey(str);

			(yyval.symbolInfoVar)->setCode(tempCode);
			(yyval.symbolInfoVar)->setTempVar(tempVar);

			delete[] tempCode;

			fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
			fprintf(logout, "Calculated values: %s %d %f\n\n", (yyval.symbolInfoVar)->getVarType(), (yyval.symbolInfoVar)->intVal, (yyval.symbolInfoVar)->floatVal);
				fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());



     	}
#line 3573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 2073 "1505080.y" /* yacc.c:1646  */
    {	     //done 		//ALL DONE          
						fprintf(parseout, "unary_expression : ADDOP unary_expression\n");
						fprintf(logout, "Line No %d -> unary_expression : ADDOP unary_expression\n", line_count);
						fprintf(codeLog, "Line No %d -> unary_expression : ADDOP unary_expression\n", line_count);

						if( strcmp((yyvsp[0].symbolInfoVar)->getVarType(), "VOID")==0){
							fprintf(errorout, "Semantic Error : Line No %d -> Expression cannot be VOID\n", line_count);

							sem_error++;
						}
						
						(yyval.symbolInfoVar) = (yyvsp[0].symbolInfoVar);
						char* str = new char[strlen((yyvsp[0].symbolInfoVar)->getKey())+ 200];

						if( strcmp ((yyvsp[-1].symbolInfoVar)->getKey(), "+")==0 ){
							sprintf(str, "+%s", (yyvsp[0].symbolInfoVar)->getKey());
						}
						else{
							sprintf(str, "-%s", (yyvsp[0].symbolInfoVar)->getKey());
							
							(yyval.symbolInfoVar)->intVal = -((yyval.symbolInfoVar)->intVal);
							(yyval.symbolInfoVar)->floatVal = -((yyval.symbolInfoVar)->floatVal);

							char *tempCode = new char[strlen((yyvsp[0].symbolInfoVar)->getCode())+200];
							char *tempVar = newTempVar();

							sprintf(tempCode, "%s \nMOV AX, %s \nNEG AX \nMOV %s, AX \n", 
											(yyvsp[0].symbolInfoVar)->getCode(), (yyvsp[0].symbolInfoVar)->getTempVar(), tempVar);
							(yyval.symbolInfoVar)->setCode(tempCode);         

							delete[] tempCode;
							(yyval.symbolInfoVar)->setTempVar(tempVar);
						}
						
						(yyval.symbolInfoVar)->setKey(str);
						(yyval.symbolInfoVar)->setType("unary_expression");


						fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
						fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());

						delete[] str;


					}
#line 3623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 2119 "1505080.y" /* yacc.c:1646  */
    {	    //done
						fprintf(parseout, "unary_expression : NOT unary_expression\n");
						fprintf(logout, "Line No %d -> unary_expression : NOT unary_expression\n", line_count);
						fprintf(codeLog, "Line No %d -> unary_expression : NOT unary_expression\n", line_count);

						if( strcmp((yyvsp[0].symbolInfoVar)->getVarType(), "VOID")==0 ){
							fprintf(errorout, "Semantic Error : Line No %d -> Expression cannot be VOID\n", line_count);

							sem_error++;
						}

						(yyval.symbolInfoVar) = (yyvsp[0].symbolInfoVar);
						char* str = new char[strlen((yyvsp[0].symbolInfoVar)->getKey())+ 200];

						sprintf(str, "!%s", (yyvsp[0].symbolInfoVar)->getKey());
						
						(yyval.symbolInfoVar)->setKey(str);
						(yyval.symbolInfoVar)->setType("unary_expression");

						char *tempCode = new char[strlen((yyvsp[0].symbolInfoVar)->getCode())+200];

						char *elseLabel = newLabel();
						char *endLabel = newLabel();

						char *tempVar = newTempVar();

						sprintf(tempCode, "%s\nCMP %s, 0 \nJNZ %s \nMOV %s, 1 \nJMP %s \n%s: \nMOV %s, 0 \n%s: \n", 
									(yyvsp[0].symbolInfoVar)->getCode(), (yyvsp[0].symbolInfoVar)->getTempVar(), elseLabel, tempVar , endLabel, elseLabel, tempVar, endLabel);

						(yyval.symbolInfoVar)->setCode(tempCode);         
						delete[] tempCode;
						(yyval.symbolInfoVar)->setTempVar(tempVar);

						if((yyval.symbolInfoVar)->intVal==0){
							(yyval.symbolInfoVar)->intVal=1;
						}
						else{
							(yyval.symbolInfoVar)->intVal = 0;
						}

						if((yyval.symbolInfoVar)->floatVal==0){
							(yyval.symbolInfoVar)->floatVal=1;
						}
						else{
							(yyval.symbolInfoVar)->floatVal = 0;
						}
						
						fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
				fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());

						delete[] str;

				 	}
#line 3681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 2173 "1505080.y" /* yacc.c:1646  */
    {	    //done
						fprintf(parseout, "unary_expression : factor\n");
						fprintf(logout, "Line No %d -> unary_expression : factor\n", line_count);
						fprintf(codeLog, "Line No %d -> unary_expression : factor\n", line_count);

						(yyval.symbolInfoVar) = (yyvsp[0].symbolInfoVar);
						(yyval.symbolInfoVar)->setType("unary_expression");
						fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
				fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());


					}
#line 3698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 2188 "1505080.y" /* yacc.c:1646  */
    {	 //done  		//ALL DONE
			fprintf(parseout, "factor : variable\n");
			fprintf(logout, "Line No %d -> factor : variable\n", line_count);
			fprintf(codeLog, "Line No %d -> factor : variable\n", line_count);

			(yyval.symbolInfoVar) = (yyvsp[0].symbolInfoVar);
			(yyval.symbolInfoVar)->setType("variable");

			char *tempCode = new char[200];
			char *tempVar = newTempVar();

			if(strcmp((yyvsp[0].symbolInfoVar)->getIDType(),"VAR")==0 ){
				sprintf(tempCode, "MOV AX, %s \nMOV %s, AX \n", (yyvsp[0].symbolInfoVar)->getTempVar(), tempVar);
			}
			else{
				sprintf(tempCode, "LEA SI, %s \nMOV BX, %d \nADD BX, %d \nMOV CX, SI[BX] \nMOV %s, CX\n", 
										(yyvsp[0].symbolInfoVar)->getTempVar(), (yyvsp[0].symbolInfoVar)->getArrIdx(), (yyvsp[0].symbolInfoVar)->getArrIdx(), tempVar);
			}

			(yyval.symbolInfoVar)->setCode(tempCode);         
			(yyval.symbolInfoVar)->setTempVar(tempVar);
			delete[] tempCode;
			

			fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
			fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());





		}
#line 3735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 2221 "1505080.y" /* yacc.c:1646  */
    {	//function call 			//DONE
			fprintf(parseout, "factor : ID LPAREN argument_list RPAREN\n");
			fprintf(logout, "Line No %d -> factor : ID LPAREN argument_list RPAREN\n", line_count);
			fprintf(codeLog, "Line No %d -> factor : ID LPAREN argument_list RPAREN\n", line_count);


			char* str = new char[strlen((yyvsp[-3].symbolInfoVar)->getKey())+strlen((yyvsp[-1].symbolInfoVar)->getKey())+ 200];
			sprintf(str, "%s(%s)", (yyvsp[-3].symbolInfoVar)->getKey(), (yyvsp[-1].symbolInfoVar)->getKey());

			

				SymbolInfo *temp = symbolTable->lookUp((yyvsp[-3].symbolInfoVar)->getKey());

				char *tempCode = new char[strlen((yyvsp[-1].symbolInfoVar)->getCode()) + 200];
				tempCode[0]=0;
				char *tempVar = newTempVar();


				if(temp==NULL){
					//symbolTable->printAllScopeTable(errorout);
					fprintf(errorout, "Semantic Error : Line No %d -> Function %s() not declared in this scope\n", line_count, (yyvsp[-3].symbolInfoVar)->getKey());
					sem_error++;

					(yyval.symbolInfoVar)=(yyvsp[-3].symbolInfoVar);

				}
				else if(strcmp (temp->getIDType(),"FUNC")!=0){
					fprintf(errorout, "Semantic Error : Line No %d -> Identifier %s not a function\n", line_count, (yyvsp[-3].symbolInfoVar)->getKey());
					sem_error++;

					(yyval.symbolInfoVar)=(yyvsp[-3].symbolInfoVar);
				}
				// else if(!temp->getFuncIsDefined()){
				// 	fprintf(errorout, "Semantic Error : Line No %d -> Function %s() is not defined\n", line_count, $1->getKey());
				// 	sem_error++;

				// 	$$=$1;
				// }
				else if(temp->getParamNo() != argNo){
					fprintf(errorout, "Semantic Error : Line No %d -> Function %s() parameter number and argument number mismatch\n", line_count, (yyvsp[-3].symbolInfoVar)->getKey());
					sem_error++;

					(yyval.symbolInfoVar)=(yyvsp[-3].symbolInfoVar);
				}
				else if(temp->getParamNo() != argNo){
					fprintf(errorout, "Semantic Error : Line No %d -> Function %s() parameter number and argument number mismatch\n", line_count, (yyvsp[-3].symbolInfoVar)->getKey());
					sem_error++;

					(yyval.symbolInfoVar)=(yyvsp[-3].symbolInfoVar);
				}
				else{
					// SymbolInfo* sInfo = temp;
					// if(sInfo!=NULL && sInfo->paramList!=NULL && argNo>0){	//parameter type mismatch check
					// 	for(int i=0; i<argNo; i++){
					// 		SymbolInfo *t = sInfo->paramList[i];
					// 		SymbolInfo *t2 = argList[i];
					// 		if(t==NULL || t2==NULL){
					// 			fprintf(errorout, "Warning : Line No %d -> Function %s() parameter and argument type mismatch\n", line_count, sInfo->getKey());
								
					// 		}
					// 		else if(strcmp(t->getVarType(), t2->getVarType())!=0 ){
					// 			fprintf(errorout, "Warning : Line No %d -> Function %s() parameter and argument  type mismatch\n", line_count, sInfo->getKey());
								
					// 		}
					// 	}
					// }

					int curSc = symbolTable->getScopeNum();

					symbolTable->setScope(temp->getScopeNo());

					sprintf(tempCode, "%s \ncall %s \nMOV %s, DX \nPOPF \nPOP DI \nPOP SI \nPOP BP \nPOP SP \nPOP DX \nPOP CX \nPOP BX \nPOP AX", 
										(yyvsp[-1].symbolInfoVar)->getCode(), temp->getKey(), tempVar);

					symbolTable->setScope(curSc);

					(yyval.symbolInfoVar) = new SymbolInfo();

					

					temp->copyInfoTo((yyval.symbolInfoVar));
					//fprintf(logout, "%s %s %s %s %d %d %d %f\n", temp->getKey(), temp->getType(), temp->getIDType(), temp->getVarType(), temp->getArrSize(), temp->getArrIdx(), temp->intVal, temp->floatVal);	
					//fprintf(logout, "%s %s %s %s %d %d %d %f\n", $$->getKey(), $$->getType(), $$->getIDType(), $$->getVarType(), $$->getArrSize(), $$->getArrIdx(), $$->intVal, $$->floatVal);	

				}

				(yyval.symbolInfoVar)->setKey(str);
				(yyval.symbolInfoVar)->setType("factor");
				
				(yyval.symbolInfoVar)->setCode(tempCode);
				(yyval.symbolInfoVar)->setTempVar(tempVar);

				delete[] tempCode;

				fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());
				fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
				
				//fprintf(logout, "%s %s %s %s %d %d %d %f\n", $$->getKey(), $$->getType(), $$->getIDType(), $$->getVarType(), $$->getArrSize(), $$->getArrIdx(), $$->intVal, $$->floatVal);	

				delete[] str;


			

		}
#line 3845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 2327 "1505080.y" /* yacc.c:1646  */
    {	    //done
			fprintf(parseout, "factor : LPAREN expression RPAREN\n");
			fprintf(logout, "Line No %d -> factor : LPAREN expression RPAREN\n", line_count);
			fprintf(codeLog, "Line No %d -> factor : LPAREN expression RPAREN\n", line_count);

			char* str = new char[strlen((yyvsp[-1].symbolInfoVar)->getKey())+ 200];
			sprintf(str, "(%s)", (yyvsp[-1].symbolInfoVar)->getKey());

			(yyval.symbolInfoVar) = (yyvsp[-1].symbolInfoVar);

			(yyval.symbolInfoVar)->setKey(str);
			(yyval.symbolInfoVar)->setType("factor");

			fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
			fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());

			delete[] str;

		}
#line 3869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 2347 "1505080.y" /* yacc.c:1646  */
    {	    //done
			fprintf(parseout, "factor : CONST_INT\n");
			fprintf(logout, "Line No %d -> factor : CONST_INT\n", line_count);
			fprintf(codeLog, "Line No %d -> factor : CONST_INT\n", line_count);

			(yyval.symbolInfoVar) = (yyvsp[0].symbolInfoVar);
			(yyval.symbolInfoVar)->intVal = atoi((yyval.symbolInfoVar)->getKey());
			(yyval.symbolInfoVar)->setVarType("INT");

			char* tempVar = newTempVar();
			(yyval.symbolInfoVar)->setTempVar(tempVar); 

			char* tempCode = new char[200];
			sprintf(tempCode, "MOV %s, %d\n", tempVar, (yyval.symbolInfoVar)->intVal);

			(yyval.symbolInfoVar)->setCode(tempCode);        
			 delete[] tempCode;

			fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());	
					fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());		

		}
#line 3896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 2370 "1505080.y" /* yacc.c:1646  */
    {	    //done
			fprintf(parseout, "factor : CONST_FLOAT\n");
			fprintf(logout, "Line No %d -> factor : CONST_FLOAT\n", line_count);
			fprintf(codeLog, "Line No %d -> factor : CONST_FLOAT\n", line_count);

			(yyval.symbolInfoVar) = (yyvsp[0].symbolInfoVar);
			(yyval.symbolInfoVar)->floatVal = atof((yyval.symbolInfoVar)->getKey());
			(yyval.symbolInfoVar)->setVarType("FLOAT");

			char* tempVar = newTempVar();
			(yyval.symbolInfoVar)->setTempVar(tempVar); 

			char* tempCode = new char[200];
			sprintf(tempCode, "MOV %s, %d\n", tempVar, (int)(yyval.symbolInfoVar)->floatVal);

			(yyval.symbolInfoVar)->setCode(tempCode);         
			delete[] tempCode;

			fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());	
					fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());

		}
#line 3923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 2393 "1505080.y" /* yacc.c:1646  */
    {	    //done
			fprintf(parseout, "factor : variable INCOP\n");
			fprintf(logout, "Line No %d -> factor : variable INCOP\n", line_count);
			fprintf(codeLog, "Line No %d -> factor : variable INCOP\n", line_count);

			char* key = new char[strlen((yyvsp[-1].symbolInfoVar)->getKey())+ 200];
			strcpy(key, (yyvsp[-1].symbolInfoVar)->getKey());
			
			char* str = new char[strlen((yyvsp[-1].symbolInfoVar)->getKey())+ 200];
			sprintf(str, "%s++", (yyvsp[-1].symbolInfoVar)->getKey());

			(yyval.symbolInfoVar) = (yyvsp[-1].symbolInfoVar);

			(yyval.symbolInfoVar)->setKey(str);
			(yyval.symbolInfoVar)->setType("factor");

			(yyval.symbolInfoVar)->intVal = (yyval.symbolInfoVar)->intVal+1;
			(yyval.symbolInfoVar)->floatVal = (yyval.symbolInfoVar)->floatVal+1;


				//assigning value into symbolTable
				if(strcmp((yyvsp[-1].symbolInfoVar)->getIDType(),"VAR")==0 ){
					//fprintf(logout, "Here\n");

					SymbolInfo *temp = symbolTable->lookUp(key);
					if(temp==NULL){
						//symbolTable->printAllScopeTable(errorout);
						fprintf(errorout, "Semantic Error : Line No %d -> Variable %s not declared in this scope\n", line_count, (yyvsp[-1].symbolInfoVar)->getKey());
						sem_error++;

					}
					else{
						temp->intVal = (yyval.symbolInfoVar)->intVal;
						temp->floatVal = (yyval.symbolInfoVar)->floatVal;

						char *tempCode = new char[200];
						char *tempVar = newTempVar();

						sprintf(tempCode, "MOV AX, %s \nMOV %s, AX \nINC %s \n", (yyvsp[-1].symbolInfoVar)->getTempVar(), tempVar, (yyvsp[-1].symbolInfoVar)->getTempVar());
						
						(yyval.symbolInfoVar)->setCode(tempCode);
						(yyval.symbolInfoVar)->setTempVar(tempVar);         
						delete[] tempCode;

					}

					/*temp = symbolTable->lookUp($1->getKey());
					if (temp!=NULL){
						fprintf(logout, "Here3\n");
						fprintf(logout, "%s %s %s %s %d %d %d %f\n", temp->getKey(), temp->getType(), temp->getIDType(), temp->getVarType(), temp->getArrSize(), $$->getArrIdx(), temp->intVal, temp->floatVal);	
					}*/


				}
				else if( strcmp((yyvsp[-1].symbolInfoVar)->getIDType(),"ARR")==0 ){
					//dont know yet

					//fprintf(logout, "HERE2\n");

					char *newKey = key;

					for(int i = strlen(newKey)-1; i>=0; i--){
						if(newKey[i]=='['){
							newKey[i]=0;
							break;
						}
					}

					SymbolInfo *temp = symbolTable->lookUp(newKey);
					if(temp==NULL){
						//symbolTable->printAllScopeTable(errorout);
						fprintf(errorout, "Semantic Error : Line No %d -> Variable %s not declared in this scope\n", line_count, (yyvsp[-1].symbolInfoVar)->getKey());
						sem_error++;

					}
					else{
						temp->intVal = (yyval.symbolInfoVar)->intVal;
						temp->floatVal = (yyval.symbolInfoVar)->floatVal;

						temp->setArrIdx((yyvsp[-1].symbolInfoVar)->getArrIdx());

						if(strcmp(temp->getVarType(), "INT")==0){
							temp->setIntListVal((yyval.symbolInfoVar)->getArrIdx(), (yyval.symbolInfoVar)->intVal);	
						}
						else if(strcmp(temp->getVarType(), "FLOAT")==0){
							temp->setFloatListVal((yyval.symbolInfoVar)->getArrIdx(), (yyval.symbolInfoVar)->floatVal);	
						}

						char *tempCode = new char[200];
						char *tempVar = newTempVar();
						sprintf(tempCode, "LEA SI, %s \nMOV BX, %d \nADD BX, %d \nMOV CX, SI[BX] \nMOV %s, CX \nINC CX \nMOV SI[BX], CX \n", 
												(yyvsp[-1].symbolInfoVar)->getTempVar(), (yyvsp[-1].symbolInfoVar)->getArrIdx(), (yyvsp[-1].symbolInfoVar)->getArrIdx(), tempVar);
						
						(yyval.symbolInfoVar)->setCode(tempCode);         
						(yyval.symbolInfoVar)->setTempVar(tempVar);         
						delete[] tempCode;


					}

					/*temp = symbolTable->lookUp(newKey);
					
					if (temp!=NULL){
						fprintf(logout, "Here4\n");
						fprintf(logout, "%s %s %s %s %d %d %d %f\n", temp->getKey(), temp->getType(), temp->getIDType(), temp->getVarType(), temp->getArrSize(), $$->getArrIdx(), temp->intVal, temp->floatVal);	
					
						fprintf(logout, "%d\n", temp->getIntListVal($1->getArrIdx()) );	
						
					}*/

				}


			fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
					fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());

			delete[] str;

		}
#line 4047 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 2513 "1505080.y" /* yacc.c:1646  */
    {	    //done
			fprintf(parseout, "factor : variable DECOP\n");
			fprintf(logout, "Line No %d -> factor : variable DECOP\n", line_count);
			fprintf(codeLog, "Line No %d -> factor : variable DECOP\n", line_count);
			
			char* key = new char[strlen((yyvsp[-1].symbolInfoVar)->getKey())+ 200];
			strcpy(key, (yyvsp[-1].symbolInfoVar)->getKey());

			char* str = new char[strlen((yyvsp[-1].symbolInfoVar)->getKey())+ 200];
			sprintf(str, "%s--", (yyvsp[-1].symbolInfoVar)->getKey());

			(yyval.symbolInfoVar) = (yyvsp[-1].symbolInfoVar);
			(yyval.symbolInfoVar)->setKey(str);
			(yyval.symbolInfoVar)->setType("factor");

			(yyval.symbolInfoVar)->intVal = (yyval.symbolInfoVar)->intVal-1;
			(yyval.symbolInfoVar)->floatVal = (yyval.symbolInfoVar)->floatVal-1;


				//assigning value into symbolTable
				if(strcmp((yyvsp[-1].symbolInfoVar)->getIDType(),"VAR")==0 ){
					//fprintf(logout, "Here\n");

					SymbolInfo *temp = symbolTable->lookUp(key);
					if(temp==NULL){
						//symbolTable->printAllScopeTable(errorout);
						fprintf(errorout, "Semantic Error : Line No %d -> Variable %s not declared in this scope\n", line_count, (yyvsp[-1].symbolInfoVar)->getKey());
						sem_error++;

					}
					else{
						temp->intVal = (yyval.symbolInfoVar)->intVal;
						temp->floatVal = (yyval.symbolInfoVar)->floatVal;

						char *tempCode = new char[200];
						char *tempVar = newTempVar();

						sprintf(tempCode, "MOV AX, %s \nMOV %s, AX \nDEC %s \n", (yyvsp[-1].symbolInfoVar)->getTempVar(), tempVar, (yyvsp[-1].symbolInfoVar)->getTempVar());
						
						(yyval.symbolInfoVar)->setCode(tempCode);
						(yyval.symbolInfoVar)->setTempVar(tempVar);         
						delete[] tempCode;

					}

					/*temp = symbolTable->lookUp($1->getKey());
					if (temp!=NULL){
						fprintf(logout, "Here3\n");
						fprintf(logout, "%s %s %s %s %d %d %d %f\n", temp->getKey(), temp->getType(), temp->getIDType(), temp->getVarType(), temp->getArrSize(), $$->getArrIdx(), temp->intVal, temp->floatVal);	
					}*/


				}
				else if( strcmp((yyvsp[-1].symbolInfoVar)->getIDType(),"ARR")==0 ){
					//dont know yet

					//fprintf(logout, "HERE2\n");

					char *newKey = key;

					for(int i = strlen(newKey)-1; i>=0; i--){
						if(newKey[i]=='['){
							newKey[i]=0;
							break;
						}
					}

					SymbolInfo *temp = symbolTable->lookUp(newKey);
					if(temp==NULL){
						//symbolTable->printAllScopeTable(errorout);
						fprintf(errorout, "Semantic Error : Line No %d -> Variable %s not declared in this scope\n", line_count, (yyvsp[-1].symbolInfoVar)->getKey());
						sem_error++;

					}
					else{
						temp->intVal = (yyval.symbolInfoVar)->intVal;
						temp->floatVal = (yyval.symbolInfoVar)->floatVal;

						temp->setArrIdx((yyvsp[-1].symbolInfoVar)->getArrIdx());

						if(strcmp(temp->getVarType(), "INT")==0){
							temp->setIntListVal((yyval.symbolInfoVar)->getArrIdx(), (yyval.symbolInfoVar)->intVal);	
						}
						else if(strcmp(temp->getVarType(), "FLOAT")==0){
							temp->setFloatListVal((yyval.symbolInfoVar)->getArrIdx(), (yyval.symbolInfoVar)->floatVal);	
						}

						char *tempCode = new char[200];
						char *tempVar = newTempVar();
						sprintf(tempCode, "LEA SI, %s \nMOV BX, %d \nADD BX, %d \nMOV CX, SI[BX] \nMOV %s, CX \nDEC CX \nMOV SI[BX], CX\n", 
												(yyvsp[-1].symbolInfoVar)->getTempVar(), (yyvsp[-1].symbolInfoVar)->getArrIdx(), (yyvsp[-1].symbolInfoVar)->getArrIdx(), tempVar);
						
						(yyval.symbolInfoVar)->setCode(tempCode);         
						(yyval.symbolInfoVar)->setTempVar(tempVar);         
						delete[] tempCode;


						


					}

					/*temp = symbolTable->lookUp(newKey);
					
					if (temp!=NULL){
						fprintf(logout, "Here4\n");
						fprintf(logout, "%s %s %s %s %d %d %d %f\n", temp->getKey(), temp->getType(), temp->getIDType(), temp->getVarType(), temp->getArrSize(), $$->getArrIdx(), temp->intVal, temp->floatVal);	
					
						fprintf(logout, "%d\n", temp->getIntListVal($1->getArrIdx()) );	
						
					}*/

				}

			fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
					fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());

			delete[] str;

		}
#line 4172 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 2636 "1505080.y" /* yacc.c:1646  */
    {	//done 			//NOTHING TO DO
					fprintf(parseout, "argument_list : arguments\n");
					fprintf(logout, "Line No %d -> argument_list : arguments\n", line_count);
					fprintf(codeLog, "Line No %d -> argument_list : arguments\n", line_count);

					(yyval.symbolInfoVar) = (yyvsp[0].symbolInfoVar);
					(yyval.symbolInfoVar)->setType("argument_list");
					fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
					fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());

			  	}
#line 4188 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 2648 "1505080.y" /* yacc.c:1646  */
    {	//done
					fprintf(parseout, "argument_list : <empty>\n");
					fprintf(logout, "Line No %d -> argument_list : <empty>\n", line_count);
					fprintf(codeLog, "Line No %d -> argument_list : <empty>\n", line_count);

					argNo=0;

					(yyval.symbolInfoVar) = new SymbolInfo("","argument_list");
					fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
					fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());

			  	}
#line 4205 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 2663 "1505080.y" /* yacc.c:1646  */
    {	//done
				fprintf(parseout, "arguments : arguments COMMA logic_expression\n");
				fprintf(logout, "Line No %d -> arguments : arguments COMMA logic_expression\n", line_count);
				fprintf(codeLog, "Line No %d -> arguments : arguments COMMA logic_expression\n", line_count);

				(yyval.symbolInfoVar) = (yyvsp[-2].symbolInfoVar);

				char *str = new char[strlen((yyvsp[-2].symbolInfoVar)->getKey()) + strlen((yyvsp[0].symbolInfoVar)->getKey()) + 50];
				sprintf(str, "%s,%s", (yyvsp[-2].symbolInfoVar)->getKey(), (yyvsp[0].symbolInfoVar)->getKey());

				(yyval.symbolInfoVar)->setKey(str);
				(yyval.symbolInfoVar)->setType("arguments");
	
				fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());

				delete[] str;

				SymbolInfo* temp = new SymbolInfo();
				
				(yyvsp[0].symbolInfoVar)->copyInfoTo(temp);
				temp->setType("arguments");

				argList[argNo] = temp;

				argNo++;

				char *tempCode = new char[strlen((yyvsp[-2].symbolInfoVar)->getCode())+strlen((yyvsp[0].symbolInfoVar)->getCode())+200];

				sprintf(tempCode, "%s \n%s \nPUSH %s \n", (yyvsp[-2].symbolInfoVar)->getCode(), (yyvsp[0].symbolInfoVar)->getCode(), (yyvsp[0].symbolInfoVar)->getTempVar());


				(yyval.symbolInfoVar)->setCode(tempCode);

				delete[] tempCode;

					fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
					fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());
				

	      	}
#line 4250 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 2704 "1505080.y" /* yacc.c:1646  */
    {		//done
				fprintf(parseout, "arguments : logic_expression\n");
				fprintf(logout, "Line No %d -> arguments : logic_expression\n", line_count);
				fprintf(codeLog, "Line No %d -> arguments : logic_expression\n", line_count);

				(yyval.symbolInfoVar) = (yyvsp[0].symbolInfoVar);
				(yyval.symbolInfoVar)->setType("arguments");
				fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());

				argNo = 0;

				SymbolInfo* temp = new SymbolInfo();

				char *tempCode = new char[strlen((yyvsp[0].symbolInfoVar)->getCode())+200];

				sprintf(tempCode, "%s \nPUSH %s \n",(yyvsp[0].symbolInfoVar)->getCode(), (yyvsp[0].symbolInfoVar)->getTempVar());
				
				(yyvsp[0].symbolInfoVar)->copyInfoTo(temp);

				(yyval.symbolInfoVar)->setCode(tempCode);
				delete[] tempCode;

				temp->setType("arguments");

				argList[argNo] = temp;

				argNo++;

					fprintf(logout, "%s\n\n", (yyval.symbolInfoVar)->getKey());
					fprintf(codeLog, "%s\n\n", (yyval.symbolInfoVar)->getCode());

	      	}
#line 4287 "y.tab.c" /* yacc.c:1646  */
    break;


#line 4291 "y.tab.c" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 2739 "1505080.y" /* yacc.c:1906  */

int main(int argc,char *argv[])
{	FILE *fp;

	if((fp=fopen(argv[1],"r"))==NULL)
	{
		printf("Cannot Open Input File.\n");
		exit(1);
	}

	parseout = fopen("1505080_parse.txt","w");
	logout= fopen("1505080_log.txt","w");
	errorout = fopen("1505080_error.txt","w");
	codeout = fopen("1505080_code.asm","w");
	codeLog = fopen("1505080_codeLog.txt","w");
	
	if(parseout==NULL || logout==NULL || errorout==NULL || codeout==NULL || codeLog==NULL){
		printf("Cannot Open Output File.\n");
		exit(1);

	}

	symbolTable = new SymbolTable(13);
	symbolTable->enterScope();

	parList = new SymbolInfo*[20];
	argList = new SymbolInfo*[20];

	yyin=fp;
	yyparse();

	symbolTable->printAllScopeTable(logout);


	fprintf(logout, "\n\nLine count = %d\n", line_count);
	fprintf(logout, "Lexical error count = %d\n", lex_error);	
	fprintf(logout, "Semantic error count = %d\n", sem_error);		
	fprintf(errorout, "\nSemantic error count = %d\n", sem_error);
	
	if(lex_error+sem_error)
		printf("Errors = %d\n", lex_error+sem_error);

	fclose(parseout);
	fclose(logout);
	fclose(errorout);
	fclose(codeout);
	fclose(codeLog);
	fclose(yyin);


	//code optimization

	FILE *optCode = fopen("1505080_OptCode.asm","w");
	codeout = fopen("1505080_code.asm","r");

	if(codeout==NULL || optCode==NULL){
		printf("Cannot Open Output File.\n");
		exit(1);

	}

	char *str1 = new char[100];
	char *str2 = new char[200];

	char *dst1 = new char[20];
	char *dst2 = new char[20];
	char *src1 = new char[20];
	char *src2 = new char[20];

	char *dummy = new char[20];

	fgets(str1, 100, codeout);
	//fprintf(optCode, "%s\n", str1);

	while(fgets(str2, 100, codeout)!=NULL){	
		if(strcmp(str2, "")==0 || strcmp(str2, " ")==0 || strcmp(str2, " \n")==0 || str2[0]==0 || str2[0]=='\n'){
			//printf("NEW LINE\n");
			continue;
		}
		else{
			fprintf(optCode, "%s", str1);
	
		}

		if(str1[0]=='M' && str2[0]=='M' && str1[1]=='O' && str2[1]=='O' && str1[2]=='V' && str2[2]=='V'){
			sscanf(str1, "%s %s %s", dummy, dst1, src1);
			sscanf(str2, "%s %s %s", dummy, dst2, src2);

			dst1[strlen(dst1)-1]=0;
			dst2[strlen(dst2)-1]=0;
			//printf("%s, %s \t%s, %s\n", dst1, src1, dst2, src2);
			if(strcmp(dst1, src2)==0 && strcmp(dst2, src1)==0){
				printf("OPTIMIZATION : MOV %s, %s \tMOV %s, %s\n", dst1, src1, dst2, src2);
				//sprintf(str1, ";%s", str2);
				strcpy(str1,  ";");
				strcat(str1, str2);

			}
			else{
				strcpy(str1, str2);
			}


		}
		else{
			strcpy(str1, str2);	
		}

		
		
	}

	fprintf(optCode, "%s", str1);

	fclose(optCode);
	fclose(codeout);


	
	return 0;
}

