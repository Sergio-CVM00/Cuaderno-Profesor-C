#ifndef _HORARIOS_H_
#define _HORARIOS_H_
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//ESTRUCTURA HORARIOS
typedef struct{
    int id_profesor; //debe coincidir cin un ident de usuario,id_usuario con perfil de profesor en USUARIOS.TXT
    int dia_clase; //entre el 1 y el 5
    int hora_clase;
    int id_materia;//debe coincidir con el id_materia de una materia (en materias.txt)
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
#endif
