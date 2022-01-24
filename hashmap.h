#ifndef HASHMAP_H
#define HASHMAP_H

#include "set.h"

struct HM {
  struct Set* set;
  void (*hashFunc)(void*, void*);
  void (*valueFunc)(void*, void*);
};

struct Node_HM{
  void* key;
  struct LL* row;
};

void INIT_HM(struct HM*, void* (*hashFunc)(void*, void*), void* (*valueFunc)(void*, void*));

int CONTAINS_KEY_HM(struct HM* hm, void* key);
int CONTAINS_VALUE_HM(struct HM* hm, void* value);

struct LL* FETCH_KEY_ROW_IN_HM(struct HM* hm, void* key, void* (*hashFunc)(void*,void*));
struct LL* REMOVE_KEY_ROW_IN_HM(struct HM* hm, void* key, void* (*hashFunc)(void*,void*));

void* FETCH_ENTRY_IN_HM_RAW(struct HM* hm, void* data);
void* REMOVE_ENTRY_IN_HM_RAW(struct HM* hm, void* data);


#endif
