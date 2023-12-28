#ifndef DECORATOR_H
#define DECORATOR_H
#include <iostream>
#include <string>

class Tea {
protected:
  int strength, bitterness, temperature;

public:
  Tea() : strength(100), bitterness(50), temperature(80) {}

  virtual int getStrength() { return strength; }
  virtual int getBitterness() { return bitterness; }
  virtual int getTemperature() { return temperature; }

  void getState() {
    std::cout << "\033[91m################\033[0m" << std::endl
              << "Strength: " << (this->getStrength()) << std::endl
              << "Bitterness: " << this->getBitterness() << std::endl
              << "Temperature: " << this->getTemperature() << std::endl
              << "\033[91m################\033[0m" << std::endl;
  }
};

class Milk : public Tea {
protected:
  Tea *tea;

public:
  Milk(Tea *t) {
    tea = t;
    strength -= 20;
    bitterness -= 10;
  }

  int getStrength() { return strength + tea->getStrength(); }
  int getBitterness() { return bitterness + tea->getBitterness(); }
  int getTemperature() { return tea->getTemperature(); }
};

class Sugar : public Tea {
protected:
  Tea *tea;

public:
  Sugar(Tea *t) {
    tea = t;
    bitterness -= 20;
  }

  int getStrength() { return tea->getStrength(); }
  int getBitterness() { return bitterness + tea->getBitterness(); }
  int getTemperature() { return tea->getTemperature(); }
};

class Syrup : public Tea {
protected:
  Tea *tea;
  int flavor;

public:
  Syrup(Tea *t, int f) : tea(t), flavor(f) {}

  int getStrength() { return tea->getStrength(); }
  int getBitterness() { return tea->getBitterness(); }
  int getTemperature() { return tea->getTemperature(); }
};
#endif // DECORATOR_H