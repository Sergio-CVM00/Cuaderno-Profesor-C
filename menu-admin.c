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

Menu_Usuarios(usuario **usu){
    int menuAnadir,op,aux_id;
    do{
            system("cls");
            printf("\nSeleccione una opcion:\n");
            printf("1: Dar de alta Usuario \n");
            printf("2: Dar de baja usuario\n");
            printf("3: Modificar usuario\n");
            printf("4: Listar usuarios\n");
            printf("5: volver al menu general de admin\n");
            fflush(stdin);
            scanf("%i", &menuAnadir);
    } while (menuAnadir < 1 || menuAnadir >= 5 );
    switch (menuAnadir){

        case 1:
            system("cls");
            puts("MENU ADMIN: ");
            puts("dar de alta\n");
            darAlta_Usuarios(usu);
            
            break;
        case 2:
            puts("dar de baja\n");
            do
            {
                system("cls");
                Listar_usuarios(usu);
                puts("MENU ADMIN: ");
                printf("Introduzca el id_usuario que quiera borrar: ");
                fflush(stdin);
                scanf("%i",&aux_id);
            } while (comprobar_usuario(&usu,aux_id) == 0);
            darBaja_Usuarios(usu,aux_id);
            break;
        case 3:
            system("cls");
            puts("MENU ADMIN: ");
            puts("modificar\n");
            Modificar_usuarios(usu);
            break;
        case 4:
            system("cls");
            Listar_usuarios(usu);
            puts("MENU ADMIN: ");
            break;
        case 5:
            break;
    }
}

void menu_general(usuario **usu,calificaciones **cali, horario **hor, alumno **alum,materia **mat, matricula **mtri){
    int op;
    do
    {
        system("cls");
        printf("\n1-USUARIO 2-ALUMNO 3-MATERIA 4-HORARIO  ");
        printf("\nA que menu de admin desea acceder: ");
        scanf("%i",&op);
    }while (op > 0 && op  < 5);
    switch (op)
    {
    case 1:
        /* code */
        break;
    case 2:
        MenuAlumno(alum,mtri,mat);
        break;
    case 3:
        MenuMaterias(mat);
        break;
    case 4:
        //menuhorarios
        break;
    }
}

void darAlta_Usuarios(usuario **usu)
{
    int existe,id;
    system("cls");

    *usu=(usuario*)realloc((*usu),(nUsuario+1)*sizeof(usuario));
        do{
            existe=0;
            printf("Introduce tu ID de usuario nuevo: ");
            fflush(stdin);
            scanf("%i",&id);
            existe=comprobar_usuario(*usu,id);
            if(existe==1){printf("Este nick ya existe\n");}
        }while(existe==1);
        (*usu)[nUsuario].id_usuario = id;

        printf("Introduce tu nombre completo: ");
        fflush(stdin);
        fgets((*usu)[nUsuario].nombre_usuario,19,stdin);
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

        guardar_usuarios(usu);
}

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

    guardar_usuarios(usu);
    system("cls");
    printf("\n            USUARIO ELIMINADO\n");
}

//LISTAR USUARIOS
void Listar_usuarios(usuario **usu){

    //Lista todos los usuarios del sistema por pantalla
    int i;
    printf("\nUsuarios registrados en el sistema:");
    for (i = 0; i < nUsuario; i++)
    {
        printf("\n%i: %i-%s-%s-%s-%s",(*usu)[i].id_usuario,(*usu)[i].nombre_usuario,(*usu)[i].perfil_usuario,(*usu)[i].usuario,(*usu)[i].contrasena);
    }

}
//MOODIFICAR UN USUARIO

