/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "cvor.h"
#include "red.h"

void yyerror(const char* msg);
int yylex();
int postoji(char* id);
void dodaj_u_tabelu(char* id, int tip, char* value);
void print_tree(Cvor* node, char *prefix, int is_last);
extern int yylineno;
extern char* yytext;
Cvor* korijen;

enum TipPromenljive { QUERY_TYPE = 0, RESULT_TYPE = 1 };

struct Promenljiva {
    char* id;
    int tip;
    char* value;
};

struct Promenljiva tabela_simbola[50];
int brPromjenljivih = 0;

#line 100 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_WORD = 3,                       /* WORD  */
  YYSYMBOL_STRING = 4,                     /* STRING  */
  YYSYMBOL_QUERY = 5,                      /* QUERY  */
  YYSYMBOL_RESULT_OF_QUERY = 6,            /* RESULT_OF_QUERY  */
  YYSYMBOL_EXEC = 7,                       /* EXEC  */
  YYSYMBOL_IF = 8,                         /* IF  */
  YYSYMBOL_TOKEN_BEGIN = 9,                /* TOKEN_BEGIN  */
  YYSYMBOL_END = 10,                       /* END  */
  YYSYMBOL_FOR = 11,                       /* FOR  */
  YYSYMBOL_IN = 12,                        /* IN  */
  YYSYMBOL_EMPTY = 13,                     /* EMPTY  */
  YYSYMBOL_NOT_EMPTY = 14,                 /* NOT_EMPTY  */
  YYSYMBOL_URL_EXISTS = 15,                /* URL_EXISTS  */
  YYSYMBOL_UNION = 16,                     /* UNION  */
  YYSYMBOL_DIFFERENCE = 17,                /* DIFFERENCE  */
  YYSYMBOL_INTERSECTION = 18,              /* INTERSECTION  */
  YYSYMBOL_OR = 19,                        /* OR  */
  YYSYMBOL_PLUS = 20,                      /* PLUS  */
  YYSYMBOL_MINUS = 21,                     /* MINUS  */
  YYSYMBOL_STAR = 22,                      /* STAR  */
  YYSYMBOL_ASSIGN = 23,                    /* ASSIGN  */
  YYSYMBOL_SEMICOLON = 24,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 25,                     /* COMMA  */
  YYSYMBOL_COLON = 26,                     /* COLON  */
  YYSYMBOL_LANGLE = 27,                    /* LANGLE  */
  YYSYMBOL_RANGLE = 28,                    /* RANGLE  */
  YYSYMBOL_LBRACKET = 29,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 30,                  /* RBRACKET  */
  YYSYMBOL_LPAREN = 31,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 32,                    /* RPAREN  */
  YYSYMBOL_TO = 33,                        /* TO  */
  YYSYMBOL_UNKNOWN = 34,                   /* UNKNOWN  */
  YYSYMBOL_YYACCEPT = 35,                  /* $accept  */
  YYSYMBOL_program = 36,                   /* program  */
  YYSYMBOL_declarations = 37,              /* declarations  */
  YYSYMBOL_declaration = 38,               /* declaration  */
  YYSYMBOL_commands = 39,                  /* commands  */
  YYSYMBOL_command = 40,                   /* command  */
  YYSYMBOL_assign_command = 41,            /* assign_command  */
  YYSYMBOL_condition = 42,                 /* condition  */
  YYSYMBOL_list_of_queries = 43,           /* list_of_queries  */
  YYSYMBOL_query_list = 44,                /* query_list  */
  YYSYMBOL_query = 45,                     /* query  */
  YYSYMBOL_terms = 46,                     /* terms  */
  YYSYMBOL_term = 47,                      /* term  */
  YYSYMBOL_directive = 48,                 /* directive  */
  YYSYMBOL_operator = 49,                  /* operator  */
  YYSYMBOL_set_operator = 50,              /* set_operator  */
  YYSYMBOL_identifier = 51,                /* identifier  */
  YYSYMBOL_query_name = 52,                /* query_name  */
  YYSYMBOL_KEY = 53,                       /* KEY  */
  YYSYMBOL_VALUE = 54,                     /* VALUE  */
  YYSYMBOL_TERM = 55                       /* TERM  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   108

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  44
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  94

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   289


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    56,    56,    64,    65,    69,    88,   103,   117,   118,
     122,   131,   147,   163,   183,   187,   212,   242,   271,   298,
     316,   322,   328,   340,   344,   354,   358,   365,   374,   378,
     382,   392,   403,   404,   405,   409,   410,   411,   417,   421,
     425,   429,   430,   434,   435
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "WORD", "STRING",
  "QUERY", "RESULT_OF_QUERY", "EXEC", "IF", "TOKEN_BEGIN", "END", "FOR",
  "IN", "EMPTY", "NOT_EMPTY", "URL_EXISTS", "UNION", "DIFFERENCE",
  "INTERSECTION", "OR", "PLUS", "MINUS", "STAR", "ASSIGN", "SEMICOLON",
  "COMMA", "COLON", "LANGLE", "RANGLE", "LBRACKET", "RBRACKET", "LPAREN",
  "RPAREN", "TO", "UNKNOWN", "$accept", "program", "declarations",
  "declaration", "commands", "command", "assign_command", "condition",
  "list_of_queries", "query_list", "query", "terms", "term", "directive",
  "operator", "set_operator", "identifier", "query_name", "KEY", "VALUE",
  "TERM", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-45)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-41)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      75,    21,    26,    49,    56,   -45,   -45,    31,   -45,    34,
     -45,    21,    38,    26,   -45,    71,   -45,    36,    48,     3,
     -45,    53,    57,    58,    59,    -2,    79,   -45,   -45,    20,
      35,    21,    68,    69,   -45,   -45,    26,    26,    26,    71,
      71,    65,    21,    67,    70,   -45,   -45,   -45,   -45,    22,
     -45,   -45,    35,    72,   -45,   -16,   -45,   -45,   -45,    63,
      73,    74,    10,     8,    88,   -45,   -45,   -45,   -45,    26,
      35,   -45,   -45,   -45,    83,    21,   -45,   -45,   -45,    96,
     -45,    71,    71,   -45,    35,   -45,   -45,   -45,   -45,    76,
      71,    62,   -45,   -45
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     3,    39,     0,    38,     0,
       1,     0,     0,     0,     4,     2,     8,     0,     0,     0,
       7,     0,     0,     0,     0,     0,     0,     9,    14,     0,
       0,     0,     0,     0,    24,    10,     0,     0,     0,     0,
       0,     0,     0,     0,    43,    44,    32,    33,    34,     0,
      25,    29,     0,     0,    28,     0,    21,     6,     5,     0,
       0,     0,     0,     0,     0,    15,    35,    36,    37,     0,
       0,    23,    26,    30,     0,     0,    20,    17,    18,     0,
      11,     0,     0,    16,    27,    41,    42,    31,    22,     0,
      12,     0,    19,    13
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -45,   -45,   -45,    97,   -36,   -15,   -45,   -45,    61,   -45,
     -45,    33,   -44,   -45,   -45,   -45,    -1,    -9,   -45,   -45,
     -45
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,    15,    16,    17,    25,    32,    55,
      33,    49,    50,    51,    52,    69,    18,     7,    53,    87,
      54
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      27,     9,    21,    62,    63,    72,     6,    39,    73,    75,
      34,     8,    26,     8,    76,    11,    12,    11,    12,    13,
      80,    13,    56,     8,     6,    44,    45,    42,    43,     8,
      30,    40,    31,    65,    81,    59,    60,    61,    44,    45,
      72,    70,    46,    47,    48,    90,    91,    27,    27,    10,
      71,    22,    23,    24,    19,    46,    47,    48,    20,     8,
      28,     1,     2,    11,    12,     8,    88,    13,    83,    11,
      12,    29,    93,    13,     8,    27,    27,    35,    11,    12,
       1,     2,    13,    66,    67,    68,    85,    86,    36,    37,
      38,    41,    57,    58,    31,    77,   -40,    82,    74,    79,
      89,    14,    64,    84,     0,    78,     0,     0,    92
};

static const yytype_int8 yycheck[] =
{
      15,     2,    11,    39,    40,    49,     3,     9,    52,    25,
      19,     3,    13,     3,    30,     7,     8,     7,     8,    11,
      10,    11,    31,     3,     3,     3,     4,     7,    29,     3,
      27,    33,    29,    42,    26,    36,    37,    38,     3,     4,
      84,    19,    20,    21,    22,    81,    82,    62,    63,     0,
      28,    13,    14,    15,    23,    20,    21,    22,    24,     3,
      24,     5,     6,     7,     8,     3,    75,    11,    69,     7,
       8,    23,    10,    11,     3,    90,    91,    24,     7,     8,
       5,     6,    11,    16,    17,    18,     3,     4,    31,    31,
      31,    12,    24,    24,    29,    32,    26,     9,    26,    25,
       4,     4,    41,    70,    -1,    32,    -1,    -1,    32
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     6,    36,    37,    38,     3,    52,     3,    51,
       0,     7,     8,    11,    38,    39,    40,    41,    51,    23,
      24,    52,    13,    14,    15,    42,    51,    40,    24,    23,
      27,    29,    43,    45,    52,    24,    31,    31,    31,     9,
      33,    12,     7,    51,     3,     4,    20,    21,    22,    46,
      47,    48,    49,    53,    55,    44,    52,    24,    24,    51,
      51,    51,    39,    39,    43,    52,    16,    17,    18,    50,
      19,    28,    47,    47,    26,    25,    30,    32,    32,    25,
      10,    26,     9,    51,    46,     3,     4,    54,    52,     4,
      39,    39,    32,    10
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    35,    36,    37,    37,    38,    38,    38,    39,    39,
      40,    40,    40,    40,    40,    41,    41,    42,    42,    42,
      43,    44,    44,    45,    45,    46,    46,    46,    47,    47,
      47,    48,    49,    49,    49,    50,    50,    50,    51,    52,
      53,    54,    54,    55,    55
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     2,     5,     5,     3,     1,     2,
       3,     5,     6,     7,     2,     4,     5,     4,     4,     6,
       3,     1,     3,     3,     1,     1,     2,     3,     1,     1,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* program: declarations commands  */
