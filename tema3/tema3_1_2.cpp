#include <iostream>
using namespace std;

typedef enum{ noPresentado, suspenso, aprobado, notable, sobresaliente, matriculaDeHonor } tCalificacion;
string cadCalif(tCalificacion calif);
tCalificacion notaToCalif(double nota);


int main() {
  double nota1;
  double nota2;
  tCalificacion calif1;
  tCalificacion calif2;

  cout << "Introduce la primera nota: ";
  cin >> nota1;
  cout << "Introduce la segunda nota: ";
  cin >> nota2;

  calif1 = notaToCalif(nota1);
  calif2 = notaToCalif(nota2);

  cout << "La primera nota " << nota1 << " es " << cadCalif(calif1) << endl;
  cout << "La segunda nota " << nota2 << " es " << cadCalif(calif2) << endl;

}

tCalificacion notaToCalif(double nota) {
  tCalificacion calif;
  if (nota == 0) {
    calif = noPresentado;
  } else {
    if (nota < 5){
      calif = suspenso;
    } else {
      if (nota < 7) {
        calif = aprobado;
      } else {
        if (nota < 9) {
          calif = notable;
        } else {
          if (nota < 10) {
            calif = sobresaliente;
          } else {
            if (nota >= 10) {
              calif = matriculaDeHonor;
            }
          }
        }
      }
    }
  }
  return calif;
}

string cadCalif(tCalificacion calif) {
  string cad;
  switch (calif) {
    case 0: {
      cad = "No Presentado";
    }
    break;
    case 1: {
      cad = "Suspenso";
    }
    break;
    case 2: {
      cad = "Aprobado";
    }
    break;
    case 3: {
      cad = "Notable";
    }
    break;
    case 4: {
      cad = "Sobresaliente";
    }
    break;
    case 5: {
      cad = "Matricula de honor";
    }
    break;
  }
  return cad;

}
