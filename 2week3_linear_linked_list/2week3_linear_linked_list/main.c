/*
Use the linear linked list code to store a randomly generated set of 100 integers.  
Now write a routine that will rearrange the list in sorted order of these values. Note you might want to use bubble sort to do this. 
Print these values in rows of 5 on the screen.
*/

#include "List.h"

#define size 100
inline int Random(int lower, int upper) { return (rand() % (upper - lower + 1)) + lower; }

int main(void) {
    node_t* head = NULL;
    srand(time(0));     // Use current time as seed for random generator 

    for (int i = 0; i < size; i++)
    {
        push(&head, i + Random(15, 600));
    }

    printList(head);
    
    bubbleSort(head);
    printf("\n\n");

    printList(head);
    
    return 0;
}

