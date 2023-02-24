/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:39:23 by lmedrano          #+#    #+#             */
/*   Updated: 2023/02/24 11:11:07 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init(node_list **stack, int ac, char **av)
{
	node_list	*new_stack;
	char	 	**res;
	int			i;

	i = 0;
	if (ac == 2)
		res = ft_split(av[1], ' ');
	else
		i = 1;
		res = av;
	while(res[i])
	{
		new_stack = lst_addnew(ft_atoi(res[i]));
		lst_addback(&stack, new_stack);
		i++;
	}
	ft_normalize(stack);
	if (ac == 2)
		ft_free(res);
}

int main(int ac, char **av )
{
	node_list **stack_a;
	node_list **stack_b;

	if (ac < 2)
		return (-1);
	ft_check_args(ac, av);
	stack_a = malloc(sizeof(node_list));
	stack_b = malloc(sizeof(node_list));
	*stack_a = NULL;
	*stack_b = NULL;
	ft_init(stack_a, ac, av);
	if (is_sorted(stack_a))
	{
		ft_free_stack(stack_a);
		ft_free_stack(stack_b);
		return (0);
	}
	ft_sort(stack_a, stack_b);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
	

	return (0);
}
