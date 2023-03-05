/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manipulations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:15:10 by lmedrano          #+#    #+#             */
/*   Updated: 2023/03/05 11:18:28 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*lst_last(t_node *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

t_node	*lst_new(int contenu)
{
	t_node	*list;

	list = malloc(sizeof(t_node));
	if (!list)
		return (NULL);
	list->contenu = contenu;
	list->index = -1;
	list->next = NULL;
	return (list);
}

void	lst_addfront(t_node **lst, t_node *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	lst_addback(t_node **lst, t_node *new)
{
	t_node	*list;

	if (!new)
		return ;
	if (*lst)
	{
		list = lst_last(*lst);
		list->next = new;
	}
	else
		*lst = new;
}

int	lst_size(t_node *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
