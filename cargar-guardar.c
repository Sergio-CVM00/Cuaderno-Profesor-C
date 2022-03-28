#include "cargar-guardar.h"
#include "stdio.h"

int main(){
    int nUsuario; usuario *vUsuario = CargarUsuarios(vUsuario, &nUsuario);
    printf("\nNumero de usuarios: %s\n", nUsuario);
}

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
                *vUsuario[*n].id_usuario = atoi(token);  // hasta que encuentre un guion
		
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


//
//Horarios 
//
void GuardarHorarios(usuario *vHorarios, int n){

    FILE *fichero;
    int i=0;

    fichero = fopen("Horarios.txt", "w+");

    if (fichero == NULL)
    {
        puts("Error al cargar Usuarios.txt");
    }
    else
    {
        while (i < n)
        {
            fprintf(fichero, "%i-%i-%i-%i\n", vHorarios[i].id_usuario, vHorarios[i].nombre_usuario, vHorarios[i].perfil_usuario, vHorarios[i].usuario, vHorarios[i].contrasena);
            i++;
        }
        puts("Usuarios.txt guardado correctamente");
    }
    fclose(fichero);
}

horario* CargarHorarios(horario *vHorario, int *n){

    FILE *fichero;
    char linea[80]; //Cadena para guardar una linea entera
    char *token;
    *n=0;
    
    vHorario = NULL;
    fichero = fopen("Horarios.txt", "r");
    if (fichero == NULL)
    {
        puts("Error al abrir el fichero Horarios.txt.");
    }
    else
    {
        while (fgets(linea, 80, fichero))
        {
            if (strcmp(linea, "\0"))
            {
                vHorario = (horario *) realloc(vHorario,((*n)+1) * sizeof(horario));
                
                token = strtok(linea, "-");
                *vHorario[*n].id_profesor = atoi(token);  // hasta que encuentre un guion
		
                token = strtok(NULL, "-");
                *vHorario[*n].dia_clase = atoi(token);	   //borra lo anterior e imprime hasta que encuentre el proximo guion
							
                token = strtok(NULL, "-");
                *vHorario[*n].hora_clase = atoi(token);
                
                token = strtok(NULL, "\n");
                *vHorario[*n].id_materia = atoi(token);
				
                (*n)++; 
            }
        }
    }
    fclose(fichero);
	return vHorario;
}

//
//Calificaciones 
//
void GuardarCalifiaciones(calificaciones *vCalificaciones, int n){

    FILE *fichero;
    int i=0;

    fichero = fopen("Horarios.txt", "w+");

    if (fichero == NULL)
    {
        puts("Error al cargar Usuarios.txt");
    }
    else
    {
        while (i < n)
        {
            fprintf(fichero, "%s-%s-%i-%i-%i\n", vCalificaciones[i].fecha_calif, vCalificaciones[i].descrip_calif, vCalificaciones[i].id_materia, vCalificaciones[i].id_alum, vCalificaciones[i].valor_cal);
            i++;
        }
        puts("Usuarios.txt guardado correctamente");
    }
    fclose(fichero);
}

void cargar_calificaciones(calificaciones **cf)
{
    char linea[120];
    char *token;
    FILE *f;
    nCalificaciones=0;

    f=fopen("Calificaciones.txt","a+");

    if(f==NULL)
    {
        puts("Error de apertura");
    }
    else
    {
        rewind(f);
        *cf=malloc(1*sizeof(nCalificaciones));
        while(fgets(linea,120,f)!=NULL)
        {
            *cf=(calificaciones*)realloc((*cf),(nCalificaciones+1)*sizeof(calificaciones));

            if((*cf)==NULL)
            {
                puts("No hay memoria suficiente");
            }
            else
            {
                token=strtok(linea,"-");
                strcpy((*cf)[nCalificaciones].id_materia,token);
                token=strtok(NULL,"-");
                strcpy((*cf)[nCalificaciones].id_materia,token);
                token=strtok(NULL,"-");
                strcpy((*cf)[nCalificaciones].id_alum,token);
                token=strtok(NULL,"\n");
                strcpy((*cf)[nCalificaciones].valor_cal,token);
                nCalificaciones++;
            }
        }
        fclose(f);
    }
}