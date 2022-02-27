/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 03:18:03 by pnoronha          #+#    #+#             */
/*   Updated: 2022/02/27 08:30:43 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	big_sort(t_lst **a, t_lst **b, t_data *data, int chunks)
{
	int	next_chunk;
	int	hold_max;
	int	chunk_size;

	chunk_size = data->number_count / chunks;
	data->max = data->number_count;
	data->min = data->number_count - chunk_size;
	next_chunk = data->min;
	hold_max = data->max;
	while(chunks > 0)
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
		if (chunks == 1 && (data->number_count % chunks) != 0)
			data->min = 0;
		else
			data->min = data->max - chunk_size;
		chunks--;
	}
}
