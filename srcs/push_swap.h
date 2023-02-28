/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:59:10 by lmedrano          #+#    #+#             */
/*   Updated: 2023/01/27 15:37:44 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "../libft/libft.h"

int 	    is_sorted(node_list *stack);
void        ft_free_stack(node_list **stack);
void        ft_free_str(char *str);
void        ft_error();
int	        swap(node_list **stack);
int	        swap_a(node_list **stack_a);
int	        swap_b(node_list **stack_b);
int	        swap_both(node_list **stack_a, node_list **stack_b);
int	        push(node_list **stack_to, node_list **stack_from);
int	        push_a(node_list **stack_a, node_list **stack_b);
int	        push_b(node_list **stack_b, node_list **stack_a);
int	        rotate(node_list **stack);
int	        rotate_a(node_list **stack_a);
int	        rotate_b(node_list **stack_b);
int	        rotate_both(node_list **stack_a, node_list **stack_b);
int	        rotate_down(node_list **stack);
int	        rotate_down_a(node_list **stack_a);
int	        rotate_down_b(node_list **stack_b);
int	        rotate_down_both(node_list **stack_a, node_list **stack_b);
node_list	*lst_addnew(int contenu);
void	    lst_addback(node_list **lst, node_list *new);
int	        lst_size(node_list *lst);
void	    print_stack(node_list *stack);
int		    is_sorted(node_list *stack);
void        ft_check_args(int ac, char **av);
void	    ft_sort(node_list **stack_a, node_list **stack_b);
void        ft_normalize(node_list **stack);
void        small_sort(node_list **stack_a, node_list **stack_b);
void        big_sort(node_list **stack_a, node_list **stack_b);

#endif
