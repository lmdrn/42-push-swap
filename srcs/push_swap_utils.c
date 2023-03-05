/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:15:10 by lmedrano          #+#    #+#             */
/*   Updated: 2023/03/05 13:25:32 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long int	ft_atoi2(const char *str)
{
	int				i;
	int				is_neg;
	long long int	result;

	i = 0;
	is_neg = 1;
	result = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{	
		if (str[i] == '-')
		{
			is_neg = -1;
			i++;
		}	
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = (str[i++] - '0') + (result * 10);
	result *= is_neg;
	return (result);
}

void	ft_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(0);
}

void	ft_free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_free_stack(t_node **stack)
{
	t_node	*current;
	t_node	*tmp;

	current = *stack;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	free(stack);
}
