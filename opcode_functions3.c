#include "monty.h"
/**
 * mod_opcode - computes the rest of division of second top element by top element
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
