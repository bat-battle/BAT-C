/*************************************************************************
	> File Name: stack.c
	> Author: 
	> Mail: 
	> Created Time: 2017年04月03日 星期一 16时11分21秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

Stack *init()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->index = -1;

    return stack;
}

char peek(Stack *stack)
{
    if(stack->index == -1)
    {
        printf("空栈!\n");
        return '\0';
    }
    return stack->data[stack->index];
}

char pop(Stack *stack)
{
    if(stack->index == -1)
    {
        printf("空栈\n");
        return '\0';
    }
    return stack->data[(stack->index)--];
}

void push(Stack *stack, char ch)
{
    if(stack->index + 1 >= 20)
    {
        printf("栈已满");
        return;
    }
    stack->data[++(stack->index)] = ch;
}

int isEmpty(Stack *stack)
{
    if(-1 == stack->index)
    {
        return 1;
    }
    return 0;
}
