#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

void INIT_LL(struct LL* ll, int(*compareFunc)(void*, void*)){
  if(EMPTY_LL(ll)){
    ll->head = NULL;
    ll->tail = NULL;
    ll->compareFunc = compareFunc;
  } else {
    printf("Expected empty list when initializing list but found list with %d elements", SIZE_LL(ll));
  }
}

int CONTAINS_LL(struct LL* ll, void* data){
  for(struct Node* it = ITERATOR_HEAD_LL(ll); it != NULL; it=it->next){
    if(ll->compareFunc(data, it->data)){
      return 1;
    }
  }
  return 0;
}

void PUSH_LL(struct LL* ll, void* data){
  if(ll == NULL){
    printf("Error: While pushing it appears the linked list has not been initialized correctly!!");
  } else if (EMPTY_LL(ll)){
    ll->head = malloc(sizeof(struct Node));
    ll->tail = ll->head;
    ll->head->prev = NULL;
    ll->head->next = NULL;
    ll->head->data = data;
  } else {
    struct Node* newHead = malloc(sizeof(struct Node));
    newHead->next = ll->head;
    newHead->data = data;
    newHead->prev = NULL;
    ll->head->prev = newHead; 
    ll->head = newHead;
  }
}

void ENQUEUE_LL(struct LL* ll, void* data){
  if(ll == NULL){
    printf("Error: While  it appears the linked list has not been initialized correctly!!");
  } else if (EMPTY_LL(ll)){
    ll->head = malloc(sizeof(struct Node));
    ll->tail = ll->head;
    ll->head->prev = NULL;
    ll->head->next = NULL;
    ll->head->data = data;
  } else {
    struct Node* newTail = malloc(sizeof(struct Node));
    newTail->next = NULL;
    newTail->data = data;
    newTail->prev = ll->tail;
    ll->tail->next = newTail; 
    ll->tail = newTail;
  }
}

void* POP_LL_RAW(struct LL* ll){
  if(ll == NULL){
    printf("Error: While popping it appears the linked list has not been initialized correctly!!");
    return NULL;
  } else if (EMPTY_LL(ll)){
    printf("Error: While popping it appears the list is allready empty");
    return NULL;
  } else if (ll->head == ll->tail){
    struct Node* temp = ll->head;
    ll->head = NULL;
    ll->tail = NULL;
    void* data = temp->data;
    free(temp);
    return data;
  } else {
    struct Node* temp = ll->head;
    ll->head=ll->head->next;
    ll->head->prev = NULL;
    void* data = temp->data;
    free(temp);
    return data;
  }
}

void* DEQUEUE_LL_RAW(struct LL* ll){
  if(ll == NULL){
    printf("Error: While dequeueing it appears the linked list has not been initialized correctly!!");
    return NULL;
  } else if (EMPTY_LL(ll)){
    printf("Error: While dequeueing it appears the list is allready empty");
    return NULL;
  } else if (ll->head == ll->tail){
    struct Node* temp = ll->head;
    ll->head = NULL;
    ll->tail = NULL;
    void* data = temp->data;
    free(temp);
    return data;
  } else {
    struct Node* temp = ll->tail;
    ll->tail=ll->tail->prev;
    ll->tail->next = NULL;
    void* data = temp->data;
    free(temp);
    return data;
  }
}

int SIZE_LL(struct LL* ll){
  if(ll == NULL){
    printf("When getting the size of the list it appears that the list wasnt declared correctly");
  }

  int count = 0;
  struct Node* temp = ll->head;

  while(temp != NULL){
    temp=temp->next;
    count++;
  }

  return count;
}

struct Node* ITERATOR_HEAD_LL(struct LL* ll){
  if(ll == NULL){
    printf("Error: While fetching iterator it appears the linked list has not been initialized correctly!!");
    return NULL;
  } else {
    return ll->head;
  }
}

struct Node* ITERATOR_TAIL_LL(struct LL* ll){
  if(ll == NULL){
    printf("Error: While fetching iterator it appears the linked list has not been initialized correctly!!");
    return NULL;
  } else {
    return ll->tail;
  }
}

int EMPTY_LL(struct LL* ll){
  if(ll == NULL){
    printf("Error: While detecting empty list it appears the linked list has not been initialized correctly!!");
    return 1;
  } else {
    return ll->head == NULL;
  }
}

