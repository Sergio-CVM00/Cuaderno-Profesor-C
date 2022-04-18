// test git sergio
// He modificado desde MI RAMA, hago un commit de los cambios que he hecho.
// Pusheo esos cambios a MI RAMA para tenerlos guardado en github.

// Cuando quieras llevar los cambios de ese fichero a la rama MAIN.
// Dentro de github desktop te colocas en la rama main, vas a la opcion de "branch/rama"
// PULSAS "merge into current branch" seleccionas la rama de la cual quieras traer esos cambios.

// PULSAS "merge into current branch" seleccionas la rama de la cual quieras traer esos cambios.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <ctime>
#include "menu-admin.h"



// USUARIOS
/*
Dar de alta usuarios
Dar de baja usuarios
Listar usuarios
Modificar usuarios
*/

/*void darAlta_Usuarios(usuario **usu)
{
    int existe,id;
    system("cls");

    //*usu=(usu*)realloc((*usu),(nUsuario+1)*sizeof(usuario));
    
        do{
            existe=0;
            printf("Introduce tu ID de usuario nuevo: ");
            fflush(stdin);
            scanf("%i",&id);
            existe=comprobar_id_usu(*usu,id);
            if(existe==1){printf("Este nick ya existe\n");}
        }while(existe==1);
        (*usu)[nUsuario].id_usuario = id;
    
        printf("Introduce tu nombre completo: ");
        fflush(stdin);
        fgets((*usu)[nUsuario].nombre_usuario,21,stdin);
        salto((*usu)[nUsuario].nombre_usuario);
        fflush(stdin);

        printf("Introduce un perfil para el usuario: ");
        fflush(stdin);
        fgets((*usu)[nUsuario].contrasena,29,stdin);
        salto((*usu)[nUsuario].contrasena);
        fflush(stdin);

        printf("Introduce el usuario con el que accedera al sistema(Ejemplo:'prof1'): ");
        fflush(stdin);
        fgets((*usu)[nUsuario].contrasena,6,stdin);
        salto((*usu)[nUsuario].contrasena);
        fflush(stdin);

        printf("Introduce una contrasenia: ");
        fflush(stdin);
        fgets((*usu)[nUsuario].contrasena,10,stdin);
        salto((*usu)[nUsuario].contrasena);
        fflush(stdin);

        nUsuario++;

        guardar_usuario(*usu);
}*/

void darBaja_Usuarios(usuario **usu, int op)
{

    if (op == nUsuario - 1)
    {
        nUsuario--;
    }
    else
    {
        (*usu)[op].id_usuario = (*usu)[nUsuario - 1].id_usuario;
        strcpy((*usu)[op].nombre_usuario, (*usu)[nUsuario - 1].nombre_usuario);
        strcpy((*usu)[op].perfil_usuario, (*usu)[nUsuario - 1].perfil_usuario);
        strcpy((*usu)[op].usuario, (*usu)[nUsuario - 1].usuario);
        strcpy((*usu)[op].contrasena, (*usu)[nUsuario - 1].contrasena);
        nUsuario--;
    }

    guardar_usuarios(*usu);
    system("cls");
    printf("\n            USUARIO ELIMINADO\n");
}

