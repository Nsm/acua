#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#include <stdlib.h>
#include <string.h>

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20080827

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
#ifdef YYPARSE_PARAM_TYPE
#define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
#else
#define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
#endif
#else
#define YYPARSE_DECL() yyparse(void)
#endif /* YYPARSE_PARAM */

extern int YYPARSE_DECL();

static int yygrowstack(void);
#define YYPREFIX "yy"
#line 4 "yacc.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CANT_ESTADOS  35
#define CANT_ENTRADAS  22

int nuevo_estado[CANT_ESTADOS - 1][CANT_ENTRADAS] = {{4, 2, 9, 11, 7, 30, 5, 17, 23, 21, 1, 27, 29, 28, 13, 15, 19, 20, 25, 26, 3, 0},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 34, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{34, 2, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 3, 34},
{34, 3, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34},
{4, 4, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34},
{34, 34, 34, 34, 34, 34, 6, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34},
{34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34},
{34, 34, 34, 34, 34, 34, 8, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34},
{34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34},
{34, 34, 34, 34, 34, 34, 10, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34},
{34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34},
{34, 34, 34, 34, 34, 34, 12, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34},
{34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34},
{34, 34, 34, 34, 34, 34, 14, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34},
{34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34},
{34, 34, 34, 34, 34, 34, 16, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34},
{34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34},
{34, 34, 34, 34, 34, 34, 18, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34},
{34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34},
{34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34},
{34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34},
{34, 34, 34, 34, 34, 34, 34, 34, 34, 22, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34},
{34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34},
{34, 34, 34, 34, 34, 34, 34, 34, 24, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34},
{34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34},
{34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34},
{34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34},
{34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34},
{34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34},
{34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34},
{34, 34, 34, 34, 32, 34, 31, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34},
{34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34},
{32, 32, 32, 32, 33, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32},
{32, 32, 32, 32, 33, 0, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32 }};


int startId(char c);
int startNumber(char c);
int startSum(char c);
int startSubstraction(char c);
int startMultiplication(char c);
int startDivision(char c);
int startAutoSum(char c);
int startAutoSubstraction(char c);
int startAutoMultiplication(char c);
int startAutoDivision(char c);
int startAsignation(char c);
int startNegation(char c);
int startAnd(char c);
int startOr(char c);
int startString(char c);
int startSemicolon(char c);
int startComma(char c);
int startSeparator(char c);
int startLower(char c);
int startUpper(char c);
int startBracket(char c);
int startRightBracket(char c);
int startBrace(char c);
int startRightBrace(char c);
int startEqual(char c);
int startEqualLower(char c);
int startEqualUpper(char c);
int startNotEqual(char c);
int startComment(char c);
int contId(char c);
int contNumber(char c);
int contSum(char c);
int contSubstraction(char c);
int contMultiplication(char c);
int contDivision(char c);
int contAutoSum(char c);
int contAutoSubstraction(char c);
int contAutoMultiplication(char c);
int contAutoDivision(char c);
int contAsignation(char c);
int contNegation(char c);
int contAnd(char c);
int contOr(char c);
int contString(char c);
int contSemicolon(char c);
int contComma(char c);
int contSeparator(char c);
int contLower(char c);
int contUpper(char c);
int contBracket(char c);
int contRightBracket(char c);
int contBrace(char c);
int contRightBrace(char c);
int contEqual(char c);
int contEqualLower(char c);
int contEqualUpper(char c);
int contNotEqual(char c);
int contComment(char c);
int endId(char c);
int endNumber(char c);
int endSum(char c);
int endSubstraction(char c);
int endMultiplication(char c);
int endDivision(char c);
int endAutoSum(char c);
int endAutoSubstraction(char c);
int endAutoMultiplication(char c);
int endAutoDivision(char c);
int endAsignation(char c);
int endNegation(char c);
int endAnd(char c);
int endOr(char c);
int endString(char c);
int endSemicolon(char c);
int endComma(char c);
int endSeparator(char c);
int endLower(char c);
int endUpper(char c);
int endBracket(char c);
int endRightBracket(char c);
int endBrace(char c);
int endRightBrace(char c);
int endEqual(char c);
int endEqualLower(char c);
int endEqualUpper(char c);
int endNotEqual(char c);
int endComment(char c);
int error(char c);
int nothing(char c);
int reservedWord(char * id);
int yyparse();
void yyerror(char *);
char* getTypeString(int tipoToken);

