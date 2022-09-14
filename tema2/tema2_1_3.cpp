//Este programa pasa de grados Fahrenheit a Celsius
#include <iostream>
using namespace std;

int main () {
  double g_f = 0.0 ; //Grados en Fahrenheit
  cout << "Introduzca valor en grados Fahrenheit: ";
  cin >> g_f ;
  double g_c = ((g_f - 32)*5)/9; // Grados en Celsius
  cout << "EL valor introducido en grados Celsius equivale a " << g_c << endl;
  return 0;
}