void MenuAlumno(alumno *alum){

    int menuAnadir,op;
    do
    {
        printf("\nSeleccione una opcion:\n");
        printf("1: Dar de alta Alumno \n");
        printf("2: Dar de baja Alumno\n");
        printf("3: Modificar Alumno\n");
        printf("4: Listar Alumnos\n");
        printf("5: Informacion de alumnos\n");
        fflush(stdin);
        scanf("%i", &menuAnadir);
    } while (menuAnadir < 1 || menuAnadir > 5);
    switch (menuAnadir)
    {

    case 1:
        puts("Seleccionó dar de alta\n");
        dar_alta_alumno(&alum);
        break;
    case 2:
        puts("Seleccionó dar de baja\n");
        eliminar_alumno(&alum, op);
    case 3:
        puts("Seleccionó modificar\n");
        modificar_alumno(&alum);
    case 4:
        puts("Seleccionó listar alumnos");
        listar_alumno(alum);
    case 5:
        /*Además, para un alumno seleccionado, se permitirá mostrar la lista de materias en las que se encuentra matriculado,
        realizar cambios de matrícula a otras materias, eliminar matrícula en alguna materia y crear nuevas matrículas. */
        puts("Seleccionó informacion de alumnos(ver ,modificar matriculas)");
        //matricula_alumnos(&alum, &materia, &matricula);
    }
}
    void dar_alta_alumno(alumno **alum)
    {
        int id_alum_;
        int existe;
        *alum = (alumno *)realloc((*alum), (nAlumno + 1) * sizeof(alumno));
        do
        {
            existe = 0;
            printf("Introduce tu id de alumno");
            //fflush(stdin);
			//fgets (cadena, sizeof (cadena), stdin);
			scanf( "%i", &id_alum_);
            //fgets(id_alum_, 5, stdin);
            //salto(id_alum_);
            existe = comprobar_id_alumno(*alum, id_alum_);
            if (existe == 1)
            {
                printf("Este usuario ya existe\n");
            }
        } while (existe == 1);
        (*alum)[nAlumno].id_alum = id_alum_;

        printf("Introduce el nombre completo del alumno: ");
        fflush(stdin);
        fgets((*alum)[nAlumno].nombre_alum, 21, stdin);
        salto((*alum)[nAlumno].nombre_alum);
        fflush(stdin);

        printf("Introduce la direccion del alumno: ");
        fflush(stdin);
        fgets((*alum)[nAlumno].direc_alum, 31, stdin);
        salto((*alum)[nAlumno].direc_alum);
        fflush(stdin);

        printf("Introduce la localidad del alumno: ");
        fflush(stdin);
        fgets((*alum)[nAlumno].local_alum, 31, stdin);
        salto((*alum)[nAlumno].local_alum);
        fflush(stdin);

        printf("Introduce el curso del alumno: ");
        fflush(stdin);
        fgets((*alum)[nAlumno].curso, 31, stdin);
        salto((*alum)[nAlumno].curso);
        fflush(stdin);

        printf("Introduce el grupo del alumno: ");
        fflush(stdin);
        fgets((*alum)[nAlumno].grupo, 11, stdin);
        salto((*alum)[nAlumno].grupo);
        fflush(stdin);

        nAlumno++;

        guardar_alumnos(*alum);
    }


void eliminar_alumno(alumno **alum, int op)
{
        mostrar_alumno(*alum,op);
        do
        {
            printf("\nIntroduce el numero del alumno que desea eliminar: ");
            scanf("%i", &op);
        } while (op < 0 || op >= nAlumno);

        if (op == nAlumno - 1)
        {
            nAlumno--;
        }
        else
        {
            (*alum)[op].id_alum = (*alum)[nAlumno - 1].id_alum;
            strcpy((*alum)[op].nombre_alum, (*alum)[nAlumno - 1].nombre_alum);
            strcpy((*alum)[op].direc_alum, (*alum)[nAlumno - 1].direc_alum);
            strcpy((*alum)[op].local_alum, (*alum)[nAlumno - 1].local_alum);
            strcpy((*alum)[op].curso, (*alum)[nAlumno - 1].curso);
            strcpy((*alum)[op].grupo, (*alum)[nAlumno - 1].grupo);
            nAlumno--;
        }
    

}
   



