#pragma once
#include <c++/7/bits/c++config.h>
#include <string>
#include <iostream>

//Node data structure used by the linked list
template <typename Type>
struct Node
{
    Node<Type>* previous;
    Node<Type>* next;
    Type data;

    
    //Node constructors
    Node() 
    :previous(nullptr), next(nullptr), data() {}

    Node(Type m_data) 
    :previous(nullptr), next(nullptr), data(m_data) {}

};

template <typename _Type>
class DoublyLinkedList
{
private:
    Node<_Type>* m_head;
    Node<_Type>* m_tail;
    unsigned int m_node_count;

public:
    //constructors for the linked list -----------------------------------------------------------

    // Default
    DoublyLinkedList()
    {
        m_head = nullptr;
        m_tail = nullptr;
        m_node_count = 0;
    }

    // Copy Constructor
    DoublyLinkedList(const DoublyLinkedList<_Type>& other) { (*this) = other; }

    // constuctor w/ data
    DoublyLinkedList(const _Type& m_data)
    {
        Node<_Type>* node = new Node<_Type>(m_data);
        m_head = node;
        m_tail = node;
        //make the list circular
        m_head->previous = m_tail;
        m_tail->next = m_head;
        //set the size correctly
        m_node_count = 1;
    }

    // Destructor
    ~DoublyLinkedList()
    {
      Node<_Type>* p = m_head;
      for(int i = 0; i < m_node_count; i++)
      {
          m_head = m_head->next;
          delete p;
          p = m_head;
      }
    }

    //add to to the end of the list
    void append(_Type data)
    {
        Node<_Type>*tmp = new Node<_Type>(data);
        // list empty?
        if (! m_head)
        {
            m_head = tmp;
            m_tail = tmp;
            m_head->previous = m_tail;
            m_tail->next = m_head;
            m_node_count++;
        }
        else
        {
            m_tail->next = tmp;
            m_tail->next->previous = m_tail;
            m_tail = tmp;
            m_tail->next = m_head;
            m_head->previous = m_tail;
            m_node_count++;
        }
    }

    //add to the beginning of the list
    void prepend(_Type data)
    {
        // create the new node
        Node<_Type>*tmp = new Node<_Type>(data);
        // check if list empty
        if (! m_head)
        {
            m_head = tmp;
            m_tail = tmp;
            m_head->previous = m_tail;
            m_tail->next = m_head;
            m_node_count++;
        }
        else
        {
            tmp->next = m_head;
            m_head->previous = tmp;
            m_head = tmp;
            m_tail->next = m_head;
            m_head->previous = m_tail;
            m_node_count++;
        }
    }

    //Add to the middle of the list (index = 0) means insert at the beginning of the list
    void insert(int index, _Type data)
    {
        // if index is out of reach
        if(index >= m_node_count)
        {
            std::cout << "Out of Range \n";
            return;
        }

        // if index is front of list
        if( index == 0)
        {
            this->prepend(data);
            return;
        }
        // create new Node
        Node<_Type>*p = new Node<_Type>(data);
        // create a Node ptr and point at head
        Node<_Type>*temp;
        temp = m_head;
        // move through list till you reach index
        int counter = 0;
        while(counter != index - 1)
        {
            temp = temp->next;
            counter++;
        }
        // switch previus pointer of the Node in front of temp to p
        temp->next->previous = p;
        // connect p prev ptr to temp Node
        p->previous = temp;
        // connect p nxt ptr to Node in front of temp
        p->next = temp->next;
        // point temp nxt ptr to p
        temp->next = p;

        //increase node count
        m_node_count++;
    }

    
    //Remove from the end of the list
    void removeLast()
    {
        if(m_node_count == 1)
        {
            delete m_head;
            m_head = nullptr;
            m_tail = nullptr;
            m_node_count = 0;
            return;
        }
        // create temp node
        Node<_Type>* temp = m_tail;
        // switch head prev prt to new tail
        m_head->previous = m_tail->previous;
        // move tail ptr to prev local
        m_tail = m_tail->previous;
        // move new tails nxt ptr to head
        m_tail->next = m_head;
        // delete temp
        delete temp;
        // decrease size
        m_node_count--;
    }

