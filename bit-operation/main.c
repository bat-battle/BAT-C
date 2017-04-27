/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: 2017年03月19日 星期日 10时05分09秒
 ************************************************************************/

#include<stdio.h>
#include"operation.h"

int main()
{
    int n = 0;
    int data = 10;

    printf("请输入置１的位置：");
    scanf("%d", &n);

    data = set(data, n);

    printf("将第%d位置１后的数字为%d\n", n, data);

    data = reset(data, n);

    printf("将第%d位清0后的数字为%d\n", n, data);
    return 0;
}

