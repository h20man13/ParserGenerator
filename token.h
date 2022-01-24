#ifndef TOKEN_H
#define TOKEN_H

#include "position.h"

#define TERMINAL 0
#define NON_TERMINAL 1
#define ARROW 3
#define NEW_LINE 4
  
struct Token{
  char* lexeme;
  struct Position* position;
  int type;
};

void MAKE_TOKEN(struct Token*, char*, struct Position*, int);
void DELETE_TOKEN(struct Token*);

char* GET_LEXEME_TOKEN(struct Token*);
int GET_TYPE_TOKEN(struct Token*);
struct Position* GET_POSITION_TOKEN(struct Token*);



#endif
