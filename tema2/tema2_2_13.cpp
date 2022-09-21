#include <iostream>
#include <string>
using namespace std;

int main () {
  //frases
  string f1;
  string f2;
  string f3;
  //longitud de las frases
  int l1;
  int l2;
  int l3;

  cout << "Introduce la primera cadena: ";
  cin >> f1;
  cout << "Introduce la segunda cadena: ";
  cin >> f2;
  cout << "Introduce la tercera cadena: ";
  cin >> f3;

  l1 = f1.size();
  l2 = f2.size();
  l3 = f3.size();

  if (l1 > l2) {
		if (l3 > l2) {
      if (l3 > l1) {
        cout << f2 << ", " << f1 << ", " << f3 << endl;

      } else {
        cout << f2 << ", " << f3 << ", " << f1 << endl;

      }

		} else {
      cout << f3 << ", " << f2 << ", " << f1 << endl;

		}
	} else {
		if (l3 > l1) {
      if (l3 > l2) {
        cout << f1 << ", " << f2 << ", " << f3 << endl;

      } else {
        cout << f1 << ", " << f3 << ", " << f2 << endl;

      }
		} else {
      cout << f3 << ", " << f1 << ", " << f2 << endl;

		}
	}

  return 0;
}
