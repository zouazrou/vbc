#include "vbc_stack.h"
void    push(t_stack **stack, char c)
{
    t_stack *new_node;

    new_node = new_element(c);
    if (!new_node)
        return ;
    new_node->next = *stack;
    *stack = new_node;
}
char    pop(t_stack **stack)
{
    t_stack *temp;
    char    popped;

    if (is_empty(*stack))
        return ('\0');
    temp = *stack;
    popped = temp->c;
    *stack = (*stack)->next;
    free(temp);
    return (popped);
}

char    peek(t_stack *stack)
{
    if (is_empty(stack))
        return ('\0');
    return (stack->c);
}

int     is_empty(t_stack *stack)
{
    return (stack == NULL);
}

void    free_stack(t_stack **stack)
{
    t_stack *temp;

    while (!is_empty(*stack))
    {
        temp = *stack;
        *stack = (*stack)->next;
        free(temp);
    }
}

t_stack *new_element(char c)
{
    t_stack *new_node;
    
    new_node = (t_stack *)malloc(sizeof(t_stack));
    if (!new_node)
        return (NULL);
    new_node->c = c;
    new_node->next = NULL;
    return (new_node);
}
void init_bzero(char *output)
{
    for (int i = 0; i < 512; i++)
    {
        output[i] = 0;
    }
    
}