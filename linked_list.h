#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node{
  void* data;
  struct Node* next;
  struct Node* prev;
};

struct LL{
  struct Node* head;
  struct Node* tail;
  int(*compareFunc)(void*, void*);
};

void INIT_LL(struct LL*, int(*compareFunc)(void*, void*));

int CONTAINS_LL(struct LL*, void*);

void PUSH_LL(struct LL*, void*);
void ENQUEUE_LL(struct LL*, void*);

void* POP_LL_RAW(struct LL* ll);
#define POP_LL(LIST, TYPE) ((TYPE*)POP_LL_RAW((LIST)))
void* DEQUEUE_LL_RAW(struct LL*);
#define DEQUEUE_LL(LIST, TYPE) ((TYPE*)DEQUEUE_LL_RAW((LIST)))

int SIZE_LL(struct LL*);

void* FETCH_AT_INDEX_LL_RAW(struct LL*, int);
#define FETCH_AT_INDEX_LL(LIST, INDEX, TYPE) ((TYPE*)FETCH_AT_INDEX_LL_RAW((LIST), (INDEX)))

void* REMOVE_AT_IDEX_LL_RAW(struct LL*, int index);
#define REMOVE_AT_INDEX_LL(LIST, INDEX, TYPE) ((TYPE*)REMOVE_AT_INDEX_LL_RAW((LIST), (INDEX)))

void* REMOVE_ELEMENT_IN_LL_RAW(struct LL*, void* data);
#define REMOVE_ELEMENT_IN_LL(LIST, DATA, TYPE) ((TYPE*)REMOVE_ELEMENT_IN_LL_RAW((LIST), (DATA)))

void* FETCH_ELEMENT_IN_LL_RAW(struct LL*, void* data);
#define FETCH_ELEMENT_IN_LL(LIST, DATA, TYPE) ((TYPE*)FETCH_ELEMENT_IN_LL_RAW((LIST), (DATA)))

struct Node* ITERATOR_HEAD_LL(struct LL*);
struct Node* ITERATOR_TAIL_LL(struct LL*);

int EMPTY_LL(struct LL*);

void DELETE_LL(struct LL*);

#endif
