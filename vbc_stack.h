#ifndef VBC_STACK_H
# define VBC_STACK_H

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

typedef struct s_stack
{
	char            c;
	struct s_stack  *next;
}					t_stack;

t_stack *new_element(char c);
void    push(t_stack **stack, char c);
char    pop(t_stack **stack);
char    peek(t_stack *stack);
int     is_empty(t_stack *stack);
void    free_stack(t_stack **stack);
void	init_bzero(char *output);

#endif