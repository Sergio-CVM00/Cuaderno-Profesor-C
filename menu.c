#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
/*#include "usuario.h"
#include "usuario.h"
#include "calificaciones.h"
#include "alumno.h"
#include "horario.h"*/
/*
#include "menu-profesor.h"
#define PROF 0
#define ADM  1
void menu_inicio(usuario **usu,alumno **alum,horario **hor,calificaciones **cali){

        int op ,perfil_,rep,pos=-1,inicio,pos_actual;
        do{
                do{
                        printf("1: Iniciar sesion\n");
                        printf("2: Registrarme\n");
                        printf("3: Ficha alumno\n");

                        fflush(stdin);
                        system("cls");
                        scanf("%i",&op);
                } while(op<1 || op>3);

                switch(op){
                        case 1:iniciar_sesion(*usu);
                        break;
                        case 2:registrarse(*usu);
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
	                       // do{
	                    printf("1: Cambiar de perfil\n");
	                    printf("2: Abrir menu profesor\n");
	                    printf("3: Salir\n");
	                    system("cls");
						scanf("%i",&op);
	                    }while(op<1 && op>5);
	                        switch(op){
	                            case 1: pos_actual=pos;
	                                pos=iniciar_sesion(usu);
	                                if(pos==-1){pos=pos_actual;}
	                                    inicio=1;
	                                    break;
	                            case 2: MenuProfesor(*usu,alum,hor,cali);
	                                break;
	
	                               default: inicio=2;
	                        }
	                        if(inicio==1){rep=0;}
	                        else{
	                            printf("Quieres hacer algo mas (1-SI 2-NO  numero): ");
	                            scanf("%i",&rep);
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
	                                        case 1: menu_configuracion_admin();
	                                                break;
	
	                                        case 2: pos_actual=pos;
	                                                pos=iniciar_sesion(usu);
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
        }while(inicio==1);
        system("pause");
        system("cls");

//}
}
*/

