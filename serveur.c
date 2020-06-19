#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h> 
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

int main(){

    int sock = socket(AF_INET, SOCK_STREAM, 0);
      struct sockaddr_in adresse_serveur;
      adresse_serveur.sin_family = AF_INET;
      adresse_serveur.sin_port = htons(9002);
      adresse_serveur.sin_addr.s_addr = INADDR_ANY;
    bind(sock, (struct sockaddr*) &adresse_serveur, sizeof(adresse_serveur));
      listen(sock, 5);
      printf("Le serveur ecoute sur l'adresse: %s et sur le port: %d\n",inet_ntoa(adresse_serveur.sin_addr),htons(9002));
    char msg_rcv[256];
    char coucou[256]="coucou";
    char bonjour[256]="bonjour";
    char rien[256]="";
    int ret;
	for (;;){
	  int accept_client = accept(sock, NULL, NULL);
	  printf("Connecté ...! \n");
	  int msg_du_client = recv(accept_client, msg_rcv, sizeof(msg_rcv), 0);
	  printf("<<\"%s\"\n", msg_rcv);
	if (strncmp(coucou, msg_rcv , 4) == 0 ){
	  printf(">>Bonjour!\n");
	  msg_du_client = send(accept_client, bonjour, sizeof(bonjour), 0);
	  close(accept_client);
	  close(sock);
	 break;
	}
	else
	  printf("reesayer..\n");
	  msg_du_client = send(accept_client, rien, sizeof(rien), 0);
}
    close(sock);
   return 0;
}
