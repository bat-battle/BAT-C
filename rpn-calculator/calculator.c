/*************************************************************************
	> File Name: calculator.c
	> Author: 
	> Mail: 
	> Created Time: 2017年04月03日 星期一 16时02分15秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"stack.h"

int getLevel(char op);
int compareOP(char op1, char op2);
char *converter(char *str);
int calculator(char *str);

int main()
{
    char *str = "9 + (5 - 2) * 4";//中缀
    char *temp = converter(str);
    puts(temp);

    int result = calculator(temp);

    printf("result is: %d\n", result);

    free(temp);
    return 0;
}

int calculator(char *str)
{
    Stack *stack = init();

    for(;'\0' != *str; ++str)
    {
        if('0' <= *str && *str <= '9')
        {
            push(stack, *str);
            continue;
        }
        int valu1 = pop(stack) - '0';
        int valu2 = pop(stack) - '0';
        int result = 0;
        switch(*str)
        {
            case '+':
               result = valu2 + valu1;
               break;
            case '-':
               result = valu2 - valu1;
               break;
            case '*':
               result = valu2 * valu1;
               break;
            case '/':
               result = valu2 / valu1;
               break;
        }
        push(stack, result + '0');
    }
    int temp = pop(stack) - '0';
    free(stack);
    return temp;
}

char *converter(char *str)
{
    char *temp = (char *)malloc(strlen(str) + 1);
    int index = 0;

    memset(temp, '\0', strlen(str) + 1);
    Stack *stack = init();

    for(; '\0' != *str; ++str)
    {
        if(' ' == *str)
        {
            continue;
        }
        if(*str >= '0' && *str <= '9')
        {
            temp[index++] = *str;
            continue;
        }
        if(')' == *str)
        {
            while('(' != peek(stack))
            {
                temp[index++] = pop(stack);
            }
            pop(stack);
            continue;
        }
        if('(' == *str)
        {
            push(stack, *str);
            continue;
        }
        if(isEmpty(stack) || '(' == peek(stack))
        {
            push(stack, *str);
            continue;
        }
        while(!isEmpty(stack) && compareOP(peek(stack), *str) >= 0)
        {
            temp[index++] = pop(stack);
        }
        push(stack, *str);
    }
    while(!isEmpty(stack))
    {
        temp[index++] = pop(stack);
    }
    free(stack);
    return temp;
}

int compareOP(char op1, char op2)
{
    return getLevel(op1) - getLevel(op2);
}

int getLevel(char op)
{
    if('+' == op || '-' == op)
    {
        return 1;
    }
    if('*' == op || '/' == op)
    {
        return 2;
    }
    return 0;
}

