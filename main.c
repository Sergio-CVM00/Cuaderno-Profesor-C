#include <stdio.h>

#include "menu-admin.h"



int main(){
    //cargar usuarios del sistema.
    usuario *usu;
    alumno *alum;
    calificaciones *cali;
    horario *hor;
    materia *mate;
    matricula *mtri;
    

    //CARGAR
    cargar_matricula(&mtri); //operativo
    cargar_alumnos(&alum); //operativo
    //cargar_horarios(&hor); //operativo
    cargar_materias(&mate); //operativo
    //cargar_calificaciones(&cali); //operativo
    //cargar_usuarios(&usu); // pendiente de solucionar (maximo 2 usuarios)
    //printf("\n nUsuario: %i", nMateria);

	
    //GUARDAR
    
    //guardar_matricula(&mtri);
    //guardar_alumnos(&alum);
    //guardar_materias(&mate);
    //guardar_horarios(&hor);
    //guardar_calificaciones(&cali);
    //guardar_usuarios(&usu);


	//COMPROBACIONES DE FUNCIONES DE ROBE
	//MenuAlumno(alum,mtri,mate); //operativa al 100%. 
	//MenuMaterias(mate); //operativa al 100%
	menu_matricula_alumnos(mtri,alum,mate); //operativo al 100%
	

	
	
    return 0;
    //dsgsgr

}
