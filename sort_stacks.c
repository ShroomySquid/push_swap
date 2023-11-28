/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrett <fbarrett@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:13:00 by fbarrett          #+#    #+#             */
/*   Updated: 2023/11/28 11:53:12 by fbarrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(long *list, int len)
{
	int	i;

	i = 1;
	while (list[i] && (list[i - 1] <= list[i]))
		i++;
	if (i < len)
		return (0);
	return (1);
}

int	is_rev_sorted(long *list, int len)
{
	int	i;

	i = 1;
	while (list[i] && list[i - 1] >= list[i])
		i++;
	if (i < len)
		return (0);
	return (1);
}

int	find_biggest(long *lista, int len_a)
{
	int	biggest;
	int	i;

	biggest = lista[0];
	i = 1;
	while (i < len_a)
	{
		if (lista[i] > biggest)
			biggest = lista[i];
		i++;
	}
	return (biggest);
}

int	finish_it(t_stack *stack)
{
	while ((*stack).len_b > 0)
		pa(stack);
	return (1);
}

int	sort_it(t_stack *stack, int exponent)
{
	int	a;
	int	b;

	a = (*stack).len_a;
	b = 0;
	while (b < a)
	{
		if (((*stack).relative_lista[0] >> exponent) % 2 == 0)
			pb(stack);
		else
			ra(*stack);
		b++;
	}
	finish_it(stack);
	if (is_sorted(stack->relative_lista, stack->len_a))
		return (1);
	return (sort_it(stack, (exponent + 1)));
}
