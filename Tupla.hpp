#pragma once
#include <string>
#include <vector>
using namespace std;

class Tupla {
  private:
    int id;
    vector<string> objs;
  public:
    Tupla(){};
    void randId();
    int getId() {return id;}
    void setObj(string obj) {objs.push_back(obj);}
    void setId(int id) {this->id = id;}
};
