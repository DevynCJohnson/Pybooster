// -*- coding: utf-8 -*-
// vim:fileencoding=utf-8
/**
@file extra_datatypes.h
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@brief Additional datatypes, such as FILO-Stack, Queue (FIFO Stack), etc. (header)
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


#ifndef EXTRA_DATATYPES_INCLUDED
#define EXTRA_DATATYPES_INCLUDED


#include "MACROS.h"


/* GPIO DATATYPES FOR EMBEDDED SYSTEMS */


typedef struct {
    uint8_t block;
    uint8_t port;
    uint16_t bit;
} GPIO_Pin_t;


typedef enum {
    GPIO_Input = 0,
    GPIO_Output = 1
} GPIO_Direction_t;


typedef enum {
    GPIO_LineLevel_Low = 0,
    GPIO_LineLevel_High = 1,
    GPIO_LineLevel_Error = 2
} GPIO_LineLevel_t;


typedef enum {
    GPIO_NoPull = 0,
    GPIO_PullUp = 1,
    GPIO_PullDown = 2,
    GPIO_PullUpDown = 3
} GPIO_PullUpDown_t;


typedef enum {
    GPIO_OutputType_PP = 0,
    GPIO_OutputType_OD = 1
} GPIO_OutputType_t;


typedef enum {
    GPIO_RiseTime_Shortest = 0,
    GPIO_RiseTime_Moderate = 1,
    GPIO_RiseTime_Longest = 2
} GPIO_RiseTime_t;


typedef struct {
    GPIO_Pin_t pin;
    GPIO_Direction_t direction;
    GPIO_LineLevel_t initLineLevel;
    GPIO_PullUpDown_t pull;
    GPIO_OutputType_t outputType;
    GPIO_RiseTime_t riseTime;
} GPIO_PinInitStruct_t;


/** Sets an already registered pin up with an entire new init profile */
typedef struct {
    _Bool(*reconfig)(GPIO_PinInitStruct_t *initStruct);
    _Bool(*setPinDirection)(int16_t pinIndex, GPIO_Direction_t dir);
    GPIO_Direction_t(*getPinDirection)(int16_t pinIndex);
    _Bool(*setLineLevel)(int16_t pinIndex, GPIO_LineLevel_t level);
    GPIO_LineLevel_t(*getLineLevel)(int16_t pinIndex);
    _Bool(*setPull)(int16_t pinIndex, GPIO_PullUpDown_t pull);
    GPIO_PullUpDown_t(*getPull)(int16_t pinIndex);
    _Bool(*setOutputType)(int16_t pinIndex, GPIO_OutputType_t outputType);
    GPIO_OutputType_t(*getOutputType)(int16_t pinIndex);
    _Bool(*setRiseTime)(int16_t pinIndex, GPIO_RiseTime_t riseTime);
    GPIO_RiseTime_t(*getRiseTime)(int16_t pinIndex);
} GPIO_PinControlInterface_t;


/** Registers an external GPIO block, registers an entry in the pin database, and Encapsulates pin control functions */
typedef struct {
    int8_t(*registerExternGpioBlock)(GPIO_PinControlInterface_t *controlInterface);
    int16_t(*registerPin)(GPIO_PinInitStruct_t *initStruct);
    GPIO_PinControlInterface_t ctrl;
} GPIO_ControlInterface_t;


/* DATATYPES FOR EMBEDDED SYSTEMS */


/** I2C datatype for embedded systems */
typedef struct {
  _Bool(*readBytes)(uint8_t addr, char *buf, uint16_t numBytes, _Bool stop);
  _Bool(*writeBytes)(uint8_t addr, char *buf, uint16_t numBytes, _Bool stop);
} I2CDriver_t;


/** USART datatype for embedded systems */
typedef struct {
    uint16_t(*writeBytes)(const char *bytes, uint16_t numBytes);
    uint16_t(*writeLine)(const char *dataline);
    uint16_t(*rxBytesAvailable)(void);
    uint16_t(*readBytes)(char *buf, uint16_t numBytes);
    uint16_t(*readLine)(char *buf);
    uint16_t(*readLineTruncate)(char *buf, uint16_t maxLen);
} USARTDriver_t;


