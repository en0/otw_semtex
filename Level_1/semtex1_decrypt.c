/* We ran the analyzer against the actual binary on the semtex server. It produced the int map[] and int frm[] 
 * below. All we need to do now is reverse the encryption in the for loop to make a decrpyter.
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_KEY "HRXDZNWEAWWCP"

int map[] = { 10,  7, 12, 9,  2, 11,  4,  1,  6, 3,  8,  5, 0 };
int frm[] = { 10, 10, 11, 4, 12, 20, 13, 23, 15, 3, 19, 13, 0 };

int main(int argc, char** argv) {

	char* src;

	if(argc!=2) src = DEFAULT_KEY;
	else src = argv[1];

	if(strlen(src) != 13) {
		fprintf(stderr, "FAITAL: I can only do 13 chars... sorry\n");
		return EXIT_FAILURE;
	}
	
	void* buffer = malloc(14);
	char* out = (char*)buffer;

	memset(buffer,0,14);

	printf("Decrypting \"%s\"\n", src);

	int i;
	for(i = 0; i < 13; i++) {
		int v = (char)((int)src[map[i]] - frm[i]);
		if(v < 'A') v+=26;
		out[i] = v;
	}

	printf("Decryption finished: %s\n", out);

	free(buffer);
	return EXIT_SUCCESS;
}
