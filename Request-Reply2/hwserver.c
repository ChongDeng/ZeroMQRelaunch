//  Hello World server

#include <zmq.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include "../Utils.h"

int main (void)
{
    //  Socket to talk to clients
    void *context = zmq_ctx_new ();
    void *responder = zmq_socket (context, ZMQ_REP);
    int rc = zmq_bind (responder, "tcp://*:5555");
    assert (rc == 0);

    while (1) {
        char *buffer = s_recv(responder);
        printf ("Received: %s\n", buffer);
	free(buffer);

        sleep (1);          //  Do some 'work'
	s_send(responder, "World");        
    }
    return 0;
}