/** IOStream datatype for embedded systems */
typedef struct {
/**
    @brief   Write a specified number of bytes to the stream.
    @param   bytes     [in]  The input buffer.
    @param   numBytes  [in]  The number of bytes to write.
    @return  The number of bytes written to the stream.
*/
    uint16_t(*writeBytes)(const char *bytes, uint16_t numBytes);
/**
    @brief   Write a line to the stream. Line ending characters (determined by the implementation function) will be appended.
    @param   line       [in]   Pointer to the start of a NULL-terminated string containing the text to be written. Line ending characters will be added and so are not required.
    @return  The number of bytes written to the stream.
*/
    uint16_t(*writeLine)(const char *dataline);
/**
    @brief   Query the number of bytes available to read.
    @return  The number of bytes available to read.
*/
    uint16_t(*bytesAvailableToRead)(void);
/**
    @brief   Inspect a byte in the stream's buffer without removing it.
    @param   depth     [in]  Distance from the front of the read queue (i.e. the next byte to be read has depth 0, the byte after that has depth 1 and so on).
    @return  The byte value. In the case of an error (e.g. a byte does not exist at that depth) return an implementation-specific error code.
*/
    char(*peek)(uint16_t depth);
/**
    @brief   Read a specified number of bytes from the stream. If insufficient bytes are available, read all available bytes.
    @param   buf       [out]       The target buffer.
    @param   numBytes  [in]        The requested number of bytes.
    @return  The number of bytes read.
*/
    uint16_t(*readBytes)(char *buf, uint16_t numBytes);
/**
    @brief   Read the next available line from the stream. The implementation must define the line-ending sequence it uses to determine when a line is available. Line-ending characters are removed and the function outputs a NULL-terminated string.
    @param   buffer    [out]       The target buffer.
    @return  The length of the output string *not* including the NULL-terminator.
*/
    uint16_t(*readLine)(char *buf);
/**
    @brief   Read the next available line from the stream but truncate the output.
   *          The implementation must define the line-ending sequence it uses to
   *          determine when a line is available. Line-ending characters are
   *          removed and the function outputs a NULL-terminated string. Where
   *          the output string would exceed the maximum specified length,
   *          truncate the string appropriately whilst still ensuring that the
   *          NULL-terminator is the last byte in the output.
    @param   buffer    [out]       The target buffer.
    @param   maxLen    [in]        The maximum permissible length of the output (including the NULL-terminator) in bytes.
    @return  The length of the output string *not* including the NULL-terminator.
*/
    uint16_t(*readLineTruncate)(char *buf, uint16_t maxLen);
} IOStream_t;


/* TYPEDEFS */


/**
    Endian-aware 32-bit unsigned integer with sub-divisions\n
    Use `umix32_t.num8.num0` to access the first byte (8-bits) of the integer
*/
typedef union {
    uint32_t num32;
#   ifdef ENDIAN_LITTLE
    struct umix32_8t {  // Little-Endian
        uint8_t num3;
        uint8_t num2;
        uint8_t num1;
        uint8_t num0;
    } num8;
#   elif defined(ENDIAN_BIG)
    struct umix32_8t {  // Big-Endian
        uint8_t num0;
        uint8_t num1;
        uint8_t num2;
        uint8_t num3;
    } num8;
#   else
#   error   "The target system's endianness is not supported!"
#   endif
#   ifdef ENDIAN_LITTLE
    struct umix32_16t {  // Little-Endian
        uint16_t num1;
        uint16_t num0;
    } num16;
#   elif defined(ENDIAN_BIG)
    struct umix32_16t {  // Big-Endian
        uint16_t num0;
        uint16_t num1;
    } num16;
#   else
#   error   "The target system's endianness is not supported!"
#   endif
} umix32_t;


/** Calendar-months Datatype */
typedef enum {
    january = 1,
    february = 2,
    march = 3,
    april = 4,
    may = 5,
    june = 6,
    july = 7,
    august = 8,
    september = 9,
    october = 10,
    november = 11,
    december = 12
} month_t;


/** Calendar-weekday Datatype */
typedef enum {
    sunday = 0x1,
    monday = 0x2,
    tuesday = 0x3,
    wednesday = 0x4,
    thursday = 0x5,
    friday = 0x6,
    saturday = 0x7
} weekday_t;


/** SOCKS5 status codes */
typedef enum {
    SOCKS5_SUCCEEDED = 0x00,
    SOCKS5_GENERAL_ERROR = 0x01,
    SOCKS5_NOT_ALLOWED = 0x02,
    SOCKS5_NET_UNREACHABLE = 0x03,
    SOCKS5_HOST_UNREACHABLE = 0x04,
    SOCKS5_CONNECTION_REFUSED = 0x05,
    SOCKS5_TTL_EXPIRED = 0x06,
    SOCKS5_COMMAND_NOT_SUPPORTED = 0x07,
    SOCKS5_ADDRESS_TYPE_NOT_SUPPORTED = 0x08,
} socks5_reply_status_t;


/** Linked-Stack Datatype */
typedef struct linked_stack_node {
    uint64_t data;
    struct linked_stack_node *next;
} linked_stack_node_t;


