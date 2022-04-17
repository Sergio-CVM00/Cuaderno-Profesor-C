#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "horario.h"
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

void guardar_horarios(horario **hor){
	FILE *f;
	int i;
	f=fopen("Horarios.txt","w");
	for(i=0;i<nHorario;i++){
		fprintf(f,"%i-%i-%i-%i\n",(*hor)[i].id_profesor,(*hor)[i].dia_clase,(*hor)[i].hora_clase,(*hor)[i].id_materia);
	}
    fclose(f);
}
