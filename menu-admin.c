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

void darAlta_Usuarios(usuario **usu)
{
}

void darBaja_Usuarios(usuario **usu, int op)
{

    if (op == Njugadores - 1)
    {
        Njugadores--;
    }
    else
    {
        strcpy((*jug)[op].nick, (*jug)[Njugadores - 1].nick);
        strcpy((*jug)[op].nom_comp, (*jug)[Njugadores - 1].nom_comp);
        (*jug)[op].nivel = (*jug)[Njugadores - 1].nivel;
        (*jug)[op].vida = (*jug)[Njugadores - 1].vida;
        (*jug)[op].escudo = (*jug)[Njugadores - 1].escudo;
        strcpy((*jug)[op].estado, (*jug)[Njugadores - 1].estado);
        (*jug)[op].cartera = (*jug)[Njugadores - 1].cartera;
        (*jug)[op].p_jugadas = (*jug)[Njugadores - 1].p_jugadas;
        (*jug)[op].p_ganadas = (*jug)[Njugadores - 1].p_ganadas;
        strcpy((*jug)[op].perfil, (*jug)[Njugadores - 1].perfil);
        strcpy((*jug)[op].contrasenia, (*jug)[Njugadores - 1].contrasenia);
        Njugadores--;
    }

    guardar_jugador(*jug);
    system("cls");
    printf("\n            JUGADOR ELIMINADO\n");
    mostrar_jugadores(*jug);
}

// HORARIOS
/*
añadir horas de clase a un profesor concreto
eliminarlas
modificarlas
listar horarios de cada profesor
*/

