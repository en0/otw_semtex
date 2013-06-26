#ifndef LOCK_H
#define LOCK_H 1

#include <string.h>

#define LC_LEN 5
#define LC_INIT 300
#define LC_TARG 400

extern void printLock(int[LC_LEN]);
extern void initLock(int[LC_LEN]);
extern void moveLock(int[LC_LEN],int);
extern int checkLock(int[LC_LEN]);

#endif
