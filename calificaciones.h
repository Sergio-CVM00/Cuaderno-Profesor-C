
#ifndef _CALIFICACIONES_H_
#define __CALIFICACIONES_H_
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

//ESTRUCTURA CALIFICACIONES
typedef struct{
    char fecha_calif[11];
    char descrip_calif[31];
    int id_materia;
    int id_alum;
    int valor_cal;
}calificaciones;

int nCalificaciones;
//Cabecera: void cargar_calificaciones(calificaciones **cali);
//Precondicion: fichero Calificaciones.txt
//Postcondicion: guarda los datos de calificaciones en el txt.
void cargar_calificaciones(calificaciones **cali);

//Cabecera: void guardar_calificaciones(calificaciones *cali);
//Precondicion: fichero Calificaciones.txt
//Postcondicion: guarda los datos de calificaciones en el txt.
void guardar_calificaciones(calificaciones **cali);

void mostrar_calificacion(calificaciones *cali, int pos);
void mostrar_calificaciones(calificaciones *cali);
void modificar_calificaciones(calificaciones **cali,int pos);
#endif
