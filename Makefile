exclient: client.c
	gcc client.c -o client
	./client

compclient: client.c
	gcc client.c -o client

exserv: serveur.c
	gcc serveur.c -o serveur
	./serveur

compserv: serveur.c
	gcc serveur.c -o serveur
