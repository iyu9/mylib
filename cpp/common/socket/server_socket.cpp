#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

const int PORT = 12345;
const char MESSAGE[] = "Hello, John";

int main() {
    struct sockaddr_in addr;
    struct sockaddr_in client;
    int sock0;
    int sock;
    socklen_t length;

    char buf[2048];
    char inbuf[2048];

    sock0 = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = INADDR_ANY;
    bind(sock0, (struct sockaddr *)&addr, sizeof(addr));
    
    listen(sock0, 5);

    memset(buf, 0, sizeof(buf));
    snprintf(buf, sizeof(buf),
        "HTTP/1.0 200 OK\r\nContent-Length: 20\r\nContent-Type: text/html\r\n\r\nHELLO\r\n");

    while(1) {
        length = (socklen_t)sizeof(client);
        sock = accept(sock0, (struct sockaddr *)&client, &length);
        
        //first
        //write(sock, MESSAGE, sizeof(MESSAGE));

        //for http
        memset(inbuf, 0, sizeof(inbuf));
        recv(sock, inbuf, sizeof(inbuf), 0);

        printf("%s", inbuf);
        send(sock, buf, (int)strlen(buf), 0);
        //

        close(sock);
    }
    close(sock0);

    return 0;
}
