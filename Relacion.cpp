#include "Relacion.hpp"
#include <iostream>
#include <fstream>
using namespace std;

Relacion::Relacion(string Nombre) {
  nombre = Nombre;
}
void Relacion::guardar() {
  fstream archivo;
  archivo.open("Relaciones.txt", ios::app);
  archivo << nombre << ";" << "ID" << ";";
  for(int i = 0; i < encabezados.size(); i++) {
    archivo << encabezados[i] << ";";
  }
  archivo << endl;
  archivo.close();
}
