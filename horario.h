#ifndef _HORARIOS_H_
#define _HORARIOS_H_
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//ESTRUCTURA HORARIOS
typedef struct{
    int id_profesor;
    int dia_clase;
    int hora_clase;
    int id_materia;
}horario;

int nHorario;

//Cabecera: void cargar_horarios(horario **hor);
//Precondicion: fichero Horarios.txt
//Postcondicion: carga los datos de horarios en el sistema.
void cargar_horarios(horario **hor);

//Cabecera: void guardar_horarios(calificaciones *cali);
//Precondicion: fichero Horarios.txt
//Postcondicion: guarda los datos de horarios en el txt.
void guardar_horarios(horario **hor);
int comprobar_id_horario(horario *hor, int id_profesor,int id_materia,int dia_clase,int hora_clase);
void mostrar_horario(horario *hor, int pos);
void mostrar_horarios(horario *hor);
#endif
