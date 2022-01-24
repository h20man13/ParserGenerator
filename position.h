#ifndef POSITION_H
#define POSITION_H

struct Position{
  int LINE;
  int COL;
};

const char* TO_STRING(struct Position*, char*);
void INIT_POSITION(struct Position*, int, int);
void DELETE_POSITION(struct Position*);

#endif
