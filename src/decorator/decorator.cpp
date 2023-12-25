#include "decorator.h"
int main() {
  Coffee *coffee = new Coffee();
  coffee = new Cream(coffee);
  coffee = new Sugar(coffee);
  coffee = new Cinnamon(coffee);

  std::cout << "Description: " << coffee->getDescription() << std::endl;
  std::cout << "Cost: $" << coffee->getCost() << std::endl;

  delete coffee;

  return 0;
}