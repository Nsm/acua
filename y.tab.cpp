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
#line 2 "yacc.y"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;

#define CANT_ESTADOS  35
#define CANT_ENTRADAS  22
#define CUERPO 1
#define PROGRAMA 2
#define BOOL 3
#define LINUX 1
#define WINDOWS 2

#ifdef WIN32
int targetOs = WINDOWS;
#else
int targetOs = LINUX;
#endif


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

/*TABLA DE SIMBOLOS*/

struct simbolo{
	char nombre[40];
	int tipo;
	int posicion;
	simbolo *siguiente;
};

simbolo * tablaSimbolos = NULL;

simbolo * getSimbolo(int id);

int addToSimbolTable(char * name, int tipo);

char valor[40];

/*ARBOL*/

struct nodo{
	int identificador;
	bool simbolo;
	nodo *derecha;
	nodo *izquierda;
};

nodo* programa;

nodo * crearNodo(int operacion, nodo * izquierda, nodo * derecha);
nodo * crearHoja(int numeroSimbolo);


/*GENERACION DE ASSEMBLER*/

struct resultado{
	string codigo;
	int tipo;
	string variable;
};

int auxiliarCount = 0;
int etiquetaCount = 0;

resultado * generarAssemblerSimbolo(nodo * n);
resultado * generarAssemblerSum(resultado * izquierda, resultado * derecha);
resultado * generarAssemblerAsignation(resultado * izquierda, resultado * derecha);
resultado * generarAssemblerSubstraction(resultado * izquierda, resultado * derecha);
resultado * generarAssemblerMultiplication(resultado * izquierda, resultado * derecha);
resultado * generarAssemblerDivision(resultado * izquierda, resultado * derecha);
resultado * generarAssemblerAutoSum(resultado * izquierda, resultado * derecha);
resultado * generarAssemblerAutoSubstraction(resultado * izquierda, resultado * derecha);
resultado * generarAssemblerAutoMultiplication(resultado * izquierda, resultado * derecha);
resultado * generarAssemblerAutoDivision(resultado * izquierda, resultado * derecha);
resultado * generarAssemblerCuerpo(resultado * izquierda,resultado * derecha);
resultado * generarAssemblerLower(resultado * izquierda,resultado * derecha);
resultado * generarAssemblerUpper(resultado * izquierda,resultado * derecha);
resultado * generarAssemblerEqual(resultado * izquierda,resultado * derecha);
resultado * generarAssemblerEqualLower(resultado * izquierda,resultado * derecha);
resultado * generarAssemblerEqualUpper(resultado * izquierda,resultado * derecha);
resultado * generarAssemblerNotEqual(resultado * izquierda,resultado * derecha);
resultado * generarAssemblerIf(resultado * izquierda,resultado * derecha);
resultado * generarAssemblerElse(resultado * izquierda,resultado * derecha);
resultado * generarAssemblerAnd(resultado * izquierda,resultado * derecha);
resultado * generarAssemblerOr(resultado * izquierda,resultado * derecha);
resultado * generarAssemblerNegation(resultado * derecha);
resultado * generarAssemblerWhile(resultado * izquierda,resultado * derecha);
resultado * generarAssemblerRepeat(resultado * izquierda,resultado * derecha);
resultado * generarAssemblerDisplay(resultado * derecha);




/*DECLARACION DE VARIABLES*/
struct variableDeclarada{
	int posicion;
	variableDeclarada * siguiente;
};

void actualizarTipoVariables(variableDeclarada * variables, int tipo);

