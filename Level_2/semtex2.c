#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

	uid_t id = geteuid();
	printf("EUID == %i\n", id);
	if(id != 666) {
		printf("This is not the devils number. Think dynamically!\n");
		return EXIT_FAILURE;
	}
	
	printf("The devils number is 666, the devils password is jJjl2Msl\n");
	return EXIT_SUCCESS;

}

