/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
    > Info: 将文件２的内容追加到文件１的内容后面 
	> Created Time: 2017年05月05日 星期五 20时39分25秒
 ************************************************************************/

#include<stdio.h>

#define SIZE 512

void main(int argc, char *argv[])
{
    char buffer[SIZE] = {'\0'};
    FILE *fp1 = NULL;
    FILE *fp2 = NULL;

    if(argc != 3)
    {
        printf("Usage: linkfile filename1 filename2\n");
        return;
    }
    if((fp1 = fopen(argv[1], "a+")) == NULL)
    {
        printf("The file %s can not be opened.\n", argv[1]);
        return;
    }
    if((fp2 = fopen(argv[2], "r")) == NULL)
    {
        printf("The file %s can not be opened.\n", argv[2]);
        return;
    }
    while(fgets(buffer, SIZE, fp1) != NULL)
    {
        printf("%s\n", buffer);
    }
    while(fgets(buffer, SIZE, fp2) != NULL)
    {
        fputs(buffer, fp1);
    }

    fclose(fp1);
    fclose(fp2);

    if((fp1 = fopen(argv[1], "r")) == NULL)
    {
        printf("The file %s can not be opened.\n", argv[1]);
        return;
    }
    while(fgets(buffer, SIZE, fp1) != NULL)
    {
        printf("%s\n", buffer);
    }
    fclose(fp1);
}
