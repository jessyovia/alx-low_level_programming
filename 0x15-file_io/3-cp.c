#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 1024

/**
 * main - Entry point, copies the content of one file to another.
 * @argc: The number of arguments passed to the program.
 * @argv: An array of argument strings (file_from and file_to).
 * Description: This program first checks the number of arguments
 * and prints the appropriate error message if it's incorrect
 *
 * Return: 0 on success, or an error code as specified in the requirements.
 */

int main(int argc, char *argv[])
{
int src_fileD, dest_fileD, close_src, close_dest;
ssize_t rd, wrt;
char buffer[BUF_SIZE];

if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}

src_fileD = open(argv[1], O_RDONLY);
if (src_fileD == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
exit(98);
}

dest_fileD = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
if (dest_fileD == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
close(src_fileD);
exit(99);
}

while ((rd = read(src_fileD, buffer, BUF_SIZE)) > 0)
{
wrt = write(dest_fileD, buffer, rd);
if (wrt != rd)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
close(src_fileD);
close(dest_fileD);
exit(99);
}
}
close_src = close(src_fileD);
close_dest = close(dest_fileD);
if (close_src == -1 || close_dest == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fileD %d\n",
(close_src == -1) ? src_fileD : dest_fileD);
exit(100);
}

return (0);
}
