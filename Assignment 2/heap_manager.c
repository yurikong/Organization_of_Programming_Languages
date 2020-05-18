#include <stdio.h>
#include <stdlib.h>

struct Block {
    int block_size;             // # of bytes in the data section
    struct Block *next_block;   // pointer to the next block
};

const int B_SIZE = sizeof(struct Block);    // overhead size
const int P_SIZE = sizeof(void*);           // size of void pointer
static struct Block *free_head;        // always points to the first free block

void my_initialize_heap(int size);
void* my_malloc(int size);
void my_free(void *data);

void my_initialize_heap(int size)
{
    if(size <= 0)   // size must be positive
    {
        printf("Size must be positive.\n");
        return;
    }
    // use malloc to allocate memory to represent the heap
    struct Block *buffer = (struct Block*)malloc(size);
    buffer->block_size = size - B_SIZE;
    buffer->next_block = NULL;
    free_head = buffer;
}

void* my_malloc(int size)
{
    if(size <= 0)   // size must be positive
    {
        printf("Size must be positive.\n");
        return NULL;
    }
    // memory block must be in multiples of sizeof(void*)
    while(size % P_SIZE != 0)
        size++;
    // no free block
    if(!free_head)
        return NULL;
    // list iterators
    struct Block *prev = NULL;
    struct Block *curr = free_head;
    struct Block *next = curr->next_block;
    // walk the list and find a block that has enough memory
    while(curr->block_size < size && next)
    {
        prev = curr;
        curr = next;
        next = curr->next_block;
    }
    // determine if it's enough to split
    int excess = curr->block_size - size;
    // can it split?
    if(excess >= B_SIZE + P_SIZE)
    {
        // each block is made of overhead, pointer, and data section
        struct Block *new_block = (struct Block*)((char*)curr + B_SIZE + size);
        // new block now has available memory minus original block data section and pointer, and its overhead
        new_block->block_size = curr->block_size - B_SIZE - size;
        new_block->next_block = next;
        curr->block_size = size;    // update block size
        prev ? (prev->next_block = new_block) : (free_head = new_block);    // if head of list, update free_head, else remove curr block from list
    }
    else
        prev ? (prev->next_block = next) : (free_head = next);
    curr->next_block = NULL;    // clear up any current block pointer
    return (void*) (curr + 1);   // return a pointer that points to data section
}

void my_free(void *data)
{
    if(!data)   // check for null pointer
    {
        printf("Null pointer.\n");
        return;
    }
    struct Block *temp = (struct Block *)data - 1;    // move to head of block
    temp->next_block = free_head;       // link back to free list
    free_head = temp;     // update free head
}