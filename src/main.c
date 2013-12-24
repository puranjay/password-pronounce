/**
 * The small program generates a pronouncable (but random) alphanumeric string 
 * of the required length, comprising of a pronouncable alphabetical part and 
 * two trailing digits.
 *
 * The length, as well as number of strings generated can be modified through 
 * command line arguments.
 *
 * Author:	Puranjay Sharma
 * Version:	0.1.0
 * 
 * This program is created under a GPLv2 license.
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <getopt.h>
#include "../include/randrange.h"

#define MAXLENGTH    30

const char vowels[] = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};
const char consonants[] = {'b', 'c', 'C', 'd', 'f', 'F', 'g', 'G', 'h', 'j', 'J', 'k', 'l', 'm', 'M', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};

char* getPwd(int length)
{
	static char buffer[MAXLENGTH];  /* Generated password string */
	int  endnum;			/* Trailing digits */
	int  wordlength;		/* Length of the alphabetical character string */
	int  vowflag = 0;		/* Flag is zero if the previous member of the string was not a vowel*/
        int  i, cx = 0, index;
	
	/* Generate the letters */

	wordlength = length - 2;	/*Since there are two trailing digits, the wordlength is the full length minus two */

	for (i = 0; i < wordlength; i++){
		if (vowflag == 0 && i != (wordlength - 1)){
			index = randRange(10);  /* Generates a random integer between 0 and 9 */
			cx += snprintf (buffer + cx, length + 1 - cx, "%c", vowels[index]);
			vowflag = 1;
		}

		else{
			index = randRange(26);
			cx += snprintf (buffer + cx, length + 1 - cx, "%c", consonants[index]);
			vowflag = 0;
		}
	}
	
	/* Generate the trailing digits */

	endnum = randRange(90) + 10;
	snprintf (buffer + cx, length + 1 - cx, "%d", endnum);

	return buffer;
}


int main(int argc, char **argv)
{
	
	int length, repetitions; /* Store the command line arguments for string length and the number of strings required */
	int opt;
	int i;
	
	srand(time(0));

	if (argc < 3){
		fprintf(stderr, "Usage: %s -l length -n number of passwords\n", argv[0]);
       		exit(EXIT_FAILURE);
	}		

	while ((opt = getopt(argc, argv, "l:n:")) != -1) {
		switch (opt){
			case 'n':
				repetitions = atoi(optarg);
				break;
			case 'l':
				length = atoi(optarg);
				break;
			default:
				fprintf(stderr, "Usage: %s -l length -n number of passwords\n", argv[0]);
				exit (EXIT_FAILURE);
		}
	}
	
	for (i = 0; i < repetitions; i++)
		puts(getPwd(length));
		
	return 0;
}

	

