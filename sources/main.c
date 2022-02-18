/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:37:50 by pnoronha          #+#    #+#             */
/*   Updated: 2022/02/18 17:53:35 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_dblst	**stack_a;
	t_dblst **stack_b;

	if (argc < 2)
		input_error();
	stack_a = (t_dblst **)malloc(sizeof(t_dblst));
	stack_b = (t_dblst **)malloc(sizeof(t_dblst));
	data.number_count = (argc - 1);
	data.values = (argv + 1);
	input_parse(&data);
	*stack_a = fill_stack(&data);

	//stack_iter(stack_a);
	//swap(stack_a);
	//stack_iter(stack_a);
	//push(stack_a, stack_b);
	//stack_iter(stack_a);
	//rotate(stack_a);
	//stack_iter(stack_a);
	//reverse_rotate(stack_a);
	//stack_iter(stack_a);
	//reverse_rotate(stack_a);
	//stack_iter(stack_a);
	sorting(stack_a);

	return (EXIT_SUCCESS);
}

int	input_error(void)
{
	ft_putstr("Error\n");
	exit(EXIT_FAILURE);
}
