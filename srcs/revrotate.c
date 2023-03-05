/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:50:47 by lmedrano          #+#    #+#             */
/*   Updated: 2023/03/04 16:50:49 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_down(t_node **stack)
{
	t_node	*prev_last;
	t_node	*last;

	if (lst_size(*stack) > 2)
	{
		prev_last = *stack;
		while (prev_last->next->next)
			prev_last = prev_last->next;
		last = prev_last->next;
		prev_last->next = NULL;
		last->next = *stack;
		*stack = last;
	}
}

void	rotate_down_a(t_node **stack_a)
{
	rotate_down(stack_a);
	ft_putendl_fd("rra", 1);
}

void	rotate_down_b(t_node **stack_b)
{
	rotate_down(stack_b);
	ft_putendl_fd("rrb", 1);
}

void	rotate_down_both(t_node **stack_a, t_node **stack_b)
{
	rotate_down(stack_a);
	rotate_down(stack_b);
	ft_putendl_fd("rrr", 1);
}
