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
//	char ip[] = "172.16.3.118";
//	char ip[] = "172.16.3.42";
//	char ip[] = "192.168.43.189";
//	char ip[] = "192.168.1.176";
	int fd, puerto;
	puerto = 8080;
	//socket
	if ((fd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
		printf("error del socket\n");
		exit(-1);
	}
	//datos del servidor
	server.sin_family = AF_INET;
	server.sin_port = htons(puerto);
	server.sin_addr.s_addr = inet_addr(ip);
	bzero(&(server.sin_zero),8);
	//conectar al servidor
	if(connect(fd, (struct sockaddr*)&server,sizeof(struct sockaddr)) == -1){
		printf("error de connexion()\n");
		exit(-1);
	}
	while(1){
		send(fd,sensor_info,100,0);// Envia mensaje al servidor y se desconecta
//		printf("->%s\n",sensor_info);
		break;
	}
	close(fd);
	return;
}

char* int_to_cha(int i, char b[]){
	char const digitos[] = "0123456789";
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
		*--p = digitos[i%10];
		i = i/10;
	}while(i);

	return b;
}

void sent_data(){
	FILE *fp;
	signed short p = 3;
//	char event00[100] = "cat /home/zd4y/Documents/OperativeSystems/hayka/info.txt";
	char event00[100] = "cat /home/tomsb/Escritorio/sistemas_operativos/LAB/HAYKA/sb/cli_file/value.txt";
	int col = 0;
	int val;
//	char name[100];
	char dato[100] = {'\0'};
	char dig[2];

	//abrir archivo
	if ((fp = popen(event00, "r")) == NULL) {
		printf ("ERROR!! No hay archivo\n");
	}

	while ((val = getc(fp)) != EOF) {
//	while (getc(fp) != EOF) {
///////////////////////////////////////////////////
		if(val == 118){
			char name[2] = {'v'};
		//	strcat(dato,getc(fp));
			strcat(dato,name);
			printf("----->>>%s\n",dato);
		}
//		val = getc(fp); 
//		printf("val->%d\n",val);
////////////////////////////////////////////////////////
		if(val != 10 && val != 118){
			int_to_cha(val-48,dig);
			strcat(dato,dig);
			printf("----->>%s\n",dato);
		}
		else if(val == 10){
			client(dato);
			printf("#----->%s\n",dato);
			dato[0]='\0';
			printf("$----->%s\n",dato);
		}
	}
	fclose(fp);
}

#endif
