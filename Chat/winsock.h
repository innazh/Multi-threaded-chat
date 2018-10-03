#ifndef WINSOCK_H
#define WINSOCK_H

#include <windows.networking.sockets.h>
#pragma comment(lib, "Ws2_32.lib")
#include <iostream>
#include <fstream>
#include <string>
#include <thread>

int const MAX_SOCKETS = 2;

class winsock {
protected:
	int m_ver1, m_ver2; 
	int m_port; 
	std::string m_ip; 
	char m_buffer[128];
	WSADATA m_wsa_data;

public:
	winsock(int ver_num_1, int ver_num_2);
	void start_DLLS();
	SOCKET initialize_tcp_socket();
};

#endif WINSOCK_H
