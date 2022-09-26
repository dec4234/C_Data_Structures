#include "stdlib.h"

typedef struct Node {
    int data;
    struct Node *next;
}
Node;

Node *new(int data) {
    Node *n = malloc(sizeof(Node));

    n->data = data;
    n->next = NULL;

    return n;
}

Node *addDataToEnd(Node *list, int data) {
    for (Node *temp = list; temp != NULL; temp = temp->next) {
        if (temp->next == NULL) {
            temp->next = new(data);
            return temp->next;
        }
    }

    return NULL;
}

Node *last(Node *list) {
    for (Node *temp = list; temp != NULL; temp = temp->next) {
        if (temp->next == NULL) {
            return temp;
        }
    }
}

/**
 * Remove a Node from the list
 * @param list The head of the list which contains the node to be removed
 * @param toRemove The node to be removed from the list
 * @return The head of the list post-removal, as the head node MIGHT have been removed
 */
Node *removeNode(Node *list, Node *toRemove) {
    if (list == toRemove) {
        Node *next = list->next; // Switch the head of the list to the 2nd Node if the removed node is the current head
        free(list);
        return next;
    }

    Node *prev = NULL;
    for (Node *temp = list; temp != NULL; temp = temp->next) {
        if (temp == toRemove) {
            prev->next = temp->next; // Connect Node 1 to Node 3, bypassing Node 2
            free(toRemove); // This is the final place where we can access the toRemove node, so free it here
            return list;
        }

        prev = temp;
    }

    return list;
}

/**
 * The size of the list
 * O(n) complexity
 * @param head The head of the list that you want to know the size of
 * @return Size of the list
 */
int size(Node *head) {
    int i = 0;

    for (Node *temp = head; temp != NULL; temp = temp->next) {
        i++;
    }

    return i;
}

/**
 * Frees the entire linked list starting with the last node
 * @param head The head of the list that you want to free
 */
void freeLinkedList(Node *head) {
    while (head != NULL) {
        Node *prev = head;

        for (Node *inner = head; inner != NULL; inner = inner->next) {
            if (inner->next == NULL) {
                prev->next = NULL;
                if(head == inner) {
                    head = NULL; // Indicates that the entire list has been freed
                }

                free(inner);
                break;
            } else {
                prev = inner;
            }
        }
    }
}

void printAll(Node *head) {
    for (Node *temp = head; temp != NULL; temp = temp->next) {
        printf("%i\n", temp->data);
    }
}

void linkedlisttest() {
    Node *n = new(1);
    addDataToEnd(n, 6);
    addDataToEnd(n, 5);

    printf("Size: %i", size(n)); // Returns i * 10 + 1 ????
    printAll(n);


    // printf("%i\n", last(n)->data);

    n = removeNode(n, n->next); // Remove the Node containing "6"
    printAll(n);
    freeLinkedList(n);

}