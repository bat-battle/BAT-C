// 提供一个简单的傻瓜式聊天，客户端说什么，服务器就回应什么内容。
// ./server port_no
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<strings.h>
#include<unistd.h>
#include<arpa/inet.h>

#define ERROR -1
#define MAX_CLIENTS 20
#define MAX_DATA 1024

int main(int argc, char **argv)
{
    struct sockaddr_in server;
    struct sockaddr_in client;
    int sock;
    int new;
    int sockaddr_len = sizeof(struct sockaddr_in);
    int data_len;
    char data[MAX_DATA];

    //创建一个本地socket描述符，指定tcp协议，即SOCK_STREAM
    if((sock = socket(AF_INET , SOCK_STREAM, 0)) == ERROR)
    {
        perror("server socket: ");
        exit(-1);   
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[1]));
    server.sin_addr.s_addr = INADDR_ANY;
    bzero(&server.sin_zero,8);

    //把上面socket函数返回的‘本地’描述符命名，即就是把服务器要监听的ip和port绑定到这个描述符上，
    //操作系统就建立了此socket描述符和ip、port联系。类似把电话卡绑定到手机
    if((bind(sock , (struct sockaddr *)&server, sockaddr_len)) == ERROR)
    {
        perror("bind : ");
        exit(-1);
    }

    //绑定之后的描述符，就可以用来监听客户端的连接请求了，操作系统给sock这个描述符创建
    //两个队列（半连接和完全连接），伺候accept函数就根据sock这个描述符去取其队列里维护的客户端请求了
    if((listen(sock, MAX_CLIENTS)) == ERROR)
    {
        perror("listen");
        exit(-1);
    }          

    while(1) //Better signal handling required
    {
        //accept函数返回一个新的描述符，用来唯一标识当前连接的客户端。可以用这个新的描述符去send、recv数据
        //操作系统具体是根据(协议类型，原ip，原port，目的ip，目的port)标识客户端的连接
        if((new = accept(sock, ( struct sockaddr *)&client , &sockaddr_len)) == ERROR)
        {
            perror("accept"); 
            exit(-1); 
        }
        printf("New Client connected from port no %d and IP %s\n",ntohs(client.sin_port),inet_ntoa(client.sin_addr));
        data_len = 1;

        while(data_len)
        {      
            data_len = recv(new,data , MAX_DATA, 0);
            //recv函数返回值小于0，标示失败
            if (data_len < 0)
                continue;
            printf("recv[%d]: %s\n", data_len, data);

            if(data_len)
            {
                send(new, data, data_len, 0);
                data[data_len] = '\0' ; // null the last byte to detect string
                printf("send[%d]: %s\n", data_len, data);
            }
        }
        printf("Client disconnected\n");
        //数据发送完成后，需要及时关闭socket描述符，让系统回收资源，以便其他用户可以使用其port
        close(new);
    }
    close(sock);
    return 0;
}
