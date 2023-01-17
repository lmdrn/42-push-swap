/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:15:10 by lmedrano          #+#    #+#             */
/*   Updated: 2023/01/10 17:25:17 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/*node_list	*swap_a(node_list *stack_a)
{

}

node_list	*swap_b(node_list *stack_b)
{
}*/

/*node_list	ss(node_list stack_ a, node_list stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
}

node_list	*push_to_a(node_list stack_a, node_list stack_b)
{
//push 1st int from b to a
//do nthg if b is empty
	stack_b->next = *stack_a;
	*stack_a = stack_b;
}

node_list *push_to_b(node_list stack_b, node_list stack_a)
{
//push 1st int from a to b
//do nothg if a is NULL
	stack_a->next = *stack_b;
	*stack_b = stack_a;	
}	

node_list ra(node_list stack_a)
{
//décale d'un cran vers le haut dans stack a
}

int rb(int b)
{
//décale d'un cran vers le haut dans stack b
}

int rr(int a, int b)
{
//ra + rb
}
*/
node_list *rra(node_list *stack_a)
{
	node_list *temp;
	node_list *new_stack;
	int		i;
	int		j;
	
	printf("\n");
	print_stack(stack_a);
	temp = stack_a;//assign to head of stack a
	i = 0;
	while (temp->next) //while i'm not at the end of the list
	{
		temp = temp->next;//move forward
		i++;//count length
		printf("%d\n", i);
	}
	temp->next = stack_a;//here temp->next should be equal to last elem
						 //which we assign to head

	j = i - 1;//assign j to lenght of list minus x times we want to rotate 
			  //always one time in our case
	temp = stack_a;//reassign hed to temp to back to beginning of list
	while (j)
	{
		temp = temp->next;//should go to last elem we want
		j--;
	}	
	new_stack = temp->next; //return our new head;
	temp->next = NULL;
   
	printf("\n");
	print_stack(new_stack);
	return (new_stack);	//should tell the new last elem 
					  //that the next one is the end of the list
}
/*
node_list rrb(node_list stack_b)
{
//décale d'un cran vers le bas dans stack b
	node_list	*first;

	first = stack_b;
	first->next = first->next->next;
	//todo 1st becomes last
}

int rrr(int a, int b)
{
//rra+rrb
}*/
