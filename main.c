#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "position.h"
#include "token.h"

void lex(struct LL* ll, FILE* fp){
  char ch = fgetc(fp);
  int lp = 0;
  int ln = 1;
  while(ch != EOF){
    if(ch == '\n'){
      struct Position* position = malloc(sizeof(struct Position));
      INIT_POSITION(position,ln ,lp);
      
      char* lexeme = malloc(sizeof(char)*2);
      lexeme[0] = '\n';
      lexeme[1] = '\0';
      
      struct Token* tok = malloc(sizeof(struct Token));
      MAKE_TOKEN(tok, lexeme, position, NEW_LINE);

      PUSH_LL(ll, tok);
      
      ln++;
      lp = 0;
    } else if(ch >= 'a' && ch <= 'z'){
      struct Position* position = malloc(sizeof(struct Position));
      INIT_POSITION(position,ln ,lp);
      
      char* lexeme = malloc(sizeof(char)*2);
      lexeme[0] = ch;
      lexeme[1] = '\0';
      
      struct Token* tok = malloc(sizeof(struct Token));
      MAKE_TOKEN(tok, lexeme, position, TERMINAL);

      PUSH_LL(ll, tok);
      
      lp++;
    } else if(ch >= 'A' && ch <= 'Z'){
      struct Position* position = malloc(sizeof(struct Position));
      INIT_POSITION(position,ln ,lp);
      
      char* lexeme = malloc(sizeof(char)*2);
      lexeme[0] = ch;
      lexeme[1] = '\0';
      
      struct Token* tok = malloc(sizeof(struct Token));
      MAKE_TOKEN(tok, lexeme, position, NON_TERMINAL);

      PUSH_LL(ll, tok);
      
      lp++;
    } else if(ch == '-'){
      ch = fgetc(fp);
      if(ch == '>'){
	struct Position* position = malloc(sizeof(struct Position));
	INIT_POSITION(position,ln,lp);
      
	char* lexeme = malloc(sizeof(char)*3);
	lexeme[0] = '-';
	lexeme[1] = '>';
	lexeme[2] = '\0';
      
	struct Token* tok = malloc(sizeof(struct Token));
	MAKE_TOKEN(tok, lexeme, position, ARROW);

	PUSH_LL(ll, tok);
	lp+=2;
      } else {
	printf("Error: unexpected token %c found", ch);
	if(ch == '\n'){
	  lp = 0;
	  ln++;
	} else {
	  lp+=2;
	}
      }
    } else {
      printf("Error: unexpected token %c found ", ch);
    }
  }
}

int main(int args, char** argv){
  if(args == 2){
    FILE* in_file = fopen(argv[1], "r");
    if(in_file == NULL){
      printf("Error: no file found named %s", argv[1]);
    } else {
      struct LL tokenList;
      INIT_LL(&tokenList, NULL);

      lex(&tokenList, in_file);
    }
    fclose(in_file);
    return 0;
  } else {
    printf("Error: Expected only 1 filename argument but recieved %d arguments!!\n", args);
    return 1;
  }
}
