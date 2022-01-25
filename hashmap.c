#include "hashmap.h"
#include "set.h"
#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

void INIT_HM(struct HM* hm, void* (*hashFunc)(void*), int (*hashCompareFunc)(void*,void*), int (*listValueFunc)(void*, void*)){
  if(hm == NULL){
    printf("Error: hashmap appears to be uninitialized");
  } else {
    hm->hashFunc = hashFunc;
    hm->listValueFunc = listValueFunc;
    hm->set = malloc(sizeof(struct Set));
    INIT_SET(hm->set, hashCompareFunc);
  }
}

int CONTAINS_KEY_HM(struct HM* hm, void* key){
  void* resultHash = hm->hashFunc(key);
  int res = CONTAINS_SET(hm->set, resultHash);
  free(resultHash);
  return res;
}

int CONTAINS_VALUE_HM(struct HM* hm, void* value){
  if(CONTAINS_KEY_HM(hm, value)){
    struct LL* ll = FETCH_KEY_ROW_IN_HM(hm, value);
    return CONTAINS_LL(ll, value);
  } else {
    return 0;
  }
}

struct LL* FETCH_KEY_ROW_IN_HM(struct HM* hm, void* key){
  if(CONTAINS_KEY_HM(hm, key)){
    void* keyHash = hm->hashFunc(key);
    struct Node_HM* resNode = FETCH_ELEMENT_FROM_SET(hm->set, keyHash, struct Node_HM);
    struct LL* resList = resNode->row; 
    free(keyHash);
    return resList;
  } else {
    printf("Error: Key was not discovered");
    return NULL;
  }
}

struct LL* REMOVE_KEY_ROW_IN_HM(struct HM* hm, void* key){
  if(CONTAINS_KEY_HM(hm, key)){
    void* keyHash = hm->hashFunc(key);
    struct Node_HM* resNode = REMOVE_ELEMENT_FROM_SET(hm->set, keyHash, struct Node_HM);
    struct LL* resList = resNode->row; 
    free(keyHash);
    return resList;
  } else {
    printf("Error: Key was not discovered");
    return NULL;
  }
}

void* FETCH_ENTRY_IN_HM_RAW(struct HM* hm, void* data){
  if(CONTAINS_KEY_HM(hm, data)){
    struct LL* ll = FETCH_KEY_ROW_IN_HM(hm, data);
    return FETCH_ELEMENT_IN_LL_RAW(ll, data);
  } else {
    printf("Entry not found when fetching data!!");
    return NULL;
  }
}

void* REMOVE_ENTRY_IN_HM_RAW(struct HM* hm, void* data){
  if(CONTAINS_KEY_HM(hm, data)){
    struct LL* ll = FETCH_KEY_ROW_IN_HM(hm, data);
    return REMOVE_ELEMENT_IN_LL_RAW(ll, data);
  } else {
    printf("Entry not found when fetching data!!");
    return NULL;
  }
}
