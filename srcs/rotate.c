/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:50:58 by lmedrano          #+#    #+#             */
/*   Updated: 2023/03/05 11:17:37 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (lst_size(*stack) > 2)
	{
		last = lst_last(*stack);
		first = *stack;
		*stack = (*stack)->next;
		last->next = first;
		first->next = NULL;
	}
}

void	rotate_a(t_node **stack_a)
{
	rotate(stack_a);
	ft_putendl_fd("ra", 1);
}

void	rotate_b(t_node **stack_b)
{
	rotate(stack_b);
	ft_putendl_fd("rb", 1);
}

void	rotate_both(t_node **stack_a, t_node **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putendl_fd("rr", 1);
}
