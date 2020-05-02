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
           }

           // logic to handle all city requests (city's listed in wikipedia: https://en.wikipedia.org/wiki/List_of_UTC_time_offsets)
           // UTC +12:00
           if(strcmp(address, "gettime>Auckland") == 0 || strcmp(address, "gettime>Suva") == 0 || strcmp(address, "gettime>Petropavlovsk-Kamchatsky") == 0){
               // parse city out of command.
               char * city = strtok(address, ">");
               city = strtok(NULL, ">");

               if(hours == 14){
                   hours = -10;
               }
               if(hours == 15){
                   hours = -9;
               }
               if(hours == 16){
                   hours = -8;
               }
               if(hours == 17){
                   hours = -7;
               }
               if(hours == 18){
                   hours = -6;
               }
               if(hours == 19){
                   hours = -5;
               }
               if(hours == 20){
                   hours = -4;
               }
               if(hours == 21){
                   hours = -3;
               }
               if(hours == 22){
                   hours = -2;
               }
               if(hours == 23){
                   hours = -1;
               }
               if(hours == 24){
                   hours = 0;
               }
               sprintf (c, "givetime>time in %s is: %02d:%02d:%02d", city, hours + 11, minutes, seconds);
               printf("%s", c);
               zmq_send( pusher, c, strlen(c), 0 );
           }

           // UTC +10:00
           if(strcmp(address, "gettime>Sydney") == 0 || strcmp(address, "gettime>Port_Moresby") == 0 || strcmp(address, "gettime>Vladivostok") == 0){
               // parse city out of command.
               char * city = strtok(address, ">");
               city = strtok(NULL, ">");

               if(hours == 16){
                   hours = -8;
               }
               if(hours == 17){
                   hours = -7;
               }
               if(hours == 18){
                   hours = -6;
               }
               if(hours == 19){
                   hours = -5;
               }
               if(hours == 20){
                   hours = -4;
               }
               if(hours == 21){
                   hours = -3;
               }
               if(hours == 22){
                   hours = -2;
               }
               if(hours == 23){
                   hours = -1;
               }
               if(hours == 24){
                   hours = 0;
               }
               sprintf (c, "givetime>time in %s is: %02d:%02d:%02d", city, hours + 9, minutes, seconds);
               printf("%s", c);
               zmq_send( pusher, c, strlen(c), 0 );
           }

           // UTC +09:00
           if(strcmp(address, "gettime>Tokyo") == 0 || strcmp(address, "gettime>Seoul") == 0 || strcmp(address, "gettime>Pyonyang") == 0 || strcmp(address, "gettime>Ambon") == 0 || strcmp(address, "gettime>Yakutsk") == 0){
               // parse city out of command.
               char * city = strtok(address, ">");
               city = strtok(NULL, ">");

               if(hours == 17){
                   hours = -7;
               }
               if(hours == 18){
                   hours = -6;
               }
               if(hours == 19){
                   hours = -5;
               }
               if(hours == 20){
                   hours = -4;
               }
               if(hours == 21){
                   hours = -3;
               }
               if(hours == 22){
                   hours = -2;
               }
               if(hours == 23){
                   hours = -1;
               }
               if(hours == 24){
                   hours = 0;
               }
               sprintf (c, "givetime>time in %s is: %02d:%02d:%02d", city, hours + 8, minutes, seconds);
               printf("%s", c);
               zmq_send( pusher, c, strlen(c), 0 );
           }

           // UTC +08:00
           if(strcmp(address, "gettime>Shanghai") == 0 || strcmp(address, "gettime>Taipei") == 0 || strcmp(address, "gettime>Kuala_Lumpur") == 0 || strcmp(address, "gettime>Signapore") == 0 || strcmp(address, "gettime>Perth") == 0 || strcmp(address, "gettime>Manila") == 0 || strcmp(address, "gettime>Makassar") == 0 || strcmp(address, "gettime>Irkutsk") == 0){
               // parse city out of command.
               char * city = strtok(address, ">");
               city = strtok(NULL, ">");

               if(hours == 18){
                   hours = -6;
               }
               if(hours == 19){
                   hours = -5;
               }
               if(hours == 20){
                   hours = -4;
               }
               if(hours == 21){
                   hours = -3;
               }
               if(hours == 22){
                   hours = -2;
               }
               if(hours == 23){
                   hours = -1;
               }
               if(hours == 24){
                   hours = 0;
               }
               sprintf (c, "givetime>time in %s is: %02d:%02d:%02d", city, hours + 7, minutes, seconds);
               printf("%s", c);
               zmq_send( pusher, c, strlen(c), 0 );
           }

           // UTC +07:00
           if(strcmp(address, "gettime>Jakarta") == 0 || strcmp(address, "gettime>Ho_Chi_Minh_City") == 0 || strcmp(address, "gettime>Bangkok") == 0|| strcmp(address, "gettime>Krasnoyarsk") == 0){
               // parse city out of command.
               char * city = strtok(address, ">");
               city = strtok(NULL, ">");

               if(hours == 19){
                   hours = -5;
               }
               if(hours == 20){
                   hours = -4;
               }
               if(hours == 21){
                   hours = -3;
               }
               if(hours == 22){
                   hours = -2;
               }
               if(hours == 23){
                   hours = -1;
               }
               if(hours == 24){
                   hours = 0;
               }
               sprintf (c, "givetime>time in %s is: %02d:%02d:%02d", city, hours + 6, minutes, seconds);
               printf("%s", c);
               zmq_send( pusher, c, strlen(c), 0 );
           }

           // UTC +06:00
           if(strcmp(address, "gettime>Dhaka") == 0 || strcmp(address, "gettime>Almaty") == 0 || strcmp(address, "gettime>Omsk") == 0){
               // parse city out of command.
               char * city = strtok(address, ">");
               city = strtok(NULL, ">");

               if(hours == 20){
                   hours = -4;
               }
               if(hours == 21){
                   hours = -3;
               }
               if(hours == 22){
                   hours = -2;
               }
               if(hours == 23){
                   hours = -1;
               }
               if(hours == 24){
                   hours = 0;
               }
               sprintf (c, "givetime>time in %s is: %02d:%02d:%02d", city, hours + 5, minutes, seconds);
               printf("%s", c);
               zmq_send( pusher, c, strlen(c), 0 );
           }

           // UTC +05:00
           if(strcmp(address, "gettime>Karachi") == 0 || strcmp(address, "gettime>Tashkent") == 0 || strcmp(address, "gettime>Yekaterinburg") == 0){
               // parse city out of command.
               char * city = strtok(address, ">");
               city = strtok(NULL, ">");

               if(hours == 21){
                   hours = -3;
               }
               if(hours == 22){
                   hours = -2;
               }
               if(hours == 23){
                   hours = -1;
               }
               if(hours == 24){
                   hours = 0;
               }
               sprintf (c, "givetime>time in %s is: %02d:%02d:%02d", city, hours + 4, minutes, seconds);
               printf("%s", c);
               zmq_send( pusher, c, strlen(c), 0 );
           }

           // UTC +04:00
           if(strcmp(address, "gettime>Dubai") == 0 || strcmp(address, "gettime>Baku") == 0 || strcmp(address, "gettime>Tbilisi") == 0 || strcmp(address, "gettime>Yerevan") == 0 || strcmp(address, "gettime>Samara") == 0){
               // parse city out of command.
               char * city = strtok(address, ">");
               city = strtok(NULL, ">");

               if(hours == 23){
                   hours = -2;
               }
               if(hours == 23){
                   hours = -1;
               }
               if(hours == 24){
                   hours = 0;
               }
               sprintf (c, "givetime>time in %s is: %02d:%02d:%02d", city, hours + 3, minutes, seconds);
               printf("%s", c);
               zmq_send( pusher, c, strlen(c), 0 );
           }

           // UTC +03:00
           if(strcmp(address, "gettime>Moscow") == 0 || strcmp(address, "gettime>Istanbul") == 0 || strcmp(address, "gettime>Riyadh") == 0 || strcmp(address, "gettime>Baghdad") == 0 || strcmp(address, "gettime>Addis_Ababa") == 0 || strcmp(address, "gettime>Doha") == 0){
               // parse city out of command.
               char * city = strtok(address, ">");
               city = strtok(NULL, ">");

               if(hours == 23){
                   hours = -1;
               }
               if(hours == 24){
                   hours = 0;
               }
               sprintf (c, "givetime>time in %s is: %02d:%02d:%02d", city, hours + 2, minutes, seconds);
               printf("%s", c);
               zmq_send( pusher, c, strlen(c), 0 );
           }

           // UTC +02:00
           if(strcmp(address, "gettime>Cario") == 0 || strcmp(address, "gettime>Johannesburg") == 0 || strcmp(address, "gettime>Kiev") == 0 || strcmp(address, "gettime>Bucharest") == 0 || strcmp(address, "gettime>Athens") == 0 || strcmp(address, "gettime>Jerulasem") == 0 || strcmp(address, "gettime>Sofia") == 0){
               // parse city out of command.
               char * city = strtok(address, ">");
               city = strtok(NULL, ">");

               if(hours == 24){
                   hours = 0;
               }
               sprintf (c, "givetime>time in %s is: %02d:%02d:%02d", city, hours + 1, minutes, seconds);
               printf("%s", c);
               zmq_send( pusher, c, strlen(c), 0 );
           }

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
                   hours = 26;
               }
               if(hours == 1){
                   hours = 25;
               }
               sprintf (c, "givetime>time in %s is: %02d:%02d:%02d", city, hours - 2, minutes, seconds);
               printf("%s", c);
               zmq_send( pusher, c, strlen(c), 0 );
           }

           // UTC -04:00
           if(strcmp(address, "gettime>Santiago") == 0 || strcmp(address, "gettime>Santo_Domingo") == 0 || strcmp(address, "gettime>Manaus") == 0 || strcmp(address, "gettime>Caracas") == 0 || strcmp(address, "gettime>La_Paz") == 0 || strcmp(address, "gettime>Halifax") == 0 ){
               // parse city out of command.
               char * city = strtok(address, ">");
               city = strtok(NULL, ">");

               if(hours == 3){
                   hours = 27;
               }

               if(hours == 2){
                   hours = 26;
               }

               if(hours == 1){
                   hours = 25;
               }
               if(hours == 0){
                   hours = 24;
               }
               sprintf (c, "givetime>time in %s is: %02d:%02d:%02d", city, hours - 3, minutes, seconds);
               printf("%s", c);
               zmq_send( pusher, c, strlen(c), 0 );
           }

           // UTC -05:00
           if(strcmp(address, "gettime>New_York") == 0 || strcmp(address, "gettime>Toronto") == 0 || strcmp(address, "gettime>Havana") == 0 || strcmp(address, "gettime>Lima") == 0 || strcmp(address, "gettime>Bogotá") == 0 || strcmp(address, "gettime>Kingston") == 0 ){
               // parse city out of command.
               char * city = strtok(address, ">");
               city = strtok(NULL, ">");

               if(hours == 4){
                   hours = 28;
               }
               if(hours == 3){
                   hours = 27;
               }

               if(hours == 2){
                   hours = 26;
               }

               if(hours == 1){
                   hours = 25;
               }
               if(hours == 0){
                   hours = 24;
               }
               sprintf (c, "givetime>time in %s is: %02d:%02d:%02d", city, hours - 4, minutes, seconds);
               printf("%s", c);
               zmq_send( pusher, c, strlen(c), 0 );
           }

           // UTC -06:00
           if(strcmp(address, "gettime>Mexico_City") == 0 || strcmp(address, "gettime>Chicago") == 0 || strcmp(address, "gettime>Guatemala_City") == 0 || strcmp(address, "gettime>Tegucigalpa") == 0 || strcmp(address, "gettime>Winnipeg") == 0 || strcmp(address, "gettime>San_José") == 0 || strcmp(address, "gettime>San_Salvador") == 0 ){
               // parse city out of command.
               char * city = strtok(address, ">");
               city = strtok(NULL, ">");

               if(hours == 5){
                   hours = 29;
               }
               if(hours == 4){
                   hours = 28;
               }
               if(hours == 3){
                   hours = 27;
               }

               if(hours == 2){
                   hours = 26;
               }

               if(hours == 1){
                   hours = 25;
               }
               if(hours == 0){
                   hours = 24;
               }
               sprintf (c, "givetime>time in %s is: %02d:%02d:%02d", city, hours - 5, minutes, seconds);
               printf("%s", c);
               zmq_send( pusher, c, strlen(c), 0 );
           }

           // UTC -07:00
           if(strcmp(address, "gettime>Phoenix") == 0 || strcmp(address, "gettime>Calgary") == 0 || strcmp(address, "gettime>Ciudad_Juárez") == 0){
               // parse city out of command.
               char * city = strtok(address, ">");
               city = strtok(NULL, ">");
               if(hours == 6){
                   hours = 30;
               }
               if(hours == 5){
                   hours = 29;
               }
               if(hours == 4){
                   hours = 28;
               }
               if(hours == 3){
                   hours = 27;
               }

               if(hours == 2){
                   hours = 26;
               }

               if(hours == 1){
                   hours = 25;
               }
               if(hours == 0){
                   hours = 24;
               }
               sprintf (c, "givetime>time in %s is: %02d:%02d:%02d", city, hours - 6, minutes, seconds);
               printf("%s", c);
               zmq_send( pusher, c, strlen(c), 0 );
           }

           // UTC -08:00
           if(strcmp(address, "gettime>Los_Angeles") == 0 || strcmp(address, "gettime>Vancouver") == 0 || strcmp(address, "gettime>Tijuana") == 0){
               // parse city out of command.
               char * city = strtok(address, ">");
               city = strtok(NULL, ">");

               if(hours == 7){
                   hours = 31;
               }
               if(hours == 6){
                   hours = 30;
               }
               if(hours == 5){
                   hours = 29;
               }
               if(hours == 4){
                   hours = 28;
               }
               if(hours == 3){
                   hours = 27;
               }

               if(hours == 2){
                   hours = 26;
               }

               if(hours == 1){
                   hours = 25;
               }
               if(hours == 0){
                   hours = 24;
               }
               sprintf (c, "givetime>time in %s is: %02d:%02d:%02d", city, hours - 7, minutes, seconds);
               printf("%s", c);
               zmq_send( pusher, c, strlen(c), 0 );
           }

           // UTC -09:00
           if(strcmp(address, "gettime>Anchorage") == 0){
               // parse city out of command.
               char * city = strtok(address, ">");
               city = strtok(NULL, ">");

               if(hours == 8){
                   hours = 32;
               }
               if(hours == 7){
                   hours = 31;
               }
               if(hours == 6){
                   hours = 30;
               }
               if(hours == 5){
                   hours = 29;
               }
               if(hours == 4){
                   hours = 28;
               }
               if(hours == 3){
                   hours = 27;
               }

               if(hours == 2){
                   hours = 26;
               }

               if(hours == 1){
                   hours = 25;
               }
               if(hours == 0){
                   hours = 24;
               }
               sprintf (c, "givetime>time in %s is: %02d:%02d:%02d", city, hours - 8, minutes, seconds);
               printf("%s", c);
               zmq_send( pusher, c, strlen(c), 0 );
           }

           // UTC -10:00
           if(strcmp(address, "gettime>Honolulu") == 0){
               // parse city out of command.
               char * city = strtok(address, ">");
               city = strtok(NULL, ">");

               if(hours == 9){
                   hours = 33;
               }
               if(hours == 8){
                   hours = 32;
               }
               if(hours == 7){
                   hours = 31;
               }
               if(hours == 6){
                   hours = 30;
               }
               if(hours == 5){
                   hours = 29;
               }
               if(hours == 4){
                   hours = 28;
               }
               if(hours == 3){
                   hours = 27;
               }

               if(hours == 2){
                   hours = 26;
               }

               if(hours == 1){
                   hours = 25;
               }
               if(hours == 0){
                   hours = 24;
               }
               sprintf (c, "givetime>time in %s is: %02d:%02d:%02d", city, hours - 9, minutes, seconds);
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
