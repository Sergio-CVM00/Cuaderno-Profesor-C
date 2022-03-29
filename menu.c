#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"

void registro(usuario **vUsuario,int *nUsuario);
int log_in(usuario *vUsuario, int nUsuario, char *id_usr);

int main()
{
int nUsuario; usuario *vUsuario = CargarUsuarios(vUsuario, &nUsuario);
int usuario;
int op;
char id_usr[2];  
  do
  {
  system("cls");
  printf("!Bienvenido al cuaderno del profesor� \n 1.Registro \n 2.Log-In \n 3.Salir \n");
  fflush(stdin);
  scanf("%d",&op);

   if(op==1)
   registro(&vUsuario, &nUsuario);
   if(op==2)
    usuario=log_in(vUsuario, nUsuario, id_usr);
   if(op==3)
    exit(-1);
  }while( op>3);



//Aqui iran los menus de profesor y admin.



}

void registro(usuario **vUsuario,int *nUsuario)
{
system("cls");
  char usr[]="usuario";
	char num_char[3 + sizeof(char)];
	typedef struct
  {
    char nombre[20];
    char contrasena[9];
	}regist;

  regist provus;

		printf("Introduzca su nombre: ");
        fflush(stdin);
        gets(provus.nombre);
        printf("\nIntroduzca su contrasena: ");
        fflush(stdin);
        gets(provus.contrasena);
        printf("\nSu registro se ha realizado exito");

        printf("\n Registro realizado con exito.");
        printf("-%s",provus.nombre);
        printf("-%d",*nUsuario);
        system("pause");

        *vUsuario = (usuario *)realloc(*vUsuario, ((*nUsuario) + 1) * sizeof(usuario));
        
        strcpy((*vUsuario)[*nUsuario].Rol, usr);
        strcpy((*vUsuario)[*nUsuario].nombre, provus.nombre);
        strcpy((*vUsuario)[*nUsuario].contrasena, provus.contrasena);

if(*nUsuario<10)
    {
        	(*vUsuario)[*nUsuario].id_usuario[2]='0';
        	sprintf(num_char, "%d", *nUsuario+1);
        	strcat((*vUsuario)[*nUsuario].id_usuario,num_char);
		}
		else
    {
		sprintf(num_char, "%d", *nUsuario+1);
		strcpy((*vUsuario)[*nUsuario].id_usuario, num_char);		
		}
(*nUsuarios)++;
printf("%d",*nUsuario);
printf("-%s",vUsuario[4]->nombre);
system("pause");
}

int log_in(usuario *vUsuario, int nUsuario, char *id_usr)
{
    int opcion;
    char nombre[20];
    int usuario_actual;
    char c;
    int t=0;
    char contrasena[9];

  do{
       printf("\nIntroduzca su nick: ");
        fflush(stdin);
        gets(nombre);
        printf("\nIntroduzca su contrasena: ");
        fflush(stdin);
        gets(contrasena);


        for(usuario_actual = 0; usuario_actual < nUsuario && t==0 ; usuario_actual++ )
        {
          if ((strcmp(vUsuario[usuario_actual].nombre, nombre) == 0) && (strcmp(vUsuario[usuario_actual].contrasena, contrasena) == 0))
          {
        	strcpy(id_usr,vUsuario[usuario_actual].id_usuario);

    			if(strcmp(vUsuario[usuario_actual].Rol,"admin")==0)
          {
     			  vUsuario[usuario_actual].id_rol=1;	
				  }
    			if(strcmp(vUsuario[usuario_actual].Rol,"profesor")==0)
          {
       			vUsuario[usuario_actual].id_rol= 2;
       		}
       		t = 1;
          }
        }
        if(t==0)
         {
          printf("El usuario o la contrasena son incorrectas. �Desea volver a intentarlo?s/n");
          fflush(stdin);
          scanf("%c",&c);
         }
        }while(c=='s');
return usuario_actual-1;
  }


