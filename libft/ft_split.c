/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 21:33:17 by lmedrano          #+#    #+#             */
/*   Updated: 2022/11/08 09:28:40 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_word_count(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			word++;
			while (s[i] != c && s[i] != '\0')
					i++;
		}
		else
			i++;
	}
	return (word);
}

char	**ft_free(char **tab, int j)
{
	while (j-- > 0)
		free(tab[j]);
	free(tab);
	return (NULL);
}

char	**ft_second_floor(char const *s, char c, char **tab, int i)
{
	int	j;
	int	k;
	int	count;

	j = -1;
	while (++j < (ft_word_count(s, c)))
	{
		count = 0;
		while (s[i] == c)
			i++;
		i = i - 1;
		while (s[++i] != c && s[i] != '\0')
			count++;
		tab[j] = malloc(sizeof(char) * (count + 1));
		if (tab[j] == NULL)
			return (ft_free(tab, j));
		i -= count;
		k = 0;
		while (s[i] != c && s[i] != '\0')
			tab[j][k++] = s[i++];
	tab[j][k] = '\0';
	}
	tab[j] = 0;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**tab;

	i = 0;
	tab = malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (tab == NULL)
		return (NULL);
	tab[ft_word_count(s, c)] = 0;
	return (ft_second_floor(s, c, tab, i));
}
