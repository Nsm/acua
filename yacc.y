

%{

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

%}


%token ID
%token NUMBER
%token SUM
%token SUBSTRACTION
%token MULTIPLICATION
%token DIVISION
%token AUTOSUM
%token AUTOSUBSTRACTION
%token AUTOMULTIPLICATION
%token AUTODIVISION
%token ASIGNATION
%token NEGATION
%token AND
%token OR
%token STRING
%token SEMICOLON
%token COMMA
%token SEPARATOR
%token LOWER
%token UPPER
%token BRACKET
%token RIGHTBRACKET
%token BRACE
%token RIGHTBRACE
%token EQUAL
%token EQUALLOWER
%token EQUALUPPER
%token NOTEQUAL
%token COMMENT
%token IF
%token ELSE
%token WHILE
%token DEFINE
%token DISPLAY
%token TYPEFLOAT
%token TYPESTRING
%token REPEAT
%token UNTIL


%start programa  /* DEFINE EL START SYMBOL*/

/* REGLAS */


%%





 programa : bloque_declaracion cuerpo {printf( "Reconocido el programa :)\n");};
 | cuerpo {printf( "Reconocido el programa :)\n");};

 cuerpo : sentencia {printf( "Reconocido el cuerpo\n");};
 | cuerpo sentencia;

 sentencia : asig SEMICOLON ;
 | asig_especial SEMICOLON ;
 | desicion ;
 | mientras ;
 | ciclo_hasta ;
 | escribir SEMICOLON;

 comp_logico : LOWER ;
 | UPPER ;
 | EQUALLOWER ;
 | EQUALUPPER ;
 | EQUAL ;

 condicion : condicionsimple {printf( "Reconocida una condicion simple\n");};
 | condicionmultiple {printf( "Reconocida una condicion multiple\n");};

 condicionsimple : exp comp_logico exp {printf( "");};

 condicionmultiple : NEGATION condicionsimple {printf( "");};
 | condicionsimple OR condicionsimple {printf( "");};
 | condicionsimple AND condicionsimple {printf( "");};
 | condicionsimple NEGATION condicionsimple {printf( "");};

 desicion : IF BRACKET condicion RIGHTBRACKET BRACE cuerpo RIGHTBRACE {printf( "Reconocido un if\n");};
 | IF BRACKET condicion RIGHTBRACKET BRACE cuerpo RIGHTBRACE ELSE BRACE cuerpo RIGHTBRACE {printf( "Reconocido un if\n");};

 asig : ID ASIGNATION exp {printf( "Reconocida una asignacion\n");};

 asig_especial : ID  AUTOSUM  exp {printf( "Reconocida una asignacion especial\n");};
 | ID  AUTOSUBSTRACTION  exp {printf( "Reconocida una asignacion especial\n");};
 | ID  AUTOMULTIPLICATION  exp {printf( "Reconocida una asignacion especial\n");};
 | ID  AUTODIVISION  exp {printf( "Reconocida una asignacion especial\n");};

 exp : exp  SUM  termino {printf( "Reconocida una suma\n");};

 exp : exp  SUBSTRACTION  termino {printf( "Reconocida una resta\n");};

 exp : termino {printf( "");};

 termino : termino  MULTIPLICATION  factor {printf( "");};

 termino : termino  DIVISION  factor {printf( "");};

 termino : factor {printf( "");};

 tipo_dato : TYPESTRING | TYPEFLOAT;

 factor : ID {printf( "");};
 | NUMBER {printf( "");};
 | BRACKET  exp  RIGHTBRACKET {printf( "");};

 lista_variables : ID {printf( "");};
 | ID COMMA lista_variables {printf( "");};

 declaracion : lista_variables  SEPARATOR  tipo_dato SEMICOLON {printf( "");};
 | declaracion lista_variables  SEPARATOR  tipo_dato SEMICOLON {printf( "");};

 bloque_declaracion : DEFINE BRACE declaracion RIGHTBRACE {printf( "Reconocido un bloque de declaracion\n");};

 mientras : WHILE BRACKET condicion RIGHTBRACKET BRACE cuerpo RIGHTBRACE {printf( "Reconocido un while\n");};

 ciclo_hasta : REPEAT BRACE cuerpo RIGHTBRACE UNTIL BRACKET condicion RIGHTBRACKET {printf( "Reconocido un Until\n");};

 escribir : DISPLAY STRING {printf( "Reconocido un display\n");};

%%

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


