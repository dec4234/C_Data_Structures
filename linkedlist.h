#include "stdlib.h"

typedef struct Node
{
    int data;
    struct Node* next;
}
Node;

Node* new(int data)
{
    Node* n = malloc(sizeof(Node));

    n->data = data;
    n->next = NULL;

    return n;
}

Node* addDataToEnd(Node* list, int data)
{
    for(Node* temp = list; temp != NULL; temp = temp->next)
    {
        if(temp->next == NULL)
        {
            temp->next = new(data);
            return temp->next;
        }
    }

    return NULL;
}

Node* last(Node* list)
{
    for(Node* temp = list; temp != NULL; temp = temp->next)
    {
        if(temp->next == NULL)
        {
            return temp;
        }
    }
}

Node* removeNode(Node* list, Node* toRemove)
{
    if(list == toRemove)
    {
        Node* next = list->next; // Switch the head of the list to the 2nd Node if the removed node is the current head
        free(list);
        return next;
    }

    Node* prev = NULL;
    for(Node* temp = list; temp != NULL; temp = temp->next)
    {
        if(temp == toRemove)
        {
            prev->next = temp->next; // Connect Node 1 to Node 3, bypassing Node 2
            free(toRemove); // This is the final place where we can access the toRemove node, so remove it here
            return list;
        }

        prev = temp;
    }
}

void freeLinkedList()
{

}

int size(Node* head)
{
    int i = 0;

    for(Node* temp = head; temp != NULL; temp = temp->next)
    {
        i++;
    }

    return i;
}

void printAll(Node* head) {
    for(Node* temp = head; temp != NULL; temp = temp->next)
    {
        printf("%i\n", temp->data);
    }
}

void linkedlisttest()
{
    Node* n = new(1);
    addDataToEnd(n, 6);
    addDataToEnd(n, 5);

    printAll(n);

    // printf("%i\n", last(n)->data);

    n = removeNode(n, n->next); // Remove the Node containing "6"
    printAll(n);

}