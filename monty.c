#include "monty.h"
/**
 * main - Entry point
 * @argc: number of args
 * @argv: array of args
 *
 * Return: 0(success)
 */
int main(int argc, char **argv)
{
	stack_t *head = NULL;
	static char *content[1024] = {NULL}, list[100];
	FILE *fd;
	int n = 0, i = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(list, sizeof(list), fd) != NULL)
		i++;
	rewind(fd);
	for (n = 0; n < i; n++)
	{
		fgets(list, sizeof(list), fd);
		strcpy(content[n], list);
	}
	handle(content, head);
	free_com(content);
	fclose(fd);
	return (0);
}

/**
 * handle - executes opcodes
 * @str: contents of file
 * @head: head of list
 */
void handle(char *str[], stack_t *head)
{
	int ln, n, i, lp;
	instruction_t st[] = {
		{"pall", pall},
		{"add", add},
		{"pop", pop},
		{"swap", swap},
		{"nop", nop},
		{"pint", pint},
		{NULL, NULL}
	};

	for (ln = 1, n = 0; str[n] != NULL; ln++, n++)
	{
		if (_strcmp("push", str[n]))
		{
			lp = getval(str[n], ln);
			push(&head, ln, lp);
		}
		else
		{
			i = 0;
			while (st[i].opcode != NULL)
			{
				if (_strcmp(st[i].opcode, str[n]))
				{
					st[i].f(&head, ln);
					break;
				}
				i++;
			}
			if ((st[i].opcode == NULL) && !(_strcmp(str[n], "\n")))
			{
				fprintf(stderr, "l%u:  unknown instruction %s", ln, str[n]);
				if (!newline(str[n]))
					perror("\n");
				exit(EXIT_FAILURE);
			}
		}
	}
	free_stack(head);
}

/**
 * _strcmp - compares strings
 * @p: string 1
 * @s: string 2
 *
 * Return: 1(success)
 */
int _strcmp(char *p, char *s)
{
	while (*s != '\0')
	{
		if (*s == ' ')
		{
			s++;
		}
		else if (*p == *s)
		{
			p++;
			s++;
			if (*p == '\0' && (*s == ' ' || *s == '\n' || *s == '\0'))
				return (1);
		}
	}
	return (0);
}
