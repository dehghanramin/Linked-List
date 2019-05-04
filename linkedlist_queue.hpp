#ifndef _LINKEDLIST_HPP_
#define _LINKEDLIST_HPP_
#include <cstddef>
#include <iostream>

namespace collection
{
    namespace queue
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
collection::queue::linked<T>::linked()
{
    head = NULL;
    end = NULL;
}

template <class T>
void collection::queue::linked<T>::push(T const& input)
{
    if (head == NULL)
    {
        Node<T>* temp;
        temp = new Node<T>;
        temp->data = input;
        temp->link = NULL;
        head = temp;
        end = temp;
    }
    else
    {
        Node<T>* temp;
	    temp = new Node<T>;
	    temp->data = input;
	    temp->link = NULL;
	    end->link = temp;
        end = temp;
    }	
}

template <class T>
T collection::queue::linked<T>::pop()
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
    catch(short const& e)
    {
        std::cerr << "Error " << e << ". Empty list!" << std::endl;
    }
    
    
}

#endif