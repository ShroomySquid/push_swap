/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrett <fbarrett@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:56:04 by fbarrett          #+#    #+#             */
/*   Updated: 2023/11/28 11:46:22 by fbarrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_stack *stack)
{
	if (!swap(stack->lista, (*stack).len_a))
		return (0);
	if (!swap(stack->relative_lista, (*stack).len_a))
		return (0);
	write(1, "sa\n", 3);
	return (1);
}

int	sb(t_stack *stack)
{
	if (!swap(stack->listb, (*stack).len_b))
		return (0);
	if (!swap(stack->relative_listb, (*stack).len_b))
		return (0);
	write(1, "sb\n", 3);
	return (1);
}

int	ss(t_stack *stack)
{
	int	valid_op;

	valid_op = swap(stack->relative_lista, (*stack).len_a);
	valid_op += swap(stack->relative_listb, (*stack).len_b);
	valid_op += swap(stack->lista, (*stack).len_a);
	valid_op += swap(stack->listb, (*stack).len_b);
	if (valid_op < 4)
		return (0);
	write(1, "ss\n", 3);
	return (1);
}

int	pa(t_stack *stack)
{
	if ((*stack).len_b < 1)
		return (0);
	if (move_back((*stack).lista, (*stack).len_a, 
			(*stack).len_a + (*stack).len_b))
	{
		stack->lista[0] = stack->listb[0];
		move_up((*stack).listb, (*stack).len_b);
	}
	else
		return (0);
	if (move_back((*stack).relative_lista, (*stack).len_a, 
			(*stack).len_a + (*stack).len_b))
	{
		stack->relative_lista[0] = stack->relative_listb[0];
		move_up((*stack).relative_listb, (*stack).len_b);
	}
	else
		return (0);
	write(1, "pa\n", 3);
	(*stack).len_a = (*stack).len_a + 1;
	(*stack).len_b = (*stack).len_b - 1;
	return (1);
}

int	pb(t_stack *stack)
{
	if ((*stack).len_a < 1)
		return (0);
	if (move_back((*stack).listb, (*stack).len_b, 
			(*stack).len_b + (*stack).len_a))
	{
		stack->listb[0] = stack->lista[0];
		move_up((*stack).lista, (*stack).len_a);
	}
	else
		return (0);
	if (move_back((*stack).relative_listb, 
			(*stack).len_b, (*stack).len_b + (*stack).len_a))
	{
		stack->relative_listb[0] = stack->relative_lista[0];
		move_up((*stack).relative_lista, (*stack).len_a);
	}
	else
		return (0);
	write(1, "pb\n", 3);
	(*stack).len_b = (*stack).len_b + 1;
	(*stack).len_a = (*stack).len_a - 1;
	return (1);
}