#line 57 "parser.y"
    {
        dodajSina(korijen,(yyvsp[-1].CvorPokazivac));
        dodajSina(korijen,(yyvsp[0].CvorPokazivac));
    }
#line 1205 "parser.tab.c"
    break;

  case 3: /* declarations: declaration  */
#line 64 "parser.y"
                  {(yyval.CvorPokazivac) = kreirajCvor("Declarations"); dodajSina((yyval.CvorPokazivac),(yyvsp[0].CvorPokazivac));}
#line 1211 "parser.tab.c"
    break;

  case 4: /* declarations: declarations declaration  */
#line 65 "parser.y"
                               {(yyval.CvorPokazivac) = (yyvsp[-1].CvorPokazivac); dodajSina((yyval.CvorPokazivac),(yyvsp[0].CvorPokazivac));}
#line 1217 "parser.tab.c"
    break;

  case 5: /* declaration: QUERY query_name ASSIGN query SEMICOLON  */
#line 70 "parser.y"
      {

          int len = strlen("QueryDeclaration") + strlen((yyvsp[-3].CvorPokazivac)->vrijednost) + 4;
          char* tekst = (char*)malloc(len);
          snprintf(tekst, len, "QueryDeclaration(%s)", (yyvsp[-3].CvorPokazivac)->vrijednost);
          
          Cvor* temp = kreirajCvor(tekst);

            
          (yyval.CvorPokazivac) = temp;
          dodajSina(temp,(yyvsp[-4].CvorPokazivac));
          dodajSina((yyvsp[-4].CvorPokazivac),(yyvsp[-1].CvorPokazivac));
           
          
          free(tekst);
          
          dodaj_u_tabelu((yyvsp[-3].CvorPokazivac)->vrijednost, QUERY_TYPE, (yyvsp[-1].CvorPokazivac)->vrijednost);
      }
