//Práctica Alai Blanco y Rocío Uñón - 1A
#include <iostream>
#include <cstdlib> //Para números aleatorios
#include <cmath> //Para el valor absoluto

//Revisar nombres variables

using namespace std;

//CONSTANTES

const int N_CASILLAS = 63;

//Puentes
const int  C_PUENTE_1 = 6;
const int  C_PUENTE_2 = 12;

//Dados
const int  C_DADOS_1 = 26;
const int  C_DADOS_2 = 53;

//Penalizaciones
const int  C_POSADA = 19;
const int  TURNOS_POSADA = 1;

const int  C_PRISION = 52;
const int  TURNOS_PRISION = 2;

const int  C_POZO = 31;
const int  TURNOS_POZO = 3;

const int  C_LABERINTO = 42;

const int  C_MUERTE = 58;

//MODO DEBUG -> permite controlar el modo de juego
const bool MODO_DEBUG = true;


//FUNCIONES

//Comprueban si la casilla es especial
bool esOca(int casilla);
bool esPuente(int casillapuente);
bool esDados(int casillaDados);
bool esPosada(int casillaPosada);
bool esPrision(int casillaPrision);
bool esPozo(int casillaPozo);
bool esLaberinto(int casillaLaberinto);
bool esMuerte(int casillaMuerte);

//Ejecutan la consecuencia de cada casilla especial
int siguienteOca(int posicionOca);
int siguientePuente(int posicionPuente);
int siguienteDado(int posicionDado);
int siguienteLab(int posicionLab);
int siguienteMuerte(int posicionMuerte);

//Funciones basicas del juego
int tirarDadoAleatorio();
int tirarDadoManual();
int quienEmpieza();
int efectoPosicion(int casillaActual);
int efectoTiradas(int casillaActual, int numeroDeTiradas);

//Comprueba si algun jugador ha ganado
bool esMeta(int casillaActualM);


//FUNCION PRINCIPAL DEL JUEGO (MAIN)
int main()
{
	srand(time(NULL));//Invocamos los números aleatorios

	int casillaJ1 = 1;
	int casillaJ2 = 1;
	int turno;
	int numeroDeTiradas = 1;
	int casillaActual = 1;
	int dado;

	cout << "Bienvenidos a la oca, presiona enter para empezar, suerte!!";
	cin.get();  //Pausa el programa

	turno = quienEmpieza();
	cout << "El afortunado que empieza es el jugador " << turno;
	cin.get();

	//while "externo" que ejecuta el juego mientras no haya ganador
	while (!esMeta(casillaActual)) {

		cout << endl << "TURNO JUGADOR " << turno << ": " << endl;

		cout << "Estas en la casilla " << casillaActual << endl;

		//while "interno" que ejecuta el turno de cada jugador
		while (numeroDeTiradas > 0 && !esMeta(casillaActual)) {

			//Lanzamos dado y definimos modo de partida
			if (MODO_DEBUG == true) {
				dado = tirarDadoManual();
			}
			else {
				if (MODO_DEBUG == false) {
					dado = tirarDadoAleatorio();
				}
			}
			cout << "Valor del dado: " << dado << endl;

			numeroDeTiradas = numeroDeTiradas - 1;

			casillaActual = casillaActual + dado;
			cout << "Pasas a la casilla " << casillaActual << endl;

			casillaActual = efectoPosicion(casillaActual); //Comprueba si es una casilla especial
			numeroDeTiradas = efectoTiradas(casillaActual, numeroDeTiradas); //Define las tiradas que tienes

			if (!esMeta(casillaActual)) { //Queremos que una vez hayamos ganado, no pause el programa y automaticamente nos diga que hemos ganado
				cin.get();
			}
		}

		numeroDeTiradas = abs(numeroDeTiradas) + 1; //Actualiza el numero de tiradas para cambiar de turno

		//Cambiamos turnos
		if (!esMeta(casillaActual)) {
			if (turno == 1) {
				casillaJ1 = casillaActual;
				turno = 2;
				casillaActual = casillaJ2;
			}
			else {
				casillaJ2 = casillaActual;
				turno = 1;
				casillaActual = casillaJ1;

			}
		}
	}

	cout << "Enhorabuena, jugador " << turno << " has ganado!" << endl;
	return 0;
}


//FUNCIONES COMPROBACION CASILLAS

bool esOca(int casillaoca)
{
	bool oca = false;
	if ((casillaoca % 9) == 0 || (casillaoca % 9) == 5) {
		oca = true;
	}

	return oca;
}

bool esPuente(int casillapuente)
{
	bool puente = false;

	if (casillapuente == C_PUENTE_1 || casillapuente == C_PUENTE_2)
	{
		puente = true;
	}

	return puente;
}

bool esDados(int casillaDados)
{
	bool dados = false;

	if (casillaDados == C_DADOS_1 || casillaDados == C_DADOS_2)
	{
		dados = true;
	}

	return dados;
}

bool esPosada(int casillaPosada)
{
	bool posada = false;

	if (casillaPosada == C_POSADA)
	{
		posada = true;
	}

	return posada;
}

bool esPrision(int casillaPrision)
{
	bool prision = false;

	if (casillaPrision == C_PRISION)
	{
		prision = true;
	}

	return prision;
}
bool esPozo(int casillaPozo)
{
	bool pozo = false;

	if (casillaPozo == C_POZO)
	{
		pozo = true;
	}

	return pozo;
}
bool esLaberinto(int casillaLaberinto)
{
	bool laberinto = false;

	if (casillaLaberinto == C_LABERINTO)
	{
		laberinto = true;
	}

	return laberinto;
}
bool esMuerte(int casillaMuerte)
{
	bool muerte = false;

	if (casillaMuerte == C_MUERTE)
	{
		muerte = true;
	}

	return muerte;
}


