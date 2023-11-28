/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrett <fbarrett@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:03:53 by fbarrett          #+#    #+#             */
/*   Updated: 2023/11/28 11:47:31 by fbarrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_stack stack)
{
	if (!rotate(stack.lista, stack.len_a))
		return (0);
	if (!rotate(stack.relative_lista, stack.len_a))
		return (0);
	write(1, "ra\n", 3);
	return (1);
}

int	rb(t_stack stack)
{
	if (!rotate(stack.listb, stack.len_b))
		return (0);
	if (!rotate(stack.relative_listb, stack.len_b))
		return (0);
	write(1, "rb\n", 3);
	return (1);
}

int	rr(t_stack *stack)
{
	int	valid_op;

	valid_op = rotate(stack->relative_lista, (*stack).len_a);
	valid_op += rotate(stack->relative_listb, (*stack).len_b);
	valid_op += rotate(stack->lista, (*stack).len_a);
	valid_op += rotate(stack->listb, (*stack).len_b);
	if (valid_op < 4)
		return (0);
	write(1, "rr\n", 3);
	return (1);
}

int	rra(t_stack stack)
{
	if (!r_rotate(stack.lista, stack.len_a))
		return (0);
	if (!r_rotate(stack.relative_lista, stack.len_a))
		return (0);
	write(1, "rra\n", 4);
	return (1);
}

int	rrb(t_stack stack)
{
	if (!r_rotate(stack.listb, stack.len_b))
		return (0);
	if (!r_rotate(stack.relative_listb, stack.len_b))
		return (0);
	write(1, "rrb\n", 4);
	return (1);
}
