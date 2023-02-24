/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:15:10 by lmedrano          #+#    #+#             */
/*   Updated: 2023/01/27 11:32:40 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	swap(node_list **stack)
{
	node_list *current_x;
	node_list *current_y;
	node_list *previous_y;
	node_list *temp;

	current_x = *stack;
	current_y = (*stack)->next;
	previous_y = *stack;
	*stack = current_y;
	previous_y->next = current_x;
	temp = current_y->next;
	current_y->next = current_x->next;
	current_x->next = temp;
	printf("\nswapped list: \n");
	print_stack(*stack);
}

/*void	swap_both(node_list **stack_a, node_list **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
}*/

void	push_to_a(node_list **stack_a, node_list **stack_b)
{
    node_list *new_element;
	
    if (!*stack_b)
        return ;
    new_element = *stack_a; 
    *stack_a = *stack_b;
    *stack_b = (*stack_b)->next;
    (*stack_a)->next = new_element;
    printf("\npushed list A: \n");
    print_stack(*stack_a);
    printf("\npushed list B: \n");
    print_stack(*stack_b);
}

void	push_to_b(node_list **stack_a, node_list **stack_b)
{
	node_list *new_element;

	if (!*stack_a)
		return ;
	new_element = *stack_b;
	*stack_b = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_b)->next = new_element;
	printf("\npush > list A: \n");
	print_stack(*stack_a);
	printf("\npush > list B: \n");
	print_stack(*stack_b);
}

void	rotate(node_list **stack)
{
	node_list	*first;
	node_list	*last;
	int			i;


	if (*stack == NULL || (*stack)->next == NULL)
		return ;
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
	printf("\nrotate up list:\n");
	print_stack(*stack);
}

/*void	rotate_a_b(node_list **stack_a, node_list  **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
}*/

void	rotate_down(node_list **stack)
{
	node_list *temp;
	int		i;
	int		j;
	
	if (!*stack || !(*stack)->next)
		return ;
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
	printf("\nrotate down list:\n");
	print_stack(*stack);
}

/*void rotate_down_both(node_list **stack_a, node_list **stack_b)
{
	rotate_down_a(stack_a);
	rotate_down_b(stack_b);
}*/
