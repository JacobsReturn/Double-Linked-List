#include <iostream>
#include "LinkedList.h"

int main()
{
    /*
    
    LinkedList myList;
    myList.PushBack(20);
    myList.PushFront(20);
    myList.PushBack(30);
    myList.PushBack(21);
    myList.Sort();
    myList.InsertAtIndex(2, 30); // 30 should be at the 'third' (index 2) position in the list
    
    myList.PrintAllNodes(); // internially loops through each node and prints the value
    std::cout << myList.Count() << std::endl; // shoudl tell us how many items are in the list

    myList.PopBack(); // removes the last item
    myList.PopFront(); // removes the first item

    std::cout << myList.First() << std::endl; // prints the value of the first node
    std::cout << myList.Back() << std::endl; // prints the value of the last node

    myList.RemoveAtIndex(1); // removes the node at index 1 from the list

    myList.PrintAllNodes(); // internially loops through each node and prints the value
    std::cout << myList.Count() << std::endl; // shoudl tell us how many items are in the list



    */

    LinkedList* list = new LinkedList();

    list->PushBack(1);
    list->PushBack(67);
    list->PushFront(100);
    list->PopFront();

    list->PushBack(13);
    list->PushBack(86);
    list->PushBack(19);
    list->PushFront(19);

    //list->InsertAtIndex(4, 69);

    /*list->ForEach([](int& value) {
        std::cout << value << ", ";
     });*/

    list->PrintTree();
    list->Sort();

    list->RemoveAtIndex(4);

    list->PrintTree();

    list->Sort();
    list->PrintTree();
}
