//Solución del enunciado + operador de control if y else

#include <iostream>
using namespace std;

int main () {
  //variables
  double examen;
  double actividades;
  double final;
  double nota;

  cout << "Introduce tu nota del examen: ";
  cin >> examen;
  cout << "Introduce tu nota de las prácticas: ";
  cin >> actividades;
  cout << "Introduce tu nota del examen final: ";
  cin >> final;

  nota = (examen*0.2)+(actividades*0.2)+(final*0.6);

  cout << "Tu media es: " << nota << endl;

  if (final >= 5 && actividades >= 5 ) {
    cout << "Aprobado" << endl;
  }
  else {
    cout << "Suspenso" << endl;
  }

  return 0;
}