#line 1240 "parser.tab.c"
    break;

  case 6: /* declaration: QUERY query_name ASSIGN list_of_queries SEMICOLON  */
#line 89 "parser.y"
      {
          int len = strlen("QueryDeclaration") + strlen((yyvsp[-3].CvorPokazivac)->vrijednost) + 4;
          char* tekst = (char*)malloc(len);
          snprintf(tekst, len, "QueryDeclaration(%s)", (yyvsp[-3].CvorPokazivac)->vrijednost);
          
          Cvor* temp = kreirajCvor(tekst);


          (yyval.CvorPokazivac) = temp;
          dodajSina(temp,(yyvsp[-1].CvorPokazivac));

          dodaj_u_tabelu((yyvsp[-3].CvorPokazivac)->vrijednost, QUERY_TYPE, strdup("LIST"));

      }
#line 1259 "parser.tab.c"
    break;

  case 7: /* declaration: RESULT_OF_QUERY identifier SEMICOLON  */
#line 104 "parser.y"
      {
          int len = strlen("ResultOfQueryDeclaration") + strlen((yyvsp[-1].CvorPokazivac)->vrijednost) + 4;
          char* tekst = (char*)malloc(len);
          snprintf(tekst, len, "ResultOfQueryDeclaration(%s)", (yyvsp[-1].CvorPokazivac)->vrijednost);

          Cvor* temp = kreirajCvor(tekst);

          (yyval.CvorPokazivac) = temp;
          dodaj_u_tabelu((yyvsp[-1].CvorPokazivac)->vrijednost, RESULT_TYPE, strdup(""));
      }
