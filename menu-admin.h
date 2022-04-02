#ifndef _MENUADMIN_H_
#define _MENUADMIN_H_
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//USUARIOS
typedef struct{
    int id_usuario;
    char nombre_usuario[19];
    char perfil_usuario[29]; //administrador o profesor
    char usuario[4]; // con el que accedemos al sistema
    char contrasena[7];
}usuario;
//ESTRUCTURA ALUMNO
typedef struct{
    int id_alum;
    char nombre_alum[19];
    char direc_alum[29];
    char local_alum[29];
    char curso[29];
    char grupo[9];
}alumno;
//ESTRUCTURA MATRICULAS
typedef struct{
    int id_materia; //debe coinidir con el id de alguna materia
    char id_alum[5]; //debe coincidir con el id de algun alumno
}matricula;
int nUsuario;
int nAlumno;
int nMatricula;

//Cabecera: void cargar_matriculas(matricula **mtri);
//Precondicion: fichero Matricula.txt
//Postcondicion: carga los datos de matriculas.txt en el sistema
void cargar_matriculas(matricula **mtri);

//Cabecera: void guardar_matriculas(matricula *mtri);
//Precondicion: fichero Matricula.txt
//Postcondicion: guarda los datos de matriculas en el fichero txt-
void guardar_matriculas(matricula *mtri);


void MenuAlumno(alumno *alum,alumno **alum);
dar_alta_alumno(alumno **alum);
void eliminar_usuario(alumno **alum, int op);
void modificar_alumno(alumno **alum);


//funciones auxiliares
void salto(char *str);
int comprobar_id(alumno *alum, char *id_alum);
void mostrar_alumno(alumno *alum,int pos);
void mostrar_alumnos(alumno *alum);
void guardar_alumno(alumno *alum)
#endif