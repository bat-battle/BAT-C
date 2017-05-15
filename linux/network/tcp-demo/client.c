// ./client ip port

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<strings.h>
#include<arpa/inet.h>

#define ERROR -1
#define BUFFER 1024

int main(int argc, char **argv)
{
           struct sockaddr_in remote_server;
           int sock;
           char input[BUFFER];		
           char output[BUFFER];
           int len;

           //创建一个本地socket描述符，指定tcp协议，即SOCK_STREAM
           if((sock = socket(AF_INET, SOCK_STREAM, 0 )) == ERROR)
            {
                  perror("socket");
                  exit(-1);
            }

            remote_server.sin_family = AF_INET;
            remote_server.sin_port = htons(atoi(argv[2]));
            remote_server.sin_addr.s_addr = inet_addr(argv[1]);
            bzero(&remote_server.sin_zero, 8);
            
            //根据用户从命令行输入的服务器ip和port，连接到服务器，客户端的ip和port有操作系统自动获取并回填给tcp和ip层
            //connect函数触发了三次握手，建立tcp连接。
            //此函数返回后，就可以用sock去通信了。
            if((connect(sock, (struct sockaddr *)&remote_server, sizeof(struct sockaddr_in))) == ERROR)
           { 
               perror("connect");
               exit(-1);           
           }

           while(1)
           {
               printf("input: ");
               //用fgets函数完成从标准输入读取用户的输入，大家也可以用scanf等其他函数
               fgets(input, BUFFER, stdin);
               send(sock, input , strlen(input), 0);

               len = recv(sock, output, BUFFER, 0);
               output[len] = '\0';
               printf("recv from server: %s\n", output);
           }
           //数据发送完成后，需要及时关闭socket描述符，让系统回收资源，以便其他用户可以使用其port
           close(sock);
           return 0;
}
