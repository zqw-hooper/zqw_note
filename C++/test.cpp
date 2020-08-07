#include <algorithm>
#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <memory>
#include <utility>
#include <bitset>
#include <fstream>
#include <sstream>
#include <istream>
#include <stdexcept>
#include <limits>

/**数组做形参**/
// int* printit(int buf[]) {
//   int *tmp = new int[8];
//   for (int i = 0; i < sizeof(buf); i++) {
//     printf("a[i] value is : %d\n", buf[i]);
//     tmp[i] = buf[i] + 1;
//     printf("tmp[i] value is : %d\n", tmp[i]);
//   }
//   // printf("tmp value is : %d\n", tmp);
//   return tmp;
// }

/**禁用隐式转换**/
// class B
// {
//   public :
//   int data;
//   B(int _data) : data(_data) { printf("data is : %d\n", data); }
//   // explicit B(int _data):data(_data){printf("data is : %d\n",data);}
// };

/**模板函数**/
// template <typename T1,typename T2,typename T3>
// T1 add(T2& a, T3& b)
// {
//   return a+b;
// }

/**函数指针**/
// int test(int a,int b)
// {
//     /*do something*/
//     printf("value are: %d,%d\n",a,b);
//     return 0;
// }
// typedef int(*fp)(int,int);

/**virtual and override区别:**/
// class BbaseClass{
//   public:
//     virtual void fucnA(float a){printf("this is base class: %f\n",a);}
// };

// class DeriveClass:public BbaseClass
// {
//   public:
//      virtual void fucnA(float a) override {printf("this is derive class: %f\n",a*5);};
// };

/**Polymorphism**/
// class Father
// {
// public:
//   Father() { printf("Father constructor!\n"); }
//    ~Father() { printf("Father deconstructor!\n"); }

//   virtual void Print() { printf("Father Print!\n"); }
// };

// class Son : public Father
// {
// public:
//   Son() { printf("Son constructor!\n"); }
//   ~Son() { printf("Son constructor!\n"); }

//   void Print() override { printf("Son Print!\n"); }
// };

// class Son1 : public Father
// {
// public:
//   Son1() { printf("Son1 constructor!\n"); }
//   ~Son1() { printf("Son1 constructor!\n"); }

//   void Print() { printf("Son1 Print!\n"); }
// };

/**pointer function**/
// int *expand(int a)
// {
//   int *ptr = new int();
//   *ptr = a * 31;
//   return ptr;
// }

/** 指针类型作为引用形参 **/
// struct ABC
// {
//     int a;
//     int b;
// };
// void test(ABC*& temp)
// {
//   temp->a = 33;
// }
// void test1(ABC*& temp)
// {
//   temp->a = 1111;
//   temp->b = 2222;
// }

/**右值引用**/
// void test(int &&temp)
// {
// printf("temp is : %d\n",temp);
//   temp = 112;
// }

/**static_cast  dynamic_cast**/
class Animal
{
public:
    virtual void eat() { printf("animal eat food!\n"); }
};

class Cat : public Animal
{
public:
    void eat() { printf("cat eat food!\n"); };
    void vivipation() { printf("vivipation!\n"); };

private:
    void eatBone();
};

/**引用返回值**/
// int& test(int temp)
// {
//     int &bb = temp;
//     bb = 152;
//     return bb;
// }

/**指针返回值**/
// int* test(int temp)
// {
//     int * bb = new int();
//     *bb = temp*2;
//     return bb;
// }

/**ifstream and stringstream**/
// void run(std::istream& in)
// {
//     std::string preamble;
//     in >> preamble;
//     // std::cout << "preamble is is  :" << preamble << std::endl;

//     if (preamble != "BO_")
//     {
//         in.setstate(std::ios_base::failbit);
//         // return in;
//     }
//     else
//     { 
//         std::ostringstream ostr;
//         ostr << in.rdbuf();
//         std::string str = ostr.str();
//         std::cout << "string are  :" << str << std::endl;
//     }
// }

