/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 09:14:00 by lmedrano          #+#    #+#             */
/*   Updated: 2023/01/27 17:47:20 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>


int		list_size(node_list **stack)
{
	int 		len;
	node_list	*new_stack;

	len = 0;
	new_stack = *stack;
	while (new_stack != NULL)
	{
		new_stack = new_stack->next;
		len++;
	}
	return (len);
}

int		elem_pos(node_list **stack, int contenu)
{
	int			pos;
	int 		head;

	head = (*stack)->contenu;
	printf("head is %d\n", head);
	printf("contenu is %d\n", contenu);
	pos = 1;
	while (*stack != NULL)
	{
		
		if (((*stack)->contenu == contenu) || (contenu == head))
			break ;
		pos++;
	*stack = (*stack)->next;
	}
	return (pos);
}


int	rotate_to_head(node_list **stack, int pos)
{
	int	rotations;

	index = 0;
	while (*stack != NULL)
	{
		while (pos > 1)
		{
			rotate(stack);
			rotations++;
			pos--;
		}
		*stack = (*stack)->next;
	}
	return (rotations);
}

void	push_swap(node_list **stack_a, node_list **stack_b)
{
	int			min;
	int			max;
	int 		pos;
	int			rotation_nbr;
	
	//1.pushed 1st 2 elem to B
	push_to_b(stack_a, stack_b);
	push_to_b(stack_a, stack_b);
	//2. IF OUTSIDE RANGE
	//get min
	min = smallest(*stack_b);
	printf("min is : %d\n", min);
	//get max
	max = biggest(*stack_b);	
	printf("max is : %d\n", max);
	//in A
	while (*stack_a != NULL)
	{
		if ((*stack_a)->contenu < min || (*stack_a)->contenu > max)
		{
			pos = elem_pos(stack_a);
			printf("pos is: %d\n", pos);
			rotation_nbr = rotate_to_head(stack_a, pos);
		}
		else
		*stack_a = (*stack_a)->next;	
	}
	//in B
	while (*stack_b != NULL)
	{
		if ((*stack_b)->contenu != max)
		{
			pos = list_size(stack_b);
			rotation_nbr = rotate_to_head(stack_b, pos);
		}
		else
			*stack_b = (*stack_b)->next;
	}
	//3.IF IN RANGE
	//in A
	while (*stack_a != NULL)
	{
		if (is in range)
		{
			pos = elem_pos(stack_a);
			printf("pos is: %d\n", pos);
			rotation_nbr = rotate_to_head(stack_a, pos);
		}
		else
			*stack_a = (*stack_a)->next;
	}
	//in B
	while (*stack_b != NULL)
	{
		if (is in range)
		{
			pos = get (a-1);
			rotation_nbr = rotate_to_head(stack_b, pos);
		}
		else
			*stack_b = (*stack_b)->next;
	}
}
