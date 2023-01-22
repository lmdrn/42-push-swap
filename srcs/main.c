/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:39:23 by lmedrano          #+#    #+#             */
/*   Updated: 2023/01/22 11:27:30 by lmedrano         ###   ########.fr       */
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

void	print_stack(node_list *s)
{
	if (!s)
		return ;
	printf("this value is : %d\n", s->contenu);
	print_stack(s->next);
}

int main(int argc, char **argv )
{
    int i;
	int j;
	int len;
	char **res;
	int numero;
	node_list *stack_a = NULL;
	node_list *stack_b = NULL;
	node_list *new = NULL;

	i = 0;
	len = ft_mot_count(argv[1], ' ');
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
		//tests to be sure it prints the right stuff
		print_stack(stack_a);
		stack_a = *swap_a(&stack_a);
		stack_a = *rotate_down_a(&stack_a);
		stack_a = *rotate_a(&stack_a);
		stack_b = *push_to_b(&stack_a, &stack_b);
		stack_a = *push_to_a(&stack_a, &stack_b);
	}
	return (0);
}
