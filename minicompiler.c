/********************
Program: []{}() Compiler
Author: Emily Liu
Date: 06/10/2017
Description: Determines whether a string of characters is valid based on the placement of [], {}, and ().
Input: String of characters.
Output: Statement printed which states whether the string is valid or not.
********************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main(){
	//Get string input
	printf("Enter a string with (), {}, and/or []: ");
	char code[50];
	scanf("%[^\n]s", code); //Read to newline
	printf("You entered: ");
	printf("%s", code);
	printf("\n");

	struct list *l=malloc(sizeof(struct list));

	init(l);

	//"Compilation"
	int string_size=strlen(code);
	int i;
	int placeholder;
	for(i=0; i<string_size; i++){
		if (code[i]=='[') {
			push_back(l, 0);
		}
		else if (code[i]==']') {
			placeholder=pop_back(l);
			if(placeholder!=0){ //Attempted to pop an empty list
				printf("String was invalid! [] not found.\n");
				delete(l);
				return 0;
			}
		}
		else if (code[i]=='{') {
			push_back(l, 1);
		}
		else if (code[i]=='}') {
			placeholder=pop_back(l);
			if(placeholder!=1){ //Attempted to pop an empty list
				printf("String was invalid! {} not found.\n");
				delete(l);
				return 0;
			}
		}
		else if (code[i]=='(') {
			push_back(l, 2);
		}
		else if (code[i]==')') {
			placeholder=pop_back(l);
			if(placeholder!=2){ //Attempted to pop an empty list
				printf("String was invalid! () not found.\n");
				delete(l);
				return 0;
			}
		}
		/*printf("List contents:\n");
		print(*l);
		printf("\n");*/
	}

	//Check list size for successful compilation. Size 0 indicates valid string.
	int list_size=size(*l);
	//printf("%d", list_size); //For debugging
	//printf("\n");
	if (list_size==0) {
		printf("String was valid and compiled successfully!\n");
	}
	else{
		printf("String was invalid!\n");
	}

	//printf("%d", empty(l)); //For debugging

	delete(l);

	return 0;
}
