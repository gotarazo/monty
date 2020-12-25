#include "monty.h"

/**
* push -Push stack
* @stack: Pointer to Stack (DL-List)
* @n: Value
* Return: stack (Top of the stack)
*/

stack_t *push(stack_t **stack, int n)
{
stack_t *top;
top = malloc(sizeof(stack_t));

if (!top)
{
fprintf(stderr, "Error: malloc failed\n");
free(top);
exit(EXIT_FAILURE);
}

top->n = n;
top->prev = NULL;
top->next = *stack;
if (*stack)
(*stack)->prev = top;

*stack = top;
return (*stack);
}

/**
* pushq - add node at the end
* @stack: pointer to head
* @n: number of the new node
* Return: Stack (end of the stack)
*/

stack_t *pushq(stack_t **stack, int n)
{
stack_t *top = NULL, *tmp = NULL;
top = malloc(sizeof(stack_t));
tmp = *stack;

if (!top)
{
fprintf(stderr, "Error: malloc failed\n");
free(top);
exit(EXIT_FAILURE);
}
top->n = n;
top->next = NULL;
if (!*stack)
{
top->prev = NULL;
*stack = top;
return (*stack);
}

while (tmp->next)
tmp = tmp->next;

top->prev = tmp;
tmp->next = top;
return (*stack);
}

/**
* pall -Print all the stack
* @stack: Pointer to stack (DL-List)
* @line_number: Lenght of the list
*/

void pall(stack_t **stack, unsigned int line_number)
{
stack_t *top = *stack;
(void) line_number;
while (top)
{
printf("%d\n", top->n);
top = top->next;
}
}

/**
* free_stack -Free a stack
* @stack: Pointer to stack (DL-List)
*/

void free_stack(stack_t *stack)
{
if (stack)
{
while (stack->next)
{
stack = stack->next;
free(stack->prev);
}
free(stack);
}
}
