/*************************************************************************
	> File Name: main.c
	> Author: 将一个文件的内容复制到另一个文件中去
	> Mail: 
	> Created Time: 2017年05月05日 星期五 20时39分25秒
 ************************************************************************/

#include<stdio.h>

void main(int argc,char *argv[]) //命令行参数
{
    int ch;
    FILE *in,*out; //定义in和out两个文件类型指针
    if(argc!=3) //判断命令行是否正确
    {
        printf("Error in format,Usage: copyfile filename1 filename2\n");
        return; //命令行错，结束程序的执行
    }
    //按读方式打开由argv[1]指出的文件
    if((in=fopen(argv[1],"r"))==NULL)
    {
        printf("The file <%s> can not be opened.\n",argv[1]);
        return; //打开失败，结束程序的执行
    }
    //成功打开了argv[1]所指文件，再
    //按写方式打开由argv[2]指出的文件
    if((out=fopen(argv[2],"w"))==NULL)
    {
        printf("The file %s can not be opened.\n",argv[2]);
        return; //打开失败，结束程序的执行
    }
    //成功打开了argv[2]所指文件
    ch=fgetc(in); //从in所指文件的当前指针位置读取一个字符
    while(ch!=EOF) //判断刚读取的字符是否是文件结束符
    {
        fputc(ch,out); //若不是结束符，将它写入out所指文件
        ch=fgetc(in); //继续从in所指文件中读取下一个字符
    } //完成将in所指文件的内容写入（复制）到out所指文件中
    fclose(in); //关闭in所指文件
    fclose(out); //关闭out所指文件
}
