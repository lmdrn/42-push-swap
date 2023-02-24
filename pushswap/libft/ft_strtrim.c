/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:47:38 by lmedrano          #+#    #+#             */
/*   Updated: 2022/10/29 21:49:42 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_starttrim(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	start = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (set[j] == s1[i])
			{
				start++;
				break ;
			}
			j++;
		}
		if (set[j] == '\0')
			break ;
		i++;
	}
	return (start);
}

int	ft_endtrim(char const *s1, char const *set, int start)
{
	int	i;
	int	j;
	int	end;

	i = 0;
	end = ft_strlen(s1);
	j = end - 1;
	while (j > start)
	{
		i = 0;
		while (set[i] != '\0')
		{
			if (set[i] == s1[j])
			{
				end--;
				break ;
			}
			i++;
		}
		if (set[i] == '\0')
			break ;
		j--;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	start = ft_starttrim(s1, set);
	end = ft_endtrim(s1, set, start);
	str = ft_substr(s1, start, (end - start));
	return (str);
}
