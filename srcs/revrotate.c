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

int	rotate_down(t_node **stack)
{
	t_node	*temp;
	int		i;
	int		j;

	if (!*stack || !(*stack)->next)
		return (-1);
	temp = *stack;
	i = 0;
	while ((*stack)->next)
	{
		*stack = (*stack)->next;
		i++;
	}
	(*stack)->next = temp;
	j = i - 1;
	temp = *stack;
	while (j)
	{
		temp = temp->next;
		j--;
	}	
	temp->next = NULL;
	return (0);
}

int	rotate_down_a(t_node **stack_a)
{
	if (rotate_down(stack_a) == -1)
		return (-1);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	rotate_down_b(t_node **stack_b)
{
	if (rotate_down(stack_b) == -1)
		return (-1);
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	rotate_down_both(t_node **stack_a, t_node **stack_b)
{
	if ((lst_size(*stack_a) < 2) || (lst_size(*stack_b) < 2))
		return (-1);
	rotate_down_a(stack_a);
	rotate_down_b(stack_b);
	ft_putendl_fd("rrr", 1);
	return (0);
}