int (* funciones[CANT_ESTADOS - 1][CANT_ENTRADAS])(char) = {
{startId, startNumber, startSum, startSubstraction, startMultiplication , startDivision, startAsignation, startNegation, startAnd, startOr, startString, startSemicolon, startComma, startSeparator, startLower, startUpper, startBracket, startRightBracket, startBrace, startRightBrace, startNumber, nothing},
{contString, contString, contString, contString, contString, contString, contString, contString, contString, contString, endString, contString, contString, contString, contString, contString, contString, contString, contString, contString, contString, contString},
{endNumber, contNumber, endNumber, endNumber, endNumber, endNumber, endNumber, endNumber, endNumber, endNumber, endNumber, endNumber, endNumber, endNumber, endNumber, endNumber, endNumber, endNumber, endNumber, endNumber, contNumber, endNumber},
{endNumber, contNumber, endNumber, endNumber, endNumber, endNumber, endNumber, endNumber, endNumber, endNumber, endNumber, endNumber, endNumber, endNumber, endNumber, endNumber, endNumber, endNumber, endNumber, endNumber, endNumber, endNumber},
{contId, contId, endId, endId, endId, endId, endId, endId, endId, endId, endId, endId, endId, endId, endId, endId, endId, endId, endId, endId, endId, endId},
{endAsignation, endAsignation, endAsignation, endAsignation, endAsignation, endAsignation, startEqual, endAsignation, endAsignation, endAsignation, endAsignation, endAsignation, endAsignation, endAsignation, endAsignation, endAsignation, endAsignation, endAsignation, endAsignation, endAsignation, endAsignation, endAsignation},
{endEqual, endEqual, endEqual, endEqual, endEqual, endEqual, endEqual, endEqual, endEqual, endEqual, endEqual, endEqual, endEqual, endEqual, endEqual, endEqual, endEqual, endEqual, endEqual, endEqual, endEqual, endEqual},
{endMultiplication, endMultiplication, endMultiplication, endMultiplication, endMultiplication, endMultiplication, startAutoMultiplication, endMultiplication, endMultiplication, endMultiplication, endMultiplication, endMultiplication, endMultiplication, endMultiplication, endMultiplication, endMultiplication, endMultiplication, endMultiplication, endMultiplication, endMultiplication, endMultiplication, endMultiplication},
{endAutoMultiplication, endAutoMultiplication, endAutoMultiplication, endAutoMultiplication, endAutoMultiplication, endAutoMultiplication, endAutoMultiplication, endAutoMultiplication, endAutoMultiplication, endAutoMultiplication, endAutoMultiplication, endAutoMultiplication, endAutoMultiplication, endAutoMultiplication, endAutoMultiplication, endAutoMultiplication, endAutoMultiplication, endAutoMultiplication, endAutoMultiplication, endAutoMultiplication, endAutoMultiplication, endAutoMultiplication},
{endSum, endSum, endSum, endSum, endSum, endSum, startAutoSum, endSum, endSum, endSum, endSum, endSum, endSum, endSum, endSum, endSum, endSum, endSum, endSum, endSum, endSum, endSum},
{endAutoSum, endAutoSum, endAutoSum, endAutoSum, endAutoSum, endAutoSum, endAutoSum, endAutoSum, endAutoSum, endAutoSum, endAutoSum, endAutoSum, endAutoSum, endAutoSum, endAutoSum, endAutoSum, endAutoSum, endAutoSum, endAutoSum, endAutoSum, endAutoSum, endAutoSum},
{endSubstraction, endSubstraction, endSubstraction, endSubstraction, endSubstraction, endSubstraction, startAutoSubstraction, endSubstraction, endSubstraction, endSubstraction, endSubstraction, endSubstraction, endSubstraction, endSubstraction, endSubstraction, endSubstraction, endSubstraction, endSubstraction, endSubstraction, endSubstraction, endSubstraction, endSubstraction},
{endAutoSubstraction, endAutoSubstraction, endAutoSubstraction, endAutoSubstraction, endAutoSubstraction, endAutoSubstraction, endAutoSubstraction, endAutoSubstraction, endAutoSubstraction, endAutoSubstraction, endAutoSubstraction, endAutoSubstraction, endAutoSubstraction, endAutoSubstraction, endAutoSubstraction, endAutoSubstraction, endAutoSubstraction, endAutoSubstraction, endAutoSubstraction, endAutoSubstraction, endAutoSubstraction, endAutoSubstraction},
{endLower, endLower, endLower, endLower, endLower, endLower, startEqualLower, endLower, endLower, endLower, endLower, endLower, endLower, endLower, endLower, endLower, endLower, endLower, endLower, endLower, endLower, endLower},
{endEqualLower, endEqualLower, endEqualLower, endEqualLower, endEqualLower, endEqualLower, endEqualLower, endEqualLower, endEqualLower, endEqualLower, endEqualLower, endEqualLower, endEqualLower, endEqualLower, endEqualLower, endEqualLower, endEqualLower, endEqualLower, endEqualLower, endEqualLower, endEqualLower, endEqualLower},
{endUpper, endUpper, endUpper, endUpper, endUpper, endUpper, startEqualUpper, endUpper, endUpper, endUpper, endUpper, endUpper, endUpper, endUpper, endUpper, endUpper, endUpper, endUpper, endUpper, endUpper, endUpper, endUpper},
{endEqualUpper, endEqualUpper, endEqualUpper, endEqualUpper, endEqualUpper, endEqualUpper, endEqualUpper, endEqualUpper, endEqualUpper, endEqualUpper, endEqualUpper, endEqualUpper, endEqualUpper, endEqualUpper, endEqualUpper, endEqualUpper, endEqualUpper, endEqualUpper, endEqualUpper, endEqualUpper, endEqualUpper, endEqualUpper},
{endNegation, endNegation, endNegation, endNegation, endNegation, endNegation, startNotEqual, endNegation, endNegation, endNegation, endNegation, endNegation, endNegation, endNegation, endNegation, endNegation, endNegation, endNegation, endNegation, endNegation, endNegation, endNegation},
{endNotEqual, endNotEqual, endNotEqual, endNotEqual, endNotEqual, endNotEqual, endNotEqual, endNotEqual, endNotEqual, endNotEqual, endNotEqual, endNotEqual, endNotEqual, endNotEqual, endNotEqual, endNotEqual, endNotEqual, endNotEqual, endNotEqual, endNotEqual, endNotEqual, endNotEqual},
{endBracket, endBracket, endBracket, endBracket, endBracket, endBracket, endBracket, endBracket, endBracket, endBracket, endBracket, endBracket, endBracket, endBracket, endBracket, endBracket, endBracket, endBracket, endBracket, endBracket, endBracket, endBracket},
{endRightBracket, endRightBracket, endRightBracket, endRightBracket, endRightBracket, endRightBracket, endRightBracket, endRightBracket, endRightBracket, endRightBracket, endRightBracket, endRightBracket, endRightBracket, endRightBracket, endRightBracket, endRightBracket, endRightBracket, endRightBracket, endRightBracket, endRightBracket, endRightBracket, endRightBracket},
{error, error, error, error, error, error, error, error, error, contOr, error, error, error, error, error, error, error, error, error, error, error, error},
{endOr, endOr, endOr, endOr, endOr, endOr, endOr, endOr, endOr, endOr, endOr, endOr, endOr, endOr, endOr, endOr, endOr, endOr, endOr, endOr, endOr, endOr},
{error, error, error, error, error, error, error, error, contAnd, error, error, error, error, error, error, error, error, error, error, error, error, error},
{endAnd, endAnd, endAnd, endAnd, endAnd, endAnd, endAnd, endAnd, endAnd, endAnd, endAnd, endAnd, endAnd, endAnd, endAnd, endAnd, endAnd, endAnd, endAnd, endAnd, endAnd, endAnd},
{endBrace, endBrace, endBrace, endBrace, endBrace, endBrace, endBrace, endBrace, endBrace, endBrace, endBrace, endBrace, endBrace, endBrace, endBrace, endBrace, endBrace, endBrace, endBrace, endBrace, endBrace, endBrace},
{endRightBrace, endRightBrace, endRightBrace, endRightBrace, endRightBrace, endRightBrace, endRightBrace, endRightBrace, endRightBrace, endRightBrace, endRightBrace, endRightBrace, endRightBrace, endRightBrace, endRightBrace, endRightBrace, endRightBrace, endRightBrace, endRightBrace, endRightBrace, endRightBrace, endRightBrace},
{endSemicolon, endSemicolon, endSemicolon, endSemicolon, endSemicolon, endSemicolon, endSemicolon, endSemicolon, endSemicolon, endSemicolon, endSemicolon, endSemicolon, endSemicolon, endSemicolon, endSemicolon, endSemicolon, endSemicolon, endSemicolon, endSemicolon, endSemicolon, endSemicolon, endSemicolon},
{endSeparator, endSeparator, endSeparator, endSeparator, endSeparator, endSeparator, endSeparator, endSeparator, endSeparator, endSeparator, endSeparator, endSeparator, endSeparator, endSeparator, endSeparator, endSeparator, endSeparator, endSeparator, endSeparator, endSeparator, endSeparator, endSeparator},
{endComma, endComma, endComma, endComma, endComma, endComma, endComma, endComma, endComma, endComma, endComma, endComma, endComma, endComma, endComma, endComma, endComma, endComma, endComma, endComma, endComma, endComma},
{endDivision, endDivision, endDivision, endDivision, startComment, endDivision, startAutoDivision, endDivision, endDivision, endDivision, endDivision, endDivision, endDivision, endDivision, endDivision, endDivision, endDivision, endDivision, endDivision, endDivision, endDivision, endDivision},
{endAutoDivision, endAutoDivision, endAutoDivision, endAutoDivision, endAutoDivision, endAutoDivision, endAutoDivision, endAutoDivision, endAutoDivision, endAutoDivision, endAutoDivision, endAutoDivision, endAutoDivision, endAutoDivision, endAutoDivision, endAutoDivision, endAutoDivision, endAutoDivision, endAutoDivision, endAutoDivision, endAutoDivision, endAutoDivision},
{nothing, nothing, nothing, nothing, nothing, nothing, nothing, nothing, nothing, nothing, nothing, nothing, nothing, nothing, nothing, nothing, nothing, nothing, nothing, nothing, nothing, nothing},
{nothing, nothing, nothing, nothing, nothing, nothing, nothing, nothing, nothing, nothing, nothing, nothing, nothing, nothing, nothing, nothing, nothing, nothing, nothing, nothing, nothing, nothing}};



