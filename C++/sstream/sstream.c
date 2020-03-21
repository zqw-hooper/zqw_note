#include <iostream>
#include <sstream>
#include <string>

int main() {
  std::stringstream ss, ss1;
  ss << "this is a test about sstream" << 20191122 << "!";
  std::string s = ss.str();
  std::cout << s << std::endl;

  // this set str as the content of the stringstream of ss1
  ss1.str(s);
  for (int i = 0; i < 6; i++) {
    std::string s1;
    ss1 >> s1;
    std::cout << s1 << std::endl;
  }

  std::cout << "stringstream trans to string is :" << ss1.str() << std::endl;
  std::cerr << "cerr stringstream trans to string is :" << ss1.str()
            << std::endl;
  std::clog << "clog stringstream trans to string is :" << ss1.str()
            << std::endl;

  return 0;
}