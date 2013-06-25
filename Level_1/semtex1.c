/* This is a mockup of the application used to encrypt the data. We will use this to 
 * build a tool that will analize the encryption. This requires some knowledege of the
 * encrpytion. So we already have a good idea of how it works. Our analizer will just 
 * work out the details and give us a correct header for this application.
 *
 * Sample Output: 
 *
 * $ /semtex/semtex1 AAAAAAAAAAAAA
 * encrypting "AAAAAAAAAAAAA"
 * encryption finished: AXMDNNPKTEKUL
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int map[] = { 3, 2, 1, 6, 5, 4, 9, 8, 7, 12, 11, 10, 0 };
int frm[] = { 1, 2, 3, 1, 2, 3, 1, 2, 3,  1,  2,  3, 1 };
//int map[] = { 10,  7, 12, 9,  2, 11,  4,  1,  6, 3,  8,  5, 0 }; /* This is the actual mapping on the server. */
//int frm[] = { 10, 10, 11, 4, 12, 20, 13, 23, 15, 3, 19, 13, 0 }; /* This is the actual transform on the server. */


int main(int argc, char** argv) {
	if(argc != 2) {
		fprintf(stderr, "Usage: /semtex/semtex1 < key >\n");
		return EXIT_FAILURE;
	}

	if(strlen(argv[1]) != 13) {
		fprintf(stderr, "FAITAL: I can only do 13 chars... sorry\n");
		return EXIT_FAILURE;
	}

	void* buffer = malloc(14);
	char* out = (char*)buffer;
	char* src = argv[1];

	memset(buffer,0,14);

	printf("encrypting \"%s\"\n", src);
	//sleep(3);

	int i;
	for(i = 0; i < 13; i++) {
		out[map[i]] = (char)((int)src[i] + frm[i]);
	}

	printf("encryption finished: %s\n", out);

	free(buffer);
	return EXIT_SUCCESS;
}
