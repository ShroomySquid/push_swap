/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrett <fbarrett@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:50:17 by fbarrett          #+#    #+#             */
/*   Updated: 2023/11/28 11:59:57 by fbarrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
	int		len_a;
	int		len_b;
	long	*lista;
	long	*relative_lista;
	long	*listb;
	long	*relative_listb;
}				t_stack;

void	sort_3(t_stack stack);
void	sort_small_stack(t_stack stack);
int		sort_it(t_stack *stack, int exponent);
int		is_rev_sorted(long *list, int len);
int		find_biggest(long *lista, int len_a);
int		find_smallest(long *lista, int len_a);
int		is_sorted(long *list, int len);
int		check_invalid_digits(char *str);
int		check_valid_argv(char **argv);
int		check_valid_list(t_stack stack);
void	free_stack(t_stack *stack);
int		make_relative_list(t_stack *stack);
int		swap(long *list, int len);
int		move_back(long *list, int len, int max_len);
int		move_up(long *list, int len);
int		rotate(long *list, int len);
int		r_rotate(long *list, int len);
int		sa(t_stack *stack);
int		sb(t_stack *stack);
int		ss(t_stack *stack);
int		pb(t_stack *stack);
int		pa(t_stack *stack);
int		ra(t_stack stack);
int		rb(t_stack stack);
int		rr(t_stack *stack);
int		rra(t_stack stack);
int		rrb(t_stack stack);
int		rrr(t_stack *stack);

#endif