#line 1274 "parser.tab.c"
    break;

  case 8: /* commands: command  */
#line 117 "parser.y"
              {(yyval.CvorPokazivac) = kreirajCvor("Commands"); dodajSina((yyval.CvorPokazivac),(yyvsp[0].CvorPokazivac));}
#line 1280 "parser.tab.c"
    break;

  case 9: /* commands: commands command  */
#line 118 "parser.y"
                       {(yyval.CvorPokazivac) = (yyvsp[-1].CvorPokazivac); dodajSina((yyvsp[-1].CvorPokazivac),(yyvsp[0].CvorPokazivac));}
#line 1286 "parser.tab.c"
    break;

  case 10: /* command: EXEC query_name SEMICOLON  */
#line 122 "parser.y"
                                {
        int len = strlen("ExecCommand()") + strlen((yyvsp[-1].CvorPokazivac)->vrijednost) + 2;
        char* tekst = (char*)malloc(len);
        snprintf(tekst, len, "ExecCommand(%s)", (yyvsp[-1].CvorPokazivac)->vrijednost);

        Cvor* temp = kreirajCvor(tekst);
        (yyval.CvorPokazivac) = temp;
        free(tekst); 
    }
#line 1300 "parser.tab.c"
    break;

  case 11: /* command: IF condition TOKEN_BEGIN commands END  */
#line 131 "parser.y"
                                           {

        /*int len = strlen("If(condition:)") + strlen($2->vrijednost) + 2;
        char* tekst = (char*)malloc(len);
        snprintf(tekst, len, "ForCommand(iteroator:%s)", $2->vrijednost);

        Cvor* temp = kreirajCvor(tekst);*/

        if((yyvsp[-3].CvorPokazivac) != NULL){
            dodajSina((yyvsp[-4].CvorPokazivac),(yyvsp[-3].CvorPokazivac));
            dodajSina((yyvsp[-4].CvorPokazivac),(yyvsp[-1].CvorPokazivac));
        }

        (yyval.CvorPokazivac) = (yyvsp[-4].CvorPokazivac);

    }
#line 1321 "parser.tab.c"
    break;

  case 12: /* command: IF condition TO commands COLON commands  */
#line 147 "parser.y"
                                             {

        

        if((yyvsp[-4].CvorPokazivac) != NULL){
            
            dodajSina((yyvsp[-5].CvorPokazivac),(yyvsp[-2].CvorPokazivac));
        }
        else{
            
            dodajSina((yyvsp[-5].CvorPokazivac),(yyvsp[0].CvorPokazivac));
            
        }
        (yyval.CvorPokazivac) = (yyvsp[-5].CvorPokazivac);

    }
#line 1342 "parser.tab.c"
    break;

  case 13: /* command: FOR identifier IN list_of_queries TOKEN_BEGIN commands END  */
#line 164 "parser.y"
      {
          int len = strlen("ForCommand(iterator:)") + strlen((yyvsp[-5].CvorPokazivac)->vrijednost) + 2;
          char* tekst = (char*)malloc(len);
          snprintf(tekst, len, "ForCommand(iteroator:%s)", (yyvsp[-5].CvorPokazivac)->vrijednost);

          Cvor* temp = kreirajCvor(tekst);

          (yyval.CvorPokazivac) = temp;
          Cvor* iterable = kreirajCvor("iterable");
          Cvor* body = kreirajCvor("Body");
          dodajSina(temp,iterable);
          dodajSina(body, (yyvsp[-1].CvorPokazivac));
          dodajSina(temp,body);
          
          dodajSina(iterable,(yyvsp[-3].CvorPokazivac));  
          

          dodaj_u_tabelu((yyvsp[-5].CvorPokazivac)->vrijednost, RESULT_TYPE, strdup(""));
      }
