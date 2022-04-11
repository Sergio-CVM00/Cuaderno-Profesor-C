//Todavia falta unos cuantos errores que pulir //



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cargar-guardar.h"

int iniciarsesion(usuario **usu){
char nick_[20];
int existe,id;
system("cls");
printf("\n          BIENVENIDO AL CUADERNO DEL PROFESOR\n");
          do{
            printf("\nIntroduce tu nombre: ");
            fflush(stdin);
        	fgets((*usu)[nUsuario].contrasenia,6,stdin);
        	salto((*usu)[nUsuario].contrasenia);
        	fflush(stdin);
        	
            printf("Introduce la contrasenia: ");
            fflush(stdin);
        	fgets((*usu)[nUsuario].contrasenia,10,stdin);
        	salto((*usu)[nUsuario].contrasenia);
        	fflush(stdin);
            pos=posnombre(*usu,nombre);

                if(comprobarnombre(*usu,nombre)==0  (strcmp(pass,(usu)[pos].pass)!=0)){
                printf("\nEl usuario o contrasenia son incorrectos quieres salir (1-Si/2-No): ");
                scanf("%i",&rep);
                if(rep==1){return -1;}
                }

                system("cls");
            }while((comprobar_nombre(usu,nombre)==0)  (strcmp(pass,(usu)[pos].pass)!=0) && rep==2));



strcpy((usu)[pos].estado,"ON");


return pos;


}

