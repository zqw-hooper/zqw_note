#include <iostream>
#include <list>

int main() {
  std::list<std::pair<int, char>> mylist;
  mylist.emplace_front(10, 'a');
  mylist.emplace_front(20, 'b');
  mylist.emplace_back(30, 'd');
  std::cout << "mylist contains : ";
  for (auto x : mylist) {
    std::cout << "\n" << x.first << ", " << x.second << std::endl;
  }
  return 0;
}