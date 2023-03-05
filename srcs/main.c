/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:39:23 by lmedrano          #+#    #+#             */
/*   Updated: 2023/03/05 14:12:57 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init(t_node **stack, int ac, char **av)
{
	t_node	*new_stack;
	int		i;

	i = 0;
	if (ac == 2)
		av = ft_split(av[1], ' ');
	else
		i = 1;
	while (av[i])
	{
		new_stack = lst_new(ft_atoi(av[i]));
		lst_addback(stack, new_stack);
		i++;
	}
	ft_normalize(stack);
	if (ac == 2)
		ft_free_str(av);
}

void	ft_sort(t_node **stack_a, t_node **stack_b)
{
	if (lst_size(*stack_a) <= 5)
		small_sort(stack_a, stack_b);
	else
		big_sort(stack_a, stack_b);
}

int	is_sorted(t_node **stack)
{
	t_node	*tmp;

	tmp = *stack;
	while (tmp && tmp->next)
	{
		if (tmp->contenu > tmp->next->contenu)
		{
			return (0);
		}	
		tmp = tmp->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_node	**stack_a;
	t_node	**stack_b;

	if (*av && ac < 2)
		return (0);
	ft_check_args(ac, av);
	stack_a = malloc(sizeof(t_node *));
	stack_b = malloc(sizeof(t_node *));
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
}
