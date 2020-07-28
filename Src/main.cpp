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
    DoublyLinkedList<int> int_list;
    auto var = int_list.firstNode();
    return 0;
}
