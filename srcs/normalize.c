/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:15:10 by lmedrano          #+#    #+#             */
/*   Updated: 2023/01/27 11:32:40 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//function to get next min
node_list *get_next_min(node_list **stack)
{
    node_list *head;
    node_list *next_min;
    int        has_min;

    head = *stack;
    next_min = NULL;
    has_min = 0;
    if (!head)
        return (*stack);
    while (head && head->next)
    {
        if ( (head->index == -1) && (!has_min || head->contenu < next_min->contenu) )
        {
            next_min = head;
            has_min = 1;
        }
        head = head->next;
    }
    return (next_min);

}
//function to transform digit into index 
void ft_normalize(node_list **stack)
{
    node_list *head;
    int       index;

    index = 0;
    head = *stack;
    while (head)
    {
        head->index = index++;
        head = get_next_min(stack);
    }
}


