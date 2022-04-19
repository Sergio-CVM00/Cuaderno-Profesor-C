#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "materia.h"
void cargar_materias(materia **mate){

    char linea[160];
    char *token;
    FILE *f;

    nMateria=0;

    f=fopen("Materias.txt","r+");

    if(f==NULL){
        puts("Error de apertura");
    }else{
    		
                rewind(f);
                  *mate=malloc(1*sizeof(materia));

                    while(fgets(linea,160,f)!=NULL){
                    *mate=(materia*)realloc((*mate),(nMateria+1)*sizeof(materia));
					
                     if((*mate)==NULL){
                        puts("No hay memoria suficiente");
                    }
                    else{
                        token=strtok(linea,"-");
                        (*mate)[nMateria].id_materia=atoi(token);

                        token=strtok(NULL,"-");
                        strcpy((*mate)[nMateria].nombre_materia,token);

                        token=strtok(NULL,"\n");
                        strcpy((*mate)[nMateria].abrev_materia,token);
                        nMateria++;
                        }
               }
     fclose(f);
    }
    
}

void guardar_materias(materia **mate){
	FILE *f;
	int i;
	f=fopen("Materias.txt","w");
	for(i=0;i<nMateria;i++){
		fprintf(f,"%i-%s-%s\n",(*mate)[i].id_materia,(*mate)[i].nombre_materia,(*mate)[i].abrev_materia);
	}
    fclose(f);
}
