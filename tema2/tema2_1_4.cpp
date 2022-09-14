//Enunciado: Escribe un programa que lea del teclado un tiempo transcurrido en
//segundos y muestre en la pantalla las horas, los minutos y los segundos equivalentes.
//Este ejercicio se puede interpretar de 2 maneras.
#include <iostream>
using namespace std;

int main () {
  double seg = 0.0;
  double min = 0.0;
  double hor = 0.0;
  cout << "Introduzca un valor en segundos: ";
  cin >> seg;
  // 1
  cout << "Equivale a " << double(seg/60) << " minutos o " << double(seg/3600) << " horas." << endl;


}
