#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

ssize_t read_and_write(int src_fd, int dest_fd)
{
ssize_t bytes_read, bytes_written;
char buffer[1024];

while ((bytes_read = read(src_fd, buffer, 1024)) > 0)
{
bytes_written = write(dest_fd, buffer, bytes_read);
if (bytes_written == -1 || bytes_written != bytes_read)
return (-1);
}

return (bytes_read);
}

int main(int argc, char *argv[])
{
int src_fd, dest_fd, close_src, close_dest;

if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}

src_fd = open(argv[1], O_RDONLY);
if (src_fd == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
exit(98);
}

dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
if (dest_fd == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
close(src_fd);
exit(99);
}

if (read_and_write(src_fd, dest_fd) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
close(src_fd);
close(dest_fd);
exit(99);
}

close_src = close(src_fd);
close_dest = close(dest_fd);
if (close_src == -1 || close_dest == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n" (close_src == -1) ? src_fd : dest_fd);
exit(100);
}

return (0);
}