void modificar_alumno(alumno **alum)
{
    int pos, op, existe, a, est;
    int id_alum_;
    system("cls");
    do
    {
        mostrar_alumnos(*alum);
        do
        {
            printf("\nIntroduce el numero del alumno que desea modificar: ");
            scanf("%i", &pos);
        } while (pos < 0 || pos >= nAlumno);
        do
        {
            printf("Que dato desea modificar: ");
            scanf("%i", &op);
        } while (op < 1 || op > 5);

        switch (op)
        {
        case 1:
            do
            {
                existe = 0;
                printf("Introduce el nuevo id: ");
                fflush(stdin);
                scanf("%i", &id_alum_);
                //salto(id_alum_);
                existe = comprobar_id_alumno(*alum, id_alum_);
                if (existe == 1)
                {
                    printf("Este alumno ya existe\n");
                }
            } while (existe == 1);
            (*alum)[pos].id_alum =  id_alum_;
            break;
        case 2:
            printf("Introduce el nuevo nombre completo: ");
            fflush(stdin);
            fgets((*alum)[pos].nombre_alum, 21, stdin);
            salto((*alum)[pos].nombre_alum);
            break;
        case 3:
            printf("Introduce la nueva direccion: ");
            fflush(stdin);
            fgets((*alum)[pos].direc_alum, 31, stdin);
            salto((*alum)[pos].direc_alum);
            break;
        case 4:
            printf("Introduce la nueva localidad: ");
            fflush(stdin);
            fgets((*alum)[pos].local_alum, 31, stdin);
            salto((*alum)[pos].local_alum);
            break;
        case 5:
            printf("Introduce el nuevo curso: ");
            fflush(stdin);
            fgets((*alum)[pos].curso, 31, stdin);
            salto((*alum)[pos].curso);
            break;
        case 6:
            printf("Introduce el nuevo grupo: ");
            fflush(stdin);
            fgets((*alum)[pos].grupo, 11, stdin);
            salto((*alum)[pos].grupo);
            break;
        }
        system("cls");
        guardar_alumnos(*alum);

        mostrar_alumnos(*alum);
        printf("\nDesea modificar otro dato (1-SI/2-NO  numero): ");
        scanf("%i", &a);
        system("cls");
    } while (a == 1);
}

void listar_alumno(alumno *alum)
{
    int i;
    printf("Se mostraran todos los alumnos del sistema:\n\n");
    puts("//////////////////////////////////////////////////////////////////////////////");

    printf("\n            LISTA DE ALUMNOS\n\n");
            printf("1-id || 2-nom_comp || 3-direc_alum || 4-curso || 5-grupo\n");

            for (i = 0; i < nAlumno; i++)
            {
                printf("%i-%i/%s/%s/%s/%s/%s\n", i, alum[i].id_alum, alum[i].nombre_alum, alum[i].direc_alum, alum[i].local_alum, alum[i].curso,alum[i].grupo);
            }
    puts("////////////////////////////////////////////////////////////////////////////////////////////////////");
}

void matricula_alumnos(alumno **alum, alumno **materia, matricula **mtri)
{
   
int menuAnadir;
    

    do
    {
        printf("\nSeleccione una opcion:\n");
        printf("1: Listar materias en las que se encuentra matriculado \n");
        printf("2: Crear matricula\n");
        printf("3: Eliminar materia en alguna matricula\n");
        printf("4: Modificar matricula\n");

        fflush(stdin);
        scanf("%i", &menuAnadir);
    } while (menuAnadir < 1 || menuAnadir > 4);
    switch (menuAnadir)
    {

    case 1:
        puts("Seleccionó listar materias alumno\n");
        listar_materias_alumno(*alum, *mtri);
        break;
    case 2:
        puts("Seleccionó crear matricula alumno\n");
        crear_matricula_alumno(*alum, *materia, *mtri);
        break;
    case 3:
        puts("Seleccionó eliminar materia en alguna  matricula \n");
        eliminar_materias_alumno(*alum, *materia, *mtri);
        break;
    case 4:
        puts("Seleccionó modificar materias de  matriculas\n");
        modificar_materias_alumno(*alum, *materia, *mtri);
        break;
    }
}

void listar_materias_alumno(alumno *alum,matricula *mtri){
    int id_alum_;
    int existe;
    int matriculado,i,j;
    int *materias;
    existe = 0;
    do{
        printf("Introduce tu id de alumno que sea ver su matricula");
        fflush(stdin);
        scanf("%i",&id_alum_);
        //salto(id_alum_);
        existe = comprobar_id_alumno(alum, id_alum_);

    }while (existe == 0 );
    i = 0;
    j= 0;
    while( i<nMatricula){
        if(mtri[i].id_alum == id_alum_){
            materias[j] = mtri[i].id_materia;
            j++;
            
        }
        
        i++;
    }
    for(i = 0;i<=j;i++){
        printf("%i\n", materias[i]);

    }
    
  

}

