#include "winsock.h"

winsock::winsock(int ver_num_1, int ver_num_2) {

	m_ver1 = ver_num_1;
	m_ver2 = ver_num_2;
	
}

void winsock::start_DLLS() {
	if ((WSAStartup(MAKEWORD(m_ver1, m_ver2), &m_wsa_data) != 0)) {
		std::cout << "Could not start up DDLs" << std::endl;
		std::cin.get();
		exit(EXIT_FAILURE);
	}
}

//try: passing socket as a parameter.
SOCKET winsock::initialize_tcp_socket() {
	SOCKET new_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (new_sock == INVALID_SOCKET) {
		std::cout << "Could not initialize socket" << std::endl;
		std::cin.get();
		exit(EXIT_FAILURE);
	}
}