#line 1366 "parser.tab.c"
    break;

  case 15: /* assign_command: identifier ASSIGN EXEC query_name  */
#line 187 "parser.y"
                                        {

        if (postoji((yyvsp[-3].CvorPokazivac)->vrijednost) == -1) {
            yyerror("Nedeklarisana varijabla");
        }

        (yyval.CvorPokazivac) = kreirajCvor("AsssignCommand");
        
        
        int len = strlen((yyvsp[-3].CvorPokazivac)->vrijednost) + strlen("Target:")+ 3;
        char* tekst = (char*)malloc(len);
        snprintf(tekst, len, "Target:%s", (yyvsp[-3].CvorPokazivac)->vrijednost);
        Cvor* temp = kreirajCvor(tekst);
        dodajSina((yyval.CvorPokazivac),temp); 
        free(tekst);

        
        int len1 = strlen((yyvsp[0].CvorPokazivac)->vrijednost) + strlen("ExecCommand") + 4;
        char* tekst1 = (char*)malloc(len1);
        snprintf(tekst1, len1, "ExecCommand(%s)", (yyvsp[0].CvorPokazivac)->vrijednost);

        Cvor* temp1 = kreirajCvor(tekst1);
        dodajSina((yyval.CvorPokazivac),temp1);
        free(tekst1);
    }
#line 1396 "parser.tab.c"
    break;

  case 16: /* assign_command: identifier ASSIGN identifier set_operator identifier  */
#line 212 "parser.y"
                                                          {

        if (postoji((yyvsp[-4].CvorPokazivac)->vrijednost) == -1) {
            yyerror("Nedeklarisana varijabla");
        }
        if (postoji((yyvsp[-2].CvorPokazivac)->vrijednost) == -1) {
            yyerror("Nedeklarisana varijabla");
        }
        

        (yyval.CvorPokazivac) = kreirajCvor("AsssignCommand");

        int len = strlen((yyvsp[-4].CvorPokazivac)->vrijednost) + strlen("Target:")+ 3;
        char* tekst = (char*)malloc(len);
        snprintf(tekst, len, "Target:%s", (yyvsp[-4].CvorPokazivac)->vrijednost);
        Cvor* temp = kreirajCvor(tekst);
        dodajSina((yyval.CvorPokazivac),temp); 
        free(tekst);

        int len1 = strlen((yyvsp[-2].CvorPokazivac)->vrijednost) + strlen((yyvsp[-1].CvorPokazivac)->vrijednost) + strlen((yyvsp[0].CvorPokazivac)->vrijednost) + strlen("SetOperation") + 4;
        char* tekst1 = (char*)malloc(len1);
        snprintf(tekst1, len1, "SetOperation(%s%s%s)", (yyvsp[-2].CvorPokazivac)->vrijednost,(yyvsp[-1].CvorPokazivac)->vrijednost, (yyvsp[0].CvorPokazivac)->vrijednost);

        Cvor* temp1 = kreirajCvor(tekst1);
        dodajSina((yyval.CvorPokazivac),temp1);
        free(tekst1);
    }
#line 1428 "parser.tab.c"
    break;

  case 17: /* condition: EMPTY LPAREN identifier RPAREN  */
#line 242 "parser.y"
                                    {

        if (postoji((yyvsp[-1].CvorPokazivac)->vrijednost) == -1) {
            yyerror("Nedeklarisana varijabla");
        }
        
        int len = strlen((yyvsp[-3].CvorPokazivac)->vrijednost) + strlen((yyvsp[-1].CvorPokazivac)->vrijednost)+4;
        char* tekst = (char*)malloc(len);
        snprintf(tekst, len, "%s(%s)", (yyvsp[-3].CvorPokazivac)->vrijednost, (yyvsp[-1].CvorPokazivac)->vrijednost);
        Cvor* temp = kreirajCvor(tekst);
        
        if (postoji((yyvsp[-1].CvorPokazivac)->vrijednost) == -1) {
            yyerror("Nedeklarisana varijabla");
            (yyval.CvorPokazivac) = NULL;
        }
        else{
            int id = postoji((yyvsp[-1].CvorPokazivac)->vrijednost);
            if (strcmp(tabela_simbola[id].value,"") == 0){
                (yyval.CvorPokazivac) = temp;
            }
            else{
                (yyval.CvorPokazivac) = NULL;
            }
        }
        

        free(tekst);
        
      }
