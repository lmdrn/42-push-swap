/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:59:10 by lmedrano          #+#    #+#             */
/*   Updated: 2023/03/05 13:47:55 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "../libft/libft.h"

void			ft_free_stack(t_node **stack);
void			ft_free_str(char **str);
void			ft_error(char *str);
void			swap(t_node **stack);
void			swap_a(t_node **stack_a);
void			swap_b(t_node **stack_b);
void			swap_both(t_node **stack_a, t_node **stack_b);
void			push(t_node **stack_to, t_node **stack_from);
void			push_a(t_node **stack_a, t_node **stack_b);
void			push_b(t_node **stack_b, t_node **stack_a);
void			rotate(t_node **stack);
void			rotate_a(t_node **stack_a);
void			rotate_b(t_node **stack_b);
void			rotate_both(t_node **stack_a, t_node **stack_b);
void			rotate_down(t_node **stack);
void			rotate_down_a(t_node **stack_a);
void			rotate_down_b(t_node **stack_b);
void			rotate_down_both(t_node **stack_a, t_node **stack_b);
t_node			*lst_new(int contenu);
t_node			*lst_last(t_node *head);
void			lst_addfront(t_node **lst, t_node *new);
void			lst_addback(t_node **lst, t_node *new);
int				lst_size(t_node *lst);
void			print_stack(t_node *stack);
int				is_sorted(t_node **stack);
void			ft_check_args(int ac, char **av);
void			ft_sort(t_node **stack_a, t_node **stack_b);
void			ft_normalize(t_node **stack);
void			small_sort(t_node **stack_a, t_node **stack_b);
void			big_sort(t_node **stack_a, t_node **stack_b);
long long int	ft_atoi2(const char *str);
int				get_min(t_node **stack, int index);
int				get_distance(t_node **stack, int min);

#endif
