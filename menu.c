#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cargar-guardar.h"




int main(){
  //FUNCIONES DE CARGA, necesarias para el correcto uso de datos dentro del sistema.
  int nUsuario; usuario *vUsuario = CargarUsuarios(vUsuario, &nUsuario);
  printf("\nNumero de usuarios: %s\n", nUsuario);
  return 0;
}




/*
int main()
{

int op;
int nUsuario;
int usuario
//int *vUsuario = CargarUsuarios(vUsuario, &nUsuario);




  do
  {

  system("cls");
  printf("!Bienvenido al cuaderno del profesor� \n 1.Registro \n 2.Log-In \n 3.Salir \n");
  fflush(stdin);
  scanf("%d",&op);

   if(op==1)
   registro(&vUsuario, &nUsuario);
   if(op==2)
    log_in(  );
  
   if(op==3)
    exit(-1);

  }while( op>3);
}
*/
/*
void registro(usuario **vUsuario, int *nUsuario)
{
  system("cls");
  char prof[] = "profesor";
  char num_char[3 + sizeof(char)];
  typedef struct
  {
    char nombre[20];
    char contrasena[9];
  } provisional;
  provisional provus;

  printf("Introduzca su nombre: ");
  fflush(stdin);
  gets(provus.nombre);
  printf("\nIntroduzca su contrasena: ");
  fflush(stdin);
  gets(provus.contrasena);
  printf("\nSu registro se ha realizado exito");

  printf("\n Registro realizado con exito.");
  printf("-%s", provus.nombre);
  printf("-%d", *nUsuarios);
  system("pause");

  *vUsuario = (usuario *)realloc(*vUsuario, ((*nUsuarios) + 1) * sizeof(usuario));

  strcpy((*vUsuario)[*nUsuarios].nombre, provus.nombre);
  strcpy((*vUsuario)[*nUsuarios].contrasena, provus.contrasena);



}
*/
/*int log_in()
{
system("cls");

  do{
       printf("\nIntroduzca su nick: ");
        fflush(stdin);
        gets(nombre);
        printf("\nIntroduzca su contrasena: ");
        fflush(stdin);
        gets(contrasena);

  }
}
*/
