/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrett <fbarrett@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:27:37 by fbarrett          #+#    #+#             */
/*   Updated: 2023/11/28 13:37:58 by fbarrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "Libft/libft.h"

int	check_invalid_digits(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_valid_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!check_invalid_digits(argv[i]) || ft_strlen(argv[i]) > 11)
		{
			ft_putstr_fd("Error\n", 1);
			return (0);
		}
		i++;
	}
	i = 0;
	return (1);
}

int	static	check_valid_int(t_stack stack)
{
	int	i;

	i = 0;
	while (i < stack.len_a)
	{
		if (stack.lista[i] > 2147483647 || stack.lista[i] < -2147483648)
		{
			free(stack.lista);
			free(stack.listb);
			ft_putstr_fd("Error\n", 1);
			return (0);
		}
		i++;
	}
	return (1);
}

int	static	check_double(t_stack stack)
{
	int	i;
	int	a;

	i = 0;
	while (i < stack.len_a)
	{
		a = i + 1;
		while (a < stack.len_a)
		{
			if (stack.lista[i] == stack.lista[a])
			{
				write(1, "Error", 5);
				return (0);
			}
			a++;
		}
		i++;
	}
	return (1);
}

int	check_valid_list(t_stack stack)
{
	int	i;

	i = 0;
	if (!check_valid_int(stack))
		i += 1;
	if (!check_double(stack))
		i += 1;
	if (!make_relative_list(&stack))
		i += 1;
	if (i > 0)
	{
		free_stack(&stack);
		return (0);
	}
	else
		return (1);
}
