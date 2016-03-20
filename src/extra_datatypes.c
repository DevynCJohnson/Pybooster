// -*- coding: utf-8 -*-
// vim:fileencoding=utf-8
/**
@file extra_datatypes.c
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@brief Additional datatypes, such as FILO-Stack, Queue (FIFO Stack), etc.
@version 2016.03.20

@section DESCRIPTION
Additional datatypes such as -
 - Syscall Enums for Various Operating Systems
 - Light-weight queue datatype (FIFO Stack)
 - Light-weight FILO stack datatype
 - Light-weight linked-stack datatype (dynamically growing/shrinking FILO Stack)
 - and more

@section LICENSE
GNU Lesser General Public License v3
Copyright (c) Devyn Collier Johnson, All rights reserved.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 3.0 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library.
*/


#include "extra_datatypes.h"


/* SYSCALL ENUM CONSTANTS */


/** Syscalls enum for Bell-Lab's Plan 9 operating system */
enum PLAN9_SYSCALLS {
    SYSR1 = 0,
    _ERRSTR = 1,
    BIND = 2,
    CHDIR = 3,
    CLOSE = 4,
    DUP = 5,
    ALARM = 6,
    EXEC = 7,
    EXITS = 8,
    _FSESSION = 9,
    FAUTH = 10,
    _FSTAT = 11,
    SEGBRK = 12,
    _MOUNT = 13,
    OPEN = 14,
    _READ = 15,
    OSEEK = 16,
    SLEEP = 17,
    _STAT = 18,
    RFORK = 19,
    _WRITE = 20,
    PIPE = 21,
    CREATE = 22,
    FD2PATH = 23,
    BRK_ = 24,
    REMOVE = 25,
    _WSTAT = 26,
    _FWSTAT = 27,
    NOTIFY = 28,
    NOTED = 29,
    SEGATTACH = 30,
    SEGDETACH = 31,
    SEGFREE = 32,
    SEGFLUSH = 33,
    RENDEZVOUS = 34,
    UNMOUNT = 35,
    _WAIT = 36,
    SEMACQUIRE = 37,
    SEMRELEASE = 38,
    SEEK = 39,
    FVERSION = 40,
    ERRSTR = 41,
    STAT = 42,
    FSTAT = 43,
    WSTAT = 44,
    FWSTAT = 45,
    MOUNT = 46,
    AWAIT = 47,
    PREAD = 50,
    PWRITE = 51,
    TSEMACQUIRE = 52,
};


#ifndef NO_DYNAMIC_DATATYPES


/* LINKED-STACK FUNCTIONS */


/**
    Push an element into stack; return NULL on error\n
    Usage: head = push_linked_stack(head, element);
*/
linked_stack_node_t *push_linked_stack(linked_stack_node_t *head, const uint64_t data) {
    linked_stack_node_t *tmp = (linked_stack_node_t *)calloc(0x01, sizeof(linked_stack_node_t));
    if (tmp == (linked_stack_node_t *)NULL) { free(tmp); return NULL; }
    tmp->data = data;
    tmp->next = head;
    head = tmp;
    return head;
}


/** Pop an element from the stack; Usage: head = pop_linked_stack(head, &element); */
linked_stack_node_t *pop_linked_stack(linked_stack_node_t *head, uint64_t *element) {
    linked_stack_node_t *tmp = head;
    *element = head->data;
    head = head->next;
    free(tmp);
    return head;
}


/* DISPLAY FUNCTIONS */


/**
    Display stack content\n
    Usage: display_stack(stack, &top);
*/
void display_stack(const int *__restrict__ s, const int *__restrict__ top) {
    puts("Stack: ");
    register int i;
    for(i = 0x00; i < *top; i++) { printf("%i ", s[i]); }
    puts("\n");
}


/**
    Display the stack content\n
    Usage: display_linked_stack(head);
*/
void display_linked_stack(linked_stack_node_t *head) {
    linked_stack_node_t *current;
    current = head;
    if (current != (linked_stack_node_t *)NULL) {
        puts("Stack: ");
        do {
            printf("%"PRIu64" ", current->data);
            current = current->next;
        } while (current != (linked_stack_node_t *)NULL);
        puts("\n");
    }
    else { puts("The Stack is empty\n"); }
}


/**
    Display queue content\n
    Usage: display_queue(queue, head, tail);
*/
void display_queue(const int *__restrict__ q, const int head, const int tail) {
    puts("Queue: ");
    register int i = tail;
    while (i >= head) {
        printf("%i ", q[--i]);
        if (i >= head || i == 0) { break; }
    }
    puts("\n");
}


/* BINARY-HEAP FUNCTIONS */


/**
    Binary Heap Datatype\n
    Initialze a binary heap\n
    Usage: PriorityQueue H; init_heap(MAXSIZE);
*/
PriorityQueue init_heap(size_t MaxElements) {
    PriorityQueue H;
    if (MaxElements < 10) { return NULL; }  // Is MaxElements less than the minimum priority queue
    H = calloc(0x1, sizeof(binary_heap_t));
    if (H == NULL) { return NULL; }
    H->Elements = calloc((size_t)(MaxElements + 0x1), sizeof(ElementType));
    if (H->Elements == NULL) { return NULL; }
    H->Capacity = MaxElements;
    H->Size = 0x0;
    H->Elements[0] = -32767;  // H->Element[0] is a sentinel
    return H;
}


/**
    Insert data into the heap;\n
    Usage: heapinsert(X, H);
*/
void heapinsert(ElementType X, PriorityQueue H) {
    if (!isheapfull(H)) {
        register size_t i;
        for (i = ++H->Size; H->Elements[i / 0x2] > X; i /= 0x2) {
            H->Elements[i] = H->Elements[i / 0x2];
        }
        H->Elements[i] = X;
    }
}


/** Remove smallest element from binary-heap */
ElementType deletemin_heap(PriorityQueue H) {
    ElementType MinElement, LastElement;
    if (isheapempty(H)) { return H->Elements[0x0]; }
    MinElement = H->Elements[0x1];
    LastElement = H->Elements[H->Size--];
    register size_t i, Child;
    for (i = 0x1; (i * 0x2) <= H->Size; i = Child) {  // Find smaller child
        Child = (i * 0x2);
        if (Child != (H->Size) && ((H->Elements[Child + 0x1]) < (H->Elements[Child])))
            Child++;
        // Percolate one level
        if (LastElement > (H->Elements[Child])) H->Elements[i] = H->Elements[Child];
        else break;
    }
    H->Elements[i] = LastElement;
    return MinElement;
}


/** Return smallest element */
ElementType findmin_heap(PriorityQueue H) {
    if (!isheapempty(H)) { return H->Elements[1]; }
    return H->Elements[0x00];
}


#endif
