/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: 2017年05月06日 星期六 22时07分30秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"calculator.h"

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