void alumnos_funciones(alumno *vAlumno, int *nAlumno)
{
    int menuAnadir, i, j, auxiliar1, auxiliar2;
    char eliminarA[2];
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
        fflush(stdin);
        printf("\nIntroduce el identificador del nuevo alumno\n");
        gets((vAlumno)[*nAlumno].id_alum);
        fflush(stdin);
        printf("\nIntroduce el nombre del nuevo alumno\n");
        gets((vAlumno)[*nAlumno].nombre_alum);
        fflush(stdin);
        printf("\nIntroduce la direccion del nuevo alumno\n");
        gets((vAlumno)[*nAlumno].direc_alum);
        fflush(stdin);
        printf("\nIntroduce la localidad del nuevo alumno\n");
        gets((vAlumno)[*nAlumno].local_alum);
        fflush(stdin);
        printf("\nIntroduce el curso del nuevo alumno\n");
        gets((vAlumno)[*nAlumno].curso);
        printf("\nIntroduce el grupo del nuevo alumno\n");
        gets((vAlumno)[*nAlumno].grupo);
        (*nAlumno)++;
        printf("Correctamente anadido\n");

    case 2:
        printf("\nIntroduce el identificador del alumno que desea eliminar\n");
        gets(eliminarA);
        for (j = 0; j < (*nAlumno); j++)
        {
            if (strcmp((vAlumno)[j].id_alum, eliminarA) == 0)
            {
                auxiliar2 = j;
            }
        }

        for (j = auxiliar2; j + 1 < (*nAlumno); j++)
        { ///////////////////////////////////////////////////////
            strcpy((vAlumno)[j].nombre_alum, (vAlumno)[j + 1].nombre_alum);
            strcpy((vAlumno)[j].direc_alum, (vAlumno)[j + 1].direc_alum);
            strcpy((vAlumno)[j].local_alum, (vAlumno)[j + 1].local_alum);
            strcpy((vAlumno)[j].curso, (vAlumno)[j + 1].curso);
            strcpy((vAlumno)[j].grupo, (vAlumno)[j + 1].grupo);
            // PARA ENTEROS (vAlumno)[j].precio=(vAlumno)[j+1].precio;

            (*nAlumno)--;
            printf("\nEl Alumno se elimino correctamente\n");
        }
    case 3:
        int i, d, correctoU = 0;
        char a[2], nuevo_idA[5], nuevo_nombreA[19], nueva_dirA[29], nueva_localA[29], nuevo_cursoA[29], nuevo_grupoA[9];
        printf("Seleccione el identificador del alumno en el que quiere hacer cambios\n\n");

        gets(a);

        for (i = 0; i < (*nAlumno); i++)
        {
            if (strcmp((vAlumno)[i].id_alum, a) == 0)
                correctoU = 1;
            do
            {
                printf("Seleccione una opcion\n");
                printf("1: Cambiar identificador del alumno\n");
                printf("2: Cambiar nombre del alumno\n");
                printf("3: Cambiar direccion del alumno\n");
                printf("4: Cambiar localidad de alumno\n");
                printf("5: Cambiar curso del alumno\n");
                printf("6: Cambiar grupo del alumno\n");
                fflush(stdin);
                scanf("%i", &d);
            } while (d < 1 || d > 6);

            switch (d)
            {
            case 1:
                printf("Introduce el nuevo identificador del alumno\n");
                fflush(stdin);
                gets(nuevo_idA);
                strcpy((vAlumno)[i].id_alum, nuevo_idA);
                break;

            case 2:
                printf("Introduce el nuevo nombre del alumno\n");
                fflush(stdin);
                gets(nuevo_nombreA);
                strcpy((vAlumno)[i].nombre_alum, nuevo_nombreA);
                break;

            case 3:
                printf("Introduce la nueva direccion del alumno\n");
                fflush(stdin);
                gets(nueva_dirA);
                strcpy((vAlumno)[i].direc_alum, nueva_dirA);
                break;

            case 4:
                printf("Introduce la nueva localidad del alumno\n");
                fflush(stdin);
                gets(nueva_localA);
                strcpy((vAlumno)[i].local_alum, nueva_localA);
                break;

            case 5:
                printf("Introduce el nuevo curso del alumno\n");
                fflush(stdin);
                gets(nuevo_cursoA);
                strcpy((vAlumno)[i].curso, nuevo_cursoA);
                break;
            case 6:
                printf("Introduce el nuevo grupo del alumno\n");
                fflush(stdin);
                gets(nuevo_grupoA);
                strcpy((vAlumno)[i].grupo, nuevo_grupoA);
                break;
            }
        }

    case 4:
        int i;
        printf("Se mostraran todos los alumnos del sistema:\n\n");
        puts("//////////////////////////////////////////////////////////////////////////////");
        printf("Los alumnos y su informacion son: \n\n");
        for (i = 0; i < (*nAlumno); i++)
        {

            printf("Identificador del usuario: %d\n", (vAlumno)[i].id_alum);
            printf("Nombre del alumno: %s\n", (vAlumno)[i].nombre_alum);
            printf("Direccion del alumno: %s\n", (vAlumno)[i].direc_alum);
            printf("Localidad del alumno: %s\n", (vAlumno)[i].local_alum);
            printf("Curso del alumno: %s\n", (vAlumno)[i].curso);
            printf("Grupo del alumno: %s\n", (vAlumno)[i].grupo);
            puts("/////////////////////////////////////////////////////////////////////////////");
        }

        puts("////////////////////////////////////////////////////////////////////////////////////////////////////");
    case 5:
        /*Además, para un alumno seleccionado, se permitirá mostrar la lista de materias en las que se encuentra matriculado,
        realizar cambios de matrícula a otras materias, eliminar matrícula en alguna materia y crear nuevas matrículas. */
    }
}

void MenuAlumno(alumno *alum, alumno **alum)
{
    int menuAnadir, op;
    int i, j, auxiliar1, auxiliar2;
    char eliminarA[2];
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
        eliminar_alumno(&alum, &op);
    case 3:
        puts("Seleccionó modificar\n");
        modificar_alumno(&alum);
    }

    dar_alta_alumno(alumno * *alum)
    {
        int id_alum_;
        int existe;
        *alum = (alumno *)realloc((*jug), (nAlumno + 1) * sizeof(alumno));
        do
        {
            existe = 0;
            pritnf("Introduce tu id de alumno");
            fflush(stdin);
            fgets(id_alum_, 5, stdin);
            salto(id_alum_);
            existe = comprobar_id(*alum, id_alum_);
            if (existe == 1)
            {
                printf("Este usuario ya existe\n");
            }
        } while (existe == 1);
        trcpy((*alum)[nAlumno].id_alum, id_alum_);

        printf("Introduce el nombre completo del alumno: ");
        fflush(stdin);
        fgets((*alum)[nAlumno].nombre_alum, 40, stdin);
        salto((*alum)[nAlumno].nombre_alum);
        fflush(stdin);

        printf("Introduce la direccion del alumno: ");
        fflush(stdin);
        fgets((*alum)[nAlumno].direc_alum, 29, stdin);
        salto((*alum)[nAlumno].direc_alum);
        fflush(stdin);

        printf("Introduce la localidad del alumno: ");
        fflush(stdin);
        fgets((*alum)[nAlumno].local_alum, 29, stdin);
        salto((*alum)[nAlumno].local_alum);
        fflush(stdin);

        printf("Introduce el curso del alumno: ");
        fflush(stdin);
        fgets((*alum)[nAlumno].curso, 29, stdin);
        salto((*alum)[nAlumno].curso);
        fflush(stdin);

        printf("Introduce el grupo del alumno: ");
        fflush(stdin);
        fgets((*alum)[nAlumno].grupo, 9, stdin);
        salto((*alum)[nAlumno].grupo);
        fflush(stdin);

        nAlumno++;

        guardar_jugador(*alum);
    }
}

