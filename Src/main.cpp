#include <iostream>
#include "../lib/CDLL/Include/DoublyLinkedList.h"

// Personal Logging Macros -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
#define Log std::cout <<
#define And <<
#define End << "\n"
#define Skip std::cout << "\n"
#define New_line << "\n" <<
#define Get std::cin >>
#define AAnd >>

int main()
{
    // DoublyLinkedList<char> list;
    // list.append('p');
    // list.append('p');
    // list.append('p');
    // list.append('p');
    // list.append('p');
    // list.append('p');
    // DoublyLinkedList<char> list2;
    // list2 = list;
    // auto word = list2.toString();
    // Log word End;

    DoublyLinkedList<int> list3;
    for(int i = 0; i < 10; i++)
    {
        list3.append(i);
    }
    DoublyLinkedList<int> list4(list3);
    // Log "Old " And list4.getSize() End;
    // list4 = list3;
    // Log "New " And list4.getSize() End;
    for(int i = 0; i < list4.getSize(); i++)
    {
        Log list4[i] End;
    }

    return 0;
}
