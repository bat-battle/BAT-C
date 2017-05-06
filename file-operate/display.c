/*************************************************************************
	> File Name: display.c
	> Author:
	> Mail: 
    > Info: 显示指定文件的内容
	> Created Time: 2017年05月05日 星期五 23时55分29秒
 ************************************************************************/

#include<stdio.h>

void main(int argc, char *argv[])
{
    char ch = '\0';
    FILE *file = NULL;
    if(argc != 2)
    {
        printf("Error format,Usage: display filename1\n");
        return; 
    }
    if((file = fopen(argv[1], "r")) == NULL)
    {
        printf("The file <%s> can not be opened.\n", argv[1]);
        return;
    }
    while((ch = fgetc(file)) != EOF)
    {
        putchar(ch);
    }
    fclose(file);
}
