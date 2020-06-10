#include <iomanip>
#include <iostream>
#include <math.h>
#include <vector>

#define GREEN "\033[32m" /* Green */
#define WHITE "\033[37m" /* White */
#define RED "\033[31m"   /* Red */

typedef int QcVectorType;
std::vector<QcVectorType> src = {5, 3, 1, 2, 4};

void swap(QcVectorType *a, QcVectorType *b)
{
  QcVectorType temp = *a;
  *a = *b;
  *b = temp;
}

void insertSort(std::vector<QcVectorType> &t_src)
{
  QcVectorType j = 0;
  QcVectorType p = 0;
  QcVectorType temp = 0;
  for (p = 1; p < t_src.size(); p++)
  {
    temp = t_src.at(p);
    for (j = p; j > 0 && t_src.at(j - 1) > temp; j--)
    {
      t_src.at(j) = t_src.at(j - 1);
    }
    t_src.at(j) = temp;
  }
}

QcVectorType mediaPivot(std::vector<QcVectorType> &t_src, int left, int right)
{
  int center = floor((left + right) / 2);
  if (t_src.at(left) > t_src.at(center))
  {
    swap(&t_src.at(left), &t_src.at(center));
  }
  if (t_src.at(left) > t_src.at(right))
  {
    swap(&t_src.at(left), &t_src.at(right));
  }
  if (t_src.at(center) > t_src.at(right))
  {
    swap(&t_src.at(center), &t_src.at(right));
  }

  swap(&t_src.at(center), &t_src.at(right - 1));
  return t_src.at(right - 1);
}

int partition(std::vector<QcVectorType> &t_src, int left, int right)
{
  int i = left;
  int j = right - 1;                 // 5
  QcVectorType pivot = t_src.at(right - 1); //mediaPivot(t_src, left, right);
  // for (int a = 0; a < t_src.size(); a++)
  // {
  // 	std::cout << GREEN << "after mediaPivot vector is : \033[31m" <<
  // t_src.at(a) << std::endl;
  // 	std::cout << WHITE << std::endl;
  // }
  for (;;)
  {
    // std::cout << "print i and j : " << i << ", " << j << std::endl;
    while (pivot > t_src.at(++i))
    {
      // std::cout << "pivot is bigger, the position is : " << i << std::endl;
    }

    while (pivot < t_src.at(--j))
    {
      // std::cout << "pivot is smaller, the position is : " << j << std::endl;
    }

    if (i < j)
    {
      // std::cout << "i swap once  : " << i << ", " << j << std::endl;
      swap(&t_src.at(i), &t_src.at(j));
    }
    else
    {
      break;
    }
  }
  // for (int a = 0; a < t_src.size(); a++) {
  //   std::cout << GREEN << "before swap vector is : \033[31m" << t_src.at(a)
  //             << std::endl;
  //   std::cout << WHITE << std::endl;
  // }
  // std::cout << GREEN << "i is : \033[31m" << i << std::endl;
  swap(&t_src.at(i), &t_src.at(right - 1));
  // for (int k = 0; k < t_src.size(); k++) {
  //   std::cout << RED << "after swap vector is : \033[31m" << t_src.at(k)
  //             << std::endl;
  //   std::cout << WHITE << std::endl;
  // }
  return i;
}

void quick_sort(std::vector<QcVectorType> &t_src, int left, int right)
{
  if (right > left)
  {
    int i = partition(t_src, left, right);
    quick_sort(t_src, left, i - 1);
    quick_sort(t_src, i + 1, right);
  }
  // else
  // {
  //   insertSort(t_src);
  // }
}

int main()
{
  std::cout << setiosflags(std::ios::fixed);
  quick_sort(src, 0, src.size() - 1);
  for (int k = 0; k < src.size(); k++)
  {
    std::cout << RED << "sort result vector is : \033[31m" << src.at(k)
              << std::endl;
    std::cout << WHITE << std::endl;
  }
  return 0;
}