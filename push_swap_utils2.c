/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrett <fbarrett@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:58:25 by fbarrett          #+#    #+#             */
/*   Updated: 2023/12/01 08:27:41 by fbarrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(long *list, int len)
{
	int	temp;

	if (!list || len < 2)
		return (0);
	temp = list[0];
	move_up(list, len);
	list[len - 1] = temp;
	return (1);
}

int	r_rotate(long *list, int len)
{
	int	temp;

	if (!list || len < 2)
		return (0);
	temp = list[len - 1];
	move_back(list, (len - 1), len);
	list[0] = temp;
	return (1);
}

int	find_smallest(long *lista, int len_a)
{
	int	smallest;
	int	i;

	smallest = lista[0];
	i = 1;
	while (i < len_a)
	{
		if (lista[i] < smallest)
			smallest = lista[i];
		i++;
	}
	return (smallest);
}

int	make_relative_list(t_stack *stack)
{
	int	i;
	int	a;
	int	position;

	i = 0;
	while (i < (*stack).len_a)
	{
		position = 1;
		a = 0;
		while (a < (*stack).len_a)
		{
			if ((*stack).lista[a] < (*stack).lista[i])
				position++;
			a++;
		}
		(*stack).relative_lista[i] = position;
		i++;
	}
	return (1);
}
