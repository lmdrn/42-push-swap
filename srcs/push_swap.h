/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:59:10 by lmedrano          #+#    #+#             */
/*   Updated: 2023/01/10 19:06:17 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "../libft/libft.h"

node_list	*swap_a(node_list *stack_a);
node_list	*rra(node_list *stack_a);
void	print_stack(node_list *s);
node_list  t_lst_addnew(int content);

#endif
