//Librerias
#include <iostream>
#include <string>
#include <iomanip> //Manipular cout
#include <fstream>
#include <time.h>
#include <cstdlib>

using namespace std;

//Constantes
const int MAX_JUGUETES = 10;
const int MAX_PEDIDOS = 3;
const int MAX_CARTAS = 10;

//Estructuras
typedef struct {
  string nombre;
  double peso;
  int cantidad;
} tjuguete;

typedef tjuguete tJuguetes[MAX_JUGUETES];

typedef struct {
  int contador;
  tJuguetes lista;
}tListaJuguetes;

typedef string tListaPedidos[MAX_PEDIDOS];

typedef struct {
  string nombre;
  string ciudad;
  tListaPedidos listaPedidos;
  bool preparado;
  bool pendiente;
} tcarta;

typedef tcarta tlistaCartas[MAX_CARTAS];

typedef struct {
  int contador;
  tlistaCartas lista;
} tListaCartas;

//Funciones
bool cargarJuguetes(tListaJuguetes& lista);
bool cargarCartas(tListaCartas& l);
int buscarJuguete(tListaJuguetes l, string nombrebuscado);
void listarJuguetes(tListaJuguetes lista);



int main() {
  srand(time(NULL));
  tListaJuguetes listaJ;
  tListaCartas listaC;

  cargarJuguetes(listaJ);
  cargarCartas(listaC);
  listarJuguetes(listaJ);
  cout << buscarJuguete(listaJ, "w") << endl;

  return 0;
}

//Funciones

//Procesos de carga de archivos
bool cargarJuguetes(tListaJuguetes& l) {
  ifstream archivo;
  int i = 0;
  bool ok = true;
  string nombreJ;
  l.contador = 0;
  archivo.open("juguetes.txt");
  if (archivo.is_open()){
    archivo >> nombreJ;
    while(i < MAX_JUGUETES && nombreJ != "XXX"){
      l.lista[i].nombre = nombreJ;
      archivo >> l.lista[i].peso >> l.lista[i].cantidad;
      archivo >> nombreJ;
      i++;
    }
    l.contador = i;

    archivo.close();
  } else {
    cout << "Error en la lectura del archivo de inventario de juguetes." << endl;
    ok = false;
  }
  return ok;
}

bool cargarCartas(tListaCartas& l) {
  ifstream archivo;
  string nombreN;
  bool ok = true;
  l.contador = 0;
  archivo.open("cartas.txt");
  if (archivo.is_open()){
    archivo >> nombreN;
    while(l.contador < MAX_JUGUETES && nombreN != "XXX"){
      l.lista[l.contador].nombre = nombreN;
      archivo >> l.lista[l.contador].ciudad;
      for (int j = 0; j < MAX_PEDIDOS; j++){
        archivo >> l.lista[l.contador].listaPedidos[j];
      }
      l.lista[l.contador].preparado = false;
      l.lista[l.contador].pendiente = false;
      archivo >> nombreN;
      l.contador++;
    }
    archivo.close();
  } else {
    ok = false;
    cout << "Error en la lectura del archivo de cartas." << endl;
  }
  return ok;
}

int buscarJuguete(tListaJuguetes l, string nombrebuscado){
  int pos = 0;
  while (l.lista[pos].nombre != nombrebuscado && pos < l.contador){
    pos++;
  }
  return pos;
}

//void trineoDestino (string ciudad, tListaCartas listaC, tListaJuguetes listaJ) {
//  if (){
//  }
//}

void listarJuguetes(tListaJuguetes l){
  cout << "Listado de los juguetes que hay en la fábrica: " << endl;
  cout << setw(15) << left << "Nombre" << setw(15) << left << "Peso" << setw(15) << left << "Cant." << endl;
  for(int i = 0; i < l.contador; i++){
    cout << setw(15) << left << l.lista[i].nombre << setw(15) << left << l.lista[i].peso << setw(15) << left << l.lista[i].cantidad << endl;
  }
}
