//Todavia falta unos cuantos errores que pulir //
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cargar-guardar.h"

int iniciarsesion(usuario **usu){
char nick[20];
char contrasena[10];
int existe, id;
system("cls");
printf("\n          BIENVENIDO AL CUADERNO DEL PROFESOR\n");
          do{
            printf("\nIntroduce tu nombre: ");
            fflush(stdin);
        	fgets((*usu)[nUsuario].contrasena,6,stdin);
        	salto((*usu)[nUsuario].contrasena);
        	fflush(stdin);
        	
            printf("Introduce la contrasenia: ");
            fflush(stdin);
        	fgets((*usu)[nUsuario].contrasena,10,stdin);
        	salto((*usu)[nUsuario].contrasena);
        	fflush(stdin);
        	
            existe=existenombre(*usu,nick);

                if (strcmp(contrasena,(*usu)[existe].contrasena)!=0){
                printf("\nEl usuario o contrasena son incorrectos quieres salir (1-Si/2-No): ");
                scanf("%i",&id);
                if(id==1){return -1;}
                }

                system("cls");
            }while(strcmp(contrasena,(*usu)[existe].contrasena)==0 )  ;
			 id==2;
			 return id ;

strcpy((*usu)[existe].contrasena,"ON");


return existe;


}
*/
