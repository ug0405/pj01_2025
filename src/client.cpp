#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_fd == -1)
    {
        perror("socket failed");
        return 1;
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1"); // サーバーのIPアドレス（ローカルホスト）
    server_address.sin_port = htons(8080);                   // サーバーのポート番号

    // サーバーへの接続要求
    if (connect(client_fd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1)
    {
        perror("connect failed");
        return 1;
    }

    std::cout << "Connected to server!" << std::endl;

    close(client_fd);
    return 0;
}
