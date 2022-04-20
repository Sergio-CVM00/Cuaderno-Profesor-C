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

void mostrar_calificacion(calificaciones *cali, int pos)
{
    printf("1-fecha_calif || 2-descrip_calif || 3-id_materia || 4-id_alum || 5-valor_cal\n");

    if (pos > 0 && pos < nCalificaciones)
    {
        printf("\n%s/%s/%i/%i/%i\n", cali[pos].fecha_calif, cali[pos].descrip_calif, cali[pos].id_materia, cali[pos].id_alum,cali[pos].valor_cal);
    }
}

void mostrar_calificaciones(calificaciones *cali)
{
    printf("\n            LISTA DE CALIFICACIONES\n\n");
    printf("1-fecha_calif || 2-descrip_calif || 3-id_materia || 4-id_alum || 5-valor_cal\n");
    int i;
    for (i = 0; i < nCalificaciones; i++)
    {
        printf("%i-%s/%s/%i/%i/%i\n", i,  cali[i].fecha_calif, cali[i].descrip_calif, cali[i].id_materia, cali[i].id_alum,cali[i].valor_cal);
    }
}

void modificar_calificaciones(calificaciones **cali,int pos)
{
	int a;
	int valor_cal_;
	mostrar_calificaciones(*cali);
    do
    {
        printf("\nIntroduce el numero : ");
        scanf("%i", &pos);
    } while (pos < 0 || pos >= nCalificaciones);
    printf("Desea modificar la calificacion del alumno %i introduzca 1, si no 0 :  ",(*cali)[pos].id_alum);
    scanf("%i",&a);
    if(a==1){
    	printf("Introduce el nuevo valor de la calificacion completo: ");
    	scanf("%i",&valor_cal_);
    	(*cali)[pos].valor_cal = valor_cal_; 
    	
	}
	if(a==0){
		mostrar_calificaciones(*cali);
	}
	else{
		mostrar_calificaciones(*cali);
	}                                       
}
