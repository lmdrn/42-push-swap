/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:15:10 by lmedrano          #+#    #+#             */
/*   Updated: 2023/01/27 11:32:40 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_num(char *num)
{
    int i;
    i = 0;
    if (num[0] == '-')
        i++;
    while (num[i])
    {
        if (!ft_isdigit(num[i]))
            return (0);
        i++;
    }
    return (1);
}

int is_alien(int num, char **av, int i)
{
    i++;
    while (av[i])
    {
        if (ft_atoi(av[i]) == num)
            return (1);
        i++;
        return (0);
    }
}

void    ft_check_args(int ac, char **av)
{
    int     i;
    long    tmp;
    char    **res;

    i = 0;
    if (ac == 2)
        res = ft_split(av[1], ' ');
    else
    {
        i = 1,
        res = av;
    }
    while (res[i])
    {
        tmp = ft_atoi(av[i]);
        if (!is_num(av[i]))
            ft_error("Error\n");
        if (is_alien(tmp, res, i))
            ft_error("Error\n");
        if (tmp < -2147483648 || tmp > 2147483648)
            ft_error("Error\n");
        i++;
    }
    if (ac == 2)
        ft_free(res);
}