#include <stdio.h>
#include <zmq.h>
#include <unistd.h>
#include "zhelpers.h"
#include <time.h>

void * context; //Global context, because you only need one !

int main( int argc, char * argv[] )
{
    printf("init...\n");
    context = zmq_ctx_new();

    // declare the subscriber and the pusher as ZMQ_SUB and ZMQ_PUSH
    void *sub       = zmq_socket( context, ZMQ_SUB  );
    int hours, minutes, seconds, day, month, year;

    char s[] = "gettime>";
    char c[128];

    // connect the sub socket and declare the topic you want to subscribe to
    zmq_connect( sub, "tcp://benternet.pxl-ea-ict.be:24042" );
    zmq_setsockopt (sub, ZMQ_SUBSCRIBE, s, strlen(s));


    // connect the pusher socket
    void * pusher   = zmq_socket( context, ZMQ_PUSH );
    zmq_connect( pusher, "tcp://benternet.pxl-ea-ict.be:24041" );



    printf("subbed...\n");
    sleep(1);
    while (1) {


           //  Read envelope with address
           char *address = s_recv(sub);

           // Print out message contents
           printf ("[%s]\n", address);

            // init time
           time_t now;
           time(&now);

           struct tm *local = localtime(&now);

           hours = local->tm_hour;
           minutes = local->tm_min;
           seconds = local->tm_sec;

           day = local ->tm_mday;
           month = local->tm_mon +1;
           year = local->tm_year + 1900;

           // logic to handle GMT request
           if(strcmp(address, "gettime>GMT") == 0 ){
               sprintf (c, "givetime>Greenwich mean time is: %02d:%02d:%02d\n", hours, minutes, seconds);
               printf("%s", c);
               zmq_send( pusher, c, strlen(c), 0 );
               break;
           }

           // logic to handle all city requests (city's listed in wikipedia: https://en.wikipedia.org/wiki/List_of_UTC_time_offsets)
           // UTC +01:00
           if(strcmp(address, "gettime>Berlin") == 0 || strcmp(address, "gettime>Rome") == 0 || strcmp(address, "gettime>Paris") == 0 || strcmp(address, "gettime>Madrid") == 0 || strcmp(address, "gettime>Warsaw") == 0 || strcmp(address, "gettime>Lagos") == 0 || strcmp(address, "gettime>Kinshasa") == 0 || strcmp(address, "gettime>Algiers") == 0 || strcmp(address, "gettime>Casablanca") == 0){
               // parse city out of command.
               char * city = strtok(address, ">");
               city = strtok(NULL, ">");

               sprintf (c, "givetime>time in %s is: %02d:%02d:%02d", city, hours, minutes, seconds);
               printf("%s", c);
               zmq_send( pusher, c, strlen(c), 0 );
           }

           // UTC +00:00
           if(strcmp(address, "gettime>London") == 0 || strcmp(address, "gettime>Dublin") == 0 || strcmp(address, "gettime>Lisbon") == 0 || strcmp(address, "gettime>Abidjan") == 0 || strcmp(address, "gettime>Accra") == 0 || strcmp(address, "gettime>Dakar") == 0 ){
               // parse city out of command.
               char * city = strtok(address, ">");
               city = strtok(NULL, ">");

               if((hours<1)){
                   hours = 24;
               }
               sprintf (c, "givetime>time in %s is: %02d:%02d:%02d", city, hours - 1, minutes, seconds);
               printf("%s", c);
               zmq_send( pusher, c, strlen(c), 0 );
           }


          // UTC -03:00
           if(strcmp(address, "gettime>São_Paulo") == 0 || strcmp(address, "gettime>Buenos_Aires") == 0 || strcmp(address, "gettime>Montevideo") == 0){
               // parse city out of command.
               char * city = strtok(address, ">");
               city = strtok(NULL, ">");

               if(hours == 2){
                   hours = 25;
               }
               if(hours == 1){
                   hours = 24;
               }
               sprintf (c, "givetime>time in %s is: %02d:%02d:%02d", city, hours - 3, minutes, seconds);
               printf("%s", c);
               zmq_send( pusher, c, strlen(c), 0 );
           }

           // Gtfo of my RAM ya bitch...
           free(address);
    }

    printf("If you see this something got fucked up...\n");

    // gtfo of here mr. socket tyvm...
    zmq_close( sub );
    printf("Magic!\n");
    zmq_ctx_shutdown( context ); //optional for cleaning lady order (get ready you l*zy f*ck)
    printf("Magic!\n");
    zmq_ctx_term( context ); //cleaning lady goes to work
    printf("KTNXBYE!\n");
    return 0;
}
