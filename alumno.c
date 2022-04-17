#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "alumno.h"
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
		fprintf(f,"%i-%s-%s-%s-%s-%s\n",alum[i].id_alum,alum[i].nombre_alum,alum[i].direc_alum,alum[i].local_alum,alum[i].curso,alum[i].grupo);
	}
    fclose(f);
}
