#include <stdio.h>
#include "cargar-guardar.h"


int main(){
    //cargar usuarios del sistema.
    usuario *usu;
    alumno *alum;
    calificaciones *cali;
    horario *hor;
    materia *mat;
    matricula *mtri;

    cargar_usuarios(&usu);
    /*cargar_alumnos(&alum);
    cargar_calificaciones(&cali);*/

    printf("\nnUsuario: %i",nUsuario);
    //llamada a menu principal.
    return 0;
    //dsgsgr
}
