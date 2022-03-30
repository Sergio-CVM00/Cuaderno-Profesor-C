
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    int id_usuario[2];
    char nombre_usuario[19];
    char perfil_usuario[29]; //administrador o profesor
    char usuario[4]; // con el que accedemos al sistema
    char contrasena[7];
}usuario;

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

int main(){
    int nUsuario; usuario *vUsuario = CargarUsuarios(vUsuario, &nUsuario);
}

/*
void cargar_usuarios(usuario **us)
{

    char linea[70];
    char *token;
    FILE *f;

    nusuario=0;


    f=fopen("Usuarios.txt","a+");

    if(f==NULL)
    {
        puts("Error de apertura");
    }
    else
    {
        rewind(f);
        *us=malloc(1*sizeof(usuario));

        while(fgets(linea,70,f)!=NULL)
        {
            *us=(usuario*)realloc((*us),(nusuario+1)*sizeof(usuario));

            if((*us)==NULL)
            {
                puts("No hay memoria suficiente");
            }
            else
            {
                token=sustok(linea,"-");
                ((*us)[nusuario].id_usuario)=atoi(token);
                token=sustok(NULL,"-");//leer enuse barras del ficharo y lo guarda en la variable token.
                suscpy((*us)[nusuario].nombre_usuario,token);
                token=sustok(NULL,"-");
                suscpy((*us)[nusuario].perfil_usuario,token);
                token=sustok(NULL,"-");
                suscpy((*us)[nusuario].usuario,token);
                token=sustok(NULL,"\n");
                suscpy((*us)[nusuario].contrasena,token);
                nusuario++;
            }
        }
        fclose(f);
    }
}

void guardar_usuarios(usuario **us)
{
    FILE *f;
    int i;
    f=fopen("Usuarios.txt","w+");
    for(i=0; i<nusuario; i++)
    {
        fprintf(f,"%i-%s-%s-%s-%s\n",(*us)[i].usuario, (*us)[i].nombre_usuario, (*us)[i].perfil_usuario, (*us)[i].usuario, (*us)[i].contrasena);
    }
    fclose(f);
}

*/


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




