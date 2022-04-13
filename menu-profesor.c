#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu-profesor.h"
//#include "profesor.h"

/*void MenuProfesor ( char* NombreProfesor, alumnos *valumnos , horario *vhorario, calificaciones  *vcalificaciones){

    int x;
    printf("\n Bienvenido al  menu profesor, elige una de las siguientes \n");
	do{
    printf("1: Listado de alumnos\n");
    printf("2: Horario\n");
    printf("3: Calificaciones\n");
    printf("4: Salir del menu profesor \n");
    	fflush(stdin);
    scanf("%i",&x);

    }while(x<1 || x>4);

  switch(x){
        case 1: printf("Listado de alumnos\n");
				listar_alumnos();break;
        case 2: printf("Horario\n");
				listar_horario();break;
		case 3: printf("Calificaciones\n");
				listar_calificaciones();break;
    }

    printf("\nHa salido del menu profsor\n");
    system("PAUSE");

return;

}






void listar_alumnos(){
char aux;
FILE *Alumnos;  

Alumnos=fopen("Alumnos.txt","r");
if (Alumnos == NULL)
{
    printf("Error al abrir el fichero");
    exit(1);
}

while(aux != EOF) {
    aux = fgetc(Alumnos);
    printf("%c",aux);

}
fclose(Alumnos);
}



void listar_horarios(){
char aux;
FILE *Horario;  

Horario=fopen("Horarios.txt","r");
if (Horario == NULL)
{
    printf("Error al abrir el fichero");
    exit(1);
}

while(aux != EOF) {
    aux = fgetc(Horario);
    printf("%c",aux);

}
fclose(Horario);
}


void listar_calificaciones(){
char aux;
FILE *Calificaciones;  

Calificaciones=fopen("Calificaciones.txt","r");
if (Calificaciones) == NULL)
{
    printf("Error al abrir el fichero");
    exit(1);
}

while(aux != EOF) {
    aux = fgetc(Calificacione);
    printf("%c",aux);

}
fclose(Calificaciones);
}
*/
