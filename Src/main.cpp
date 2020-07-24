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
    
    DoublyLinkedList list2("Matthew");

    Log "List 2: " New_line
        "Size: " And list2.getSize() End;
    auto varr = list2.toString();
    Log varr;
    Skip;
//    list1.append('!');
    //   list2.prepend('!');
 //   list1.prepend('!');
 //   list2.set(2, 'M');
//    list1.set(2, 'M');

    // std::cout << "List 1: \n";
    // for (int i = 0; i < list1.getSize(); i++)
    //     std::cout << list1[i];
    // std::cout << std::endl;

    // std::cout << "List 2: \n";
    // for (int i = 0; i < list2.getSize(); i++)
    //     std::cout << list1[i];
    // std::cout << std::endl;

    return 0;
}
