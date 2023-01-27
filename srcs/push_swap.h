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

void		swap(node_list **stack);
void		rotate_down(node_list **stack);
void		rotate(node_list **stack_a);
void		push_to_a(node_list **stack_a, node_list **stack_b);
void		push_to_b(node_list **stack_a, node_list **stack_b);
void		print_stack(node_list *s);
void		lst_addback(node_list **lst, node_list *new);
node_list  	*lst_addnew(int content);
void		push_swap_three(node_list **stack_a);
void		push_swap(node_list **stack_a, node_list **stack_b);
int			calculator(node_list **stack_a, int contenu);
int			list_pos(node_list **stack, int contenu);
#endif
