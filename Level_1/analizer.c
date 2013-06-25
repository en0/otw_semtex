#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFLEN 255

void *buffer;
int pipefd[2];
const char *c[] = { "./semtex1", "-------------", NULL };

int map[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int frm[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

char* getResp(void* buffer, int rcv) {
	((char*)buffer)[rcv-1]=0;
	return buffer+rcv-14;
}

char* try(char* word) {
	
	int pid;

	if(pipe(pipefd) == -1) {
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	c[1] = word;

	pid = fork();
	switch(pid) {
		case -1:
			perror("fork");
			exit(EXIT_FAILURE);
			break;
		
		case 0:
			close(STDOUT_FILENO);
			dup2(pipefd[1], STDOUT_FILENO);
			close(pipefd[0]);
			execv(c[0],c);
			_exit(EXIT_FAILURE);
			break;

		default:
			close(pipefd[1]);
			wait(pid);
			break;
	}

	int rcv = read(pipefd[0], buffer, BUFFLEN);
	close(pipefd[0]);

	return getResp(buffer, rcv);
}

void setdiff(char* base, char* new, int index) {
	int i;
	for(i = 0; base[i] != 0; i++) {
		if(base[i] != new[i]) {
			printf(" (index %i <= *%i + %i)\n", i, index, (new[i] - 'A' - 1));
			map[index] = i;
			frm[index] = new[i] - 'A' - 1;
		}
	}
}

int main() {
	buffer = malloc(BUFFLEN);
	char* current;
	char base[13];
	char test[14];

	current = try("AAAAAAAAAAAAA");
	memcpy(base, current, 13);
	printf("BASE: 'AAAAAAAAAAAAA' -> '%s'\n", base);
	printf("----------------------------------------\n");
	int i;
	for(i = 0; i < 13; i++) {
		memset((void*)test, 'A', 13); test[13] = 0;
		test[i] = 'B';
		current = try(test);
		printf("-TRY: '%s' -> '%s'", test, current);
		setdiff(base, current, i);
	}
	printf("----------------------------------------\n");

	free(buffer);

	printf("\nMapping and transform: \n");
	printf("int map[] = {");
	for(i = 0; i < 13; i++) 
		printf(" %i,", map[i]);
	printf(" };\n");
		
	printf("int frm[] = {");
	for(i = 0; i < 13; i++)
		printf(" %i,", frm[i]);
	printf(" };\n");

	return EXIT_SUCCESS;
}

