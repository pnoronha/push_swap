/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 23:01:22 by pnoronha          #+#    #+#             */
/*   Updated: 2022/02/27 06:37:28 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		get_max(t_lst *lst)
{
	int	max;

	max = lst->index;
	lst = lst->next;
	while (lst != NULL)
	{
		if (lst->index > max)
			max = lst->index;
		lst = lst->next;
	}
	return (max);
}

int		get_min(t_lst *lst)
{
	int	min;

	min = lst->index;
	lst = lst->next;
	while (lst != NULL)
	{
		if (lst->index < min)
			min = lst->index;
		lst = lst->next;
	}
	return (min);
}

int		get_moves(t_lst *lst, int lsize)
{
	int	ret;
	int	pos_min;
	int pos_max;

	pos_min = get_position(lst, get_min(lst));
	pos_max = get_position(lst, get_max(lst));
	if (pos_min < (lsize - pos_min) && pos_max < (lsize - pos_max))
		ret = 1;
	else if (pos_min > (lsize - pos_min) && pos_max > (lsize - pos_max))
		ret = 2;
	else
		if (pos_min < (lsize / 2))
		{
			if (pos_min < (lsize - pos_max) + 1)
				ret = 1;
			else
				ret = 2;
		}
		else
		{
			if (pos_max < (lsize - pos_min) + 1)
				ret = 1;
			else
				ret = 2;
		}
	return (ret);
}

int		get_position(t_lst *a, int value)
{
	int	pos;

	pos = 1;
	while (a->index != value)
	{
		a = a->next;
		pos++;
	}
	return (pos);
}

void	sorting(t_lst **stack_a, t_data *data)
{
	t_lst	*sorted;
	t_lst	*stack_b;

	if (!*stack_a || (*stack_a)->next == NULL)
		return ;
	sorted = (t_lst *)malloc(sizeof(t_lst));
	stack_b = (t_lst *)malloc(sizeof(t_lst));
	stack_b = NULL;
	sorted = fill_stack(data);
	*stack_a = save_index(stack_a, sorted);
	free(sorted);
	if (data->number_count <= 5)
		small_sort(stack_a, &stack_b, data);
	else
	{
		if (data->number_count <= 25)
			big_sort(stack_a, &stack_b, data, 2);
		else if (data->number_count <= 100)
			big_sort(stack_a, &stack_b, data, data->number_count / 10);
		else
			big_sort(stack_a, &stack_b, data, 11);
	}
}
