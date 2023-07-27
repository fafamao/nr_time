#include <practice.h>

namespace lambda
{
    void lambda_p()
    {
        std::vector<int> data;

        for (int i = 0; i < 10; i++)
        {
            data.push_back(i);
            std::cout << "Data vector: " << data[i] << std::endl;
        }

        std::for_each(data.begin(), data.end(), [](int &x)
                      { std::cout << x << std::endl; });

        std::function<void(int &x)> print = [](int &x)
        { std::cout << x << std::endl; };

        std::for_each(data.begin(), data.end(), print);
    }
}

namespace reference
{
    void log(std::string str, auto value)
    {
        std::cout << str << value << std::endl;
    }
    void reference_p()
    {
        int a = 123;
        int &b = a;
        int &&c = 123;
        const int &d = 123;
        log("Address of a is ", &a);
        log("Value of a is ", a);
        log("Address of b is ", &b);
        log("Value of b is ", b);
        log("Address of c is ", &c);
        log("Value of c is ", c);
        log("Value of ++c is ", ++c);
        log("Address of d is ", &d);
        log("Value of d is ", d);
    }
}