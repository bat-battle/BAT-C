/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: 2017年05月05日 星期五 20时39分25秒
 ************************************************************************/

#include<stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;

    for(i = 0; i < argc; ++i)
    {
        printf("%s\n", argv[i]);
    }
    return 0;
}
