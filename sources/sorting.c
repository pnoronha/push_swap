/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 23:01:22 by pnoronha          #+#    #+#             */
/*   Updated: 2022/03/02 22:24:10 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_lst	*sort_aux(t_lst *stack_a)
{
	t_lst	*head;
	t_lst	*index;
	int		temp;

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

static t_lst	*save_index(t_lst **stack_a, t_lst *sorted)
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

void	sorting(t_lst **stack_a, t_data *data)
{
	t_lst	*sorted;
	t_lst	*stack_b;

	if (!*stack_a || (*stack_a)->next == NULL)
		return ;
	stack_b = NULL;
	sorted = fill_stack(data);
	*stack_a = save_index(stack_a, sorted);
	lst_delete(&sorted);
	if (data->number_count <= 5)
		small_sort(stack_a, &stack_b, data);
	else
	{
		if (data->number_count <= 25)
			big_sort(stack_a, &stack_b, data, 1);
		else if (data->number_count <= 100)
			big_sort(stack_a, &stack_b, data, 3);
		else
			big_sort(stack_a, &stack_b, data, 7);
	}
	lst_delete(&stack_b);
}
