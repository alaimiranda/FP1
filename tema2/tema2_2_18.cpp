#include <iostream>
#include <iomanip>
using namespace std;

int main () {
  //Variables
	int operando1;
	char operador;
	int operando2;

	while (operando1 != 0) {
		cout << "Introduce una operación incluyendo el primero operando, el operador y el segundo operando separados por espacios: ";
		cin >> operando1;
		cin >> operador;
		cin >> operando2;

		if (operador == '+') {
			cout << operando1 << operador << operando2 << " = " << operando1 + operando2 << endl;
		} if (operador == '-') {
			cout << operando1 << operador << operando2 << " = " << operando1 - operando2 << endl;
		} if (operador == '*') {
			cout << operando1 << operador << operando2 << " = " << operando1 * operando2 << endl;
		} if (operador == '/') {
			cout << operando1 << operador << operando2 << " = " << operando1 / operando2 << endl;
		}
	}

	return 0;
}
