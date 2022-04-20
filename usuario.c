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

int iniciar_sesion(usuario **usu){
        char pass[20];
        int pos,rep=2,id;
        printf("\n          INICIO SESION\n");
                do{
                        printf("\nIntroduce tu id: ");
                        fflush(stdin);
                        scanf("%i",&id);
                        printf("Introduce la contrasenia: ");
                        fflush(stdin);
                        fgets(pass,20,stdin);
                        pos=pos_usuario(*usu,id); //posicion del usuario en el vector del sistema

                                if(comprobar_usuario(*usu,id)==0 || strcmp(pass,(*usu)[pos].contrasena)!=0){
                                        printf("\nEl usuario o contrasenia son incorrectos quieres salir (1-Si/2-No): ");
                                        scanf("%i",&rep);
                                if(rep==1){return -1;}
                                }

                                system("cls");
                }while((comprobar_usuario(*usu,id)==0 || strcmp(pass,(*usu)[pos].contrasena)!=0) && rep==2);

        return pos;
}

void registrarse(usuario **usu){
    int existe,id;
    system("cls");

    *usu=(usuario*)realloc((*usu),(nUsuario+1)*sizeof(usuario));
            do{
                existe=0;
                printf("Introduce tu id: ");
                fflush(stdin);
                scanf("%i",&id);
                existe=(comprobar_usuario(*usu,id));
                if(existe==1){printf("Este id ya existe\n");}
            }while(existe==1);
            (*usu)[nUsuario].id_usuario = id;

        printf("Introduce tu nombre de usuario: ");
        fflush(stdin);
        fgets((*usu)[nUsuario].nombre_usuario,19,stdin);
        fflush(stdin);

        printf("Introduce tu perfil de usuario: ");
        fflush(stdin);
        fgets((*usu)[nUsuario].perfil_usuario,29,stdin);

        fflush(stdin);

        printf("Introduce tu tipo de usuario: ");
        fflush(stdin);
        fgets((*usu)[nUsuario].usuario,6,stdin);
        fflush(stdin);

        printf("Introduce una contrasenia: ");
        fflush(stdin);
        fgets((*usu)[nUsuario].contrasena,10,stdin);
        fflush(stdin);

        nUsuario++;
        guardar_usuarios(usu);
}

int pos_usuario(usuario *usu, int id){
    //Devuelve la posicion del usuario en el sistema. (vector estructura)
    int i=0;
    while(i<nUsuario && usu[i].id_usuario==id){i++;}
    return i;

}

int comprobar_usuario(usuario *usu,int id){
    //0 usuario no existe -- 1 usuario existe
    int i=0;
    while(i<nUsuario && usu[i].id_usuario == id){i++;}
    if(i==nUsuario){
        return 0;
    }else{
        return 1;
    }
}
