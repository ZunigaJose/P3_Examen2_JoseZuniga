#pragma once
#include <string>
#include <vector>
using namespace std;

class Tupla {
  private:
    int id;
  public:
    Tupla();
    vector<string> objs;
    void randId();
    int getId() {return id;}
    void setObj(string obj) {objs.push_back(obj);}
    void setId(int id) {this->id = id;}
    void guardar(string name);
};
