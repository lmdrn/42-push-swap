/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:15:10 by lmedrano          #+#    #+#             */
/*   Updated: 2023/01/27 11:32:40 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//make function that longest bits
int longest_bits(node_list **stack_a)
{
    node_list *head;
    int        max;
    int        longest_bits;

    head = *stack_a;
    max = head->index;
    longest_bits = 0;

    while (head && head->next)
    {
        if ( head->index > max )
            max = head->index;
        head = head->next;
    }
    while ( max >> longest_bits != 0 )
        longest_bits++;
    return (longest_bits);

}

void    big_sort(node_list **stack_a, node_list **stack_b)
{
    //radix sort is here
    int       len;
    int       longest;
    node_list *head;
    int       i;
    int       j;

    head = *stack_a;
    len = lst_size(head);
    longest = longest_bits(stack_a);
    i = 0;
    while (i < longest)
    {
        j = 0;
        while ( j < len )
        {
            head = *stack_a;
            if ( ((head->index >> i) & 1) == 1 )
                rotate_a(stack_a);
            else
                push_b(stack_a, stack_b);
            j++;
        }
        while ( lst_size(*stack_b) != 0 )
            push_a(stack_a, stack_b);
        i++;
    }

}