/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrett <fbarrett@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:13:28 by fbarrett          #+#    #+#             */
/*   Updated: 2023/11/28 11:48:42 by fbarrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(long *list, int len)
{
	int	temp;

	if (len < 2 || (list[0] == list[1]))
		return (0);
	temp = list[0];
	list[0] = list[1];
	list[1] = temp;
	return (1);
}

int	move_back(long *list, int len, int max_len)
{
	if (len > max_len || !list)
		return (0);
	while (len > 0)
	{
		list[len] = list[len - 1];
		len--;
	}
	return (1);
}

int	move_up(long *list, int len)
{
	int	i;

	if (!list)
		return (0);
	i = 1;
	while (i < len)
	{
		list[i - 1] = list[i];
		i++;
	}
	return (1);
}

int	rrr(t_stack *stack)
{
	int	valid_op;

	valid_op = r_rotate(stack->relative_lista, (*stack).len_a);
	valid_op += r_rotate(stack->relative_listb, (*stack).len_b);
	valid_op += r_rotate(stack->lista, (*stack).len_a);
	valid_op += r_rotate(stack->listb, (*stack).len_b);
	if (valid_op < 4)
		return (0);
	write(1, "rrr\n", 3);
	return (1);
}
