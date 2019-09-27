#include "monty.h"
/**
 * mod_opcode - computes the rest of division
 * @stack: pointer to the head
 * @line_number: line number
 * Return: void
 */
void mod_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *cur = *stack;
	stack_t *new_node;

	if (!cur || !cur->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (cur->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node = cur->next;
	new_node->n = new_node->n % cur->n;
	pop_opcode(stack, line_number);
}
/**
 * pchar_opcode - prints the char at the top of the stack
 * @stack: pointer to the head of a linked list
 * @line_number: the line number
 * Return: void
 */
void pchar_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *cur = *stack;

	if (!(*stack))
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (cur->n < 0 || cur->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", cur->n);
}
