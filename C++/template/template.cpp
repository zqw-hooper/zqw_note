#include <iostream>
#include <string>
using namespace std;

template <typename T, typename T1> 
void message(const T &msg, T1 val = T1())
{
  if (!val) {
    std::cout << "### " << msg << std::endl;
  } else {
    std::cout << "### " << msg << "---" << val << std::endl;
  }
}

template <typename T> 
void message1(const T &msg)
{
  std::cout << "@@@ " << msg << std::endl;
}

int main(int argc, char **argv) 
{
  message("template test", 20200724);
  message<string, int>("template test", 20200723); // 有无<string,int>都可以

  message1("message1 template test");
  message1<string>("message1 template test2");

  return 0;
}
