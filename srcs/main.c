/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:39:23 by lmedrano          #+#    #+#             */
/*   Updated: 2023/01/10 18:39:25 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>


//warning ! tu pensera bien a utiliser TON ft_printf avant de push !!
int	ft_mot_count(char const *s, char c)
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

void	print_stack(t_list *s)
{
	if (!s)
		return ;
	printf("this value is : %d\n", s->content);
	print_stack(s->next);
}

int main(int argc, char **argv )
{
    int i;
	int j;
	int len;
	char **res;
	int numero;
	t_list *stack_a = NULL;
	t_list *new = NULL;

	i = 0;
	len = ft_mot_count(argv[1], ' ');
	if (argc == 2)
	{
		while (i < len)
		{
			res = ft_split(argv[1], ' ');
			i++;
		}
		j = 0;
		while (res[j])
		{
			numero = ft_atoi(res[j]);
			new = ft_lstnew(numero);
			ft_lstadd_back(&stack_a, new);
			j++;
		}
		print_stack(stack_a);
		swap_a(stack_a);
	}
	return (0);
}
