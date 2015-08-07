#include "server.h"
#include <sys/socket.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

using namespace std ;

int serverInit( const int port )
{
	//Create a server socket
	int serverFd ;
	if( (serverFd = socket( AF_INET , SOCK_STREAM , 0 )) < 0 ){
		cout << "Failed: socket create failed "<< endl ;
		cout << "errno is " << errno << endl ;
		exit( -1 );
	}
	else{
		cout << "create socket : OK" << endl ;
	}
	//construct a address for this server socket 
	struct sockaddr_in serverAddr;
	bzero( &serverAddr , sizeof( struct sockaddr_in) );
	serverAddr.sin_family = AF_INET;
	//this server can connect any host in the internet
	serverAddr.sin_addr.s_addr = htonl( INADDR_ANY );
	serverAddr.sin_port = htons( port );
	//bind the socket 
	if( bind(serverFd , (struct sockaddr*)(&serverAddr) , sizeof(struct sockaddr)) == -1 ){
		cout << "Faild: socket bind failed" << endl ;
		cout << "The errno is : " << errno << endl ;
		exit( -1 );
	}
	else{
		cout << "bind socket : OK " << endl ;
	}
	//listen this main socket
	if( listen(serverFd , 5 ) == -1 ){
		cout << "Faild: listen function failed " << endl ;
		cout << "errno is " << errno << endl ;
		exit( -1 );
	}
	else{
		cout << "listen socket : OK "<< endl ;
	}
	cout << "socket initial done "<< endl ;
	return serverFd;
}

void closeServer( const int fd )
{
	close( fd );
}

/*
int server::printData()
{
	int i ;
	std::cout << "Print the DateList"<< std::endl ;
	for(i = 0 ; i < dataList.size() ; i ++ ){
		std::cout<< "data[" << i << "] is " << dataList[i] << std::endl ;
	}
	std::cout << "Print done"<< std::endl;
	return i ;
}
*/
int readAll(const int fd , char *buffer , int length )
{
	int bytes_left , bytes_read ;
	char *Ptr = buffer ;
	bytes_left = length ;
	while( bytes_left > 0 ){
		bytes_read = read(fd , Ptr , bytes_left);
		if( bytes_read < 0){
			if(errno == EINTR){
				bytes_read = 0 ;
			}
			else{
				cout << "fatal failt"<<endl;
				exit(-1);
			}
		}
		else if(bytes_read == 0 ){
			break;
		}
		bytes_left -= bytes_read ;
		Ptr += bytes_read;
	}
	return (length - bytes_read);
}

void receiveFile( int clientFd )
{
	char buff[1024];
	int readNum = 0;
	readNum = read(clientFd , buff , 1024);
	buff[ readNum ] = '\0';
	cout <<"buff is " << buff << endl ;
	ofstream file( buff,ios::out);
	if(file.fail()){
		cout << "file:"<<buff << "fialed "<< endl ;
		exit(1);
	}
	cout << buff << ": file open success" << endl ;
	while(1){
		readNum = read(clientFd , buff , 1024);
		cout << "read number of data :" << readNum << endl ;
		if(strcmp(buff , "exit__")==0){
			break;
		}
		file.write( buff , readNum );
	}
	file.close();
	cout << "file close done " << "receiveFile over" << endl ;
}
