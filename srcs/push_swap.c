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
#include <limits.h>

int 	biggest(node_list *stack_a)
{
	int max;

	max = INT_MIN;
	while (stack_a != NULL)
	{
		if (max < stack_a->contenu)
			max = stack_a->contenu;
		stack_a = stack_a->next;
	}
	return (max);
}


int	smallest(node_list *stack_a)
{
	int		min;

	min = INT_MAX;
	while (stack_a != NULL)
	{
			if (min > stack_a->contenu)
				min = stack_a->contenu;
			stack_a = stack_a->next;
	}
	return (min);
}

void	push_swap_three(node_list **stack_a)
{
	int i;
	int min;
	int max;
	int first;
	int last;
	node_list	*new_stack;

	i = 0;
	new_stack = *stack_a;
	min = smallest(new_stack);
	max = biggest(new_stack);
	first = (*stack_a)->contenu;
	while (new_stack->next != NULL)
	{
		if (min > new_stack->contenu)
			min = new_stack->contenu;
		if ( max < new_stack->contenu)
			max = new_stack->contenu;
		new_stack = new_stack->next;
		i++;
	}
	last = new_stack->contenu;
	printf("\nmin is: %d\n", min);
	printf("max is: %d\n", max);
	printf("length is: %d\n", i);
	printf("first is: %d\n", first);
	printf("last is: %d\n", last);
	//if lists is only 3 numbers
	if (min != first && max != last)
	{
			// if max 1st
			if (max == first)
			{
					rotate(stack_a);
					// && min last
					if (min == last)
						swap(stack_a);
			}
			// if min 1st
			else if (min == first)
			{
				swap(stack_a);
				rotate(stack_a);
			}
			// if max last
			else if (max == last)
			{
				swap(stack_a);
			}
			// if min last
			else if (min == last)
			{
				rotate_down(stack_a);
			}
	}
			printf("\nOrdered A List:\n");
			print_stack(*stack_a);
}

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
