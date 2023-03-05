/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:15:10 by lmedrano          #+#    #+#             */
/*   Updated: 2023/03/05 14:11:44 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_three(t_node **stack_a)
{
	if ((*stack_a)->index == get_min(stack_a, -1) && (*stack_a)->next->index
		> (*stack_a)->next->next->index)
	{
		rotate_a(stack_a);
		swap_a(stack_a);
		rotate_down_a(stack_a);
	}
	else if ((*stack_a)->index
		== get_min(stack_a, get_min(stack_a, -1)))
	{
		if ((*stack_a)->next->index < (*stack_a)->index)
			swap_a(stack_a);
		else
			rotate_down_a(stack_a);
	}
	else
	{
		if ((*stack_a)->next->index == get_min(stack_a, -1))
			rotate_a(stack_a);
		else
		{
			swap_a(stack_a);
			rotate_down_a(stack_a);
		}
	}
}

void	push_swap_four(t_node **stack_a, t_node **stack_b)
{
	int	distance;

	distance = get_distance(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		rotate_a(stack_a);
	else if (distance == 2)
	{
		rotate_a(stack_a);
		rotate_a(stack_a);
	}
	else if (distance == 3)
		rotate_down_a(stack_a);
	if (!is_sorted(stack_a))
	{
		push_b(stack_a, stack_b);
		push_swap_three(stack_a);
		push_a(stack_b, stack_a);
	}
}

void	push_swap_five(t_node **stack_a, t_node **stack_b)
{
	int	distance;

	distance = get_distance(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		rotate_a(stack_a);
	else if (distance == 2)
	{
		rotate_a(stack_a);
		rotate_a(stack_a);
	}
	else if (distance == 3)
	{
		rotate_down_a(stack_a);
		rotate_down_a(stack_a);
	}
	else if (distance == 4)
		rotate_down_a(stack_a);
	if (is_sorted(stack_a))
		return ;
	push_b(stack_a, stack_b);
	push_swap_four(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

void	small_sort(t_node **stack_a, t_node **stack_b)
{
	int	len;

	if (!is_sorted(stack_a) || lst_size(*stack_a) != 0
		|| lst_size(*stack_a) != 1)
	{
		len = lst_size(*stack_a);
		if (len == 2)
			swap_a(stack_a);
		else if (len == 3)
			push_swap_three(stack_a);
		else if (len == 4)
			push_swap_four(stack_a, stack_b);
		else if (len == 5)
			push_swap_five(stack_a, stack_b);
	}
}
