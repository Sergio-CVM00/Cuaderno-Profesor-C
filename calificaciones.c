#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "calificaciones.h"
void cargar_calificaciones(calificaciones **cali){

    char linea[300];
    char *token;
    FILE *f;

    nCalificaciones=0;

    f=fopen("Calificaciones.txt","r+");

    if(f==NULL){
        puts("Error de apertura");
    }else{
                rewind(f);
                  *cali=malloc(1*sizeof(calificaciones));

                    while(fgets(linea,300,f)!=NULL){
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
    (*cali)[0].valor_cal = 777;
    strcpy((*cali)[0].descrip_calif, "c es una maravilla");
    /*pruebas:

        (*cali)[1].id_alum = 999
    */
}

void guardar_calificaciones(calificaciones **cali){
	FILE *f;
	int i;
	f=fopen("Calificaciones.txt","w");
	for(i=0;i<nCalificaciones;i++){
		fprintf(f,"%s-%s-%i-%i-%i\n",(*cali)[i].fecha_calif,(*cali)[i].descrip_calif,(*cali)[i].id_materia,(*cali)[i].id_alum,(*cali)[i].valor_cal);
	}
    fclose(f);
}
