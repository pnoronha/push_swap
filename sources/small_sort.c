/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 02:59:44 by pnoronha          #+#    #+#             */
/*   Updated: 2022/02/27 09:02:52 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_three_cases(t_lst **a, int pos1, int pos2, int pos3)
{
	if (pos1 < pos2 && pos2 > pos3 && pos3 > pos1)
	{
		sa(a);
		ra(a);
	}
	else if (pos1 > pos2 && pos1 > pos3)
	{
		if (pos2 < pos3)
			ra(a);
		else
		{
			sa(a);
			rra(a);
		}
	}
	else
	{
		if (pos2 < pos3)
			sa(a);
		else
			rra(a);
	}
}

static void	sort_three(t_lst **a)
{
	int	pos1;
	int	pos2;
	int	pos3;

	pos1 = (*a)->index;
	pos2 = (*a)->next->index;
	pos3 = (*a)->next->next->index;
	if (pos1 < pos2 && pos2 < pos3)
		return ;
	sort_three_cases(a, pos1, pos2, pos3);
}

static void	sort_five(t_lst **a, t_lst **b)
{
	while (list_size(*b) < 2)
	{
		if ((*a)->index == 1 || (*a)->index == 2)
			pb(a, b);
		else
			ra(a);
	}
	if ((*b)->index < (*b)->next->index)
		sb(b);
	sort_three(a);
	pa(a, b);
	pa(a, b);
}

void	small_sort(t_lst **a, t_lst **b, t_data *data)
{
	if (data->number_count == 2)
		sa(a);
	else if (data->number_count == 3)
		sort_three(a);
	else if (data->number_count == 4)
	{
		while ((*a)->index != 1)
		{
			if (get_position(*a, 1) < (data->number_count / 2))
				ra(a);
			else
				rra(a);
		}
		pb(a, b);
		sort_three(a);
		pa(a, b);
	}
	else
		sort_five(a, b);
	return ;
}
