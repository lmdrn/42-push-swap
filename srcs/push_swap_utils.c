/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:15:10 by lmedrano          #+#    #+#             */
/*   Updated: 2023/01/22 11:26:36 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

node_list	**swap_a(node_list **stack_a)
{
	node_list *current_x;
	node_list *current_y;
	node_list *previous_y;
	node_list *temp;

	current_x = *stack_a;
	current_y = (*stack_a)->next;
	previous_y = *stack_a;
	*stack_a = current_y;
	previous_y->next = current_x;
	temp = current_y->next;
	current_y->next = current_x->next;
	current_x->next = temp;
	printf("\nswapped list: \n");
	print_stack(*stack_a);
	return &(*stack_a);
}

node_list	**swap_b(node_list **stack_b)
{
	node_list *current_x;
	node_list *current_y;
	node_list *previous_y;
	node_list *temp;

	current_x = *stack_b;
	current_y = (*stack_b)->next;
	previous_y = *stack_b;
	*stack_b = current_y;
	previous_y->next = current_x;
	temp = current_y->next;
	current_y->next = current_x->next;
	current_x->next = temp;
	printf("\nswapped list B: \n");
	print_stack(*stack_b);
	return &(*stack_b);
}

void	swap_both(node_list **stack_a, node_list **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
}

node_list	**push_to_a(node_list **stack_a, node_list **stack_b)
{
	node_list *new_element;
	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return (NULL);
	if (*stack_a == NULL)
	{
		*stack_a = *stack_b;
		*stack_b = (*stack_b)->next;
		(*stack_a)->next = NULL;
	} else
	{
		new_element = *stack_b;
		*stack_b = (*stack_b)->next;
		new_element->next = *stack_a;
		*stack_a = new_element;
	}
	printf("\npushed list A:\n");
	print_stack(*stack_a);
	printf("\npushed list B:\n");
	print_stack(*stack_b);
	return &(*stack_a);

}

node_list **push_to_b(node_list **stack_a, node_list **stack_b)
{
    node_list *new_element;

    if (*stack_a == NULL || (*stack_a)->next == NULL)
        return (NULL);
    if (*stack_b == NULL) 
	{
        *stack_b = *stack_a;
        *stack_a = (*stack_a)->next;
        (*stack_b)->next = NULL;
	} else
	{
    	new_element = *stack_a; 
    	*stack_a = (*stack_a)->next;
    	new_element->next = *stack_b; 
    	*stack_b = new_element;
	}
	printf("\npushed list A: \n");
	print_stack(*stack_a);
	printf("\npushed list B: \n");
	print_stack(*stack_b);
    return &(*stack_b);
}


node_list **rotate_a(node_list **stack_a)
{
	node_list	*first;
	node_list	*last;
	int			i;


	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return (NULL);
	i = 0;
	first = *stack_a;
	last = *stack_a;
	while (last && last->next)
	{
		last = last->next;
		i++;
	}
	*stack_a = first->next;
	first->next = NULL;
	last->next = first;
	printf("\nrotate up list:\n");
	print_stack(*stack_a);
	return &(*stack_a);
}

node_list **rotate_b(node_list **stack_b)
{
	node_list 	*first;
	node_list	*last;
	int			i;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return (NULL);
	i = 0;
	first = *stack_b;
	last = *stack_b;
	while (last && last->next)
	{
		last = last->next;
		i++;
	}
	*stack_b = first->next;
	first->next = NULL;
	last->next = first;
	return &(*stack_b);
}

void	rotate_a_b(node_list **stack_a, node_list  **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
}

node_list **rotate_down_a(node_list **stack_a)
{
	node_list *temp;
	int		i;
	int		j;
	
	temp = *stack_a;
	i = 0;
	while (temp && temp->next)
	{
		temp = temp->next;
		i++;
	}
	temp->next = *stack_a;
	j = i - 1; 
	temp = *stack_a;
	while (j)
	{
		temp = temp->next;
		j--;
	}	
	*stack_a = temp->next;
	temp->next = NULL;
	printf("\nrotate down list:\n");
	print_stack(*stack_a);
	return &(*stack_a); 
}

node_list **rotate_down_b(node_list **stack_b)
{
	node_list	*temp;
	int			i;
	int			j;

	temp = *stack_b;
	i = 0;
	while (temp->next)
	{
		temp = temp->next;
		i++;
	}
	temp->next = *stack_b;
	j = i - 1;
	temp = *stack_b;
	while (j)
	{
		temp = temp->next;
		j--;
	}
	*stack_b = temp->next;
	temp->next = NULL;
	return &(*stack_b);
}

void rotate_down_both(node_list **stack_a, node_list **stack_b)
{
	rotate_down_a(stack_a);
	rotate_down_b(stack_b);
}
