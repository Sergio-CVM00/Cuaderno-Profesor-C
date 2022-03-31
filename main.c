#include <stdio.h>
#include "cargar-guardar.h"

int main(){
    //cargar usuarios del sistema.
    usuario *usu;
    cargar_usuarios(&usu);

    printf("\nnUsuarios: %i",nUsuarios);
    //llamada a menu principal.
    return 0;
    //dsgsgr
}