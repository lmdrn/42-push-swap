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
    if (num[i] == '-' && ft_isdigit(num[i + 1]))
        i++;
    if (num[i] == '+' && ft_isdigit(num[i + 1]))
        i++;
    while (num[i])
    {
        if (!ft_isdigit(num[i]))
            return (0);
        i++;
    }
    return (1);
}

int num_is_repeated(int num, char **av, int i)
{
    i++;
    while (av[i])
    {
        if (ft_atoi2(av[i]) == num)
            return (1);
        i++;
    }
    return (0);
}


void    check_int_min_max(char *str)
{
    int i;
    int len;

    i = 0;
    len = ft_strlen(str);
    while (str[i])
    {
        if (str[0] == '-')
        {
            if (len > 11)
                ft_error("Error");
            if ( len == 11 && ft_strncmp("-2147483648", str, 11) < 0)
                ft_error("Error");
        }
        else
        {
            if (len > 10)
                ft_error("Error");
            if (len == 10 && ft_strncmp("2147483647", str, 10) < 0)
                ft_error("Error");
        }
        i++;
    }
}

void    ft_check_args(int ac, char **av)
{
    int     i;
    long    tmp;

    i = 0;
    if (*av && ac == 2)
    {
        av = ft_split(av[1], ' ');
        check_int_min_max(av[i]);
    }
    else
        i = 1;
    while (av[i])
    {
        tmp = ft_atoi2(av[i]);
        if (!is_num(av[i]) )
            ft_error("Error");
        if (num_is_repeated(tmp, av, i))
            ft_error("Error");
        if ( tmp < -2147483648 || tmp > 2147483647 )
            ft_error("Error");

        i++;
    }
/*    if (ac == 2)
        ft_free_str(av);*/
}