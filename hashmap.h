#ifndef HASHMAP_H
#define HASHMAP_H

#include "set.h"

struct HM {
  struct Set* set;
  void* (*hashFunc)(void*);
  int (*listValueFunc)(void*, void*);
};

struct Node_HM{
  void* key;
  struct LL* row;
};

void INIT_HM(struct HM*, void* (*hashFunc)(void*), int (*hashCompareFunc)(void*,void*), int (*listValueFunc)(void*, void*));

int CONTAINS_KEY_HM(struct HM* hm, void* key);
int CONTAINS_VALUE_HM(struct HM* hm, void* value);

struct LL* FETCH_KEY_ROW_IN_HM(struct HM* hm, void* key);
struct LL* REMOVE_KEY_ROW_IN_HM(struct HM* hm, void* key);

void* FETCH_ENTRY_IN_HM_RAW(struct HM* hm, void* data);
#define FETCH_ENTRY_IN_HM(HMAP, DATA, TYPE) ((TYPE*)FETCH_ENTRY_IN_HM_RAW((HMAP), (DATA)))

void* REMOVE_ENTRY_IN_HM_RAW(struct HM* hm, void* data);
#define REMOVE_ENTRY_IN_HM(HMAP, DATA, TYPE) ((TYPE*)REMOVE_ENTRY_IN_HM_RAW((HMAP), (DATA)))

#endif
