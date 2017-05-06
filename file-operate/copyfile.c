/*************************************************************************
	> File Name: copyfile.c 
	> Author: 
	> Mail: 
    > Info:将一个文件复制到另外一个文件
	> Created Time: 2017年05月06日 星期六 17时08分36秒
 ************************************************************************/

#include<stdio.h>

int main(int argc, char *argv[])
{
    FILE *in = NULL;//被复制的文件
    FILE *out = NULL;//复制后的文件

    char buffer = '\0';

    if((in = fopen(argv[1], "r")) == NULL) 
    {
        printf("Open file<%s> error!\n", argv[1]);
        return 0;
    }
    if((out = fopen(argv[2], "w")) == NULL) 
    {
        printf("Open file<%s> error!\n", argv[2]);
        return 0;
    }

    while((buffer = fgetc(in)) != EOF)
    {
        fputc(buffer, out);
    }
    fclose(in);
    fclose(out);
    return 0;
}
