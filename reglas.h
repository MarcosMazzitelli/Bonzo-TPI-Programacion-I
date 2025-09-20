#ifndef REGLAS_H_INCLUDED
#define REGLAS_H_INCLUDED

#include <iostream>

using namespace std;

void mostrarReglas() {
    cout << "--------------------- Reglas del Juego: Bonzo ---------------------" << endl;
    cout << "Inicio:" << endl;
    cout << "1. Se lanza un dado para determinar que jugador comienza:" << endl;
    cout << "   - Impar: comienza el jugador 2." << endl;
    cout << "   - Par: comienza el jugador 1." << endl;
    cout << endl;
    cout << "Desarrollo del Juego:" << endl;
    cout << "2. Rondas: Cada jugador juega 6 rondas." << endl;
    cout << "3. Lanzamiento de Dados:" << endl;
    cout << "   - Cada jugador lanza tres dados por turno." << endl;
    cout << "   - Si no hay numero prohibido, se suman los valores y el jugador decide si seguir lanzando o plantarse." << endl;
    cout << "   - Numero Prohibido: Si aparece, el jugador pierde todos los puntos de esa ronda." << endl;
    cout << "      * Dos de tres dados son numeros prohibidos: se pierde la ronda y se lanzara con dos dados en la proxima." << endl;
    cout << "      * Dos de dos dados son numeros prohibidos: se pierde la ronda y se reinicia el puntaje total." << endl;
    cout << "      * Tres numeros prohibidos: el jugador pierde automaticamente." << endl;
    cout << "4. Bonzo, ve a dormir:" << endl;
    cout << "   - Si un jugador lanza tres dados iguales (no el numero prohibido), gana un 'Bonzo, ve a dormir'." << endl;
    cout << "   - Este Bonzo permite dos acciones:" << endl;
    cout << "     1) Quitarle un dado al oponente (en caso de que el oponente no este penalizado previamente)" << endl;
    cout << "     2) Duplicar los puntos obtenidos en esa ronda." << endl;
    cout << endl;
    cout << "Finalizacion del Juego:" << endl;
    cout << "5. Al finalizar las 6 rondas, se suman los puntos obtenidos y se asignan puntos adicionales por hitos:" << endl;
    cout << "   - Cada 'Bonzo, ve a dormir': 5 puntos." << endl;
    cout << "   - Superar los 50 puntos: 3 puntos por cada 50 puntos superados." << endl;
    cout << "   - Ronda con mayor cantidad de lanzamientos exitosos: 5 puntos." << endl;
    cout << "      * La racha de lanzamientos solo contabiliza si el jugador se planta." << endl;
    cout << "6. El jugador con mas puntos es el ganador." << endl;
    cout << "   - En caso de empate total, gana quien haya conseguido mas 'Bonzo, ve a dormir'." << endl;
    cout << endl;
}

#endif // REGLAS_H_INCLUDED
