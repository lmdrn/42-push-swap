/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:15:10 by lmedrano          #+#    #+#             */
/*   Updated: 2023/01/27 11:32:40 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
    if (is_sorted(stack_a))
        return ;
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
}

void    small_sort(node_list **stack_a, node_list **stack_b)
{
    int len;
    if (is_sorted(stack_a) || lst_size(*stack_a) == 0 || lst_size(*stack_a) == 1)
        return ;
    len = lst_size(*stack_a);
    if (len == 2)
        swap_a(stack_a);
    else if (len == 3)
        push_swap_three(stack_a);
    else if (len == 4)
        push_swap_four(stack_a, stack_b);
    else if (len == 5)
        push_swap_five(stack_a, stack_b);
}