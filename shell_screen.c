#include"main.h"

/**
*shell_launch- launches the program
*@args: takes the list of arguments that we created earlier
*Return: the saved forked process
*/
int shell_launch(char **args)
{
pid_t pid, wpid;
int status;
pid = fork();
if (pid == 0)
{
/*initial process*/
if (execvp(args[0], args) == -1)
{
perror("lsh");
}
exit(EXIT_FAILURE);
}
else if (pid < 0)
{
/* Error occurs*/
perror("lsh");
}
else
{
/* main  process*/
do {
wpid = waitpid(pid, &status, WUNTRACED);
} while (!WIFEXITED(status) && !WIFSIGNALED(status)); }

return (1);
}
