/********************************************************************************************/
/* File: main.cpp                                                           */
/* Description: Linked List Driver code to test functionality                               */
/* Compilition Envirnoment Details                                                          */
/* Compiler Used: Visual Studio 2019                                                        */
/* Standard Used: C++11                                                                     */
/********************************************************************************************/
#include <iostream>
#include <memory>
#include "singlyLinkedList.h"
#define MAX_ITEMS 6
int main()
{
    int data[MAX_ITEMS] = { 1,2,3,4,5,6 };
    std::unique_ptr<list> ptr = std::make_unique<list>();
    list* lst = nullptr;
    if (ptr->ListCreate(&lst, MAX_ITEMS, data) == STATUS::SUCCESS)
    {
        printf("After ListCreate:\n");
        ptr->ListDisplay(lst);
    }

    printf("Display in reverse:\n");
    ptr->ListDisplayReverse(lst);
    printf("\n");

    if (ptr->ListAddElem(lst, 7) == STATUS::SUCCESS)
    {
        printf("After ListAddElem:\n");
        ptr->ListDisplay(lst);
    }

    if (ptr->ListRemoveItem(lst, 4) == STATUS::SUCCESS)
    {
        printf("After ListRemoveItem:\n");
        ptr->ListDisplay(lst);
    }

    if (ptr->ListInsertBefore(lst, 5, 4) == STATUS::SUCCESS)
    {
        printf("After ListInsertBefore:\n");
        ptr->ListDisplay(lst);
    }
    return 0;
}