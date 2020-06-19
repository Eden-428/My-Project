#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>

int main(){

   int sock = socket(AF_INET, SOCK_STREAM, 0);
     struct sockaddr_in adresse_serveur;
     adresse_serveur.sin_family = AF_INET;
     adresse_serveur.sin_port = htons(9002);
     adresse_serveur.sin_addr.s_addr = INADDR_ANY;
   int connection_status = connect(sock, (struct sockaddr*) &adresse_serveur, sizeof(adresse_serveur));
     printf("status: %d\n",connection_status);
   if(connection_status == -1){
        printf("Errreur de connection avec le socket\n\n");
   }
   if(connection_status == 0){
        printf("... connecté! \n");
        printf("Adresse du serveur: %s, port: %d\n",inet_ntoa(adresse_serveur.sin_addr),htons(9002));
   }
   char message[256];
   char serveur_reponse[256];
     printf("Msg: ");
     scanf("%s",&message);
     printf(">> %s\n",message);
     send(sock, message, sizeof(message), 0);
     recv(sock, serveur_reponse, sizeof(serveur_reponse),0);
     printf("<< %s\n",serveur_reponse);
     close(socket);
     return 0;
}
