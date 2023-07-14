#include <iostream>
#include <array>

int main()
{
    // 定义一个包含3行4列的二维数组
    std::array<std::array<int, 4>, 3> myArray = {
        {
            {11, 12, 13, 14},
            {21, 22, 23, 24},
            {31, 32, 33, 34}
        }
    };

    // 访问二维数组的元素
    for (size_t i = 0; i < myArray.size(); ++i)
    {
        for (size_t j = 0; j < myArray[i].size(); ++j)
        {
            std::cout << myArray[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}