void Modificar_usuarios(usuario **usu){
    int pos,op,existe,a;
    int id_aux;
    system("cls");
    do{
        Listar_usuarios(usu);
        do{
        printf("\nIntroduce que usuario desea modificar(numero): ");
        scanf("%i",&pos);
        }while(pos<0 || pos>=nUsuario);

        do{
        printf("Que dato desea modificar: ");
        scanf("%i",&op);
        }while(op<1 || op>11);

    switch(op){
        case 1:do{
            existe=0;
            printf("Introduce el nuevo id_usuario: ");
            fflush(stdin);
            scanf("%i",&id_aux);
            existe=comprobar_usuario(*usu,id_aux);
            if(existe==1){printf("Este id ya existe\n");}
            }while(existe==1);
            (*usu)[pos].id_usuario = id_aux ;
            break;
        case 2:printf("Introduce el nuevo nombre completo: ");
            fflush(stdin);
            fgets((*usu)[pos].nombre_usuario,40,stdin);
            break;
        case 3:printf("Introduce el nuevo perfil del usuario: ");
            fflush(stdin);
            fgets((*usu)[pos].perfil_usuario,40,stdin);
            break;
        case 4:printf("Introduce el nuevo tipo de usuario: ");
            fflush(stdin);
            fgets((*usu)[pos].usuario,40,stdin);
            break;
        case 5:printf("Introduce la nueva contrasena: ");
            fflush(stdin);
            fgets((*usu)[pos].contrasena,40,stdin);
            break;
        }
    system("cls");
    guardar_usuarios(usu);
    Listar_usuarios(usu);
    printf("\nDesea modificar otro dato ( 1-SI / 2-NO  numero): ");
    scanf("%i",&a);
    system("cls");
    }while(a==1);
}



    void MenuAlumno(alumno *alum,matricula *mtri,materia *mate){
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
            puts("dar de alta\n");
            dar_alta_alumno(&alum);
            break;
        case 2:
            puts("dar de baja\n");
            eliminar_alumno(&alum, op);
            break;
        case 3:
            puts("modificar\n");
            modificar_alumno(&alum);
            break;
        case 4:
            puts("listar alumnos");
            listar_alumno(alum);
            break;
        case 5:
            puts("informacion de alumnos(ver ,modificar matriculas)\n");
            menu_matricula_alumnos(mtri,alum,mate);
            break;
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
            printf("Introduce tu id de alumno: ");
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

        guardar_alumnos(alum);
    }


    void eliminar_alumno(alumno **alum, int op)
    {
        int a;
        do{

            mostrar_alumnos(*alum);
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
                guardar_alumnos(alum);
            }
        mostrar_alumnos(*alum);
        printf("\nDesea eliminar otro alumno (1-SI/2-NO  numero): ");
        scanf("%i", &a);
        system("cls");
        }while (a==1);
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
        guardar_alumnos(alum);

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

void menu_matricula_alumnos(matricula *mtri,alumno *alum,materia *mate)
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
        puts("//////listar materias alumno//////\n");
        listar_materias_alumno(mtri,&alum);
        break;
    case 2:
        puts("////// crear matricula alumno//////\n");
        crear_matricula_alumno(&mtri,&mate,&alum);
        break;
    case 3:
        puts("////// eliminar materia en alguna  matricula////// \n");
        eliminar_materias_alumno(&mtri);
        break;
    case 4:
        puts("////// modificar materias de  matriculas//////\n");
        modificar_materias_alumno(&mtri,&alum,&mate);
        break;
    }
}

void listar_materias_alumno(matricula *mtri,alumno **alum){
	int pos, op,a;
    int existe = 0;
	int existeM =0;
    int existeMatricula = 0;
    int *materias;
    int id_alum_;
    system("cls");


        do
        {
            printf("\nIntroduce el id del alumno que desea ver su matricula: ");
            scanf("%i", &id_alum_);
            existe = comprobar_id_alumno(*alum,id_alum_);
            if( existe==0){
            	printf("Alumno no existe");
			}
        }while (existe==0);
    	int i;
    	for (i = 0; i < nMatricula; i++)
    	{
    		if(mtri[i].id_alum==id_alum_){
    			printf("%i/%i\n", mtri[i].id_alum, mtri[i].id_materia);
        		puts("////////////////////////////////////////////////////////////////////////////////////////////////////");
			}
   		 }

}

void crear_matricula_alumno(matricula **mtri,materia **mate,alumno **alum)
{
	int id_alum_;
	int materias;
	int id_materia_;
	int existe ;
	int existeM ;
	int existeMatricula;
	*mtri=(matricula*)realloc((*mtri),(nMatricula+1)*sizeof(matricula));



   	do{
	   	do{
			printf("Introduce id de alumno : ");
		    fflush(stdin);
		    scanf("%i",&id_alum_);
		    existe = comprobar_id_alumno(*alum, id_alum_); // sino existe 1
			if(existe==0){
		    	printf("Alumno no existe.Vuelva a introducir la identificacion del alumno \n");
			}
	    }while (existe == 0);
	    do{
	    	printf("Introduce id de la materia a asignar al alumno: ");
			fflush(stdin);
			scanf("%i",&id_materia_);
			existeM = comprobar_id_materia(*mate, id_materia_);
			if(existeM==0){
		    	printf("Materia no existe \n");
			}
		}while(existeM ==0);
		do{
			existeMatricula = comprobar_matricula(*mtri,id_alum_,id_materia_);
			if(existeMatricula==1){
		    	printf("Matricula existente.Vuelve a introducir los parametros \n");
		    	break;

			}

		}while(existeMatricula==1);
	   	(*mtri)[nMatricula].id_alum = id_alum_;
		(*mtri)[nMatricula].id_materia = id_materia_;
		printf("Deseea seguir con este proceso? 1-SI || 2- NO ");
	   	scanf("%i",&materias);
	   	nMatricula++;
	   	guardar_matricula(mtri);

}while(materias==1);



}

