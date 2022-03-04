/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:37:50 by pnoronha          #+#    #+#             */
/*   Updated: 2022/03/04 19:40:29 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_lst	**stack_a;

	if (argc < 2)
		return (0);
	data.number_count = (argc - 1);
	data.values = (argv + 1);
	if (!input_parse(&data))
		input_error();
	stack_a = (t_lst **)malloc(sizeof(t_lst));
	*stack_a = fill_stack(&data);
	sorting(stack_a, &data);
	lst_delete(stack_a);
	free(stack_a);
	return (EXIT_SUCCESS);
}

int	input_error(void)
{
	ft_putstr("Error\n");
	exit(EXIT_FAILURE);
}
