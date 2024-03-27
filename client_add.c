#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1" 
#define SERVER_PORT 8080       

#define CLIENT_IP "127.0.0.1" 
#define CLIENT_PORT 8888      

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <num1> <num2>\n", argv[0]);
        return 1;
    }

    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);

    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Socket creation failed");
        return 1;
    }

    struct sockaddr_in client_address, server_address;
    memset(&client_address, 0, sizeof(client_address));
    client_address.sin_family = AF_INET;
    client_address.sin_port = htons(CLIENT_PORT);
    client_address.sin_addr.s_addr = inet_addr(CLIENT_IP);

    if (bind(client_socket, (struct sockaddr *)&client_address, sizeof(client_address)) == -1) {
        perror("Binding failed");
        return 1;
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    server_address.sin_addr.s_addr = inet_addr(SERVER_IP);

    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Connection failed");
        return 1;
    }

    send(client_socket, &num1, sizeof(num1), 0);
    send(client_socket, &num2, sizeof(num2), 0);

    int sum;
    recv(client_socket, &sum, sizeof(sum), 0);
    printf("Sum received from server: %d\n", sum);

    close(client_socket);

    return 0;
}
