#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <iostream>
#include "juego.h"
#include "menu.h"
#include "mostrarEnPantalla.h"
#include "creditos.h"
#include "reglas.h"
#include "estadisticas.h"

using namespace std;


int menu(){
    string confirmacion;
    string ganador;
    int puntajeGanador;
    int vectorPuntajeRanking[6]= {0};
    string vectorNombre[6]= {" "};
    while (true) {

        int opc=mostrarOpcionesMenu();

        switch(opc) {
            case 1:
                limpiarPantalla();
                comienzoJuego(ganador, puntajeGanador,vectorPuntajeRanking,vectorNombre); //Funcion del juego
                presioneEnterParaContinuar();
                break;
            case 2:
                limpiarPantalla();
                mostrarReglas();  //Funcion para mostrar las reglas del juego
                presioneEnterParaContinuar();
                break;
            case 3:
                limpiarPantalla();
                mostrarCreditos(); // Funcion para mostrar los cŕeditos
                presioneEnterParaContinuar();
                break;
            case 4:
                limpiarPantalla();
                ranking(ganador, puntajeGanador,vectorPuntajeRanking,vectorNombre); //Funcion para mostrar un ranking de mejores 5 jugadores
                presioneEnterParaContinuar();
                break;
            case 5: //Opcion para salir del menu
                limpiarPantalla();
                cout << "Confirma que desea salir del menu? si/no" << endl;
                cin>>confirmacion;
                limpiarPantalla();
                while(confirmacion != "si"&& confirmacion != "no"){

                    cout << "Opcion incorrecta"<<endl<<"Confirma que desea salir del menu? si/no" << endl;
                    cin>>confirmacion;
                    limpiarPantalla();
                }
                if (confirmacion=="si"){
                    cout << "Gracias por jugar! Te esperamos de nuevo pronto!" << endl;
                    return 0; // si ingresa la opcion 5 y confirma, el programa finaliza.
                }
                break;
            default:
                limpiarPantalla();
                cout << "opcion icorrecta" << endl;
                presioneEnterParaContinuar();
        }
        limpiarPantalla();
    }
}




#endif // MENU_H_INCLUDED
