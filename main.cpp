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

void listarRelaciones();

void crearArc(fstream &archivo, string name) {
  archivo.open(name + ".txt", ios::in);
  if(!archivo) {
    cout << "Aqui!!";
    archivo.open(name + ".txt", ios::trunc | ios::in);
    archivo.close();
    archivo.open(name + ".txt", ios::in);
  }
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

int seleccionarRelacion() {
  listarRelaciones();
  int op;
  cout << "Ingrese su opcion: ";
  cin >> op;
    while(op < 0 || op > relaciones.size() - 1){
      cout << "Valor invalido!\nVuelva a intentar: ";
      cin >> op;
    }
    return op;
}

void nuevaTupla() {
  int pos = seleccionarRelacion();
  vector<string> entries;
  string entry;
  for (int i = 1; i < relaciones[pos].encabezados.size(); i++) {
    cout << "Ingrese el valor de " << relaciones[pos].encabezados[i] << ": ";
    cin >> entry;
    entries.push_back(entry);
  }
  Tupla tupla;
  tupla.objs = entries;
  tupla.guardar(relaciones[pos].getNombre());
}

void escribirTuplas() {
  fstream archivo;
  for (int i = 0; i < relaciones.size(); i++) {
    crearArc(archivo, relaciones[i].getNombre());
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
  for (int i = 0; i < relaciones.size(); i++) {
    cout << i << " " << relaciones[i].getNombre() << endl;
  }
}

int menuContinue() {
  int op;
  cout << "Presione 0 para salir / Cualquier tecla para continuar: ";
  cin >> op;
  return op;
}

void crearRelacion() {
  string nombre;
  cout << "Ingrese el nombre de la Relacion: ";
  cin >> nombre;
  Relacion rela(nombre);
  relaciones.push_back(rela);
  int nEnca = 1;
  string enca;
  do {
    cout << "Ingrese el encabezado " << nEnca << " : ";
    cin >> enca;
    relaciones[relaciones.size() - 1].setEncabezado(enca);
    nEnca++;
  } while(menuContinue());
  relaciones[relaciones.size() - 1].guardar();
}

int main() {
  fstream Relaciones;
  Relaciones.open("Relaciones.txt", ios::in);
  cargarRelaciones(Relaciones);
  //crearRelacion();
  nuevaTupla();
  //cargarTuplas();
  return 0;
}
