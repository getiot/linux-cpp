#include <iostream>
#include <fstream>

int main()
{
    /* Writing file */
#if 0
    std::ofstream outfile("seq_data.txt");                 // Create
#else
    std::ofstream outfile("seq_data.txt", std::ios::app);  // Append
#endif
    if (!outfile) {
        std::cerr << "Oops! Unable to save session data!" << std::endl;
    }
    else {
        outfile << "Hello, GetIoT.tech" << std::endl;
    }

    outfile.close();

    /* Reading file */
    std::ifstream infile("seq_data.txt");
    if (!infile) {
        std::cerr << "Oops! Unable to read data!" << std::endl;
    }
    else {
        std::string data;
        while (infile >> data) {
            std::cout << data << std::endl;
        }
    }

    infile.close();

    return 0;
}