void* FETCH_AT_INDEX_LL_RAW(struct LL* ll, int index){
  if(ll == NULL){
    printf("Error: When getting the size of the list it appears that the list wasnt declared correctly");
    return NULL;
  } else if(EMPTY_LL(ll)){
    printf("Error: cant fetch element at index %d because the list is empty", index);
    return NULL;
  } else {
    int moves = 0;
    struct Node* temp;
    for(temp = ll->head; temp != NULL && moves < index; moves++, temp=temp->next);

    if(temp == NULL){
      printf("Cant fetch index %d from list with size %d", index, moves+1);
      return NULL;
    } else {
      return temp->data;
    }
  }
}

void* REMOVE_AT_INDEX_LL_RAW(struct LL* ll, int index){
  if(ll == NULL){
    printf("Error: When getting the size of the list it appears that the list wasnt declared correctly");
    return NULL;
  } else if(EMPTY_LL(ll)){
    printf("Error: cant fetch element at index %d because the list is empty", index);
    return NULL;
  } else if (ll->head == ll->tail && index == 0) {
    struct Node* temp = ll->head;

    ll->head = NULL;
    ll->tail = NULL;

    void* data = temp->data;
    free(temp);

    return data;
  } else {
    int moves = 0;
    struct Node* temp;
    for(temp = ll->head; temp != NULL && moves < index; moves++, temp=temp->next);

    if(temp == NULL){
      printf("Cant remove index %d from list with size %d", index, moves+1);
      return NULL;
    } if (temp == ll->head) {
      temp->next->prev = NULL;
      ll->head = ll->head->next;
      void* data = temp->data;
      free(temp);
      return data;
    } else if(temp == ll->tail){
      temp->prev->next = NULL;
      ll->tail = ll->tail->prev;
      void* data = temp->data;
      free(temp);
      return data;
    } else {
      temp->next->prev = temp->prev;
      temp->prev->next = temp->next;
      void* data = temp->data;
      free(temp);
      return data;
    }
  }
}

void* REMOVE_ELEMENT_IN_LL_RAW(struct LL* ll, void* data){
  if(ll == NULL){
    printf("Error: When getting the size of the list it appears that the list wasnt declared correctly!!\n");
    return NULL;
  } else if(EMPTY_LL(ll)){
    printf("Error: cant remove element at because the list is empty!!\n");
    return NULL;
  } else if (ll->head == ll->tail) {
    if(ll->compareFunc(ll->head->data, data)){
      struct Node* temp = ll->head;
      ll->head = NULL;
      ll->tail = NULL;
      void* data = temp->data;
      free(temp);
      return data;
    } else {
      printf("Error: List could not find element in list!!\n");
      return NULL;
    }
  } else {
    struct Node* temp;
    for(temp = ll->head; temp != NULL && !ll->compareFunc(temp->data, data); temp=temp->next);

    if(temp == NULL){
      printf("Element doesnt exist in list!!\n");
      return NULL;
    } if (temp == ll->head) {
      temp->next->prev = NULL;
      ll->head = ll->head->next;
      void* data = temp->data;
      free(temp);
      return data;
    } else if(temp == ll->tail){
      temp->prev->next = NULL;
      ll->tail = ll->tail->prev;
      void* data = temp->data;
      free(temp);
      return data;
    } else {
      temp->next->prev = temp->prev;
      temp->prev->next = temp->next;
      void* data = temp->data;
      free(temp);
      return data;
    }
  }
}

void* FETCH_ELEMENT_IN_LL_RAW(struct LL* ll, void* data){
  if(ll == NULL){
    printf("Error: When getting the size of the list it appears that the list wasnt declared correctly!!\n");
    return NULL;
  } else if(EMPTY_LL(ll)){
    printf("Error: cant remove element at because the list is empty!!\n");
    return NULL;
  } else {
    struct Node* temp;

    for(temp = ll->head; temp != NULL && !ll->compareFunc(temp->data, data); temp=temp->next);

    if(temp == NULL){
      printf("Element doesnt exist in list!!\n");
      return NULL;
    } else {
      return temp->data;
    }
  }
}

void DELETE_LL(struct LL* ll){
  if(ll == NULL){
    printf("Error: While deleting list it appears the list was not initialized correctly!!\n");
  } else {
    while(ll->head != NULL){
      struct Node* temp = ll->head;
      ll->head = ll->head->next;
      free(temp->data);
      free(temp);
    }
  }
}
