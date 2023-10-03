#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"
#include <sys/types.h>
#include <sys/stat.h>

/**
 * append_text_to_file - Appends text to the end of a file.
 * @filename: The name of the file.
 * @text_content: A NULL-terminated string to add at the end of the file.
 * Description:This function appends text to the end of a file, returning 1
 * 1 on success and -1 on failure. It does not create the file if it
 * doesn't exist, and if text_content is NULL.
 *
 * Return: 1 on success, -1 on failure.
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int file_d = 0, byte_w = 0, node = 0;

	if (filename == NULL)
		return (-1);

	file_d = open(filename, O_RDWR | O_APPEND);
	if (file_d == -1)
		return (-1);

	if (text_content == NULL)
	{
		close(file_d);
		return (1);
	}

	while (text_content[node] != '\0')
		node++;

	byte_w = write(file_d, text_content, node);
	if (byte_w == -1)
	{
		close(file_d);
		return (-1);
	}

	close(file_d);
	return (1);
}