typedef int   ElementType;


/** Binary-Heap Datatype */
typedef struct HeapStruct {
    size_t Capacity;
    size_t Size;
    ElementType *Elements;
} binary_heap_t;


typedef binary_heap_t   *PriorityQueue;


/* QUEUE-DATATYPE MACROS */


/**
    Light-weight queue datatype (FIFO Stack)\n
    Initialize queue pointers\n
    Usage: int head, tail, element, queue[SIZE]; init_queue(head, tail);
*/
#define init_queue(head, tail)   (head = 0x0; tail = 0x0)


/**
    Enqueue an element (queue must not be full)\n
    Usage: enqueue(queue, tail, element);
*/
#define enqueue(q, tail, element)   ((q)[((tail))++] = (int)(element))


/**
    Dequeue an element (queue must not be empty)\n
    Usage: element = dequeue(queue, head);
*/
#define dequeue(q, head)   ((int)(q)[((head))++])


/**
    Return 1 if queue is full, otherwise return 0\n
    Usage: isqueuefull(tail, size);
*/
#define isqueuefull(tail, size)   ((int)((int)(tail) == (int)(size)))


/**
    Return 1 if the queue is empty, otherwise return 0\n
    Usage: isqueueempty(head, tail);
*/
#define isqueueempty(tail, head)   ((int)((int)(tail) == (int)(head)))


/**
    Return 1 if the queue is finished, otherwise return 0\n
    Usage: isqueuedone(head, tail, size);
*/
#define isqueuedone(head, tail, size)   ((int)(((int)(head) == (int)(tail)) && ((int)(head) == (int)(size))))


/* FILO-STACK-DATATYPE MACROS */


/**
    Light-weight FILO stack datatype\n
    Initialize stack pointer\n
    Usage: int stack[SIZE], top; init_stack(top);
*/
#define init_stack(top)   (top = (int)0x0)


/**
    Push an element into stack (stack must not be full)\n
    Usage: push_stack(stack, top, elem);
*/
#define push_stack(s, top, element)   (s[((int)(top))++] = (int)(element))


/**
    Remove an element from stack (stack must not be empty)\n
    Usage: elem = pop_stack(stack, top);
*/
#define pop_stack(s, top)   ((int)s[--((int)(top))])


/**
    Return 1 if stack is full, otherwise return 0\n
    Usage: while(!isstackfull(top, size)) {}
*/
#define isstackfull(s, top)   ((int)(((int)(top) == (int)(size)) ? (int)0x1 : (int)0x0))


/**
    Return 1 if the stack is empty, otherwise return 0\n
    Usage: isstackempty(top);
*/
#define isstackempty(top)   ((int)(((int)(top) == (int)0x0) ? (int)0x1 : (int)0x0))


#ifndef NO_DYNAMIC_DATATYPES


/* INITIALIZATION */
// LINKED-STACK FUNCTIONS
/**
    Init the stack\n
    Light-weight linked-stack datatype (dynamically growing/shrinking FILO Stack)\n
    Usage: linked_stack_node_t *head = NULL; init_linked_stack(head);
*/
#define init_linked_stack(head)   ((head) = (linked_stack_node_t *)NULL)
linked_stack_node_t *push_linked_stack(linked_stack_node_t *head, const uint64_t data);
linked_stack_node_t *pop_linked_stack(linked_stack_node_t *head, uint64_t *element);
/**
    Returns 1 if the stack is empty, otherwise returns 0\n
    Usage: islinkedstackempty(head);
*/
#define islinkedstackempty(head)   ((int)((linked_stack_node_t *)head == (linked_stack_node_t *)NULL ? (int)0x1 : (int)0x0))
// DISPLAY DATATYPES
void display_stack(const int *__restrict__ s, const int *__restrict__ top);
void display_linked_stack(linked_stack_node_t *head);
void display_queue(const int *__restrict__ q, const int head, const int tail);
// BINARY-HEAP FUNCTIONS
/** Test if the binary-heap is empty */
#define isheapempty(H)   ((int)(((PriorityQueue)(H))->Size == 0x0))
/** Test if the binary-heap is full */
#define isheapfull(H)   ((int)(((PriorityQueue)(H))->Size == ((PriorityQueue)(H))->Capacity))
/** Clear the binary-heap */
#define empty_heap(H)   (H->Size = 0x0)
/** Delete the binary-heap */
#define destroy_heap(H)   (free(((PriorityQueue)(H))->Elements); free(H))
PriorityQueue init_heap(size_t MaxElements);
void heapinsert(ElementType X, PriorityQueue H);
ElementType deletemin_heap(PriorityQueue H);
ElementType findmin_heap(PriorityQueue H);


#endif


#endif
