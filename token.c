#include "token.h"
#include <stdlib.h>

void MAKE_TOKEN(struct Token* tok, char* const lexeme, struct Position* pos, int type){
  tok->lexeme = lexeme;
  tok->position = pos;
  tok->type = type;
}

void DELETE_TOKEN(struct Token* tok){
  free(tok->position);
  free(tok->lexeme);
  free(tok);
}

char* GET_LEXEME_TOKEN(struct Token* tok){
  return tok->lexeme;
}

int GET_TYPE_TOKEN(struct Token* tok){
  return tok->type;
}

struct Position* GET_POSITION_TOKEN(struct Token* tok){
  return tok->position;
}



