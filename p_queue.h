#ifndef P_QUEUE

#define P_QUEUE

#include <stdlib.h>
#include <inttypes.h>

typedef struct item
{
    int64_t data;
    struct item* next;
} item;

typedef struct p_queue
{
    uint64_t size;
    item* first;
    item* last;
} p_queue;

p_queue create_queue(const uint64_t size);

int8_t is_empty_queue(const p_queue* q);

void push(p_queue* q, int64_t data);

int64_t pop(p_queue* q);

int64_t* at(const p_queue* q, const uint64_t index);

uint64_t size(const p_queue* q);

uint64_t count(const p_queue* q);

int8_t continuity(const p_queue* q);

void clear(p_queue* q);

item* create_item(int64_t data);

#endif