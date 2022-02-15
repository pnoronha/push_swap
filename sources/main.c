/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:37:50 by pnoronha          #+#    #+#             */
/*   Updated: 2022/02/15 00:39:50 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		input_error();
	data.number_count = (argc - 1);
	data.values = (argv + 1);
	data.stack_a = NULL;
	input_parse(&data);
	return (EXIT_SUCCESS);
}

int	input_error(void)
{
	ft_putstr("Error\n");
	exit(EXIT_FAILURE);
}
