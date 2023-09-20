#include "shell.h"

/**
 * _eputs - it prints an input string
 * @str: it is the string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
	int b = 0;

	if (!str)
		return;
	while (str[b] != '\0')
	{
		_eputchar(str[b]);
		b++;
	}
}

/**
 * _eputchar - it writes the character c to stderr
 * @d: this is the character to print
 *
 * Return: 1, On success
 * On error, return -1 and errno is set appropriately.
 */
int _eputchar(char d)
{
	static int a;
	static char buf[WRITE_BUF_SIZE];

	if (d == BUF_FLUSH || a >= WRITE_BUF_SIZE)
	{
		write(2, buf, a);
		a = 0;
	}
	if (d != BUF_FLUSH)
		buf[a++] = d;
	return (1);
}

/**
 * _putfd - writes the character d to given fd
 * @d: It is the character to print
 * @fd: The filedescriptor to write to
 *
 * Return: 1, On success.
 * On error, return -1, and errno is set appropriately.
 */
int _putfd(char d, int fd)
{
	static int a;
	static char buf[WRITE_BUF_SIZE];

	if (d == BUF_FLUSH || a >= WRITE_BUF_SIZE)
	{
		write(fd, buf, a);
		a = 0;
	}
	if (d != BUF_FLUSH)
		buf[a++] = d;
	return (1);
}

/**
 * _putsfd - it prints an input string
 * @str: it is the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putsfd(char *str, int fd)
{
	int a = 0;

	if (!str)
		return (0);
	while (*str)
	{
		a += _putfd(*str++, fd);
	}
	return (a);
}

