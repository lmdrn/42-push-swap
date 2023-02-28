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

int     get_min(node_list **stack_a, int index)
{
    node_list *head;
    int         min;

    head = *stack_a;
    min = head->index;
    while (head->next)
    {
        head = head->next;
        if ( (head->index < min) && (head->index != index) )
            min = head->index;
    }
    return (min);

}

int     get_distance(node_list **stack, int min)
{   
    node_list *head;
    int       distance;

    head = *stack;
    distance = 0;
    while ( head && head->next )
    {
        if (head->index == min)
            break;
        distance++;
        head = head->next;
    }
    return (distance);
}

void	push_swap_three(node_list **stack_a)
{
	node_list *head;
    int       min;
    int       next_min;

    head = *stack_a;
    min = get_min(stack_a, -1);
    next_min = get_min(stack_a, min);
    //check if sorted (1,2,3)
    if ( is_sorted(*stack_a) )
        return ;
    //check if min is first and next min is last (1,3,2)
    if ( (head->index == min) && (head->next->index != next_min))
    {
        rotate_down_a(stack_a);
        swap(stack_a);
        rotate_a(stack_a);
    }
    //check if min is second and next_min is first (2,1,3)
    else if( head->next->index == next_min )
    {
        if (head->next->index == min)
            swap_a(stack_a);
        else
            rotate_down_a(stack_a);
    }
    ///check if neither min nor next_min is first (3,2,1 or 3,1,2)
    else
    {
        if (head->next->index)
            rotate_a(stack_a);
        else
            swap_a(stack_a);
            rotate_down_a(stack_a);
    }   
}

void	push_swap_four(node_list **stack_a, node_list **stack_b)
{
	//get distance between 2 numbers (should have 3 case: distance = 1,2 ou 3)
    int         distance;

    distance = get_distance(stack_a, get_min(stack_a, -1));
    if ( is_sorted(*stack_a) )
        return ;
    // if distance from min to head is one 
    if ( distance == 1 )
        rotate_a(stack_a);
    // if distance from min to head is two
    else if (distance == 2)
    {   rotate_a(stack_a);
        rotate_a(stack_a);
    }
    // if distance from min to head is three
    else if (distance == 3)
        rotate_down_a(stack_a);
    if ( is_sorted(*stack_a) )
        return ;
    push_b(stack_a, stack_b);
    push_swap_three(stack_a);
    push_a(stack_a, stack_b);
}

void	push_swap_five(node_list **stack_a, node_list **stack_b)
{
	//get distance between 2 numbers (should have 4 cases: distance = 1,2,3 ou 4)
    int     distance;
    
    distance = get_distance(stack_a, get_min(stack_a, -1));
    if ( is_sorted(*stack_a) )
        return ;
    if ( distance == 1 )
        rotate_a(stack_a);
    else if ( distance == 2 )
    {
        rotate_a(stack_a);
        rotate_a(stack_a);
    }
    else if ( distance == 3)
    {
        rotate_down_a(stack_a);
        rotate_down_a(stack_a);
    }
    else if ( distance == 4 )
        rotate_down_a(stack_a);
    if ( is_sorted(*stack_a) )
        return ;
    push_b(stack_a, stack_b);
    push_swap_four(stack_a, stack_b);
    push_a(stack_a, stack_b);
}
                                                                                                                                                                                                                                                                   


void    small_sort(node_list **stack_a, node_list **stack_b)
{
    int len;
    if (is_sorted(*stack_a) || lst_size(*stack_a) == 0 || lst_size(*stack_a) == 1)
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