#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <arpa/inet.h>

void write_file(char const* name,int val){
//	FILE *f = fopen("file.txt","a");
	FILE *f = fopen(name,"a");
	if (f == NULL){
		printf("Error abriendo file!\n");
		exit(1);
	}
	fprintf(f,"%d\n",val);
	fclose(f);
}


void create_file(char const* name){
	remove(name);
	FILE *f = fopen(name,"a");
	fclose(f);
}


int main(int argc, char **argv){
	if(argc > 1){
		struct sockaddr_in server;
		struct sockaddr_in client;
		int fd, fd2, longitud_cliente, puerto;
		char buf[100];
		char name_file[100];
		puerto = atoi(argv[1]);
 
		//Configuracion del servidor
		server.sin_family = AF_INET; //Familia TCP/IP 
		server.sin_port = htons(puerto); //Puerto
		server.sin_addr.s_addr = INADDR_ANY;//Cualker clint pued conctrs
		bzero(&(server.sin_zero),8); //Funcion que rellena con 0's 
 
		 //definicion de socket
		if (( fd = socket(AF_INET,SOCK_STREAM,0) ) < 0){
			perror("Error de apertura de socket");
			exit(-1);
		}
 
		//avisar al sistema que se creo un socket
		if(bind(fd,(struct sockaddr*)&server,sizeof(struct sockaddr)) == -1){
			printf("error en bind() \n");
			exit(-1);
		}
 
		//establecer el socket en listen 
		if(listen(fd,5) == -1) {
			printf("error en listen()\n");
			exit(-1);
		}
 
		//aceptar conexiones

		int val;
		

		while(1){
			longitud_cliente = sizeof(struct sockaddr_in);
			//a continuacion llamada a accept()
			if ((fd2 = accept(fd,(struct sockaddr *)&client,&longitud_cliente)) == -1) {
				printf("error en accept()\n");
				exit(-1);
			}
 
 			recv(fd2,buf,100,0);
			if(buf[0]=='v'){
			//	strcpy(name_file,"");
				strcpy(name_file,buf);
				create_file(name_file);
			}else{
				val = atoi(buf);
				write_file(name_file,val);
			}
//			printf("%d\n",val);
			close(fd2);


		}
		close(fd);
	}
	else{
		printf("NO se ingreso el puerto por parametro\n");
	}
 
	return 0;
 
}
