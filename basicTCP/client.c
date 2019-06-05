#include <stdio.h>
#include <stdlib.h>

/*include basic socket functionality */
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{

    /*need a place to store socket fd.*/
    int network_socket;

    /* Create a socket*/
    network_socket = socket(AF_INET, SOCK_STREAM, 0);

    /*Need a address to connect to, so need address struct */
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9000); 
    server_address.sin_addr.s_addr = INADDR_ANY;

    /* We now want to connect*/
    int connection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));

    if (connection_status == -1)
    {
        printf("Connection failed! \n");
        return -1;
    }
    else
    {
        printf("Connection success! \n");
    }

    /* we not need to receive some data from the sever */
    char server_response[256];
    int receive_status = recv(network_socket, &server_response, sizeof(server_response), 0);

    if (receive_status == -1)
    {
        printf("failed to get data from server! \n");
        return -1;
    }

    printf("We got: %s \n", server_response);

    /*We not need to close socket */
    close(network_socket);


    return 0;
}