void eliminar_materias_alumno(matricula **mtri){
	int id_alum_;
	int id_materia_;
	int pos;

    mostrar_matriculas(*mtri);
    do
    {
    printf("\nIntroduce el numero de la matricula que desea modificar: ");
            scanf("%i", &pos);
    } while (pos < 0 || pos >= nMatricula);
    if (pos == nMatricula - 1)
    {
    	nMatricula--;
    }
    else
    {
        (*mtri)[pos].id_materia = (*mtri)[nMatricula - 1].id_materia;
        (*mtri)[pos].id_alum = (*mtri)[nMatricula - 1].id_alum;
        nMatricula--;
    }

    guardar_matricula(mtri);
    system("cls");
    printf("\n            MATRICULA ELIMINADA\n");
    mostrar_matriculas(*mtri);



}
void modificar_materias_alumno(matricula **mtri,alumno **alum,materia **mate){
    //ACLARAR QUE SOLO PUEDO MODIFICAR LA MATERIA DE UN ALUMNO PERO NO DE UN ALUMNO A UNA MATERIA
    int pos, op,  a;
    int existe = 0;
	int existeM =0;
    int existeMatricula = 0;
    int id_alum_;
    int id_materia_;
    system("cls");
   do{
        mostrar_matriculas(*mtri);
	     do{
    		printf("\nIntroduce el numero de la matricula que desea modificar: ");
            scanf("%i", &pos);
    	} while (pos < 0 || pos >= nMatricula);
	    do{
	    	printf("Introduce id de la materia a asignar al alumno: ");
			fflush(stdin);
			scanf("%i",&id_materia_);
			existeM = comprobar_id_materia(*mate, id_materia_);
			if(existeM==0){
		    	printf("Materia no existe \n");
			}
		}while(existeM ==0);
		do{
			existeMatricula = comprobar_matricula(*mtri,id_alum_,id_materia_);
			if(existeMatricula==1){
		    	printf("Matricula existente.Vuelve a introducir los parametros \n");
		    	//break;

			}

		}while(existeMatricula==1);
	    (*mtri)[pos].id_materia = id_materia_;
	    system("cls");
        guardar_matricula(mtri);
        mostrar_matriculas(*mtri);
        printf("\nDesea modificar otro dato (1-SI/2-NO  numero): ");
        scanf("%i", &a);
        system("cls");
        }while (a == 1);
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
        puts("dar de alta\n");
        dar_alta_materia(&mate);
        break;
    case 2:
        puts("dar de baja\n");
        eliminar_materia(&mate, op);
        break;
    case 3:
        puts("modifica materiar\n");
        modificar_materia(&mate);
        break;
    case 4:
        puts("listar alumnos");
        listar_materia(mate);
        break;
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
        printf("Introduce tu id de materia: ");
        //fflush(stdin);
		//fgets (cadena, sizeof (cadena), stdin);
		scanf( "%i", &id_materia_);
        //fgets(id_alum_, 5, stdin);
        //salto(id_alum_);
        existe = comprobar_id_materia(*mate, id_materia_);
        if (existe == 1){
                printf("Esta materia ya existe\n");
        }
        } while (existe == 1);
        (*mate)[nMateria].id_materia = id_materia_;

        printf("Introduce el nombre de la asignatura: ");
        fflush(stdin);
        fgets((*mate)[nMateria].nombre_materia, 51, stdin);
        salto((*mate)[nMateria].nombre_materia);
        fflush(stdin);

        printf("Introduce la abreviatura de la asignatura: ");
        fflush(stdin);
        fgets((*mate)[nMateria].abrev_materia, 5, stdin);
        salto((*mate)[nMateria].abrev_materia);
        fflush(stdin);


        nMateria++;

        guardar_materias(mate);
	}

void eliminar_materia(materia **mate, int op)
{
        mostrar_materias(*mate);
        do
        {
            printf("\nIntroduce el numero de la materia que desea eliminar: ");
            scanf("%i", &op);
        } while (op < 0 || op >= nMateria);

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


    guardar_materias(mate);
    system("cls");
    printf("\n            MATERIA ELIMINADA\n");
}

