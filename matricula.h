#ifndef _MATRICULAS_H_
#define _MATRICULAS_H_
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//ESTRUCTURA MATRICULAS
typedef struct{
    int id_materia; //debe coinidir con el id de alguna materia
    int id_alum; //debe coincidir con el id de algun alumno

}matricula;
int nMatricula;

//Cabecera: void cargar_matricula(matricula **mtri);
//Precondicion: fichero Matriculas.txt
//Postcondicion: carga los datos de matriculas del txt en el sistema.
void cargar_matricula(matricula **mtri);
//Cabecera: void guardar_matricula(matricula *mtri);
//Precondicion: fichero Matriculas.txt
//Postcondicion: guarda los datos de matriculas en el txt.
void guardar_matricula(matricula **mtri);

//Cabecera: void guardar_matricula(matricula *mtri);
//Precondicion: estructura de matricula ,un id de materia y un id de alumno.
//Postcondicion: devuelve 0 si no existe matricula.Devuelve 1 si existe matricula.
int comprobar_matricula(matricula *matri,int id_alum,int id_materia);

//Cabecera: void guardar_matricula(matricula *mtri);
//Precondicion: estructura de matricula  y pos para la posicion del vector.
//Postcondicion:muestra los datos de la matricula  pasado por pos.
void mostrar_matricula(matricula *mtri, int pos);

//Cabecera: void guardar_matricula(matricula *mtri);
//Precondicion: estructura de matricula.
//Postcondicion: muestras las matricula del sistema enumaradas.
void mostrar_matriculas(matricula *mtri);

#endif
