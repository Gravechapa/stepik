#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <iostream>
#include <string>
int main()
{
    int mainSocket = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in so;
    so.sin_family = AF_INET;
    so.sin_port = htons(8800);
    so.sin_addr.s_addr = htonl(INADDR_ANY);

    int optval = 1;
    setsockopt (mainSocket, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));
    
    if (bind(mainSocket, (struct sockaddr*) &so, sizeof(so)) != 0 )
        {
            std::cout << "binding failed" <<std::endl;
            return -1;
        }
    if (listen(mainSocket, SOMAXCONN) != 0)
        {
            std::cout << "listening failed" << std::endl;
            return -2;
        }
   int connectedSocket = accept(mainSocket, NULL, NULL);
   
   std::string commandBuffer = "";
   while (true)
    {
        if (commandBuffer.size() == 5)
            commandBuffer = "";
        char buffer;
        recv(connectedSocket, (char*) &buffer, sizeof(buffer), MSG_NOSIGNAL);
        if (buffer == '#' || commandBuffer.size() != 0)
            commandBuffer += buffer;
        send(connectedSocket, &buffer, sizeof(buffer), MSG_NOSIGNAL);
        if (commandBuffer == "#stop")
            break;
    }
    shutdown(connectedSocket, SHUT_RDWR);
    close(connectedSocket);
    return 0;

}