/*
void guardarAlumnos(alumno *vAlumno,int n){
    FILE *fichero;
    int i = 0;
    fichero = fopen("alumnos.txt","w+");
    if(fichero==NULL){
        printf("ERROR");
    }else{
        while(i<n){
            fprintf(fichero,"%s-%s-%s-%s-%s-%s\n",vAlumno[i].id_alum,vAlumno[i].nombre_alum,vAlumno[i].direc_alum,vAlumno[i].local_alum,vAlumno[i].curso,vAlumno[i].grupo);
            i++;
        }
        puts("Alumno guardado correctamente");
    }
    fclose(fichero);
}
int cargarAlumnos(alumno** vAlumnos,int*n);{
    FILE*fichero;
    char linea[80];
    char*token;
    *n=0;



    *vAlumnos=NULL;

    fichero=fopen("Alumnos.txt","r");

    if (fichero==NULL){
        printf("Error al cargar el fichero Alumnos.txt");
    }
    else{

        do{
            fgets(linea,80,fichero);

            if(strcmp(linea,"/0"))
            {
              *vAlumnos= realloc((alumno*)(*vAlumnos),((*n)+1) * sizeof(alumno));

                token = strtok(linea, "-");
                strcpy(*vAlumnos[*n].id_alum, token);

                token = strtok(NULL, "-");
                strcpy(*vAlumnos[*n].nombre_alum, token);

                token = strtok(NULL, "-");
                strcpy(*vAlumnos[*n].direc_alum, token);

                token = strtok(NULL, "-");
                strcpy(*vAlumnos[*n].local_alum, token);

                token = strtok(NULL, "-");
                strcpy(*vAlumnos[*n].curso, token);

                token = strtok(NULL, "\n");
                strcpy(*vAlumnos[*n].grupo, token);

                (*n)++;
        }
       }while(!feof(fichero));
      }

    fclose(fichero);
    return *vAlumnos
    }


void guardarMaterias(materia *vMateria,int n){
    FILE *fichero;
    int i = 0;
    fichero = fopen("materias.txt","w+");
    if(fichero==NULL){
        printf("ERROR");
    }else{
        while(i<n){
            fprintf(fichero,"%s-%s-%s\n",vMateria[i].id_materia,vMateria[i].nombre_materia,vMateria[i].abrev_materia);
            i++;
        }
        puts("Materia guardado correctamente");
    }
    fclose(fichero);
}
int cargarMarerias(materia** vMaterias,int*n);{
    FILE*fichero;
    char linea[80];
    char*token;
    *n=0;



    *vMaterias=NULL;

    fichero=fopen("Materias.txt","r");

    if (fichero==NULL){
        printf("Error al cargar el fichero Materias.txt");
    }
    else{

        do{
            fgets(linea,80,fichero);

            if(strcmp(linea,"/0"))
            {
              *vMaterias=realloc((materia *)(*vMaterias),((*n)+1) * sizeof(materia ));

                token = strtok(linea, "-");
                strcpy(*vMaterias[*n].id_materia, token);

                token = strtok(NULL, "-");
                strcpy(*vMaterias[*n].nombre_materia, token);

                token = strtok(NULL, "\n");
                strcpy(*vMaterias[*n].abrev_materia, token);

                (*n)++;


        }
       }while (!feof(fichero));
      }

    fclose(fichero);
    return *vMaterias;

    }


void guardarMatriculas(matricula *vMatricula,int n){
    FILE *fichero;
    int i = 0;
    fichero = fopen("matricula.txt","w+");
    if(fichero==NULL){
        printf("ERROR");
    }else{
        while(i<n){
            fprintf(fichero,"%s-%s\n",vMatricula[i].id_materia, vMatricula[i].id_alum);
            i++;
        }
        puts("Matricula guardado correctamente");
    }
    fclose(fichero);
}
matricula* CargarMatriculas(matricula *vMatricula, int *n){
    FILE *fichero;

    char linea[80];    //Cadena para guardar una linea entera
    char *token;
    *n=0;
    vMatricula = NULL;
	
    fichero = fopen("matriculas.txt", "r");
    
    vMatricula=(matricula*)malloc(0*sizeof(matricula));

    if (fichero == NULL)
    {
        puts("Error al abrir el fichero matriculas.txt.");
    }
    else
    {
        while (fgets(linea, 60, fichero))
        {
            if (strcmp(linea, "\0"))
            {
                vMatricula = (matricula *) realloc(vMatricula,((*n)+1) * sizeof(matricula));			
				 
                token = strtok(linea, "-");
                strcpy(vMatricula[*n].id_materia, token);

                token = strtok(NULL, "\n");
                strcpy(vMatricula[*n].id_alum, token);

                (*n)++;
            }
        }
   
    }
    fclose(fichero);
	return vMatricula;
}

//
//Calificaciones 
//
int  cargarCalificaciones(calificacion** vCalificaciones, int*n);{
    FILE*fichero;
    char linea[80];
  	char*token;
    *n=0;



   *vCalificaciones=NULL;

    fichero=fopen("Calificaciones.txt","r");

    if (fichero==NULL){
        printf("Error al cargar el fichero Calificaciones.txt");
    }
    else{

        do{
            fgets(linea,80,fichero);


            if(strcmp(linea,"/0"))
            {
              *vCalificaciones=realloc((calificacion *)( *vCalificaciones),((*n)+1) * sizeof(calificacion ));

                 token = strtok(linea, "-");
                strcpy(*vCalificaciones[*n].fecha_calif, token);

                token = strtok(NULL, "-");
                strcpy(*vCalificaciones[*n].descrip_calif, token);

                token = strtok(NULL, "-");
                strcpy(*vCalificaciones[*n].id_materia, token);

                token = strtok(NULL, "-");
                strcpy(*vCalificaciones[*n].id_alum, token);

                token = strtok(NULL, "-");
                strcpy(*vCalificaciones[*n].valor_calif, token);

                               (*n)++;
        }
       }while (!feof(fichero));
      }

    fclose(fichero);
    return *vCalificaciones;

}
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


//
//Horarios 
//
void guardarHorarios(horario *vHorarios,int n){
    FILE *fichero;
    int i = 0;
    fichero = fopen("horarios.txt","w+");
    if(fichero==NULL){
        printf("ERROR");
    }else{
        while(i<n){
            fprintf(fichero,"%s-%s\n",vHorarios[i].id_profesor,vHorarios[i].dia_clase,vHorarios[i].hora_clase,vHorarios[i].id_materia);
            i++;
        }
        puts("Horario guardado correctamente");
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

*/
