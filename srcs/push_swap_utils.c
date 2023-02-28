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

void    ft_error()
{
    write(1, "Error\n", 6);
    exit(0);
}

void    ft_free_str(char *str)
{
    int i;
    i = 0;
    while(str[i])
        i++;
    while(i >= 0)
    {
        free(&str[i]);
        i--;
    }
}

void    ft_free_stack(node_list **stack)
{
    node_list *current;
    node_list *tmp;

    current = *stack;
    while (current)
    {
        tmp = current;
        current = current->next;
        free(tmp);
    }
    free(stack);
}