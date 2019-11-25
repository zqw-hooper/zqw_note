#include <iostream>
#include <array>

int main() 
{
  std::array<int, 10> myarray;
  for (int i = 0; i < myarray.size(); i++) 
	{
    myarray.at(i) = i + 1;
  }

	std::cout << "the array max size is :" << myarray.max_size() << std::endl;
	std::cout << "the front element is :" << myarray.front() << std::endl;
	std::cout << "the last element is :" << myarray.back() << std::endl;

	std::cout << "myarray contains iterator is :";
  for (auto it = myarray.begin();it!=myarray.end();++it) {
    std::cout << "\n" <<"iterate is :" << *it << std::endl;
  }

	std::cout << "myarray contains const iterator is :";
  for (auto it = myarray.cbegin();it!=myarray.cend();++it) {
    std::cout << "\n" <<"iterate is :" << *it << std::endl;
  }

  std::cout << "myarray contains reverse iterator is :";
  for (auto it = myarray.rbegin();it!=myarray.rend();++it) {
    std::cout << "\n" <<"iterate is :" << *it << std::endl;
  }

	myarray.fill(0);
	std::cout << "after fill myarray contains is :";
  for (auto it = myarray.begin();it!=myarray.end();++it) {
    std::cout << "\n" <<"iterate is :" << *it << std::endl;
  }

  return 0;
}