#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "matricula.h"
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
                  *mtri=malloc(1*sizeof(matricula));

                    while(fgets(linea,160,f)!=NULL){
                    *mtri=(matricula*)realloc((*mtri),(nMatricula+1)*sizeof(matricula));

                     if((*mtri)==NULL){
                        puts("No hay memoria suficiente");
                    }
                    else{
                        token=strtok(linea,"-");
                        (*mtri)[nMatricula].id_materia=atoi(token);
                        //strcpy((*mtri)[nMatricula].id_materia,token);

                        token=strtok(NULL,"\n");
                        (*mtri)[nMatricula].id_alum=atoi(token);
                        //strcpy((*mtri)[nMatricula].id_alum,token);

                        nMatricula++;
                        }
               }
     fclose(f);
    }
}

void guardar_matricula(matricula *mtri){
	FILE *f;
	int i;
	f=fopen("Matriculas.txt","w+");
	for(i=0;i<nMatricula;i++){
		fprintf(f,"%i-%s-%s\n",mtri[i].id_materia,mtri[i].id_alum);
	}
    fclose(f);
}
