#include "Tupla.hpp"
#include<stdlib.h>
#include<time.h>
#include <iostream>
#include <fstream>
using namespace std;

void Tupla::randId() {
  srand(time(NULL));
  id = 1000+rand()%(10000-1000);
}

Tupla::Tupla() {
  randId();
}

void crearArchivo(ofstream &archivo, string name) {
  archivo.open(name + ".txt", ios::app);
  if(!archivo) {
    cout << "Aqui!!";
    archivo.open(name + ".txt", ios::trunc | ios::in);
    archivo.close();
    archivo.open(name + ".txt", ios::app);
  }
}

void Tupla::guardar(string name){
  ofstream archivo;
  crearArchivo(archivo, name);
  archivo << id << ";";
  for(int i = 0; i < objs.size(); i++) {
    archivo << objs[i] << ";";
  }
  archivo << endl;
  archivo.close();
}
