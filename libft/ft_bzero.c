/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:23:32 by lmedrano          #+#    #+#             */
/*   Updated: 2022/10/18 14:27:18 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t nbr)
{
	int		i;
	char	*new_str;

	i = 0;
	new_str = str;
	while (nbr)
	{
		new_str[i] = 0;
		i++;
		nbr--;
	}
}
