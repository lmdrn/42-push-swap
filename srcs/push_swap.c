/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 09:14:00 by lmedrano          #+#    #+#             */
/*   Updated: 2023/01/24 17:52:47 by lmedrano         ###   ########.fr       */
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

void	push_swap(node_list **stack_a, node_list **stack_b)
{
	int			min;
	int			max;
	int 		len;
	node_list	*new_stack_a;

	//1.pushed 1st 2 elem to B
	printf("YOU ARE OUTSIDE THE LOOP \n");
	push_to_b(stack_a, stack_b);
	push_to_b(stack_a, stack_b);
	//2. find cheapest nbr
	min = smallest(*stack_b);
	printf("min is : %d\n", min);
	max = biggest(*stack_b);	
	printf("max is : %d\n", max);
	new_stack_a = *stack_a;
	while (new_stack_a != NULL)
	{
		printf("contenu stack %d\n", new_stack_a->contenu);
		if (new_stack_a->contenu < min || new_stack_a->contenu > max)
		{
			len = list_size(stack_b);
			printf("len is: %d\n", len);
			while (len > 1)
			{
				if ((*stack_b)->contenu != max)
					rotate_a(stack_b);
				len--;
			}
			printf("YOU ARE HERE \n");
			print_stack(new_stack_a);
			print_stack(*stack_b);
			push_to_b(stack_a, stack_b);
			//ce push la, il fait tout merder sur A
			if ((*stack_b)->contenu > max)
				max = (*stack_b)->contenu;
			if ((*stack_b)->contenu < min)
				min = (*stack_b)->contenu;
			printf("new min is : %d\n", min);
			printf("new max is : %d\n", max);
		}
		// saute un int ici :(
		// should define new head for stack_a
		new_stack_a = new_stack_a->next;
	}
}
