/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:15:10 by lmedrano          #+#    #+#             */
/*   Updated: 2023/03/05 11:19:07 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_node **stack, int index)
{
	t_node	*head;
	int		min;

	head = *stack;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if (head->index < min && head->index != index)
			min = head->index;
	}
	return (min);
}

int	get_distance(t_node **stack, int min)
{
	t_node	*head;
	int		distance;

	head = *stack;
	distance = 0;
	while (head)
	{
		if (head->index == min)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}

t_node	*get_next_min(t_node **stack)
{
	t_node	*head;
	t_node	*next_min;
	int		has_min;

	head = *stack;
	next_min = NULL;
	has_min = 0;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1)
				&& (!has_min || head->contenu < next_min->contenu))
			{
				next_min = head;
				has_min = 1;
			}
			head = head->next;
		}
	}
	return (next_min);
}

void	ft_normalize(t_node **stack)
{
	t_node	*head;
	int		index;

	index = 0;
	head = get_next_min(stack);
	while (head)
	{
		head->index = index++;
		head = get_next_min(stack);
	}
}
