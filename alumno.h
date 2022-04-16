#ifndef _ALUMNOS_H_
#define __ALUMNOS_H_
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


//ESTRUCTURA ALUMNO
typedef struct{
    int id_alum;
    char nombre_alum[21];
    char direc_alum[31];
    char local_alum[31];
    char curso[31];
    char grupo[11];
}alumno;
int nAlumno;
//Cabecera: void cargar_alumnos(alumno **alum)
//Precondicion: fichero Alumnos.txt
//Postcondicion: carga los datos de alumnos en el sistema.
void cargar_alumnos(alumno **alum);

//Cabecera: void guardar_usuarios(usuario *usu);
//Precondicion: fichero Usuarios.txt
//Postcondicion: guarda los datos de usuarios en el txt.
void guardar_alumnos(alumno *alum);

#endif