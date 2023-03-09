#include <iostream>

template <typename T>
void display_message(const std::string &msg, T value)
{
    std::cout << value << std::endl;
}

int main()
{
    display_message("hello", 1);

    return 0;
}