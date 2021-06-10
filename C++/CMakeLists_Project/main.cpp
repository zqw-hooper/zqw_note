#include <bits/stdc++.h>
#include <cfloat>
#include <float.h>
#include <iostream>
#include <memory>
#include <stdio.h>

std::shared_ptr<int> a = std::make_shared<int>();

void test(int &_in) {
  a = std::make_shared<int>(_in);
  printf("*a %d\n", *a);
}

int main() {

  // double a = DBL_MAX;
  // float b = static_cast<float>(a);
  float b = FLT_MAX;
  if (std::isfinite(b)) {
    std::cout << "b  = " << b << std::endl;
  } else {
    std::cout << "b is inf " << std::endl;
    b = FLT_MAX;
    std::cout << "set b = " << b << std::endl;
  }

  // Printing the two variables
  // std::cout << "isfinite(b)  = " << std::isfinite(b) << std::endl;
  // std::cout << "isfinite(c)  = " << std::isfinite(c) << std::endl;

  return 0;
}