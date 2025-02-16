#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main()
{
    // AF_INET は IPv4（インターネットプロトコルバージョン4） を使うことを指定する定数
    // SOCK_STREAM は TCP（Transmission Control Protocol） を使うことを指定する定数
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1)
    {
        perror("socket failed");
        return 1;
    }

    struct sockaddr_in address;
    address.sin_family = AF_INET;         // アドレスファミリー
    address.sin_addr.s_addr = INADDR_ANY; // 任意のIPアドレス
    address.sin_port = htons(8080);       // ポート番号（8080を使用）

    // bind() でアドレスをソケットに割り当てる
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) == -1)
    {
        perror("bind failed");
        return 1;
    }

    // listen() を使って接続待機状態にする
    if (listen(server_fd, 3) == -1)
    {
        perror("listen failed");
        return 1;
    }

    std::cout << "Listening for connections..." << std::endl;

    // クライアントからの接続を待機し、接続を受け入れる
    int client_fd = accept(server_fd, nullptr, nullptr);
    if (client_fd == -1)
    {
        perror("accept failed");
        return 1;
    }

    std::cout << "Client connected!" << std::endl;

    // 接続が成功したら、ここでクライアントと通信を行う

    close(client_fd);
    close(server_fd);

    return 0;
}
