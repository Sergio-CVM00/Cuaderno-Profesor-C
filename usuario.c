#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "usuario.h"
//Usuario cargar y guardar
void cargar_usuarios(usuario **usu){

    char linea[200];
    char *token;
    FILE *f;

    nUsuario=0;

    f=fopen("Usuarios.txt","r+");

    if(f==NULL){
        puts("Error de apertura");
    }else{
                rewind(f);
                  *usu=malloc(1*sizeof(usuario));

                    while(fgets(linea,200,f)!=NULL){
                        *usu=(usuario*)realloc((*usu),(nUsuario+1)*sizeof(usuario));
                        if((*usu)==NULL){
                            puts("No hay memoria suficiente");
                        }
                        else{
                            token=strtok(linea,"-");
                            (*usu)[nUsuario].id_usuario=atoi(token);

                            token=strtok(NULL,"-");
                            strcpy((*usu)[nUsuario].nombre_usuario,token);

                            token=strtok(NULL,"-");
                            strcpy((*usu)[nUsuario].perfil_usuario,token);

                            token=strtok(NULL,"-");
                            strcpy((*usu)[nUsuario].usuario,token);

                            token=strtok(NULL,"\n");
                            strcpy((*usu)[nUsuario].contrasena,token);

                            nUsuario++;
                            //printf("\n nUsuario: %i",nUsuario);
                        }
              		}

     fclose(f);
    }
}

void guardar_usuarios(usuario **usu){
	FILE *f;
	int i;
	f=fopen("Usuarios.txt","w");
	for(i=0;i<nUsuario;i++){
		fprintf(f,"%i-%s-%s-%s-%s\n",(*usu)[i].id_usuario,(*usu)[i].nombre_usuario,(*usu)[i].perfil_usuario,(*usu)[i].usuario,(*usu)[i].contrasena);
	}
    fclose(f);
}
