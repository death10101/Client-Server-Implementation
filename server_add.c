#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define SERVER_IP "127.0.0.1"

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Socket creation failed");
        return 1;
    }

    struct sockaddr_in server_address, client_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = inet_addr(SERVER_IP);

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Binding failed");
        return 1;
    }

    if (listen(server_socket, 5) == -1) {
        perror("Listening failed");
        return 1;
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            perror("Acceptance failed");
            return 1;
        }

        int num1, num2;
        recv(client_socket, &num1, sizeof(num1), 0);
        recv(client_socket, &num2, sizeof(num2), 0);

        int sum = num1 + num2;
        send(client_socket, &sum, sizeof(sum), 0);

        close(client_socket);
    }

    close(server_socket);

    return 0;
}
