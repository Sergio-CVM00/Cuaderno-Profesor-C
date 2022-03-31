#ifndef _MENUADMIN_H_
#define _MENUADMIN_H_
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

//ESTRUCTURA MATRICULAS
typedef struct{
    int id_materia; //debe coinidir con el id de alguna materia
    char id_alum[5]; //debe coincidir con el id de algun alumno
}matricula;

int nMatricula;

//Cabecera: void cargar_matriculas(matricula **mtri);
//Precondicion: fichero Matricula.txt
//Postcondicion: carga los datos de matriculas.txt en el sistema
void cargar_matriculas(matricula **mtri);

//Cabecera: void guardar_matriculas(matricula *mtri);
//Precondicion: fichero Matricula.txt
//Postcondicion: guarda los datos de matriculas en el fichero txt-
void guardar_matriculas(matricula *mtri);

#endif