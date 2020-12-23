#include "monty.h"

/**
* sub -Substracts the top two element from the second top  of the stack
* @stack: Pointer to stack (DL-List)
* @line_number: Lenght of the list
*/

void sub(stack_t **stack, unsigned int line_number)
{
stack_t *tmp;
if (*stack && (*stack)->next)
{
tmp = (*stack)->next;
(*stack)->next->n = (*stack)->next->n - (*stack)->n;
pop(stack, line_number);
*stack = tmp;
}
else
{
fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
free_stack(*stack);
exit(EXIT_FAILURE);
}
}

/**
* div -Divides the second top element of the stack by the top
* @stack: Pointer to stack (DL-List)
* @line_number: Lenght of the list
*/

void _div(stack_t **stack, unsigned int line_number)
{
stack_t *tmp = *stack;

if (*stack && (*stack)->next)
{
if ((*stack)->n != 0)
{
tmp = (*stack)->next;
(*stack)->next->n = (*stack)->next->n / (*stack)->n;
pop(stack, line_number);
*stack = tmp;
}
else
{
fprintf(stderr, "L%d: division by zero\n", line_n);
exit(EXIT_FAILURE);
}
}
else
{
fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
free_stack(*stack);
exit(EXIT_FAILURE);
}
}

/**
* mul -Multiplies the second top element of the stack with the top element
* @stack: Pointer to stack (DL-List)
* @line_number: Lenght of the list
*/

void mul(stack_t **stack, unsigned int line_number)
{
stack_t *tmp = *stack;

if (*stack && (*stack)->next)
{
tmp = (*stack)->next;
(*stack)->next->n = (*stack)->next->n * (*stack)->n;
pop(stack, line_number);
*stack = tmp;
}
else
{
fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
free_stack(*stack);
exit(EXIT_FAILURE);
}
}

/**
* mod -Computes rest of division of 2nd top element by the top element
* @stack: Pointer to stack (DL-List)
* @line_number: Lenght of the list
*/

void mod(stack_t **stack, unsigned int line_number)
{
stack_t *tmp = *stack;

if (*stack && (*stack)->next && (*stack)->n != 0)
{
tmp = (*stack)->next;
(*stack)->next->n = (*stack)->next->n % (*stack)->n;
pop(stack, line_number);
*stack = tmp;
}
else
{
fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
free_stack(*stack);
exit(EXIT_FAILURE);
}
}
