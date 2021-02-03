#include <cstdio>
#include <iostream>
using namespace std;

#if 0
class counter {
public:
  counter() : count(0) {}
  ~counter() {}

  void operator++() { count++; }
  void operator++(int) { count++; }
  void operator--() { count--; }
  void operator--(int) { count--; }
  int get() { return count; }
  void reset() { count = 0; }

private:
  int count;
};

template <typename T> 
class shared_ptr 
{
public:
  shared_ptr(T *in) 
  {
    m_ptr = in;
    m_count = new counter();
    if (m_ptr != nullptr) 
    {
      (*m_count)++;
    }
  }
  shared_ptr(const shared_ptr &in) 
  {
    m_ptr = in.m_ptr;
    m_count = in.m_count;
    (*m_count)++;
  }
  // shared_ptr& operator=(){}

  ~shared_ptr() 
  {
    (*m_count)--;
    if (m_count->get() == 0) 
    {
      delete m_count;
      delete m_ptr;
    }
  }

  T *get() { return m_ptr; }
  int use_count() { return m_count->get(); }
  T &operator*() { return *m_ptr; }
  T *operator->() { return m_ptr; }

private:
  counter *m_count;
  T *m_ptr;
};

int main() {
  shared_ptr<int> ptr1(new int(151));
  cout << "--- Shared pointers ptr1 ---\n";
  *ptr1 = 100;
  cout << " ptr1's value now: " << *ptr1 << endl;
  cout << " ptr1's use count: " << ptr1.use_count() << endl;
  printf("ptr1's address is : %p\n", ptr1.get());

  shared_ptr<int> ptr2 = ptr1;
  printf("ptr1's address is : %p\n", ptr1.get());
  printf("ptr1's address is : %p\n", ptr2.get());
  cout << " ptr1's use count: " << ptr1.use_count() << endl;
  cout << " ptr2's use count: " << ptr2.use_count() << endl;
  return 0;
}

#elif 1

class A {
public:
  void operator++(int) { cout << "operator++(int)"; }
  void operator++() { cout << "operator++()"; }
};

int main()
{
    A a;
    ++a; // "operator++()"
    a++; // "operator++(int)"
  return 0;
}
#endif