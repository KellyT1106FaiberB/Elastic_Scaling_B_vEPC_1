#include "udp_client.h"

UdpClient::UdpClient() {
	conn_fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	g_utils.handle_type1_error(conn_fd, "Socket error: udpclient_udpclient");
	port = g_freeport;
}

void UdpClient::conn(string arg_ip_addr, string arg_server_ip_addr, int arg_server_port) {
	init(arg_ip_addr, arg_server_ip_addr, arg_server_port);
	g_nw.bind_sock(conn_fd, sock_addr);
	set_port();
	g_nw.set_rcv_timeout(conn_fd, 1);
}
void UdpClient::conn_refresh() {
	cout<<"refreshing with:"<<ip_addr<<"|"<<server_ip_addr<<"|"<<server_port<<"|"<<endl;
	conn_fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	g_utils.handle_type1_error(conn_fd, "Socket error: udpclient_udpclient");
	port = g_freeport;
	conn(ip_addr,server_ip_addr,server_port);
	//set_server(server_ip_addr,server_port);
}
void UdpClient::set_client(string arg_ip_addr) {
	ip_addr = arg_ip_addr;
	g_nw.set_inet_sock_addr(ip_addr, port, sock_addr);
	g_nw.bind_sock(conn_fd, sock_addr);
	set_port();	
	g_nw.set_rcv_timeout(conn_fd, 1);
}

void UdpClient::set_server(string arg_server_ip_addr, int arg_server_port) {
	server_port = arg_server_port;
	server_ip_addr = arg_server_ip_addr;
	g_nw.set_inet_sock_addr(server_ip_addr, server_port, server_sock_addr);
}

void UdpClient::init(string arg_ip_addr, string arg_server_ip_addr, int arg_server_port) {
	int status;

	ip_addr = arg_ip_addr;
	g_nw.set_inet_sock_addr(ip_addr, port, sock_addr);
	server_port = arg_server_port;
	server_ip_addr = arg_server_ip_addr;
	g_nw.set_inet_sock_addr(server_ip_addr, server_port, server_sock_addr);
}

void UdpClient::set_port() {
	g_nw.get_sock_addr(conn_fd, sock_addr);
	port = ntohs(sock_addr.sin_port);
}

int UdpClient::snd(Packet pkt) {
	int status;
	int err_code = 0;
	while (1) {
		status = sendto(conn_fd, pkt.data, pkt.len, 0, (sockaddr*)&server_sock_addr, g_sock_addr_len);
		if (errno == EPERM || errno == EINVAL) {
			errno = 0;
			usleep(10);
			continue;
		}
		else if (errno == EAGAIN){
			close(conn_fd);errno = 0;	
			conn_refresh();	
			err_code = -1;
			break;	
		}
		else {
			break;
		}
	}
	
	g_utils.handle_type2_error(status, "Sendto error: udpclient_snd");
	return err_code;
}

int UdpClient::rcv(Packet &pkt) {
	int status;
	int err_code = 0;

	pkt.clear_pkt();
	status = recvfrom(conn_fd, pkt.data, BUF_SIZE, 0, (sockaddr*)&server_sock_addr, &g_sock_addr_len);
	if (errno == EAGAIN){
		close(conn_fd);errno = 0;
		conn_refresh();
		err_code = -1;		
		
	}
	g_utils.handle_type2_error(status, "Recvfrom error: udpclient_rcv");
	pkt.data_ptr = 0;
	pkt.len = status;
}

UdpClient::~UdpClient() {
	close(conn_fd);
}