    //Remove from the beginning of the list
    void removeFirst()
    {
        if(m_node_count == 1)
        {
            delete m_head;
            m_head = nullptr;
            m_tail = nullptr;
            m_node_count = 0;
            return;
        }
        // create temp node ptr
        Node<_Type>* temp;
        temp = m_head;
        // switch tail next ptr to new local
        m_tail->next = m_head->next;
        // switch head ptr to new local
        m_head = m_head->next;
        // switch new heads prev ptr to tail
        m_head->previous = m_tail;
        // delete old head
        delete temp;
        // decrease size
        m_node_count--;
    }

    //Remove from a specific position in the list
    void removeAt(int index)
    {
        if(index == 0)
            this->removeFirst();
        else if (index == m_node_count)
            this->removeLast();
        else
        {
            // creat temp Node ptr
            Node<_Type>* temp;
            temp = m_head;
            // find local based on index
            for(int i = 0; i < index; i++)
            {
                temp = temp->next;
            }
            // switch prev prt
            temp->next->previous = temp->previous;
            // switch next ptr
            temp->previous->next = temp->next;
            // delete Node
            delete temp;
            // decrease node count
            m_node_count--;
        }
    }

    //Remove all nodes from the linked list
    void clear()
    {
        Node<_Type>* p = m_head;
        for(int i = 0; i < m_node_count; i++)
        {
            m_head = m_head -> next;
            delete p;
            p = m_head;
        }
        // point head and tail ptr to null
        m_head = nullptr;
        m_tail = nullptr;
        m_node_count = 0;
    }

    //Get a value at a position in the linked list
    _Type get(int index) const
    {
        // create a Node ptr & point to head
        Node<_Type>*temp;
        temp = m_head;
        // find index in the list
        for(int i = 0; i < index; i++)
            temp = temp->next;
        // return the data
        return temp->data;
    }

    //Modify a value at a position in the linked list
    void set(int index, _Type new_value)
    {
        // create a Node ptr & point to head
        Node<_Type>*temp;
        temp = m_head;
        // find index in the Node
        for(int i = 0; i < index; i++)
            temp = temp->next;
        // put data into the Node
        temp->data = new_value;
    }

    //Find the first occurence of "search char" in the linked list and return its position. Return -1 if the character is not found.
    int findFirstOf(const _Type& search) const
    {
        int index = 0;
        Node<_Type>*temp;
        temp = m_head;

        for(int i = 0; i < m_node_count; i++)
        {
            if(temp->data == search)
                return index;
            else
            {
                temp = temp->next;
                index++;
            }
        }
        return -1;
    }

    //Find the last occurence of "search_char" in the linked list and return its position. Return -1 if the character is not found.
    int findLastOf(char search) const
    {
        int index = m_node_count - 1;
        Node<_Type>*temp;
        temp = m_tail;
        for(int i = index; i >= 0; i--)
        {
            if(temp->data == search)
                return index;
            else
            {
                temp = temp->previous;
                index--;
            }
        }
        return -1;
    }

    // Overload the = operator
    DoublyLinkedList<_Type>& operator=(const DoublyLinkedList<_Type>& other)
    {
        clear();
        if (other.m_node_count > 0)
        {
            Node<_Type>* o_current, *t_current;
            m_head = new Node<_Type>(other.m_head->data);
            t_current = m_head;
            o_current = other.m_head->next;
            for (int i = 1; i < other.m_node_count; i++)
            {
                t_current->next = new Node<_Type>(o_current->data);
                t_current->next->previous = t_current;
                o_current = o_current->next;
                t_current = t_current->next;
            }
            m_tail = t_current;
            m_head->previous = m_tail;
            m_tail->next = m_head;
        }
        return (*this);
    }

    // Overload [] operators
    _Type operator[](int index) const { return get(index); }

    // Return First Node
    Node<_Type>* firstNode() { return m_head; }

    // Return last node
    Node<_Type>* lastNode() { return m_tail; }

    // Return Size
    int getSize() const { return m_node_count; }

};

