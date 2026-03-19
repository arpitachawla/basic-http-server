#include<sys/socket.h>
#include<sys/sendfile.h>
#include<unistd.h>
#include<netinet/in.h>
#include<string.h>
#include<fcntl.h>

int main(){
	int sfd= socket(AF_INET, SOCK_STREAM, 0);
	//socket will return non-zero integer, the socket file descriptor after completion of socket call
	//-1 in case it will fail
	
	struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_port = htons(8080);          // Port 8080 in network byte order
        addr.sin_addr.s_addr = INADDR_ANY;    // Bind to all interfaces
        memset(&(addr.sin_zero), 0, 8);  
	
	int b_var= bind(sfd,(const struct sockaddr*)&addr, sizeof(addr));

	//Bind function is used to bind the socket for easy traversal


	int backlog=20;

	listen(sfd,backlog);
	//20 value is just to test it
	//
	int client_fd= (sfd, 0,0);
	char buffer [256]={0};

	recv(client_fd, buffer, 256, 0);
	
	//ssize_t recv( int socket, void *buffer, size_t length, int flags)
	//GET /file.html
	char *f= buffer+5;
	//strchr() is used to locate a character in a string
	
	*strchr(f, ' ')= '0';
        int opened_fd= open(f, O_RDONLY);
	sendfile(client_fd, opened_fd, 0, 256);

	close(opened_fd);

	close(client_fd);

	close(sfd);
}
