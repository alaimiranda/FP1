#include <iostream>
using namespace std;

//funciones
bool is_num(char c);
bool is_may(char c);
bool is_min(char c);


int main() {
  char c;
  cout << "Introduce un caracter: ";
  cin >> c;

  if (is_num(c) || is_may(c) || is_min(c)) {
    if (is_num(c)){
      cout << "El caracter " << c << " es un número." << endl;
    } else if (is_may(c)) {
      cout << "El caracter " << c << " es una letra mayúscula." << endl;
    } else if (is_min(c)) {
      cout << "El caracter " << c << " es una letra minúscula." << endl;
    }
  } else {
    cout << "El caracter " << c << " no es alfanumerico." << endl;
  }


}

//funciones
bool is_num(char c) {
  if (c > 47 && c < 58) {
    return true;
  } else return false;
}

bool is_may(char c) {
  if (c > 64 && c < 91) {
    return true;
  } else return false;
}

bool is_min(char c) {
  if (c > 96 && c < 123) {
    return true;
  } else return false;
}
