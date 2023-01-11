/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:22:32 by lmedrano          #+#    #+#             */
/*   Updated: 2022/10/25 11:05:06 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == '\t')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		is_neg;
	long	result;

	i = 0;
	is_neg = 1;
	result = 0;
	while (str[i] != '\0')
	{
		while (ft_isspace(str[i]) == 1)
			i++;
		while ((str[i] == '+') || (str[i] == '-'))
		{	
			if ((str[i + 1] == '+') || (str[i + 1] == '-'))
				return (0);
			if (str[i] == '-')
				is_neg *= -1;
			i++;
		}
		while (str[i] >= '0' && str[i] <= '9')
			result = (str[i++] - '0') + (result * 10);
		return (result * is_neg);
	}
	return (0);
}
