/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:15:10 by lmedrano          #+#    #+#             */
/*   Updated: 2023/03/05 13:56:17 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_num(char *num)
{
	int	i;

	i = 0;
	if (num[i] == '-' && ft_isdigit(num[i + 1]))
		i++;
	if (num[i] == '+' && ft_isdigit(num[i + 1]))
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

int	num_is_repeated(int num, char **av, int i)
{
	i++;
	while (av[i])
	{
		if (ft_atoi2(av[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

void	ft_check_args(int ac, char **av)
{
	int		i;
	long	tmp;

	i = 0;
	if (ac == 2)
		av = ft_split(av[1], ' ');
	else
		i = 1;
	while (av[i])
	{
		tmp = ft_atoi2(av[i]);
		if (!is_num(av[i]) || num_is_repeated(tmp, av, i)
			|| tmp < -2147483648 || tmp > 2147483647)
		{
			ft_error("Error");
		}
		i++;
	}
	if (ac == 2)
		ft_free_str(av);
}
