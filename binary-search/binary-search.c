/*************************************************************************
	> File Name: binary-search.c
	> Author: 
	> Mail: 
	> Created Time: 2017年05月09日 星期二 08时57分08秒
 ************************************************************************/

#include<stdio.h>

int search(int *datas, int size, int key);

int main(int argc, char *argv[])
{
    int datas[] = {1, 3, 5, 7, 9};
    
    int location = search(datas, sizeof(datas) / sizeof(int), 0);

    if(-1 == location)
    {
        printf("Not found!\n");
    }
    else
    {
        printf("%d is in %d\n", datas[location], location);
    }
    return 0;
}

int search(int *datas, int size, int key)
{
    int left = 0;
    int right = size - 1;
    int middle = 0;

    while(left <= right)
    {
        middle = (left + right) / 2;
        if(key == datas[middle])
        {
            return middle;
        }
        if(key < datas[middle])
        {
            right = middle - 1;
        }
        else
        {
            left = middle + 1;
        }
    }
    return -1;
}
