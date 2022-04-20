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
int comprobar_id_materia(materia *mate, int id_materia)
{
    int i = 0;
    while (i < nMateria && mate[i].id_materia != id_materia)
    {
        i++;
    }
    if (i == nMateria)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}


void mostrar_materia(materia *mate, int pos)
{
    printf("1-id || 2-nombre || 3-abreviatura\n");

    if (pos > 0 && pos < nMateria)
    {
        printf("\n%i/%s/%s\n", mate[pos].id_materia, mate[pos].nombre_materia, mate[pos].abrev_materia);
    }
}
void mostrar_materias(materia *mate)
{
    printf("\n            LISTA DE MATERIAS\n\n");
    printf("1-id || 2-nombre || 3-abreviatura\n");
    int i;
    for (i = 0; i < nMateria; i++)
    {
        printf("%i-%i/%s/%s\n", i, mate[i].id_materia, mate[i].nombre_materia, mate[i].abrev_materia);
    }
}