// FUNCIONES SALTOS

int siguienteOca(int posicionOca)
{
	int nuevaPosicionO = 0;

	if ((posicionOca % 9) == 0) {
		nuevaPosicionO = posicionOca + 5;
	}
	if ((posicionOca % 9) != 0) {
		nuevaPosicionO = posicionOca + 4;
	}

	return nuevaPosicionO;
}

int siguientePuente(int posicionPuente)
{
	int nuevaPosicionP = 0;

	if (posicionPuente == C_PUENTE_1) {
		nuevaPosicionP = C_PUENTE_2;
	}
	if (posicionPuente == C_PUENTE_2) {
		nuevaPosicionP = C_PUENTE_1;
	}

	return nuevaPosicionP;
}

int siguienteDado(int posicionDado)
{
	int nuevaPosicionD = 0;

	if (posicionDado == C_DADOS_1) {
		nuevaPosicionD = C_DADOS_2;
	}
	if (posicionDado == C_DADOS_2) {
		nuevaPosicionD = C_DADOS_1;
	}

	return nuevaPosicionD;
}

int siguienteLab(int posicionLab)
{
	int nuevaPosicionL = posicionLab - 12;

	return nuevaPosicionL;
}

int siguienteMuerte(int posicionMuerte)
{
	int nuevaPosicionM = 1;

	return nuevaPosicionM;
}


//FUNCIONES QUE REGULAN EL JUEGO

int tirarDadoAleatorio() {

	int nDado;

	nDado = 1 + rand() % (7 - 1);
	//Saldrá un número aleatorio entre el 1 y el 6

	return nDado;

}

//MODO DEBUG

int tirarDadoManual() {
	int dadoManual;

	cout << "Introduce el valor del dado ";
	cin >> dadoManual;

	return dadoManual;
}

int quienEmpieza() {

	int empieza;

	empieza = 1 + rand() % (3 - 1);

	return empieza;
}

int efectoPosicion(int casillaActual) {
	int casillaNueva = casillaActual;

	if (esOca(casillaActual) == true) {
		if (casillaActual == N_CASILLAS) {
			casillaNueva = casillaActual;
		}
		else {
			casillaNueva = siguienteOca(casillaActual);
			cout << "De oca en oca y tiro porque me toca" << endl;
			cout << "Pasas a la casilla " << casillaNueva << endl;
		}
	}
	else {
		if (esPuente(casillaActual) == true) {
			casillaNueva = siguientePuente(casillaActual);
			cout << "De puente a puente y porque me lleva la corriente" << endl;
			cout << "Pasas a la casilla " << casillaNueva << endl;
		}
		else {
			if (esDados(casillaActual) == true) {
				casillaNueva = siguienteDado(casillaActual);
				cout << "De dado a dado y tiro porque me ha tocado" << endl;
				cout << "Pasas a la casilla " << casillaNueva << endl;
			}
			else {
				if (esPosada(casillaActual) == true) {
					casillaNueva = casillaActual;
					cout << "Oh no! Has caido en la posada, pierdes un turno" << endl;
				}
				else {
					if (esPrision(casillaActual) == true) {
						casillaNueva = casillaActual;
						cout << "Has caido en la prision delincuente, pierdes dos turnos" << endl;
					}
					else {
						if (esPozo(casillaActual) == true) {
							casillaNueva = casillaActual;
							cout << "Que mala suerte! Has caido en el pozo, pierdes tres turnos" << endl;
						}
						else {
							if (esMuerte(casillaActual) == true) {
								casillaNueva = siguienteMuerte(casillaActual);
								cout << "De oca a oca... ES BROMA ;)" << endl;
								cout << "Has caido en la muerte, vuelve a la casilla 1, no te desanimes que tienes mas tiempo jugando a esta maravilla" << endl;
							}
							else {
								if (esLaberinto(casillaActual) == true) {
									casillaNueva = siguienteLab(casillaActual);
									cout << "Lo siento, te has perdido en el laberinto, retrocede 12 casillas" << endl;
									cout << "Pasas a la casilla " << casillaNueva << endl;
								}
							}
						}
					}
				}

			}
		}
	}
	return casillaNueva;
}

int efectoTiradas(int casillaActual, int numeroDeTiradas) {

	int nuevasTiradas = numeroDeTiradas;

	if (esOca(casillaActual) || esDados(casillaActual) || esPuente(casillaActual)) {
		if (casillaActual != N_CASILLAS) {
			nuevasTiradas = numeroDeTiradas + 1;
			cout << "Vuelves a tirar!" << endl;
		}
	}
	else {
		if (esPosada(casillaActual) == true) {
			nuevasTiradas = numeroDeTiradas - 1;
		}
		else {
			if (esPrision(casillaActual) == true) {
				nuevasTiradas = numeroDeTiradas - 2;
			}
			else {
				if (esPozo(casillaActual) == true) {
					nuevasTiradas = numeroDeTiradas - 3;
				}
			}
		}
	}


	return nuevasTiradas;
}

//Comprueba si hay ganador
bool esMeta(int casillaActualM) {

	bool ganador = false;

	if (casillaActualM >= N_CASILLAS) {
		ganador = true;
	}

	return ganador;
}
