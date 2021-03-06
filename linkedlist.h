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



void insert_list(LinkedList * list, LinkedListNode * node)
{
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

LinkedListNode * Get_Linked_List_Node(LinkedList * list, int pos)
{
    LinkedListNode * currentNode = list->head;
    if(currentNode == NULL) return NULL;

    while( --pos > 0 && (currentNode = currentNode->next) != NULL);

    return currentNode;
}

LinkedList * Clone_Linked_List(LinkedList * list)
{
    LinkedList * clone = NULL;
    initializer_list(clone);

    LinkedListNode * currentNode = list->head;

    if(currentNode == NULL) return clone;

    do
    {
        insert_list(clone, currentNode);
    }while((currentNode = currentNode->next) != NULL );

    return clone;
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

LinkedList * merge_list(LinkedList * list, LinkedList * anotherList)
{
    LinkedList * m = new LinkedList();
    initializer_list(m);

    LinkedListNode * head = list->head;
    LinkedListNode * anotherHead = anotherList->head;

    while(head != NULL && anotherHead != NULL)
    {
        int v1 = head->data;
        int v2 = anotherHead->data;

        if( v1 < v2)
         {
             insert_list(m, v1);
             head = head->next;
         }
        else{
            anotherHead = anotherHead->next;
            insert_list(m, v2);
        }
    }

    while(head != NULL)
    {
        insert_list(m, head->data);
        head = head->next;
    }

    while(anotherHead != NULL)

    {
        insert_list(m, anotherHead->data);
        anotherHead = anotherHead->next;
    }

    return m;
}


LinkedListNode * Get_First_Common_Node(LinkedListNode * node_l1, LinkedListNode * node_l2)
{
    if(node_l1 == NULL || node_l2 == NULL) return NULL;

    if( node_l1->next == NULL && node_l2->next == NULL)
    {
        if(node_l1 == node_l2) return node_l1;

        return NULL;
    }

    LinkedListNode * nextL1Node = node_l1->next == NULL ? node_l1 : node_l1->next;
    LinkedListNode * nextL2Node = node_l2->next == NULL ? node_l2 : node_l2->next;

    LinkedListNode * crossed_node = NULL;

    crossed_node = Get_First_Common_Node(nextL1Node, nextL2Node);

    if(crossed_node != NULL)
    {
        if(node_l1 != node_l2)
            return crossed_node;
        else
            return node_l1;
    }

    return NULL;
}



#endif // LINKEDLIST_H_INCLUDED
