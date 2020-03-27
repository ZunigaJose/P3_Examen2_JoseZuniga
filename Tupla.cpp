#include "Tupla.hpp"
#include<stdlib.h>
#include<time.h>
using namespace std;

void Tupla::randId() {
  srand(time(NULL));
  id = 1000+rand()%(10000-1000);
}
