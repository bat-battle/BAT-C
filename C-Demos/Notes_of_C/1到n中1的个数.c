#if 0
问题：

给定一个十进制正整数N，写下从1开始，到N的所有整数，然后数一下其中出现的所有“1”的个数。

例如：
N= 2，写下1，2。这样只出现了1个“1”。

N= 12，我们会写下1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12。这样，1的个数是5。

问题一：

写一个函数f(N),返回1到N之间出现1的个数，比如f（12）= 5。

解法一：

让我们首先想到的一个方法是：遍历1~N，统计每个数1出现的个数，相加便得到所有1的个数。
#endif

//解法一

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long long int Count(long long int n){
    long long int count = 0;
    while(n){
        count += (n % 10 == 1)?1:0;
        n = n / 10;
    }
    return count;
}
int main()
{
    long long int n,i,count;
    while(scanf("%lld",&n) != EOF){
        count = 0;
        for(i = 1;i <= n;i++){
            count += Count(i);
        }
        printf("%lld\n",count);
    }
    return 0;
}

//解法二

#if 0

#include<stdio.h>

long long int Count(long long int n){
    //1的个数
    long long int count = 0;
    //当前位
    long long int Factor = 1;
    //低位数字
    long long int LowerNum = 0;
    //当前位数字
    long long int CurrNum = 0;
    //高位数字
    long long int HigherNum = 0;
    if(n <= 0){
        return 0;
    }
    while(n / Factor != 0){
        //低位数字
        LowerNum = n - (n / Factor) * Factor;
        //当前位数字
        CurrNum = (n / Factor) % 10;
        //高位数字
        HigherNum = n / (Factor * 10);
        //如果为0,出现1的次数由高位决定
        if(CurrNum == 0){
            //等于高位数字 * 当前位数
            count += HigherNum * Factor;
        }
        //如果为1,出现1的次数由高位和低位决定
        else if(CurrNum == 1){
            //高位数字 * 当前位数 + 低位数字 + 1
            count += HigherNum * Factor + LowerNum + 1;
        }
        //如果大于1,出现1的次数由高位决定
        else{
            //（高位数字+1）* 当前位数
            count += (HigherNum + 1) * Factor;
        }
        //前移一位
        Factor *= 10;
    }
    return count;
}

int main(){
    long long int a;
    while(scanf("%lld",&a) != EOF){
        printf("%lld\n",Count(a));
    }
    return 0;
}
#endif
