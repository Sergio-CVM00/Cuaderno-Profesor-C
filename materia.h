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

//Cabecera: int comprobar_id_materia(materia *mate, int id_materia);
//Precondicion: estructura de materia y un id de materia.
//Postcondicion: devuelve 0 si no existe materia.Devuelve 1 si existe materia.
int comprobar_id_materia(materia *mate, int id_materia);

//Cabecera: void mostrar_materias(materia *mate);
//Precondicion: estructura de materia.
//Postcondicion: muestras las materias del sistema enumaradas.
void mostrar_materias(materia *mate);

//Cabecera: void mostrar_materia(materia *mate, int pos);
//Precondicion: estructura de materia  y pos para la posicion del vector.
//Postcondicion:muestra los datos de la materia  pasado por pos.
void mostrar_materia(materia *mate, int pos);

#endif