#line 280 "yacc.y"
typedef union{
	int  ival;
	nodo *pval;
	variableDeclarada *vval;
} YYSTYPE;
#line 317 "y.tab.cpp"
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
    0,    0,    1,    1,    2,    2,    2,    2,    2,    2,
    2,    3,    3,    4,    4,    4,    4,    4,    4,    5,
    5,    5,    6,   17,    7,    8,    8,    8,    8,    9,
    9,    9,   10,   10,   10,   18,   11,   11,   11,   19,
   19,   12,   12,   13,   14,   15,   16,
};
static const short yylen[] = {                            2,
    2,    1,    1,    2,    2,    2,    1,    1,    1,    1,
    2,    1,    1,    3,    3,    3,    3,    3,    3,    2,
    3,    3,    7,    5,    3,    3,    3,    3,    3,    3,
    3,    1,    3,    3,    1,    1,    1,    1,    3,    1,
    3,    4,    5,    4,    7,    8,    2,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    3,    0,
    0,    0,    0,    9,   10,    0,    8,    0,    0,    0,
    0,    0,    0,    0,    0,   47,    0,    4,    0,    5,
    6,    0,   11,   37,   38,    0,    0,    0,   35,    0,
    0,    0,    0,    0,    0,    0,   13,    0,    0,   40,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   20,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   44,    0,    0,    0,    0,    0,   39,    0,    0,   33,
   34,    0,   22,   21,    0,    0,    0,    0,    0,    0,
    0,    0,   41,   36,    0,    0,   24,    0,    0,    0,
   42,    0,   23,   45,   43,    0,   46,
};
static const short yydgoto[] = {                          7,
    8,    9,   45,   46,   47,   10,   11,   12,   48,   38,
   39,   51,   13,   14,   15,   16,   17,   95,   52,
};
static const short yysindex[] = {                      -230,
  -84, -267, -254, -244, -238, -233,    0, -182,    0, -262,
 -223, -215, -182,    0,    0, -205,    0, -229, -229, -229,
 -229, -229, -165, -165, -188,    0, -182,    0, -206,    0,
    0, -182,    0,    0,    0, -229, -240, -200,    0, -240,
 -240, -240, -240, -229, -202, -187,    0, -245, -178,    0,
 -248, -195, -246, -182, -173, -229, -229, -229, -229,    0,
 -172, -229, -229, -229, -229, -229, -229, -229, -229, -166,
    0, -189, -141, -170, -176, -216,    0, -200, -200,    0,
    0, -182,    0,    0, -240, -240, -240, -240, -240, -240,
 -182, -170,    0,    0, -148, -136,    0, -192, -191, -145,
    0, -165,    0,    0,    0, -131,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,  157,    0,    1,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  158,    0,    0,    0,    0, -111, -150,    0, -109,
 -105,  -95,  -87,    0,    0,  -92,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -130, -110,    0,
    0,    0,    0,    0, -257, -252, -155, -114, -100,  -94,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
  -11,   -8,  -21,   73,    0,    0,    0,    0,  -14,   81,
   85,    0,    0,    0,    0,    0,    0,   95,  137,
};
#define YYTABLESIZE 294
static const short yytable[] = {                         28,
    7,   32,   49,   37,   40,   41,   42,   43,   50,   23,
    1,   14,   14,   56,   57,   53,   15,   15,   56,   57,
   14,   55,   24,   28,   29,   15,    1,   34,   35,   64,
   65,   71,   26,   75,   25,   66,   67,   68,   69,    2,
    1,    3,   76,    5,   28,   27,    6,   36,   30,   85,
   86,   87,   88,   89,   90,    2,   31,    3,    4,    5,
   58,   59,    6,   97,    1,    1,   33,   28,   50,    2,
   98,    3,   54,    5,    1,   61,    6,   73,   74,   99,
  106,   62,   63,   73,   92,   56,   57,  103,  104,   28,
   28,   34,   35,    2,    2,    3,    3,    5,    5,   70,
    6,    6,   44,    2,   77,    3,   82,    5,   32,   32,
    6,   36,   91,   18,   18,   93,   60,   96,   32,   32,
   94,   32,   18,  101,   32,   32,  105,   32,   30,   30,
   32,   32,   32,   32,   83,   84,   78,   79,   30,   30,
  102,   30,   80,   81,   30,   30,  107,   30,   31,   31,
   30,   30,   30,   30,   16,   16,    2,    1,   31,   31,
   26,   31,   27,   16,   31,   31,   28,   31,   17,   17,
   31,   31,   31,   31,   19,   19,   29,   17,   18,   19,
   20,   21,   22,   19,   25,   12,  100,   72,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    7,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    7,    0,    0,    0,    0,    0,    7,    0,    7,    0,
    7,    0,    0,    7,
};
static const short yycheck[] = {                          8,
    0,   13,   24,   18,   19,   20,   21,   22,  257,  277,
  257,  269,  270,  259,  260,   27,  269,  270,  259,  260,
  278,   36,  277,   32,  287,  278,  257,  257,  258,  275,
  276,  280,  271,  280,  279,  281,  282,  283,  284,  286,
  257,  288,   54,  290,   53,  279,  293,  277,  272,   64,
   65,   66,   67,   68,   69,  286,  272,  288,  289,  290,
  261,  262,  293,  280,  257,  257,  272,   76,  257,  286,
   82,  288,  279,  290,  257,  278,  293,  273,  274,   91,
  102,  269,  270,  273,  274,  259,  260,  280,  280,   98,
   99,  257,  258,  286,  286,  288,  288,  290,  290,  278,
  293,  293,  268,  286,  278,  288,  279,  290,  259,  260,
  293,  277,  279,  269,  270,  257,   44,  294,  269,  270,
  291,  272,  278,  272,  275,  276,  272,  278,  259,  260,
  281,  282,  283,  284,   62,   63,   56,   57,  269,  270,
  277,  272,   58,   59,  275,  276,  278,  278,  259,  260,
  281,  282,  283,  284,  269,  270,    0,    0,  269,  270,
  272,  272,  272,  278,  275,  276,  272,  278,  269,  270,
  281,  282,  283,  284,  269,  270,  272,  278,  263,  264,
  265,  266,  267,  278,  272,  278,   92,   51,   -1,   -1,
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
"sentencia : desicion_compuesta",
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
"condicionsimple : exp NOTEQUAL exp",
"condicionmultiple : NEGATION condicionsimple",
"condicionmultiple : condicionsimple OR condicionsimple",
"condicionmultiple : condicionsimple AND condicionsimple",
"desicion : IF BRACKET condicion RIGHTBRACKET BRACE cuerpo RIGHTBRACE",
"desicion_compuesta : desicion ELSE BRACE cuerpo RIGHTBRACE",
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
#line 415 "yacc.y"

/* CODIGO */

void actualizarTipoVariables(variableDeclarada * variables, int tipo){
	while(variables){
		simbolo * s = getSimbolo(variables->posicion);
		s->tipo = tipo;
		variableDeclarada * borrar = variables;
		variables = variables->siguiente;
		delete borrar;
	}
}


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

string getAuxVariable(){
	stringstream out;
	char s[] = "_aux";
	int pos = addToSimbolTable(s,TYPEFLOAT);
	out << pos;
	return "v" + out.str();
}

string getEtiqueta(){
	etiquetaCount ++;
	stringstream out;
	out << etiquetaCount;
	string s = "e";
	s += out.str();
	return s;
}

resultado * generarAssembler(nodo * raiz){
	if(raiz != NULL){
		resultado * izquierda = generarAssembler(raiz->izquierda);
		resultado * derecha = generarAssembler(raiz->derecha);
		if(raiz->simbolo){
			return generarAssemblerSimbolo(raiz);
		}
		switch(raiz->identificador){
			case SUM:
				return generarAssemblerSum(izquierda, derecha);
				break;
			case ASIGNATION:
				return generarAssemblerAsignation(izquierda, derecha);
				break;
			case SUBSTRACTION:
				return generarAssemblerSubstraction(izquierda, derecha);
				break;
			case MULTIPLICATION:
				return generarAssemblerMultiplication(izquierda, derecha);
				break;
			case DIVISION:
				return generarAssemblerDivision(izquierda, derecha);
				break;
			case AUTOSUM:
				return generarAssemblerAutoSum(izquierda,derecha);
				break;
			case AUTOSUBSTRACTION:
				return generarAssemblerAutoSubstraction(izquierda, derecha);
				break;
			case AUTOMULTIPLICATION:
				return generarAssemblerAutoMultiplication(izquierda, derecha);
				break;
			case AUTODIVISION:
				return generarAssemblerAutoDivision(izquierda, derecha);
				break;
			case CUERPO:
				return generarAssemblerCuerpo(izquierda,derecha);
				break;
			case LOWER:
				return generarAssemblerLower(izquierda,derecha);
				break;
			case UPPER:
				return generarAssemblerUpper(izquierda,derecha);
				break;
			case EQUAL:
				return generarAssemblerEqual(izquierda,derecha);
				break;
			case EQUALLOWER:
				return generarAssemblerEqualLower(izquierda,derecha);
				break;
			case EQUALUPPER:
				return generarAssemblerEqualUpper(izquierda,derecha);
				break;
			case NOTEQUAL:
				return generarAssemblerNotEqual(izquierda,derecha);
				break;
			case IF:
				return generarAssemblerIf(izquierda,derecha);
				break;
			case ELSE:
				return generarAssemblerElse(izquierda,derecha);
				break;
			case AND:
				return generarAssemblerAnd(izquierda,derecha);
				break;
			case OR:
				return generarAssemblerOr(izquierda,derecha);
				break;
			case NEGATION:
				return generarAssemblerNegation(derecha);
				break;
			case WHILE:
				return generarAssemblerWhile(izquierda,derecha);
				break;
			case REPEAT:
				return generarAssemblerRepeat(izquierda,derecha);
				break;
			case DISPLAY:
				return generarAssemblerDisplay(derecha);
				break;
			default:
				return NULL;
				break;
		}
	}else{
		return NULL;
	}
}

string generarEncabezadoAssembler(){
	string data, bss;
	if(targetOs == LINUX){
		data = "section .data\n";
		bss = "section .bss\n";
	}else{
		data = "segment data\n";
		bss = "segment stack stack\n";
	}
	simbolo * actual =  tablaSimbolos;
	int sizeStack = 0;
	while(actual != NULL ){
		if(actual->tipo == STRING){
			stringstream out;
			out << actual->posicion;
			string nombre = "c";
			nombre += out.str();
			if(targetOs == LINUX){
				data +=  nombre + ":	db '" + actual->nombre + "',10\n";
			}else{
				data +=  nombre + ":	db '" + actual->nombre + "',13,10,'$'\n";
			}
		}else if(actual->tipo == TYPEFLOAT){
			sizeStack ++;
			stringstream out;
			out << actual->posicion;
			string nombre = "v";
			nombre += out.str();
			bss +=  nombre + ":	resq 1 \n";
		}else if(actual->tipo == NUMBER){
			stringstream out;
			out << actual->posicion;
			string nombre = "c";
			nombre += out.str();
			string valor = actual->nombre;
			if(valor.find('.') == string::npos){
				//si no tiene un punto se le agrega .0 ya que los valores enteros generan problemas
				valor += ".0";	
			}			
			data +=  nombre + ":	dq " + valor + "\n";
		}
		actual = actual->siguiente;
	}
	string code;
	if(targetOs == LINUX){
		code = "section .text\nglobal _start\n_start:";
	}else{
		stringstream out;
		out << sizeStack;
		data = "resq " + out.str() + "\n" + data; 
		code = "segment code\n..start:\nmov ax,data\nmov ds,ax";
	}
	return data + bss + code;
}

resultado * generarAssemblerSimbolo(nodo * n){
	resultado * res = new resultado;
	simbolo * sim = getSimbolo(n->identificador);
	if(sim->tipo == TYPEFLOAT || sim->tipo == TYPESTRING){
		res->codigo = "";
		stringstream out;
		out << sim->posicion;
		res->variable = "v" + out.str();
		res->tipo = sim->tipo;
	}else if(sim->tipo == STRING){
		stringstream out1;
		stringstream out2;
		out1 << strlen(sim->nombre) + 1;
		res->codigo = out1.str();
		out2 << n->identificador;
		res->variable = "c" + out2.str();
		res->tipo = sim->tipo;
	}else if(sim->tipo == ID){
		//Esto significa que se esta usando una variable que no se declaro (sino su tipo deberia haber cambiado a TYPEFLOAT o TYPESTRING)
		cout << "Variable no declarada: " << sim->nombre << '\n';
		exit(1);
	}else if(sim->tipo == NUMBER){
		stringstream out;
		res->codigo = "";
		out << n->identificador;
		res->variable = "c" + out.str();
		res->tipo = TYPEFLOAT;
	}
	return res;
}

resultado * generarAssemblerSum(resultado * izquierda, resultado * derecha){
	resultado * res = new resultado;
	res->tipo = TYPEFLOAT;
	res->codigo = izquierda->codigo;
	res->codigo += derecha->codigo;
	res->codigo += "fld qword [" + izquierda->variable + "]\n";
	res->codigo += "fadd qword [" + derecha->variable + "]\n";
	string aux = getAuxVariable();
	res->codigo += "fstp qword ["+aux+"]\n";
	res->variable = aux;
	delete izquierda;
	delete derecha;
	return res;
}

resultado * generarAssemblerAsignation(resultado * izquierda, resultado * derecha){
	resultado * res = new resultado;
	res->tipo = TYPEFLOAT;
	res->codigo = izquierda->codigo;
	res->codigo += derecha->codigo;
	res->codigo += "fld qword [" + derecha->variable + "]\n";
	res->codigo += "fstp qword [" + izquierda->variable + "]\n";
	res->variable = izquierda->variable;
	delete izquierda;
	delete derecha;
	return res;
}

resultado * generarAssemblerSubstraction(resultado * izquierda, resultado * derecha){
	resultado * res = new resultado;
	res->tipo = TYPEFLOAT;
	res->codigo = izquierda->codigo;
	res->codigo += derecha->codigo;
	res->codigo += "fld qword [" + izquierda->variable + "]\n";
	res->codigo += "fsub qword [" + derecha->variable + "]\n";
	string aux = getAuxVariable();
	res->codigo += "fstp qword ["+aux+"]\n";
	res->variable = aux;
	delete izquierda;
	delete derecha;
	return res;
}

resultado * generarAssemblerMultiplication(resultado * izquierda, resultado * derecha){
    resultado * res = new resultado;
	res->tipo = TYPEFLOAT;
	res->codigo = izquierda->codigo;
	res->codigo += derecha->codigo;
	res->codigo += "fld qword [" + izquierda->variable + "]\n";
	res->codigo += "fmul qword [" + derecha->variable + "]\n";
	string aux = getAuxVariable();
	res->codigo += "fstp qword ["+aux+"]\n";
	res->variable = aux;
	delete izquierda;
	delete derecha;
	return res;
}

resultado * generarAssemblerDivision(resultado * izquierda, resultado * derecha){
    resultado * res = new resultado;
	res->tipo = TYPEFLOAT;
	res->codigo = izquierda->codigo;
	res->codigo += derecha->codigo;
	res->codigo += "fld qword [" + izquierda->variable + "]\n";
	res->codigo += "fdiv qword [" + derecha->variable + "]\n";
	string aux = getAuxVariable();
	res->codigo += "fstp qword ["+aux+"]\n";
	res->variable = aux;
	delete izquierda;
	delete derecha;
	return res;

}

resultado * generarAssemblerAutoSum(resultado * izquierda, resultado * derecha){
    resultado * res = new resultado;
	res->tipo = TYPEFLOAT;
	res->codigo = izquierda->codigo;
	res->codigo += derecha->codigo;
	res->codigo += "fld qword [" + izquierda->variable + "]\n";
	res->codigo += "fadd qword [" + derecha->variable + "]\n";
	res->codigo += "fstp qword ["+izquierda->variable+"]\n";
	res->variable = izquierda->variable;
	delete izquierda;
	delete derecha;
	return res;
}

resultado * generarAssemblerAutoSubstraction(resultado * izquierda, resultado * derecha){
    resultado * res = new resultado;
	res->tipo = TYPEFLOAT;
	res->codigo = izquierda->codigo;
	res->codigo += derecha->codigo;
	res->codigo += "fld qword [" + izquierda->variable + "]\n";
	res->codigo += "fsub qword [" + derecha->variable + "]\n";
	res->codigo += "fstp qword ["+izquierda->variable+"]\n";
	res->variable = izquierda->variable;
	delete izquierda;
	delete derecha;
	return res;
}

resultado * generarAssemblerAutoMultiplication(resultado * izquierda, resultado * derecha){
    resultado * res = new resultado;
	res->tipo = TYPEFLOAT;
	res->codigo = izquierda->codigo;
	res->codigo += derecha->codigo;
	res->codigo += "fld qword [" + izquierda->variable + "]\n";
	res->codigo += "fmul qword [" + derecha->variable + "]\n";
	res->codigo += "fstp qword ["+izquierda->variable+"]\n";
	res->variable = izquierda->variable;
	delete izquierda;
	delete derecha;
	return res;
}

resultado * generarAssemblerAutoDivision(resultado * izquierda, resultado * derecha){
    resultado * res = new resultado;
	res->tipo = TYPEFLOAT;
	res->codigo = izquierda->codigo;
	res->codigo += derecha->codigo;
	res->codigo += "fld qword [" + izquierda->variable + "]\n";
	res->codigo += "fdiv qword [" + derecha->variable + "]\n";
	res->codigo += "fstp qword ["+izquierda->variable+"]\n";
	res->variable = izquierda->variable;
	delete izquierda;
	delete derecha;
	return res;
}

resultado * generarAssemblerCuerpo(resultado * izquierda,resultado * derecha){
	resultado * res = new resultado;
	res->codigo = izquierda->codigo + derecha->codigo;
	res->tipo = NULL;
	res->variable = "";
	delete izquierda;
	delete derecha;
	return res;
}

resultado * generarAssemblerLower(resultado * izquierda,resultado * derecha){
	resultado * res = new resultado;
	res->tipo = BOOL;
	string aux = getAuxVariable();
	res->variable = aux;
	res->codigo = izquierda->codigo;
	res->codigo += derecha->codigo;
	res->codigo += "fld qword [" + izquierda->variable + "]\n";
	res->codigo += "fcomp qword [" + derecha->variable + "]\n";
	res->codigo += "fnstsw  ax\n";
	res->codigo += "sahf\n";
	string etiquetaFalso = getEtiqueta();
	res->codigo += "jnb " + etiquetaFalso + '\n';
	res->codigo += "mov dword [" + aux + "], 1h" + '\n';
	string etiquetaFin = getEtiqueta();
	res->codigo += "jmp " + etiquetaFin + '\n';
	res->codigo += etiquetaFalso + ":\n";
	res->codigo += "mov dword [" + aux + "], 0h" + '\n';
	res->codigo += etiquetaFin + ":\n";
	delete izquierda;
	delete derecha;
	return res;
}

resultado * generarAssemblerUpper(resultado * izquierda,resultado * derecha){
	resultado * res = new resultado;
	res->tipo = BOOL;
	string aux = getAuxVariable();
	res->variable = aux;
	res->codigo = izquierda->codigo;
	res->codigo += derecha->codigo;
	res->codigo += "fld qword [" + izquierda->variable + "]\n";
	res->codigo += "fcomp qword [" + derecha->variable + "]\n";
	res->codigo += "fnstsw  ax\n";
	res->codigo += "sahf\n";
	string etiquetaFalso = getEtiqueta();
	res->codigo += "jna " + etiquetaFalso + '\n';
	res->codigo += "mov dword [" + aux + "], 1h" + '\n';
	string etiquetaFin = getEtiqueta();
	res->codigo += "jmp " + etiquetaFin + '\n';
	res->codigo += etiquetaFalso + ":\n";
	res->codigo += "mov dword [" + aux + "], 0h" + '\n';
	res->codigo += etiquetaFin + ":\n";
	delete izquierda;
	delete derecha;
	return res;
}

resultado * generarAssemblerEqual(resultado * izquierda,resultado * derecha){
	resultado * res = new resultado;
	res->tipo = BOOL;
	string aux = getAuxVariable();
	res->variable = aux;
	res->codigo = izquierda->codigo;
	res->codigo += derecha->codigo;
	res->codigo += "fld qword [" + izquierda->variable + "]\n";
	res->codigo += "fcomp qword [" + derecha->variable + "]\n";
	res->codigo += "fnstsw  ax\n";
	res->codigo += "sahf\n";
	string etiquetaFalso = getEtiqueta();
	res->codigo += "jne " + etiquetaFalso + '\n';
	res->codigo += "mov dword [" + aux + "], 1h" + '\n';
	string etiquetaFin = getEtiqueta();
	res->codigo += "jmp " + etiquetaFin + '\n';
	res->codigo += etiquetaFalso + ":\n";
	res->codigo += "mov dword [" + aux + "], 0h" + '\n';
	res->codigo += etiquetaFin + ":\n";
	delete izquierda;
	delete derecha;
	return res;
}

resultado * generarAssemblerEqualLower(resultado * izquierda,resultado * derecha){
	resultado * res = new resultado;
	res->tipo = BOOL;
	string aux = getAuxVariable();
	res->variable = aux;
	res->codigo = izquierda->codigo;
	res->codigo += derecha->codigo;
	res->codigo += "fld qword [" + izquierda->variable + "]\n";
	res->codigo += "fcomp qword [" + derecha->variable + "]\n";
	res->codigo += "fnstsw  ax\n";
	res->codigo += "sahf\n";
	string etiquetaFalso = getEtiqueta();
	res->codigo += "ja " + etiquetaFalso + '\n';
	res->codigo += "mov dword [" + aux + "], 1h" + '\n';
	string etiquetaFin = getEtiqueta();
	res->codigo += "jmp " + etiquetaFin + '\n';
	res->codigo += etiquetaFalso + ":\n";
	res->codigo += "mov dword [" + aux + "], 0h" + '\n';
	res->codigo += etiquetaFin + ":\n";
	delete izquierda;
	delete derecha;
	return res;
}

resultado * generarAssemblerEqualUpper(resultado * izquierda,resultado * derecha){
	resultado * res = new resultado;
	res->tipo = BOOL;
	string aux = getAuxVariable();
	res->variable = aux;
	res->codigo = izquierda->codigo;
	res->codigo += derecha->codigo;
	res->codigo += "fld qword [" + izquierda->variable + "]\n";
	res->codigo += "fcomp qword [" + derecha->variable + "]\n";
	res->codigo += "fnstsw  ax\n";
	res->codigo += "sahf\n";
	string etiquetaFalso = getEtiqueta();
	res->codigo += "jb " + etiquetaFalso + '\n';
	res->codigo += "mov dword [" + aux + "], 1h" + '\n';
	string etiquetaFin = getEtiqueta();
	res->codigo += "jmp " + etiquetaFin + '\n';
	res->codigo += etiquetaFalso + ":\n";
	res->codigo += "mov dword [" + aux + "], 0h" + '\n';
	res->codigo += etiquetaFin + ":\n";
	delete izquierda;
	delete derecha;
	return res;

}

resultado * generarAssemblerNotEqual(resultado * izquierda,resultado * derecha){
	resultado * res = new resultado;
	res->tipo = BOOL;
	string aux = getAuxVariable();
	res->variable = aux;
	res->codigo = izquierda->codigo;
	res->codigo += derecha->codigo;
	res->codigo += "fld qword [" + izquierda->variable + "]\n";
	res->codigo += "fcomp qword [" + derecha->variable + "]\n";
	res->codigo += "fnstsw  ax\n";
	res->codigo += "sahf\n";
	string etiquetaFalso = getEtiqueta();
	res->codigo += "je " + etiquetaFalso + '\n';
	res->codigo += "mov dword [" + aux + "], 1h" + '\n';
	string etiquetaFin = getEtiqueta();
	res->codigo += "jmp " + etiquetaFin + '\n';
	res->codigo += etiquetaFalso + ":\n";
	res->codigo += "mov dword [" + aux + "], 0h" + '\n';
	res->codigo += etiquetaFin + ":\n";
	delete izquierda;
	delete derecha;
	return res;
}

resultado * generarAssemblerIf(resultado * izquierda,resultado * derecha){
	resultado * res = new resultado;
	res->tipo = BOOL;
	res->variable = izquierda->variable;
	res->codigo = izquierda->codigo;
	res->codigo += "mov ax, word [" + izquierda->variable + "]\n";
	res->codigo += "cmp ax, 0h\n";
	string etiquetaFalso = getEtiqueta();
	res->codigo += "je " + etiquetaFalso + '\n';
	res->codigo += derecha->codigo;
	res->codigo += etiquetaFalso + ":\n";
	delete izquierda;
	delete derecha;
	return res;
}

resultado * generarAssemblerElse(resultado * izquierda,resultado * derecha){
	resultado * res = new resultado;
	res->tipo = NULL;
	res->variable = "";
	res->codigo = izquierda->codigo;
	res->codigo += "mov ax, word [" + izquierda->variable + "]\n";
	res->codigo += "cmp ax, 0h\n";
	string etiquetaFalso = getEtiqueta();
	res->codigo += "jne " + etiquetaFalso + '\n';
	res->codigo += derecha->codigo;
	res->codigo += etiquetaFalso + ":\n";
	delete izquierda;
	delete derecha;
	return res;
}

resultado * generarAssemblerAnd(resultado * izquierda,resultado * derecha){
	resultado * res = new resultado;
	res->tipo = BOOL;
	string aux = getAuxVariable();
	res->variable = aux;
	res->codigo = izquierda->codigo;
	res->codigo += derecha->codigo;
	res->codigo += "mov ax, word [" + derecha->variable + "]\n";
	res->codigo += "and ax, word [" + izquierda->variable + "]\n";
	res->codigo += "mov word [" + aux + "], ax \n";
	delete izquierda;
	delete derecha;
	return res;
}

resultado * generarAssemblerOr(resultado * izquierda,resultado * derecha){
	resultado * res = new resultado;
	res->tipo = BOOL;
	string aux = getAuxVariable();
	res->variable = aux;
	res->codigo = izquierda->codigo;
	res->codigo += derecha->codigo;
	res->codigo += "mov ax, word [" + derecha->variable + "]\n";
	res->codigo += "or ax, word [" + izquierda->variable + "]\n";
	res->codigo += "mov word [" + aux + "], ax \n";
	delete izquierda;
	delete derecha;
	return res;
}

resultado * generarAssemblerNegation(resultado * derecha){
	resultado * res = new resultado;
	res->tipo = BOOL;
	string aux = getAuxVariable();
	res->variable = aux;
	res->codigo += derecha->codigo;
	res->codigo += "mov ax, word [" + derecha->variable + "]\n";
	res->codigo += "not ax\n";
	res->codigo += "and ax, 1h\n";
	res->codigo += "mov word [" + aux + "], ax\n";
	delete derecha;
	return res;
}

resultado * generarAssemblerWhile(resultado * izquierda,resultado * derecha){
	resultado * res = new resultado;
	res->tipo = NULL;
	res->variable = "";
	string etiquetaWhile = getEtiqueta();
	res->codigo = etiquetaWhile + ":\n";
	res->codigo += izquierda->codigo;
	res->codigo += "mov ax, word [" + izquierda->variable + "]\n";
	res->codigo += "cmp ax, 0h\n";
	string etiquetaAfuera = getEtiqueta();
	res->codigo += "je " + etiquetaAfuera + '\n';
	res->codigo += derecha->codigo;
	res->codigo += "jmp " + etiquetaWhile + '\n';
	res->codigo += etiquetaAfuera + ":\n";
	delete izquierda;
	delete derecha;
	return res;
}

resultado * generarAssemblerRepeat(resultado * izquierda,resultado * derecha){
	resultado * res = new resultado;
	res->tipo = NULL;
	res->variable = "";
	string etiquetaRepeat = getEtiqueta();
	res->codigo = etiquetaRepeat + ":\n";
	res->codigo += izquierda->codigo;
	res->codigo += derecha->codigo;
	res->codigo += "mov ax, word [" + derecha->variable + "]\n";
	res->codigo += "cmp ax, 0h\n";
	string etiquetaAfuera = getEtiqueta();
	res->codigo += "jne " + etiquetaAfuera + '\n';
	res->codigo += "jmp " + etiquetaRepeat + '\n';
	res->codigo += etiquetaAfuera + ":\n";
	delete izquierda;
	delete derecha;
	return res;
}

resultado * generarAssemblerDisplay(resultado * derecha){
	resultado * res = new resultado;
	res->tipo = NULL;
	res->variable = "";
	if(targetOs == WINDOWS){
		res->codigo = "mov ax,0x0\n";
		res->codigo += "mov ah,0x09 \n";
		res->codigo += "mov dx, " + derecha->variable +" \n";
		res->codigo += "int 0x21 \n";
	}else{
		res->codigo = "mov eax,4 \n";
		res->codigo += "mov ebx,1 \n";
		res->codigo += "mov ecx," + derecha->variable +" \n";
		res->codigo += "mov edx," + derecha->codigo + " \n";
		res->codigo += "int 80h \n";
	}
	delete derecha;
	return res;
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

void yyerror (char *s) {
	fprintf (stderr, "%s\n", s);
	exit(1);
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
	while(actual != NULL && !(strcmp(actual->nombre,name) == 0 && (actual->tipo == tipo || (tipo == ID && (actual->tipo == TYPESTRING || actual->tipo == TYPEFLOAT ))))){
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
	yylval.ival = -1;
    return 0;

}
int startSubstraction(char c){
	yylval.ival = -1;
    return 0;
}
int startMultiplication(char c){
	yylval.ival = -1;
    return 0;
}
int startDivision(char c){
	yylval.ival = -1;
    return 0;
}
int startAutoSum(char c){
	yylval.ival = -1;
    return 0;
}
int startAutoSubstraction(char c){
	yylval.ival = -1;
    return 0;
}
int startAutoMultiplication(char c){
	yylval.ival = -1;
    return 0;
}
int startAutoDivision(char c){
	yylval.ival = -1;
    return 0;
}
int startAsignation(char c){
	yylval.ival = -1;
    return 0;
}
int startNegation(char c){
	yylval.ival = -1;
    return 0;
}
int startAnd(char c){
	yylval.ival = -1;
    return 0;
}
int startOr(char c){
	yylval.ival = -1;
    return 0;
}
int startString(char c){
	memset(valor,'\0',sizeof(valor));
    return 0;
}
int startSemicolon(char c){
	yylval.ival = -1;
    return 0;
}
int startComma(char c){
	yylval.ival = -1;
    return 0;
}
int startSeparator(char c){
	yylval.ival = -1;
    return 0;
}
int startLower(char c){
	yylval.ival = -1;
    return 0;
}
int startUpper(char c){
	yylval.ival = -1;
    return 0;
}
int startBracket(char c){
	yylval.ival = -1;
    return 0;
}
int startRightBracket(char c){
	yylval.ival = -1;
    return 0;
}
int startBrace(char c){
	yylval.ival = -1;
    return 0;
}
int startRightBrace(char c){
	yylval.ival = -1;
    return 0;
}
int startEqual(char c){
	yylval.ival = -1;
    return 0;
}
int startEqualLower(char c){
	yylval.ival = -1;
    return 0;
}
int startEqualUpper(char c){
	yylval.ival = -1;
    return 0;
}
int startNotEqual(char c){
	yylval.ival = -1;
    return 0;
}
int startComment(char c){
	yylval.ival = -1;
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
	if(strlen(valor) < 39){
		valor[strlen(valor)] = c;
		return 0;
	}else{
		printf("\nError de sintaxis: numero fuera de rango %s... \n",valor);
		exit(1);
	}
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
		if((yylval.ival = searchSimbol(valor,tipoToken)) == -1){
			yylval.ival = addToSimbolTable(valor,tipoToken);
		}
		return tipoToken;
	}else{
		//palabra reservada
		int tipoToken = reservedWord(valor);
		return tipoToken;
	}
}
int endNumber(char c){
	atof(valor);
	if(errno){
		printf("\nError de sintaxis: numero mal formado o fuera de rango '%s'\n",valor);
		exit(1);
	}
    if((yylval.ival = searchSimbol(valor,NUMBER)) == -1){
        yylval.ival = addToSimbolTable(valor,NUMBER);
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
	if((yylval.ival = searchSimbol(valor,tipoToken)) == -1){
		yylval.ival = addToSimbolTable(valor,tipoToken);
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


    yyparse();
    fclose(archivo);

	printf("\nArbol:\n");
	imprimirArbol(programa);

	resultado * res = generarAssembler(programa);
	string pie;
	if(targetOs == WINDOWS){
		pie = "mov ah,0x4C\nint 0x21";
	}else{
		pie = "mov eax,1\nmov ebx,0\nint 80h";
	}
	
	string encabezado = generarEncabezadoAssembler();
	cout << "\nAssembler:\n" << encabezado << '\n' << res->codigo << pie;

	ofstream asmfile;
  	asmfile.open ("out.asm");
  	asmfile << encabezado << '\n' << res->codigo << pie;
  	asmfile.close();

	string nombre = argv[1];
	if(nombre.find('.') != string::npos){
		nombre = nombre.substr(0,nombre.find_last_of('.'));
	}
	cout << "Nombre:" << nombre;

  	if(targetOs == WINDOWS){
  		//windows
		nombre += ".exe";
		system("nasm -f obj out.asm");
		string linkCommand = "alink -o \"" + nombre + "\" out.obj";
		system(linkCommand.c_str());
		//remove("out.asm");
		remove("out.obj");
	}else{
		//linux		
		system("nasm -f elf out.asm");
		string linkCommand = "ld -s -o " + nombre +" out.o";
		system(linkCommand.c_str());
		//remove("out.asm");
		remove("out.o");
	}
	
	
    return 0;
}


#line 1950 "y.tab.cpp"
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
#line 341 "yacc.y"
	{printf( "Reconocido el programa :)\n");programa = yyvsp[0].pval;}
break;
case 2:
#line 342 "yacc.y"
	{printf( "Reconocido el programa :)\n");programa = yyvsp[0].pval;}
break;
case 3:
#line 344 "yacc.y"
	{printf( "Reconocido el cuerpo\n");yyval.pval = yyvsp[0].pval;}
break;
case 4:
#line 345 "yacc.y"
	{yyval.pval = crearNodo(CUERPO,yyvsp[-1].pval,yyvsp[0].pval);}
break;
case 5:
#line 347 "yacc.y"
	{yyval.pval = yyvsp[-1].pval;}
break;
case 6:
#line 348 "yacc.y"
	{yyval.pval = yyvsp[-1].pval;}
break;
case 7:
#line 349 "yacc.y"
	{yyval.pval = yyvsp[0].pval;}
break;
case 8:
#line 350 "yacc.y"
	{yyval.pval = yyvsp[0].pval;}
break;
case 9:
#line 351 "yacc.y"
	{yyval.pval = yyvsp[0].pval;}
break;
case 10:
#line 352 "yacc.y"
	{yyval.pval = yyvsp[0].pval;}
break;
case 11:
#line 353 "yacc.y"
	{yyval.pval = yyvsp[-1].pval;}
break;
case 12:
#line 356 "yacc.y"
	{printf( "Reconocida una condicion simple\n"); yyval.pval = yyvsp[0].pval;}
break;
case 13:
#line 357 "yacc.y"
	{printf( "Reconocida una condicion multiple\n");yyval.pval = yyvsp[0].pval;}
break;
case 14:
#line 359 "yacc.y"
	{yyval.pval = crearNodo(LOWER,yyvsp[-2].pval,yyvsp[0].pval);}
break;
case 15:
#line 360 "yacc.y"
	{yyval.pval = crearNodo(UPPER,yyvsp[-2].pval,yyvsp[0].pval);}
break;
case 16:
#line 361 "yacc.y"
	{yyval.pval = crearNodo(EQUALLOWER,yyvsp[-2].pval,yyvsp[0].pval);}
break;
case 17:
#line 362 "yacc.y"
	{yyval.pval = crearNodo(EQUALUPPER,yyvsp[-2].pval,yyvsp[0].pval);}
break;
case 18:
#line 363 "yacc.y"
	{yyval.pval = crearNodo(EQUAL,yyvsp[-2].pval,yyvsp[0].pval);}
break;
case 19:
#line 364 "yacc.y"
	{yyval.pval = crearNodo(NOTEQUAL,yyvsp[-2].pval,yyvsp[0].pval);}
break;
case 20:
#line 366 "yacc.y"
	{yyval.pval = crearNodo(NEGATION,NULL,yyvsp[0].pval);}
break;
case 21:
#line 367 "yacc.y"
	{yyval.pval = crearNodo(OR,yyvsp[-2].pval,yyvsp[0].pval);}
break;
case 22:
#line 368 "yacc.y"
	{yyval.pval = crearNodo(AND,yyvsp[-2].pval,yyvsp[0].pval);}
break;
case 23:
#line 371 "yacc.y"
	{printf( "Reconocido un if\n");yyval.pval = crearNodo(IF,yyvsp[-4].pval,yyvsp[-1].pval);}
break;
case 24:
#line 373 "yacc.y"
	{printf( "Reconocido un if else\n"); yyval.pval = crearNodo(ELSE,yyvsp[-4].pval,yyvsp[-1].pval);}
break;
case 25:
#line 375 "yacc.y"
	{printf( "Reconocida una asignacion\n");yyval.pval = crearNodo(ASIGNATION,crearHoja(yyvsp[-2].ival),yyvsp[0].pval);}
break;
case 26:
#line 377 "yacc.y"
	{printf( "Reconocida una asignacion especial\n");yyval.pval = crearNodo(AUTOSUM,crearHoja(yyvsp[-2].ival),yyvsp[0].pval);}
break;
case 27:
#line 378 "yacc.y"
	{printf( "Reconocida una asignacion especial\n");yyval.pval = crearNodo(AUTOSUBSTRACTION,crearHoja(yyvsp[-2].ival),yyvsp[0].pval);}
break;
case 28:
#line 379 "yacc.y"
	{printf( "Reconocida una asignacion especial\n");yyval.pval = crearNodo(AUTOMULTIPLICATION,crearHoja(yyvsp[-2].ival),yyvsp[0].pval);}
break;
case 29:
#line 380 "yacc.y"
	{printf( "Reconocida una asignacion especial\n");yyval.pval = crearNodo(AUTODIVISION,crearHoja(yyvsp[-2].ival),yyvsp[0].pval);}
break;
case 30:
#line 382 "yacc.y"
	{printf( "Reconocida una suma\n"); yyval.pval = crearNodo(SUM,yyvsp[-2].pval,yyvsp[0].pval);}
break;
case 31:
#line 384 "yacc.y"
	{printf( "Reconocida una resta\n");yyval.pval = crearNodo(SUBSTRACTION,yyvsp[-2].pval,yyvsp[0].pval);}
break;
case 32:
#line 386 "yacc.y"
	{yyval.pval = yyvsp[0].pval;}
break;
case 33:
#line 388 "yacc.y"
	{printf( "Reconocida una multiplicacion\n"); yyval.pval = crearNodo(MULTIPLICATION,yyvsp[-2].pval,yyvsp[0].pval);}
break;
case 34:
#line 390 "yacc.y"
	{printf( "Reconocida una division\n"); yyval.pval = crearNodo(DIVISION,yyvsp[-2].pval,yyvsp[0].pval);}
break;
case 35:
#line 392 "yacc.y"
	{yyval.pval = yyvsp[0].pval;}
break;
case 36:
#line 394 "yacc.y"
	{yyval.ival = TYPEFLOAT;}
break;
case 37:
#line 396 "yacc.y"
	{yyval.pval = crearHoja(yyvsp[0].ival);}
break;
case 38:
#line 397 "yacc.y"
	{yyval.pval = crearHoja(yyvsp[0].ival);}
break;
case 39:
#line 398 "yacc.y"
	{yyval.pval = yyvsp[-1].pval;}
break;
case 40:
#line 400 "yacc.y"
	{variableDeclarada *v = new variableDeclarada; v->posicion = yyvsp[0].ival;v->siguiente = NULL; yyval.vval = v;}
break;
case 41:
#line 401 "yacc.y"
	{variableDeclarada *v = new variableDeclarada; v->posicion = yyvsp[0].ival;v->siguiente = yyvsp[-2].vval; yyval.vval = v;}
break;
case 42:
#line 403 "yacc.y"
	{actualizarTipoVariables(yyvsp[-3].vval,yyvsp[-1].ival);}
break;
case 43:
#line 404 "yacc.y"
	{}
break;
case 44:
#line 406 "yacc.y"
	{}
break;
case 45:
#line 408 "yacc.y"
	{yyval.pval = crearNodo(WHILE,yyvsp[-4].pval,yyvsp[-1].pval);}
break;
case 46:
#line 410 "yacc.y"
	{yyval.pval = crearNodo(REPEAT,yyvsp[-5].pval,yyvsp[-1].pval);}
break;
case 47:
#line 412 "yacc.y"
	{printf( "Reconocido un display\n");yyval.pval = crearNodo(DISPLAY,NULL,crearHoja(yyvsp[0].ival));}
break;
#line 2325 "y.tab.cpp"
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
