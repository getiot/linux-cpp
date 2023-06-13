#include <iostream>

template <typename T>
class MyStack {
private:
    int maxSize; /* 存储栈的最大大小 */
    int top;     /* 表示栈的顶部元素的位置，空栈时 top 为-1 */
    T* data;     /* 指向存储元素的数组的指针 */

public:
    /*
     * MyStack 类的构造函数，接受一个 int 类型参数作为栈的最大大小，
     * 然后通过初始化列表来初始化类的三个成员变量 maxSize, top 和 data。
     * 
     * 在这里，使用 new 运算符为 data 成员变量分配一段大小为 n 且类型为 T 的内存空间，即一个 T 类型的数组。
     * 通过使用初始化列表，可以避免在构造函数体中对变量进行额外的初始化/赋值，同时还可以提供更好的代码可读性和可维护性。
     */
    MyStack(int n) : maxSize(n), top(-1), data(new T[n]) {}

    /* 在栈顶插入一个元素 */
    void push(const T& value) {
        if (top == maxSize - 1) {
            std::cerr << "Stack is full!" << std::endl;
            return;
        }
        data[++top] = value;
    }

    /* 从栈中弹出栈顶元素 */
    T pop() {
        if (top == -1) {
            std::cerr << "Stack is empty!" << std::endl;
            return T();
        }
        return data[top--];
    }

    /* 获取栈顶元素的值（但是不弹出该元素） */
    T peek() const {
        if (top == -1) {
            std::cerr << "Stack is empty!" << std::endl;
            return T();
        }
        return data[top];
    }

    /* 判断栈是否为空 */
    bool isEmpty() const {
        return top == -1;
    }

    /* 析构函数，销毁 MyStack 类对象并释放动态分配的内存 */
    ~MyStack() {
        delete[] data;
    }
};

int main()
{
    MyStack<int> si(5);
    MyStack<std::string> ss(5);

    si.push(11);
    si.push(12);

    ss.push("Hello");
    ss.push("World");

    std::cout << si.pop() << std::endl;      // 输出 12
    std::cout << si.peek() << std::endl;     // 输出 11
    std::cout << si.isEmpty() << std::endl;  // 输出 0 (= false)

    std::cout << ss.pop() << std::endl;      // 输出 World
    std::cout << ss.pop() << std::endl;      // 输出 Hello
    std::cout << ss.isEmpty() << std::endl;  // 输出 1 (= true)
    return 0;
}