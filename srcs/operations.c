/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:15:10 by lmedrano          #+#    #+#             */
/*   Updated: 2023/01/27 11:32:40 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// <-------------- SWAP OPERATIONS -------------->

int	swap(node_list **stack)
{
	node_list *current_x;
	node_list *current_y;
	node_list *previous_y;
	node_list *temp;

	if (lst_size(*stack) < 2)
		return (-1);
	current_x = *stack;
	current_y = (*stack)->next;
	if (!current_x && ! current_y)
		ft_error();
	previous_y = *stack;
	*stack = current_y;
	previous_y->next = current_x;
	temp = current_y->next;
	current_y->next = current_x->next;
	current_x->next = temp;
	return (0);
}

int	swap_a(node_list **stack_a)
{
	if (swap(stack_a) == -1)
		return (-1);
	write(1, "sa", 2);
	return (0);
}

int	swap_b(node_list **stack_b)
{
	if (swap(stack_b) == -1) 
		return (-1);
	write(1, "sb", 2);
	return (0);
}

int	swap_both(node_list **stack_a, node_list **stack_b)
{
	if ((lst_size(*stack_a) < 2) || (lst_size(*stack_b) < 2))
		return (-1);
	swap(stack_a);
	swap(stack_b);
	write(1, "ss", 2);
	return (0);

}

// <-------------- PUSH OPERATIONS -------------->

int	push(node_list **stack_to, node_list **stack_from)
{
    node_list *tmp;
	node_list *head_to;
	node_list *head_from;

	if (*stack_from == NULL || (*stack_from)->next == NULL)
		return (-1);
	head_to = *stack_to;
	head_from = *stack_from;
	tmp = head_from;
	head_from = head_from->next;
	*stack_from = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
		*stack_to = head_to;
	}
	else
	{
		tmp->next = head_to;
		*stack_to = tmp;
	}
	return (0);
}

int	push_a(node_list **stack_a, node_list **stack_b)
{
	if (push(stack_a, stack_b) == -1)
		return (-1);
	write(1, "pa", 2);
	return (0);
}

int	push_b(node_list **stack_b, node_list **stack_a)
{
	if (push(stack_b, stack_a) == -1)
		return (-1);
	write(1, "pb", 2);
	return (0);
}

// <-------------- ROTATE OPERATIONS -------------->

int	rotate(node_list **stack)
{
	node_list	*first;
	node_list	*last;
	int			i;

	if (*stack == NULL || (*stack)->next == NULL)
		return (-1) ;
	i = 0;
	first = *stack;
	last = *stack;
	while (last && last->next)
	{
		last = last->next;
		i++;
	}
	*stack = first->next;
	first->next = NULL;
	last->next = first;
	return (0);
}


int	rotate_a(node_list **stack_a)
{
	if (rotate(stack_a) == -1)
		return (-1);
	write(1, "ra", 2);
	return (0);
}

int	rotate_b(node_list **stack_b)
{
	if (rotate(stack_b) == -1)
		return (-1);
	write(1, "rb", 2);
	return (0);
}

int	rotate_both(node_list **stack_a, node_list **stack_b)
{
	if ((lst_size(*stack_a) < 2) || (lst_size(*stack_b) < 2))
		return (-1);
	rotate_a(stack_a);
	rotate_b(stack_b);
	write(1, "rr", 2);
	return (0);
}

// <-------------- REVERSE ROTATE OPERATIONS -------------->

int	rotate_down(node_list **stack)
{
	node_list *temp;
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

int	rotate_down_a(node_list **stack_a)
{
	if (rotate_down(stack_a) == -1)
		return (-1);
	write(1, "rra", 3);
	return (0);

}

int	rotate_down_b(node_list **stack_b)
{
	if (rotate_down(stack_b) == -1)
		return (-1);
	write(1, "rrb", 3);
	return (0);
}

int	rotate_down_both(node_list **stack_a, node_list **stack_b)
{
	if ((lst_size(*stack_a) < 2) || (lst_size(*stack_b) < 2))
		return (-1);
	rotate_down_a(stack_a);	
	rotate_down_b(stack_b);	
	write(1, "rrr", 3);
	return (0);
}