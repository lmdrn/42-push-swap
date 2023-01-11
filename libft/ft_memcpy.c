/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:43:11 by lmedrano          #+#    #+#             */
/*   Updated: 2022/10/25 15:43:04 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t nbytes)
{
	size_t			i;
	unsigned char	*n_dst;
	const char		*n_src;

	i = 0;
	n_dst = dst;
	n_src = src;
	if (!dst && !src)
		return (0);
	while (nbytes > 0)
	{
		n_dst[i] = n_src[i];
		nbytes --;
		i++;
	}
	return (dst);
}
