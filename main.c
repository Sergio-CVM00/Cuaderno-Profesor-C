#include <stdio.h>
#include "menu-admin.h"
int main(){

    //cargar datos del sistema.
    usuario *usu;
    alumno *alum;
    calificaciones *cali;
    horario *hor;
    materia *mate;
    matricula *mtri;


    //CARGAR
    cargar_matricula(&mtri); //operativo
    cargar_alumnos(&alum); //operativo
    cargar_horarios(&hor); //operativo
    cargar_materias(&mate); //operativo
    cargar_calificaciones(&cali); //operativo
    cargar_usuarios(&usu); // pendiente de solucionar (maximo 2 usuarios)
    //printf("\n nUsuario: %i", nMateria);





    /*
    -----HORARIOS comprobacaciones-----

    listar_horarios(hor); //operativo -- MODIFICADO
    anadir_horas_profesor(&hor); //operativo --MODIFICADO
    eliminar_horario(&hor); //operativo --MODIFICADO
    modificar_horario(&hor,&mate); //operativo --MODIFICADO
    MenuHorarios(&hor,&mate); //operativo --MODIFICADO
    */


    return 0;

}
