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
int comprobar_id_horario(horario *hor, int id_profesor,int id_materia,int dia_clase,int hora_clase)
{
    int i = 0;
    while (i < nHorario && hor[i].id_profesor != id_profesor && hor[i].id_materia != id_materia && hor[i].dia_clase != dia_clase && hor[i].hora_clase != hora_clase)
    {
        i++;
    }
    if (i == nHorario)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void mostrar_horario(horario *hor, int pos)
{
    printf("1-id_profesor || 2-dia_clase || 3-hora_clase || 4-id_materia\n");

    if (pos > 0 && pos < nHorario)
    {
        printf("\n%i/%i/%i/%i\n", hor[pos].id_profesor, hor[pos].dia_clase, hor[pos].hora_clase, hor[pos].id_materia);
    }
}
void mostrar_horarios(horario *hor)
{
    printf("\n            LISTA DE HORARIOS\n\n");
    printf("1-id_profesor || 2-dia_clase || 3-hora_clase || 4-id_materia\n");
    int i;
    for (i = 0; i < nHorario; i++)
    {
        printf("%i-%i/%s/%s/%s/%s\n", i, hor[i].id_profesor, hor[i].dia_clase, hor[i].hora_clase, hor[i].id_materia);
    }
}
