//  Hello World client
#include <zmq.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "../Utils.h"

int main (void)
{
    printf ("Connecting to hello world server...\n");
    void *context = zmq_ctx_new ();
    void *requester = zmq_socket (context, ZMQ_REQ);
    zmq_connect (requester, "tcp://localhost:5555");

    int request_nbr;
    for (request_nbr = 0; request_nbr != 10; request_nbr++) {
        printf ("Sending Hello %d...\n", request_nbr);
	s_send(requester, "Hello");

	char *buffer = s_recv(requester);
        printf ("Received: %s %d\n", buffer, request_nbr);
	free(buffer);
    }

    zmq_close (requester);
    zmq_ctx_destroy (context);
    return 0;
}
