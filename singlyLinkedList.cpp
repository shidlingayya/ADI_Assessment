#include <iostream>
#include <stack>
#include "singlyLinkedList.h"

list* list::getNewNode(int idata)
{
	list* newNode = new list();
	if (newNode)
	{
		newNode->data = idata;
		newNode->next = nullptr;
	}
	return newNode;
}

int list::CountTotalNodes(struct list* lst)
{
	int counter = 0;
	if (!lst)
	{
		return counter;
	}

	list* tmpNode = lst;
	while (tmpNode)
	{
		counter++;
		tmpNode = tmpNode->next;
	}
	return counter;	
}

int list::ListCreate(struct list** lst, int dataLen, int* data)
{
	for (auto i = 0; i < dataLen; i++)
	{
		list* newNode = getNewNode(data[i]);

		//list is empty
		if (*lst == nullptr)
		{
			*lst = newNode;
		}
		else
		{
			list* tmpNode = *lst;
			while (tmpNode->next != nullptr)
			{
				tmpNode = tmpNode->next;
			}
			tmpNode->next = newNode;
		}
	}
	return STATUS::SUCCESS;
}
int list::ListDisplay(list* lst)
{
	//Do not override head node
	list* tempNode = lst;
	if (tempNode == nullptr)
	{
		std::cout << "List is empty !!!" << std::endl;
		return STATUS::FAILURE;
	}

	while (tempNode != nullptr)
	{
		std::cout << tempNode->data << "->";
		tempNode = tempNode->next;
	}
	std::cout << std::endl;
	return STATUS::SUCCESS;
}
int list::ListDisplayReverse(struct list* lst)
{
	std::stack<list*> stack_list;
	if (lst == nullptr)
	{
		std::cout << "Attempted to reverse empty list!!!" << std::endl;
		return STATUS::FAILURE;
	}

	list* copy_of_node = lst;
	while (copy_of_node != nullptr)
	{
		stack_list.push(copy_of_node);
		copy_of_node = copy_of_node->next;
	}
	while (!stack_list.empty())
	{
		list* tmp = stack_list.top();
		std::cout << tmp->data << "->";
		stack_list.pop();
	}
	return STATUS::SUCCESS;
}

int list::ListAddElem(struct list* lst, int data)
{
	list* newNode = getNewNode(data);
	if (!newNode)
	{
		std::cout << "Unable to create new node!!!" << std::endl;
		return STATUS::FAILURE;
	}

	//if list empty already
	if (lst == nullptr)
	{
		lst = newNode;
	}
	else
	{
		list* tmpNode = lst;
		while (tmpNode->next != nullptr)
		{
			tmpNode = tmpNode->next;
		}
		tmpNode->next = newNode;
	}
	return STATUS::SUCCESS;
}

int list::ListRemoveItem(struct list* lst, int index)
{
	if (lst == nullptr)
	{
		std::cout << "Attempted to delete element from empty list" << std::endl;
		return STATUS::FAILURE;
	}

	list* prev = nullptr;
	list* tmpNode = lst;
	while (tmpNode != nullptr && index != 0)
	{
		prev = tmpNode;
		tmpNode = tmpNode->next;
		index--;
	}

	if (tmpNode == nullptr)
	{
		std::cout << "Node requested to delete not found";
		return STATUS::FAILURE;
	}
	else
	{
		if(prev && tmpNode)
		{ 
			prev->next = tmpNode->next;
			delete tmpNode;
		}
	}
	return STATUS::SUCCESS;
}
int list::ListInsertBefore(struct list* lst, int elem, int index)
{
	list *new_node = getNewNode(elem);
	if (index > CountTotalNodes(lst))
	{
		std::cout << "The number of nodes is less than index " << std::endl;
		return STATUS::FAILURE;
	}

	int counter = 0;
	list* prev = nullptr;
	list* tmpNode = lst;
	while (tmpNode != nullptr && index != counter)
	{
		prev = tmpNode;
		tmpNode = tmpNode->next;
		counter++;
	}

	if (prev && tmpNode)
	{
		prev->next = new_node;
		new_node->next = tmpNode;
	}
	return STATUS::SUCCESS;
}
