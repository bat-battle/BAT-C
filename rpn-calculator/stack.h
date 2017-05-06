/*************************************************************************
	> File Name: stack.h
	> Author: 
	> Mail: 
	> Created Time: 2017年04月03日 星期一 16时20分52秒
 ************************************************************************/

#ifndef _STACK_H
#define _STACK_H

typedef struct stack
{
    char data[20];
    int index;
} Stack;

char pop(Stack *stack);

void push(Stack *stack, char ch);

int isEmpty(Stack *stack);

char peek(Stack *stack);

Stack *init();

#endif
