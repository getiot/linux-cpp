#include <iostream>
#include <fstream>

int main()
{
    /* Writing file */
    std::fstream file("seq_data.txt", std::ios_base::in | std::ios_base::app);

    if (!file) {
        std::cerr << "Oops! Unable to save session data!" << std::endl;
    }
    else {
        file << "Hello, GetIoT.tech" << std::endl;
    }

    file.seekg(0);

    /* Reading file */
    std::string data;
    while (file >> data) {
        std::cout << data << std::endl;
    }

    file.close();

    return 0;
}