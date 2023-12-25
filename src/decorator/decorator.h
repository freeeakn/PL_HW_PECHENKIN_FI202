#ifndef DECORATOR_H
#define DECORATOR_H
#include <iostream>
#include <string>

class Coffee {
protected:
  std::string description;
  double cost;

public:
  Coffee() : description("Coffee"), cost(1.0) {}

  virtual std::string getDescription() { return description; }
  virtual double getCost() { return cost; }
};

class Cream : public Coffee {
protected:
  Coffee *coffee;

public:
  Cream(Coffee *c) {
    this->coffee = c;
    this->description = coffee->getDescription() + ", Cream";
    this->cost = coffee->getCost() + 0.5;
  }

  std::string getDescription() { return description; }
  double getCost() { return cost; }
};

class Sugar : public Coffee {
protected:
  Coffee *coffee;

public:
  Sugar(Coffee *c) {
    this->coffee = c;
    this->description = coffee->getDescription() + ", Sugar";
    this->cost = coffee->getCost() + 0.3;
  }

  std::string getDescription() { return description; }
  double getCost() { return cost; }
};

class Cinnamon : public Coffee {
protected:
  Coffee *coffee;

public:
  Cinnamon(Coffee *c) {
    this->coffee = c;
    this->description = coffee->getDescription() + ", Cinnamon";
    this->cost = coffee->getCost() + 0.2;
  }

  std::string getDescription() { return description; }
  double getCost() { return cost; }
};
#endif //DECORATOR_H