FILE *archivo;
int yylex();

struct simbolo{
	char nombre[30];
	int tipo;
	int posicion;
	simbolo *siguiente;
};

simbolo * tablaSimbolos = NULL;

char valor[30];

#line 225 "y.tab.cpp"
#define ID 257
#define NUMBER 258
#define SUM 259
#define SUBSTRACTION 260
#define MULTIPLICATION 261
#define DIVISION 262
#define AUTOSUM 263
#define AUTOSUBSTRACTION 264
#define AUTOMULTIPLICATION 265
#define AUTODIVISION 266
#define ASIGNATION 267
#define NEGATION 268
#define AND 269
#define OR 270
#define STRING 271
#define SEMICOLON 272
#define COMMA 273
#define SEPARATOR 274
#define LOWER 275
#define UPPER 276
#define BRACKET 277
#define RIGHTBRACKET 278
#define BRACE 279
#define RIGHTBRACE 280
#define EQUAL 281
#define EQUALLOWER 282
#define EQUALUPPER 283
#define NOTEQUAL 284
#define COMMENT 285
#define IF 286
#define ELSE 287
#define WHILE 288
#define DEFINE 289
#define DISPLAY 290
#define TYPEFLOAT 291
#define TYPESTRING 292
#define REPEAT 293
#define UNTIL 294
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    0,    2,    2,    3,    3,    3,    3,    3,    3,
   10,   10,   10,   10,   10,   11,   11,   12,   13,   13,
   13,   13,    6,    6,    4,    5,    5,    5,    5,   14,
   14,   14,   15,   15,   15,   17,   17,   16,   16,   16,
   18,   18,   19,   19,    1,    7,    8,    9,
};
static const short yylen[] = {                            2,
    2,    1,    1,    2,    2,    2,    1,    1,    1,    2,
    1,    1,    1,    1,    1,    1,    1,    3,    2,    3,
    3,    3,    7,   11,    3,    3,    3,    3,    3,    3,
    3,    1,    3,    3,    1,    1,    1,    1,    1,    3,
    1,    3,    4,    5,    4,    7,    8,    2,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    3,
    0,    0,    7,    8,    9,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   48,    0,    0,    4,    5,    6,
   10,   38,   39,    0,    0,    0,   35,    0,    0,    0,
    0,    0,    0,    0,   17,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   19,    0,    0,    0,
    0,   11,   12,   15,   13,   14,    0,    0,    0,    0,
   45,    0,    0,   40,    0,    0,   33,   34,    0,   22,
   21,   20,    0,    0,   42,   37,   36,    0,    0,    0,
    0,    0,   43,    0,    0,    0,   46,   44,    0,    0,
   47,    0,    0,   24,
};
static const short yydgoto[] = {                          7,
    8,    9,   10,   11,   12,   13,   14,   15,   16,   67,
   43,   44,   45,   46,   36,   37,   88,   49,   50,
};
static const short yysindex[] = {                      -245,
 -149, -258, -237, -251, -212, -218,    0, -223, -223,    0,
 -200, -198,    0,    0,    0, -196, -231, -231, -231, -231,
 -231, -219, -219, -176,    0, -223, -223,    0,    0,    0,
    0,    0,    0, -231, -249, -239,    0, -249, -249, -249,
 -249, -231, -186, -132,    0, -246, -185, -178, -172, -248,
 -233, -175, -231, -231, -231, -231,    0, -181, -231, -231,
 -231,    0,    0,    0,    0,    0, -231, -174, -176, -240,
    0, -167, -171,    0, -239, -239,    0,    0, -223,    0,
    0,    0, -249, -223,    0,    0,    0, -163, -240, -158,
 -224, -189,    0, -147, -219, -161,    0,    0, -139, -150,
    0, -223, -180,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,  143,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  145,    0,    0,    0,
    0,    0,    0,    0, -126, -148,    0, -123, -116, -200,
 -115,    0,    0, -120,    0,    0,    0, -111,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -128, -108,    0,    0,    0,    0,
    0,    0, -253,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    1,    0,    0,    0,    0,
    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
    0,   -6,   -9,    0,    0,    0,    0,    0,    0,    0,
  -20,   29,    0,  -13,   26,   31,   70,  -19,    0,
};
#define YYTABLESIZE 294
static const short yytable[] = {                         28,
   23,   27,   47,   35,   38,   39,   40,   41,   48,   53,
   54,    1,   53,   54,   18,   18,   18,   28,   22,   51,
   52,   55,   56,    1,   18,   32,   33,   24,   62,   63,
   72,   71,    1,    1,   64,   65,   66,   32,   33,   23,
    2,   28,    3,    4,    5,   34,   73,    6,   42,   85,
   86,   87,    2,   83,    3,   96,    5,   34,   25,    6,
   26,    2,    2,    3,    3,    5,    5,    1,    6,    6,
   57,   29,   91,   30,   99,   31,    1,   92,   75,   76,
   48,   28,   28,   53,   54,   77,   78,   80,   81,   82,
   97,   58,   68,   28,   69,  103,    2,   79,    3,  104,
    5,   70,   74,    6,   84,    2,   89,    3,   93,    5,
   32,   32,    6,   17,   18,   19,   20,   21,   95,   32,
   32,   32,   90,   32,   98,  100,   32,   32,  102,   32,
   30,   30,   32,   32,   32,   59,   60,   61,  101,   30,
   30,   30,    2,   30,    1,   26,   30,   30,   27,   30,
   31,   31,   30,   30,   30,   28,   25,   16,   94,   31,
   31,   31,   41,   31,    0,    0,   31,   31,    0,   31,
    0,    0,   31,   31,   31,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   23,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   23,    0,    0,    0,    0,    0,   23,    0,   23,    0,
   23,    0,    0,   23,
};
static const short yycheck[] = {                          9,
    0,    8,   23,   17,   18,   19,   20,   21,  257,  259,
  260,  257,  259,  260,  268,  269,  270,   27,  277,   26,
   34,  261,  262,  257,  278,  257,  258,  279,  275,  276,
   50,  280,  257,  257,  281,  282,  283,  257,  258,  277,
  286,   51,  288,  289,  290,  277,  280,  293,  268,   69,
  291,  292,  286,   67,  288,  280,  290,  277,  271,  293,
  279,  286,  286,  288,  288,  290,  290,  257,  293,  293,
   42,  272,   79,  272,   95,  272,  257,   84,   53,   54,
  257,   91,   92,  259,  260,   55,   56,   59,   60,   61,
  280,  278,  278,  103,  273,  102,  286,  279,  288,  280,
  290,  274,  278,  293,  279,  286,  274,  288,  272,  290,
  259,  260,  293,  263,  264,  265,  266,  267,  277,  268,
  269,  270,  294,  272,  272,  287,  275,  276,  279,  278,
  259,  260,  281,  282,  283,  268,  269,  270,  278,  268,
  269,  270,    0,  272,    0,  272,  275,  276,  272,  278,
  259,  260,  281,  282,  283,  272,  272,  278,   89,  268,
  269,  270,  274,  272,   -1,   -1,  275,  276,   -1,  278,
   -1,   -1,  281,  282,  283,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  280,   -1,   -1,   -1,   -1,   -1,  286,   -1,  288,   -1,
  290,   -1,   -1,  293,
};
#define YYFINAL 7
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 294
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"ID","NUMBER","SUM",
"SUBSTRACTION","MULTIPLICATION","DIVISION","AUTOSUM","AUTOSUBSTRACTION",
"AUTOMULTIPLICATION","AUTODIVISION","ASIGNATION","NEGATION","AND","OR","STRING",
"SEMICOLON","COMMA","SEPARATOR","LOWER","UPPER","BRACKET","RIGHTBRACKET",
"BRACE","RIGHTBRACE","EQUAL","EQUALLOWER","EQUALUPPER","NOTEQUAL","COMMENT",
"IF","ELSE","WHILE","DEFINE","DISPLAY","TYPEFLOAT","TYPESTRING","REPEAT",
"UNTIL",
};
static const char *yyrule[] = {
"$accept : programa",
"programa : bloque_declaracion cuerpo",
"programa : cuerpo",
"cuerpo : sentencia",
"cuerpo : cuerpo sentencia",
"sentencia : asig SEMICOLON",
"sentencia : asig_especial SEMICOLON",
"sentencia : desicion",
"sentencia : mientras",
"sentencia : ciclo_hasta",
"sentencia : escribir SEMICOLON",
"comp_logico : LOWER",
"comp_logico : UPPER",
"comp_logico : EQUALLOWER",
"comp_logico : EQUALUPPER",
"comp_logico : EQUAL",
"condicion : condicionsimple",
"condicion : condicionmultiple",
"condicionsimple : exp comp_logico exp",
"condicionmultiple : NEGATION condicionsimple",
"condicionmultiple : condicionsimple OR condicionsimple",
"condicionmultiple : condicionsimple AND condicionsimple",
"condicionmultiple : condicionsimple NEGATION condicionsimple",
"desicion : IF BRACKET condicion RIGHTBRACKET BRACE cuerpo RIGHTBRACE",
"desicion : IF BRACKET condicion RIGHTBRACKET BRACE cuerpo RIGHTBRACE ELSE BRACE cuerpo RIGHTBRACE",
"asig : ID ASIGNATION exp",
"asig_especial : ID AUTOSUM exp",
"asig_especial : ID AUTOSUBSTRACTION exp",
"asig_especial : ID AUTOMULTIPLICATION exp",
"asig_especial : ID AUTODIVISION exp",
"exp : exp SUM termino",
"exp : exp SUBSTRACTION termino",
"exp : termino",
"termino : termino MULTIPLICATION factor",
"termino : termino DIVISION factor",
"termino : factor",
"tipo_dato : TYPESTRING",
"tipo_dato : TYPEFLOAT",
"factor : ID",
"factor : NUMBER",
"factor : BRACKET exp RIGHTBRACKET",
"lista_variables : ID",
"lista_variables : ID COMMA lista_variables",
"declaracion : lista_variables SEPARATOR tipo_dato SEMICOLON",
"declaracion : declaracion lista_variables SEPARATOR tipo_dato SEMICOLON",
"bloque_declaracion : DEFINE BRACE declaracion RIGHTBRACE",
"mientras : WHILE BRACKET condicion RIGHTBRACKET BRACE cuerpo RIGHTBRACE",
"ciclo_hasta : REPEAT BRACE cuerpo RIGHTBRACE UNTIL BRACKET condicion RIGHTBRACKET",
"escribir : DISPLAY STRING",

};
#endif
#ifndef YYSTYPE
typedef int YYSTYPE;
#endif
#if YYDEBUG
#include <stdio.h>
#endif

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

