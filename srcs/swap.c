/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:50:21 by lmedrano          #+#    #+#             */
/*   Updated: 2023/03/04 16:55:03 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **stack)
{
	t_node	*tmp;

	if (lst_size(*stack) > 2)
	{
		tmp = (*stack)->next;
		(*stack)->next = tmp->next;
		tmp->next = *stack;
		*stack = tmp;
	}
}

void	swap_a(t_node **stack_a)
{
	swap(stack_a);
	ft_putendl_fd("sa", 1);
}

void	swap_b(t_node **stack_b)
{
	swap(stack_b);
	ft_putendl_fd("sb", 1);
}

void	swap_both(t_node **stack_a, t_node **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss", 1);
}
