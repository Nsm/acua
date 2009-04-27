#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}


int get_evento (c){
    //aca deberia hacerse un if por cada columna en la tabla de funciones que retorne el numero para el evneto correspondiente
    if(){
    }
}

int yylex (void){
	int estado = 0;
	int estado final = 13;
	while (estado != estado final)
    {
        columna = get_evento (c);            /*obtener la columna de la matriz*/
        (*proceso [estado] [columna]) ();
        estado = nuevo_estado [estado] [columna];
        get (c);
    }
    unget (c)                 /*si corresponde*/
    modifica la variable yylval              /*posición en tabla de símbolos ó -1*/
    return ;
}
