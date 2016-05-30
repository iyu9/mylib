#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

char HOST[] = "127.0.0.1";
int PORT = 12345;

int main() {
    struct sockaddr_in server;
    int sock;
    char buf[32];
    int n;

    char *toSendText = "This is a test";

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0) {
        perror("socket");
        printf("%d\n", errno);
        return 1;
    }

    /* 接続先指定用構造体の準備 */
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr(HOST);

    connect(sock, (struct sockaddr *)&server, sizeof(server));

    /* サーバからデータを受信 */
    memset(buf, 0, sizeof(buf));
    n = read(sock, buf, sizeof(buf));

    printf("%d, %s\n", n, buf);

    //送信してみる
    send(sock, toSendText, strlen(toSendText)+1, 0);

    close(sock);

    return 0;
}
