#include "winsock_server.h"

void winsock_server::bind_socket() {
	struct sockaddr_in serv_addr;
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(m_port);
	serv_addr.sin_addr.s_addr = inet_addr(INADDR_ANY);
	if(bind(m_server_socket, (struct sockaddr *)&serv_addr, sizeof(serv_addr))!=0) {
		std::cout << "Could not bind socket" << std::endl;
		closesocket(m_server_socket);
		WSACleanup();
		std::cin.get();
		exit(EXIT_FAILURE);
	}
}

void winsock_server::listen_socket() {
	if (listen(m_server_socket, 5) != 0) {
		std::cout << "Could listen for incoming connections" << std::endl;
		closesocket(m_server_socket);
		WSACleanup();
		std::cin.get();
		exit(EXIT_FAILURE);
	}
}



winsock_server::winsock_server(int port, std::string ip, std::ofstream* ofs) {
	m_port = port;
	m_ip = ip;
	m_ofs = ofs;
}