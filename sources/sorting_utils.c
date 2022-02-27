/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:39:34 by pnoronha          #+#    #+#             */
/*   Updated: 2022/02/26 21:53:15 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_lst *sort_aux(t_lst *stack_a);

void	invert_sorted(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_count)
	{
		ft_putstr("pb\n");
		i++;
	}
	while (i > 0)
	{
		ft_putstr("rrb\n");
		ft_putstr("pa\n");
		i--;
	}
	exit(EXIT_SUCCESS);
}

t_lst	*save_index(t_lst **stack_a, t_lst *sorted)
{
	t_lst	*head;
	int		i;

	head = *stack_a;
	sorted = sort_aux(sorted);
	i = 1;
	while (sorted != NULL)
	{
		*stack_a = head;
		while (*stack_a != NULL)
		{
			if (sorted->value == (*stack_a)->value)
			{
				(*stack_a)->index = i++;
				break ;
			}
			(*stack_a) = (*stack_a)->next;
		}
		sorted = sorted->next;
	}
	*stack_a = head;
	return (*stack_a);
}

static t_lst *sort_aux(t_lst *stack_a)
{
	t_lst	*head;
	t_lst	*index;
	int temp;

	head = stack_a;
	index = NULL;
	while (stack_a != NULL)
	{
		index = stack_a->next;
		while (index != NULL)
		{
			if (stack_a->value > index->value)
			{
				temp = stack_a->value;
				stack_a->value = index->value;
				index->value = temp;
			}
			index = index->next;
		}
		stack_a = stack_a->next;
	}
	return (head);
}
