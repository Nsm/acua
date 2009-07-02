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
#define CUERPO 1
#define PROGRAMA 2

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

simbolo * getSimbolo(int id);

char valor[30];

struct nodo{
	int identificador;
	bool simbolo;
	nodo *derecha;
	nodo *izquierda;
};

nodo* programa, *cuerpo, *sentencia, *condicion, *condicionsimple,*condicionmultiple, *desicion, *asig, *asig_especial, *exp, *termino, *tipo_dato, *factor, *lista_variables, *declaracion ,*bloque_declaracion, *mientras,*ciclo_hasta,*escribir;

nodo * crearNodo(int operacion, nodo * izquierda, nodo * derecha);
nodo * crearHoja(int numeroSimbolo);

#line 241 "y.tab.cpp"
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
   10,   10,   11,   11,   11,   11,   11,   12,   12,   12,
   12,    6,    6,    4,    5,    5,    5,    5,   13,   13,
   13,   14,   14,   14,   16,   16,   15,   15,   15,   17,
   17,   18,   18,    1,    7,    8,    9,
};
static const short yylen[] = {                            2,
    2,    1,    1,    2,    2,    2,    1,    1,    1,    2,
    1,    1,    3,    3,    3,    3,    3,    2,    3,    3,
    3,    7,   11,    3,    3,    3,    3,    3,    3,    3,
    1,    3,    3,    1,    1,    1,    1,    1,    3,    1,
    3,    4,    5,    4,    7,    8,    2,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    3,
    0,    0,    7,    8,    9,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   47,    0,    0,    4,    5,    6,
   10,   37,   38,    0,    0,    0,   34,    0,    0,    0,
    0,    0,    0,    0,   12,    0,    0,   40,    0,    0,
    0,    0,    0,    0,    0,    0,   18,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   44,
    0,    0,   39,    0,    0,   32,   33,    0,   21,   20,
   19,    0,    0,    0,    0,    0,    0,   41,   36,   35,
    0,    0,    0,    0,    0,   42,    0,    0,    0,   45,
   43,    0,    0,   46,    0,    0,   23,
};
static const short yydgoto[] = {                          7,
    8,    9,   10,   11,   12,   13,   14,   15,   16,   43,
   44,   45,   46,   36,   37,   91,   49,   50,
};
static const short yysindex[] = {                      -245,
 -241, -268, -266, -262, -252, -221,    0, -198, -198,    0,
 -206, -202,    0,    0,    0, -192, -201, -201, -201, -201,
 -201, -230, -230, -170,    0, -198, -198,    0,    0,    0,
    0,    0,    0, -201, -220, -188,    0, -220, -220, -220,
 -220, -201, -189, -157,    0, -246, -185,    0, -190, -247,
 -226, -244, -201, -201, -201, -201,    0, -183, -201, -201,
 -201, -201, -201, -201, -201, -201, -181, -156, -172,    0,
 -108, -191,    0, -188, -188,    0,    0, -198,    0,    0,
    0, -220, -220, -220, -220, -220, -198,    0,    0,    0,
 -155, -172, -144, -225, -211,    0, -149, -230, -150,    0,
    0, -139, -136,    0, -198, -186,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,  153,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  157,    0,    0,    0,
    0,    0,    0,    0, -113, -154,    0, -109,  -93,  -85,
  -84,    0,    0,  -89,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -134, -114,    0,    0,    0,    0,    0,
    0, -138, -118,  -98,  -95,  -92,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    1,    0,
    0,    0,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
    0,   -6,   -9,    0,    0,    0,    0,    0,    0,  -20,
   49,    0,  -13,  128,  129,   98,  141,    0,
};
#define YYTABLESIZE 294
static const short yytable[] = {                         28,
   22,   27,   47,   35,   38,   39,   40,   41,   22,   48,
   23,    1,   53,   54,   53,   54,   24,   28,   25,   51,
   52,   17,   18,   19,   20,   21,   32,   33,   62,   63,
    1,    1,   70,   73,   64,   65,   66,   42,   53,   54,
    2,   28,    3,    4,    5,    1,   34,    6,   82,   83,
   84,   85,   86,   72,   99,   32,   33,   26,    1,    2,
    2,    3,    3,    5,    5,   29,    6,    6,  100,   30,
    1,   94,   55,   56,    2,   34,    3,  102,    5,   31,
   95,    6,   68,   69,   28,   28,   48,    2,   58,    3,
   57,    5,   67,  107,    6,   78,   28,   87,  106,    2,
   88,    3,   93,    5,   31,   31,    6,   79,   80,   81,
   59,   60,   61,   31,   31,   31,   96,   31,   89,   90,
   31,   31,  101,   31,   29,   29,   31,   31,   31,   13,
   13,   13,   98,   29,   29,   29,  103,   29,  104,   13,
   29,   29,  105,   29,   30,   30,   29,   29,   29,   14,
   14,   14,    2,   30,   30,   30,    1,   30,   25,   14,
   30,   30,   26,   30,   68,   92,   30,   30,   30,   17,
   17,   17,   15,   15,   15,   16,   16,   16,   27,   17,
   74,   75,   15,   76,   77,   16,   28,   24,   11,   97,
   71,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   22,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   22,    0,    0,    0,    0,    0,   22,    0,   22,    0,
   22,    0,    0,   22,
};
static const short yycheck[] = {                          9,
    0,    8,   23,   17,   18,   19,   20,   21,  277,  257,
  277,  257,  259,  260,  259,  260,  279,   27,  271,   26,
   34,  263,  264,  265,  266,  267,  257,  258,  275,  276,
  257,  257,  280,  278,  281,  282,  283,  268,  259,  260,
  286,   51,  288,  289,  290,  257,  277,  293,   62,   63,
   64,   65,   66,  280,  280,  257,  258,  279,  257,  286,
  286,  288,  288,  290,  290,  272,  293,  293,  280,  272,
  257,   78,  261,  262,  286,  277,  288,   98,  290,  272,
   87,  293,  273,  274,   94,   95,  257,  286,  278,  288,
   42,  290,  278,  280,  293,  279,  106,  279,  105,  286,
  257,  288,  294,  290,  259,  260,  293,   59,   60,   61,
  268,  269,  270,  268,  269,  270,  272,  272,  291,  292,
  275,  276,  272,  278,  259,  260,  281,  282,  283,  268,
  269,  270,  277,  268,  269,  270,  287,  272,  278,  278,
  275,  276,  279,  278,  259,  260,  281,  282,  283,  268,
  269,  270,    0,  268,  269,  270,    0,  272,  272,  278,
  275,  276,  272,  278,  273,  274,  281,  282,  283,  268,
  269,  270,  268,  269,  270,  268,  269,  270,  272,  278,
   53,   54,  278,   55,   56,  278,  272,  272,  278,   92,
   50,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
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
"condicion : condicionsimple",
"condicion : condicionmultiple",
"condicionsimple : exp LOWER exp",
"condicionsimple : exp UPPER exp",
"condicionsimple : exp EQUALLOWER exp",
"condicionsimple : exp EQUALUPPER exp",
"condicionsimple : exp EQUAL exp",
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
"lista_variables : lista_variables COMMA ID",
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
#line 335 "yacc.y"

/* CODIGO */

nodo * crearNodo(int operacion, nodo * izquierda, nodo * derecha){
	nodo * nuevoNodo = new nodo;
	nuevoNodo->izquierda = izquierda;
	nuevoNodo->derecha = derecha;
	nuevoNodo->identificador = operacion;
	nuevoNodo->simbolo = false;
	return nuevoNodo;
}

nodo * crearHoja(int numeroSimbolo){
	nodo * nuevoNodo = new nodo;
	nuevoNodo->izquierda = NULL;
	nuevoNodo->derecha = NULL;
	nuevoNodo->identificador = numeroSimbolo;
	nuevoNodo->simbolo = true;
	return nuevoNodo;
}

//Funcion auxiliar para mejorar el debug
char* getTypeString(int tipoToken){
	switch (tipoToken) {
		case ID:
			return "Id";
			break;
		case NUMBER:
			return "Number";
			break;
		case SUM:
			return "Sum (+)";
			break;
		case SUBSTRACTION:
			return "Substraction (-)";
			break;
		case MULTIPLICATION:
			return "Multiplication (*)";
			break;
		case DIVISION:
			return "Division (/)";
			break;
		case AUTOSUM:
			return "AutoSum (+=)";
			break;
		case AUTOSUBSTRACTION:
			return "AutoSubstraction (-=)";
			break;
		case AUTOMULTIPLICATION:
			return "AutoMultiplication (*=)";
			break;
		case AUTODIVISION:
			return "AutoDivision (/=)";
			break;
		case ASIGNATION:
			return "Asignation (=)";
			break;
		case NEGATION:
			return "Negation (!=)";
			break;
		case AND:
			return "And (&&)";
			break;
		case OR:
			return "Or (||)";
			break;
		case STRING:
			return "String";
			break;
		case SEMICOLON:
			return "Semicolon (;)";
			break;
		case COMMA:
			return "Comma (,)";
			break;
		case SEPARATOR:
			return "Separator (:)";
			break;
		case LOWER:
			return "Lower (<)";
			break;
		case UPPER:
			return "Upper (>)";
			break;
		case BRACKET:
			return "Bracket (()";
			break;
		case RIGHTBRACKET:
			return "RightBracket ())";
			break;
		case BRACE:
			return "Brace ({)";
			break;
		case RIGHTBRACE:
			return "RightBrace (})";
			break;
		case EQUAL:
			return "Equal (==)";
			break;
		case EQUALLOWER:
			return "EqualLower (<=)";
			break;
		case EQUALUPPER:
			return "EqualUpper (>=)";
			break;
		case NOTEQUAL:
			return "NotEqual (!=)";
			break;
		case COMMENT:
			return "Comment";
			break;
		case IF:
			return "If";
			break;
		case ELSE:
			return "Else";
			break;
		case WHILE:
			return "While";
			break;
		case DEFINE:
			return "Define";
			break;
		case DISPLAY:
			return "Display";
			break;
		case TYPEFLOAT:
			return "Float";
			break;
		case TYPESTRING:
			return "String";
			break;
		default:
			return "";
			break;
	}
}

void imprimirArbol(nodo * raiz){
	if(raiz != NULL){
		imprimirArbol(raiz->izquierda);
		if(raiz->simbolo){
			printf("%d : %s\n",raiz->identificador,getSimbolo(raiz->identificador)->nombre);
		}else{
			printf("%s\n",getTypeString(raiz->identificador));
		}
		imprimirArbol(raiz->derecha);
	}
}

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

simbolo * getSimbolo(int id){
	simbolo * nodo = tablaSimbolos;
	while(nodo->posicion > id){
		nodo = nodo->siguiente;
	}
	if(nodo->posicion == id){
		return nodo;
	}else{
		return NULL;
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
	yylval = -1;
    return 0;

}
int startSubstraction(char c){
	yylval = -1;
    return 0;
}
int startMultiplication(char c){
	yylval = -1;
    return 0;
}
int startDivision(char c){
	yylval = -1;
    return 0;
}
int startAutoSum(char c){
	yylval = -1;
    return 0;
}
int startAutoSubstraction(char c){
	yylval = -1;
    return 0;
}
int startAutoMultiplication(char c){
	yylval = -1;
    return 0;
}
int startAutoDivision(char c){
	yylval = -1;
    return 0;
}
int startAsignation(char c){
	yylval = -1;
    return 0;
}
int startNegation(char c){
	yylval = -1;
    return 0;
}
int startAnd(char c){
	yylval = -1;
    return 0;
}
int startOr(char c){
	yylval = -1;
    return 0;
}
int startString(char c){
	memset(valor,'\0',sizeof(valor));
    return 0;
}
int startSemicolon(char c){
	yylval = -1;
    return 0;
}
int startComma(char c){
	yylval = -1;
    return 0;
}
int startSeparator(char c){
	yylval = -1;
    return 0;
}
int startLower(char c){
	yylval = -1;
    return 0;
}
int startUpper(char c){
	yylval = -1;
    return 0;
}
int startBracket(char c){
	yylval = -1;
    return 0;
}
int startRightBracket(char c){
	yylval = -1;
    return 0;
}
int startBrace(char c){
	yylval = -1;
    return 0;
}
int startRightBrace(char c){
	yylval = -1;
    return 0;
}
int startEqual(char c){
	yylval = -1;
    return 0;
}
int startEqualLower(char c){
	yylval = -1;
    return 0;
}
int startEqualUpper(char c){
	yylval = -1;
    return 0;
}
int startNotEqual(char c){
	yylval = -1;
    return 0;
}
int startComment(char c){
	yylval = -1;
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
		if((yylval = searchSimbol(valor,tipoToken)) == -1){
			yylval = addToSimbolTable(valor,tipoToken);
		}
		return tipoToken;
	}else{
		//palabra reservada
		int tipoToken = reservedWord(valor);
		return tipoToken;
	}
}
int endNumber(char c){
    if((yylval = searchSimbol(valor,NUMBER)) == -1){
        yylval = addToSimbolTable(valor,NUMBER);
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
	if((yylval = searchSimbol(valor,tipoToken)) == -1){
		yylval = addToSimbolTable(valor,tipoToken);
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

	printf("\nArbol:\n");
	imprimirArbol(programa);

    return 0;
}


#line 1211 "y.tab.cpp"
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
#line 264 "yacc.y"
	{printf( "Reconocido el programa :)\n");programa = crearNodo(PROGRAMA,bloque_declaracion,cuerpo);}
break;
case 2:
#line 265 "yacc.y"
	{printf( "Reconocido el programa :)\n");programa = cuerpo;}
break;
case 3:
#line 267 "yacc.y"
	{printf( "Reconocido el cuerpo\n");cuerpo = sentencia;}
break;
case 4:
#line 268 "yacc.y"
	{cuerpo = crearNodo(CUERPO,cuerpo,sentencia);}
break;
case 5:
#line 270 "yacc.y"
	{sentencia = asig;}
break;
case 6:
#line 271 "yacc.y"
	{sentencia = asig_especial;}
break;
case 7:
#line 272 "yacc.y"
	{sentencia = desicion;}
break;
case 8:
#line 273 "yacc.y"
	{sentencia = mientras;}
break;
case 9:
#line 274 "yacc.y"
	{sentencia = ciclo_hasta;}
break;
case 10:
#line 275 "yacc.y"
	{sentencia = escribir;}
break;
case 11:
#line 278 "yacc.y"
	{printf( "Reconocida una condicion simple\n"); condicion = condicionsimple;}
break;
case 12:
#line 279 "yacc.y"
	{printf( "Reconocida una condicion multiple\n");condicion = condicionmultiple;}
break;
case 18:
#line 287 "yacc.y"
	{condicionmultiple = crearNodo(NEGATION,NULL,condicionsimple);}
break;
case 19:
#line 288 "yacc.y"
	{}
break;
case 20:
#line 289 "yacc.y"
	{}
break;
case 21:
#line 290 "yacc.y"
	{}
break;
case 22:
#line 292 "yacc.y"
	{printf( "Reconocido un if\n");desicion = crearNodo(IF,condicion,cuerpo);}
break;
case 23:
#line 293 "yacc.y"
	{printf( "Reconocido un if\n");}
break;
case 24:
#line 295 "yacc.y"
	{printf( "Reconocida una asignacion\n");asig = crearNodo(ASIGNATION,crearHoja(yyvsp[-2]),exp);}
break;
case 25:
#line 297 "yacc.y"
	{printf( "Reconocida una asignacion especial\n");asig_especial = crearNodo(AUTOSUM,crearHoja(yyvsp[-2]),exp);}
break;
case 26:
#line 298 "yacc.y"
	{printf( "Reconocida una asignacion especial\n");asig_especial = crearNodo(AUTOSUBSTRACTION,crearHoja(yyvsp[-2]),exp);}
break;
case 27:
#line 299 "yacc.y"
	{printf( "Reconocida una asignacion especial\n");asig_especial = crearNodo(AUTOMULTIPLICATION,crearHoja(yyvsp[-2]),exp);}
break;
case 28:
#line 300 "yacc.y"
	{printf( "Reconocida una asignacion especial\n");asig_especial = crearNodo(AUTODIVISION,crearHoja(yyvsp[-2]),exp);}
break;
case 29:
#line 302 "yacc.y"
	{printf( "Reconocida una suma\n"); exp = crearNodo(SUM,exp,termino);}
break;
case 30:
#line 304 "yacc.y"
	{printf( "Reconocida una resta\n");exp = crearNodo(SUBSTRACTION,exp,termino);}
break;
case 31:
#line 306 "yacc.y"
	{exp = termino;}
break;
case 32:
#line 308 "yacc.y"
	{printf( "Reconocida una multiplicacion\n"); termino = crearNodo(MULTIPLICATION,termino,factor);}
break;
case 33:
#line 310 "yacc.y"
	{printf( "Reconocida una division\n"); termino = crearNodo(DIVISION,termino,factor);}
break;
case 34:
#line 312 "yacc.y"
	{termino = factor;}
break;
case 37:
#line 316 "yacc.y"
	{factor = crearHoja(yyvsp[0]);}
break;
case 38:
#line 317 "yacc.y"
	{factor = crearHoja(yyvsp[0]);}
break;
case 39:
#line 318 "yacc.y"
	{factor = exp;}
break;
case 40:
#line 320 "yacc.y"
	{lista_variables = crearHoja(yyvsp[0]);}
break;
case 41:
#line 321 "yacc.y"
	{crearNodo(COMMA,lista_variables,crearHoja(yyvsp[0]));}
break;
case 42:
#line 323 "yacc.y"
	{declaracion = crearNodo(SEPARATOR,lista_variables,tipo_dato);}
break;
case 43:
#line 324 "yacc.y"
	{}
break;
case 44:
#line 326 "yacc.y"
	{bloque_declaracion = declaracion;}
break;
case 45:
#line 328 "yacc.y"
	{mientras = crearNodo(WHILE,condicion,cuerpo);}
break;
case 46:
#line 330 "yacc.y"
	{ciclo_hasta = crearNodo(REPEAT,cuerpo,condicion);}
break;
case 47:
#line 332 "yacc.y"
	{printf( "Reconocido un display\n");escribir = crearNodo(DISPLAY,NULL,crearHoja(yyvsp[0]));}
break;
#line 1558 "y.tab.cpp"
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
