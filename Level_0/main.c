#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define SOURCE_URI 			"semtex.labs.overthewire.org"
#define SOURCE_PORT_ELF 	"24000"
#define SOURCE_PORT_ELF64 	"24001"
#define SOURCE_PORT_PPC 	"24002"

typedef struct addrinfo addrinfo_t;

int main() {

	addrinfo_t hints, *res, *p;
	int sfd;

	char buffer[2];

	memset(&hints, 0, sizeof(addrinfo_t));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	int status = getaddrinfo(SOURCE_URI, SOURCE_PORT_ELF64, &hints, &res);

	if(status != 0) {
		fprintf(stderr,"FAITAL: %s\n", gai_strerror(status));
		return EXIT_FAILURE;
	}

	for(p = res; p != NULL; p = p->ai_next) {
		sfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
		if(sfd == -1) continue;
		if(connect(sfd, p->ai_addr, p->ai_addrlen) != -1)
			break; /* success */

		close(sfd);
	}

	if(p==NULL) {
		fprintf(stderr, "FAILTAL: Failed to connect\n");
		return EXIT_FAILURE;
	}


	int rcv;
	for(rcv = -1; rcv != 0;) {
		rcv = recv(sfd, (void*)buffer, 2, MSG_WAITALL);
		printf("%c", buffer[0]);
	}

	close(sfd);
	freeaddrinfo(res);

	return EXIT_SUCCESS;
}
