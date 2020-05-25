#include <stdio.h>
#include <zmq.h>
#include <unistd.h>
#include "zhelpers.h"

void * context; //Global context, because you only need one !

int main( int argc, char * argv[] )
{
    printf("init...\n");
    context = zmq_ctx_new();
    void *sub       = zmq_socket( context, ZMQ_SUB  );


    char s[] = "givetime>";
    char s2[] = "givesterrebeeld>";

    // connect the sub socket and declare the topic you want to subscribe to
    zmq_connect( sub, "tcp://benternet.pxl-ea-ict.be:24042" );
    zmq_setsockopt (sub, ZMQ_SUBSCRIBE, s, strlen(s));
    zmq_setsockopt (sub, ZMQ_SUBSCRIBE, s2, strlen(s2));


    // declare the subscriber and the pusher as ZMQ_SUB and ZMQ_PUSH;
    void * pusher   = zmq_socket( context, ZMQ_PUSH );

    // connect the pusher socket
    zmq_connect( pusher, "tcp://benternet.pxl-ea-ict.be:24041" );


    // declare the string to send
    char c[128];
    printf("command: ");
    scanf("%s", c);


    printf("connected all sockets...\n");

    printf("sending data packet...\n");


    // Sending data packet here...
    zmq_send( pusher, c, strlen(c), 0 );


    printf("%s has been sent...\n", c);


    sleep(1);


   //  Read envelope with address
   char *address = s_recv(sub);

   // Print out message contents
   printf ("[%s]\n", address);

   // Gtfo of my RAM ya bitch...
   free(address);


    // gtfo of here mr. socket tyvm...
    zmq_close( pusher );
    // printf("Magic!\n");
    zmq_ctx_shutdown( context ); //optional for cleaning lady order (get ready you l*zy f*ck)
    // printf("Magic!\n");
    zmq_ctx_term( context ); //cleaning lady goes to work
    // printf("KTNXBYE!\n");
    return 0;
}
