#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "lock.h"

int validateInput(char c) {
	if(c > '0' && c < '9')
		return 1;
	else if(c == 'r' || c == 'R')
		return 1;
	else if(c == 'q' || c == 'Q')
		exit(EXIT_FAILURE);

	printf("Invalid Input! ");
	return 0;
}

int main(){
	int _l[LC_LEN]; char c[2];

	initLock(_l);

	printf(	"\nSecurity Lock v1.0\n"
			"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"
			"Make all the lock values %i\n\n"
			"Key: 1-8 turns locks\n"
			"     r Resets the locks\n"
			"     q exits the program\n\n",
			LC_TARG);

	while(!checkLock(_l)) {
		printLock(_l);
		
		do {
			printf("Move < 1-8, r, q >: "); fflush(NULL);
			read(STDIN_FILENO, c, 2);
		} while (!validateInput(c[0]));

		if(c[0] == 'r' || c[0] == 'R') {
			initLock(_l);
			continue;
		}

		moveLock(_l, c[0]-0x30);
	}

	printLock(_l);
	printf("All locks are open!\n");
	printf("Your password is d%kj1//..");


	return EXIT_SUCCESS;
}

