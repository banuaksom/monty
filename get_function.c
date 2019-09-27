#include "monty.h"
/**
 * get_function - gets the opcode function
 * @stack: pointer to stack
 * @line_number: line number
 * Return: int
 */
int get_function(stack_t **stack, unsigned int line_number)
{
	int i;
	instruction_t ops[] = {
		{"push", push_opcode},
		{"pall", pall_opcode},
		{"pint", pint_opcode},
		{"pop", pop_opcode},
		{"swap", swap_opcode},
		{"add", add_opcode},
		{"nop", nop_opcode},
		{"sub", sub_opcode},
		{"div", div_opcode},
		{"mul", mul_opcode},
		{"mod", mod_opcode},
		{"pchar", pchar_opcode},
		{NULL, NULL}};

	if (global.arr_lines[0] == '#')
	{
		ops[6].f(stack, line_number);
		return (0);
	}
	for (i = 0; i != 12; i++)
	{
		if (!(strcmp(ops[i].opcode, global.arr_lines)))
		{
			ops[i].f(stack, line_number);
			break;
		}
	}
	if (i == 12)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n",
				line_number, global.arr_lines);
		free(global.arr_lines);
		fclose(global.file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (0);
}
