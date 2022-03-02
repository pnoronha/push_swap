/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 03:18:03 by pnoronha          #+#    #+#             */
/*   Updated: 2022/03/02 20:43:07 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	fix_stack_position(t_lst **a, t_data *data)
{
	if (get_position(*a, 1) < (data->number_count / 2))
	{
		while ((*a)->index != data->number_count)
			ra(a);
		ra(a);
	}
	else
		while ((*a)->index != 1)
			rra(a);
}

static void	push_chunk(t_lst **a, t_lst **b, t_data *data, int chunk_size)
{
	while (list_size(*b) < chunk_size)
	{
		if ((*a)->index > data->min && (*a)->index <= data->max)
			pb(a, b);
		else
			ra(a);
	}
}

static void	push_chunk_back(t_lst **a, t_lst **b, t_data **data)
{
	while (*b != NULL)
	{
		if ((*b)->index == (*data)->max)
		{
			pa(a, b);
			(*data)->max--;
		}
		else if ((*b)->index == ((*data)->min + 1))
		{
			pa(a, b);
			ra(a);
			(*data)->min++;
		}
		else
		{
			if (get_moves(*b, list_size(*b)) == 1)
				rb(b);
			else
				rrb(b);
		}
	}
}

void	big_sort(t_lst **a, t_lst **b, t_data *data, int chunks)
{
	int	next_chunk;
	int	chunk_size;

	chunk_size = data->number_count / chunks;
	data->max = data->number_count;
	data->min = data->max - chunk_size;
	next_chunk = data->min;
	while (chunks > 0)
	{
		push_chunk(a, b, data, chunk_size);
		push_chunk_back(a, b, &data);
		data->max = next_chunk;
		data->min = data->max - chunk_size;
		next_chunk = data->min;
		if (chunks == 2)
		{
			data->min = 0;
			chunk_size = data->max;
		}
		chunks--;
	}
	fix_stack_position(a, data);
}
