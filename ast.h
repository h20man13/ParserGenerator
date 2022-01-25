#ifndef AST_H
#define AST_H

struct Terminal{
  char* lexeme;
  struct Position* position;
};

struct NonTerminal{
  char* lexeme;
  struct Position* position;
  struct LL* productionList;
};

union Node_Type_Data_AST{
  struct Terminal* terminal;
  struct NonTerminal* nonTerminal;
};

struct Node_AST{
  int type;
  union Node_Type_Data_AST* data;
};

void INIT_TERMINAL(struct Node_AST*, char* lexeme, struct Position* position);

void INIT_NONTERMINAL(struct Node_AST*, char*, struct Position*);
void ADD_CHILD_NONTERMINAL(struct Node_AST*, struct Node_AST*);

void PRINT_AST(struct Node_AST*);

#endif
