#ifndef _MATERIA_H_
#define _MATERIA_H_
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//ESTRUCTURA MATERIAS
typedef struct{
    int id_materia;
    char nombre_materia[51];
    char abrev_materia[4];
}materia;
int nMateria;

//Cabecera: void cargar_materias(materia **mat);
//Precondicion: fichero Materias.txt
//Postcondicion: carga los datos de materias del txt en el sistema.
void cargar_materias(materia **mat);

//Cabecera: void guardar_materias(materia *mat);
//Precondicion: fichero Materias.txt
//Postcondicion: guarda los datos de materias en el txt.
void guardar_materias(materia **mat);

#endif
