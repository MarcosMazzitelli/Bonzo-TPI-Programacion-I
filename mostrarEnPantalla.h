#ifndef MOSTRARENPANTALLA_H_INCLUDED
#define MOSTRARENPANTALLA_H_INCLUDED

#include <iostream>

using namespace std;


void limpiarPantalla(){
    #ifdef _WIN32
        // Para Windows
        system("cls");
    #else
        // Para Linux y Mac
        system("clear");
    #endif
}


void mostrarTablaPuntajeFinal(string nombreJugador1,string nombreJugador2,int subTotalJ1,int subTotalJ2,int puntosExtraJ1,int puntosExtraJ2,int puntosPorBonzoJ1,int puntosPorBonzoJ2,int contadorBonzosJ1,int contadorBonzosJ2,int puntosPorLanzamientoJ1,int puntosPorLanzamientoJ2,int maxLanzamientosexitososJ1,int maxLanzamientosexitososJ2,int totalJugador1,int totalJugador2,int puntajeGanador,string ganador){
    cout<< "Hito                       "<<nombreJugador1<<"               "<<nombreJugador2<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    cout<< "Puntos                     "<<subTotalJ1<<"                 "<<subTotalJ2<<endl;
    cout<< "Cada 50 puntos             "<<puntosExtraJ1<<" ("<<subTotalJ1/50<<")              "<<puntosExtraJ2<<" ("<<subTotalJ2/50<<")"<<endl;
    cout<< "Bonzo, ve a dormir         "<<puntosPorBonzoJ1<<" ("<<contadorBonzosJ1<<")              "<<puntosPorBonzoJ2<<" ("<<contadorBonzosJ2<<")"<<endl;
    cout<< "Mayores lanzamientos       "<<puntosPorLanzamientoJ1<<" ("<<maxLanzamientosexitososJ1<<")              "<<puntosPorLanzamientoJ2<<" ("<<maxLanzamientosexitososJ2<<")"<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    cout<<"TOTAL                       "<<totalJugador1<<"                 "<<totalJugador2<<endl;
    cout << endl;
    if (puntajeGanador==0){
        cout<<"Ha habido un empate."<<endl<<endl;
    }else{
        cout<<"GANADOR: "<<ganador<<" con "<<puntajeGanador<<" puntos."<<endl<<endl;
    }
}

void informarResultados(int vectorDados[], int cantDados) {
    cout << "Has obtenido: ";
    for (int i = 0; i < cantDados; i++) {
        cout << vectorDados[i] << ", ";
    }
    cout << endl<<endl;
}



void mostrarDados(int dado) {

    switch (dado) {
        case 1:
            cout << " --------- \n";
            cout << "|         |\n";
            cout << "|    *    |\n";
            cout << "|         |\n";
            cout << " --------- \n";
            break;
        case 2:
            cout << " --------- \n";
            cout << "| *       |\n";
            cout << "|         |\n";
            cout << "|       * |\n";
            cout << " --------- \n";
            break;
        case 3:
            cout << " --------- \n";
            cout << "| *       |\n";
            cout << "|    *    |\n";
            cout << "|       * |\n";
            cout << " --------- \n";
            break;
        case 4:
            cout << " --------- \n";
            cout << "| *     * |\n";
            cout << "|         |\n";
            cout << "| *     * |\n";
            cout << " --------- \n";
            break;
        case 5:
            cout << " --------- \n";
            cout << "| *     * |\n";
            cout << "|    *    |\n";
            cout << "| *     * |\n";
            cout << " --------- \n";
            break;
        case 6:
            cout << " --------- \n";
            cout << "| *     * |\n";
            cout << "| *     * |\n";
            cout << "| *     * |\n";
            cout << " --------- \n";
            break;
    }
    cout << endl;
}



void mostrarTurno(string nombreJugador1,string nombreJugador2,int nroLanzamiento,int ronda, int jugador){
    cout << "-------------------------- Turno de ";
    if(jugador==1){
        cout<<nombreJugador1;
    }else{
        cout<<nombreJugador2;
    }
    cout<<" ----------------------"<<endl;
    cout<<"Lanzamiento #"<<nroLanzamiento<<endl;
    cout << "NUMERO PROHIBIDO: " << ronda << endl << endl;
}

void mostrarComienzoTurno(string nombreJugador1,string nombreJugador2,int jugador,int ronda){
    cout << "-------------------------- Turno de ";
    if(jugador==1){
        cout<<nombreJugador1;
    }else{
        cout<<nombreJugador2;
    }
    cout<<" ----------------------"<<endl<<endl;
    cout << "NUMERO PROHIBIDO: " << ronda << endl << endl;
    cout << "Presione una tecla seguido de Enter para comenzar su turno...";
    cin.ignore(); // Ignora cualquier caracter pendiente
    cin.get(); // Espera a que el usuario presione Enter
    limpiarPantalla();
}




int mostrarOpcionesMenu(){
    int opc;
    cout << endl;

    cout << " --------------  M E N U   P R I N C I P A L -------------- " << endl;
    cout << " JUEGO DE BONZO" << endl;
    cout << endl;
    cout << "Bienvenidos al juego de Bonzo" << endl;
    cout << endl;
    cout << "Las reglas son muy sencillas: suma lo maximo posible pero siempre tene cuidado de no sacar el numero prohibido!!!" << endl;
    cout << endl;
    cout << endl;
    cout << "OPCIONES: " << endl;
    cout << "1) Jugar" << endl;
    cout << "2) Ver Reglas" << endl;
    cout << "3) Ver Creditos" << endl;
    cout << "4) Ranking" << endl;
    cout << "5) Salir del juego" << endl;
    cout << endl;
    cout << endl;
    cout << "Ingresa opcion: ";
    cin >> opc;
    cout << endl;
    cout << endl;
    return opc;
}

void presioneEnterParaContinuar(){
    cout << "Presiona Enter para continuar...";
    cin.ignore(); // Ignora cualquier caracter pendiente
    cin.get(); // Espera a que el usuario presione Enter
}

void presioneEnterParaTirarDado(){
    cout<< "Presione Enter para lanzar el dado...";
    cin.ignore(); // Ignora cualquier caracter pendiente
    cin.get(); // Espera a que el usuario presione Enter

}

void presioneEnterParaMostrarResultados(){
    cout << "Presiona Enter para mostrar resultados...";
    cin.ignore(); // Ignora cualquier caracter pendiente
    cin.get(); // Espera a que el usuario presione Enter
}

#endif // MOSTRARENPANTALLA_H_INCLUDED

