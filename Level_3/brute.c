#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lock.h"

#define SIZE 50


void showTry(int test[]) {
	int i;
	for(i = 0; i < SIZE; printf(" %i",test[i++]));
	printf("\n");
}

void tryMove(int lock[], int test[]) {
	int i;
	initLock(lock);
	for(i = 0; i < SIZE; moveLock(lock,test[i++]));
}

void next(int test[]) {
	int len = SIZE;
	while(--len >= 0) {
		if(++test[len] <= 8) break;
		else test[len]=1;
	}
}

int main() {

	int _l[LC_LEN];
	int test[SIZE];
	memset(test,0,SIZE*sizeof(int));

	printf("Trying to pick the lock...\n");

	while(test[0] < 8) {		
		tryMove(_l,test);
		if(checkLock(_l)) break;
		next(test);
	}

	printLock(_l);
	showTry(test);

	return EXIT_SUCCESS;
}