int      yydebug;
int      yynerrs;
int      yyerrflag;
int      yychar;
short   *yyssp;
YYSTYPE *yyvsp;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* variables for the parser stack */
static short   *yyss;
static short   *yysslim;
static YYSTYPE *yyvs;
static unsigned yystacksize;
#line 320 "yacc.y"

/* CODIGO */


int get_evento (char c){
    //aca deberia hacerse un if por cada columna en la tabla de funciones que retorne el numero para el evneto correspondiente
    if((c >= 'a' && c<= 'z') || (c>='A' && c <= 'Z')) //letra
    {
        return 0;
    }else if(c >= '0' && c <= '9')
    {
        return 1;
    }else if(c == '+')
    {
        return 2;
    }else if(c == '-')
    {
        return 3;
    }else if(c == '*')
    {
        return 4;
    }else if(c == '/')
    {
        return 5;
    }else if(c == '=')
    {
        return 6;
    }else if(c == '!')
    {
        return 7;
    }else if(c == '&')
    {
        return 8;
    }else if(c == '|')
    {
        return 9;
    }else if(c == '"')
    {
        return 10;
    }else if(c == ';')
    {
        return 11;
    }else if(c == ',')
    {
        return 12;
    }else if(c == ':')
    {
        return 13;
    }else if(c == '<')
    {
        return 14;
    }else if(c == '>')
    {
        return 15;
    }else if(c == '(')
    {
        return 16;
    }else if(c == ')')
    {
        return 17;
    }else if(c == '{')
    {
        return 18;
    }else if(c == '}')
    {
        return 19;
    }else if(c == '.')
    {
        return 20;
    }else if(c == ' ' || c == '\n' || c == '\t' || feof(archivo))
    {
        return 21;
    }else{
        printf("\nError de sintaxis: caracter no valido '%c'\n",c);
        exit(1);
    }
}



