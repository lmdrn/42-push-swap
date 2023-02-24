/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:52:00 by lmedrano          #+#    #+#             */
/*   Updated: 2022/10/29 22:11:35 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*n_dst;
	const char		*n_src;

	i = 0;
	n_dst = dst;
	n_src = src;
	if (dst > src && *n_src != '\0')
	{
		while (n > 0)
		{	
			n_dst[n - 1] = n_src[n - 1];
			n--;
		}
	}
	else if (src > dst)
	{
		while (i < n)
		{
			n_dst[i] = n_src[i];
			i++;
		}	
	}
	return (dst);
}
