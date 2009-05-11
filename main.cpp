#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CANT_ESTADOS  35
#define CANT_ENTRADAS  22

int nuevo_estado[CANT_ESTADOS - 1][CANT_ENTRADAS] = {{4, 2, 9, 11, 7, 30, 5, 17, 23, 21, 1, 27, 29, 28, 13, 15, 19, 20, 25, 26, 3, 0},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 34, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 3, 34},
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
{endAutoDivision, endAutoDivision, endAutoDivision, endAutoDivision, endAutoDivision, endAutoDivision, endAutoDivision, endAutoDivision, endAutoDivision, endAutoDivision, endAutoDivision, endAutoDivision, endAutoDivision, endAutoDivision, endAutoDivision, endAutoDivision, endAutoDivision, endAutoDivision, endAutoDivision, endAutoDivision, endAutoDivision, endAutoDivision}};



FILE *archivo;
int yylex();

struct simbolo{
	char nombre[30];
	simbolo *siguiente;
};

simbolo * tablaSimbolos = NULL;

char yyval[30];

int main(int argc,char * argv[])
{
    if(argc != 2){
        printf("\nDebe pasar el nombre del archivo como parametro\n");
        exit(1);
    }
    if((archivo = fopen(argv[1],"r")) == NULL){
        printf("\nEl archivo %s no existe\n",argv[1]);
        exit(1);
    }

    int tipoToken;
    while(!feof(archivo)){
        tipoToken = yylex();
        if(tipoToken != -1){
        	printf("\nReconocido token tipo: %s valor: %s\n",getTypeString(tipoToken),yyval);
        }
    }

    fclose(archivo);
    return 0;
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
	while (estado != estado_final && !(estado == 0 && feof(archivo)))
    {
        c = fgetc(archivo);
        columna = get_evento(c);
        token = (*funciones[estado][columna])(c);
        estado = nuevo_estado [estado] [columna];
    }
	if(!feof(archivo)){
		ungetc(c,archivo);
	}

    return token;
}

void addToSimbolTable(char * name){
	//agrega un nuevo simbolo a la lista
	simbolo * nuevo = new simbolo;
	strcpy(nuevo->nombre,name);
	if(tablaSimbolos != NULL){
		nuevo->siguiente = tablaSimbolos;
	}
	tablaSimbolos = nuevo;
}

//Funcion auxiliar para mejorar el debug
char* getTypeString(int tipoToken){
	switch (tipoToken) {
		case 1:
			return "Id";
			break;
		case 2:
			return "Number";
			break;
		case 3:
			return "Sum";
			break;
		case 4:
			return "Substraction";
			break;
		case 5:
			return "Multiplication";
			break;
		case 6:
			return "Division";
			break;
		case 7:
			return "AutoSum";
			break;
		case 8:
			return "AutoSubstraction";
			break;
		case 9:
			return "AutoMultiplication";
			break;
		case 10:
			return "AutoDivision";
			break;
		case 11:
			return "Asignation";
			break;
		case 12:
			return "Negation";
			break;
		case 13:
			return "And";
			break;
		case 14:
			return "Or";
			break;
		case 15:
			return "String";
			break;
		case 16:
			return "Semicolon";
			break;
		case 17:
			return "Comma";
			break;
		case 18:
			return "Separator";
			break;
		case 19:
			return "Lower";
			break;
		case 20:
			return "Upper";
			break;
		case 21:
			return "Bracket";
			break;
		case 22:
			return "RightBracket";
			break;
		case 23:
			return "Brace";
			break;
		case 24:
			return "RightBrace";
			break;
		case 25:
			return "Equal";
			break;
		case 26:
			return "EqualLower";
			break;
		case 27:
			return "EqualUpper";
			break;
		case 28:
			return "NotEqual";
			break;
		case 29:
			return "Comment";
			break;
		case 30:
			return "If";
			break;
		case 31:
			return "Else";
			break;
		case 32:
			return "While";
			break;
		case 33:
			return "Define";
			break;
		case 34:
			return "Display";
			break;
		default:
			return "";
			break;
	}
}


