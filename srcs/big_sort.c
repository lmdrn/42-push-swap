/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:15:10 by lmedrano          #+#    #+#             */
/*   Updated: 2023/03/04 17:22:25 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_sort(t_node **stack_a, t_node **stack_b)
{
	int		len;
	int		i;
	int		j;

	len = lst_size(*stack_a);
	i = 0;
	while (!(is_sorted(stack_a)))
	{
		j = 0;
		while (j < len)
		{
			if ((((*stack_a)->index >> i) & 1) == 1)
				rotate_a(stack_a);
			else
				push_b(stack_a, stack_b);
			j++;
		}
		while (lst_size(*stack_b) != 0)
			push_a(stack_b, stack_a);
		i++;
	}
}
