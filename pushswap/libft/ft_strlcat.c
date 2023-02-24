/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:39:03 by lmedrano          #+#    #+#             */
/*   Updated: 2022/10/30 10:48:42 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	while (src[i] != '\0')
		i++;
	src_len = i;
	i = 0;
	while (dst[i] != '\0')
		i++;
	dst_len = i;
	j = 0;
	if (dstsize == 0)
		return (src_len);
	while ((src[j] != '\0') && (i < (dstsize - 1)))
		dst[i++] = src[j++];
	dst[i] = '\0';
	if (dst_len > dstsize)
		return (src_len + dstsize);
	return (dst_len + src_len);
}
