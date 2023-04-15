#include "p_queue.h"

// Creates only one int64_t item allocated in heap and return it's poiter.
item* create_item(int64_t data) {
    item* p = (item*)malloc(sizeof(item*) * 1);
    p->data = data;
    p->next = NULL;
    return p;
}

// Creates a queue with given size. Elements are initialized with zeros. 
p_queue create_queue(const uint64_t size) {
    p_queue q;
    if (size > 0)
        q.first = create_item(0);
    else
        q.first = NULL;
    q.last = q.first;
    for (uint64_t i = 0; i + 1 < size; ++i) {
        q.last->next = create_item(0);
        q.last = q.last->next;
    }
    q.size = size;
    return q;
}

// Checks if queue has elements in it.
int8_t is_empty_queue(const p_queue* q) {
    return (q->first == q->last) && (q->first == NULL);
}

// Pushes a new element into the end of queue
void push(p_queue* q, int64_t data) {
    if (is_empty_queue(q)) {
        q->last = create_item(data);
        q->first = q->last;
    }
    else {
        q->last->next = create_item(data);
        q->last = q->last->next;
    }
    ++q->size;
}

// Pops an element from the beginning of queue and returns it's data. 
int64_t pop(p_queue* q) {
    if (is_empty_queue(q)) {
        exit(-1);
    }
    int64_t data = q->first->data;
    item* p = q->first;
    q->first = q->first->next;
    free(p);
    --q->size;
    return data;
}

// Returns a poiter to value of element at given index.
int64_t* at(const p_queue* q, const uint64_t index) {
    if (index >= q->size) {
        return NULL;
    }
    item* iterator = q->first;
    uint64_t count = 0;
    while (count < index && iterator != NULL) {
        iterator = iterator->next;
        ++count;
    }
    if (count < index) {
        return NULL;
    }
    return &iterator->data;
}

uint64_t size(const p_queue* q) {
    return q->size;
}

uint64_t count(const p_queue* q) {
    uint64_t count = 0;
    item* iterator = q->first;
    while (iterator != NULL) {
        iterator = iterator->next;
        ++count;
    }
    return count;
}

int8_t continuity(const p_queue* q) {
    return size(q) == count(q);
}

void clear(p_queue* q) {
    if (is_empty_queue(q)) {
        q->size = 0;
        return;
    }
    item* i1,* i2 = q->first;
    q->first = NULL;
    while (i2 != NULL) {
        i1 = i2;
        i2 = i2->next;
        free(i1);
    }
    if (q->last != NULL)
        free(q->last);
    q->last = NULL;
    q->size = 0;
}