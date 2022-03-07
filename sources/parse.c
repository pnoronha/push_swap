/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:43:17 by pnoronha          #+#    #+#             */
/*   Updated: 2022/03/07 18:51:07 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_not_duplicated(t_data *data)
{
	int	*values_arr;
	int	i;
	int	j;

	i = 0;
	values_arr = (int *)malloc(sizeof(int) * data->number_count);
	while (i < data->number_count)
	{
		values_arr[i] = ft_atoi(data->values[i]);
		i++;
	}
	i = 0;
	while (i < data->number_count)
	{
		j = i + 1;
		while (j < data->number_count)
		{
			if (values_arr[i] == values_arr[j])
				return (FAILURE);
			j++;
		}
		i++;
	}
	free(values_arr);
	return (SUCCESS);
}

static int	is_sorted(t_data *data)
{
	int	sorted;
	int	i;

	sorted = 1;
	i = 0;
	while (i < data->number_count - 1)
	{
		if (ft_atoi(data->values[i]) > ft_atoi(data->values[i + 1]))
			sorted = 0;
		i++;
	}
	return (sorted);
}

static int	is_interger(char *number)
{
	int	index;

	if (!*number)
		return (FAILURE);
	index = 0;
	if (number[index] == '-' || number[index] == '+')
	{
		index++;
		if (!number[index])
			return (FAILURE);
	}
	while (number[index])
		if (!ft_isdigit(number[index++]))
			return (FAILURE);
	if (ft_atol(number) < INT_MIN || ft_atol(number) > INT_MAX)
		return (FAILURE);
	return (SUCCESS);
}

int	input_parse(t_data *data)
{
	int		index;

	index = 0;
	while (index < data->number_count)
	{
		if (!is_interger(data->values[index++]))
			return (FAILURE);
	}
	if (!is_not_duplicated(data))
		return (FAILURE);
	else if (is_sorted(data))
		exit(EXIT_SUCCESS);
	return (SUCCESS);
}
