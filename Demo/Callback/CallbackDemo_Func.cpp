#include <iostream>
#include <functional>

// 外部函数
void externalFunction() {
    // 在这里添加外部函数的实现
    // 这是一个示例，你可以根据你的需要来编写具体实现
    std::cout << "Calling external function." << std::endl;
}

class MyCloud {
public:
    // 注册回调函数
    void registerCallback(const std::function<void()>& cb_func) {
        // 在需要调用的时候调用
        cb_func();
    }
};

int main() 
{
    MyCloud myCloud;
    myCloud.registerCallback(externalFunction);
    
    return 0;
}