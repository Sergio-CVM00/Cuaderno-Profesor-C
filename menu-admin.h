#ifndef _MENUADMIN_H_
#define _MENUADMIN_H_
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include "usuario.h"
#include "calificaciones.h"
#include "alumno.h"
#include "materia.h"
#include "horario.h"
#include "matricula.h"




// --------------- USUARIOS-----------------------
//Cabecera: void darAlta_Usuarios(usuario **usu);
//Precondicion: recibir struct usuarios
//Postcondicion: crear un usuario nuevo
void darAlta_Usuarios(usuario **usu);

//Cabecera: void darBaja_Usuarios(usuario **usu, int op)
//Precondicion: recibir un id usuario existente.
//Postcondicion: eliminar un usuario indicado
void darBaja_Usuarios(usuario **usu, int op);

//Cabecera: void Modificar_usuarios(usuario **usu);
//Precondicion: .
//Postcondicion: modifica un usuario existente.
void Modificar_usuarios(usuario **usu);

//Cabecera: void Listar_usuarios(usuario **usu);
//Precondicion: .
//Postcondicion: Muestra por pantalla todos los usuarios del sistema
void Listar_usuarios(usuario **usu);

//Cabecera: Menu_Usuarios(usuario **usu);
//Precondicion: .
//Postcondicion: Menu para gestionar todas las opciones que tiene un admin para usuarios.
Menu_Usuarios(usuario **usu);



// --------------- ALUMNOS -----------------------
//Cabecera: void MenuAlumno(alumno *alum,alumno **alum);
//Precondicion:
//Postcondicion: usuario escoge 1 de las 5 opciones para tratar la info de un/os alumno/s
void MenuAlumno(alumno *alum,matricula *mtri,materia *mate);

//Cabecera: void dar_alta_alumno(alumno **alum);
//Precondicion: alumno no dado de alta en el sistema
//Postcondicion: da de alta a un alumno del fichero Alumnos.txt
void dar_alta_alumno(alumno **alum);

//Cabecera: void eliminar_alumno(alumno **alum, int op);
//Precondicion: alumno dado de alta en el sistema
//Postcondicion: elimina alumno del fichero Alumnos.txt
void eliminar_alumno(alumno **alum, int op);

//Cabecera: void modificar_alumno(alumno **alum);
//Precondicion: alumno dado de alta en el sistema
//Postcondicion: modifica  datos de alumno del fichero Alumnos.txt
void modificar_alumno(alumno **alum);

//Cabecera: void listar_alumno(alumno *alum);
//Precondicion: alumnos dados de alta en el sistema
//Postcondicion: muestra los datos de todos los alumnos  del fichero Alumnos.txt
void listar_alumno(alumno *alum);



// --------------- MATRICULAS -----------------------
//Cabecera: void guardar_matriculas(matricula *mtri);
//Precondicion: fichero Matricula.txt
//Postcondicion: guarda los datos de matriculas en el fichero txt-
void menu_matricula_alumnos(matricula *mtri,alumno *alum,materia *mate);

//Cabecera: void listar_materias_alumno(alumno *alum,materia *mate,matricula *mtri);
//Precondicion: fichero Matricula.txt
//Postcondicion: guarda los datos de matriculas en el fichero txt-
void listar_materias_alumno(matricula *mtri,alumno **alum);


//Cabecera: void guardar_matriculas(matricula *mtri);
//Precondicion: fichero Matricula.txt
//Postcondicion: guarda los datos de matriculas en el fichero txt-
void crear_matricula_alumno(matricula **mtri,materia **mate,alumno **alum);



// --------------- MATERIAS -----------------------
//Cabecera: void guardar_matriculas(matricula *mtri);
//Precondicion: fichero Matricula.txt
//Postcondicion: guarda los datos de matriculas en el fichero txt-
void eliminar_materias_alumno( matricula **mtri);

//Cabecera: void guardar_matriculas(matricula *mtri);
//Precondicion: fichero Matricula.txt
//Postcondicion: guarda los datos de matriculas en el fichero txt-
//void modificar_materias_alumno(alumno **alum,materia **mate,matricula **matri);
void modificar_materias_alumno(matricula **mtri,alumno **alum,materia **mate);

//MATERIAS
//Cabecera: void MenuMaterias(materia *mate, materia **mate);
//Precondicion:
//Postcondicion: usuario escoge 1 de las opciones para tratar la info de de una/s materia/s
void MenuMaterias(materia *mate);

//Cabecera: void dar_alta_materia(materia **mate);
//Precondicion: materia no dada de alta en el sistema
//Postcondicion: da de alta a una materia del fichero Materias.txt
void dar_alta_materia(materia **mate);

//Cabecera: void eliminar_materia(materia **mate, int op);
//Precondicion: materia dada de alta en el sistema
//Postcondicion: elimina alumno del fichero Materias.txt
void eliminar_materia(materia **mate, int op);

//Cabecera: void modificar_materia(materia **mate);
//Precondicion: materia dada de alta en el sistema
//Postcondicion: modifica  datos de materias del fichero Materias.txt
void modificar_materia(materia **mate);

//Cabecera: void listar_alumno(alumno *alum);
//Precondicion: materias dadas de alta en el sistema
//Postcondicion: muestra los datos de todas los materias  del fichero Materias.txt
void listar_materia(materia *mate);

// --------------- FUNCIONS AUXILIARES -----------------------
//Cabecera: void listar_alumno(alumno *alum);
//Precondicion: materias dadas de alta en el sistema
//Postcondicion: muestra los datos de todas los materias  del fichero Materias.txt
void salto(char *str);



#endif
