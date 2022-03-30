#ifndef _CARGAR_H_
#define _CARGAR_H_
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
    int id_usuario[2];
    char nombre_usuario[19];
    char perfil_usuario[29]; //administrador o profesor
    char usuario[4]; // con el que accedemos al sistema
    char contrasena[7];
}usuario;

typedef struct{
    int dia;
    int mes;
    int ano;
}fecha;

//ESTRUCTURA ALUMNO
typedef struct{
    int id_alum[5];
    char nombre_alum[19];
    char direc_alum[29];
    char local_alum[29];
    char curso[29];
    char grupo[9];
}alumno;

//ESTRUCTURA CALIFICACIONES
typedef struct{
    char fecha_calif[8];
    char descrip_calif[5];
    int id_materia[3];
    int id_alum[5];
    int valor_cal[9];
}calificaciones;

//ESTRUCTURA HORARIOS
typedef struct{
    int id_profesor[2]; //debe coincidir cin un ident de usuario,id_usuario con perfil de profesor en USUARIOS.TXT
    int dia_clase[5]; //entre el 1 y el 5
    int hora_clase[5];
    int id_materia[4];//debe coincidir con el id_materia de una materia (en materias.txt)
}horario;

//ESTRUCTURA MATERIAS
typedef struct{
    int id_materia[3];
    char nombre_materia[49];
    char abrev_materia[3];
}materia;

//ESTRUCTURA MATRICULAS
typedef struct{
    int id_materia[3]; //debe coinidir con el id de alguna materia
    char id_alum[5]; //debe coincidir con el id de algun alumno
}matricula;

int nusuario;
int nAlumno;
int nCalificaciones;
int nHorario;
int nMateria;
int nMatricula;

/*
    usuario *vUsuarios;
    alumno *v_alumnos;
    calificaciones *vCalificaciones;
    horario *vHorario;
    materia *v_materias;
    matricula *v_matricula;
*/
//funciones de carga

//Cabecera: usuario* CargarUsuarios(usuario *vUsuario, int *n);
//Precondicion: fichero Usuarios.txt
//Postcondicion: Devuelve el vector vUsuarios con el contenido del fichero usuarios
void cargar_usuarios(usuario **us)

//Cabecera: usuario* CargarUsuarios(usuario *vUsuario, int *n);
//Precondicion: fichero Usuarios.txt
//Postcondicion: guarda los cambios en el .txt
//funciones de guardar


#endif