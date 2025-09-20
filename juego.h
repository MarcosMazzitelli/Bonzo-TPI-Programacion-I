#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

#include <iostream>
#include "mostrarEnPantalla.h"
#include "estadisticas.h"


using namespace std;

int tirarUnDado(){
    return rand() % 6 + 1;
}

bool hayBonzo(int vectorDados[],int cantDados){
    int contador=0;
    if (cantDados==3){ //Solo evalua si se tiran 3 dados
        for(int i=0; i<cantDados-1; i++){   //Solo dos vueltas para no realizar una iteracion de mas en una posicion del vector inexistente (posicion 4)
            if (vectorDados[i]==vectorDados[i+1]){ //Acumulamos si dado 0 es igual a dado 1 || y si dado 1 es igual a dado 2
                contador++;
            }
        }
    }
    if(contador==2){
        return true;
    }else{
    return false;
    }
}


void verificarBonzoVeADormir(int vectorDados[],int cantDados,bool &rivalPenalizado,bool &penalizarJugador1,bool &penalizarJugador2,int &acuTurno, int &tirada,int ronda, int jugador, int &contadorBonzosJ1, int &contadorBonzosJ2){
    string opcion;
    if (hayBonzo(vectorDados, cantDados)){
        cout<<endl<<"Has obtenido un Bonzo ve a dormir!"<<endl<<endl;
          if (!penalizarJugador1 && !penalizarJugador2 && (ronda!=6 || jugador!=2)) { //si ninguno de los dos esta penalizado y no es la ronda 6 y el turno jugador 2. mostramos las dos opciones, sino duplicamos puntos

            cout<<"Seleccione una opcion:"<<endl<<endl;
            cout<<"Ingrese 'DUPLICAR' para duplicar los puntos obtenidos en esta tirada."<<endl;
            cout<<"Ingrese 'QUITAR' para quitarle un dado a su oponente."<<endl<<endl;
            cin>>opcion;
            while (opcion!="duplicar" && opcion!="quitar"){   //validacion de opcion 1 o 2
                cout<<endl<<"Ingrese una opcion valida:"<<endl<<endl;
                cout<<"Ingrese 'duplicar' para duplicar los puntos obtenidos en esta tirada."<<endl;
                cout<<"Ingrese 'quitar' para quitarle un dado a su oponente."<<endl<<endl;
                cin>>opcion;
            }
            cout<<endl<<endl;
            if (opcion=="duplicar"){
                acuTurno+=tirada; //se duplica la tirada (se suma nuevamente ya que en tirar dados ya estaba sumada una vez)
                    cout<<"Su tirada se ha duplicado!"<<endl;
                    cout<<"Ahora tienes: "<<tirada*2<<" puntos."<<endl<<endl<<endl;
            }else{ //si la opcion no es duplicar, entonces es "quitar"
                cout<<endl<<endl<<"Felicidades has penalizado a tu rival!"<<endl<<"El proximo turno lanzara solo con dos dados."<<endl<<endl;
                rivalPenalizado=true; //bandera de penalizacion para quitarle el castigo en caso de que siga tirando y saque un numero prohibido
                if(jugador==1){
                    penalizarJugador2=true; // bandera que aplica la penalizacion a un jugador o al otro
                }else{
                    penalizarJugador1=true;
                }
            }
        }else{
            acuTurno+=tirada;
            cout<<"Su tirada se ha duplicado!"<<endl;
            cout<<"Ahora tienes: "<<tirada*2<<" puntos."<<endl<<endl<<endl;
        }
        if (jugador==1){
            contadorBonzosJ1++;
        }else{
            contadorBonzosJ2++;
        }

    }

}



void preguntarSiPlantarse(bool &debePlantarse, int acuTurno, int vectorPuntajeJugador1[], int vectorPuntajeJugador2[], int ronda, int jugador) {
    char decision;
    cout<<"El puntaje total obtenido en este turno es de: "<<acuTurno<<endl;
    cout << "Deseas plantarte (p) o continuar (c)? " << endl;
    cin >> decision;

    while (decision != 'p' && decision != 'c') {
        cout << "Opcion invalida, por favor ingrese una opcion correcta." << endl;
        cout << "Deseas plantarte (p) o continuar (c)? " << endl;
        cin >> decision;
    }
    cout<<endl<<endl<<endl;
    if (decision == 'p') {  // Solo acumlamos el puntaje en el vector si el jugador se planta, sino se pierde.
        debePlantarse = true; //condicion de corte de turno y acumulamos en el vector de puntajes
        if (jugador==1){
            vectorPuntajeJugador1[ronda-1]=acuTurno;
        }else{
            vectorPuntajeJugador2[ronda-1]=acuTurno;
        }

    }
}

