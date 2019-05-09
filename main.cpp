#include "linkedlist_array.hpp"
#include <string>
#include <iostream>


int main(void)
{
    collection::array::linked<int> list;
    list.alloc(10);
    // for (short i = 1; i < 10; ++i)
    // {
    //     list.index_back(i);
    // }
    for (short i = 0; i < 10; ++i)
    {
        std::cout << list[i] << std::endl;
    }
    list.dealloc();
    std::cout << "deallocated" << std::endl;
    // for (short i = 0; i < 4; ++i)
    // {
    //     std::cout << list[i] << std::endl;
    // }
    return 0;
}