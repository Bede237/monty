#include "monty.h"

/**
 * pint - prints firts element
 * @stack: pointer to head
 * @ln: line number
 */
void pint(stack_t **stack, unsigned int ln)
{
	stack_t *tmp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", ln);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", tmp->n);
}

/**
 * add - adds top two vals
 * @stack: pointer to head
 * @ln: line num
 */
void add(stack_t **stack, unsigned int ln)
{
	int len = list_len(*stack);
	int i, j, n;
	stack_t *temp = *stack;

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack to short\n", ln);
		exit(EXIT_FAILURE);
	}
	i = temp->n;
	j = temp->next->n;
	n = i + j;
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
	(*stack)->n = n;
	(*stack)->prev = NULL;
}
/**
 * list_len - gets length of list
 * @stack: pointer to head
 *
 * Return: num of nodes
 */
int list_len(stack_t *stack)
{
	int count = 0;

	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}
