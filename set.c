#ifndef SET_H
#define SET_H

#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

struct Set{
  struct LL* ll;
};

void INIT_SET(struct Set* set, int(*compareFunc)(void*, void*)){
  if(set == NULL){
    printf("Error it appears memory has not been assigned for the set yet.\nCant create set for null value!!!\n");
  } else {
    set->ll = malloc(sizeof(struct LL));
    INIT_LL(set->ll, compareFunc);
  }
}

int CONTAINS_SET(struct Set* set, void* data){
  return CONTAINS_LL(set->ll, data);
}

void ADD_ELEMENT_TO_SET(struct Set* set, void* data){
  if(!CONTAINS_SET(set, data)){
    ENQUEUE_LL(set->ll, data);
  }
}

void* REMOVE_ELEMENT_FROM_SET(struct Set* set, void* data){
  if(CONTAINS_SET(set, data)){
    return REMOVE_ELEMENT_IN_LL_RAW(set->ll, data);
  } else {
    printf("Error: While removing element from set the set doesnt contain the required element");
    return NULL;
  }
}

struct Node* ITERATOR_SET(struct Set* set){
  return ITERATOR_HEAD_LL(set->ll);
}

int EMPTY_SET(struct Set* set){
  return EMPTY_LL(set->ll);
}

void DELETE_SET(struct Set* set){
  DELETE_LL(set->ll);
  free(set);
}

#endif
