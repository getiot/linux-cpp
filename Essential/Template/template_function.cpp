#include <iostream>

template <typename T>
void display_message(const std::string &msg, T value)
{
    std::cout << msg << ": " << value << std::endl;
}

int main()
{
    display_message("Hello", 100);
    display_message("Hello", "GetIoT.tech");

    return 0;
}