#include <iostream>
#include <Eigen/Dense>
#include <cmath>
#include <chrono>

#define DATA_WIDTH  8000
#define DATA_HEIGHT 200

// #define ENABLE_PRINT

int main()
{
    // 定义一个包含3行4列的二维数组
    Eigen::MatrixXi matrix(DATA_HEIGHT, DATA_WIDTH);
    // int data[DATA_HEIGHT][DATA_WIDTH];

    std::cout << "Origianl: " << std::endl;

    auto start_time1 = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < DATA_HEIGHT; ++i) {
        for (int j = 0; j < DATA_WIDTH; ++j) {
            matrix(i, j) = i * DATA_WIDTH + j;
        }
    }

    auto end_time1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_time1 = end_time1 - start_time1;
    std::cout << "Elapsed Time: " << elapsed_time1.count() << "seconds" << std::endl;

#ifdef ENABLE_PRINT
    for (int i = 0; i < DATA_HEIGHT; ++i) {
        for (int j = 0; j < DATA_WIDTH; ++j) {
            std::cout << matrix(i, j) << " ";
        }
        std::cout << "\n";
    }
#endif

    std::cout << "Modified: " << std::endl;

    auto start_time = std::chrono::high_resolution_clock::now();

    matrix = matrix.array() * 2;

    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_time = end_time - start_time;

#ifdef ENABLE_PRINT
    for (int i = 0; i < DATA_HEIGHT; ++i) {
        for (int j = 0; j < DATA_WIDTH; ++j) {
            std::cout << matrix(i, j) << " ";
        }
        std::cout << "\n";
    }
#endif

    std::cout << "Elapsed Time: " << elapsed_time.count() << "seconds" << std::endl;

    return 0;
}