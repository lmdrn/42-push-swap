/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 09:14:00 by lmedrano          #+#    #+#             */
/*   Updated: 2023/01/24 14:19:24 by lmedrano         ###   ########.fr       */
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
					rotate_a(stack_a);
					// && min last
					if (min == last)
						swap_a(stack_a);
			}
			// if min 1st
			else if (min == first)
			{
				swap_a(stack_a);
				rotate_a(stack_a);
			}
			// if max last
			else if (max == last)
			{
				swap_a(stack_a);
			}
			// if min last
			else if (min == last)
			{
				rotate_down_a(stack_a);
			}
	}
			printf("\nOrdered A List:\n");
			print_stack(*stack_a);
}

void	push_swap(node_list **stack_a, node_list **stack_b)
{

}
