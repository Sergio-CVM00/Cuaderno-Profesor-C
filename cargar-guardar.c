
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
		fprintf(f,"%i-%s-%s-%s-%s-%s\n",hor[i].id_alum,alum[i].nombre_alum,alum[i].direc_alum,alum[i].local_alum,alum[i].curso,alum[i].grupo);
	}
    fclose(f);
}

//CALIFICACIONES cargar y guardar:
void cargar_calificaciones(calificaciones **cali){

    char linea[160];
    char *token;
    FILE *f;

    nCalificaciones=0;

    f=fopen("Calificaciones.txt","r+");

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
	f=fopen("Calificaciones.txt","w+");
	for(i=0;i<nCalificaciones;i++){
		fprintf(f,"%s-%s-%i-%i-%i\n",cali[i].fecha_calif,cali[i].descrip_calif,cali[i].id_materia,cali[i].id_alum,cali[i].valor_cal);
	}
    fclose(f);
}

//HORARIO cargar y guardar
void cargar_horarios(horario **hor){

    char linea[160];
    char *token;
    FILE *f;

    nHorario=0;

    f=fopen("Horarios.txt","r+");

    if(f==NULL){
        puts("Error de apertura");
    }else{
                rewind(f);
                  *hor=malloc(1*sizeof(horario));

                    while(fgets(linea,160,f)!=NULL){
                    *hor=(horario*)realloc((*hor),(nHorario+1)*sizeof(horario));

                     if((*hor)==NULL){
                        puts("No hay memoria suficiente");
                    }
                    else{
                        token=strtok(linea,"-");
                        (*hor)[nHorario].id_profesor=atoi(token);

                        token=strtok(NULL,"-");
                        (*hor)[nHorario].dia_clase=atoi(token);

                        token=strtok(NULL,"-");
                        (*hor)[nHorario].hora_clase=atoi(token);

                        token=strtok(NULL,"\n");
                        (*hor)[nHorario].id_materia=atoi(token);

                        nHorario++;
                        }
               }
     fclose(f);
    }
}

void guardar_horarios(horario *hor){
	FILE *f;
	int i;
	f=fopen("Horarios.txt","w+");
	for(i=0;i<nHorario;i++){
		fprintf(f,"%i-%i-%i-%i\n",hor[i].id_profesor,hor[i].dia_clase,hor[i].hora_clase,hor[i].id_materia);
	}
    fclose(f);
}

//MATERIA cargar y guardar
void cargar_materias(materia **mat){

    char linea[160];
    char *token;
    FILE *f;

    nMateria=0;

    f=fopen("Materias.txt","r+");

    if(f==NULL){
        puts("Error de apertura");
    }else{
                rewind(f);
                  *mat=malloc(1*sizeof(horario));

                    while(fgets(linea,160,f)!=NULL){
                    *mat=(horario*)realloc((*mat),(nMateria+1)*sizeof(horario));

                     if((*mat)==NULL){
                        puts("No hay memoria suficiente");
                    }
                    else{
                        token=strtok(linea,"-");
                        (*mat)[nMateria].id_profesor=atoi(token);

                        token=strtok(NULL,"-");
                        strcpy((*mat)[nMateria].descrip_calif,token);

                        token=strtok(NULL,"\n");
                        (*mat)[nMateria].id_materia=atoi(token);

                        nHorario++;
                        }
               }
     fclose(f);
    }
}

void guardar_materias(materia *mat){
	FILE *f;
	int i;
	f=fopen("Materias.txt","w+");
	for(i=0;i<nMateria;i++){
		fprintf(f,"%i-%s-%s\n",mat[i].id_materia,mat[i].nombre_materia,mat[i].abrev_materia);
	}
    fclose(f);
}

//MATRICULA cargar y guardar
void cargar_matricula(matricula **mtri){

    char linea[160];
    char *token;
    FILE *f;

    nMatricula=0;

    f=fopen("Matriculas.txt","r+");

    if(f==NULL){
        puts("Error de apertura");
    }else{
                rewind(f);
                  *mtri=malloc(1*sizeof(horario));

                    while(fgets(linea,160,f)!=NULL){
                    *mtri=(horario*)realloc((*mtri),(nMatricula+1)*sizeof(horario));

                     if((*mtri)==NULL){
                        puts("No hay memoria suficiente");
                    }
                    else{
                        token=strtok(linea,"-");
                        (*mtri)[nMatricula].id_profesor=atoi(token);

                        token=strtok(NULL,"\n");
                        strcpy((*mtri)[nMatricula].descrip_calif,token);

                        nHorario++;
                        }
               }
     fclose(f);
    }
}

void guardar_materias(matricula *mtri){
	FILE *f;
	int i;
	f=fopen("Matriculas.txt","w+");
	for(i=0;i<nMatricula;i++){
		fprintf(f,"%i-%s-%s\n",mtri[i].id_materia,mtri[i].id_alum);
	}
    fclose(f);
}