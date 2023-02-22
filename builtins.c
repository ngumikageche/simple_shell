#include"main.h"
/**
 * shell_cd - 1
 * @args: 1
 * @args: 2
 * @args: 3
 * shell_help - 2
 * shell_exit - 3
 * builtin_str - builtin string
 * Return: null
 * Function Declarations for builtin shell commands:
 */
int shell_cd(char **args);
int shell_help(char **args);
int shell_exit(char **args);
char *builtin_str[];
/**
 * builtin_str -  List of builtin commands,
 * followed by their corresponding functions.
 *
 * Returns: builtin functions
 */

char *builtin_str[] = {
"cd",
"help",
"exit"
}

/**
 * return: N/A
 */

int (builtin_func[]) (char *) = {
&shell_cd,
&shell_help,
&shell_exit
};
int shell_num_builtins(void)
{
return (sizeof(builtin_str) / sizeof(char *));
}

/**
 * shell_cd -  implements Builtin functions.
 *@args: arrays of the sub functions

 *Return: when pointer is declared
 */
int shell_cd(char **args)
{
if (args[1] == NULL)
{
fprintf(stderr, "lsh: expected argument to \"cd\"\n");
}
else
{
if (chdir(args[1]) != 0)
{
perror("lsh");
}
}
return (1);
}

/**
 * shell_help - checks if there is a second argument
 * @args: checks for errors
 *
 * Return: if there is an erroe
 */

int shell_help(char **args)
{
int i;
printf("Stephen Brennan's LSH\n");
printf("Type program names and arguments, and hit enter.\n");
printf("The following are built in:\n");

for (i = 0; i < shell_num_builtins(); i++)
{
printf("  %s\n", builtin_str[i]);
}

printf("Use the man command for information on other programs.\n");
return (1);
}

/**
 * shell_exit - exits the terminal
 *@args: takes the string arrays
 *return: zero 0
 */

int shell_exit(char **args)
{
return (0);
}

/**
 * shell_execute - executes the commands
 * @args: checks if commands are equal to builtins
 * return: 1 if null
 */
int shell_execute(char **args)
{
int i;
if (args[0] == NULL)
{
return (1);
}

for (i = 0; i < shell_num_builtins(); i++)
{
if (strcmp(args[0], builtin_str[i]) == 0)
{
return ((*builtin_func[i])(args));
}
}
return (shell_launch(args));
}
