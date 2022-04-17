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

    //CARGAR
    cargar_matricula(&mtri); //operativo
    cargar_alumnos(&alum); //operativo
    cargar_horarios(&hor); //operativo
    cargar_materias(&mat); //operativo
    cargar_calificaciones(&cali); //operativo
    //cargar_usuarios(&usu); // pendiente de solucionar (maximo 2 usuarios)
    //printf("\n nUsuario: %i", nUsuario);


    //GUARDAR
    /*
    guardar_matricula(&mtri);
    guardar_alumnos(&alum);
    guardar_materias(&mat);
    guardar_horarios(&hor);
    guardar_calificaciones(&cali);
    */


    guardar_usuarios(&usu);






    //listar_materias_alumno(alum,mtri);
    //llamada a menu principal.
    return 0;
    //dsgsgr

}