void eliminar_usuario(alumno **alum, int op)
{

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

    guardar_alumno(*alum);
    system("cls");
    printf("\n            ALUMNO ELIMINADO\n");
}

void modificar_alumno(alumno **alum)
{
    int pos, op, existe, a, est;
    int id_alum_;
    system("cls");
    do
    {
        mostrar_alumno(*alum);
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
                scanf("%i", &(*alum)[pos].id_alum);
                salto(id_alum_);
                existe = comprobar_id(*jug, id_alum_);
                if (existe == 1)
                {
                    printf("Este alumno ya existe\n");
                }
            } while (existe == 1);
            strcpy((*alum)[pos].id_alum, id_alum_);
            break;
        case 2:
            printf("Introduce el nuevo nombre completo: ");
            fflush(stdin);
            fgets((*alum)[pos].nombre_alum, 19, stdin);
            salto((*alum)[pos].nombre_alum);
            break;
        case 3:
            printf("Introduce la nueva direccion: ");
            fflush(stdin);
            fgets((*alum)[pos].direc_alum, 29, stdin);
            salto((*alum)[pos].direc_alum);
            break;
        case 4:
            printf("Introduce la nueva localidad: ");
            fflush(stdin);
            fgets((*alum)[pos].local_alum, 29, stdin);
            salto((*alum)[pos].local_alum);
            break;
        case 5:
            printf("Introduce el nuevo curso: ");
            fflush(stdin);
            fgets((*alum)[pos].curso, 29, stdin);
            salto((*alum)[pos].curso);
            break;
        case 6:
            printf("Introduce el nuevo grupo: ");
            fflush(stdin);
            fgets((*alum)[pos].grupo, 9, stdin);
            salto((*alum)[pos].grupo);
            break;
        }
        system("cls");
        guardar_alumno(*alum);

        mostrar_alumnos(*alum);
        printf("\nDesea modificar otro dato (1-SI/2-NO  numero): ");
        scanf("%i", &a);
        system("cls");
    } while (a == 1);
}
// FUNCIONES AUXILIARES
void salto(char *str)
{
    int tam;
    tam = strlen(str);
    str[tam - 1] = '\0';
}

int comprobar_id(alumno *alum, char *id_alum)
{
    int i = 0;
    while (i < nAlumno && strcmp(alum[i].id_alum, id_alum) != 0)
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

void mostrar_alumno(alumno * alum, int pos)
{
    printf("1-id || 2-nombre_completo || 3-direc_alum || 4-curso || 5-grupo\n");

    if (pos > 0 && pos < nAlumno)
    {
        printf("\n%i/%s/%s/%s/%s\n", alum[pos].id_alum, jug[pos].nombre_usuario, jug[pos].perfil_usuario, jug[pos].usuario, jug[pos].contrasena);
    }
}
void mostrar_alumnos(alumno * alum)
{
    printf("\n            LISTA DE JUGADORES\n\n");
    printf("1-id || 2-nom_comp || 3-direc_alum || 4-curso || 5-grupo\n");
    int i;
    for (i = 0; i < nAlumno; i++)
    {
        printf("%i-%i/%s/%s/%s/%s\n", i, alum[pos].id_alum, jug[pos].nombre_usuario, jug[pos].perfil_usuario, jug[pos].usuario, jug[pos].contrasena);
    }
}

void guardar_alumno(alumno *alum){
	FILE *f;
	int i;
	f=fopen("Alumnos.txt","w+");
	for(i=0;i<nAlumno;i++){
		fprintf(f,"%i/%s/%s/%s/%s\n",alum[pos].id_alum, jug[pos].nombre_usuario, jug[pos].perfil_usuario, jug[pos].usuario, jug[pos].contrasena);
	}
fclose(f);
}
    // holaaaaa
    // adios
