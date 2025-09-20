#ifndef ESTADISTICAS_H_INCLUDED
#define ESTADISTICAS_H_INCLUDED

#include <iostream>
#include "mostrarEnPantalla.h"

using namespace std;


void mostrarPuntajeFinal (int contadorBonzosJ1, int contadorBonzosJ2, int maxLanzamientosexitososJ1, int maxLanzamientosexitososJ2,int subTotalJ1,int subTotalJ2, string nombreJugador1,string nombreJugador2,string &ganador, int &puntajeGanador){
    int puntosPorLanzamientoJ1=0;
    int puntosPorLanzamientoJ2=0;
    int puntosExtraJ1=0;
    int puntosExtraJ2=0;
    int puntosPorBonzoJ1=0;
    int puntosPorBonzoJ2=0;
    int totalJugador1=0;
    int totalJugador2=0;

    //calcular lanzamientos exitosos
    if(maxLanzamientosexitososJ1>maxLanzamientosexitososJ2){
        puntosPorLanzamientoJ1=5;
    }else if (maxLanzamientosexitososJ2>maxLanzamientosexitososJ1){
        puntosPorLanzamientoJ2=5;
    }else{
        puntosPorLanzamientoJ1=5;
        puntosPorLanzamientoJ2=5;
    }

    //Otorgar 3 puntos cada 50
    puntosExtraJ1=(subTotalJ1/50)*3;
    puntosExtraJ2=(subTotalJ2/50)*3;

    //Otorgar 5 puntos por cada bonzo obtenido
    puntosPorBonzoJ1=contadorBonzosJ1*5;
    puntosPorBonzoJ2=contadorBonzosJ2*5;

    //Calcular puntos finales
    totalJugador1=subTotalJ1+puntosPorLanzamientoJ1+puntosPorBonzoJ1+puntosExtraJ1;
    totalJugador2=subTotalJ2+puntosPorLanzamientoJ2+puntosPorBonzoJ2+puntosExtraJ2;

    //Determinar ganador de la partida
    if(totalJugador1>totalJugador2){
        ganador=nombreJugador1;
        puntajeGanador=totalJugador1;
    }else if (totalJugador2>totalJugador1){
        ganador=nombreJugador2;
        puntajeGanador=totalJugador2;
    }else if(contadorBonzosJ1>contadorBonzosJ2){
        ganador=nombreJugador1;
        puntajeGanador=totalJugador1;
    }else if (contadorBonzosJ2>contadorBonzosJ1){
        ganador=nombreJugador2;
        puntajeGanador=totalJugador2;
    }else if(maxLanzamientosexitososJ1>maxLanzamientosexitososJ2){
        ganador=nombreJugador1;
        puntajeGanador=totalJugador1;
    }else if(maxLanzamientosexitososJ2>maxLanzamientosexitososJ1){
        ganador=nombreJugador2;
        puntajeGanador=totalJugador2;
    }else{
        puntajeGanador=0;
    }

    limpiarPantalla();
    presioneEnterParaMostrarResultados();
    limpiarPantalla();
    //Una vez finalizada la partida, calcula los puntos, en caso de que exista un ganador lo determina, y muestra por pantalla las estadisticas de la partida
    mostrarTablaPuntajeFinal(nombreJugador1,nombreJugador2,subTotalJ1,subTotalJ2,puntosExtraJ1,puntosExtraJ2,puntosPorBonzoJ1,puntosPorBonzoJ2,contadorBonzosJ1,contadorBonzosJ2,puntosPorLanzamientoJ1,puntosPorLanzamientoJ2,maxLanzamientosexitososJ1,maxLanzamientosexitososJ2,totalJugador1,totalJugador2,puntajeGanador,ganador);
}


void subtotalPuntaje(int vectorPuntajeJugador1[],int vectorPuntajeJugador2[],int &subTotalJ1,int &subTotalJ2){
    //Una vez finalizada la partida, lee el contenido de los vectores que contienen el puntaje por ronda y los acumula para tener el puntaje de las 6 rondas en una sola variable y poder compararla
    for (int i=0; i<6; i++){
        subTotalJ1+= vectorPuntajeJugador1[i];
        subTotalJ2+= vectorPuntajeJugador2[i];
    }
}


void ranking(string ganador, int puntajeGanador,int vectorPuntajeRanking[],string vectorNombre[]){

    if(puntajeGanador>0){
        cout<<endl<<"El ultimo ganador fue "<<ganador<<" con "<<puntajeGanador<<" puntos."<<endl<<endl;
    }else{
        cout<<endl<<"Todavia no hay datos de ningun jugador, intenta jugar una partida!"<<endl<<endl;
    }
    cout<<"------------------------------ Ranking ------------------------------"<<endl<<endl;
    cout<<"Posicion                    Nombre                    Puntaje"<<endl;
    cout<<"---------------------------------------------------------------------"<<endl;
    for (int i=0; i<5; i++){
        if(vectorPuntajeRanking[i]>0){
            cout<<"   "<<i+1<<"                        "<<vectorNombre[i]<<"                         "<<vectorPuntajeRanking[i]<<endl;
            cout<<"---------------------------------------------------------------------"<<endl;
        }
    }

}


void actualizarRanking(string ganador, int puntajeGanador, int vectorPuntajeRanking[], string vectorNombre[]){

    vectorPuntajeRanking[5]=puntajeGanador;
    vectorNombre[5]=ganador;

    for (int x=0; x<6; x++){
        for (int i=0; i<5; i++){
            if (vectorPuntajeRanking[i] < vectorPuntajeRanking[i+1]){
                int auxPuntaje= vectorPuntajeRanking[i];
                string auxNombre= vectorNombre[i];
                vectorPuntajeRanking[i]=vectorPuntajeRanking[i+1];
                vectorNombre[i]=vectorNombre[i+1];
                vectorPuntajeRanking[i+1]=auxPuntaje;
                vectorNombre[i+1]=auxNombre;
            }
        }
    }
}



#endif // ESTADISTICAS_H_INCLUDED
