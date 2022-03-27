#include "cargar-guardar.h"
#include "stdio.h"


//
//Usuarios 
//
void GuardarUsuarios(usuario *vUsuario, int n){

    FILE *fichero;
    int i=0;

    fichero = fopen("Usuarios.txt", "w+");

    if (fichero == NULL)
    {
        puts("Error al cargar Usuarios.txt");
    }
    else
    {
        while (i < n)
        {
            fprintf(fichero, "%s-%s-%s-%s-%s\n", vUsuario[i].id_usuario, vUsuario[i].nombre_usuario, vUsuario[i].perfil_usuario, vUsuario[i].usuario, vUsuario[i].contrasena);
            i++;
        }
        puts("Usuarios.txt guardado correctamente");
    }
    fclose(fichero);
}

usuario* CargarUsuarios(usuario *vUsuario, int *n){
    FILE *fichero;
    char linea[80]; //Cadena para guardar una linea entera
    char *token;
    *n=0;
    
    vUsuario = NULL;
    fichero = fopen("Usuarios.txt", "r");
    if (fichero == NULL)
    {
        puts("Error al abrir el fichero Usuarios.txt.");
    }
    else
    {
        while (fgets(linea, 80, fichero))
        {
            if (strcmp(linea, "\0"))
            {
                vUsuario = (usuario *) realloc(vUsuario,((*n)+1) * sizeof(usuario));
                              

                token = strtok(linea, "-");
                strcpy(vUsuario[*n].id_usuario, token);  // hasta que encuentre un guion
		
                token = strtok(NULL, "-");
                strcpy(vUsuario[*n].nombre_usuario, token);	   //borra lo anterior e imprime hasta que encuentre el proximo guion
							
                token = strtok(NULL, "-");
                strcpy(vUsuario[*n].perfil_usuario, token);
                
                token = strtok(NULL, "-");
                strcpy(vUsuario[*n].usuario, token);

                token = strtok(NULL, "\n");
                strcpy(vUsuario[*n].contrasena, token);
				
                (*n)++; 
            }
        }
    }
    fclose(fichero);
	return vUsuario;
}