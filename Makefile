compserv: serveur.c
	gcc serveur.c -o serveur -lpthread

exserv: serveur.c
	gcc serveur.c -o serveur -lpthread
	./serveur 8888

exclient: client.c
	gcc client.c -o client -lpthread
	./client 8888

compclient: client.c
	gcc client.c -o client -lpthread

