/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 07:12:05 by lmedrano          #+#    #+#             */
/*   Updated: 2022/10/29 21:50:25 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbrcount(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		neg;
	int		len;
	char	*res;

	neg = 1;
	len = ft_nbrcount(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	res = malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	res[len] = '\0';
	if (n < 0)
		neg *= -1;
	while (len > 0)
	{
		res[len - 1] = (neg * (n % 10)) + '0';
		n /= 10;
		len--;
	}
	if (neg == -1)
		res[0] = '-';
	return (res);
}
