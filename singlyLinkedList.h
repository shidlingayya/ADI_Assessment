#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

enum STATUS
{
	SUCCESS = 0,
    FAILURE = -1
};

struct list
{
	list* getNewNode(int idata);
	int CountTotalNodes(struct list* lst);
	int ListCreate(struct list** lst, int dataLen, int* data);
	int ListDisplay(struct list* lst);
	int ListDisplayReverse(struct list* lst);
	int ListAddElem(struct list* lst, int data);
	int ListRemoveItem(struct list* lst, int index);
	int ListInsertBefore(struct list* lst, int elem, int index);
	int data;
	list* next;
	static const int SUCCESS = 0;
	static const int FAILURE = -1;
};

#endif