int yylex(){
    int columna = 0 ;
	int estado = 0;
	int estado_final = CANT_ESTADOS - 1;
	int token = -1;
    char c;
    //mientras el estado sea distinto del final y no se de que estamos en el estado inicial y el archivo llego a su fin entonces iteramos sobre los estados
	while (estado != estado_final  && !feof(archivo))
    {
        c = fgetc(archivo);
        columna = get_evento(c);
        token = (*funciones[estado][columna])(c);
        estado = nuevo_estado [estado] [columna];
    }

	if(feof(archivo)){
		if(estado == 0){
			return -1;
		}else if(estado != estado_final){
			printf("Error de sintaxis, fin del archivo inesperado\n");
			exit(1);
		}else{
			return token;
		}
	}

	if(token != STRING){
		//se retorna el ultimo caracter leido al archivo porque no forma parte
		//de este token. Salvo cuando el token es un string (la ultima comilla no debe volver al archivo)
		ungetc(c,archivo);
	}

    return token;
}

int searchSimbol(char * name, int tipo){
	simbolo * actual;
	actual = tablaSimbolos;
	while(actual != NULL && !(strcmp(actual->nombre,name) == 0 && (actual->tipo == tipo))){
		actual = actual->siguiente;
	}
	if(actual != NULL){
		return actual->posicion;
	}else{
		return -1;
	}
}

