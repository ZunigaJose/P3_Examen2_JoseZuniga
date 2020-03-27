#pragma once
#include <string>
#include <vector>
#include "Tupla.hpp"
using namespace std;

class Relacion {
  private:
    string nombre;
  public:
    vector<string> encabezados;
    vector<Tupla> Tuplas;
    Relacion() {};
    Relacion(string);
    void setEncabezado(string encabezado) {encabezados.push_back(encabezado);}
    void setTupla(Tupla tupla) {Tuplas.push_back(tupla);}
    string getNombre() {return nombre;}
    void guardar();
};
