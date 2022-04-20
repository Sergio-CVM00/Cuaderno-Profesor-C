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

                        token=strtok(NULL,"\n");
                        (*mtri)[nMatricula].id_alum=atoi(token);

                        nMatricula++;
                        }
               }
     fclose(f);
    }
}

void guardar_matricula(matricula **mtri){
	FILE *f;
	int i;
	f=fopen("Matriculas.txt","w");
	for(i=0;i<nMatricula;i++){
		fprintf(f,"%i-%i\n",(*mtri)[i].id_materia,(*mtri)[i].id_alum);
	}
    fclose(f);
}
int comprobar_matricula(matricula *matri,int id_alum,int id_materia){
	int i = 0;
    while (i < nMatricula && matri[i].id_alum != id_alum && matri[i].id_materia != id_materia  )
    {
        i++;
    }
    if (i == nMatricula)
    {
        return 0;
    }
    else
    {
        return 1;
    }
	
}
void mostrar_matricula(matricula *mtri, int pos)
{
    printf("1-id_alum || 2-id_materia \n");

    if (pos > 0 && pos < nMatricula)
    {
        printf("\n%i/%i\n", mtri[pos].id_alum, mtri[pos].id_materia);
    }
}
void mostrar_matriculas(matricula *mtri)
{
    printf("\n            LISTA DE MATRICULAS\n\n");
    printf("1-id_alum || 2-id_materia\n");
    int i;
    for (i = 0; i < nMatricula; i++)
    {
        printf("%i-%i/%i\n", i, mtri[i].id_alum, mtri[i].id_materia);
    }
}
