/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:33:07 by lmedrano          #+#    #+#             */
/*   Updated: 2022/10/25 12:12:23 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	letter;
	int		i;

	letter = c;
	i = 0;
	while ((s[i] != '\0'))
		i++;
	while ((i > 0) && (s[i] != letter))
		i--;
	if (s[i] == letter)
		return (&((char *)s)[i]);
	return (0);
}
