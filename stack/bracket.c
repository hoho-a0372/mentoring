#include <stdio.h>

#define MAX_SIZE 1000
#define TRUE 1
#define FALSE 0

typedef struct _stack{
	char data[MAX_SIZE];
	int top;
}_Stack;

_Stack stack;

void init(){
	stack.top = 0;
}
int isEmpty(){
	if(stack.top != 0){
		return FALSE;
	}
	else {
		return TRUE;
	}
}
int isFull(){
	if(stack.top != MAX_SIZE){
		return FALSE;
	}
	else {
		return TRUE;
	}
}
int size(){
	return (stack.top);
}

char push(char ch){
	if(isFull()){
		return -1;
	}
	else return stack.data[stack.top++]=ch;
}

char pop(){
	if(isEmpty()){
		return -1;
	}
	else return stack.data[--stack.top];
}

char peek(){
	return stack.data[stack.top-1];
}

int check(char ch){
	switch(ch){
	case '(' : case '{' : case '[' :
		push(ch);
		break;
	case ')' :
		if(isEmpty())	return 2;
		else{
			if(pop() != '(') 
				return 3;
		}
		break;
	case '}' :
		if(isEmpty())	return 2;
		else{
			if(pop() != '{')
				 return 3;
		}
		break;
	case ']' :
		if(isEmpty())	return 2;
		else{
			if(pop() != '[')
				return 3;
		}
		break;
	default : break;
	}
	return 0;
}
			
int main(){
	init();
	char input[MAX_SIZE];
	scanf("%s", input);
	int i = 0, er = 0;
	while(input[i] != '\0'){
		er = check(input[i++]);
		if(er) break;
	}
	if(!isEmpty()) er = 1;
	if(!er) 
		printf("괄호정상: %s\n", input);
	else
		printf("괄호오류: %s (조건%d 위반)\n", input, er);
	return 0;
}
