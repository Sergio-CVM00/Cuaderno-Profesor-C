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
void guardar_alumnos(alumno **alum);

//Cabecera: int comprobar_id_alumno(alumno *alum, int id_alum);
//Precondicion: estrucutra de alumno y un id de alumno
//Postcondicion: devuelve 0 si no existe alumno.Devuelve 1 si existe alumno.
int comprobar_id_alumno(alumno *alum, int id_alum);

//Cabecera:void mostrar_alumno(alumno *alum,int pos);
//Precondicion: estrucutura de alumno y pos para la posicion del vector
//Postcondicion: muestra los datos del alumno  pasado por pos.
void mostrar_alumno(alumno *alum,int pos);

//Cabecera:void mostrar_alumnos(alumno *alum);
//Precondicion: estrucutra de alumno
//Postcondicion: muestra todos los alumnos del sistema enumerados.
void mostrar_alumnos(alumno *alum);

#endif
