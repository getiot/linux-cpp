#include <iostream>

void display_message(char ch)
{
    std::cout << "C: " << ch << std::endl;
}

void display_message(const std::string& msg)
{
    std::cout << msg << std::endl;
}

void display_message(const std::string& msg, int loop)
{
    for (int i=0; i<loop; i++) {
        std::cout << msg << std::endl;
    }
}

int main()
{
    /* 1 */
    display_message('G');

    /* 2 */
    display_message("GetIoT.tech");

    /* 3 */
    display_message("GetIoT.tech!", 2);

    return 0;
}