int addToSimbolTable(char * name, int tipo){
	//agrega un nuevo simbolo a la lista
	simbolo * nuevo = new simbolo;
	strcpy(nuevo->nombre,name);
	nuevo->tipo = tipo;
	nuevo->siguiente = tablaSimbolos;
	if(tablaSimbolos != NULL){
		nuevo->posicion = tablaSimbolos->posicion + 1;
	}else{
		nuevo->posicion = 0;
	}
	tablaSimbolos = nuevo;
	return nuevo->posicion;
}

int startId(char c){
	memset(valor,'\0',sizeof(valor));
	valor[strlen(valor)] = c;
    return 0;
}
int startNumber(char c){
	memset(valor,'\0',sizeof(valor));
	valor[strlen(valor)] = c;
    return 0;
}
int startSum(char c){
	yyval = -1;
    return 0;

}
int startSubstraction(char c){
	yyval = -1;
    return 0;
}
int startMultiplication(char c){
	yyval = -1;
    return 0;
}
int startDivision(char c){
	yyval = -1;
    return 0;
}
int startAutoSum(char c){
	yyval = -1;
    return 0;
}
int startAutoSubstraction(char c){
	yyval = -1;
    return 0;
}
int startAutoMultiplication(char c){
	yyval = -1;
    return 0;
}
int startAutoDivision(char c){
	yyval = -1;
    return 0;
}
int startAsignation(char c){
	yyval = -1;
    return 0;
}
int startNegation(char c){
	yyval = -1;
    return 0;
}
int startAnd(char c){
	yyval = -1;
    return 0;
}
int startOr(char c){
	yyval = -1;
    return 0;
}
int startString(char c){
	memset(valor,'\0',sizeof(valor));
    return 0;
}
int startSemicolon(char c){
	yyval = -1;
    return 0;
}
int startComma(char c){
	yyval = -1;
    return 0;
}
int startSeparator(char c){
	yyval = -1;
    return 0;
}
int startLower(char c){
	yyval = -1;
    return 0;
}
int startUpper(char c){
	yyval = -1;
    return 0;
}
int startBracket(char c){
	yyval = -1;
    return 0;
}
int startRightBracket(char c){
	yyval = -1;
    return 0;
}
int startBrace(char c){
	yyval = -1;
    return 0;
}
int startRightBrace(char c){
	yyval = -1;
    return 0;
}
int startEqual(char c){
	yyval = -1;
    return 0;
}
int startEqualLower(char c){
	yyval = -1;
    return 0;
}
int startEqualUpper(char c){
	yyval = -1;
    return 0;
}
int startNotEqual(char c){
	yyval = -1;
    return 0;
}
int startComment(char c){
	yyval = -1;
    return 0;
}
int contId(char c){
	if(strlen(valor) <= 30){
		valor[strlen(valor)] = c;
		return 0;
	}else{
		printf("\nError de sintaxis: identificador demasiado largo %s... solo se permiten 30 caracteres\n",valor);
		exit(1);
	}
}
int contNumber(char c){
	valor[strlen(valor)] = c;
    return 0;
}
int contSum(char c){
    return 0;
}
int contSubstraction(char c){
    return 0;
}
int contMultiplication(char c){
    return 0;
}
int contDivision(char c){
    return 0;
}
int contAutoSum(char c){
    return 0;
}
int contAutoSubstraction(char c){
    return 0;
}
int contAutoMultiplication(char c){
    return 0;
}
int contAutoDivision(char c){
    return 0;
}
int contAsignation(char c){
    return 0;
}
int contNegation(char c){
    return 0;
}
int contAnd(char c){
    return 0;
}
int contOr(char c){
    return 0;
}
int contString(char c){
	if(strlen(valor) <= 30){
		valor[strlen(valor)] = c;
		return 0;
	}else{
		printf("\nError de sintaxis: string demasiado largo %s... solo se permiten 30 caracteres\n",valor);
		exit(1);
	}
}
int contSemicolon(char c){
    return 0;
}
int contComma(char c){
    return 0;
}
int contSeparator(char c){
    return 0;
}
int contLower(char c){
    return 0;
}
int contUpper(char c){
    return 0;
}
int contBracket(char c){
    return 0;
}
int contRightBracket(char c){
    return 0;
}
int contBrace(char c){
    return 0;
}
int contRightBrace(char c){
    return 0;
}
int contEqual(char c){
    return 0;
}
int contEqualLower(char c){
    return 0;
}
int contEqualUpper(char c){
    return 0;
}
int contNotEqual(char c){
    return 0;
}
int contComment(char c){
    return 0;
}
int endId(char c){
	if(!reservedWord(valor)){
		//identificador
		int tipoToken = ID;
		if((yyval = searchSimbol(valor,tipoToken)) == -1){
			yyval = addToSimbolTable(valor,tipoToken);
		}
		return tipoToken;
	}else{
		//palabra reservada
		int tipoToken = reservedWord(valor);
		return tipoToken;
	}
}
int endNumber(char c){
    if((yyval = searchSimbol(valor,2)) == -1){
        yyval = addToSimbolTable(valor,2);
    }
    return NUMBER;
}
int endSum(char c){
    return SUM;
}
int endSubstraction(char c){
    return SUBSTRACTION;
}
int endMultiplication(char c){
    return MULTIPLICATION;
}
int endDivision(char c){
    return DIVISION;
}
int endAutoSum(char c){
    return AUTOSUM;
}
int endAutoSubstraction(char c){
    return AUTOSUBSTRACTION;
}
int endAutoMultiplication(char c){
    return AUTOMULTIPLICATION;
}
int endAutoDivision(char c){
    return AUTODIVISION;
}
int endAsignation(char c){
    return ASIGNATION;
}
int endNegation(char c){
    return NEGATION;
}
int endAnd(char c){
    return AND;
}
int endOr(char c){
    return OR;
}
int endString(char c){
	int tipoToken = STRING;
	if((yyval = searchSimbol(valor,tipoToken)) == -1){
		yyval = addToSimbolTable(valor,tipoToken);
	}
    return tipoToken;
}
int endSemicolon(char c){
    return SEMICOLON;
}
int endComma(char c){
    return COMMA;
}
int endSeparator(char c){
    return SEPARATOR;
}
int endLower(char c){
    return LOWER;
}
int endUpper(char c){
    return UPPER;
}
int endBracket(char c){
    return BRACKET;
}
int endRightBracket(char c){
    return RIGHTBRACKET;
}
int endBrace(char c){
    return BRACE;
}
int endRightBrace(char c){
    return RIGHTBRACE;
}
int endEqual(char c){
    return EQUAL;
}
int endEqualLower(char c){
    return EQUALLOWER;
}
int endEqualUpper(char c){
    return EQUALUPPER;
}
int endNotEqual(char c){
    return NOTEQUAL;
}
int endComment(char c){
    return COMMENT;
}
int error(char c){
	printf("\nError de sintaxis: caracter no esperado '%c'\n",c);
	exit(1);
    return -1;
}

