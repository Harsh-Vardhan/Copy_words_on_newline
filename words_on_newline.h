/**
 * Copy words from source file to target file, where each word is on a new line 
 *
 * \param	sp_read		stream pointer to source text file
 * \param	sp_write	stream pointer to target text file
 *
 * \return	count_words	number of words found in the source text file
 * */

int words_on_newline(FILE* sp_read, FILE* sp_write)
{
	/* Local Declarations */
	int	count_words = 0;
	int	count_spaces = 0;
	char	ch;
	char	marker_pos;

	marker_pos = 'O';
	while ((ch = fgetc(sp_read)) != EOF)
	{
		/* if ch == whitespace */
		if (ch == ' ' || ch == '\t' || ch == '\n')
		{
			count_spaces++;
			marker_pos = 'O';
		}
		/* else if marker is positioned outside word */
		else if (marker_pos == 'O')
		{
			/* then this is the beginning of a new word
			 * update marker as positioned inside word */
			marker_pos = 'I';

			/* if this is not the first word of the source file
			 * start a newline on target file */
			if (count_words > 1)
				fputc('\n', sp_write);

			/* copy character to target file */
			fputc(ch, sp_write);
			
			/* update number of words found */
			count_words++;
		}
		/* else marker is positioned inside word */
		else
		{
			/* copy character to target file */
			fputc(ch, sp_write);
		}
	}

	/* Display count of whitespaces found */
	printf("\n**%d whitespaces found", count_spaces);

	/* Exit Function */
	return count_words;
}

