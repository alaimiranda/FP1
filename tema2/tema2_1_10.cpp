#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

int main () {
  //variables
  int x;
  int y;
  double solucion;
  double pi = 3.141592;
  double e = 2.71828;
  double n = 1.531;

  cout << "Introduzca x: ";
  cin >> x;
  cout << "Introduzca y: ";
  cin >> y;

  solucion = sqrt(pow(n, (x + y))+(((abs(pow(e, x)-pow(e, y)))*(sin(x)-tan(y)))/(log10(y)*pow(pi, x))));

  cout << solucion << endl;

  return 0;

}

// raíz -> sqrt() <cmath>
// potencia -> pow() <math.h>
//valor absoluto -> abs() <cmath>
// seno y tangente -> sin()/tan() <cmath> 
