/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:50:30 by lmedrano          #+#    #+#             */
/*   Updated: 2023/03/05 14:16:05 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **stack_from, t_node **stack_to)
{
	t_node	*tmp;

	if (lst_size(*stack_from) != 0)
	{
		tmp = *stack_from;
		*stack_from = (*stack_from)->next;
		lst_addfront(stack_to, tmp);
	}
}

void	push_a(t_node **stack_b, t_node **stack_a)
{
	push(stack_b, stack_a);
	ft_putendl_fd("pa", 1);
}

void	push_b(t_node **stack_a, t_node **stack_b)
{
	push(stack_a, stack_b);
	ft_putendl_fd("pb", 1);
}