#line 1462 "parser.tab.c"
    break;

  case 18: /* condition: NOT_EMPTY LPAREN identifier RPAREN  */
#line 271 "parser.y"
                                        {

        if (postoji((yyvsp[-1].CvorPokazivac)->vrijednost) == -1) {
            yyerror("Nedeklarisana varijabla");
        }

        int len = strlen((yyvsp[-3].CvorPokazivac)->vrijednost) + strlen((yyvsp[-1].CvorPokazivac)->vrijednost)+ 4;
        char* tekst = (char*)malloc(len);
        snprintf(tekst, len, "%s(%s)", (yyvsp[-3].CvorPokazivac)->vrijednost, (yyvsp[-1].CvorPokazivac)->vrijednost);
        Cvor* temp = kreirajCvor(tekst);
        
        if (postoji((yyvsp[-1].CvorPokazivac)->vrijednost) == -1) {
            yyerror("Nedeklarisana varijabla");
            (yyval.CvorPokazivac) = NULL;
        }
        else{
            int id = postoji((yyvsp[-1].CvorPokazivac)->vrijednost);
            if (strcmp(tabela_simbola[id].value,"") == 0){
                (yyval.CvorPokazivac) = NULL;
            }
            else{
                (yyval.CvorPokazivac) = temp;
            }
        }

        free(tekst);
    }
#line 1494 "parser.tab.c"
    break;

  case 19: /* condition: URL_EXISTS LPAREN identifier COMMA STRING RPAREN  */
#line 298 "parser.y"
                                                      {

        if (postoji((yyvsp[-3].CvorPokazivac)->vrijednost) == -1) {
            yyerror("Nedeklarisana varijabla");
        }

        int len = strlen((yyvsp[-5].CvorPokazivac)->vrijednost) + strlen((yyvsp[-3].CvorPokazivac)->vrijednost)+ strlen((yyvsp[-1].CvorPokazivac)->vrijednost)+ 4;
        char* tekst = (char*)malloc(len);
        snprintf(tekst, len, "%s(%s,%s)", (yyvsp[-5].CvorPokazivac)->vrijednost, (yyvsp[-3].CvorPokazivac)->vrijednost, (yyvsp[-1].CvorPokazivac)->vrijednost);
        Cvor* temp = kreirajCvor(tekst);

        (yyval.CvorPokazivac) = temp;

        free(tekst);
    }
#line 1514 "parser.tab.c"
    break;

  case 20: /* list_of_queries: LBRACKET query_list RBRACKET  */
#line 316 "parser.y"
                                {
        (yyval.CvorPokazivac) = (yyvsp[-1].CvorPokazivac);
    }
#line 1522 "parser.tab.c"
    break;

  case 21: /* query_list: query_name  */
#line 322 "parser.y"
                {
        if (postoji((yyvsp[0].CvorPokazivac)->vrijednost) == -1) {
            yyerror("Nedeklarisana varijabla");
        }
        (yyval.CvorPokazivac) = kreirajCvor((yyvsp[0].CvorPokazivac)->vrijednost);
      }
#line 1533 "parser.tab.c"
    break;

  case 22: /* query_list: query_list COMMA query_name  */
#line 328 "parser.y"
                                 {
        
        int len = strlen((yyvsp[-2].CvorPokazivac)->vrijednost) + strlen((yyvsp[0].CvorPokazivac)->vrijednost) + 5;
        char* combined = (char*)malloc(len);
        snprintf(combined, len, "[%s, %s]", (yyvsp[-2].CvorPokazivac)->vrijednost, (yyvsp[0].CvorPokazivac)->vrijednost);

        (yyval.CvorPokazivac) = kreirajCvor(combined);
        free(combined);
    }
#line 1547 "parser.tab.c"
    break;

  case 23: /* query: LANGLE terms RANGLE  */
#line 341 "parser.y"
    {
        (yyval.CvorPokazivac) = (yyvsp[-1].CvorPokazivac);
    }
#line 1555 "parser.tab.c"
    break;

  case 24: /* query: query_name  */
#line 345 "parser.y"
    {
        if (postoji((yyvsp[0].CvorPokazivac)->vrijednost) == -1) {
            yyerror("Nedeklarisana varijabla");
        }
        (yyval.CvorPokazivac) = kreirajCvor((yyvsp[0].CvorPokazivac)->vrijednost);
    }
