#include "vbc_stack.h"

int is_operator(char c)
{
    return (c == '*' || c == '+' || c == '-' || c == '/');
}
void syntax_err(char *input, int i)
{
    if (input[i] == '(' && !input[i+1])
        exit((printf("syntax error near unexpected token `%c'\n", input[i]), 1));
    if (is_operator(input[i]) && !input[i+1])
        exit((printf("syntax error near unexpected token `%c'\n", input[i]), 1));

}

int priority(char c)
{
    if (c == '+' || c == '-')
        return (1);
    else if (c == '*' || c == '/')
        return (2); 
    return (0); 

}
char *infix2postfix(char *input)
{
    int     i;
    int     p = 0;
    char    *output;
    t_stack *stack = NULL;
    
    output = malloc(512);
    init_bzero(output);

    i = -1;
    while (input[++i])
    {
        if (isdigit(input[i]))
            output[p++] = input[i];
        else if (input[i] == '(' )
            push(&stack, '(');
        else if (input[i] == ')')
        {
            while (!is_empty(stack) && peek(stack) != '(')
                output[p++] = pop(&stack);
            pop(&stack);
        }
        else if (is_operator(input[i]))
        {
            while (!is_empty(stack) && priority(input[i]) <= priority(peek(stack)))
            {
                output[p++] = pop(&stack);
            }
            push(&stack, input[i]);
        }
        else
            exit((printf("syntax error near unexpected token `%c'\n", input[i]), 1));
    }
    while (!is_empty(stack))
    {
        output[p++] = pop(&stack);
    }
    free_stack(&stack);
    return (output);
}

int main(int ac, char **av)
{
    char *input;
    char *output;

    if (ac != 2)
        return (printf("Input\n"), 0);
    input = av[1];
    printf("Input = [%s]\n", input);

    output = infix2postfix(input);
    printf  ("\n==========\n%s\n", output);
    printf("\nRESULT IS = %.2f\n", eval(output));
    free(output);
    return 0;
}
// is (operato priorete > that in stack) push it in stack
// else pop from stack