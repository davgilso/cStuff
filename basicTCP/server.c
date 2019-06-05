#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

int main()
{
    char server_message[256] = "You have connected to my server!";

    /* Create the server socket. */
    int server_socket;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    /* Create server address. */
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9000);
    server_address.sin_addr.s_addr = INADDR_ANY;

    /* Now bind connection to IP address */
    bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));

    /* Now listen for connections from clients! */
    listen(server_socket, 1);

    /* Accept connection requests */
    int client_socket;
    client_socket = accept(server_socket, NULL, NULL);

    /* send the message to the connected client */
    send(client_socket, server_message, sizeof(server_message), 0);

    close(server_socket);


    return 0;
}