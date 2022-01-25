#include "ast.h"
#include "token.h"
#include <stdio.h>
#include <stdlib.h>

/*
struct Terminal{
  char* lexeme;
  struct Position* position;
};
*/

void INIT_TERMINAL(struct Node_AST* node, char* lexeme, struct Position* position){
  if(node == NULL){
    printf("Error: it appears your terminal node was not initialized correctly");
  } else if(node->type == TERMINAL){
    struct Terminal* term = malloc(sizeof(struct Terminal));
    node->data->terminal = term;
    term->lexeme = lexeme;
    term->position = position;
  } else {
    printf("Invalid terminal %s with type found with id of %d at %s!!!", lexeme, node->type, TO_STRING(position));
  }
}

/*
struct NonTerminal{
  char* lexeme;
  struct Position* position;
  struct LL* productionList;
};


union Node_Type_Data_AST{
  struct Terminal terminal;
  struct NonTerminal nonTerminal;
};

struct Node_AST{
  int type;
  union Node_Type_Data_AST data;
}
*/

void INIT_NONTERMINAL(struct Node_Ast*node, char* lexeme, struct Position* position){
  if(node == NULL){
    printf("Error it appears your terminal node was not initialized correctly");
  } else if(node->type == NONTERMINAL){
    struct NonTerminal* term = malloc(sizeof(struct NonTerminal));
    node->data->nonTerminal = term;
    term->lexeme = lexeme;
    term->position = postition;
    term->productionList = malloc(sizeof(struct LL));
    INIT_LL(productionList, NULL);
  } else {
    printf("Invalid non terminal %s with type found with id of %d at %s!!!", lexeme, node->type, TO_STRING(position));
  }
}

void ADD_CHILD_NONTERMINAL(struct Node_AST* node, struct Node_AST* child){
  if(node == NULL)
    printf("While initializing node it appears the node wasnt generated successfully!");

  if(node->type != NONTERMINAL)
    printf("Error: When adding child it appears the node generated is not considered to be a non-terminal!!");

  ENQUEUE_LL(node->data->nonTerminal->productionList, (void*)child);
}

void PRINT_AST(struct Node_AST* node){
  if(node == NULL){
    printf("Error cant Print Ast because the pointer is a NULL value");
  } else if(node->type == TERMINAL){
    printf("%s", node->data->terminal->lexeme);
  } else if(node->type == NONTERMINAL){
    printf("(%s (", node->data->nonTerminal->lexeme));
    struct Node* temp;
    struct LL* ll = node->data->nonTerminal->productionList;
    for(temp = INTERATOR_HEAD_LL(ll); temp != INTERATOR_TAIL_LL(ll); temp = temp->next){
      struct Node_AST* currentChild = (Node_AST*)(temp->data);
      PRINT_AST(currentChild);
      printf(" ");
    }
    struct Node_AST* finalChild =(Node_AST*)(temp->data);
    PRINT_AST(finalChild);
    printf("))");
  } else {
    printf("ErrorNode: NUM(%d)", node->type);
  }
}

#endif
