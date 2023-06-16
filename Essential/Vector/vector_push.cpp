#include <iostream>
#include <vector>

using namespace std;

class MyTest
{
public:
    MyTest(int num): number_(num) {
        std::cout << "调用构造函数" << endl;
    }

    MyTest(const MyTest& other) : number_(other.number_) {
        std::cout << "调用拷贝构造函数" << endl;
    }

    MyTest(MyTest&& other) : number_(other.number_) {
        std::cout << "调用移动构造函数" << endl;
    }

private:
    int number_;
};


int main()
{
    vector<int> values{};
    vector<MyTest> test1;
    vector<MyTest> test2;

    values.emplace_back(1);
    values.emplace_back(2);
    values.push_back(3);

    for (int i = 0; i < values.size(); i++)
    {
        cout << values[i] << " ";
    }
    cout << endl;

    cout << "emplace_back:" << endl;
    test1.emplace_back(12);

    cout << "push_back:" << endl;
    test2.push_back(13);
    
    return 0;
}