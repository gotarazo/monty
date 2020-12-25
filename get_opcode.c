#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
EXTERN;
EXT;

/**
* check_instruction -Check for instructions
* @command: Given opcode
* Return: The match fucntion with the given opcode
*/

void (*check_instruction(char *command))(stack_t**, unsigned int)
{
instruction_t instructions[] = {{"pall", pall}, {"pint", pint}, {"pop", pop},
{"swap", swap}, {"add", add}, {"nop", nop}, {"sub", sub}, {"div", _div},
{"mul", mul}, {"mod", mod}, {"pchar", pchar}, {"pstr", pstr}, {"rotl", rotl},
{"rotr", rotr}, {"stack", nop}, {"queue", nop}, {NULL, NULL}};
int i = 0;

while (instructions[i].opcode)
{
if (!strcmp(instructions[i].opcode, command))
return (instructions[i].f);
i++;
}
return (NULL);
}

/**
* execute -Execute the given instruction
* @opcode: Given opcode
* @script: File openned
* @stack: Pointer to stack (DL-List)
*/

void execute(char *opcode, stack_t **stack, FILE *script)
{
void (*function)(stack_t**, unsigned int);
char *ins = strtok(opcode, " \n\t\r");
char *arg = strtok(NULL, " \n\t\r");
int n = 0;

nb_line++;
if (*opcode == '\n' || !ins || *ins == '#')
return;

else if (!strcmp(ins, "queue"))
Queue = 1;

else if (!strcmp(ins, "stack"))
Queue = 0;

else if (!strcmp(ins, "push"))
{
if (!arg)
{
if (*stack)
free_stack(*stack);

fclose(script);
free(opcode);
fprintf(stderr, "L%d: usage: push integer\n", nb_line);
exit(EXIT_FAILURE);
}
check_if_integer(arg);
n = atoi(arg);
if (Queue == 1)
*stack = pushq(stack, n);

else
*stack = push(stack, n);

return;
}
function = check_instruction(ins);
if (!function)
{
if (*stack)
free_stack(*stack);

fclose(script);
fprintf(stderr, "L%d: unknown instruction %s\n", nb_line, ins);
free(opcode);
exit(EXIT_FAILURE);
}
function(stack, nb_line);
}

/**
* check_if_integer -Check if the string is an integer
* @number: String to check
*/

void check_if_integer(char *number)
{
int i = 1;

if ((number[0] >= '0' && number[0] <= '9') || number[0] == '-')
{
while (number[i])
{
if (!(number[i] >= '0' && number[i] <= '9'))
break;
i++;
}
if (!number[i])
return;
}
fprintf(stderr, "L%d: usage: push integer\n", nb_line);
exit(EXIT_FAILURE);
}
