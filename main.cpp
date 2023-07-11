#include <vector>
#include <stdio.h>
#include <iostream>

int main()
{
    std::vector<int> data = {100, 101, 102};
    auto tmp = data.begin();
    std::cout << "With asterix: " << *tmp << std::endl;

    return 0;
}