#include <iostream>
#include <vector>
#include <iomanip>

#define GREEN "\033[32m" /* Green */
#define WHITE "\033[37m" /* White */
#define RED "\033[31m"   /* Red */

void bubble_sort(std::vector<double> &t_src)
{
    std::cout << GREEN << "this vector size is: \033[31m  " << t_src.size() << std::endl;
    std::cout << WHITE << std::endl;
    for (int i = 0; i < t_src.size(); i++)
    {
        for (int j = 0; j < t_src.size() - i - 1; j++)
        {
            if (t_src.at(j) > t_src.at(j + 1))
            {
                double temp = 0.0;
                temp = t_src.at(j + 1);
                t_src.at(j + 1) = t_src.at(j);
                t_src.at(j) = temp;
            }
        }
    }

    for (int k = 0; k < t_src.size(); k++)
    {
        std::cout << GREEN << "bubble sort result is : \033[31m" << std::setprecision(2) << t_src.at(k) << std::endl;
        std::cout << WHITE << std::endl;
    }
}

int main()
{
    std::vector<double> src = {8, 5, 7, 6, 3, 1, 45, 98, 78, 112, 81,
                               32, 22, 43, 55, 61, 1111, 3333, 444, 6666, 53355, 88.8, 98.76};
    std::cout << setiosflags(std::ios::fixed);
    bubble_sort(src);
    return 0;
}