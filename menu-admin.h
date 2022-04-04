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
    int id_alum; //debe coincidir con el id de algun alumno
}matricula;
//ESTRUCTURA MATERIAS
typedef struct{
    int id_materia;
    char nombre_materia[49];
    char abrev_materia[3];
}materia;

int nUsuario;
int nAlumno;
int nMatricula;
int nMateria;


//Cabecera: void guardar_matriculas(matricula *mtri);
//Precondicion: fichero Matricula.txt
//Postcondicion: guarda los datos de matriculas en el fichero txt-
void MenuAlumno(alumno *alum,alumno **alum);

//Cabecera: void guardar_matriculas(matricula *mtri);
//Precondicion: fichero Matricula.txt
//Postcondicion: guarda los datos de matriculas en el fichero txt-
void dar_alta_alumno(alumno **alum);

//Cabecera: void guardar_matriculas(matricula *mtri);
//Precondicion: fichero Matricula.txt
//Postcondicion: guarda los datos de matriculas en el fichero txt-
void eliminar_alumno(alumno **alum, int op);

//Cabecera: void guardar_matriculas(matricula *mtri);
//Precondicion: fichero Matricula.txt
//Postcondicion: guarda los datos de matriculas en el fichero txt-
void modificar_alumno(alumno **alum);

//Cabecera: void guardar_matriculas(matricula *mtri);
//Precondicion: fichero Matricula.txt
//Postcondicion: guarda los datos de matriculas en el fichero txt-
void listar_alumno(alumno *alum);

//Cabecera: void guardar_matriculas(matricula *mtri);
//Precondicion: fichero Matricula.txt
//Postcondicion: guarda los datos de matriculas en el fichero txt-
void matricula_alumnos(alumno **alum, alumno **materia, matricula **matricula);

//Cabecera: void guardar_matriculas(matricula *mtri);
//Precondicion: fichero Matricula.txt
//Postcondicion: guarda los datos de matriculas en el fichero txt-
void listar_materias_alumno(alumno **alum,materia **mate,matricula **matricula);


//Cabecera: void guardar_matriculas(matricula *mtri);
//Precondicion: fichero Matricula.txt
//Postcondicion: guarda los datos de matriculas en el fichero txt-
void crear_matricula_alumno(alumno **alum,materia **mate,matricula **matri);


//Cabecera: void guardar_matriculas(matricula *mtri);
//Precondicion: fichero Matricula.txt
//Postcondicion: guarda los datos de matriculas en el fichero txt-
void eliminar_materias_alumno(alumno **alum,materia **mate ,matricula **matri);


//Cabecera: void guardar_matriculas(matricula *mtri);
//Precondicion: fichero Matricula.txt
//Postcondicion: guarda los datos de matriculas en el fichero txt-
void modificar_materias_alumno(alumno **alum,materia **mate,matricula **matri)


//MATERIAS

void MenuMaterias(materia *mate, materia **mate);

void dar_alta_materia(materia **mate);
//funciones auxiliares alumnos
void salto(char *str);
int comprobar_id_alumno(alumno *alum, int *id_alum);
void mostrar_alumno(alumno *alum,int pos);
void mostrar_alumnos(alumno *alum);
void guardar_alumno(alumno *alum);
//funciones auxiliares materias
int comprobar_id_materia(materia *mate, int *id_materia);
void mostrar_materias(materia *mate);
void mostrar_materia(materia *mate, int pos);
void guardar_materia(materia *mate);
#endif