void crear_matricula_alumno(alumno **alum, materia **mate, matricula **mtri)
{
	int id_alum_;
	int materias = 1;
	int id_materia_;
	int existe = 0;
	int existeM =1;
	*mtri=(matricula*)realloc((*mtri),(nMatricula+1)*sizeof(matricula));
	
   
   
   	while(materias!=0){
	   	do{
			printf("Introduce id de alumno");
		    fflush(stdin);
		    scanf("%i",&id_alum_);
		    printf("Introduce id de la materia a asignar al alumno: ");
			fflush(stdin);
			scanf("%i",&id_materia_);
			existeM = comprobar_id_materia(mate, id_materia_);
		    existe = comprobar_id_alumno(alum, id_alum_);
		    existeMatricula = comprobar_matricula(matri,id_alum_,id_materia_);
	    }while (existe == 1 && existeM ==1 && existeMatricula==1);
	   		(*mtri)[nMatricula].id_alum = id_alum_;
		    (*mtri)[nMatricula].id_materia = id_materia_;
		    printf("Deseea a�adir mas?, introduzca 0 en caso contrario");
	   		scanf("%i",&materias);	
	   		nMatricula++;
	}
	guardar_matricula(*mtri);
  
}
void eliminar_materias_alumno(alumno **alum, materia **mate, matricula **mtri){
	int id_alum_;
	int materias = 1;
	int id_materia_;
	int existe = 0;
	int existeM =0;
    int existeMatricula = 0;
   	while(materias!=0){
	   	do{
			printf("Introduce id de alumno");
		    fflush(stdin);
		    scanf("%i",&id_alum_);
		    printf("Introduce id de la materia del alumno: ");
			fflush(stdin);
			scanf("%i",&id_materia_);
			existeM = comprobar_id_materia(mate, id_materia_);
		    existe = comprobar_id_alumno(alum, id_alum_);
		    existeMatricula = comprobar_matricula(matri,id_alum_,id_materia_);
	    }while (existe == 1 && existeM ==1 && existeMatricula==1);
            //no se si esta correcto.
	    	id_alum_ = (*mtri)[nMatricula - 1].id_alum;
	    	id_materia_ = (*mtri)[nMatricula - 1].id_alum;
		    printf("Deseea eliminar mas?, introduzca 0 en caso contrario");
	   		scanf("%i",&materias);	
	   		nMatricula--;
	}
	
}
void modificar_materias_alumno(alumno *alum,materia *mate, matricula *mtri){
    //ACLARAR QUE SOLO PUEDO MODIFICAR LA MATERIA DE UN ALUMNO PERO NO DE UN ALUMNO A UNA MATERIA
    int pos, op, existe, a, est;
    int existe = 0;
	int existeM =0;
    int existeMatricula = 0;
    int id_alum_;
    int id_materia_;
    system("cls");
   do{
        mostrar_alumnos(*alum);
        do
        {
            printf("\nIntroduce el numero del alumno que desea modificar: ");
            scanf("%i", &pos);
        } while (pos < 0 || pos >= nAlumno);
            do
            {
                existe = 0;
                scanf("%i",&id_alum_);
                printf("Introduce el id de la materia a modificar: ");
                scanf("%i", id_materia_);
                //salto(id_materia_);
                existeM = comprobar_id_materia(mate, id_materia_);
                existe = comprobar_id_alumno(alum, id_alum_);
                existeMatricula = comprobar_matricula(mtri,id_alum_,id_materia_);
                if ( existeMatricula==1)
                {
                    printf("Esta matricula ya existe\n");
                }
            } while (existe == 1 && existeM ==1 && existeMatricula==1);
                (*mtri)[pos].id_materia = id_materia_;
                break;
            
            
            system("cls");
            guardar_matricula(*mate);

            mostrar_materias(*mate);
            printf("\nDesea modificar otro dato (1-SI/2-NO  numero): ");
            scanf("%i", &a);
            system("cls");
        } while (a == 1);
}