void reiniciarPuntaje(int vectorPuntaje[]){
    for (int i=0; i<6; i++){
        vectorPuntaje[i]=0;
    }
}



void analizarNumerosProhibidos(bool &obtuvoNroProhibido, int numerosProhibidos, int &jugador, int &ronda, int vectorPuntajeJugador1[], int vectorPuntajeJugador2[], bool estaPenalizado, bool &penalizarJugador1, bool &penalizarJugador2, bool &rivalPenalizado){

    obtuvoNroProhibido = true; //condicion de corte del while del turno de cada jugador

    if(rivalPenalizado){ // si obtenemos un numero prohibido y previamente penalizamos al rival, perdemos ese bonus.
        cout<<endl<<"Has perdido la posibilidad de quitarle un dado a tu rival."<<endl<<endl;
        penalizarJugador1=false;
        penalizarJugador2=false;
    }
    if (numerosProhibidos==3){
        cout<<"Has sacado 3 numeros prohibidos."<<endl<<endl<<"Perdiste el juego."<<endl<<endl;
        if (jugador==1){ //Seteamos en 0 todo el puntaje por perdedor.
            reiniciarPuntaje(vectorPuntajeJugador1);
        }else{
            reiniciarPuntaje(vectorPuntajeJugador2);
        }
        ronda=6;  //Seteamos manualmente la ronda en 6 y jugador en 2 para que finalice el juego
        jugador=2;
    }else if (numerosProhibidos==2){
        cout<<"Has obtenido dos numeros prohibidos y perdes el turno."<<endl;
        if(estaPenalizado){ //si esta penalizado (lanza con dos dados y ambos son prohibidos) se reinicia su puntaje en 0
            cout<<endl<<"Has perdido el puntaje acumulado hasta el momento."<<endl;
            if (jugador==1){
                reiniciarPuntaje(vectorPuntajeJugador1);
            }else{
                reiniciarPuntaje(vectorPuntajeJugador2);
            }
        }else if (ronda!=6){ //si salen 2 de 3 prohibidos, se penaliza y la proxima ronda tira con dos dados, a no ser que sea la ultima ronda.
            cout<<"La siguiente ronda lanzaras con dos dados."<<endl;
            if(jugador==1){
                penalizarJugador1=true;
            }else{
                penalizarJugador2=true;
            }
        }
    }else{
        cout << endl << "Has sacado un numero prohibido y pierdes el turno." << endl;
    }
}

int ContarNumerosProhibidos(int ronda, int dados[], int cantDados) {
    int contador = 0;
    for (int i = 0; i < cantDados; i++) {
        if (dados[i] == ronda) {
            contador++;
        }
    }
    return contador;
}


