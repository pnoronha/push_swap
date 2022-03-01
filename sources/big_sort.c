/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 03:18:03 by pnoronha          #+#    #+#             */
/*   Updated: 2022/03/01 16:30:26 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	big_sort(t_lst **a, t_lst **b, t_data *data, int chunks)
{
	int	next_chunk;
	int	hold_max;
	int	chunk_size;
	int	i;

	chunk_size = data->number_count / chunks;
	data->max = data->number_count;
	data->min = data->number_count - chunk_size;
	next_chunk = data->min;
	hold_max = data->max;
	i = 0;
	while(i < chunks)
	{
		while (list_size(*b) < chunk_size)
		{
			if ((*a)->index > data->min)
				pb(a, b);
			else
				while ((*a)->index <= data->min)
					ra(a);
		}
		while (*b != NULL)
		{
			if (i > 0)
				while ((*a)->index != data->max + 1)
					ra(a);
			if ((*b)->index == data->max)
			{
				pa(a, b);
				data->max--;
			}
			else if ((*b)->index == data->min + 1)
			{
				pa(a, b);
				ra(a);
				data->min++;
			}
			else
			{
				if (get_moves(*b, list_size(*b)) == 1)
					rb(b);
				else
					rrb(b);
			}
		}
		while ((*a)->index != hold_max)
			ra(a);
		ra(a);
		data->max = next_chunk;
		data->min = data->max - chunk_size;
		if (chunks - i == 2)
		{
			data->min = 0;
			chunk_size = data->max;
		}
		i++;
	}
}