// void init(std::istream& in)
// {
//     while (!in.eof())
//     {
//         run(in);
//         if (in.fail()) 
//         {
// 			in.clear();
// 			in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
// 		} 
//         else 
//         {
// 			// messages.push_back(msg);
// 		} 
//     } 
// }

/** this pointer **/
// class Box
// {
// public:
//     // 构造函数定义
//     Box(double l = 2.0, double b = 2.0, double h = 2.0)
//     {
//         std::cout << "Constructor called." << std::endl;
//         length = l;
//         breadth = b;
//         height = h;
//     }
//     double Volume()
//     {
//         return this->length * this->breadth * this->height;
//     }
//     int compare(Box box)
//     {
//         return this->Volume() > box.Volume();
//     }

// private:
//     double length;  // Length of a box
//     double breadth; // Breadth of a box
//     double height;  // Height of a box
// };

// class Complex
// {
// public:
//     double real, imag;

//     Complex(double r, double i) : real(r), imag(i) {}
    
//     Complex* AddOne()
//     {
//         this->real++;
//         return this;
//     }
// };

// void test(int * ptr)
// {
//     int *temp = new int();
//     temp = ptr;
//     *temp = 88;
// }

int main(int argc, char **argv)
{
    /**break return continue 测试**/ // break仅退出当前循环, break也可以用在switch中表示退出switch
    // for (int x = 0; x < 10; x++)
    // {
    //   for (int y = 0; y < 3; y++)
    //   {
    //     if (x == 3)
    //     {
    //       break;
    //     }
    //     printf("y is : %d\n", y);
    //   }
    //   printf("x is : %d\n", x);
    // }

    /**数组指针**/
    // int a[8], b[8];
    // a[0] = 1;
    // a[1] = 2;
    // a[2] = 3;
    // a[3] = 4;
    // a[4] = 55;
    // a[5] = 66;
    // a[6] = 77;
    // a[7] = 88;
    // int d[2];
    // int* c = printit(a);
    // printf("sizeof a is : %d\n", sizeof(a)/sizeof(a[0]));
    // for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
    //{
    //   printf("c value is : %d\n", *(c + i));
    //}

    /**max_element函数**/
    // int a[] = {123, 124, 6, 4, 77, 5, 58};
    // int pos = std::max_element(a, a + 7) - a;
    // std::cout << "pos is " << pos << std::endl;

    /**位移运算**/
    // uint8_t a = 6;
    // uint8_t b = a>>2;
    // printf("bb value is : %d\n",b);

    /**char const char* 和string 测试**/
    // char a = 'h';
    // printf("a is : %c\n",a);
    // std::string a = "z";
    // printf("a is : %d\n",sizeof(a));
    // printf("a size is : %d\n",a.size());
    // const char* b = "z";
    // printf("b is : %d\n",sizeof(b));
    // char c = 'z';
    // printf("c is : %d\n",sizeof(c));

    /**指针**/
    // int var = 120; // 实际变量的声明
    // int *ip;      // 指针变量的声明
    // ip = &var;
    // ip = &var; // 在指针变量中存储 var 的地址
    // std::cout << "Value of var variable: ";
    // std::cout << var << std::endl;
    // // 输出在指针变量中存储的地址
    // std::cout << "Address stored in ip variable: ";
    // std::cout << ip << std::endl;
    // 访问指针中地址的值
    // int * ip = new int[5]{23,45};
    // std::cout << "Value of *ip variable: ";
    // std::cout << *(ip+2) << std::endl;

    /**模板函数调用**/
    // float a = 45.3;
    // float b = 100.2;
    // float c = add<float>(a, b);
    // printf("c is: %f\n", c);

    /**函数指针**/
    // fp f = test;
    // f(1,2);
    // printf("%p\n", f);

    /**virtual and override区别:**/
    // DeriveClass deri;
    // deri.fucnA(1.3);
    // int a =5;
    // const int& b =a;
    // a = 7;
    // printf("b is : %d\n",b);
    // printf("a is : %d\n",a);

    /**Polymorphism**/
    // Father father;
    // Son son;
    // father.Print();
    // son.Print();
    // Father* father = new Father;
    // father->Print();
    // Father* father = new Son;
    // father->Print();
    // delete father;

    // Father* father = new Son;
    // father->Print();

    // Father* father = new Son();
    // delete father;

    /** const 在* 左边, const 在*右边(左定值, 右定向)**/
    // int * b = new int(5);
    // printf("b ptr is : %p\n", b);
    // const int* a = new int(4);
    // printf("a is : %d\n", *a);
    // printf("a ptr is : %p\n", a);
    // a = b;
    // printf("a is : %d\n", *a);
    // printf("a ptr is : %p\n", a);

    /** new and delete **/
    // int* d = new int(10);
    // printf("d is : %d\n", *d);
    // printf("d ptr is : %p\n", d);
    // int *const c = new int(8);
    // printf("c is : %d\n", *c);
    // printf("c ptr is : %p\n", c);
    // *c = 9;
    // printf("c is : %d\n", *c);
    // printf("c ptr is : %p\n", c);
    // delete d;

    /**pointer function**/
    // int a = 4;
    // int *ret = expand(a);
    // printf("ret value is : %d\n", *ret);

    /** 指针类型作为引用形参 **/
    // ABC* abc = new ABC();
    // printf("a before value is : %d\n", abc->a);
    // printf("b before value is : %d\n", abc->b);
    // test(abc);
    // printf("a mid value is : %d\n", abc->a);
    // printf("b mid value is : %d\n", abc->b);
    // test1(abc);
    // printf("a after value is : %d\n", abc->a);
    // printf("b after value is : %d\n", abc->b);

    /**禁用隐式转换**/
    // B temp = 6.3;

    /**右值引用**/
    // int &&a = 3;
    // int a = 678;
    // printf("---: %d\n", a);
    // test(std::move(a));
    // printf("------: %d\n", a);

    /**引用返回**/
    // int a = 5;
    // int & b = test(a);
    // printf("return is : %d\n",b);

    /**sizeof(long) sizeof(long long)**/
    // printf("sizeof long is :%d\n", sizeof(long));
    // printf("sizeof long long is :%d\n",sizeof(long long));

    /**static_cast**/
    // float a = 3.3;
    // int b = static_cast<int>(a);
    // printf("value is : %d\n", b);

    // Animal *animal = new Animal();
    // animal->eat();
    // Cat* cat = static_cast<Cat*>(animal);
    // cat->eat();
    // cat->vivipation();
    // Cat* cat = new Cat();
    // cat->eat();
    // Animal* animal = static_cast<Animal*>(cat);
    // animal->eat();

    /**dynamic_cast**/
    //   Animal *animal = new Animal();
    //   Cat* cat = dynamic_cast<Cat*>(animal);
    //   cat->eat();
    //   cat->vivipation();

    //   Cat* cat = new Cat();
    //   Animal* animal = dynamic_cast<Animal*>(cat);
    //   animal->eat();

    /**const_cast**/
    // const float* a = new float(88.6);
    // float* b = const_cast<float*>(a);
    // *b = 299.1;
    // printf("value is : %f\n", *a);
    // printf("value is : %f\n", *b);
    
    /**reinterpret_cast**/
    // float *a = new float(22.222);
    // int  temp = reinterpret_cast<int>(a);
    // printf("value is : %d\n", temp);

    /**father and son class related**/
    Animal* animal = new Cat();
    animal->eat();
    // Cat* cat = new Cat();
    // cat->vivipation();

    /**负数存储形式**/
    // std::bitset<16> a(2);
    // std::bitset<16> b(-2);
    // std::cout << "binary of a is : " << a << std::endl;
    // std::cout << "binary of b is : " << b << std::endl;

    /**指针返回值**/
    // int a = 17;
    // int *ret = test(a);
    // printf("ret is :%d\n", *ret);
    // delete ret;
    // printf("ret is :%d\n", *ret);

    /**shared pointer**/
    // std::shared_ptr<int> ptr1 = std::make_shared<int>();
    std::shared_ptr<int> ptr1(new int);
    *ptr1 = 1001;
    printf("shared ponter ptr1 value is : %d\n", *ptr1);
    printf("shared ponter ptr1 address is : %p\n", ptr1.get());
    *ptr1.get() = 123;
    printf("shared ponter ptr1 value is : %d\n", *ptr1);
    printf("shared ponter ptr1 address is : %p\n", ptr1.get());
    // ptr.reset();
    // printf("shared ponter use count is : %d\n", ptr.use_count());
    std::shared_ptr<int> ptr2(ptr1);
    printf("shared ponter ptr2 address is : %p\n", ptr2.get());
    printf("shared ponter ptr1 use count is : %d\n", ptr1.use_count());
    printf("shared ponter ptr2 use count is : %d\n", ptr2.use_count());


    /**ifstream and stringstream**/
    // std::ifstream file("./Ultrasonic_radar_messages_V5.0.dbc");
    // std::stringstream ptr ;
    // ptr << file.rdbuf();
    // std::string str = ptr.str();
    // init(file);

    /** this pointer **/
    // Complex c1(100, 110), c2(200, 220);
    // c2 = c1.AddOne();
    // std::cout << c2.real << "," << c2.imag << std::endl; //输出 2,1
    // Complex *c1 = new Complex(10, 11);
    // Complex *c2 = new Complex(20, 22);
    // std::cout << "pointer c2 : " << c2 << std::endl;
    // std::cout << "pointer c1 : " << c1 << std::endl;
    // c2 = c1->AddOne();
    // std::cout << "output value : " << c2->real << "," << c2->imag << std::endl;
    //--------------------------------------------------
    // char *a = "abc";
    // printf("---: %s\n", a);
    // printf("---: %p\n", a);
    // printf("---: %s\n", a + 1);
    // printf("---: %p\n", a + 1);
    // printf("---: %s\n", a + 2);
    // printf("---: %p\n", a + 2);

    // char str2[] = {'h','e','l','l','o'};
    // printf("str2 %lu %lu\n\n", sizeof(str2), strlen(str2));

    // char*  a = new char('g');
    // const char* b ="const char*";
    // printf("a value is : %s\n", a);
    // printf("b value is : %s\n", b);

    // int* a = new int(5);
    // test(a);
    // printf("output is : %d\n",*a);
    

    return 0;
}
// #include <iostream> 
// using namespace std;
 
// class Shape {
//    protected:
//       int width, height;
//    public:
//       Shape( int a=0, int b=0)
//       {
//          width = a;
//          height = b;
//       }
//       virtual int area()
//       {
//          cout << "Parent class area :" <<endl;
//          return 0;
//       }
// };
// class Rectangle: public Shape{
//    public:
//       Rectangle( int a=0, int b=0):Shape(a, b) { }
//       int area ()
//       { 
//          cout << "Rectangle class area :" <<endl;
//          return (width * height); 
//       }
// };
// class Triangle: public Shape{
//    public:
//       Triangle( int a=0, int b=0):Shape(a, b) { }
//       int area ()
//       { 
//          cout << "Triangle class area :" <<endl;
//          return (width * height / 2); 
//       }
// };
// // 程序的主函数
// int main( )
// {
//    Shape *shape;
//    Rectangle rec(10,7);
//    Triangle  tri(10,5);
 
//    // 存储矩形的地址
//    shape = &rec;
//    // 调用矩形的求面积函数 area
//    shape->area();
 
//    // 存储三角形的地址
//    shape = &tri;
//    // 调用三角形的求面积函数 area
//    shape->area();
   
//    return 0;
// }