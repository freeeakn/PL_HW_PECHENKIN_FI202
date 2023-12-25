#include "decorator.h"

int main() {
  setlocale(LC_ALL, "ru");
  Hero *c = new Hero;
  c = new Helmet(c);
  c->getState();
  c = new Boots(c);
  c->getState();
  c = new Sword(c);
  c = new Chestplate(c);
  c->getState();
  return 0;
}