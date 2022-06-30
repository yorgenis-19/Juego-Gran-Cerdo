#include<cstring>
#include<time.h>
#include<cstdlib>
#include<iostream>
using namespace std;

#include "Funciones.h"
/*Esta funcion muestra por pantalla las opciones del menu del juego*/
void OpcionesMenu(){
    cout << "GRAN CERDO" << endl;
    cout << "-------------------" << endl;
    cout << "1 - JUGAR" << endl;
    cout << "2 - ESTADISTICAS" << endl;
    cout << "3 - CERDITOS" << endl;
    cout << "-------------------" << endl;
    cout << "0 - SALIR" << endl;
}
/* Esta funcion resibe los nombres de los jugadores y los almacena en un vector */
char NombreJugadores(char jugador1[], char jugador2[], int VCantidad){
    cout << "BIENVENIDO" << endl;
    cout << endl;
    cout << "INGRESAR NOMBRE DEL JUGADOR #1: ";
    cin.getline(jugador1, VCantidad);
    cout << "INGRESAR NOMBRE DEL JUGADOR #2: ";
    cin.getline(jugador2, VCantidad);

}
/* En esta funcion se determinara quien va ser el primero en lanzar, con el lanzamientos de dados */
char SeleccionarPrimerJ(char jugador1[], char jugador2[], char primerJ[], char segundoJ[]){
    cout << endl;
    cout <<"ESTA RONDA ES PARA DETERMINAR QUIEN VA PRIMERO" << endl;
    cout <<"DEBE APRETAR LA LETRA S PARA LANZAR LOS DADOS" << endl;
    cout << endl;
    int D1,D2,D3,D4,Turno1,Turno2,R1,R2;
    char S;
    int E=0;
    while (E==0){
        int R3=0;
        while (R3 == 0){
            cout << "TURNO: " << jugador1 << endl;
            cin >> S;
            if (S=='S' || S=='s'){
                cout <<endl;
                cout << "#TIRADA D1: " << (D1 = 1 + rand() % 6)<< endl;
                cout << "#TIRADA D2: " << (D2 = 1 + rand() % 6)<< endl;
                cout << endl;
                Turno1 = D1 + D2;
                R3=1;
            }
            else{
            cout << "INGRESASTE LETRA INVALIDA" << endl;
            }
         }
        R3=0;
        while (R3 == 0){
            cout << "TURNO: " << jugador2 << endl;
            cin >> S;
            if (S=='S'|| S=='s'){
                cout <<endl;
                cout << "#TIRADA D1: " << (D3= 1 + rand() % 6)<< endl;
                cout << "#TIRADA D2: " << (D4= 1 + rand() % 6)<< endl;
                Turno2 = D3 + D4;
                R3=1;
            }
            else{
                cout << "INGRESASTE LETRA INVALIDA" << endl;
            }
        }
        if (Turno1 == Turno2){
            if (D1 > D2){
                R1 = D1;
            }
            else {
                R1 = D2;
            }
            if (D3 > D4){
                R2 = D3;
            }
            else{
                R2 = D4;
            }
            if (R1 == R2){
                E = 0;
            }
            else {
                if (R1 > R2){
                    memcpy(primerJ, jugador1, strlen(jugador1)+1);
                    memcpy(segundoJ,jugador2, strlen(jugador2)+1);
                    cout << "GANADOR# " << primerJ << endl;
                    E = 1;
                }
                else {
                    memcpy(primerJ, jugador2, strlen(jugador2)+1);
                    memcpy(segundoJ, jugador1, strlen(jugador1)+1);
                    cout << "GANADOR# " << primerJ << endl;
                    E = 1;
                }

            }

        }
        else{
            if (Turno1 > Turno2){
                memcpy(primerJ, jugador1, strlen(jugador1)+1);
                memcpy(segundoJ,jugador2, strlen(jugador2)+1);
                cout << endl;
                cout << "GANADOR# " << primerJ << endl;
                E = 1;
            }
            else{
                memcpy(primerJ, jugador2, strlen(jugador2)+1);
                memcpy(segundoJ, jugador1, strlen(jugador1)+1);

                cout << "GANADOR# " << primerJ << endl;
                E = 1;
            }
        }
    }
}
/* Esta funcion procesa las condiciones de ganar o perder puntos del primer jugador, evaluando los dados que salieron y derterminando que hacer segun las reglas del juego*/
int RondaJugador1(char PrimerJ[],char SegundoJ[],int x,int Punto,int &DADO3,int D1,int D2,int D5,int &MaxPrimerJ,char S,int R,int &J, int &z,int &ConLanza,int &ConOinks){
                    while (S =='S' || S == 's'){
                        int A;
                        ConLanza++;
                        cout << endl;
                        cout <<"GRAN CERDO: "<< endl;
                        cout << "---------------------------------------------------------------------------------------------------------------" << endl;
                        cout << PrimerJ << ":" << J << "  " << "TRUFAS ACUMULADAS" << "  " << SegundoJ << ":" << z << "  " << "TRUFAS ACUMULADAS" << endl;
                        cout << endl;
                        cout << "TURNO DE " << PrimerJ << endl;
                        cout << "+-----------------------+" << endl;
                        cout << "| RONDAS # " << x <<"            |" << endl;
                        cout << "| TRUFAS DE LA RONDA:" << R << "  |" << endl;
                        cout << "| LANZAMIENTO: " << ConLanza << "       " << " |" << endl;
                        cout << "+-----------------------+" << endl;
                        cout << endl;
                        cout << "LANZAMIENTO #" << ConLanza << endl;
                        cout << endl;
                        if (J >= Punto && z >= Punto || DADO3 == 1 ){
                            cout << "#TIRADA D1: " << (D1 = 1 + rand() % 6)<< endl;
                            cout << "#TIRADA D2: " << (D2 = 1 + rand() % 6)<< endl;
                            cout << "#TIRADA D2: " << (D5 = 1 + rand() % 6)<< endl;
                            cout << endl;
                        if (D1 == 1 && D2 == 1 && D5 == 1){
                            z+= J;
                            J=0;
                            cout << " TE ACABAS DE HUNDIR EN EL BARRO, PIERDES TODAS LAS TRUFAS =(" << endl;
                            cout << " ES EL TURNO DEL SIGUIEN JUGADOR" << endl;
                            S = 'N';
                            }
                            else {
                                if (D1 == 1 || D2 == 1 || D5 == 1){
                                    A = 0;
                                    R = A;
                                    S = 'N';
                                    cout << " ACABAS DE SALTAR AL BARRO, PIERDES TODAS LAS TRUFAS DE ESTA RONDA =(" << endl;
                                    cout << " ES EL TURNO DEL SIGUIEN JUGADOR" << endl;
                                    }
                                    else{
                                        if (D1 != D2 && D1 != D5 && D2 != D5){
                                            A = D1 + D2 + D5;
                                            R+= A;
                                            cout << "TRUFAS ACUMULADAS: " << A << endl;
                                            cout << endl;
                                            int N=1;
                                            while(N==1){
                                                cout << "¿DESEA SEGUIR LANZANDO?  (S/N)" << endl;
                                                cin >> S ;
                                                if (S=='S' || S=='s'){
                                                    N=0;
                                                    }
                                                    else{
                                                        if (S=='N' || S=='n'){
                                                            N=0;
                                                        }
                                                        else{
                                                            cout << "INGRESO LETRA INVALIDA" << endl;
                                                        }
                                                    }

                                                }
                                            }
                                            else{
                                                    cout << endl;
                                                    A = D1 + D2 + D5;
                                                    R+= A;
                                                    int N=1;
                                                    while(N==1){
                                                        cout << "¿DESEA SEGUIR LANZANDO?  (S/N)" << endl;
                                                        cin >> S ;
                                                        if (S=='S' || S=='s'){
                                                            N=0;
                                                        }
                                                        else{
                                                            if (S=='N' || S=='n'){
                                                                N=0;
                                                            }
                                                            else{
                                                                cout << "INGRESO LETRA INVALIDA" << endl;
                                                            }
                                                        }

                                                    }

                                                }
                                        }
                                }
                        }
                        else{
                            cout << "#TIRADA D1: " << (D1 = 1 + rand() % 6)<< endl;
                            cout << "#TIRADA D2: " << (D2 = 1 + rand() % 6)<< endl;
                            cout << endl;
                        if (D1 == 1 && D2 == 1){
                            J=0;
                            DADO3 = 1;
                            cout << " TE ACABAS DE HUNDIR EN EL BARRO, PIERDES TODAS LAS TRUFAS =(" << endl;
                            cout << " ES EL TURNO DEL SIGUIEN JUGADOR" << endl;
                            S = 'N';
                            }
                            else {
                                if (D1 == 1 || D2 == 1){
                                    A = 0;
                                    R = A;
                                    S = 'N';
                                    cout << " ACABAS DE SALTAR AL BARRO, PIERDES TODAS LAS TRUFAS DE ESTA RONDA =(" << endl;
                                    cout << " ES EL TURNO DEL SIGUIEN JUGADOR" << endl;
                                    }
                                    else{
                                        if (D1 != D2 ){
                                            A = D1 + D2;
                                            R+= A;
                                            cout << "TRUFAS ACUMULADAS: " << A << endl;
                                            cout << endl;
                                            int N=1;
                                            while(N==1){
                                                cout << "¿DESEA SEGUIR LANZANDO?  (S/N)" << endl;
                                                cin >> S ;
                                                if (S=='S' || S=='s'){
                                                    N=0;
                                                    }
                                                    else{
                                                        if (S=='N' || S=='n'){
                                                            N=0;
                                                        }
                                                        else{
                                                            cout << "INGRESO LETRA INVALIDA" << endl;
                                                        }
                                                    }

                                                }
                                            }
                                            else{
                                                    cout << endl;
                                                    A = (D1 + D2) * 2;
                                                    cout << "oink: " << A;
                                                    R+= A;
                                                    ConOinks++;
                                                    cout << endl;

                                                }
                                        }
                                }
                        }

                        }
                        J+= R;
}
/* Esta funcion procesa las condiciones de ganar o perder puntos del segundo jugador, evaluando los dados que salieron y derterminando que hacer segun las reglas del juego */
int RondaJugador2(char PrimerJ[],char SegundoJ[],int x,int Punto,int &DADO3,int D3,int D4,int D5,int &MaxPrimerJ,char S,int P,int &J, int &z,int &ConLanza2,int &ConOinks2){
    while (S =='S' || S=='s'){
            int C;
                            ConLanza2++;
                            cout << endl;
                            cout <<"GRAN CERDO: "<< endl;
                            cout << "---------------------------------------------------------------------------------------------------------------" << endl;
                            cout << PrimerJ << ":" << J << "  " << "TRUFAS ACUMULADAS" << " " << SegundoJ << ":" << z << "  " << "TRUFAS ACUMULADAS" << endl;
                            cout << endl;
                            cout << "TURNO DE " << SegundoJ << endl;
                            cout << "+------------------------+" << endl;
                            cout << "| RONDAS # " << x << "             |" << endl;
                            cout << "| TRUFAS DE LA RONDA:" << P << "   |" << endl;
                            cout << "| LANZAMIENTO: " << ConLanza2 << "         |" << endl;
                            cout << "+------------------------+" << endl;
                            cout << endl;
                            cout << "LANZAMIENTO #"<< ConLanza2 << endl;
                            cout << endl;
                            if (J >= Punto && z >= Punto || DADO3 == 1){
                                cout << "#TIRADA D1: " << (D3 = 1 + rand() % 6)<< endl;
                                cout << "#TIRADA D2: " << (D4 = 1 + rand() % 6)<< endl;
                                cout << "#TIRADA D3: " << (D5 = 1 + rand() % 6)<< endl;
                                cout << endl;
                            if (D3 == 1 && D4 == 1 && D5 == 1){
                                J+= z;
                                z=0;
                                DADO3 = 1;
                                cout << " TE ACABAS DE HUNDIR EN EL BARRO, PIERDES TODAS LAS TRUFAS =(" << endl;
                                cout << " ES EL TURNO DEL SIGUIEN JUGADOR" << endl;
                                S = 'N';
                                }
                                else {
                                    if (D3 == 1 || D4 == 1 || D5 == 1){
                                        C = 0;
                                        P = C;
                                        S = 'N';
                                        cout << " ACABAS DE SALTAR AL BARRO, PIERDES TODAS LAS TRUFAS DE ESTA RONDA =(" << endl;
                                        cout << " ES EL TURNO DEL SIGUIEN JUGADOR" << endl;
                                        }
                                        else{
                                            if (D3 != D4 && D3 != D5 && D4 != D5){
                                                C = D3 + D4 + D5;
                                                P+= C;
                                                cout << "TRUFAS ACUMULADAS: " << C << endl;
                                                cout << endl;
                                                int N=1;
                                                while(N==1){
                                                    cout << "¿DESEA SEGUIR LANZANDO?  (S/N)" << endl;
                                                    cin >> S ;
                                                    if (S=='S' || S=='s'){
                                                        N=0;
                                                    }
                                                    else{
                                                        if (S=='N' || S=='n'){
                                                            N=0;
                                                        }
                                                        else{
                                                            cout << "INGRESO LETRA INVALIDA" << endl;
                                                        }
                                                    }

                                                }
                                                }
                                                else{
                                                        cout << endl;
                                                        C = D3 + D4 + D5;
                                                        P+= C;
                                                        cout << "TRUFAS ACUMULADAS: " << C << endl;
                                                        int N=1;
                                                        while(N==1){
                                                            cout << "¿DESEA SEGUIR LANZANDO?  (S/N)" << endl;
                                                            cin >> S ;
                                                            if (S=='S' || S=='s'){
                                                                N=0;
                                                            }
                                                            else{
                                                                if (S=='N' || S=='n'){
                                                                    N=0;
                                                                }
                                                                else{
                                                                    cout << "INGRESO LETRA INVALIDA" << endl;
                                                                }
                                                            }

                                                        }
                                                    }
                                            }
                                    }
                            }
                            else{
                                cout << "#TIRADA D1: " << (D3 = 1 + rand() % 6)<< endl;
                                cout << "#TIRADA D2: " << (D4 = 1 + rand() % 6)<< endl;
                                cout << endl;
                            if (D3 == 1 && D4 == 1){
                                z=0;
                                DADO3 = 1;
                                cout << " TE ACABAS DE HUNDIR EN EL BARRO, PIERDES TODAS LAS TRUFAS =(" << endl;
                                cout << " ES EL TURNO DEL SIGUIEN JUGADOR" << endl;
                                S = 'N';
                                }
                                else {
                                    if (D3 == 1 || D4 == 1){
                                        C = 0;
                                        P = C;
                                        S = 'N';
                                        cout << " ACABAS DE SALTAR AL BARRO, PIERDES TODAS LAS TRUFAS DE ESTA RONDA =(" << endl;
                                        cout << " ES EL TURNO DEL SIGUIEN JUGADOR" << endl;
                                        }
                                        else{
                                            if (D3 != D4){
                                                C = D3 + D4;
                                                P+= C;
                                                cout << "TRUFAS ACUMULADAS: " << C << endl;
                                                cout << endl;
                                                int N=1;
                                                while(N==1){
                                                    cout << "¿DESEA SEGUIR LANZANDO?  (S/N)" << endl;
                                                    cin >> S ;
                                                    if (S=='S' || S=='s'){
                                                        N=0;
                                                    }
                                                    else{
                                                        if (S=='N' || S=='n'){
                                                            N=0;
                                                        }
                                                        else{
                                                            cout << "INGRESO LETRA INVALIDA" << endl;
                                                        }
                                                    }

                                                }
                                                }
                                                else{
                                                    if (D3 == D4){
                                                        cout << endl;
                                                        C = (D3 + D4) * 2;
                                                        cout << "oink: " << C;
                                                        P+= C;
                                                        ConOinks2++;
                                                        cout << endl;
                                                        }
                                                    }
                                            }
                                    }
                            }

                           }
                            z+= P;
}
/*Esta funcion muestra los creditos, el nombre del equipo y sus integrantes*/
void Creditos(){
    cout << "NOMBRE DE EQUIPO: ALMOHADIT@S" << endl;
    cout << endl;
    cout << "Ortiz Morales Robielys Maria" << " Legajo: 26863" << endl;
    cout << "Martinez Leal Yorgenis Rafael" << " Legajo: 26822" << endl;
    cout << endl;
}
/*En esta  funcion se asigna el jugador quien haya tenido la maxima puntuacion del juego y lo muestra por pantalla,cuando selecciona la opcion estadistica */
void Estadistica(int Max_Campeon,int PuntosGanador,char GanadorDelJuego[],char Nombre_MaxGanador[]){
    cout << "ESTADISTICA" << endl;
    if (PuntosGanador > Max_Campeon){
        Max_Campeon = PuntosGanador;
        memcpy(Nombre_MaxGanador, GanadorDelJuego, strlen(GanadorDelJuego)+1);
        cout << endl;
        cout << "JUGADOR CON MAYOR PUNTOS DE VICTORIA: " << Nombre_MaxGanador << " CON " << Max_Campeon << " PUNTOS DE VICTORIA =)" << endl;
        cout << endl;
        }
        else{
            cout << endl;
            cout << "JUGADOR CON MAYOR PUNTOS DE VICTORIA: " << Nombre_MaxGanador << " CON " << Max_Campeon << " PUNTOS DE VICTORIA =)" << endl;
            cout << endl;
            }
}

