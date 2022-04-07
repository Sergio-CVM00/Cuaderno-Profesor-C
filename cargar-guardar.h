#ifndef _CARGARYGUARDAR_H_
#define _CARGARYGUARDAR_H_
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
/*
El admin tiene que tener acceso a todos los datos
-usuarios
-alumnos
-calificaciones
-horario
-materia
-matriculas

En el .C menu-admin tendremos funciones que seran los menus del admin con los que el opere en el sistema.
En el .h menu-admin tendremos las estructuras "struct" de los datos necesarios

De esta forma, nos ahorramos llamar a todas las funciones de carga, solo se carga lo que se va a utilizar.
*/

//USUARIOS
typedef struct{
    int id_usuario;
    char nombre_usuario[19];
    char perfil_usuario[29]; //administrador o profesor
    char usuario[6];  // con el que accedemos al sistema
    char contrasena[10];
}usuario;

//ESTRUCTURA ALUMNO
typedef struct{
    int id_alum;
    char nombre_alum[21];
    char direc_alum[31];
    char local_alum[31];
    char curso[31];
    char grupo[11];
}alumno;

//ESTRUCTURA CALIFICACIONES
typedef struct{
    char fecha_calif[11];
    char descrip_calif[31];
    int id_materia;
    int id_alum;
    int valor_cal;
}calificaciones;

//ESTRUCTURA HORARIOS
typedef struct{
    int id_profesor; //debe coincidir cin un ident de usuario,id_usuario con perfil de profesor en USUARIOS.TXT
    int dia_clase; //entre el 1 y el 5
    int hora_clase;
    int id_materia;//debe coincidir con el id_materia de una materia (en materias.txt)
}horario;

//ESTRUCTURA MATRICULAS
typedef struct{
    int id_materia; //debe coinidir con el id de alguna materia
    int id_alum; //debe coincidir con el id de algun alumno
}matricula;
//ESTRUCTURA MATERIAS
typedef struct{
    int id_materia;
    char nombre_materia[51];
    char abrev_materia[4];
}materia;




int nUsuario;
int nAlumno;
int nCalificaciones;
int nHorario;
int nMateria;



//funciones de carga

//Cabecera: usuario* CargarUsuarios(usuario *vUsuario, int *n);
//Precondicion: fichero Usuarios.txt
//Postcondicion: carga los datos de usuarios en el sistema.
void cargar_usuarios(usuario **usu);

//Cabecera: void guardar_usuarios(usuario *usu);
//Precondicion: fichero Usuarios.txt
//Postcondicion: guarda los datos de usuarios en el txt.
void guardar_usuarios(usuario *usu);

//Cabecera: void cargar_alumnos(alumno **alum)
//Precondicion: fichero Alumnos.txt
//Postcondicion: carga los datos de alumnos en el sistema.
void cargar_alumnos(alumno **alum);

//Cabecera: void guardar_usuarios(usuario *usu);
//Precondicion: fichero Usuarios.txt
//Postcondicion: guarda los datos de usuarios en el txt.
void guardar_alumnos(alumno *alum);

//Cabecera: void cargar_calificaciones(calificaciones **cali);
//Precondicion: fichero Calificaciones.txt
//Postcondicion: guarda los datos de calificaciones en el txt.
void cargar_calificaciones(calificaciones **cali);

//Cabecera: void guardar_calificaciones(calificaciones *cali);
//Precondicion: fichero Calificaciones.txt
//Postcondicion: guarda los datos de calificaciones en el txt.
void guardar_calificaciones(calificaciones *cali);

//Cabecera: void cargar_horarios(horario **hor);
//Precondicion: fichero Horarios.txt
//Postcondicion: carga los datos de horarios en el sistema.
void cargar_horarios(horario **hor);

//Cabecera: void guardar_horarios(calificaciones *cali);
//Precondicion: fichero Horarios.txt
//Postcondicion: guarda los datos de horarios en el txt.
void guardar_horarios(horario *hor);

//Cabecera: void cargar_materias(materia **mat);
//Precondicion: fichero Materias.txt
//Postcondicion: carga los datos de materias del txt en el sistema.
void cargar_materias(materia **mat);

//Cabecera: void guardar_materias(materia *mat);
//Precondicion: fichero Materias.txt
//Postcondicion: guarda los datos de materias en el txt.
void guardar_materias(materia *mat);


void cargar_matricula(matricula **mtri);

void guardar_matricula(matricula *mtri);






#endif
