/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manipulations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:15:10 by lmedrano          #+#    #+#             */
/*   Updated: 2023/01/27 11:32:40 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	lst_size(node_list *lst)
{
	int		i;
	node_list	*list;

	i = 0;
	list = lst;
	while (list != NULL)
	{
		list = list->next;
		i++;
	}
	return (i);
}

void	print_stack(node_list *stack)
{
    node_list *tmp;

	if (!stack)
		return ;
    tmp = stack;
	while (tmp != NULL)
	{
		ft_putnbr_fd(tmp->contenu, 1);
        ft_putendl_fd("", 1);
		tmp = tmp->next;
	}
}

int		is_sorted(node_list *stack)
{
	node_list *tmp;
	if (!stack)
		return (0);
	tmp = stack;
	while (tmp && tmp->next)
	{
		if (tmp->contenu > tmp->next->contenu)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}