int startId(char c){
	memset(yyval,'\0',sizeof(yyval));
	yyval[strlen(yyval)] = c;
    return 0;
}
int startNumber(char c){
	memset(yyval,'\0',sizeof(yyval));
	yyval[strlen(yyval)] = c;
    return 0;
}
int startSum(char c){
	memset(yyval,'\0',sizeof(yyval));
    return 0;

}
int startSubstraction(char c){
	memset(yyval,'\0',sizeof(yyval));
    return 0;
}
int startMultiplication(char c){
	memset(yyval,'\0',sizeof(yyval));
    return 0;
}
int startDivision(char c){
	memset(yyval,'\0',sizeof(yyval));
    return 0;
}
int startAutoSum(char c){
	memset(yyval,'\0',sizeof(yyval));
    return 0;
}
int startAutoSubstraction(char c){
	memset(yyval,'\0',sizeof(yyval));
    return 0;
}
int startAutoMultiplication(char c){
	memset(yyval,'\0',sizeof(yyval));
    return 0;
}
int startAutoDivision(char c){
	memset(yyval,'\0',sizeof(yyval));
    return 0;
}
int startAsignation(char c){
	memset(yyval,'\0',sizeof(yyval));
    return 0;
}
int startNegation(char c){
	memset(yyval,'\0',sizeof(yyval));
    return 0;
}
int startAnd(char c){
	memset(yyval,'\0',sizeof(yyval));
    return 0;
}
int startOr(char c){
	memset(yyval,'\0',sizeof(yyval));
    return 0;
}
int startString(char c){
	memset(yyval,'\0',sizeof(yyval));
    return 0;
}
int startSemicolon(char c){
	memset(yyval,'\0',sizeof(yyval));
    return 0;
}
int startComma(char c){
	memset(yyval,'\0',sizeof(yyval));
    return 0;
}
int startSeparator(char c){
	memset(yyval,'\0',sizeof(yyval));
    return 0;
}
int startLower(char c){
	memset(yyval,'\0',sizeof(yyval));
    return 0;
}
int startUpper(char c){
	memset(yyval,'\0',sizeof(yyval));
    return 0;
}
int startBracket(char c){
	memset(yyval,'\0',sizeof(yyval));
    return 0;
}
int startRightBracket(char c){
	memset(yyval,'\0',sizeof(yyval));
    return 0;
}
int startBrace(char c){
	memset(yyval,'\0',sizeof(yyval));
    return 0;
}
int startRightBrace(char c){
	memset(yyval,'\0',sizeof(yyval));
    return 0;
}
int startEqual(char c){
	memset(yyval,'\0',sizeof(yyval));
    return 0;
}
int startEqualLower(char c){
	memset(yyval,'\0',sizeof(yyval));
    return 0;
}
int startEqualUpper(char c){
	memset(yyval,'\0',sizeof(yyval));
    return 0;
}
int startNotEqual(char c){
	memset(yyval,'\0',sizeof(yyval));
    return 0;
}
int startComment(char c){
	memset(yyval,'\0',sizeof(yyval));
    return 0;
}
int contId(char c){
	yyval[strlen(yyval)] = c;
    return 0;
}
int contNumber(char c){
	yyval[strlen(yyval)] = c;
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
	yyval[strlen(yyval)] = c;
    return 0;
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
	if(!reservedWord(yyval)){
		//identificador
		printf("Reconocido el id: %s",yyval);
		addToSimbolTable(yyval);
		return 1;
	}else{
		//palabra reservada
		int tipoToken = reservedWord(yyval);
		memset(yyval,'\0',sizeof(yyval));
		return tipoToken;
	}
}
int endNumber(char c){
    return 2;
}
int endSum(char c){
    return 3;
}
int endSubstraction(char c){
    return 4;
}
int endMultiplication(char c){
    return 5;
}
int endDivision(char c){
    return 6;
}
int endAutoSum(char c){
    return 7;
}
int endAutoSubstraction(char c){
    return 8;
}
int endAutoMultiplication(char c){
    return 9;
}
int endAutoDivision(char c){
    return 10;
}
int endAsignation(char c){
    return 11;
}
int endNegation(char c){
    return 12;
}
int endAnd(char c){
    return 13;
}
int endOr(char c){
    return 14;
}
int endString(char c){
    return 15;
}
int endSemicolon(char c){
    return 16;
}
int endComma(char c){
    return 17;
}
int endSeparator(char c){
    return 18;
}
int endLower(char c){
    return 19;
}
int endUpper(char c){
    return 20;
}
int endBracket(char c){
    return 21;
}
int endRightBracket(char c){
    return 22;
}
int endBrace(char c){
    return 23;
}
int endRightBrace(char c){
    return 24;
}
int endEqual(char c){
    return 25;
}
int endEqualLower(char c){
    return 26;
}
int endEqualUpper(char c){
    return 27;
}
int endNotEqual(char c){
    return 28;
}
int endComment(char c){
    return 29;
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
		return 30;
	}else if(strcmp(id,"else") == 0){
		return 31;
	}else if(strcmp(id,"while") == 0){
		return 32;
	}else if(strcmp(id,"define") == 0){
		return 33;
	}else if(strcmp(id,"display") == 0){
		return 34;
	}else{
		return 0;
	}
}
