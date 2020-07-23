#include "../Include/DoublyLinkedList.h"

//constructors for the linked list
DoublyLinkedList::DoublyLinkedList() //default constructor (empty list)
{
    m_head = nullptr;
    m_tail = nullptr;
    m_node_count = 0;
}

// Copy Constructor
DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& other) { (*this) = other; }

// constuctor w/ a string of chars
DoublyLinkedList::DoublyLinkedList(const std::string &data_string)
{
    if (data_string.size() == 0u)
    {
        m_head = m_tail = nullptr;
        m_node_count = 0;
    }
    else
    {
        std::string::size_type string_length, i;
        string_length = data_string.size();
        // Create the New Node
        m_head = new Node(data_string.at(0));
        m_tail = m_head;
        // Cycle Through and place in the letters
        for (i = 1; i < string_length; i++)
        {
            char character = data_string.at(i);
            Node* new_node = new Node(character);
            new_node->previous = m_tail;
            new_node->next = nullptr;
            m_tail->next = new_node;
            //assign this node as the new tail
            m_tail = new_node;
        }
        //make the list circular
        m_head->previous = m_tail;
        m_tail->next = m_head;
        //set the size correctly
        m_node_count = static_cast<int>(string_length);
    }
}

// Destructor
DoublyLinkedList::~DoublyLinkedList()
{
  Node* p = m_head;
  for(int i = 0; i < m_node_count; i++)
  {
      m_head = m_head -> next;
      delete p;
      p = m_head;
  }
}

//Add to to the end of the list
void DoublyLinkedList::append(char data)
{
     Node *tmp = new Node(data);
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

//Add to the beginning of the list
void DoublyLinkedList::prepend(char data)
{
    // create the new node
    Node *tmp = new Node(data);
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
void DoublyLinkedList::insert(int index, char data)
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
    Node *p = new Node(data);
    // create a Node ptr and point at head
    Node *temp;
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
void DoublyLinkedList::removeLast()
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
    Node* temp = m_tail;
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
void DoublyLinkedList::removeFirst()
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
    Node* temp;
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
void DoublyLinkedList::removeAt(int index)
{
    if(index == 0)
        this->removeFirst();
    else if (index == m_node_count)
        this->removeLast();
    else
    {
        // creat temp Node ptr
        Node* temp;
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
void DoublyLinkedList::clear()
{
    Node* p = m_head;
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
char DoublyLinkedList::get(int index) const
{
    // create a Node ptr & point to head
    Node *temp;
    temp = m_head;
    // find index in the list
    for(int i = 0; i < index; i++)
        temp = temp->next;
    // return the data
    return temp->data;
}

//Modify a value at a position in the linked list
void DoublyLinkedList::set(int index, char new_value)
{
    // create a Node ptr & point to head
    Node *temp;
    temp = m_head;
    // find index in the Node
    for(int i = 0; i < index; i++)
        temp = temp->next;
    // put data into the Node
    temp->data = new_value;
}

//Find the first occurence of "search char" in the linked list and return its position. Return -1 if the character is not found.
int DoublyLinkedList::findFirstOf(char search_char) const
{
     int index = 0;
     Node *temp;
     temp = m_head;

    for(int i = 0; i < m_node_count; i++)
    {
        if(temp->data == search_char)
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
int DoublyLinkedList::findLastOf(char search_char) const
{
    int index = m_node_count - 1;
    Node *temp;
    temp = m_tail;
    for(int i = index; i >= 0; i--)
    {
        if(temp->data == search_char)
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
DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList& other)
{
    clear();
    if (other.m_node_count > 0)
    {
        Node* o_current, *t_current;
        m_head = new Node(other.m_head->data);
        t_current = m_head;
        o_current = other.m_head->next;
        for (int i = 1; i < other.m_node_count; i++)
        {
            t_current->next = new Node(o_current->data);
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
char DoublyLinkedList::operator[](int index) const { return get(index); }

// Return First Node
Node *DoublyLinkedList::firstNode() { return m_head; }

// Return last node
Node *DoublyLinkedList::lastNode() { return m_tail; }

// Return Size
int DoublyLinkedList::getSize() const { return m_node_count; }

std::string DoublyLinkedList::toString() const
{
    std::string str;
    if (m_head != nullptr)
    {
        Node* current = m_head;
        str.reserve(static_cast<std::string::size_type>(m_node_count));
        for (int i = 0; i < m_node_count; i++)
        {
            str.push_back(current->data);
            current = current->next; //move to the next node
        }
    }
    return str;
}

//Node constructors
Node::Node() :previous(nullptr), next(nullptr), data('0') {}

Node::Node(char c) :previous(nullptr), next(nullptr), data(c) {}
