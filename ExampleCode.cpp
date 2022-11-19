/********************************************************************************************/
/* Author: Shidlingayya(Siddu) G                                                            */
/* Description: Analog Devices assesement                                                   */
/* Compilition Envirnoment Details                                                          */
/* Compiler Used: Visual Studio 2019                                                        */
/* Standard Used: C++11                                                                     */
/********************************************************************************************/
#include <iostream>
#include <memory>
#include "singlyLinkedList.h"
#define MAX_LIST 6
int main()
{
    int data[MAX_LIST] = { 1,2,3,4,5,6 };
    std::unique_ptr<list> ptr = std::make_unique<list>();
    list* lst = nullptr;
    if (ptr->ListCreate(&lst, 6, data) == STATUS::SUCCESS)
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