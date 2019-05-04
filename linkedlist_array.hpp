#ifndef _LINKEDLIST_HPP_
#define _LINKEDLIST_HPP_
#include <cstddef>
#include <iostream>

namespace collection
{
    namespace array
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
            T& operator[](short const&) const;
        private:
            Node<T>* head;
            Node<T>* end;
        };
    }
}
//-------------------------------------------------------------------------

template <class T>
collection::array::linked<T>::linked()
{
    head = NULL;
    end = NULL;
}



template <class T>
void collection::array::linked<T>::push(T const& input)
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
T collection::array::linked<T>::pop()
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


template <class T>
T& collection::array::linked<T>::operator[](short const& index) const
{
    Node<T>* current = head;
    short count = 0;
    try
    {
        while (current != NULL)  
        {  
            if (count == index)
            {
                return(current->data);
            }
            else if (current->link == NULL)
            {
                throw -1;
            }   
            ++count;  
            current = current->link;  
        }
    }
    catch(short const& e)
    {
        std::cerr << "Out of bound!" << std::endl;
    }
    
    
}


#endif