int nothing(char c){
	return -1;
}

int reservedWord(char * id){
	if(strcmp(id,"if") == 0){
		return IF;
	}else if(strcmp(id,"else") == 0){
		return ELSE;
	}else if(strcmp(id,"while") == 0){
		return WHILE;
    }else if(strcmp(id,"repeat") == 0){
		return REPEAT;
    }else if(strcmp(id,"until") == 0){
		return UNTIL;
    }else if(strcmp(id,"define") == 0){
		return DEFINE;
	}else if(strcmp(id,"display") == 0){
		return DISPLAY;
	}else if(strcmp(id,"float") == 0){
		return TYPEFLOAT;
	}else if(strcmp(id,"string") == 0){
		return TYPESTRING;
	}else{
		return 0;
	}
}


void yyerror(char *s)
{
    fprintf(stderr,"%s\n",s);
    return;
}


int main(int argc,char * argv[])
{
	printf("Bienvenido al compilador: acua\n");
    if(argc != 2){
        printf("\nDebe pasar el nombre del archivo como parametro\n");
        exit(1);
    }
    if((archivo = fopen(argv[1],"r")) == NULL){
        printf("\nEl archivo %s no existe\n",argv[1]);
        exit(1);
    }

    int tipoToken;
    //while(!feof(archivo)){
        yyparse();
    //}

    fclose(archivo);

    return 0;
}


