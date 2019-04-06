#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main(){
  struct list *l=malloc(sizeof(struct list));
  init(l);

  push_front(l, 10);
  push_front(l, 20);

  print(*l); //Values in list
  printf("\n");
  printf("%d", size(*l));
  printf("\n");
  printf("%d", front(*l));
  printf("\n");
  printf("%d", back(*l));
  printf("\n");

  printf("%d", remove_front(l));
  printf("\n");
  printf("%d", empty(*l)); //1 if empty, 0 if not
  printf("\n");

  delete(l);

  return 0;
}
