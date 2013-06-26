#include <stdio.h>

#include "lock.h"

const int _lc_transform[9][LC_LEN] = {
	{  0,   0,   0,   0,   0  },
	{  5,   2,   1,   7,   5  },
	{ 13,  -7,  -4,   1,   5  }, 
	{  9,  12,   9,  70,  -4  },
	{-11,   9,   0,   5, -13  },
	{  4,  17,  12,   9,  24  },
	{ 11, -17,  21,   5,  14  },
	{ 15,  31,  22, -12,   3  },
	{ 19, -12,   4,   3,  -7  }
};

void printLock(int l[LC_LEN]) {
	int i;

	printf("LOCKS ======\n");
	for(i = 0; i < LC_LEN; printf(" -%c-\t%i\n", (l[i]==LC_TARG ? 'O' : 'X'), l[i]), i++);
	printf("------------\n");
}

void initLock(int l[LC_LEN]) {
	int i;
	for(i = 0; i < LC_LEN; l[i++] = LC_INIT);
}

void moveLock(int l[LC_LEN], int v) {
	int i;
	if(v > 8 || v < 0) return;
	for(i = 0; i < LC_LEN; l[i] += _lc_transform[v][i], i++);
}

int checkLock(int l[LC_LEN]) {
	int i;
	for(i = 0; l[i] == LC_TARG && i < LC_LEN; i++);
	return (i == LC_LEN);
}