void analizarDados(int &jugador, int &ronda, int vectorDados[], int cantDados, bool &debePlantarse, bool &obtuvoNroProhibido, bool &rivalPenalizado, int &acuTurno, int vectorPuntajeJugador1[],int vectorPuntajeJugador2[], bool &penalizarJugador1, bool &penalizarJugador2, bool estaPenalizado, int &lanzamientosExitososJ1, int &lanzamientosExitososJ2,int &maxLanzamientosexitososJ1,int &maxLanzamientosexitososJ2, int &tirada, int &contadorBonzosJ1, int &contadorBonzosJ2) {

    int numerosProhibidos = ContarNumerosProhibidos(ronda, vectorDados, cantDados);  //Funcion que cuenta los numeros prohibidos por tirada, segun la ronda en juego

    if(numerosProhibidos>0){ //Si se obtiene al menos un numero prohibido, se analiza la cantidad y las penalizaciones a aplicar
        analizarNumerosProhibidos(obtuvoNroProhibido, numerosProhibidos, jugador, ronda, vectorPuntajeJugador1, vectorPuntajeJugador2, estaPenalizado, penalizarJugador1, penalizarJugador2, rivalPenalizado);
        lanzamientosExitososJ1=0;
        lanzamientosExitososJ2=0;
    }else{
        cout << "Felicidades! No has obtenido ningun numero prohibido." << endl << endl;
        verificarBonzoVeADormir(vectorDados, cantDados, rivalPenalizado, penalizarJugador1, penalizarJugador2, acuTurno, tirada, ronda, jugador,contadorBonzosJ1,contadorBonzosJ2);
        preguntarSiPlantarse(debePlantarse, acuTurno,  vectorPuntajeJugador1, vectorPuntajeJugador2, ronda, jugador); //En caso de lanzamiento exitoso, se pregunta al usuario si continua tirando o se planta
        if(jugador==1){
            lanzamientosExitososJ1++;
        }else{
            lanzamientosExitososJ2++;
        }
    }
    if(debePlantarse && lanzamientosExitososJ1>maxLanzamientosexitososJ1){ //Solo actualiza el maximo si el jugador se planta, sino se reinicia la cantidad de lanzamientos exitosos
        maxLanzamientosexitososJ1=lanzamientosExitososJ1;
    }
    if(debePlantarse && lanzamientosExitososJ2>maxLanzamientosexitososJ2){
        maxLanzamientosexitososJ2=lanzamientosExitososJ2;
    }
}


int dadosATirar (bool estaPenalizado){
    if (estaPenalizado){
        return 2;
    }
    else{
        return 3;
    }
}

void tirarDados(bool estaPenalizado, int vectorDados[], int &cantDados, int &acuTurno, int &tirada) {
    cantDados = dadosATirar(estaPenalizado);
    for (int x = 0; x < cantDados; x++) {
        vectorDados[x] = tirarUnDado();
        mostrarDados(vectorDados[x]);
        tirada+=vectorDados[x];
    }
    acuTurno+=tirada;

    informarResultados(vectorDados, cantDados); //Imprime por pantalla el resultado de la tirada
}

void siPenalizacion(bool &penalizarJugador1, bool &penalizarJugador2, int jugador, bool &estaPenalizado){
    if(jugador==1 && penalizarJugador1==true){
        estaPenalizado=true;
        penalizarJugador1=false;
    }
    else if(jugador==2 && penalizarJugador2==true){
        estaPenalizado=true;
        penalizarJugador2=false;
    }
}

void ingresoNombresJugadores(string &nombreJugador1, string &nombreJugador2) {
    string nombre1, nombre2, confirmacion;
    int dado;

    cout << "Antes de comenzar deben registrar sus nombres: " << endl;
    cout << "Nombre 1: " << endl;
    cin >> nombre1;
    cout<<endl;
    cout<<"El nombre ingresado es: '"<<nombre1<<"' Confirma? si/no"<<endl;
    cin>>confirmacion;
    limpiarPantalla();

    while(confirmacion!="si"){
        cout << "Reingrese el nombre 1: " << endl;
        cin >> nombre1;
        cout<<endl;
        cout<<"El nombre ingresado es: '"<<nombre1<<"' Confirma? si/no"<<endl;
        cin>>confirmacion;
        limpiarPantalla();
    }

    cout << "Nombre 2: " << endl;
    cin >> nombre2;
    cout<<endl;
    cout<<"El nombre ingresado es: '"<<nombre2<<"' Confirma? si/no"<<endl;
    cin>>confirmacion;
    limpiarPantalla();

    while(confirmacion!="si"){
        cout <<"Reingrese el nombre 2: " << endl;
        cin >> nombre2;
        cout<<endl;
        cout<<"El nombre ingresado es: '"<<nombre2<<"' Confirma? si/no"<<endl;
        cin>>confirmacion;
        limpiarPantalla();
    }

    cout<<endl<<"A continuacion se lanzara un dado."<<endl<<endl;
    cout<<"En caso de que salga par comienza jugando "<<nombre1<<"."<<endl;
    cout<<"Y si sale impar comienza "<<nombre2<<"."<<endl<<endl;

    presioneEnterParaTirarDado();
    cout<<endl;
    dado=tirarUnDado();
    mostrarDados(dado);
    if (dado%2==0){
        nombreJugador1=nombre1;
        nombreJugador2=nombre2;
    }else{
        nombreJugador1=nombre2;
        nombreJugador2=nombre1;
    }

    cout<<"El resultado es: "<<dado<<endl;
    cout<<"Comienza tirando "<<nombreJugador1<<"."<<endl<<endl;
    presioneEnterParaContinuar();
    limpiarPantalla();

}


