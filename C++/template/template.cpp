#include <iostream>
#include <string>
using namespace std;

#if 0

// function template
template <typename T> 
T myMax(T x, T y) 
{ 
   return (x > y)? x: y; 
} 
  
int main() 
{ 
  cout << myMax<int>(3, 7) << endl;  // Call myMax for int 
  cout << myMax<double>(3.0, 7.0) << endl; // call myMax for double 
  cout << myMax<char>('g', 'e') << endl;   // call myMax for char 

  cout << myMax(3, 7) << endl;  // Call myMax for int 
  cout << myMax(3.0, 7.0) << endl; // call myMax for double 
  cout << myMax('g', 'e') << endl;   // call myMax for char 
  return 0; 
}

#elif 0

// class template
template <typename T> 
class Array { 
private: 
    T *ptr; 
    int size; 
public: 
    Array(T arr[], int s); 
    void print(); 
}; 
  
template <typename T> 
Array<T>::Array(T arr[], int s) { 
    ptr = new T[s]; 
    size = s; 
    for(int i = 0; i < size; i++) 
        ptr[i] = arr[i]; 
} 
  
template <typename T> 
void Array<T>::print() { 
    for (int i = 0; i < size; i++) 
        cout<<" "<<*(ptr + i); 
    cout<<endl; 
} 
  
int main() { 
    int arr[5] = {1, 2, 3, 4, 5}; 
    Array<int> a(arr, 5); 
    a.print(); 
    return 0; 
} 

#elif 0
// we can pass more than one data types as arguments to templates

template<class T, class U> 
class A  { 
    T x; 
    U y; 
public: 
    A() {    cout<<"Constructor Called"<<endl;   } 
}; 
  
int main()  { 
   A<char, char> a; 
   A<int, double> b; 
   return 0; 
} 

#elif 0
// we can specify default arguments to templates.

template<class T, class U = char> 
class A  { 
public: 
    T x; 
    U y; 
    A() {   cout<<"Constructor Called"<<endl;   } 
}; 
  
int main()  { 
   A<char> a;  // This will call A<char, char>    
   return 0; 
}

#elif 0

// We can pass non-type arguments(parameters that are not data types) to templates. Non-type parameters are mainly used for specifying 
// max or min values or any other constant value for a particular instance of a template. The important 
// thing to note about non-type parameters is, they must be const. The compiler must know the value of 
// non-type parameters at compile time. Because compiler needs to create functions/classes for a specified 
// non-type value at compile time.
template <class T, int max> 
int arrMin(T arr[], int n) 
{ 
   int m = max; 
   for (int i = 0; i < n; i++) 
      if (arr[i] < m) 
         m = arr[i]; 
   
   return m; 
} 
   
int main() 
{ 
   int arr1[]  = {10, 20, 15, 12}; 
   int n1 = sizeof(arr1)/sizeof(arr1[0]); 
   
   char arr2[] = {1, 2, 3}; 
   int n2 = sizeof(arr2)/sizeof(arr2[0]); 
   
   // Second template parameter to arrMin must be a constant 
   cout << arrMin<int, 10000>(arr1, n1) << endl; 
   cout << arrMin<char, 256>(arr2, n2); 
   return 0; 
} 

#elif 0
// Function templates and static variables: Each instantiation of function template has its own copy of local static variables
template <typename T> 
void fun(const T& x) 
{ 
  static int i = 10; 
  cout << ++i; 
  return; 
} 
  
int main() 
{     
  fun<int>(1);  // prints 11 
  cout << endl; 
  fun<int>(2);  // prints 12 
  cout << endl; 
  fun<double>(1.1); // prints 11 
  cout << endl; 
  getchar(); 
  return 0; 
}
// output: 11  12   11

#elif 0

// Class templates and static variables:
// The rule for class templates is same as function templates
// Each instantiation of class template has its own copy of member static variables. 
// For example, in the following program there are two instances Test and Test. 
// So two copies of static variable count exist.
template <class T> class Test 
{   
private: 
  T val;  
public: 
  static int count; 
  Test() 
  { 
    count++; 
  } 
  // some other stuff in class 
}; 
  
template<class T> 
int Test<T>::count = 0; 
  
int main() 
{ 
  Test<int> a;  // value of count for Test<int> is 1 now 
  Test<int> b;  // value of count for Test<int> is 2 now 
  Test<double> c;  // value of count for Test<double> is 1 now 
  cout << Test<int>::count   << endl;  // prints 2   
  cout << Test<double>::count << endl; //prints 1 
     
  getchar(); 
  return 0; 
} 

#elif 0
// Template Metaprogramming
template<int n> 
struct funStruct 
{ 
    enum { val = 2*funStruct<n-1>::val }; 
}; 
  
template<> 
struct funStruct<0>
{ 
    enum { val = 1 }; 
}; 
  
int main() 
{ 
    cout << funStruct<8>::val << endl; 
    return 0; 
} 

#elif 1
// Template Specialization

template <class T> 
void fun(T a) 
{ 
   cout << "The main template fun(): " 
        << a << endl; 
} 
  
template<> 
void fun(int a) 
// or void fun<int>(int a) 
{ 
    cout << "Specialized Template for int type: "
         << a << endl; 
} 
  
int main() 
{ 
    fun<char>('a'); 
    fun<int>(10); 
    fun<float>(10.14); 
} 

#else
// An Example Program for class template specialization

template <class T> 
class Test 
{ 
  // Data memnbers of test 
public: 
   Test() 
   { 
       // Initialization of data members 
       cout << "General template object \n"; 
   } 
   // Other methods of Test 
}; 
  
template <> 
class Test <int> 
{ 
public: 
   Test() 
   { 
       // Initialization of data members 
       cout << "Specialized template object\n"; 
   } 
}; 
  
int main() 
{ 
    Test<int> a; 
    Test<char> b; 
    Test<float> c; 
    return 0; 
} 
#endif
