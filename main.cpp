#include "Relacion.hpp"
#include "Tupla.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

vector<Relacion> relaciones;

int getNumValues(string linea) {
  int vals = 0;
  for(int i = 0; i < linea.size(); i++){
    if(linea.at(i) == ';'){
      vals++;
    }
  }
  return vals;
}

void cargarRelaciones(fstream &archivo) {
  string linea;
  while(getline(archivo, linea)) {
    int n = 0;
    int num = getNumValues(linea);
    string token[num];
    for (int i = 0; i < linea.size(); i++) {
      if (linea.at(i) == ';') {
        n++;
      } else if(linea.at(i)) {
        token[n] = token[n] + linea.at(i);
      }
    }
    relaciones.push_back(Relacion(token[0]));
    for (int i = 1; i < num; i++) {
      relaciones[relaciones.size() - 1].setEncabezado(token[i]);
    }
  }
}

int menu() {
  int op;
  cout << "\n0. Salir\n1. Crear Relacion\n2. Ver Relaciones\n3. Insertar Tupla: ";
  cin >> op;
  if(op < 0 || op > 3) {
    cout << "Ingreso Invalido!!\n";
    return menu();
  }
  return op;
}

void listarRelaciones() {

}

int main() {
  fstream Relaciones;
  Relaciones.open("Relaciones.txt", ios::in | ios::out);
  cargarRelaciones(Relaciones);
  cout << relaciones[0].getNombre();
  return 0;
}