void comienzoJuego(string &ganador, int &puntajeGanador,int vectorPuntajeRanking[], string vectorNombre[]) {
    string nombreJugador1, nombreJugador2;
    bool estaPenalizado = false;  //Comienza en false fuera de los ciclos, luego varia dependiendo de la tirada o si otro jugador aplica penalizacion al rival
    int vectorPuntajeJugador1[6]= {0};
    int vectorPuntajeJugador2[6]= {0};
    bool penalizarJugador1=false; //Se ponen en true si el jugador saca bonzo y elige quitar un dado. una vez que finaliza el turno nos sirve de bandera para la funcion "siPenalizacion" que es la que define si un jugador lanza con 2 o 3 dados
    bool penalizarJugador2=false;
    int lanzamientosExitososJ1=0, maxLanzamientosexitososJ1=0, lanzamientosExitososJ2=0, maxLanzamientosexitososJ2=0;
    int contadorBonzosJ1=0;
    int contadorBonzosJ2=0;
    int subTotalJ1=0; //En estas variables vamos a guardar el contenido del vector de puntaje de cada jugador para tener un manejo mas simple del dato
    int subTotalJ2=0;

    ingresoNombresJugadores(nombreJugador1, nombreJugador2);

    for (int ronda = 1; ronda < 7; ronda++) {    //6 rondas del juego
        for (int jugador = 1; jugador < 3; jugador++) {  //Por cada ronda se alterna entre jugador 1 y 2
            bool debePlantarse = false;
            bool obtuvoNroProhibido = false;
            bool rivalPenalizado = false;
            int cantDados;
            int vectorDados[3];
            int acuTurno=0;
            int nroLanzamiento=1;

            mostrarComienzoTurno(nombreJugador1, nombreJugador2, jugador, ronda);

            siPenalizacion(penalizarJugador1, penalizarJugador2, jugador, estaPenalizado); //Define si el jugador esta o no penalizado al comienzo de su turno

            while (!debePlantarse && !obtuvoNroProhibido) { //Mientras el jugador no se plante y no saque un numero prohibido, el jugador actual va a seguir tirando en la misma ronda.
                mostrarTurno(nombreJugador1,nombreJugador2,nroLanzamiento,ronda, jugador);
                int tirada=0; //Siempre contiene la ultima tirada. Creada para utilizarse solo en caso de BONZO si se elige duplicar puntos.
                tirarDados(estaPenalizado, vectorDados, cantDados, acuTurno, tirada); //Tira, informa y acumula los 2 o 3 dados dependiendo si esta o no penalizado
                analizarDados(jugador, ronda, vectorDados, cantDados, debePlantarse, obtuvoNroProhibido, rivalPenalizado, acuTurno, vectorPuntajeJugador1, vectorPuntajeJugador2,penalizarJugador1, penalizarJugador2, estaPenalizado, lanzamientosExitososJ1, lanzamientosExitososJ2, maxLanzamientosexitososJ1, maxLanzamientosexitososJ2, tirada,contadorBonzosJ1,contadorBonzosJ2); //En funcion de los dados obtenidos, tomara decisiones (guardar puntaje, penalizar, contar prohibidos, bonus,etc.)
                nroLanzamiento++;
            }

            lanzamientosExitososJ1=0;
            lanzamientosExitososJ2=0;
            estaPenalizado=false;
            cout<<endl << "Ha finalizado su turno."<<endl<<endl;
            presioneEnterParaContinuar();
            limpiarPantalla();
        }
    }
    //mostrar resultados
    subtotalPuntaje(vectorPuntajeJugador1, vectorPuntajeJugador2, subTotalJ1, subTotalJ2);
    mostrarPuntajeFinal(contadorBonzosJ1,contadorBonzosJ2,maxLanzamientosexitososJ1,maxLanzamientosexitososJ2, subTotalJ1, subTotalJ2, nombreJugador1, nombreJugador2,ganador, puntajeGanador);
    actualizarRanking(ganador, puntajeGanador,vectorPuntajeRanking,vectorNombre);
}



#endif // JUEGO_H_INCLUDED
