/*************************************************************************
	> File Name: file-test.c
	> Author: 
	> Mail: 
	> Created Time: 2017年05月06日 星期六 13时59分24秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define putchar(ch) fputc(ch, stdout)

int main(int argc, char *argv[])
{

    //char *buffer = (char *)malloc(20);
    //char *buffer = "hello world!";

    int datas[4] = {5, 6, 7, 8};
    FILE *file = NULL;
    int i = 0;

    if((file = fopen(argv[1], "r")) == NULL)
    {
        printf("Open file error!\n");
        return 0;
    }
    //fwrite(datas, sizeof(int), sizeof(datas) / sizeof(int), file);
    fseek(file, sizeof(datas) + 1, SEEK_SET);
    fread(datas, sizeof(int), sizeof(datas) / sizeof(int), file);
    for(i = 0 ; i < sizeof(datas) / sizeof(int); ++i)
    {
        printf("%4d", datas[i]);
    }
    putchar(10);
    fseek(file, 0, SEEK_SET);
    fread(datas, sizeof(int), sizeof(datas) / sizeof(int), file);
    for(i = 0 ; i < sizeof(datas) / sizeof(int); ++i)
    {
        printf("%4d", datas[i]);
    }
    putchar(10);

    /*while((ch = getchar()) != '$') 
    {
        fputc(ch, file);
    }*/

    /*if(EOF == fputs(buffer, file))
    {
        printf("Write file error!\n");
        return 0;
    }*/

    //printf("%s\n", buffer);

    /*while((ch = fgetc(file)) != EOF) 
    {
        putchar(ch);
    }*/
    /*while(!feof(file))
    {
        putchar(fgetc(file));
    }*/
    fclose(file);
    //free(buffer);

    return 0;
}
