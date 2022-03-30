#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu-profesor.h"

void MenuProfesor (char *NombreProfesor, alumnos *vAlumnos, horario *vHorarios, calificaciones *vCalificaciones){
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
