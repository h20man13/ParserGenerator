#ifndef SET_H
#define SET_H

#include "linked_list.h"

struct Set{
  struct LL* ll;
  int(*compareFunc)(void*, void*);
};

void INIT_SET(struct Set*, int(*compareFunc)(void*, void*));
int CONTAINS_SET(struct Set*, void*);
void ADD_ELEMENT_TO_SET(struct Set*);
void* REMOVE_ELEMENT_FROM_SET(struct Set*, void*);
struct Node* ITERATOR_SET(struct LL*);
int EMPTY_SET(struct LL*);
void DELETE_SET(struct LL*);

#endif
