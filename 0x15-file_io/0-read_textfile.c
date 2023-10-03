#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * read_textfile - Reads and prints a text file to POSIX standard output.
 * @filename: The name of the file to read.
 * @letters: The number of letters to read and print.
 *
 * Description: This function first checks for NULL filename and allocates
 * memory for a buffer to read the file content.
 *
 * Return: The actual number of letters read and printed.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int file_descript, byt_read, byt_write;
	char *buffer;

	if (filename == NULL)
		return (0);
	file_descript = open(filename, O_RDONLY);
	if (file_descript == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);
	byt_read = read(file_descript, buffer, letters);
	if (byt_read == -1)
	{
		free(buffer);
		return (0);
	}
	byt_write = write(STDOUT_FILENO, buffer, byt_read);
	if (byt_write == -1 || byt_write != byt_read)
	{
		free(buffer);
		return (0);
	}
	free(buffer);
	close(file_descript);
	return (byt_read);
}
