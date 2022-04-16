#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "materia.h"
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
                  *mat=malloc(1*sizeof(materia));

                    while(fgets(linea,160,f)!=NULL){
                    *mat=(materia*)realloc((*mat),(nMateria+1)*sizeof(materia));

                     if((*mat)==NULL){
                        puts("No hay memoria suficiente");
                    }
                    else{
                        token=strtok(linea,"-");
                        (*mat)[nMateria].id_materia=atoi(token);

                        token=strtok(NULL,"-");
                        strcpy((*mat)[nMateria].nombre_materia,token);

                        token=strtok(NULL,"\n");
                         strcpy((*mat)[nMateria].abrev_materia,token);
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
