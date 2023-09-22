#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/syscall.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void pint(stack_t **stack, unsigned int ln);
void add(stack_t **stack, unsigned int ln);
int list_len(stack_t *stack);
void pall(stack_t **stack, unsigned int ln);
void push(stack_t **stack, unsigned int ln, int n);
void pop(stack_t **stack, unsigned int ln);
void swap(stack_t **stack, unsigned int ln);
void nop(stack_t **stack, unsigned int ln);
void handle(char *str[], stack_t *head);
int _strcmp(char *p, char *s);
int getval(char *list, int ln);
int check_num(char *list, int ln);
int newline(char *pt);
void free_com(char *p[]);
void free_stack(stack_t *head);

#endif
