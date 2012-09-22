/**
 * Main program to copy words from source file to target file, where each word 
 * is on a new line 
 * */

#include <stdio.h>
#include "words_on_newline.h"

#define LINEBREAK printf("\n")

int main(void)
{
	/* Local Declarations */
	int	count_words;
	FILE*	sp_read;
	FILE*	sp_write;

	/* Open files */
	if ((sp_read = fopen("src.txt", "r")) == NULL)
	{
		LINEBREAK;
		printf("ERROR: Could not open 'src.txt' for reading");
		LINEBREAK;
		return -1;
	}

	if ((sp_write = fopen("tgt.txt", "w")) == NULL)
	{
		LINEBREAK;
		printf("ERROR: Could not open 'tgt.txt' for writing");
		LINEBREAK;
		return -1;
	}

	/* Program Intro */
	LINEBREAK;
	printf("I will copy words from a given text file to another, where each word is on its own line");
	LINEBREAK;
	printf("Begin execution...");
	
	/* Call function to copy words */
	LINEBREAK;
	printf("Copying words...");
	count_words = words_on_newline(sp_read, sp_write);

	/* Display result */
	switch (count_words)
	{
		case 0:	LINEBREAK;
			printf("No words found");
			break;

		default:LINEBREAK;
			printf("Done... %d words copied", count_words);
			break;
	}

	/* Close files */
	if (fclose(sp_read) == EOF)
	{
		LINEBREAK;
		printf("ERROR: Could not close 'src.txt'");
		LINEBREAK;
		return -2;
	}

	if (fclose(sp_write) == EOF)
	{
		LINEBREAK;
		printf("ERROR: Could not close 'tgt.txt'");
		LINEBREAK;
		return -2;
	}


	/* Exit Program */
	LINEBREAK; LINEBREAK;
	return 0;
}

