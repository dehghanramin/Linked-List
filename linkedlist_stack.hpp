#ifndef _LINKEDLIST_HPP_
#define _LINKEDLIST_HPP_
#include <cstddef>
#include <iostream>

namespace collection
{
    namespace stack
    {
        template <class T>
        struct Node
        {
            T data;
            Node<T>* link;
        };

        template <class T>
        class linked
        {
        public:
            linked();
            void push(T const&);
            T pop();
        private:
            Node<T>* head;
            Node<T>* end;
        };
    }
}
//-------------------------------------------------------------------------

template <class T>
collection::stack::linked<T>::linked()
{
    head = NULL;
    end = NULL;
}



template <class T>
void collection::stack::linked<T>::push(T const& input)
{
    Node<T>* temp;
	temp = new Node<T>;
	temp->data = input;
	temp->link = head;
    head = temp;    
}

template <class T>
T collection::stack::linked<T>::pop()
{
    try
    {
        if (head == NULL)
        {
            throw -1;
        }
        Node<T>* temp_n = head->link;
        T temp_i = head->data;
        delete head;
        head = temp_n;
        return temp_i;
    }
    catch(int const& e)
    {
        std::cerr << "Error " << e << ". Empty list!" << std::endl;
    }
}



#endif