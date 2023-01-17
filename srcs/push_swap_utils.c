/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:15:10 by lmedrano          #+#    #+#             */
/*   Updated: 2023/01/10 17:25:17 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_list	*swap_a(t_list *stack_a)
{
//intervertir 2 1er elem de a
//do nthg if no elem or one elem
	t_list 		*first;
	t_list		*second;
	
	if (stack_a == NULL || stack_a->next == NULL)
		return (NULL);
	first = stack_a; // assign to head
	second = first->next; // 1st value of list is equal to 2
	first->next = first->next->next; // je decale tout d'un cran pour pas ecrire sur le null
	second->next = first; // second value of list is equal to 5
	stack_a = second; // reassign stack_a head to second list 1st value	
	printf("\n");
	print_stack(stack_a);
	return (stack_a);
}

t_list	*swap_b(t_list stack_b)
{
//intervertir les deux premier elem de B
//do nothg if no elemen or one elem
	t_list	*first;
	t_list	*second;

	if (stack_b == NULL || stack_b->next == NULL)
		return (NULL);
	first = stack_b;
	second = first->next;
	first->next = first->next->next;
	second->next = first;
	stack_b = second;
	return (stack_b);
}

t_list	ss(t_list stack_ a, t_list stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
}

t_list	*push_to_a(t_list stack_a, t_list stack_b)
{
//push 1st int from b to a
//do nthg if b is empty
	stack_b->next = *stack_a;
	*stack_a = stack_b;
}

t_list *push_to_b(t_list stack_b, t_list stack_a)
{
//push 1st int from a to b
//do nothg if a is NULL
	stack_a->next = *stack_b;
	*stack_b = stack_a;	
}	

t_list ra(t_list stack_a)
{
//décale d'un cran vers le haut dans stack a
}

int rb(int b)
{
//décale d'un cran vers le haut dans stack b
}

int rr(int a, int b)
{
//ra + rb
}

t_list rra(t_list stack_a)
{
//décale d'un cran vers le bas dans stack a
	t_list *first;

	first = stack_a;
	first->next = first->next->next;
	//todo 1st should become last
}

t_list rrb(t_list stack_b)
{
//décale d'un cran vers le bas dans stack b
	t_list	*first;

	first = stack_b;
	first->next = first->next->next;
	//todo 1st becomes last
}

int rrr(int a, int b)
{
//rra+rrb
}
