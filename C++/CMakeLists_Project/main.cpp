#include <iostream>
#include <memory>
#include <stdio.h>

std::shared_ptr<int> a = std::make_shared<int>();

void test(int &_in) {
  a = std::make_shared<int>(_in);
  printf("*a %d\n", *a);
}

int main() {

  int b = 49;
  test(b);
  return 0;
}