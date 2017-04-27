/*************************************************************************
	> File Name: operation.c
	> Author: 
	> Mail: 
	> Created Time: 2017年03月19日 星期日 10时45分21秒
 ************************************************************************/

#include<stdio.h>

int set(int data, int n)
{
    data = data | (1 << (n - 1));
    return data;
}

int reset(int data, int n)
{
    data = data & (~(1 << (n - 1)));
    return data;
}
