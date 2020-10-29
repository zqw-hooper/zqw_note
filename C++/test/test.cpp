#include <iostream>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <thread>

int function_1(int var)
{
  std::this_thread::sleep_for(std::chrono::milliseconds(5000));
  return var * 6;
}

int main()
{
    int a = 4;
    std::thread t1(function_1, std::ref(a));
    std::cout << "return var a is : " << a << std::endl;
    t1.join();
    return 0;
}