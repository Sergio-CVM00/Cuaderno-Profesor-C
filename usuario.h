#ifndef _USUARIOS_H_
#define __USUARIOS_H_
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

//USUARIOS
typedef struct{
    int id_usuario;
    char nombre_usuario[19];
    char perfil_usuario[29]; //administrador o profesor
    char usuario[6];  // con el que accedemos al sistema
    char contrasena[10];
}usuario;
int nUsuario;

//funciones de carga

//Cabecera: usuario* CargarUsuarios(usuario *vUsuario, int *n);
//Precondicion: fichero Usuarios.txt
//Postcondicion: carga los datos de usuarios en el sistema.
void cargar_usuarios(usuario **usu);

//Cabecera: void guardar_usuarios(usuario *usu);
//Precondicion: fichero Usuarios.txt
//Postcondicion: guarda los datos de usuarios en el txt.
void guardar_usuarios(usuario *usu);

#endif