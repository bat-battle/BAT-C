/*************************************************************************
	> File Name: main.c
	> Author: 按十进制和字符显示文件代码，若遇不可示字符就用井号"#"字符代替之
	> Mail: 
	> Created Time: 2017年05月05日 星期五 20时39分25秒
 ************************************************************************/

#include<stdio.h>

void main(int argc,char *argv[])
{
    char str[9];
    int ch,count,i;
    FILE *fp;
    if(argc!=2)
    {
        printf("Error format,Usage: dumpf filename\n");
        return;
    }
    if((fp=fopen(argv[1],"r"))==NULL)
    {
        printf("The file %s can not be opened.\n",argv[1]);
        return;
    }
    count=0;
    do{
        i=0;
        //按八进制输出第一列，作为一行八个字节的首地址
        printf("%06o: ",count*8);
        do{
            // 从打开的文件中读取一个字符
            ch=fgetc(fp);
            // 按十进制方式输出这个字符的ASCII码
            printf("%4d",ch);
            // 如果是不可示字符就用"#"字符代替
            if(ch<' '||ch>'~') str[i]='#';
            // 如果是可示字符，就将它存入数组str以便形成字符串
            else str[i]=ch;
            // 保证每一行输出八个字符
            if(++i==8) break;
        }while(ch!=EOF); // 遇到文件尾标志，结束读文件操作
        str[i]='\0'; // 在数组str加字符串结束标志
        for(;i<8;i++) printf(" "); // 一行不足八个字符用空格填充
        printf(" %s\n",str); // 输出字符串
        count++; // 准备输出下一行
    }while(ch!=EOF); // 直到文件结束
    fclose(fp); // 关闭fp所指文件
}
