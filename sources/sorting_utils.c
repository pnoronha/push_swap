/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:39:34 by pnoronha          #+#    #+#             */
/*   Updated: 2022/03/02 22:19:55 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_position(t_lst *a, int value)
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

static int	get_max(t_lst *lst)
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

static int	get_min(t_lst *lst)
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

static int	pos_moves(int pos_min, int pos_max, int lsize)
{
	int	ret;

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

int	get_moves(t_lst *lst, int lsize)
{
	int	ret;
	int	pos_min;
	int	pos_max;

	pos_min = get_position(lst, get_min(lst));
	pos_max = get_position(lst, get_max(lst));
	if (pos_min < (lsize - pos_min) && pos_max < (lsize - pos_max))
		ret = 1;
	else if (pos_min > (lsize - pos_min) && pos_max > (lsize - pos_max))
		ret = 2;
	else
		ret = pos_moves(pos_min, pos_max, lsize);
	return (ret);
}
