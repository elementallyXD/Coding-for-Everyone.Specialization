#pragma once
#include <stdlib.h> 
#include <stdio.h>

typedef struct Node {
    int data;
    struct Node* next;
}node_t;

void push(node_t** head_ref, int new_data);
void printList(node_t* head);
void bubbleSort(node_t* start);
void swap(node_t* a, node_t* b);