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

int	swap(t_node **stack)
{
	t_node	*current_x;
	t_node	*current_y;
	t_node	*previous_y;
	t_node	*tmp;

	if (lst_size(*stack) < 2)
		return (-1);
	current_x = *stack;
	current_y = (*stack)->next;
	previous_y = *stack;
	*stack = current_y;
	previous_y->next = current_x;
	tmp = current_y->next;
	current_y->next = current_x->next;
	current_x->next = tmp;
	return (0);
}

int	swap_a(t_node **stack_a)
{
	if (swap(stack_a) == -1)
		return (-1);
	ft_putendl_fd("sa", 1);
	return (0);
}

int	swap_b(t_node **stack_b)
{
	if (swap(stack_b) == -1)
		return (-1);
	ft_putendl_fd("sb", 1);
	return (0);
}

int	swap_both(t_node **stack_a, t_node **stack_b)
{
	if ((lst_size(*stack_a) < 2) || (lst_size(*stack_b) < 2))
		return (-1);
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss", 1);
	return (0);
}
