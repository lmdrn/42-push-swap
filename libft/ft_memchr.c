/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:00:21 by lmedrano          #+#    #+#             */
/*   Updated: 2022/10/18 14:34:49 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t nbytes)
{
	size_t		i;
	const char	*str;
	char		new_c;

	i = 0;
	str = s;
	new_c = c;
	while (nbytes > 0)
	{
		if (str[i] == new_c)
		{
			return (&((char *)str)[i]);
		}
		i++;
		nbytes--;
	}
	return (NULL);
}
