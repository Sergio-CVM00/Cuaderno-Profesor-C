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

}

void darBaja_Usuarios(usuario **usu, int op)
{

    if (op == NUsuario - 1)
    {
        NUsuario--;
    }
    else
    {
        (*usu)[op].id_usuario = (*usu)[NUsuario - 1].id_usuario;
        strcpy((*usu)[op].nom_comp, (*usu)[NUsuario - 1].nom_comp);
        NUsuario--;
        strcpy((*usu)[op].nick, (*usu)[Njugadores - 1].nick);
        strcpy((*usu)[op].nom_comp, (*usu)[Njugadores - 1].nom_comp);
        (*usu)[op].nivel = (*usu)[Njugadores - 1].nivel;
        (*usu)[op].vida = (*usu)[Njugadores - 1].vida;
        (*usu)[op].escudo = (*usu)[Njugadores - 1].escudo;
        strcpy((*usu)[op].estado, (*usu)[Njugadores - 1].estado);
        (*usu)[op].cartera = (*usu)[Njugadores - 1].cartera;
        (*usu)[op].p_jugadas = (*usu)[Njugadores - 1].p_jugadas;
        (*usu)[op].p_ganadas = (*usu)[Njugadores - 1].p_ganadas;
        strcpy((*usu)[op].perfil, (*usu)[Njugadores - 1].perfil);
        strcpy((*usu)[op].contrasenia, (*usu)[Njugadores - 1].contrasenia);
        Njugadores--;
    }

    guardar_usuario(*jug);
    system("cls");
    printf("\n            USUARIO ELIMINADO\n");
    //mostrar_usuarios(*jug);
}
*/
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
    void dar_alta_alumno(alumno * *alum)
    {
        int id_alum_;
        int existe;
        *alum = (alumno *)realloc((*alum), (nAlumno + 1) * sizeof(alumno));
        do
        {
            existe = 0;
            pritnf("Introduce tu id de alumno");
            fflush(stdin);
            char cadena [100];
			int numero = 0;
			fgets (cadena, sizeof (cadena), stdin);
			sscanf(cadena, "%d", &id_alum_);
            //fgets(id_alum_, 5, stdin);
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

        guardar_alumno(*alum);
    }


void eliminar_alumno(alumno **alum, int op)
{
    do
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
                scanf("%i", &(*alum)[pos].id_alum);
                salto(id_alum_);
                existe = comprobar_id_alumno(*mate, id_alum_);
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

void listar_alumno(alumno *alum)
{
    int i;
    printf("Se mostraran todos los alumnos del sistema:\n\n");
    puts("//////////////////////////////////////////////////////////////////////////////");

    printf("\n            LISTA DE ALUMNOS\n\n");
            printf("1-id || 2-nom_comp || 3-direc_alum || 4-curso || 5-grupo\n");
            int i;
            for (i = 0; i < nAlumno; i++)
            {
                printf("%i-%i/%s/%s/%s/%s\n", i, alum[pos].id_alum, jug[pos].nombre_usuario, jug[pos].perfil_usuario, jug[pos].usuario, jug[pos].contrasena);
            }
    puts("////////////////////////////////////////////////////////////////////////////////////////////////////");
}

void matricula_alumnos(alumno **alum, alumno **materia, matricula **matricula)
{
   
int menuAnadir;
    

    do
    {
        printf("\nSeleccione una opcion:\n");
        printf("1: Listar materias en las que se encuentra matriculado \n");
        printf("2: Crear matricula\n");
        printf("3: Eliminar matricula en alguna materia\n");
        printf("4: Modificar matricula\n");

        fflush(stdin);
        scanf("%i", &menuAnadir);
    } while (menuAnadir < 1 || menuAnadir > 4);
    switch (menuAnadir)
    {

    case 1:
        puts("Seleccionó listar materias alumno\n");
        listar_materias_alumno(&alum, &materia, &matricula);
        break;
    case 2:
        puts("Seleccionó crear matricula alumno\n");
        crear_matricula_alumno(&alum, &materia, &matricula);
        break;
    case 3:
        puts("Seleccionó eliminar materia en alguna  matricula \n");
        eliminar_materias_alumno(&alum, &materia, &matricula);
        break;
    case 4:
        puts("Seleccionó modificar materias de  matriculas\n");
        modificar_materias_alumno(&alum, &materia, &matricula);
        break;
    }
}

void listar_materias_alumno(alumno **alum,materia **mate,matricula **matricula){
    int id_alum_;
    int existe;
    existe = 0;
    pritnf("Introduce tu id de alumno que sea ver su matricula");
    fflush(stdin);
    fgets(id_alum_, 5, stdin);
    salto(id_alum_);
    existe = comprobar_id(*alum, id_alum_);
    // PARA COMPROBAR MATRICULA DE ALUMNO
    if (id_alum_ == (*matricula).id_alum)
    {
        printf("\n            MATRICULA                \n\n");
        printf("1-id || 2-nom_comp || 3-direc_alum || 4-curso || 5-grupo\n");
        int i;
        for (i = 0; i < nMateria; i++)
        {
                printf("%i-%s/%s\n", i, mate[pos].id_materia, mate[pos].nombre_materia, mate[pos].abrev_materia;
        }
    }
}

void crear_matricula_alumno(alumno **alum, materia **mate, matricula **matri)
{
    int id_alum_;
    int existe;
    existe = 0;
    pritnf("Introduce tu id de alumno que sea ver su matricula");
    fflush(stdin);
    fgets(id_alum_, 5, stdin);
    salto(id_alum_);
    existe = comprobar_id(*alum, id_alum_);
}

// MATERIAS
void MenuMaterias()
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
    } while (menuAnadir < 1 || menuAnadir > 4;
    switch (menuAnadir)
    {
    case 1:
        puts("Seleccionó dar de alta\n");
        dar_alta_materia(&mate);
        break;
    case 2:
        puts("Seleccionó dar de baja\n");
        eliminar_materia(&mate, &op);
    case 3:
        puts("Seleccionó modificar\n");
        modificar_materia(&mate);
    case 4:
        puts("Seleccionó listar alumnos");
        listar_materia(&mate);
    case 5:
        /*Además, para un alumno seleccionado, se permitirá mostrar la lista de materias en las que se encuentra matriculado,
        realizar cambios de matrícula a otras materias, eliminar matrícula en alguna materia y crear nuevas matrículas. */
        puts("Seleccionó informacion de alumnos(ver ,modificar matriculas)");
        matricula_alumnos(&alum, &materia, &matricula);
    }

    void dar_alta_materia(materia **mate)
    {
        int id_materia_;
        int existe;
        *mate = (materia *)realloc((*mate), (nMateria + 1) * sizeof(materia));
        do
        {
            existe = 0;
            pritnf("Introduce id de materia");
            fflush(stdin);
            fgets(int id_materia_, 4, stdin);
            salto(id_materia_);
            existe = comprobar_id(*mate, id_materia_);
            if (existe == 1)
            {
                printf("Esta materia ya existe\n");
            }
        } while (existe == 1);
        trcpy((*mate)[nMateria].id_materia, id_materia_);

        printf("Introduce el nombre completo de la materia: ");
        fflush(stdin);
        fgets((*mate)[nMateria].nombre_materia, 49, stdin);
        salto((*mate)[nMateria].abrev_materia);
        fflush(stdin);

        printf("Introduce la abreviatura de la materia: ");
        fflush(stdin);
        fgets((*mate)[nMateria].abrev_materia, 3, stdin);
        salto((*mate)[nMateria].abrev_materia);
        fflush(stdin);

        nMateria++;

        guardar_materia(*mate);
    }
}

void eliminar_materia(materia **mate, int op)
{
    do
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
            strcpy((*mate)[op].nombre_materia, (*mate)[nMateria - 1].nombre_materia
            strcpy((*mate)[op].abrev_materia, (*mate)[nMateria - 1].abrev_materia);
            nMateria--;
        }
    }

    guardar_materia(*mate);
    system("cls");
    printf("\n            MATERIA ELIMINADO\n");
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
        } while (op < 1 || op > 5);

        switch (op)
        {
        case 1:
            do
            {
                existe = 0;
                printf("Introduce el nuevo id: ");
                fflush(stdin);
                scanf("%i", &(*mate)[pos].id_materia);
                salto(id_materia_);
                existe = comprobar_id_materia(*mate, id_materia_);
                if (existe == 1)
                {
                    printf("Esta materia ya existe\n");
                }
            } while (existe == 1);
            strcpy((*mate)[pos].id_materia, id_materia_);
            break;
        case 2:
            printf("Introduce el nuevo nombre de la materia: ");
            fflush(stdin);
            fgets((*mate)[pos].nombre_materia, 49, stdin);
            salto((*mate)[pos].nombre_materia);
            break;
        case 3:
            printf("Introduce la nueva abreviatura: ");
            fflush(stdin);
            fgets((*mate)[pos].abrev_materia, 3, stdin);
            salto((*mate)[pos].abrev_materia);
            break;
        }
        system("cls");
        guardar_materia(*mate);

        mostrar_alumnos(*mate);
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
    int i;
    for (i = 0; i < nMateria; i++)
    {
        printf("%i-%i/%s/%s\n", i, mate[pos].id_materia, mate[pos].nombre_materia, mate[pos].abrev_materia);

        puts("////////////////////////////////////////////////////////////////////////////////////////////////////");
    }
}
}

// FUNCIONES AUXILIARES ALUMNOS
void salto(int *str)
{
    int tam;
    str[tam - 1] = '\0';
}

int comprobar_id_alumno(alumno *alum, int *id_alum)
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

/*void guardar_alumno(alumno * alum)
{
    FILE *f;
    int i;
    f = fopen("Alumnos.txt", "w+");
    for (i = 0; i < nAlumno; i++)
    {
        fprintf(f, "%i/%s/%s/%s/%s\n", alum[pos].id_alum, jug[pos].nombre_usuario, jug[pos].perfil_usuario, jug[pos].usuario, jug[pos].contrasena);
    }
    fclose(f);
}*/
// FUNCIONES AUXILIARES DE MATERIAS
int comprobar_id_materia(materia *mate, int *id_materia)
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

/*void guardar_materia(materia *mate)
        {
            FILE *f;
            int i;
            f = fopen("Materias.txt", "w+");
            for (i = 0; i < nMateria; i++)
            {
                fprintf(f, "%i/%s/%s\n", mate[pos].id_materia, mate[pos].nombre_materia, mate[pos].abrev_materia);
            }
            fclose(f);
        }*/
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
