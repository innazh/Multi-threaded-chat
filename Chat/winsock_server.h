#ifndef WINSOCK_SERVER_H_
#define WINSOCK_SERVER_H_
 
#include "winsock.h"

class winsock_server : public winsock {
protected:
	std::ofstream *m_ofs;
	std::string m_msgToWrite;
	SOCKET m_server_socket, m_connection_socket[MAX_SOCKETS + 1];
	int m_active_sockets[MAX_SOCKETS + 1];

	void Print(std::string msg)
	{
		std::cout << msg << std::endl;
		*m_ofs << msg << std::endl;
	}
public:
	winsock_server(int port, std::string ip, std::ofstream *ofs);
	void bind_socket();
	void listen_socket();
	int find_available_socket(void);
	int accept_connection();
	char * receive_message(int);
	void send_message(char *, int);
	void echo_mode(int); 
	void rec_mode(int socket_number, std::string username);
	void send_mode(); 
	~winsock_server();
};

#endif