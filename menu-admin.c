//test git sergio
//He modificado desde MI RAMA, hago un commit de los cambios que he hecho.
//Pusheo esos cambios a MI RAMA para tenerlos guardado en github.

//Cuando quieras llevar los cambios de ese fichero a la rama MAIN.
//Dentro de github desktop te colocas en la rama main, vas a la opcion de "branch/rama"
//PULSAS "merge into current branch" seleccionas la rama de la cual quieras traer esos cambios.


void usuarios_alta( ){
{
    *Vusuarios=realloc((equipo *)(*vEquipos),((*nEquipos)+1)*sizeof(equipo));

    printf("INTRODUCE LA ID DE EQUIPO (2 caracteres numéricos):\n");
    scanf(" %2s",(*vUsuarios)[*nUsuarios].id);

    printf("INTRODUCE EL NOMBRE COMPLETO (40 caracteres max.):\n");
    scanf(" %40s",(*vUsuarios)[*nUsuarios].nombre);

    (*usuarios)++;
}


void AnadirUsuarios(usuario *vUsuario, int *nUsuario){


     fflush(stdin);
     printf("\nIntroduce el identificador del nuevo usuario\n");
	 gets((vUsuario)[*nUsuario].id_usuario);
	 fflush(stdin);
     printf("\nIntroduce el nombre del nuevo usuario\n");
	 gets((vUsuario)[*nUsuario].nombre);
	 fflush(stdin);
     printf("\nIntroduce el perfil del nuevo usuario\n");
	 gets((vUsuario)[*nUsuario].Rol);
	 fflush(stdin);
     printf("\nIntroduce el nombre de USUARIO del nuevo usuario\n");
	 gets((vUsuario)[*nUsuario].nick);
	 fflush(stdin);
     printf("\nIntroduce la contrasena del nuevo usuario\n");
	 gets((vUsuario)[*nUsuario].contrasena);
     (*nUsuario)++;
     printf("Correctamente anadido\n");

    }