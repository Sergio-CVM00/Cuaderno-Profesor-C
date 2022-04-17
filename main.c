#include <stdio.h>

#include "menu-admin.h"



int main(){
    //cargar usuarios del sistema.
    usuario *usu;
    alumno *alum;
    calificaciones *cali;
    horario *hor;
    materia *mat;
    matricula *mtri;

	printf("hola mundo");

	cargar_usuarios(&usu);
   /* cargar_matricula(&mtri);
    cargar_calificaciones(&cali);*/
	
    printf("\numero de alumnos: %i",nAlumno);
    //listar_materias_alumno(alum,mtri);
    //llamada a menu principal.
    return 0;
    //dsgsgr

}
