/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:43:17 by pnoronha          #+#    #+#             */
/*   Updated: 2022/02/15 00:38:36 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_number(char *number);
static int	is_interger(char *number);
static int	is_not_duplicated(t_data *data);

void	input_parse(t_data *data)
{
	int		index;
	char	**tmp_values;

	tmp_values = data->values;
	index = 0;
	while (index < data->number_count)
	{
		if (!is_number(*data->values) || !is_interger(*data->values))
			input_error();
		data->values++;
		index++;
	}
	data->values = tmp_values;
	if (!is_not_duplicated(data))
		input_error();
	return ;
}

static int	is_number(char *number)
{
	if (!*number)
		return (FAILURE);
	if (*number == '-')
		number++;
	while (*number != '\0')
	{
		if (*number < '0' || *number > '9')
			return (FAILURE);
		number++;
	}
	return (SUCCESS);
}

static int	is_interger(char *number)
{
	char	*tmp_char;

	if (!*number)
		return (FAILURE);
	tmp_char = ft_itoa(ft_atoi(number));
	if (ft_strlen(number) != ft_strlen(tmp_char)
		|| ft_strncmp(tmp_char, number, ft_strlen(number)))
	{
		free(tmp_char);
		return (FAILURE);
	}
	else
	{
		free(tmp_char);
		return (SUCCESS);
	}
}

static int	is_not_duplicated(t_data *data)
{
	int	*values_arr;
	int i;
	int j;

	i = 0;
	values_arr = (int *)malloc(sizeof(int) * data->number_count + 1);
	while (i < data->number_count)
	{
		values_arr[i] = ft_atoi(data->values[i]);
		i++;
	}
	i = 0;
	while (i + 1 <= data->number_count)
	{
		j = i + 1;
		while (values_arr[j] != '\0')
		{
			if (values_arr[i] == values_arr[j])
				return (FAILURE);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