// MATERIAS
void MenuMaterias(materia *mate)
{
    int menuAnadir, op;
    do
    {
        printf("\nSeleccione una opcion:\n");
        printf("1: Dar de alta Materia \n");
        printf("2: Dar de baja Materia\n");
        printf("3: Modificar Materia\n");
        printf("4: Listar Materia\n");
        fflush(stdin);
        scanf("%i", &menuAnadir);
    } while (menuAnadir < 1 || menuAnadir > 4);
    switch (menuAnadir)
    {
    case 1:
        puts("Seleccionó dar de alta\n");
        dar_alta_materia(&mate);
        break;
    case 2:
        puts("Seleccionó dar de baja\n");
        eliminar_materia(&mate, op);
    case 3:
        puts("Seleccionó modificar\n");
        modificar_materia(&mate);
    case 4:
        puts("Seleccionó listar alumnos");
        listar_materia(mate);
    case 5:
        /*Además, para un alumno seleccionado, se permitirá mostrar la lista de materias en las que se encuentra matriculado,
        realizar cambios de matrícula a otras materias, eliminar matrícula en alguna materia y crear nuevas matrículas. */
        puts("Seleccionó informacion de alumnos(ver ,modificar matriculas)");
        //matricula_alumnos(&alum, &materia, &matricula);
    }
}

    void dar_alta_materia(materia **mate)
    {
        int id_materia_;
        int existe;
        *mate = (materia *)realloc((*mate), (nMateria + 1) * sizeof(materia));
        do
        {
            existe = 0;
            printf("Introduce id de materia");
            fflush(stdin);
            scanf("%i", &id_materia_);
            //salto(id_materia_);
            existe = comprobar_id_materia(*mate, id_materia_);
            if (existe == 1)
            {
                printf("Esta materia ya existe\n");
            }
        } while (existe == 1);
        (*mate)[nMateria].id_materia=id_materia_;

        printf("Introduce el nombre completo de la materia: ");
        fflush(stdin);
        fgets((*mate)[nMateria].nombre_materia,51, stdin);
        salto((*mate)[nMateria].abrev_materia);
        fflush(stdin);

        printf("Introduce la abreviatura de la materia: ");
        fflush(stdin);
        fgets((*mate)[nMateria].abrev_materia, 4, stdin);
        salto((*mate)[nMateria].abrev_materia);
        fflush(stdin);

        nMateria++;

        guardar_materias(*mate);
    }


void eliminar_materia(materia **mate, int op)
{
        mostrar_materias(*mate);
        do
        {
            printf("\nIntroduce el numero de la materia que desea eliminar: ");
            scanf("%i", &op);
        } while (op < 0 || op >= nAlumno);

        if (op == nMateria - 1)
        {
            nMateria--;
        }
        else
        {
            (*mate)[op].id_materia = (*mate)[nMateria - 1].id_materia;
            strcpy((*mate)[op].nombre_materia, (*mate)[nMateria - 1].nombre_materia);
            strcpy((*mate)[op].abrev_materia, (*mate)[nMateria - 1].abrev_materia);
            nMateria--;
        }
    

    guardar_materias(*mate);
    system("cls");
    printf("\n            MATERIA ELIMINADO\n");
}

void modificar_materia(materia **mate)
{//ACLARAR QUE SOLO PUEDO MODIFICAR LA MATERIA DE UN ALUMNO PERO NO DE UN ALUMNO A UNA MATERIA
     int pos, op, existe, a, est;
    int id_materia_;
    system("cls");
    do
    {
        mostrar_matriculas(*mtri);
        do
        {
            printf("\nIntroduce el numero de la materia que desea modificar: ");
            scanf("%i", &pos);
        } while (pos < 0 || pos >= nMatricula);
        do
        {
            printf("Que dato desea modificar: ");
            scanf("%i", &op);
        } while (op < 1 || op > 2);

        switch (op)
        {
        case 1:
            do
            {
                existe = 0;
                printf("Introduce el nuevo id de alumno: ");
                scanf("%i", id_materia_);
                existe = comprobar_id_materia(*mate, id_materia_);
                if (existe == 1)
                {
                    printf("Esta materia ya existe\n");
                }
            } while (existe == 1);
            (*mate)[pos].id_materia = id_materia_;
            break;
        case 2:
            printf("Introduce el nuevo nombre de la materia: ");
            fflush(stdin);
            fgets((*mate)[pos].nombre_materia, 51, stdin);
            salto((*mate)[pos].nombre_materia);
            break;
        case 3:
            printf("Introduce la nueva abreviatura: ");
            fflush(stdin);
            fgets((*mate)[pos].abrev_materia, 4, stdin);
            salto((*mate)[pos].abrev_materia);
            break;
        }
        system("cls");
        guardar_materias(*mate);

        mostrar_materias(*mate);
        printf("\nDesea modificar otro dato (1-SI/2-NO  numero): ");
        scanf("%i", &a);
        system("cls");
    } while (a == 1);
   
}

