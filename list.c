#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/********************
Function: init()
Description: Sets the head and tail of a list to NULL
Parameters: struct list*
Pre-conditions: list has been created
Post-conditions: NA
********************/
void init(struct list *l){
  //l->head=malloc(sizeof(struct node));
  //l->tail=malloc(sizeof(struct node));
  l->head=NULL;
  l->tail=NULL;
  /*l->head->next=l->tail;
  l->tail->next=NULL;*/
}

/********************
Function: size()
Description: Finds the size of the list by iterating through each node
Parameters: struct list
Pre-conditions: list has been created
Post-conditions: NULL terminates the list
********************/
int size(struct list l){
  int counter=1;
  if(l.head==NULL){
    counter=0;
  }
  else{
    struct node *temp;
    temp=l.head;
    while(temp->next!=NULL){
      counter++;
      temp=temp->next;
    }
  }

  return counter;
}

/********************
Function: print()
Description: Iterate through the list and print the values of each node, if any
Parameters: struct list
Pre-conditions: list has been created
Post-conditions: NULL terminates the list
********************/
void print(struct list l){
  if(l.head==NULL){
    //printf("No values in list."); //For debugging
    return;
  }
  else{
    struct node *temp;
    temp=l.head;
    while(temp->next!=NULL){
      printf("%d", temp->val);
      temp=temp->next;
    }
    printf("%d", l.tail->val);
  }
}

/********************
Function: push_front()
Description: Creates a new node at the head of a list
Parameters: struct list*, int
Pre-conditions: list has been created
Post-conditions: NA
********************/
void push_front(struct list *l, int input){
  struct node *new_node=malloc(sizeof(struct node));
  new_node->val=input;
  new_node->next=l->head;
  l->head=new_node;
  if(l->tail==NULL){
    l->tail=new_node;
  }
}

/********************
Function: push_back()
Description: Creates a new node at the tail of a list
Parameters: struct list*, int
Pre-conditions: list has been created
Post-conditions: NULL terminates the list
********************/
void push_back(struct list *l, int input){
  struct node *new_node=malloc(sizeof(struct node)); //Size must be allocated or it seg faults
  new_node->val=input;
  new_node->next=NULL;
  if(l->head==NULL){
    l->head=new_node;
    //l->head->val=input;
    //l->head->next=NULL;
    l->tail=new_node;
    //l->tail->val=input;
    //l->tail->next=NULL;
  }
  else if (l->head->next==NULL) {
    l->head->next=new_node;
    l->tail=new_node;
  }
  else{
    struct node *temp;//=malloc(sizeof(struct node));
    temp=l->head;
    while(temp->next!=NULL){
      temp=temp->next;
    }
    temp->next=new_node;
    l->tail->next=new_node;
    l->tail=new_node;
  }
}

/********************
Function: front()
Description: Gets the data of the head in the list
Parameters: struct list
Pre-conditions: list has been created
Post-conditions: The head stores a value
********************/
int front(struct list l){
  return l.head->val;
}

/********************
Function: back()
Description: Gets the data of the tail in the list
Parameters: struct list
Pre-conditions: list has been created
Post-conditions: The tail stores a value
********************/
int back(struct list l){
  return l.tail->val;
}

/********************
Function: pop_back()
Description: Get the data of the tail of the list, then iterate through the list and free the tail data before pointing tail to the preceeding node
Parameters: struct list*
Pre-conditions: list has been created
Post-conditions: NULL terminates the list, the tail stores a value
********************/
int pop_back(struct list *l){
  if (l->head==NULL) { //Cannot pop an empty list
    //printf("List was empty.");
    return 10;
  }

  int value=l->tail->val;

  if(l->head==l->tail){ //One node in list
    free(l->head);
    //free(l->tail);
    l->head=NULL;
    l->tail=NULL;
    return value;
  }

  struct node *prev;//=malloc(sizeof(struct node));
  struct node *temp;//=malloc(sizeof(struct node));
  /*if(!l->head){ //List empty
    return NULL;
  }*/
  temp=l->head;
  while(temp!=l->tail){
    prev=temp;
    temp=temp->next;
  }
  free(prev->next);
  prev->next=NULL;
  //free(l->tail);
  l->tail=prev;

  return value;
}

/********************
Function: remove_front()
Description: Get the data of the head of the list, then set the head of the list to the node postceeding it and free the original head data
Parameters: struct list*
Pre-conditions: list has been created
Post-conditions: NULL terminates the list, the head stores a value
********************/
int remove_front(struct list *l){
  if(l->head==NULL){ //Cannot remove from an empty list
    return 10;
  }

  int value=l->head->val;

  if(l->head==l->tail){ //One node in list
    free(l->head);
    l->head=NULL;
    l->tail=NULL;
    return value;
  }
  struct node *temp;
  temp=l->head;
  l->head=l->head->next;
  free(temp);
  return value;
}

/********************
Function: empty()
Description: Checks the head of the list to see if it stores a node
Parameters: struct list
Pre-conditions: list has been created
Post-conditions: NA
********************/
int empty(struct list l){
  if(l.head==NULL){
    return 1;
  }
  else{
    return 0;
  }
}

/********************
Function: delete()
Description: Frees memory for all nodes in the list, then the list itself
Parameters: struct list*
Pre-conditions: list has been created
Post-conditions: NULL terminates the list
********************/
void delete(struct list *l){
  if(l->head==NULL && l->tail==NULL){
    //free(l->head);
    //free(l->tail);
    free(l);
    return;
  }
  else{
    struct node *temp;//=malloc(sizeof(struct node));
    temp=l->head;
    while(temp->next){
      temp=l->head->next;
      free(l->head);
      l->head=temp;
    }

    /*while(temp!=NULL){
      l->head=l->head->next;
      free(temp);
    }*/

    free(temp);
    l->head=NULL;
    l->tail=NULL;
    //free(l->tail);
    //free(l->head);
    free(l);
  }

}
