/*************************************************************************
	> File Name: split-word.c
	> Author: 
	> Mail: 
	> Created Time: 2017年05月09日 星期二 09时09分20秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void split(const char *source, char words[][20]);
static int isRule(char ch);

int main(int argc, char *argv[])
{
    int i = 0;

    char *source = "reacher is a teacher!";

    char words[10][20] = {'\0'};

    split(source, words);

    for(i = 0; i < 10; ++i)
    {
        if(0 != strlen(words[i]))
        {
            printf("%s\n", words[i]);
        }
    }
    return 0;
}

void split(const char *source, char words[][20])
{
    int i = 0;
    int j = 0;
    int k = 0;

    for(i = 0; ('\0' != source[i]); ++i)
    {
        if(0 == isRule(source[i]))
        {
            words[j][k++] = source[i];
        }
        else
        {
            if(0 != strlen(words[j]))
            {
                j++;
                k = 0;
            }
        }
    }
}

static int isRule(char ch)
{
    char rules[] = {' ', ',', ';', '.', '!'};
    int i = 0;

    for(i = 0; i < sizeof(rules); ++i)
    {
        if(ch == rules[i])
        {
            return 1;
        }
    }
    return 0;
}