#line 1035 "y.tab.cpp"
/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(void)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = yystacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = yyssp - yyss;
    newss = (yyss != 0)
          ? (short *)realloc(yyss, newsize * sizeof(*newss))
          : (short *)malloc(newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    yyss  = newss;
    yyssp = newss + i;
    newvs = (yyvs != 0)
          ? (YYSTYPE *)realloc(yyvs, newsize * sizeof(*newvs))
          : (YYSTYPE *)malloc(newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    yyvs = newvs;
    yyvsp = newvs + i;
    yystacksize = newsize;
    yysslim = yyss + newsize - 1;
    return 0;
}

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

    if (yyss == NULL && yygrowstack()) goto yyoverflow;
    yyssp = yyss;
    yyvsp = yyvs;
    yystate = 0;
    *yyssp = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yyssp >= yysslim && yygrowstack())
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yyssp = yytable[yyn];
        *++yyvsp = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

#ifdef lint
    goto yyerrlab;
#endif

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yysslim && yygrowstack())
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yyssp = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yyvsp[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 248 "yacc.y"
	{printf( "Reconocido el programa :)\n");}
break;
case 2:
#line 249 "yacc.y"
	{printf( "Reconocido el programa :)\n");}
break;
case 3:
#line 251 "yacc.y"
	{printf( "Reconocido el cuerpo\n");}
break;
case 16:
#line 267 "yacc.y"
	{printf( "Reconocida una condicion simple\n");}
break;
case 17:
#line 268 "yacc.y"
	{printf( "Reconocida una condicion multiple\n");}
break;
case 18:
#line 270 "yacc.y"
	{printf( "");}
break;
case 19:
#line 272 "yacc.y"
	{printf( "");}
break;
case 20:
#line 273 "yacc.y"
	{printf( "");}
break;
case 21:
#line 274 "yacc.y"
	{printf( "");}
break;
case 22:
#line 275 "yacc.y"
	{printf( "");}
break;
case 23:
#line 277 "yacc.y"
	{printf( "Reconocido un if\n");}
break;
case 24:
#line 278 "yacc.y"
	{printf( "Reconocido un if\n");}
break;
case 25:
#line 280 "yacc.y"
	{printf( "Reconocida una asignacion\n");}
break;
case 26:
#line 282 "yacc.y"
	{printf( "Reconocida una asignacion especial\n");}
break;
case 27:
#line 283 "yacc.y"
	{printf( "Reconocida una asignacion especial\n");}
break;
case 28:
#line 284 "yacc.y"
	{printf( "Reconocida una asignacion especial\n");}
break;
case 29:
#line 285 "yacc.y"
	{printf( "Reconocida una asignacion especial\n");}
break;
case 30:
#line 287 "yacc.y"
	{printf( "Reconocida una suma\n");}
break;
case 31:
#line 289 "yacc.y"
	{printf( "Reconocida una resta\n");}
break;
case 32:
#line 291 "yacc.y"
	{printf( "");}
break;
case 33:
#line 293 "yacc.y"
	{printf( "");}
break;
case 34:
#line 295 "yacc.y"
	{printf( "");}
break;
case 35:
#line 297 "yacc.y"
	{printf( "");}
break;
case 38:
#line 301 "yacc.y"
	{printf( "");}
break;
case 39:
#line 302 "yacc.y"
	{printf( "");}
break;
case 40:
#line 303 "yacc.y"
	{printf( "");}
break;
case 41:
#line 305 "yacc.y"
	{printf( "");}
break;
case 42:
#line 306 "yacc.y"
	{printf( "");}
break;
case 43:
#line 308 "yacc.y"
	{printf( "");}
break;
case 44:
#line 309 "yacc.y"
	{printf( "");}
break;
case 45:
#line 311 "yacc.y"
	{printf( "Reconocido un bloque de declaracion\n");}
break;
case 46:
#line 313 "yacc.y"
	{printf( "Reconocido un while\n");}
break;
case 47:
#line 315 "yacc.y"
	{printf( "Reconocido un Until\n");}
break;
case 48:
#line 317 "yacc.y"
	{printf( "Reconocido un display\n");}
break;
#line 1358 "y.tab.cpp"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yysslim && yygrowstack())
    {
        goto yyoverflow;
    }
    *++yyssp = (short) yystate;
    *++yyvsp = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    return (1);

yyaccept:
    return (0);
}
