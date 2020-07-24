#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <string>
#include <iostream>

//Node data structure used by the linked list
struct Node
{
    Node* previous;
    Node* next;
    char data;

    Node();
    Node(char c);
};

class DoublyLinkedList
{
private:
    Node* m_head;
    Node* m_tail;
    int m_node_count;

public:
    DoublyLinkedList(); //default constructor
    DoublyLinkedList(const DoublyLinkedList& other); //copy constructor
    DoublyLinkedList(const std::string &data_string); //constructor with a specific string (provided)
    ~DoublyLinkedList(); //destructor

    //add to to the end of the list
    void append(char data);

    //add to the beginning of the list
    void prepend(char data);

    //add to the list
    void insert(int index, char data);

    //remove from the end of the list
    void removeLast();

    //remove from the beginning of the list
    void removeFirst();

    //remove from a specific position in the list
    void removeAt(int index);

    //remove all nodes from the linked list
    void clear();

    //get a value at a position in the linked list
    char get(int index) const;

    //modify a value at a position in the linked list
    void set(int index, char new_value);

    //find the first occurence of "search char" in the linked list and return its index position. Return -1 if the character is not found.
    int findFirstOf(char search_char) const;

    //find the last occurence of "search_char" in the linked list and return its index position. Return -1 if the character is not found.
    int findLastOf(char search_char) const;

    //deep copy assignment operator
    DoublyLinkedList& operator=(const DoublyLinkedList& other);
    //does the same thing as the get function
    char operator[](int index) const;
    //get the first node (head)
    Node* firstNode();
    //get last node (tail)
    Node* lastNode();
    //get the number of items in the list
    int getSize() const;
    //get the data in the linked list as a printable string
    std::string toString() const;
};

#endif // DOUBLYLINKEDLIST_H
