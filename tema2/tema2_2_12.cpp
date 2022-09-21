#include <iostream>
using namespace std;

int main () {
  int n1;
  int n2;
  int n3;
  int mayor;
  int medio;
  int menor;

  cout << "Introduce el primer numero: ";
  cin >> n1;
  cout << "Introduce el segundo numero: ";
  cin >> n2;
  cout << "Introduce el tercer numero: ";
  cin >> n3;


  if (n1 > n2) {
		if (n3 > n2) {
      if (n3 > n1) {
        cout << n2 << ", " << n1 << ", " << n3 << endl;
      } else {
        cout << n2 << ", " << n3 << ", " << n1 << endl;
      }
		} else {
      cout << n3 << ", " << n2 << ", " << n1 << endl;
		}
	} else {
		if (n3 > n1) {
      if (n3 > n2) {
        cout << n1 << ", " << n2 << ", " << n3 << endl;
      } else {
        cout << n1 << ", " << n3 << ", " << n2 << endl;
      }
		} else {
      cout << n3 << ", " << n1 << ", " << n2 << endl;
		}
  }

  return 0;
}
