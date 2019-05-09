#ifndef _LINKEDLIST_HPP_
#define _LINKEDLIST_HPP_
#include <cstddef>
#include <stdlib.h>

namespace collection
{
    namespace array
    {
        template <class T>
        struct Node
        {
            T data;
            Node<T>* link_next;
            Node<T>* link_previous;
        };

        template <class T>
        class linked
        {
        public:
            linked();
            ~linked();
            void index_back(T const&);
            T& operator[](size_t const&);
            void alloc(size_t const&);
            void dealloc(size_t const&);
            void dealloc();
        private:
            size_t size;
            Node<T>* head;
            Node<T>* end;
        };
    }
}
//-------------------------------------------------------------------------

template <class T>
collection::array::linked<T>::linked() : size(0)
{
    head = NULL;
    end = NULL;
}

template <class T>
collection::array::linked<T>::~linked()
{
    try
    {
        while (head != NULL)
        {
            Node<T>* next = head->link_next;
            if (next == NULL) throw -1;
            head = next;
            delete head->link_previous;
        }
    }
    catch(int const& e)
    {
        delete head;
        head = NULL;
        end = NULL;
    }
    
    
}


template <class T>
void collection::array::linked<T>::index_back(T const& input)
{
    if (head == NULL)
    {
        Node<T>* temp;
        temp = new Node<T>;
        temp->data = input;
        temp->link_next = NULL;
        temp->link_previous = head;
        head = temp;
        end = temp;
    }
    else
    {
        Node<T>* temp;
	    temp = new Node<T>;
	    temp->data = input;
	    temp->link_next = NULL;
        temp->link_previous = end;
	    end->link_next = temp;
        end = temp;
    }
    ++size;
}



template <class T>
T& collection::array::linked<T>::operator[](size_t const& index)
{
    const size_t kIndexMiddle = (size-1)/2;
    try
    {
        if (index < kIndexMiddle)
        {
            size_t count = 0;
            Node<T>* current = head;
            while (current != NULL)  
            {  
                if (count == index)
                {
                    return(current->data);
                }
                else if (current->link_next == NULL)
                {
                    throw -1;
                }   
                ++count;  
                current = current->link_next;  
            }
        }
        else
        {
            size_t count = size-1;
            Node<T>* current = end;
            while (current != NULL)  
            {  
                if (count == index)
                {
                    return(current->data);
                }
                else if (current->link_previous == head)
                {
                    throw -1;
                }   
                --count;  
                current = current->link_previous;  
            }
        }
    }
    catch(short const& e)
    {
        exit(1);
    }
}

template <class T>
void collection::array::linked<T>::alloc(size_t const& l)
{
    for (size_t i = 0; i < l; ++i)
    {
        if (head == NULL)
        {
            Node<T>* temp;
            temp = new Node<T>;
            temp->link_next = NULL;
            temp->link_previous = head;
            head = temp;
            end = temp;
        }
        else
        {
            Node<T>* temp;
            temp = new Node<T>;
            temp->link_next = NULL;
            temp->link_previous = end;
            end->link_next = temp;
            end = temp;
        }
        ++size;
    }
}


template <class T>
void collection::array::linked<T>::dealloc(size_t const& l)
{
    if (size)
    {
        size_t i = 0;
        while ((end != head) && (i < l))
        {
            Node<T>* temp = end->link_previous;
            delete end;
            end = temp;
            ++i;
        }
        --size;
    }
}

template <class T>
void collection::array::linked<T>::dealloc()
{
    if (size)
    {
        while (end != head)
        {
            Node<T>* temp = end->link_previous;
            delete end;
            end = temp;
        }
        delete end;
        end = NULL;
        head = NULL;
        --size;
    }
}


#endif