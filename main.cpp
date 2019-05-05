#include "linkedlist_stack.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    collection::stack::linked<int> list;
    list.push(12);
    std::cout << list.pop() << std::endl;
    std::cout << "Size: " << list.getSize() << std::endl;
    return 0;
}