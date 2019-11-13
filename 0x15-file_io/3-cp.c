#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "holberton.h"

/**
 * main - creates a file.
 * @argc: New file.
 * @argv: The content to write.
 * Return: 1 if worked or -1 if a error ocurred.
 */

int main(int argc, char *argv[])
{
	int ifd, ofd, numread;
	char buf[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	ifd = open(argv[1], O_RDONLY);
	if (ifd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s", argv[1]);
		exit(98);
	}
	ofd = open(argv[2], O_CREAT | O_WRONLY, 0664);
	if (ofd == -1)
	{
		close(ifd);
		dprintf(STDERR_FILENO, "Error: Can't write to %s", argv[2]);
		exit(99);
	}
	while ((numread = read(ifd, buf, 1024)) > 0)
	{
		if (write(ofd, buf, numread) != numread)
			dprintf(STDERR_FILENO, "Error: Can't write to %s", argv[2]);
			exit(99);
	}
	if (numread == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s", argv[1]);
		exit(98);
	}

	if ((close(ifd) == -1) || (close(ofd) == -1))
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d", ifd);
		exit(100);
	}
	exit(EXIT_SUCCESS);
}