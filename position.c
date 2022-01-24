#include "position.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

const char* TO_STRING(struct Position* p, char* buf){
  char line[50];
  char col[50];
  if(sprintf(line, "%d", p->LINE) == -1 || sprintf(col, "%d", p->COL) == -1){
    printf("Error: sprintf failed");
  } else {
    strcat(buf,"LINE: ");
    strcat(buf, line);
    strcat(buf, "COL: ");
    strcat(buf, col);
  }

  return buf;
}
void INIT_POSITION(struct Position* pos, int line, int col){
  pos->LINE = line;
  pos->COL = col;
}

void DELETE_POSITION(struct Position* pos){
  free(pos);
}
