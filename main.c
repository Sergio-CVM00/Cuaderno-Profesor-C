#include <stdio.h>
#include "menu-admin.h"
#define PROF 0
#define ADM  1
int main(){

    //cargar datos del sistema.
    usuario *usu;
    alumno *alum;
    calificaciones *cali;
    horario *hor;
    materia *mate;
    matricula *mtri;


    //CARGAR
    cargar_matricula(&mtri); //operativo
    cargar_alumnos(&alum); //operativo
    cargar_horarios(&hor); //operativo
    cargar_materias(&mate); //operativo
    cargar_calificaciones(&cali); //operativo
    //cargar_usuarios(&usu); // pendiente de solucionar (maximo 2 usuarios)
    menu_inicio(usu,cali, hor,alum,mate,mtri);



    /*
    -----HORARIOS comprobacaciones-----
    listar_horarios(hor); //operativo -- MODIFICADO
    anadir_horas_profesor(&hor); //operativo --MODIFICADO
    eliminar_horario(&hor); //operativo --MODIFICADO
    modificar_horario(&hor,&mate); //operativo --MODIFICADO
    MenuHorarios(&hor,&mate); //operativo --MODIFICADO
    */
    return 0;

}

void menu_inicio(usuario *usu,calificaciones *cali, horario *hor, alumno *alum,materia *mat, matricula *mtri){

        int op ,perfil_,rep,pos=-1,inicio,pos_actual;
        do{
                do{
                        printf("1: Iniciar sesion\n");
                        printf("2: Registrarme\n");
                        printf("3: Ficha alumno\n");

                        fflush(stdin);
                        scanf("%i",&op);
                } while(op<1 || op>3);

                switch(op){
                        case 1:iniciar_sesion(&usu);
                        break;
                        case 2:registrarse(&usu);
                        break;
                }

        }while (pos==-1);

        do{
                inicio=0;
                if(strcmp(usu[pos].perfil_usuario,"ADM")==0){
                perfil_=1;
                }else{perfil_=0;}

                switch(perfil_){
	                case PROF:




                            do{
                                printf("1: Cambiar de perfil\n");
                                printf("2: Abrir menu profesor\n");
                                printf("3: Salir\n");
                                system("cls");
                                scanf("%i",&op);
                            }while(op<1 && op>5);
	                        switch(op){
	                            case 1: pos_actual=pos;
	                                pos=iniciar_sesion(&usu);
	                                if(pos==-1){pos=pos_actual;}
	                                    inicio=1;
	                                    break;
	                            case 2: MenuProfesor(alum,cali);
	                                break;

                                default: inicio=2;
	                        }
                                do{
                                    if(inicio==1){rep=0;}
                                    else
                                    {
                                        printf("Quieres hacer algo mas (1-SI 2-NO  numero): ");
                                        scanf("%i",&rep);
                                    }
                                }while(rep==1);
                                break;

	                case ADM:
	                        do{
	                        system("cls");
	                                do{
	                                        printf("1: Menu Administrador\n");
	                                        printf("2: Cambiar perfil\n");
	                                        printf("3: Salir\n");
	                                        scanf("%i",&op);
	                                }while(op<1 && op>2);
	                                switch(op){
	                                        case 1: menu_general(&usu, &cali, &hor,  &alum, &mat, &mtri);
	                                                break;

	                                        case 2: pos_actual=pos;
	                                                pos=iniciar_sesion(&usu);
	                                                if(pos==-1){pos=pos_actual;}
	                                                inicio=1;
	                                                break;
	                                        default: inicio=2;
	                                        }
	                                if(inicio==1){
	                                        rep=0;
	                                }
	                                else{
	                                        printf("Quieres hacer algo mas (1-SI 2-NO  numero): ");
	                                        scanf("%i",&rep);
	                                }
	                        }while(rep==1);
	                break;
                }
        }while(inicio==1);
        system("pause");
        system("cls");

//}
}
