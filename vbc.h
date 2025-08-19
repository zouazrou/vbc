#ifndef VBC_H
#define VBC_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

typedef enum e_type
{
	NUM,
	SUM,
	MLTP,
	PRN_OPN,
	PRN_CLS,
} 		t_type;

typedef	struct s_token
{
	char			word;
	t_type			tp;
	struct s_token	*next;

} 			t_token;

typedef struct s_ast
{
    /*
    ? if :operation == NUM then use 'num'
    ! else use 'left' and 'right'
    */
    t_type operation;
    int num; 

    struct s_ast *left;
    struct s_ast *right;
}   t_ast;

/*****prototypes*******/

void	printtkn(t_token *tkn); //
t_token *tokenization(char *str);
t_token *new_tkn(char val, t_type tp);
void	add_tkn(t_token **head, t_token *token);

/****AST fns****/
t_ast	*new_node(t_token *token, t_type op);
t_ast	*build_ast(t_token *token);


#endif