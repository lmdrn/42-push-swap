/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:38:20 by lmedrano          #+#    #+#             */
/*   Updated: 2022/10/25 18:08:50 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*str;
	int			i;
	int			j;
	int			count;

	i = 0;
	j = 0;
	count = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(count + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = ((char *)s1)[i];
		i++;
	}
	while (s2[j] != '\0')
		str[i++] = ((char *)s2)[j++];
	str[i] = '\0';
	return (str);
}