void listar_materia(materia *mate)
{
    int i;
    printf("Se mostraran todos las materias del sistema:\n\n");
    puts("//////////////////////////////////////////////////////////////////////////////");

    printf("\n            LISTA DE MATERIAS\n\n");
    printf("1-id || 2-nombre_materia || 3-abreviatura\n");
   
    for (i = 0; i < nMateria; i++)
    {
        printf("%i-%i/%s/%s\n", i, mate[i].id_materia, mate[i].nombre_materia, mate[i].abrev_materia);

        puts("////////////////////////////////////////////////////////////////////////////////////////////////////");
    }
}





// FUNCIONES AUXILIARES ALUMNOS
void salto(char *str){
int tam;
    tam=strlen(str);
    str[tam-1]='\0';
}

int comprobar_id_alumno(alumno *alum, int id_alum)
{
    int i = 0;
    while (i < nAlumno && alum[i].id_alum != id_alum)
    {
        i++;
    }
    if (i == nAlumno)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void mostrar_alumno(alumno *alum, int pos)
{
    printf("1-id || 2-nombre_completo || 3-direc_alum || 4-curso || 5-grupo\n");

    if (pos > 0 && pos < nAlumno)
    {
        printf("\n%i/%s/%s/%s/%s\n", alum[pos].id_alum, alum[pos].nombre_alum, alum[pos].direc_alum, alum[pos].local_alum, alum[pos].curso,alum[pos].grupo);
    }
}
void mostrar_alumnos(alumno *alum)
{
    printf("\n            LISTA DE ALUMNOS\n\n");
    printf("1-id || 2-nom_comp || 3-direc_alum || 4-curso || 5-grupo\n");
    int i;
    for (i = 0; i < nAlumno; i++)
    {
        printf("%i-%i/%s/%s/%s/%s\n", i, alum[i].id_alum, alum[i].nombre_alum, alum[i].direc_alum, alum[i].local_alum, alum[i].curso,alum[i].grupo);
    }
}

// FUNCIONES AUXILIARES DE MATERIAS
int comprobar_id_materia(materia *mate, int id_materia)
{
    int i = 0;
    while (i < nMateria && mate[i].id_materia != id_materia)
    {
        i++;
    }
    if (i == nMateria)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int comprobar_id_usuario(usuario *usu, int *id_usuario)
{
    int i = 0;
    while (i < nUsuario && usu[i].id_usuario != *id_usuario)
    {
        i++;
    }
    if (i == nUsuario)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}


void mostrar_materia(materia *mate, int pos)
{
    printf("1-id || 2-nombre || 3-abreviatura\n");

    if (pos > 0 && pos < nMateria)
    {
        printf("\n%i/%s/%s\n", mate[pos].id_materia, mate[pos].nombre_materia, mate[pos].abrev_materia);
    }
}
void mostrar_materias(materia *mate)
{
    printf("\n            LISTA DE MATERIAS\n\n");
    printf("1-id || 2-nombre || 3-abreviatura\n");
    int i;
    for (i = 0; i < nMateria; i++)
    {
        printf("%i-%i/%s/%s\n", i, mate[i].id_materia, mate[i].nombre_materia, mate[i].abrev_materia);
    }
}
//MATRICULAS
void comprobar_matricula(matricula *matri,int id_alum,int id_materia){
	int i = 0;
    while (i < nMatricula && matri[i].id_alum != id_alum && matri[i].id_materia != id_materia  )
    {
        i++;
    }
    if (i == nMatricula)
    {
        return 0;
    }
    else
    {
        return 1;
    }
	
}
void mostrar_matricula(matricula *mtri, int pos)
{
    printf("1-id_alum || 2-id_materia \n");

    if (pos > 0 && pos < nMatricula)
    {
        printf("\n%i/%i\n", mtri[pos].id_alum, mtri[pos].id_materia);
    }
}
void mostrar_matriculas(matricula *mtri)
{
    printf("\n            LISTA DE MATRICULAS\n\n");
    printf("1-id_alum || 2-id_materia\n");
    int i;
    for (i = 0; i < nMatricula; i++)
    {
        printf("%i-%i/%i\n", i, mtri[i].id_alum, mtri[i].id_materia);
    }
}
