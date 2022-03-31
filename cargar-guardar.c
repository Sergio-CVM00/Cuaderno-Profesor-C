
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "cargar-guardar.h"

//
//USUARIOS 
//
void cargar_usuarios(usuario **usu){

    char linea[160];
    char *token;
    FILE *f;

    nUsuario=0;

    f=fopen("Usuarios.txt","r+");

    if(f==NULL){
        puts("Error de apertura");
    }else{
                rewind(f);
                  *usu=malloc(1*sizeof(usuario));

                    while(fgets(linea,160,f)!=NULL){
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
                        }
               }
     fclose(f);
    }
}

void guardar_usuarios(usuario *usu){
	FILE *f;
	int i;
	f=fopen("Usuarios.txt","w+");
	for(i=0;i<nUsuario;i++){
		fprintf(f,"%i-%s-%s-%s-%s\n",usu[i].id_usuario,usu[i].nombre_usuario,usu[i].perfil_usuario,usu[i].usuario,usu[i].contrasena);
	}
    fclose(f);
}

//ALUMNOS cargar y guardar:
void cargar_alumnos(alumno **alum){

    char linea[160];
    char *token;
    FILE *f;

    nAlumno=0;

    f=fopen("Alumnos.txt","r+");

    if(f==NULL){
        puts("Error de apertura");
    }else{
                rewind(f);
                  *alum=malloc(1*sizeof(alumno));

                    while(fgets(linea,160,f)!=NULL){
                    *alum=(alumno*)realloc((*alum),(nAlumno+1)*sizeof(alumno));

                     if((*alum)==NULL){
                        puts("No hay memoria suficiente");
                    }
                    else{
                        token=strtok(linea,"-");
                        (*alum)[nAlumno].id_alum=atoi(token);

                        token=strtok(NULL,"-");
                        strcpy((*alum)[nAlumno].nombre_alum,token);

                        token=strtok(NULL,"-");
                        strcpy((*alum)[nAlumno].direc_alum,token);

                        token=strtok(NULL,"-");
                        strcpy((*alum)[nAlumno].local_alum,token);

                        token=strtok(NULL,"-");
                        strcpy((*alum)[nAlumno].curso,token);

                        token=strtok(NULL,"\n");
                        strcpy((*alum)[nAlumno].grupo,token);

                        nAlumno++;
                        }
               }
     fclose(f);
    }
}

void guardar_alumnos(alumno *alum){
	FILE *f;
	int i;
	f=fopen("Alumnos.txt","w+");
	for(i=0;i<nAlumno;i++){
		fprintf(f,"%i-%s-%s-%s-%s-%s\n",cali[i].id_alum,alum[i].nombre_alum,alum[i].direc_alum,alum[i].local_alum,alum[i].curso,alum[i].grupo);
	}
    fclose(f);
}

//CALIFICACIONES cargar y guardar:
void cargar_calificaciones(calificaciones **cali){

    char linea[160];
    char *token;
    FILE *f;

    nCalificaciones=0;

    f=fopen("calificaciones.txt","r+");

    if(f==NULL){
        puts("Error de apertura");
    }else{
                rewind(f);
                  *cali=malloc(1*sizeof(calificaciones));

                    while(fgets(linea,160,f)!=NULL){
                    *cali=(calificaciones*)realloc((*cali),(nCalificaciones+1)*sizeof(calificaciones));

                     if((*cali)==NULL){
                        puts("No hay memoria suficiente");
                    }
                    else{
                        token=strtok(linea,"-");
                        strcpy((*cali)[nCalificaciones].fecha_calif,token);

                        token=strtok(NULL,"-");
                        strcpy((*cali)[nCalificaciones].descrip_calif,token);

                        token=strtok(NULL,"-");
                        (*cali)[nCalificaciones].id_materia=atoi(token);

                        token=strtok(NULL,"-");
                        (*cali)[nCalificaciones].id_alum=atoi(token);

                        token=strtok(NULL,"\n");
                        (*cali)[nCalificaciones].valor_cal=atoi(token);

                        nCalificaciones++;
                        }
               }
     fclose(f);
    }
}

void guardar_calificaciones(calificaciones *cali){
	FILE *f;
	int i;
	f=fopen("Alumnos.txt","w+");
	for(i=0;i<nCalificaciones;i++){
		fprintf(f,"%s-%s-%i-%i-%i\n",cali[i].fecha_calif,cali[i].descrip_calif,cali[i].id_materia,cali[i].id_alum,cali[i].valor_cal);
	}
    fclose(f);
}

//HORARIO cargar y guardar
