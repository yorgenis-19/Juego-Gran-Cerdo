#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void OpcionesMenu();

char NombreJugadores(char jugador1[], char jugador2[], int VCantidad);

char SeleccionarPrimerJ(char jugador1[], char jugador2[], char primerJ[], char segundoJ[]);

int RondaJugador1(char PrimerJ[],char SegundoJ[],int x,int Punto,int &DADO3,int D1,int D2,int D5,int &MaxPrimerJ,char S,int R,int &J, int &z,int &ConLanza,int &ConOinks);

int RondaJugador2(char PrimerJ[],char SegundoJ[],int x,int Punto,int &DADO3,int D1,int D2,int D5,int &MaxPrimerJ,char S,int P,int &J, int &z,int &ConLanza2,int &ConOinks2);

void Creditos();

void Estadistica(int Max_Campeon,int PuntosGanador,char GanadorDelJuego[],char Nombre_MaxGanador[]);

#endif // FUNCIONES_H_INCLUDED
