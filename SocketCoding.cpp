// 套接字编程
#include <cstdio>
#include <cstdlib>
#include <sys/types.h>
#include <sys/socket.h>
#include <netioapi.h>
#include <netdb.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include <string>
#include <sys/wait.h>

//回送服务器
void Server()
{
    int s;
    int len; //要回送的字符串的长度
    char buffer[256]; //数据缓冲区
    struct sockaddr_in serverAddr; //服务器本地套接字地址
    struct sockaddr_in clientAddr; //客户端套接字地址
    int clientAddrLen; //客户端套接字地址长度

    //建立服务器本地套接字地址
    memset(&serverAddr, 0, sizeof(serverAddr)); //分配内存
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(SERVER_PORT); //默认端口号
    serverAddr.sin_addr.s_addr(INADDR_ANY); //默认IP

    // 创建套接字
    if((s = socket(PF_INEF, SOCK_DGRAM,0)) < 0)
    {
        perror("Error, socket failed!");
        exit(1);
    };

    //将套接字绑定到本地地址和端口
    if((bind(s, (struct socketaddr*)&serverAddr, sizeof(serverAddr)) < 0))
    {
        perror("Error, bind failed!");
        exit(1);
    };

    while(1)  //永远运行
    {

        // 获取字符串
        len = recvfrom(s, buffer, sizeof(buffer), 0,
                        (struct socketaddr*)&clientAddr, 
                        &clientAddrLen);
        //发送字符串
        sendto(s, buffer, len, 0, (struct socketaddr*)&clientAddr,
                sizeof(clientAddr));
    }
}

