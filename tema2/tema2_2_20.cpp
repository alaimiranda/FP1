#include <iostream>
#include <string>
#include <iomanip> //manipular formato cout
using namespace std;

int main () {
	double precio;
	int unidades;
	char descuento;
	string nombre;
	string NIF;
	string direccion;
	string nombrep;
	double total;
	int tam = 70;

	cout << "Dame el precio del producto (double): ";
	cin >> precio;

	cout << "Dame el numero de unidades a comprar (int): ";
	cin >> unidades;

	cout << "¿Tienes derecho a descuento? (S/N): ";
	cin >> descuento;
	cin.ignore(40, '\n'); //cin.ignore hará que se obvie cualquier caracter tras la lectura de un char

	cout << "Dame tu nombre completo: ";
	getline (cin, nombre);

	cout << "Dame tu NIF: ";
	cin >> NIF;
	cin.ignore(40, '\n');

	cout << "Dame tu direccion: ";
	getline(cin, direccion);

	cout << "Nombre del producto: ";
	getline(cin, nombrep);

	total = unidades * precio;

  //Imprimimos la factura
	cout << endl << "Factura" << endl;

  //setw()<iomanip> establece una anchura para la línea
  //right colocará el texto a la derecha de la línea cuya anchura ha sido establecida
	cout << right << setw(tam) << nombre << endl;
	cout << right << setw(tam) << direccion << endl;
	cout << right << setw(tam) << NIF << endl;

	cout << "Producto: " << endl;
	cout << right << setw(tam) << nombrep << endl;

	cout << "Precio unitario: " << endl;
	cout << right << setw(tam) << precio << endl;

	cout << "Total: " << endl;
	cout << right << setw(tam) << total << endl;

	cout << "Descuento: " << endl;

	if ( descuento == 83 ) {
		cout << right << setw(tam) << total * 0.15 << endl;
		total = total - (total * 0.15);

		cout << "Total tras el descuento: " << endl;
		cout << right << setw(tam) << total << endl;

	} else {
		cout << right << setw(tam) << "Descuento no aplicable " << endl;
	}

	cout << "I.V.A. (21%)" << endl;
	cout << right << setw(tam) << total * 0.21 << endl;

	cout << "Precio final: " << endl;
	cout << right << setw(tam) << total + (total * 0.21) << endl;

	return 0;
}
