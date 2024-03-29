#include "monty.h"
/**
 * nop_opcode - does nothing when executed
 * @stack: pointer to the head
 * @line_number: line number
 * Return: void
 */
void nop_opcode(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 * swap_opcode - swaps the top two elements of the stack
 * @stack: pointer to the head
 * @line_number: line number
 * Return: nothing
 */
void swap_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *cur = *stack;
	stack_t *new_node;
	int tmp;

	if (!(*stack))
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n",
				line_number);
		fclose(global.file);
		exit(EXIT_FAILURE);
	}

	if (cur && cur->next)
	{
		new_node = cur->next;
		tmp = cur->n;
		cur->n = new_node->n;
		new_node->n = tmp;
	}
	else
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n",
				line_number);
		fclose(global.file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}
/**
 * sub_opcode - subtracts
 * @stack: pointer to the head of a linked list
 * @line_number: line number
 * Return: void
 */
void sub_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *cur = *stack;
	stack_t *new_node;

	if (!cur || !cur->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = cur->next;
	new_node->n = new_node->n - cur->n;
	pop_opcode(stack, line_number);
}
/**
 * div_opcode - divides the second top element of stack by top element
 * @stack: pointer to the head
 * @line_number: line number
 * Return: void
 */
void div_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *cur = *stack;
	stack_t *new_node;

	if (!cur || !cur->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (cur->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = cur->next;
	new_node->n = new_node->n / cur->n;
	pop_opcode(stack, line_number);
}
/**
 * mul_opcode - divides the second top element of stack by top element
 * @stack: pointer to the head
 * @line_number: line number
 * Return: void
 */
void mul_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *cur = *stack;
	stack_t *new_node;

	if (!cur || !cur->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = cur->next;
	new_node->n = new_node->n * cur->n;
	pop_opcode(stack, line_number);
}
