#include "decorator.h"

int main() {
  // Создаем базовый чай
  Tea* tea = new Tea();
  tea->getState();

  // Декорируем чай молоком
  Tea* teaWithMilk = new Milk(tea);
  teaWithMilk->getState();

  // Декорируем чай сахаром
  Tea* teaWithMilkAndSugar = new Sugar(teaWithMilk);
  teaWithMilkAndSugar->getState();

  // Декорируем чай сиропом
  Tea* teaWithMilkSugarAndSyrup = new Syrup(teaWithMilkAndSugar, 2);
  teaWithMilkSugarAndSyrup->getState();

  return 0;
}