#line 1566 "parser.tab.c"
    break;

  case 25: /* terms: term  */
#line 355 "parser.y"
      {
          (yyval.CvorPokazivac) = kreirajCvor((yyvsp[0].CvorPokazivac)->vrijednost);
      }
#line 1574 "parser.tab.c"
    break;

  case 26: /* terms: terms term  */
#line 358 "parser.y"
                {

        (yyval.CvorPokazivac) = kreirajCvor("Juxtaposition");
        dodajSina((yyval.CvorPokazivac),(yyvsp[-1].CvorPokazivac));
        dodajSina((yyval.CvorPokazivac),(yyvsp[0].CvorPokazivac));
        
}
#line 1586 "parser.tab.c"
    break;

  case 27: /* terms: terms OR terms  */
#line 366 "parser.y"
{
        (yyval.CvorPokazivac) = kreirajCvor("Or");
        dodajSina((yyval.CvorPokazivac), (yyvsp[-2].CvorPokazivac));  
        dodajSina((yyval.CvorPokazivac), (yyvsp[0].CvorPokazivac));  
}
#line 1596 "parser.tab.c"
    break;

  case 28: /* term: TERM  */
#line 375 "parser.y"
      {
          (yyval.CvorPokazivac) = (yyvsp[0].CvorPokazivac);
      }
#line 1604 "parser.tab.c"
    break;

  case 29: /* term: directive  */
#line 379 "parser.y"
      {
          (yyval.CvorPokazivac) = (yyvsp[0].CvorPokazivac);
      }
#line 1612 "parser.tab.c"
    break;

  case 30: /* term: operator term  */
#line 383 "parser.y"
      {
          int len = strlen((yyvsp[-1].CvorPokazivac)->vrijednost) + strlen((yyvsp[0].CvorPokazivac)->vrijednost) + 2;
          char* combined = (char*)malloc(len);
          snprintf(combined, len, "%s%s", (yyvsp[-1].CvorPokazivac)->vrijednost, (yyvsp[0].CvorPokazivac)->vrijednost);
          (yyval.CvorPokazivac) = kreirajCvor(combined);
      }
#line 1623 "parser.tab.c"
    break;

  case 31: /* directive: KEY COLON VALUE  */
#line 393 "parser.y"
    {
        int len = strlen("Directive") +  strlen((yyvsp[-2].CvorPokazivac)->vrijednost) + strlen((yyvsp[0].CvorPokazivac)->vrijednost) + 4;
        char* combined = (char*)malloc(len + 1);
        snprintf(combined, len + 1, "Directive(%s:%s)", (yyvsp[-2].CvorPokazivac)->vrijednost, (yyvsp[0].CvorPokazivac)->vrijednost);
        (yyval.CvorPokazivac) = kreirajCvor(combined);
        free(combined);
    }
#line 1635 "parser.tab.c"
    break;

  case 32: /* operator: PLUS  */
#line 403 "parser.y"
               { (yyval.CvorPokazivac) = (yyvsp[0].CvorPokazivac);}
#line 1641 "parser.tab.c"
    break;

  case 33: /* operator: MINUS  */
#line 404 "parser.y"
               { (yyval.CvorPokazivac) = (yyvsp[0].CvorPokazivac);}
#line 1647 "parser.tab.c"
    break;

  case 34: /* operator: STAR  */
#line 405 "parser.y"
               { (yyval.CvorPokazivac) = (yyvsp[0].CvorPokazivac);}
#line 1653 "parser.tab.c"
    break;

  case 35: /* set_operator: UNION  */
#line 409 "parser.y"
                    { (yyval.CvorPokazivac) = (yyvsp[0].CvorPokazivac);}
#line 1659 "parser.tab.c"
    break;

  case 36: /* set_operator: DIFFERENCE  */
#line 410 "parser.y"
                    { (yyval.CvorPokazivac) = (yyvsp[0].CvorPokazivac);}
#line 1665 "parser.tab.c"
    break;

  case 37: /* set_operator: INTERSECTION  */
#line 411 "parser.y"
                    { (yyval.CvorPokazivac) = (yyvsp[0].CvorPokazivac);}
#line 1671 "parser.tab.c"
    break;

  case 38: /* identifier: WORD  */
#line 417 "parser.y"
         { (yyval.CvorPokazivac) = (yyvsp[0].CvorPokazivac); }
