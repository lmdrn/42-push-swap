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
	t_node	*prev_tail;
	t_node	*tail;

	if (lst_size(*stack) > 2)
	{
		prev_tail = *stack;
		while (prev_tail->next->next)
			prev_tail = prev_tail->next;
		tail = prev_tail->next;
		prev_tail->next = NULL;
		tail->next = *stack;
		*stack = tail;
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
