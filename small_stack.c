/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrett <fbarrett@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:03:46 by fbarrett          #+#    #+#             */
/*   Updated: 2023/11/28 11:52:52 by fbarrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack stack)
{
	if (stack.lista[0] == find_biggest(stack.lista, stack.len_a))
		ra(stack);
	else if (stack.lista[1] == find_biggest(stack.lista, stack.len_a))
		rra(stack);
	if (!is_sorted(stack.lista, stack.len_a))
		sa(&stack);
}

static	void	sort_4(t_stack stack)
{
	while (stack.len_b < 2)
	{
		if (stack.relative_lista[0] < 3)
			pb(&stack);
		else
			ra(stack);
	}
	if (!is_sorted(stack.lista, stack.len_a) && 
		!is_rev_sorted(stack.listb, stack.len_b))
		ss(&stack);
	else if (!is_sorted(stack.lista, stack.len_a))
		sa(&stack);
	else if (!is_rev_sorted(stack.listb, stack.len_b))
		sb(&stack);
	pa(&stack);
	pa(&stack);
}

static	void	sort_5(t_stack stack)
{
	while (stack.len_b < 2)
	{
		if (stack.relative_lista[0] < 3)
			pb(&stack);
		else
			ra(stack);
	}
	if (!is_sorted(stack.lista, stack.len_a))
		sort_3(stack);
	else if (!is_rev_sorted(stack.listb, stack.len_b))
		sb(&stack);
	pa(&stack);
	pa(&stack);
}

static	void	sort_6(t_stack stack)
{
	while (stack.len_b < 3)
	{
		if (stack.relative_lista[0] < 4)
			pb(&stack);
		else
			ra(stack);
	}
	if (!is_sorted(stack.lista, stack.len_a))
		sort_3(stack);
	else if (!is_rev_sorted(stack.listb, stack.len_b))
	{
		if (stack.listb[0] == find_smallest(stack.listb, stack.len_b))
			rb(stack);
		else if (stack.listb[1] == find_smallest(stack.listb, stack.len_b))
			rrb(stack);
		if (!is_rev_sorted(stack.listb, stack.len_b))
			sb(&stack);
	}
	pa(&stack);
	pa(&stack);
	pa(&stack);
}

void	sort_small_stack(t_stack stack)
{
	if (stack.len_a == 2)
		sa(&stack);
	if (stack.len_a == 3)
		sort_3(stack);
	if (stack.len_a == 4)
		sort_4(stack);
	if (stack.len_a == 5)
		sort_5(stack);
	if (stack.len_a == 6)
		sort_6(stack);
}
