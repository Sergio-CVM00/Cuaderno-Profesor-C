//test git sergio
//He modificado desde MI RAMA, hago un commit de los cambios que he hecho.
//Pusheo esos cambios a MI RAMA para tenerlos guardado en github.

//Cuando quieras llevar los cambios de ese fichero a la rama MAIN.
//Dentro de github desktop te colocas en la rama main, vas a la opcion de "branch/rama"
//PULSAS "merge into current branch" seleccionas la rama de la cual quieras traer esos cambios.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <ctime>
#include "menu-admin.h"

void usuarios_alta( ){
{
    *Vusuarios=realloc((equipo *)(*vEquipos),((*nEquipos)+1)*sizeof(equipo));

    printf("INTRODUCE LA ID DE EQUIPO (2 caracteres numéricos):\n");
    scanf(" %2s",(*vUsuarios)[*nUsuarios].id);

    printf("INTRODUCE EL NOMBRE COMPLETO (40 caracteres max.):\n");
    scanf(" %40s",(*vUsuarios)[*nUsuarios].nombre);

    (*usuarios)++;
}

void alumnos_alta(alumno *vAlumno, int *nAlumno){
int menuAnadir,i,j,auxiliar1,auxiliar2;
   do {
            printf("\nSeleccione una opcion:\n");
            printf("1: Dar de alta Alumno \n");
            printf("2: Dar de baja Alumno\n");
            fflush(stdin);
            scanf("%i", &menuAnadir);
              }while(menuAnadir<1 || menuAnadir>2);
    switch (menuAnadir){

        case 1:
            fflush(stdin);
            printf("\nIntroduce el identificador del nuevo alumno\n");
            gets((vAlumno)[*nAlumno].id_alum);
            fflush(stdin);
            printf("\nIntroduce el nombre del nuevo alumno\n");
            gets((vAlumno)[*nAlumno].nombre_alum);
            fflush(stdin);
            printf("\nIntroduce la direccion del nuevo alumno\n");
            gets((vAlumno)[*nAlumno].direc_alum);
            fflush(stdin);
            printf("\nIntroduce la localidad del nuevo alumno\n");
            gets((vAlumno)[*nAlumno].local_alum);
            fflush(stdin);
            printf("\nIntroduce el curso del nuevo alumno\n");
            gets((vAlumno)[*nAlumno].curso);
            printf("\nIntroduce el grupo del nuevo alumno\n");
            gets((vAlumno)[*nAlumno].grupo);
            (*nAlumno)++;
            printf("Correctamente anadido\n");

        case 2:
            printf("\nIntroduce el identificador del alumno que desea eliminar\n");
            gets(eliminarA);
            for(j=0;j<(*nAlumno);j++){
            if(strcmp((vAlumno)[j].id_alum,eliminarA)==0){
            auxiliar2=j;
                }
            }

            for(j=auxiliar2;j+1<(*nAlumno);j++){ ///////////////////////////////////////////////////////
            strcpy((vAlumno)[j].nombre_alum,(vAlumno)[j+1].nombre_alum);
            strcpy((vAlumno)[j].direc_alum,(vAlumno)[j+1].direc_alum);
            strcpy((vAlumno)[j].local_alum,(vAlumno)[j+1].local_alum);
            strcpy((vAlumno)[j].curso,(vAlumno)[j+1].curso);
            strcpy((vAlumno)[j].grupo,(vAlumno)[j+1].grupo);
           //PARA ENTEROS (vAlumno)[j].precio=(vAlumno)[j+1].precio;
            

            (*nAlumno)--;
            printf("\nEl Alumno se elimino correctamente\n");
        }
            
     
    

     }