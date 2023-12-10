/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrett <fbarrett@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:09:41 by fbarrett          #+#    #+#             */
/*   Updated: 2023/12/10 16:34:44 by fbarrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "Libft/libft.h"

static	int	calloc_moi_ca(t_stack *stack)
{
	stack->lista = ft_calloc(stack->len_a, sizeof(long));
	stack->listb = ft_calloc(stack->len_a, sizeof(long));
	stack->relative_lista = ft_calloc(stack->len_a, sizeof(long));
	stack->relative_listb = ft_calloc(stack->len_a, sizeof(long));
	return (1);
}

int	create_int_array(t_stack stack, char **str_array)
{
	int	i;

	i = 0;
	while (i < stack.len_a)
	{
		stack.lista[i] = ft_atoi(str_array[i]);
		i++;
	}
	return (1);
}

void	free_stack(t_stack *stack)
{
	free(stack->lista);
	free(stack->listb);
	free(stack->relative_lista);
	free(stack->relative_listb);
}

int	list_in_str(t_stack *stack, char **argv)
{
	char	**temp_argv;

	temp_argv = ft_split(argv[1], ' ');
	if (!check_valid_argv(temp_argv))
	{
		free_all(temp_argv);
		return (1);
	}
	(*stack).len_a = count_str(argv[1], ' ');
	calloc_moi_ca(stack);
	create_int_array(*stack, temp_argv);
	free_all(temp_argv);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	stack.len_a = argc - 1;
	stack.len_b = 0;
	if (argc < 2)
		return (0);
	if (argc == 2 && ft_strchr(argv[1], ' '))
	{
		if (list_in_str(&stack, argv))
			return (1);
	}
	else if (!check_valid_argv(&argv[1]))
		return (1);
	else
	{
		calloc_moi_ca(&stack);
		create_int_array(stack, &argv[1]);
	}
	if (!check_valid_list(stack))
		return (1);
	if (stack.len_a < 7 && !is_sorted(stack.relative_lista, stack.len_a))
		sort_small_stack(stack);
	else if (!is_sorted(stack.relative_lista, stack.len_a))
		sort_it(&stack, 0);
	return (free_stack(&stack), 0);
}