#line 1677 "parser.tab.c"
    break;

  case 39: /* query_name: WORD  */
#line 421 "parser.y"
         { (yyval.CvorPokazivac) = (yyvsp[0].CvorPokazivac); }
#line 1683 "parser.tab.c"
    break;

  case 40: /* KEY: WORD  */
#line 425 "parser.y"
         { (yyval.CvorPokazivac) = (yyvsp[0].CvorPokazivac); }
#line 1689 "parser.tab.c"
    break;

  case 41: /* VALUE: WORD  */
#line 429 "parser.y"
             { (yyval.CvorPokazivac) = (yyvsp[0].CvorPokazivac); }
#line 1695 "parser.tab.c"
    break;

  case 42: /* VALUE: STRING  */
#line 430 "parser.y"
             { (yyval.CvorPokazivac) = (yyvsp[0].CvorPokazivac); }
#line 1701 "parser.tab.c"
    break;

  case 43: /* TERM: WORD  */
#line 434 "parser.y"
             { (yyval.CvorPokazivac) = (yyvsp[0].CvorPokazivac); }
#line 1707 "parser.tab.c"
    break;

  case 44: /* TERM: STRING  */
#line 435 "parser.y"
             { (yyval.CvorPokazivac) = (yyvsp[0].CvorPokazivac); }
#line 1713 "parser.tab.c"
    break;


#line 1717 "parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 438 "parser.y"


void yyerror(const char* msg) {
    fprintf(stderr, "Syntax error at line %d near '%s': %s\n", yylineno, yytext, msg);
    exit(1);
    
}

int postoji(char* id) {
    for (int i = 0; i < brPromjenljivih; i++) {
        if (strcmp(tabela_simbola[i].id, id) == 0)
            return i;
    }
    return -1;
}

void dodaj_u_tabelu(char* id, int tip, char* value) {
    int idx = postoji(id);
    if (idx != -1) {
        tabela_simbola[idx].tip = tip;
        free(tabela_simbola[idx].value);
        tabela_simbola[idx].value = strdup(value);
        return;
    }

    if (brPromjenljivih >= 50) {
        fprintf(stderr, "Previše promenljivih!\n");
        exit(1);
    }

    tabela_simbola[brPromjenljivih].id = strdup(id);
    tabela_simbola[brPromjenljivih].tip = tip;
    tabela_simbola[brPromjenljivih].value = strdup(value);
    brPromjenljivih++;
}

void ispisi_tabelu() {
    printf("\nTABELA PROMENLJIVIH:\n");
    for (int i = 0; i < brPromjenljivih; i++) {
        printf("  %s (tip %d): %s\n", tabela_simbola[i].id, tabela_simbola[i].tip, tabela_simbola[i].value);
    }
}

void print_tree(Cvor* node, char *prefix, int is_last) {
    printf("%s%s%s\n", prefix, is_last ? "└─ " : "├─ ", node->vrijednost);

    char new_prefix[1024];
    snprintf(new_prefix, sizeof(new_prefix), "%s%s", prefix, is_last ? "    " : "│   ");

    for (int i = 0; i < node->broj_sinova; i++) {
        print_tree(node->sinovi[i], new_prefix, i == node->broj_sinova - 1);
    }
}

int main() {

    
    korijen = kreirajCvor("Program");
    int res = yyparse();
    if (res == 0) {
        printf("Ulaz je ispravan\n");
    } else {
        printf("Ulaz nije ispravan\n");
    }

    print_tree(korijen, "",1);

    /*int cnt = 0;

    bool kraj = false;


    struct Red* red = malloc(sizeof(struct Red));
    int nivo = 0;

    inicijalizujRed(red);

    dodajURed(red,korijen);

    printf("Prvi nivo:\n");
   

    while(true) {
        if(red->glava == 0) {
            break;
        }
        struct Cvor* tmp = ukloniSPocetka(red);
        
        if(tmp->nivo > nivo) {
            printf("\n\n%d-ti Nivo:",tmp->nivo+1);
            printf("\n%s ",tmp->vrijednost);
            nivo++;
            
        }
        else {
            printf("%s ",tmp->vrijednost);
        }
    


        int cnt = 0;
        while(cnt < tmp->broj_sinova) {
            tmp->sinovi[cnt]->nivo = tmp->nivo + 1;
            dodajURed(red,tmp->sinovi[cnt]);
            cnt++;
        }
    }

    printf("\n");*/

    return 0;
}
