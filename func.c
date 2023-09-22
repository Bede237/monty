#include "monty.h"
/**
 * getval - gets push val
 * @list: the list
 * @ln: lin num
 *
 * Return: num
 */
int getval(char *list, int ln)
{
	char *op_cd = "push";

	while (*list != '\0')
	{
		if (*op_cd == *list)
		{
			list++;
			op_cd++;
			if (*op_cd == '\0')
			{
				while (*list)
				{
					if ((*list >= '0' && *list <= '9') || (*list == '-'))
					{
						check_num(list, ln);
						return (atoi(list));
					}
					else if (*list == ' ')
					{
						list++;
					}
					else
					{
						fprintf(stderr, "L%d: usage: push integer\n", ln);
						exit(EXIT_FAILURE);
					}
				}
			}
		}
		else
			list++;
	}
	return (0);
}
/**
 * check_num - cheks num
 * @list: list to check
 * @ln: line num
 *
 * Return: 1
 */
int check_num(char *list, int ln)
{
	while (*list)
	{
		if (*list == '\0' || *list == '\n')
		{
			break;
		}
		else if ((*list >= '0' && *list <= '9') || (*list == ' ') || (*list == '-'))
			list++;
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", ln);
			exit(EXIT_FAILURE);
		}
	}
	return (1);
}
/**
 * newline - checks for new line char
 * @pt: string
 *
 * Return: 1(success)
 */
int newline(char *pt)
{
	char *p = "\n";
	int i = 0;

	while (pt[i] != '\0')
	{
		if (*p == pt[i])
		{
			p++;
			i++;
			if (*p == '\0')
			{
				return (1);
			}
		}
		else
			i++;
	}
	return (0);
}
/**
 * free_com - free com
 * @p: pointer
 */
void free_com(char *p[])
{
	int i = 0;

	while (p[i] != NULL)
	{
		free(p[i]);
		i++;
	}
}
/**
 * free_stack - free list
 * @head: pointer
 */
void free_stack(stack_t *head)
{
	stack_t *temp;

	if (head == NULL)
		return;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
