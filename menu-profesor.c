#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
//#include "profesor.h"

void MenuProfesor (usuario *usu,alumno *alum  ,horario *hor,calificaciones *cali);
void ficha_alumno(usuario *usu,alumno *alum,calificaciones *cali,int pos);






void MenuProfesor ( usuario *usu, alumno *alum  ,horario *hor,calificaciones *cali){
    int x;
    printf("\n Bienvenido al  menu profesor, elige una de las siguientes \n");
	do{
    printf("1: Listado de alumnos\n");
    printf("2: Horario\n");
    printf("3: Ficha alumno\n");
    printf("4: Salir del menu profesor \n");
    	fflush(stdin);
    scanf("%i",&x);

    }while(x<1 || x>4);

  switch(x){
        case 1: printf("Listado de alumnos\n");
				listar_alumnos();break;
        case 2: printf("Horario\n");
				void mostrar_horario(usuario *usu,horario *hor,materia *mat, int pos)
				{
					printf("Ingrese su Id :\n");
					scanf("%i",&pos);
	
					printf("1-Id  2-dia_clase  3-hora_clase  4-id_materia  5-nombre_materia\n");

    				if (pos > 0 && pos < nUsuario)
   					 {
        				printf("\n%s/%i/%i/%i/%s\n",hor[pos].id_profesor, hor[pos].dia_clase, hor[pos].hora_clase,hor[pos].id_materia,mat[pos].nombre_materia);
  					  }
				};break;

		case 3: printf("Ficha de alumno\n");
				void ficha_alumno(usuario *usu ,alumno *alum,calificaciones *cali,int pos)
				{
						int y ;
							printf("\n Bienvenido a la ficha de alumno");
							do{
							printf("1: Ficha\n");
							printf("2: Calificaciones\n");
							printf("3: Volver al menu profesor\n");
							fflush(stdin);
							scanf("%i",&y);
							}while(y<1 || y>3);

							switch(y){
									case 1: printf("Ficha del alumno\n");
											void mostrar_alumno(alumno *alum, int pos)
											{

	
												printf("Seleccione el numero del aljmno que quiera ver en cuestion\n");
												scanf("%i",&pos);
	
												printf("1-id  2-nombre_completo  3-direc_alum  4-curso  5-grupo\n");

    											if (pos > 0 && pos < nAlumno)
   												 {
       												 printf("\n%i/%s/%s/%s/%s\n", alum[pos].id_alum, alum[pos].nombre_alum, alum[pos].direc_alum, alum[pos].local_alum, alum[pos].curso,alum[pos].grupo);
  												  }
											};break;
		
									case 2:	printf("Calificaciones\n");
										void listar_calificaciones(alumno *alum, calificaciones *cali,int pos)
										{
											printf("Seleccione el numero del alumno que quiera ver en cuestion\n");
											scanf("%i",&pos);
	
											printf("1-id  2-nombre_completo  3-calificacion");

   											 if (pos > 0 && pos < nAlumno)
   											 {
       											 printf("\n%i/%s/%i\n", alum[pos].id_alum, alum[pos].nombre_alum,cali[pos].valor_cal );
   											 }
										};break;

								}
								system ("PAUSE");
	
								return ;

	
	
};break;



    }

    printf("\nHa salido del menu profsor\n");
    system("PAUSE");

return ;

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

*/

