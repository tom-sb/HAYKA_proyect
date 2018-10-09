#ifndef __CONNECT_H__
#define __CONNECT_H__

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <unistd.h>
#include <strings.h>
#include <string.h>
#include <arpa/inet.h>

void client(char const *sensor_info){
	struct sockaddr_in server;
	char ip[] = "192.168.0.13";
	int fd, puerto;
	puerto = 8080;
	//socket
	if ((fd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
		printf("socket() error\n");
		exit(-1);
	}
	//datos del servidor
	server.sin_family = AF_INET;
	server.sin_port = htons(puerto);
	server.sin_addr.s_addr = inet_addr(ip);
	bzero(&(server.sin_zero),8);
	//conectar al servidor
	if(connect(fd, (struct sockaddr*)&server,sizeof(struct sockaddr)) == -1){
		printf("connect() error\n");
		exit(-1);
	}
	while(1){
		send(fd,sensor_info,100,0);// Envia mensaje al servidor y se desconecta
		break;
	}
	close(fd);
	return;
}

char* itoa(int i, char b[]){
	char const digit[] = "0123456789";
	char* p = b;
	int shifter = i;
	// Moverse a donde termina la representación
	do{
		++p;
		shifter = shifter/10;
	}while(shifter);

	*p = '\0';
	// Retrocede, insertando dígitos a medida que se avanza
	do{
		*--p = digit[i%10];
		i = i/10;
	}while(i);

	return b;
}

void sent_data(){
	FILE *fp;
	signed short p = 3;
	char event00[100] = "cat /home/zd4y/Documents/OperativeSystems/hayka/info.txt";
	int col = 0;
	int val;
	char dato[100] = {'\0'};
	char dig[2];

	//abrir archivo
	if ((fp = popen(event00, "r")) == NULL) {
		printf ("ERROR!! No such file\n");
	}

	while ((val = getc(fp)) != EOF) {
		if(val != 10){
			itoa(val-48,dig);
			strcat(dato,dig);
		}
		else if(val == 10){
			puts(dato);
			client(dato);
			dato[0]='\0';
		}
	}
	fclose(fp);
}

#endif
