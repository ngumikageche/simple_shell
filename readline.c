#include"main.h"
#define SHELL_RL_BUFSIZE 1024

/**
 * shell_read_line - reads a line from stdin.
 *
 * Return: returns the current string
 */
char *shell_read_line(void)
{
int bufsize = SHELL_RL_BUFSIZE;
int position = 0;
char *buffer = malloc(sizeof(char) * bufsize);
int c;

if (!buffer)
{
fprintf(stderr, "lsh: allocation error\n");
exit(EXIT_FAILURE);
}
while (1)
{
c = getchar();

if (c == EOF || c == '\n')
{
buffer[position] = '\0';
return (buffer);
}
else
{
buffer[position] = c;
}
position++;

if (position >= bufsize)
{
bufsize += SHELL_RL_BUFSIZE;
buffer = realloc(buffer, bufsize);
if (!buffer)
{
fprintf(stderr, "lsh: allocation error\n");
exit(EXIT_FAILURE);
}
}
}
}
