#include <unistd.h>

#define DEVIL 666

uid_t geteuid() {
	return (uid_t)DEVIL;
}
