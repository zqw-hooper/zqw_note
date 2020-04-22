#include <algorithm>
#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <memory>
#include <utility>
#include <bitset>

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
//   virtual ~Father() { printf("Father deconstructor!\n"); }

//   virtual void Print() { printf("Father class!\n"); }
// };

// class Son : public Father
// {
// public:
//   Son() { printf("Son constructor!\n"); }
//   ~Son() { printf("Son constructor!\n"); }

//   virtual void Print() { printf("Son class!\n"); }
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
// class Animal
// {
// public:
//     virtual void eat() { printf("animal eat food!\n"); }
// };

// class Cat : public Animal
// {
// public:
//     void eat() { printf("cat eat food!\n"); };
//     void vivipation() { printf("vivipation!\n"); };

// private:
//     void eatBone();
// };

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
    // Cat* cat = static_cast<Cat*>(animal);
    // cat->eat();
    // Cat* cat = new Cat();
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

    /**负数存储形式**/
    // std::bitset<16> a(2);
    // std::bitset<16> b(-2);
    // std::cout << "binary of a is : " << a << std::endl;
    // std::cout << "binary of b is : " << b << std::endl;

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
    

    return 0;
}
