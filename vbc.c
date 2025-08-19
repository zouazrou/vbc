#include "vbc.h"



int	 main(int ac, char **av)
{
	int result = 0;
	t_token *token = NULL;
	t_token *root = NULL;

	if (ac != 2)
		return (printf("put one arg\n"), 0);
	token = tokenization(av[1]);
	printtkn(token); //
	root = build_ast(token);
	printf("result = [%d]\n", result);
	return 0;
}


void	printtkn(t_token *tkn)
{
	while (tkn)
	{
		printf("value = '%c' | type = %d\n", tkn->word, tkn->tp);
		tkn = tkn->next;
	}

}























void	add_tkn(t_token **head, t_token *token)
{
	t_token *tmp = *head;
	if (!*head)
	{
		*head = token;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = token;
}
t_token *tokenization(char *str)
{
	int	 i = -1;
	t_token *head = NULL;

	while (str[++i])
	{
		if (str[i] == '+')
			add_tkn(&head, new_tkn(str[i], SUM));
		else if (str[i] == '*')
			add_tkn(&head, new_tkn(str[i], MLTP));
		else if (str[i] == '(')
			add_tkn(&head, new_tkn(str[i], PRN_OPN));
		else if (str[i] == ')')
			add_tkn(&head, new_tkn(str[i], PRN_CLS));
		else
			add_tkn(&head, new_tkn(str[i], NUM));
	}
	return (head);
}
t_token *new_tkn(char val, t_type tp)
{
	t_token *tkn = malloc(sizeof(t_token *));
	if (!tkn)
		exit(1);
	tkn->word = val;
	tkn->tp = tp;
	tkn->next = NULL;
	return (tkn);
}
