//Este programa halla el volumen de un como de 26.79 de altura y radio de la base 14.5
#include <iostream>
using namespace std;

int main () {
  double radio = 14.5;
  double altura = 26.79;
  double pi = 3.141592;
  double volumen = (pi*radio*radio*altura)/3;
  cout << "El volumen es " << volumen << endl;
  return 0;
}
