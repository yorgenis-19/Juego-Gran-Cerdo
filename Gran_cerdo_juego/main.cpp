#include<cstring>
#include<time.h>
#include<cstdlib>
#include<iostream>
using namespace std;

#include "Funciones.h"


int main(){
    int onoff;
    int  PuntosGanador = 0;
    int Max_Campeon = 0;
    char Nombre_MaxGanador[30];
    do{

        OpcionesMenu();

        cin >> onoff;
        cin.ignore();
        char GanadorDelJuego[30];
        switch (onoff){
            case 1:{
                srand(time(NULL));
                const int VecCantidad = 30;
                char Jugador1[VecCantidad];
                char Jugador2[VecCantidad];
                NombreJugadores(Jugador1, Jugador2, VecCantidad);

                char PrimerJ[VecCantidad];
                char SegundoJ[VecCantidad];
                SeleccionarPrimerJ(Jugador1, Jugador2, PrimerJ, SegundoJ);

                char S ='S';
                int MaxPrimerJ = 0, MaxSegundoJ = 0;
                int PriLan_CC = 0, SegLan_CC = 0;
                int ConOinks = 0, ConOiks2 = 0;
                int J = 0, z = 0, DADO3 = 0, PriJug_TrufasTotal = 0, SegJug_TrufasTotal = 0;
                char Ganador[30], Perdedor[30];
                const int Tam = 5, Punto = 50;
                for(int x=1; x<=Tam; x++){
                    int ConLanza = 0;
                    int R = 0;
                    int D1, D2, D3, D4, D5;

                    RondaJugador1(PrimerJ,SegundoJ,x,Punto,DADO3,D1,D2,D5,MaxPrimerJ,S,R,J,z,ConLanza,ConOinks);

                        if (ConLanza > MaxPrimerJ){
                            MaxPrimerJ = ConLanza;
                        }
                        int ConLanza2 = 0;
                        int P = 0;
                        if (x == 1){

                            RondaJugador2(PrimerJ,SegundoJ,x,Punto,DADO3,D3,D4,D5,MaxSegundoJ,S,P,J,z,ConLanza2,ConOiks2);
                        }
                        else{
                            int N=1;
                            while(N==1){
                                cout << SegundoJ << " ¿DESEAS LANZAR?  (S/N)" << endl;
                                cin >> S;
                                if (S=='S' || S=='s'){
                                    RondaJugador2(PrimerJ,SegundoJ,x,Punto,DADO3,D3,D4,D5,MaxSegundoJ,S,P,J,z,ConLanza2,ConOiks2);
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


                           if (ConLanza2 > MaxSegundoJ){
                            MaxSegundoJ = ConLanza2;
                           }
                           if (x < 5){
                                int E=1;
                                while(E==1){
                                    cout << PrimerJ <<" ¿DESEAS LANZAR?  (S/N)" << endl;
                                    cin >> S;
                                    if (S=='S' || S=='s' || S=='N' || S=='n'){
                                        E=0;
                                        }
                                        else{
                                            cout << "INGRESO LETRA INVALIDA" << endl;
                                            }
                                        }
                                    }
        }
        if (MaxPrimerJ > MaxSegundoJ){
                PriLan_CC = 3;
        }
        else{
            if (MaxSegundoJ > MaxPrimerJ){
                SegLan_CC = 3;
            }
            else{
                PriLan_CC = 3;
                SegLan_CC = 3;
            }
        }
        if (J > z){
                PriJug_TrufasTotal = 5;
        }
        else{
            if (z > J){
                SegJug_TrufasTotal = 5;
            }
            else {
                PriJug_TrufasTotal = 5;
                SegJug_TrufasTotal = 5;
            }
        }
        int prueba, prueba2;
            prueba = J / 50;
            prueba2 = z / 50;
        int PriJug_Oinks = ConOinks * 2, SegJug_Oinks = ConOiks2 * 2;
        int PriJug_TotalP = PriJug_TrufasTotal + prueba + PriJug_Oinks + PriLan_CC;
        int SegJug_TotalP = SegJug_TrufasTotal + prueba2 + SegJug_Oinks + SegLan_CC;
        cout << " GRAN CERDO" << endl;
        cout << "---------------------------------------------------------------------------------------------------------------" << endl;
        cout << " HITO" << "                 " << PrimerJ << "                    " << SegundoJ << endl;
        cout << " MAS TRUFAS EN TOTAL" << "  " << PriJug_TrufasTotal << " PDV  " << J << " TRUFAS " << "         " << SegJug_TrufasTotal << " PDV  " << z << " TRUFAS " << endl;
        cout << " CADA 50 TRUFAS" << "       " << prueba << " PDV  " << J << " TRUFAS " << "         " << prueba2 << " PDV  " << z << " TRUFAS " << endl;
        cout << " OINKS" << "                " << PriJug_Oinks << " PDV  " << ConOinks << "  OINKS " << "          " << SegJug_Oinks << " PDV  " << ConOiks2 << "  OINKS " << endl;
        cout << " CERDO CODICIOSO" << "      " << PriLan_CC << " PDV  " << MaxPrimerJ << "  LANZAMIENTOS" << "    " << SegLan_CC << " PDV  " << MaxSegundoJ << "  LANZAMIENTOS " << endl;
        cout << "---------------------------------------------------------------------------------------------------------------" << endl;
        cout << " TOTAL" << "                " << PriJug_TotalP << " PDV" << "                     " << SegJug_TotalP << " PDV" << endl;
        cout << endl;

        if (PriJug_TotalP > SegJug_TotalP){
            memcpy(GanadorDelJuego, PrimerJ, strlen(PrimerJ)+1);
            PuntosGanador = PriJug_TotalP;
            cout << " GANADOR: " << GanadorDelJuego << " CON " << PuntosGanador << " PUNTOS DE VICTORIA =)" << endl;
        }
        else{
            if (SegJug_TotalP > PriJug_TotalP){
                memcpy(GanadorDelJuego, SegundoJ, strlen(SegundoJ)+1);
                PuntosGanador = SegJug_TotalP;
                cout << " GANADOR: " << GanadorDelJuego << " CON " << PuntosGanador << " PUNTOS DE VICTORIA =)" << endl;
            }
            else{
                cout << "RESULTO EN EMPATE, GANAN LOS DOS JUGADORES" << endl;
            }
        }

    }
            break;
        case 2:{
            Estadistica(Max_Campeon,PuntosGanador,GanadorDelJuego,Nombre_MaxGanador);
            }
            break;
        case 3:{
            Creditos();
        }
            break;
        default :{
            if ( onoff != 0){
                cout << "OPCION ES INEXISTENTE, INTENTE NUEVAMENTE." << endl;
                cout << endl;
            }
        }
            break;
    }

}while(onoff != 0);

	return 0;
}

