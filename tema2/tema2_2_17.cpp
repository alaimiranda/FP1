#include <iostream>
#include <iomanip>
using namespace std;

int main () {
  //Variables
	int operando1 = 1;
	int operando2 = 0;

	while (1 > operando2 or operando2 > 100) {
		cout << "Introduce un numero: ";
		cin >> operando2;
	}

	while (operando1 < 11) {
		cout << right << setw(2) << operando1 << setw(2) << "x" << setw(4) << operando2 << setw(2) << "=" << setw(5) << operando1 * operando2 << endl;
		operando1 = operando1 + 1;
	}

	return 0;
}
