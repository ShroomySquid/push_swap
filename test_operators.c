/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_operators.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrett <fbarrett@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:44:21 by fbarrett          #+#    #+#             */
/*   Updated: 2023/11/26 10:36:39 by fbarrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "Libft/libft.h"

static int write_array_nbr(long *list, int len, char c)
{	
	if (!list)
		return (0);
	int i = 0;
	write(1, "array ", 6);
	write(1, &c, 1);
	write(1, ": ", 2);
	while (i < len)
	{
		ft_putnbr_fd(list[i], 1);	
		i++;
		write (1, "  ", 2); 
	}
	write(1, "\n", 1);
	return (1);
}

static int write_lists_len(int len_a, int len_b)
{
	write(1, "Length of lista: ", 17);
	ft_putnbr_fd(len_a, 1);
	write(1, "\n", 1);
	write(1, "Length of listb: ", 17);
	ft_putnbr_fd(len_b, 1);
	write(1, "\n", 1);
	return (1);
}

int write_tests(stack_list *stack)
{
	if (!(*stack).lista || !(*stack).listb)
		return (0);
	write (1, "\n", 1);
	write_array_nbr(stack->lista, stack->len_a, 'a');
	write_array_nbr(stack->listb, stack->len_b, 'b');
	write_array_nbr(stack->relative_lista, stack->len_a, 'a');
	write_array_nbr(stack->relative_listb, stack->len_b, 'b');
	write_lists_len(stack->len_a, stack->len_b);
	write(1, "\n", 1);
	return (1);
}	

int tests_operators(stack_list *stack)
{
	// test pour les fonctions d'opérations
	write_tests(stack);
	sa(stack);
	write_tests(stack);
	sb(stack);
	write_tests(stack);
	ra(*stack);
	write_tests(stack);
	rb(*stack);
	write_tests(stack);
	rra(*stack);
	write_tests(stack);
	rrb(*stack);
	write_tests(stack);
	pb(stack);
	write_tests(stack);
	pb(stack);
	write_tests(stack);
	pb(stack);
	write_tests(stack);
	ss(stack);
	write_tests(stack);
	rr(stack);
	write_tests(stack);
	rrr(stack);
	write_tests(stack);
	pa(stack);
	write_tests(stack);
	pa(stack);
	write_tests(stack);
	pa(stack);
	write_tests(stack);
	return (1);
}


int test_algos(stack_list *stack)
{
	write_tests(stack);
	return (1);
}

