#include <stdio.h>
#include <zmq.h>
#include <unistd.h>
#include "zhelpers.h"
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>

void * context; //Global context, because you only need one !

// random ass comment for RC branch LULW

bool StartsWith(const char *a, const char *b)
{
   if(strncmp(a, b, strlen(b)) == 0) return 1;
   return 0;
}

int main( int argc, char * argv[] )
{
    printf("init...\n");
    char c[128];
    int i = 0;

    char citiesplus12[100][50];
    char citiesplus11[100][50];
    char citiesplus10[100][50];
    char citiesplus9[100][50];
    char citiesplus8[100][50];
    char citiesplus7[100][50];
    char citiesplus6[100][50];
    char citiesplus5[100][50];
    char citiesplus4[100][50];
    char citiesplus3[100][50];
    char citiesplus2[100][50];
    char citiesplus1[100][50];
    char citiesplus0[100][50];
    char citiesmin1[100][50];
    char citiesmin2[100][50];
    char citiesmin3[100][50];
    char citiesmin4[100][50];
    char citiesmin5[100][50];
    char citiesmin6[100][50];
    char citiesmin7[100][50];
    char citiesmin8[100][50];
    char citiesmin9[100][50];
    char citiesmin10[100][50];
    char citiesmin11[100][50];
    char citiesmin12[100][50];


    context = zmq_ctx_new();

    // char stadje[100][50][2];

    // declare the subscriber and the pusher as ZMQ_SUB and ZMQ_PUSH
    void *sub       = zmq_socket( context, ZMQ_SUB  );
    int hours, minutes, seconds, day, month, year;

    char s[] = "gettime>";
    char s2[] = "sterrebeeld>";
    char s3[] = "getweek>";
    char s4[] = "settime>";


    bool error = true ;
    bool array12 = false;
    bool array11 = false;
    bool array10 = false;
    bool array9 = false;
    bool array8 = false;
    bool array7 = false;
    bool array6 = false;
    bool array5 = false;
    bool array4 = false;
    bool array3 = false;
    bool array2 = false;
    bool array1 = false;
    bool array0 = false;
    bool arraym1 = false;



    // connect the sub socket and declare the topic you want to subscribe to
    zmq_connect( sub, "tcp://benternet.pxl-ea-ict.be:24042" );
    zmq_setsockopt (sub, ZMQ_SUBSCRIBE, s, strlen(s));
    zmq_setsockopt (sub, ZMQ_SUBSCRIBE, s2, strlen(s2));
    zmq_setsockopt (sub, ZMQ_SUBSCRIBE, s3, strlen(s3));
    zmq_setsockopt (sub, ZMQ_SUBSCRIBE, s4, strlen(s4));

    // connect the pusher socket
    void * pusher   = zmq_socket( context, ZMQ_PUSH );
    zmq_connect( pusher, "tcp://benternet.pxl-ea-ict.be:24041" );



    printf("subbed...\n");
    sleep(1);
    while (1) {
        FILE *fileinit;
        fileinit = fopen("steden.txt","r");
        for(i=0;i<1000;i++){
            fgets(c, 100, fileinit);

            char * stad = strtok(c, ",");
            char * timezone = strtok(NULL, ",");

            char buf_a[10];
            char buf_b[50];
            sprintf(buf_a, timezone);
            sprintf(buf_b, stad);

            // printf("%s = ", stad);
            printf("%s", buf_a);

            if( StartsWith(buf_a, "+12:00") == 1 ){

                for(int j = 0;j<100;j++){
                    if(strlen(citiesplus12[j]) == 0){
                        sprintf(citiesplus12[j],"gettime>%s", buf_b);
                        break;
                    }else{
                     //  printf("problemen...");
                    }
                }
            }
            if( StartsWith(buf_a, "+11:00") == 1 ){

                for(int j = 0;j<100;j++){
                    if(strlen(citiesplus11[j]) == 0){
                        sprintf(citiesplus11[j],"gettime>%s", buf_b);
                        break;
                    }else{
                     //  printf("problemen...");
                    }
                }
            }
            if( StartsWith(buf_a, "+10:00") == 1 ){

                for(int j = 0;j<100;j++){
                    if(strlen(citiesplus10[j]) == 0){
                        sprintf(citiesplus10[j],"gettime>%s", buf_b);
                        break;
                    }else{
                     //  printf("problemen...");
                    }
                }
            }
            if( StartsWith(buf_a, "+9:00") == 1 ){

                for(int j = 0;j<100;j++){
                    if(strlen(citiesplus9[j]) == 0){
                        sprintf(citiesplus9[j],"gettime>%s", buf_b);
                        break;
                    }else{
                     //  printf("problemen...");
                    }
                }
            }
            if( StartsWith(buf_a, "+8:00") == 1 ){

                for(int j = 0;j<100;j++){
                    if(strlen(citiesplus8[j]) == 0){
                        sprintf(citiesplus8[j],"gettime>%s", buf_b);
                        break;
                    }else{
                     //  printf("problemen...");
                    }
                }
            }
            if( StartsWith(buf_a, "+7:00") == 1 ){

                for(int j = 0;j<100;j++){
                    if(strlen(citiesplus7[j]) == 0){
                        sprintf(citiesplus7[j],"gettime>%s", buf_b);
                        break;
                    }else{
                     //  printf("problemen...");
                    }
                }
            }
            if( StartsWith(buf_a, "+6:00") == 1 ){

                for(int j = 0;j<100;j++){
                    if(strlen(citiesplus6[j]) == 0){
                        sprintf(citiesplus6[j],"gettime>%s", buf_b);
                        break;
                    }else{
                     //  printf("problemen...");
                    }
                }
            }
            if( StartsWith(buf_a, "+5:00") == 1 ){

                for(int j = 0;j<100;j++){
                    if(strlen(citiesplus5[j]) == 0){
                        sprintf(citiesplus5[j],"gettime>%s", buf_b);
                        break;
                    }else{
                     //  printf("problemen...");
                    }
                }
            }
            if( StartsWith(buf_a, "+4:00") == 1 ){

                for(int j = 0;j<100;j++){
                    if(strlen(citiesplus4[j]) == 0){
                        sprintf(citiesplus4[j],"gettime>%s", buf_b);
                        break;
                    }else{
                     //  printf("problemen...");
                    }
                }
            }
            if( StartsWith(buf_a, "+3:00") == 1 ){

                for(int j = 0;j<100;j++){
                    if(strlen(citiesplus3[j]) == 0){
                        sprintf(citiesplus3[j],"gettime>%s", buf_b);
                        break;
                    }else{
                     //  printf("problemen...");
                    }
                }
            }
            if( StartsWith(buf_a, "+2:00") == 1 ){

                for(int j = 0;j<100;j++){
                    if(strlen(citiesplus2[j]) == 0){
                        sprintf(citiesplus2[j],"gettime>%s", buf_b);
                        break;
                    }else{
                     //  printf("problemen...");
                    }
                }
            }
            if( StartsWith(buf_a, "+1:00") == 1 ){

                for(int j = 0;j<100;j++){
                    if(strlen(citiesplus1[j]) == 0){
                        sprintf(citiesplus1[j],"gettime>%s", buf_b);
                        break;
                    }else{
                     //  printf("problemen...");
                    }
                }
            }
            if( StartsWith(buf_a, "+0:00") == 1 ){

                for(int j = 0;j<100;j++){
                    if(strlen(citiesplus0[j]) == 0){
                        sprintf(citiesplus0[j],"gettime>%s", buf_b);
                        break;
                    }else{
                     //  printf("problemen...");
                    }
                }
            }
            if( StartsWith(buf_a, "-1:00") == 1 ){

                for(int j = 0;j<100;j++){
                    if(strlen(citiesmin1[j]) == 0){
                        sprintf(citiesmin1[j],"gettime>%s", buf_b);
                        break;
                    }else{
                     //  printf("problemen...");
                    }
                }

            }
        }
        fclose(fileinit);



           //  Read envelope with address
           char *address = s_recv(sub);
           char * donotparse = address;
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
           int yday = local ->tm_yday;
           int wday = local ->tm_wday;

           // logic to handle GMT request
           if(strcmp(address, "gettime>GMT") == 0 ){
               sprintf (c, "givetime>Greenwich mean time is: %02d:%02d:%02d\n", hours, minutes, seconds);
               printf("%s", c);
               zmq_send( pusher, c, strlen(c), 0 );

               error = false;
           }

           // logic to handle all city requests (city's listed in wikipedia: https://en.wikipedia.org/wiki/List_of_UTC_time_offsets)
           // UTC +12:00

           for(i=0;i<100;i++){
               if(strcmp(address, citiesplus12[i]) == 0){
                   array12 = true;
                   printf("Pog");
               }else{

               }
           }
           if(array12 ||strcmp(address, "gettime>Auckland") == 0 || strcmp(address, "gettime>Suva") == 0 || strcmp(address, "gettime>Petropavlovsk-Kamchatsky") == 0){
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
               error = false;
               array12 = false;
           }


           for(i=0;i<100;i++){
               if(strcmp(address, citiesplus10[i]) == 0){
                   array10 = true;
                   printf("Pog");
               }else{

               }
           }
           // UTC +10:00
           if(array10 || strcmp(address, "gettime>Sydney") == 0 || strcmp(address, "gettime>Port_Moresby") == 0 || strcmp(address, "gettime>Vladivostok") == 0){
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
               error = false;
               array10 = false;
           }

           for(i=0;i<100;i++){
               if(strcmp(address, citiesplus9[i]) == 0){
                   array9 = true;
                   printf("Pog");
               }else{

               }
           }
           // UTC +09:00
           if(array9 || strcmp(address, "gettime>Tokyo") == 0 || strcmp(address, "gettime>Seoul") == 0 || strcmp(address, "gettime>Pyonyang") == 0 || strcmp(address, "gettime>Ambon") == 0 || strcmp(address, "gettime>Yakutsk") == 0){
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
               error = false;
               array9 = false;
           }

           for(i=0;i<100;i++){
               if(strcmp(address, citiesplus8[i]) == 0){
                   array8 = true;
                   printf("Pog");
               }else{

               }
           }
           // UTC +08:00
           if(array8 || strcmp(address, "gettime>Shanghai") == 0 || strcmp(address, "gettime>Taipei") == 0 || strcmp(address, "gettime>Kuala_Lumpur") == 0 || strcmp(address, "gettime>Signapore") == 0 || strcmp(address, "gettime>Perth") == 0 || strcmp(address, "gettime>Manila") == 0 || strcmp(address, "gettime>Makassar") == 0 || strcmp(address, "gettime>Irkutsk") == 0){
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
               error = false;
               array8 = false;
           }

           for(i=0;i<100;i++){
               if(strcmp(address, citiesplus7[i]) == 0){
                   array7 = true;
                   printf("Pog");
               }else{

               }
           }
           // UTC +07:00
           if(array7 || strcmp(address, "gettime>Jakarta") == 0 || strcmp(address, "gettime>Ho_Chi_Minh_City") == 0 || strcmp(address, "gettime>Bangkok") == 0|| strcmp(address, "gettime>Krasnoyarsk") == 0){
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
               error = false;
               array7 = false;
           }

           for(i=0;i<100;i++){
               if(strcmp(address, citiesplus6[i]) == 0){
                   array6 = true;
                   printf("Pog");
               }else{

               }
           }
           // UTC +06:00
           if(array6 || strcmp(address, "gettime>Dhaka") == 0 || strcmp(address, "gettime>Almaty") == 0 || strcmp(address, "gettime>Omsk") == 0){
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
               error = false;
               array6 = false;
           }
           for(i=0;i<100;i++){
               if(strcmp(address, citiesplus5[i]) == 0){
                   array5 = true;
                   printf("Pog");
               }else{

               }
           }
           // UTC +05:00
           if(array5 || strcmp(address, "gettime>Karachi") == 0 || strcmp(address, "gettime>Tashkent") == 0 || strcmp(address, "gettime>Yekaterinburg") == 0){
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
               error = false;
               array5 = false;
           }
           for(i=0;i<100;i++){
               if(strcmp(address, citiesplus4[i]) == 0){
                   array4 = true;
                   printf("Pog");
               }else{

               }
           }
           // UTC +04:00
           if(array4 || strcmp(address, "gettime>Dubai") == 0 || strcmp(address, "gettime>Baku") == 0 || strcmp(address, "gettime>Tbilisi") == 0 || strcmp(address, "gettime>Yerevan") == 0 || strcmp(address, "gettime>Samara") == 0){
               // parse city out of command.
               char * city = strtok(address, ">");
               city = strtok(NULL, ">");

               if(hours == 22){
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
               error = false;
               array4 = false;
           }

           for(i=0;i<100;i++){
               if(strcmp(address, citiesplus3[i]) == 0){
                   array3 = true;
                   printf("Pog");
               }else{

               }
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
               error = false;
               array3 = false;
           }

           for(i=0;i<100;i++){
               if(strcmp(address, citiesplus2[i]) == 0){
                   array2 = true;
                   printf("Pog");
               }else{

               }
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
               error = false;
               array2 = false;
           }

           for(i=0;i<100;i++){
               if(strcmp(address, citiesplus1[i]) == 0){
                   array1 = true;
                   printf("Pog");
               }else{

               }
           }
           // UTC +01:00
           if(strcmp(address, "gettime>Berlin") == 0 || strcmp(address, "gettime>Rome") == 0 || strcmp(address, "gettime>Paris") == 0 || strcmp(address, "gettime>Madrid") == 0 || strcmp(address, "gettime>Warsaw") == 0 || strcmp(address, "gettime>Lagos") == 0 || strcmp(address, "gettime>Kinshasa") == 0 || strcmp(address, "gettime>Algiers") == 0 || strcmp(address, "gettime>Casablanca") == 0){
               // parse city out of command.
               char * city = strtok(address, ">");
               city = strtok(NULL, ">");

               sprintf (c, "givetime>time in %s is: %02d:%02d:%02d", city, hours + 11, minutes, seconds);
               printf("%s", c);
               zmq_send( pusher, c, strlen(c), 0 );
               error = false;
               array1 = false;
           }




// -------------------------------------------------------------------------------------------------
           for(i=0;i<100;i++){
               if(strcmp(address, citiesplus0[i]) == 0){
                   array0 = true;
                   printf("Pog");
               }else{

               }
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
               error = false;
               array0 = false;
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
               error = false;
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
               error = false;
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
               error = false;
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
               error = false;
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
               error = false;
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
               error = false;
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
               error = false;
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
               error = false;
           }

           // sterrebeeld
           if(StartsWith(address, "sterrebeeld>")){
               char * dag = strtok(address, ">");
               char * maand;
               char * sterrebeeld;

               dag = strtok(NULL, ">");
               maand = strtok(NULL, ">");


               int maandint = atoi(maand);
               int dagint = atoi(dag);

               if(maandint == 1){
                   if(dagint <= 19){
                       sterrebeeld = "Steenbok";
                   }else{
                       sterrebeeld = "Waterman";
                   }

               }

               if(maandint == 2){
                   if(dagint <= 19){
                       sterrebeeld = "Waterman";
                   }else{
                       sterrebeeld = "Vissen";
                   }
               }

               if(maandint == 3){
                   if(dagint <= 20){
                       sterrebeeld = "Vissen";
                   }else{
                       sterrebeeld = "Ram";
                   }
               }

               if(maandint == 4){
                   if(dagint <= 20){
                       sterrebeeld = "Ram";
                   }else{
                       sterrebeeld = "Stier";
                   }
               }

               if(maandint == 5){
                   if(dagint <= 20){
                       sterrebeeld = "Stier";
                   }else{
                       sterrebeeld = "Tweeling";
                   }
               }

               if(maandint == 6){
                   if(dagint <= 21){
                       sterrebeeld = "Tweeling";
                   }else{
                       sterrebeeld = "Kreeft";
                   }
               }

               if(maandint == 7){
                   if(dagint <= 22){
                       sterrebeeld = "Kreeft";
                   }else{
                       sterrebeeld = "Leeuw";
                   }
               }

               if(maandint == 8){
                   if(dagint <= 23){
                       sterrebeeld = "Leeuw";
                   }else{
                       sterrebeeld = "Maagd";
                   }
               }

               if(maandint == 9){
                   if(dagint <= 23){
                       sterrebeeld = "Maagd";
                   }else{
                       sterrebeeld = "Weegschaal";
                   }
               }

               if(maandint == 10){
                   if(dagint <= 23){
                       sterrebeeld = "Weegschaal";
                   }else{
                       sterrebeeld = "Schorpioen";
                   }
               }

               if(maandint == 11){
                   if(dagint <= 22){
                       sterrebeeld = "Schorpioen";
                   }else{
                       sterrebeeld = "Boogschutter";
                   }
               }

               if(maandint == 12){
                   if(dagint <= 21){
                       sterrebeeld = "Boogschutter";
                   }else{
                       sterrebeeld = "Steenbok";
                   }
               }

               if(strlen(sterrebeeld)>1){
                   sprintf (c, "givesterrebeeld>uw sterrebeeld is %s", sterrebeeld);
                   printf("%s\n", c);
                   zmq_send( pusher, c, strlen(c), 0 );
                   error = false;
               }

           }

           // getweek
           if(StartsWith(address, "getweek>")){
               char * dag = strtok(address, ">");
               char * maand;
               char * jaar;

               dag = strtok(NULL, ">");
               maand = strtok(NULL, ">");
               jaar = strtok(NULL, ">");
                printf("%s  %s  %s\n", dag, maand, jaar);
               int dagint = atoi(dag);
               int maandint = atoi(maand);
               int jaarint = atoi(jaar);
               struct tm ts;


                ts.tm_mday = dagint;
                ts.tm_mon = maandint - 1;
                ts.tm_year = jaarint;


                mktime(&ts);

                printf("%d  %d  %d  %d\n", ts.tm_mon, ts.tm_year, ts.tm_mday, ts.tm_yday);

               int weeknummer = (ts.tm_yday + 14 - (ts.tm_wday ? (ts.tm_wday - 1) : 6)) / 7;

               sprintf(c, "giveweek>%d>%d", ts.tm_wday - 1, weeknummer);
               printf("%s\n", c);
               zmq_send( pusher, c, strlen(c), 0);
               error = false;
           }

            // settime
           if(StartsWith(address, "settime>")){
               char * city = strtok(address, ">");
               char * timezone;

               city = strtok(NULL, ">");
               timezone = strtok(NULL, ">");
            FILE * fp;
            int i;

            fp = fopen("steden.txt","a+");
            sprintf(c, "%s,%s\n", city, timezone);
            fputs(c, fp);

            fclose(fp);

               error = false;
           }

           if(error){
               sprintf (c, "givetime>Er is een fout opgetreden, mogelijk hebt u een fout commando ingevoerd. Uw commando: %s", donotparse);
               printf("%s", c);
               zmq_send( pusher, c, strlen(c), 0 );
           }

           // Gtfo of my RAM ya bitch...
           free(address);
           error = true;
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
