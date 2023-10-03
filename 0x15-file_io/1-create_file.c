#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "main.h"
#include <unistd.h>

/**
 * create_file - Creates a file write permissions, writes text content to it.
 * @filename: The name of the file to create.
 * @text_content: A string text to write to the file.
 * Description: This function creates the file with the specified permissions,
 * writes the provided text content to it.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int file_d = 0, byte_w = 0, temp = 0;

	if (filename == NULL)
		return (-1);

	file_d = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (file_d == -1)
		return (-1);

	if (text_content == NULL)
		text_content = "";

	while (text_content[temp] != '\0')
		temp++;

	/* Write the text content to the file */
	byte_w = write(file_d, text_content, temp);
	if (byte_w == -1)
	{
		close(file_d);
		return (-1);
	}

	close(file_d);
	return (1);
}
