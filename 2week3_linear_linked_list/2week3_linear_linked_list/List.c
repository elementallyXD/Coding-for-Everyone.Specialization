#include "List.h"

/* A utility function to insert a node at the beginning of linked list */
void push(node_t** head_ref, int new_data)
{
    /* allocate node */
    node_t* new_node = (node_t*)malloc(sizeof(node_t));

    /* put in the data  */
    new_node->data = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

/* Function to print linked list */
void printList(node_t* head)
{
    node_t* temp = head;
    int i = 0;
    while (temp != NULL)
    {
        if ((i++ % 5) == 0) {
            printf("\n");
        }

        printf("%d \t", temp->data);
        temp = temp->next;
    }
}

/* Bubble sort the given linked list */
void bubbleSort(node_t* start)
{
    int swapped, i;
    node_t* ptr1;
    node_t* lptr = NULL;

    /* Checking for empty list */
    if (start == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

/* function to swap data of two nodes a and b*/
void swap(node_t* a, node_t* b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}