

%{

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

nodo* programa;

nodo * crearNodo(int operacion, nodo * izquierda, nodo * derecha);
nodo * crearHoja(int numeroSimbolo);

%}

%union{
	int  ival;
	nodo *pval;
}


%token <ival> ID
%token <ival> NUMBER
%token <ival> SUM
%token <ival> SUBSTRACTION
%token <ival> MULTIPLICATION
%token <ival> DIVISION
%token <ival> AUTOSUM
%token <ival> AUTOSUBSTRACTION
%token <ival> AUTOMULTIPLICATION
%token <ival> AUTODIVISION
%token <ival> ASIGNATION
%token <ival> NEGATION
%token <ival> AND
%token <ival> OR
%token <ival> STRING
%token <ival> SEMICOLON
%token <ival> COMMA
%token <ival> SEPARATOR
%token <ival> LOWER
%token <ival> UPPER
%token <ival> BRACKET
%token <ival> RIGHTBRACKET
%token <ival> BRACE
%token <ival> RIGHTBRACE
%token <ival> EQUAL
%token <ival> EQUALLOWER
%token <ival> EQUALUPPER
%token <ival> NOTEQUAL
%token <ival> COMMENT
%token <ival> IF
%token <ival> ELSE
%token <ival> WHILE
%token <ival> DEFINE
%token <ival> DISPLAY
%token <ival> TYPEFLOAT
%token <ival> TYPESTRING
%token <ival> REPEAT
%token <ival> UNTIL

%type <pval> programa cuerpo sentencia condicion condicionsimple condicionmultiple desicion asig asig_especial exp termino tipo_dato factor lista_variables declaracion bloque_declaracion mientras ciclo_hasta escribir

%start programa  /* DEFINE EL START SYMBOL*/

/* REGLAS */


%%





 programa : bloque_declaracion cuerpo {printf( "Reconocido el programa :)\n");programa = crearNodo(PROGRAMA,$1,$2);};
 | cuerpo {printf( "Reconocido el programa :)\n");programa = $1;};

 cuerpo : sentencia {printf( "Reconocido el cuerpo\n");$$ = $1;};
 | cuerpo sentencia {$$ = crearNodo(CUERPO,$1,$2);};

 sentencia : asig SEMICOLON {$$ = $1;};
 | asig_especial SEMICOLON {$$ = $1;};
 | desicion {$$ = $1;};
 | mientras {$$ = $1;};
 | ciclo_hasta {$$ = $1;};
 | escribir SEMICOLON {$$ = $1;};


 condicion : condicionsimple {printf( "Reconocida una condicion simple\n"); $$ = $1;};
 | condicionmultiple {printf( "Reconocida una condicion multiple\n");$$ = $1;};

 condicionsimple : exp LOWER exp {$$ = crearNodo(LOWER,$1,$3);};
 | exp UPPER exp {$$ = crearNodo(UPPER,$1,$3);};
 | exp EQUALLOWER exp {$$ = crearNodo(EQUALLOWER,$1,$3);};
 | exp EQUALUPPER exp {$$ = crearNodo(EQUALUPPER,$1,$3);};
 | exp EQUAL exp {$$ = crearNodo(EQUAL,$1,$3);};

 condicionmultiple : NEGATION condicionsimple {$$ = crearNodo(NEGATION,NULL,$2);};
 | condicionsimple OR condicionsimple {$$ = crearNodo(OR,$1,$3);};
 | condicionsimple AND condicionsimple {$$ = crearNodo(AND,$1,$3);};
 

 desicion : IF BRACKET condicion RIGHTBRACKET BRACE cuerpo RIGHTBRACE {printf( "Reconocido un if\n");$$ = crearNodo(IF,$3,$6);};
 | IF BRACKET condicion RIGHTBRACKET BRACE cuerpo RIGHTBRACE ELSE BRACE cuerpo RIGHTBRACE {printf( "Reconocido un if\n");};

 asig : ID ASIGNATION exp {printf( "Reconocida una asignacion\n");$$ = crearNodo(ASIGNATION,crearHoja($1),$3);};

 asig_especial : ID  AUTOSUM  exp {printf( "Reconocida una asignacion especial\n");$$ = crearNodo(AUTOSUM,crearHoja($1),$3);};
 | ID  AUTOSUBSTRACTION  exp {printf( "Reconocida una asignacion especial\n");$$ = crearNodo(AUTOSUBSTRACTION,crearHoja($1),$3);};
 | ID  AUTOMULTIPLICATION  exp {printf( "Reconocida una asignacion especial\n");$$ = crearNodo(AUTOMULTIPLICATION,crearHoja($1),$3);};
 | ID  AUTODIVISION  exp {printf( "Reconocida una asignacion especial\n");$$ = crearNodo(AUTODIVISION,crearHoja($1),$3);};

 exp : exp  SUM  termino {printf( "Reconocida una suma\n"); $$ = crearNodo(SUM,$1,$3);};

 exp : exp  SUBSTRACTION  termino {printf( "Reconocida una resta\n");$$ = crearNodo(SUBSTRACTION,$1,$3);};

 exp : termino {$$ = $1;};

 termino : termino  MULTIPLICATION  factor {printf( "Reconocida una multiplicacion\n"); $$ = crearNodo(MULTIPLICATION,$1,$3);};

 termino : termino  DIVISION  factor {printf( "Reconocida una division\n"); $$ = crearNodo(DIVISION,$1,$3);};

 termino : factor {$$ = $1;};

 tipo_dato : TYPESTRING {$$ = crearHoja($1);};
 | TYPEFLOAT {$$ = crearHoja($1);};

 factor : ID {$$ = crearHoja($1);};
 | NUMBER {$$ = crearHoja($1);};
 | BRACKET  exp  RIGHTBRACKET {$$ = $2;};

 lista_variables : ID {$$ = crearHoja($1);};
 | lista_variables COMMA ID {$$ = crearNodo(COMMA,$1,crearHoja($3));};

 declaracion : lista_variables  SEPARATOR  tipo_dato SEMICOLON {$$ = crearNodo(SEPARATOR,$1,$3);};
 | declaracion lista_variables  SEPARATOR  tipo_dato SEMICOLON {};

 bloque_declaracion : DEFINE BRACE declaracion RIGHTBRACE {$$ = $3;};

 mientras : WHILE BRACKET condicion RIGHTBRACKET BRACE cuerpo RIGHTBRACE {$$ = crearNodo(WHILE,$3,$6);};

 ciclo_hasta : REPEAT BRACE cuerpo RIGHTBRACE UNTIL BRACKET condicion RIGHTBRACKET {$$ = crearNodo(REPEAT,$3,$7);};

 escribir : DISPLAY STRING {printf( "Reconocido un display\n");$$ = crearNodo(DISPLAY,NULL,crearHoja($2));};

%%

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


