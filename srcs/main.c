/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:39:23 by lmedrano          #+#    #+#             */
/*   Updated: 2023/01/27 17:24:06 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>


//warning ! tu pensera bien a utiliser TON ft_printf avant de push !!
int	ft_mot_count(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			word++;
			while (s[i] != c && s[i] != '\0')
					i++;
		}
		else
			i++;
	}
	return (word);
}

node_list	*lst_addnew(int contenu)
{
	node_list *list;

	list = malloc(sizeof(node_list));
	if (list == NULL)
		return (NULL);
	list->contenu = contenu;
	list->next = NULL;
	return (list);
}

void	lst_addback(node_list **lst, node_list *new)
{
	node_list	*list;

	list = *lst;
	if (*lst && new)
	{
		while (list->next)
			list = list->next;
		list->next = new;
	}
	else
	{
		*lst = new;
	}
}

void	print_stack(node_list *stack)
{
	if (!stack)
		return ;
	printf("--- BEGINNING STACK ---\n");
	while (stack != NULL)
	{
		printf("%d\n", stack->contenu);
		stack = stack->next;
	}
	printf("--- END STACK ---\n");
}

int main(int argc, char **argv )
{
    int i;
	int j;
	int len;
	char **res;
	int numero;
	node_list *stack_a = NULL;
	//node_list *stack_b = NULL;
	node_list *new = NULL;

	i = 0;
	len = ft_mot_count(argv[1], ' ');
	///printf("stack_a length is : %d\n", len);
	if (argc == 2)
	{
		while (i < len)
		{
			res = ft_split(argv[1], ' ');
			i++;
		}
		j = 0;
		while (res[j])
		{
			numero = ft_atoi(res[j]);
			new = lst_addnew(numero);
			lst_addback(&stack_a, new);
			j++;
		}
		if (len == 3)
			push_swap_three(&stack_a);
		else
			//push_swap(&stack_a, &stack_b);
			//printf("pos is : %d\n", elem_pos(&stack_a, 8));
			calculator(&stack_a, 2);
	}
	return (0);
}
