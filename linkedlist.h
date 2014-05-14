#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include "stdio.h"

struct LinkedListNode
{
    LinkedListNode * next;
    int data;
};

struct LinkedList
{
    LinkedListNode * head;
};

void initializer_list(LinkedList *& list)
{
    list = new LinkedList();
    list->head = NULL;
}

int list_size(LinkedList * list)
{
    int count = 0;
    LinkedListNode * currentNode = list->head;
    while(currentNode != NULL)
    {
        count++;
        currentNode = currentNode->next;
    }

    return count;
}

void parse_list(LinkedList * list)
{
    LinkedListNode * currentNode = list->head;
    int index = 0;
    while(currentNode != NULL)
    {
        printf("the %d node data is %d\r\n", ++index, currentNode->data);
        currentNode = currentNode->next;
    }
}
void insert_list(LinkedList * list, int data)
{
    LinkedListNode * node = new LinkedListNode();
    node->data = data;
    node->next = NULL;

    LinkedListNode * currentNode = list->head;
    if(currentNode == NULL) list->head = node;
    else{
        while(currentNode->next != NULL)
        {
            currentNode = currentNode->next;
        }
        currentNode->next = node;
    }
}

LinkedListNode * recursive_reverse_list(LinkedListNode * prev, LinkedListNode * node)
{
    LinkedListNode * head = NULL;
    if(node->next == NULL)
    {
        head = node;
        node->next = prev;
        return head;
    }

    head = recursive_reverse_list(node, node->next);

    node->next = prev;

    return head;
}


LinkedListNode * recursive_reverse_list2(LinkedListNode * node)
{
    LinkedListNode * head = NULL;
    if(node->next == NULL)
    {
        head = node;
        return head;
    }

    head = recursive_reverse_list2(node->next);

    node->next->next = node;
    node->next = NULL;

    return head;
}


void reverse_list(LinkedList * list)
{
    LinkedListNode * previousNode = list->head;
    if(previousNode == NULL) return;

    LinkedListNode * headNode = list->head;

    LinkedListNode * currentNode = previousNode->next;
    LinkedListNode * nextNode = NULL;
    while(currentNode != NULL)
    {
        LinkedListNode * nextNode = currentNode->next;

        currentNode->next = previousNode;

        previousNode = currentNode;

        currentNode = nextNode;
    }

    list->head = previousNode;
    headNode->next = NULL;
}

void clear_list(LinkedList * list)
{
    LinkedListNode * currentNode = list->head;
    while(currentNode != NULL)
    {
        LinkedListNode * tempNode = currentNode;
        currentNode = currentNode->next;
        delete tempNode;
    }

    list->head = NULL;
}

#endif // LINKEDLIST_H_INCLUDED
