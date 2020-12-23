#include "monty.h"

/**
* pchar -Prints the character at the top of the stack with a new line
* @stack: Pointer to stack (DL-List)
* @line_number: Lenght of the list
*/

void pchar(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL)
{
fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
exit(EXIT_FAILURE);
}
if ((*stack)->n < 0 || (*stack)->n > 127)
{
fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
exit(EXIT_FAILURE);
}
printf("%c\n", (*stack)->n);
}

/**
* pstr -Prints the string contained in a stack_t linked list
* @stack: Pointer to stack (DL-List)
* @line_number: Lenght of the list
*/

void pstr(stack_t **stack, unsigned int line_number)
{
stack_t *tmp = *stack;

while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
{
printf("%c", tmp->n);
tmp = tmp->next;
}
printf("\n");
(void)line_number;
}

/**
* rotl -Rotates the stack to the top
* @stack: Pointer to stack (DL-List)
* @line_number: Lenght of the list
*/

void rotl(stack_t **stack, unsigned int line_number)
{
stack_t *tmp, *top;
(void)line_number;

if (stack && *stack && (*stack)->next)
{
tmp = *stack;
top = *stack;
*stack = (*stack)->next;
(*stack)->prev = NULL;
while (tmp->next)
tmp = tmp->next;

tmp->next = top;
top->next = NULL;
top->prev = tmp;
}
}

/**
* rotr -Rotates the stack to the bottom
* @stack: Pointer to stack
* @line_number: Lenght of the list
*/

void rotr(stack_t **stack, unsigned int line_number)
{
stack_t *tmp;
(void)line_number;

if (stack && *stack && (*stack)->next)
{
tmp = *stack;
while (tmp->next)
tmp = tmp->next;

tmp->prev->next = NULL;
tmp->prev = NULL;
tmp->next = *stack;
(*stack)->prev = tmp;
*stack = tmp;
}
}
