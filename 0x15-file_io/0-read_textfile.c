#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <main.h>

/**
 * read_textfile - Reads and prints a text file to POSIX standard output.
 * @filename: The name of the file to read.
 * @letters: The number of letters to read and print.
 *
 * Description: This function first checks for NULL filename and allocates
 * memory for a buffer to read the file content.
 *
 * Return: The actual number of letters read and printed, or 0 on failure.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t file_descriptor, bytes_read, bytes_written;
	int fd = 0, br = 0, bw = 0;
	char *buffer;

	if (filename == NULL)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);
	br = read(fd, buffer, letters);
	if (br == -1)
	{
		free(buffer);
		return (0);
	}
	bw = write(STDOUT_FILENO, buffer, br);
	if (bw == -1 || bw != br)
	{
		free(buffer);
		return (0);
	}
	free(buffer);
	close(fd);
	return (br);
}