void modificar_materia(materia **mate)
{
    int pos, op, existe, a, est;
    int id_materia_;
    system("cls");
    do
    {
        mostrar_materias(*mate);
        do
        {
            printf("\nIntroduce el numero de la materia que desea modificar: ");
            scanf("%i", &pos);
        } while (pos < 0 || pos >= nMateria);
        do
        {
            printf("Que dato desea modificar: ");
            scanf("%i", &op);
        } while (op < 1 || op > 3);

        switch (op)
        {
        case 1:
            do
            {
                existe = 0;
                printf("Introduce el nuevo id de la materia: ");
                fflush(stdin);
                scanf("%i", &id_materia_);
                //salto(id_alum_);
                existe = comprobar_id_materia(*mate, id_materia_);
                if (existe == 1)
                {
                    printf("Esta materia ya existe\n");
                }
            } while (existe == 1);
            (*mate)[pos].id_materia =  id_materia_;
            break;
        case 2:
            printf("Introduce el nuevo nombre completo: ");
            fflush(stdin);
            fgets((*mate)[pos].nombre_materia, 51, stdin);
            salto((*mate)[pos].nombre_materia);
            break;
        case 3:
            printf("Introduce la nueva abreviatura: ");
            fflush(stdin);
            fgets((*mate)[pos].abrev_materia, 5, stdin);
            salto((*mate)[pos].abrev_materia);
            break;
        }
        system("cls");
        guardar_materias(mate);

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
    printf("////1-id || 2-nombre_materia || 3-abreviatura////\n");
    for (i = 0; i < nMateria; i++)
    {
        printf("%i-%i/%s/%s\n", i, mate[i].id_materia, mate[i].nombre_materia, mate[i].abrev_materia);

        puts("////////////////////////////////////////////////////////////////////////////////////////////////////");
    }
}

void MenuHorarios(horario *hor,materia *mate){
    int menuAnadir,op;
    do
    {
        printf("\nSeleccione una opcion:\n");
        printf("1: Dar de alta horario \n");
        printf("2: Dar de baja horario\n");
        printf("3: Modificar horario\n");
        printf("4: Listar horario\n");
        fflush(stdin);
        scanf("%i", &menuAnadir);
    } while (menuAnadir < 1 || menuAnadir > 4);
    switch (menuAnadir)
    {

    case 1:
        puts("a�adir horas de clase a un profesor\n");
        anadir_horas_profesor(&hor);
        break;
    case 2:
        puts("elminar horas de clase a un profesor\n");
        eliminar_horario(&hor, int op);
        break;
    case 3:
        puts("modificar horas de clase a un profesor\n");
      	 modificar_horario(&hor,&mate);
        break;
    case 4:
        puts("listar horas de clase a un profesors");
         listar_horarios(hor);
        break;
    }
}


void anadir_horas_profesor(horario **hor){

    int id_profesor_;
    int id_materia_;
    int hora_clase_,dia_clase_;
    int existe;
    *hor = (horario *)realloc((*hor), (nAlumno + 1) * sizeof(horario));
    do
    {
        existe = 0;
        printf("Introduce  id de profesor: ");
        scanf( "%i", &id_profesor_);
        
        printf("Introduce  dia de la clase: ");
        scanf( "%i", &dia_clase_);
        
        printf("Introduce  hora de la clase: ");
        scanf( "%i", &hora_clase_);
        
        printf("Introduce  id de materia: ");
        scanf( "%i", &id_materia_);
        
        existe = comprobar_id_horario(*hor, id_profesor_,id_materia_,dia_clase_,hora_clase_);
        if (existe == 1)
        {
            printf("Este horario ya existe\n");
        }
        } while (existe == 1);
        
        (*hor)[nHorario].id_profesor = id_profesor_;
        (*hor)[nHorario].dia_clase = dia_clase_;
        (*hor)[nHorario].hora_clase = hora_clase_;
        (*hor)[nHorario].id_materia = id_materia_;
        

        
        nHorario++;

        guardar_horarios(hor);
    }
void eliminar_horario(horario **hor, int op)
{
        mostrar_horarios(*hor);
        do
        {
            printf("\nIntroduce el numero del horario que desea eliminar: ");
            scanf("%i", &op);
        } while (op < 0 || op >= nHorario);

        if (op == nHorario - 1)
        {
            nHorario--;
        }
        else
        {
            (*hor)[op].id_profesor = (*hor)[nHorario - 1].id_profesor;
           	(*hor)[op].dia_clase = (*hor)[nHorario - 1].dia_clase;
           	(*hor)[op].hora_clase = (*hor)[nHorario - 1].hora_clase;
           	(*hor)[op].id_materia = (*hor)[nHorario - 1].id_materia;
            nHorario--;
        }
    

    guardar_horarios(hor);
    system("cls");
    printf("\n            HORARIO ELIMINADO\n");
}
void modificar_horario(horario **hor,materia **mate)
{	
	
    int pos, op, existe, a, est;
    int id_profesor_;
	int id_materia_;
	int hora_clase_,dia_clase_;
    system("cls");
    do
    {
        mostrar_horarios(*hor);
        do
        {
            printf("\nIntroduce el numero del horario que desea modificar: ");
            scanf("%i", &pos);
        } while (pos < 0 || pos >= nHorario);
        do
        {
            printf("Que dato desea modificar: ");
            scanf("%i", &op);
        } while (op < 1 || op > 4);

        switch (op)
        {
        case 1:
            do
            {
                existe = 0;
                printf("Introduce el nuevo id del profesor: ");
                fflush(stdin);
                scanf("%i", &id_profesor_);
                //salto(id_alum_);
                existe = comprobar_id_horario(*mate, id_profesor_,(*hor)[pos].id_materia,(*hor)[pos].dia_clase,(*hor)[pos].hora_clase);
                if (existe == 1)
                {
                    printf("Este horario ya existe\n");
                }
            } while (existe == 1);
            (*hor)[pos].id_profesor =  id_profesor_;
            break;
        case 2:
        	do
            {
            printf("Introduce el nuevo dia de clase: ");
            fflush(stdin);
            scanf("%i", &dia_clase_);
            existe = comprobar_id_horario(*mate, (*hor)[pos].id_profesor,(*hor)[pos].id_materia,dia_clase_,(*hor)[pos].hora_clase);
            if(existe==1){
            	printf("Este horario ya existe");
            
			}
            } while (existe == 1);
            (*hor)[pos].dia_clase =  dia_clase_;
            break;
        case 3:
        	do{
            printf("Introduce la nueva hora de clase: ");
            fflush(stdin);
            scanf("%i", &hora_clase_);
             existe = comprobar_id_horario(*mate, (*hor)[pos].id_profesor,(*hor)[pos].id_materia,(*hor)[pos].dia_clase,hora_clase_);
            if(existe==1){
            	printf("Este horario ya existe");
        
			}
            } while (existe == 1);
            (*hor)[pos].hora_clase_ =  hora_clase_;

            break;
        case 4:
        	do{
            printf("Introduce el nuevo id de materia: ");
            fflush(stdin);
            scanf("%i", &id_materia_);
            existeM = comprobar_id_materia(*mate,id_materia_);
            if(existe==0){
            	printf("Este materia no existe");
			}
            }while (existeM == 0);
            do{
            	existe = comprobar_id_horario(*mate, (*hor)[pos].id_profesor,id_materia_,(*hor)[pos].dia_clase,(*hor)[pos].hora_clase);
            	if(existe==1){
            	printf("Este horario ya existe");
				}
			}while (existe == 1)
            (*hor)[pos].id_materia =  id_materia_;
            break;
        }
        system("cls");
        guardar_horarios(hor);

        mostrar_horarios(*hor);
        printf("\nDesea modificar otro dato (1-SI/2-NO  numero): ");
        scanf("%i", &a);
        system("cls");
    } while (a == 1);
}
void listar_horarios(horario *hor)
{
    int i;
    printf("Se mostraran todos los horarios del sistema:\n\n");
    puts("//////////////////////////////////////////////////////////////////////////////");

    printf("\n            LISTA DE HORARIOS\n\n");
    printf("////1-id_profesor || 2-dia_clase || 3-hora_clase || 4-id_materia////\n");
   
    for (i = 0; i < nHorario; i++)
    {
        printf("%i-%i/%i/%i/%i\n", i, hor[pos].id_profesor, hor[pos].dia_clase, hor[pos].hora_clase, hor[pos].id_materia);

        puts("////////////////////////////////////////////////////////////////////////////////////////////////////");
    }
}

// FUNCIONES AUXILIARES ALUMNOS
void salto(char *str){
int tam;
    tam=strlen(str);
    str[tam-1]='\0';
}


// FUNCIONES AUXILIARES DE MATERIAS

//MATRICULAS

