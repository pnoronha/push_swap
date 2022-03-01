/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:37:50 by pnoronha          #+#    #+#             */
/*   Updated: 2022/03/01 14:24:56 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	t_lst	**stack_a;

	if (argc < 2)
		input_error();
	data = (t_data *)malloc(sizeof(t_data));
	stack_a = (t_lst **)malloc(sizeof(t_lst));
	data->number_count = (argc - 1);
	data->values = (argv + 1);
	input_parse(data);
	*stack_a = fill_stack(data);
	sorting(stack_a, data);
	lst_delete(stack_a);
	return (EXIT_SUCCESS);
}

int	input_error(void)
{
	ft_putstr("Error\n");
	exit(EXIT_FAILURE);
}
