#include <iostream>
#include <functional>

// 外部函数
void externalFunction(int loop, std::string& msg) {
    // 在这里添加外部函数的实现
    // 这是一个示例，你可以根据你的需要来编写具体实现
    for (auto i=0; i<loop; i++) {
        std::cout << msg << std::endl;
    }
}

class MyDemo {
public:
    // 注册回调函数
    void registerCallback(const std::function<void(int, std::string&)>& cb_func) {
        // 在需要调用的时候调用
        std::string msg("Calling external function.");
        cb_func(3, msg);
    }
};

int main() 
{
    MyDemo demo;
    demo.registerCallback(externalFunction);
    
    return 0;
}