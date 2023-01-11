/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:18:46 by lmedrano          #+#    #+#             */
/*   Updated: 2022/10/21 16:06:49 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (n[i] == '\0')
		return ((char *)h);
	while (h[i] != '\0' && (len > 0))
	{
		j = 0;
		while ((h[i + j] != '\0') && (n[j] == h[i + j]))
		{
			if (n[j + 1] == '\0')
			{
				if (ft_strlen(n) > len)
					return (NULL);
				return (&((char *)h)[i]);
			}
			j++;
		}
		i++;
		len--;
	}
	return (NULL);
}
