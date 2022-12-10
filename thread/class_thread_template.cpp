#include <iostream>
#include <thread>

class ThreadDemo
{
public:
    void start()
    {
        flag = true;
        std::cout << "Start thread" << std::endl;
        thr = new std::thread(&ThreadDemo::task, this, 10);
    }
    void stop()
    {
        std::cout << "Stop thread" << std::endl;
        flag = false;
        thr->join();
    }
    void task(int count)
    {
        std::cout << "Thread begin" << std::endl;

        while (flag)
        {
            std::cout << "a:" << count << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
            count--;
        }

        std::cout << "Thread exit" << std::endl;
    }

private:
    std::thread *thr;
    bool flag = true;
};

int main()
{
    ThreadDemo demo;

    demo.start();
    std::this_thread::sleep_for(std::chrono::seconds(5));
    demo.stop();
    
    return 0;
}
