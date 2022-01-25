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

void* REMOVE_ELEMENT_FROM_SET_RAW(struct Set*, void*);
#define REMOVE_ELEMENT_FROM_SET(SET, DATA, TYPE) ((TYPE*)REMOVE_ELEMENT_FROM_SET_RAW((SET),(DATA)));

void* FETCH_ELEMENT_FROM_SET_RAW(struct Set*, void*);
#define FETCH_ELEMENT_FROM_SET(SET, DATA, TYPE) ((TYPE*)FETCH_ELEMENT_FROM_SET_RAW((SET),(DATA)));

struct Node* ITERATOR_SET(struct LL*);
int EMPTY_SET(struct LL*);
void DELETE_SET(struct LL*);

#endif
