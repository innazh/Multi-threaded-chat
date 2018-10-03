#ifndef WINSOCK_CLIENT_H_
#define WINSOCK_CLIENT_H_

#include "winsock.h"

class winsock_client : public winsock {
protected:
	SOCKET m_client_socket;
	std::ofstream *m_ofs;
	std::string m_msgToWrite;

	void Print(std::string msg)
	{
		std::cout << msg << std::endl;
		*m_ofs << msg << std::endl;
	}
public:
	char * receive_message(); //receives message from the client_socket
	void send_message(char *); //sends message to the client_socket
	void get_message();			//Receive a message from the server
	void connect_to_tcp_server(); //tries to connect, exits if no server available
	void connect_to_tcp_server_loop(); //keeps trying to connect until successful
	winsock_client(int, std::string, std::ofstream *);
	~winsock_client();
};

#endif