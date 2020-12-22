#include "monty.h"

/**
*pint -Prints the value at the top of the stack
*@stack: Pointer to stack (DL-List)
*@line_number: Lenght of the list
*/

void pint(stack_t **stack, unsigned int line_number)
{
if (*stack)
printf("%d\n", (*stack)->n);
else
{
fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
exit(EXIT_FAILURE);
}
}

/**
*pop -Removes the top element of the stack
*@stack: Pointer to stack (DL-List)
*@line_number: Lenght of the list
*/

void pop(stack_t **stack, unsigned int line_number)
{
stack_t *tmp;

if (*stack == NULL)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
exit(EXIT_FAILURE);
}
if (!(*stack)->next)
{
free_stack(*stack);
*stack = NULL;
return;
}
else
{
tmp = *stack;
*stack = tmp->next;
tmp->next->prev = NULL;
}
free(tmp);
}

/**
*swap -Swaps the top two elements of the stack
* @stack: Pointer to stack (DL-list)
* @line_number: Lenght of the list
*/

void swap(stack_t **stack, unsigned int line_number)
{
int num;
(void)line_number;

if (*stack && (*stack)->next)
{
num = (*stack)->n;
(*stack)->n = (*stack)->next->n;
(*stack)->next->n = num;
}
else
{
fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
free_stack(*stack);
exit(EXIT_FAILURE);
}
}

/**
* add -Sum adds the top two elements of the stack
* @stack: Pointer to stack (DL-List)
* @line_number: Lenght of the list
*/

void add(stack_t **stack, unsigned int line_number)
{
stack_t *tmp = *stack;

if (*stack && (*stack)->next)
{
*stack = (*stack)->next;
(*stack)->n += tmp->n;
(*stack)->prev = NULL;
pop(&tmp, line_number);
}
else
{
fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
free_stack(*stack);
exit(EXIT_FAILURE);
}
}

/**
* nop -The opcode nop doesn’t do anything
* @stack: Pointer to stack (DL-List)
* @line_number: Lenght of the list
*/

void nop(stack_t **stack, unsigned int line_number)
{
(void)stack;
(void)line_number;
}
