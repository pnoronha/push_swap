/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:39:34 by pnoronha          #+#    #+#             */
/*   Updated: 2022/02/18 18:21:47 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_dblst *sortlist(t_dblst *stack_a);

t_dblst *save_index(t_dblst *stack_a)
{
	t_dblst	*temp;
	t_dblst *sorted;
	int		i;

	temp = stack_a;
	sorted = sortlist(stack_a);
	i = 0;
	while (sorted->next != NULL)
	{
		while (temp->next != NULL)
		{
			if (sorted->value == temp->value)
				temp->index = i;
			temp = temp->next;
		}
		sorted = sorted->next;
		i++;
	}
	return (stack_a);
}

static t_dblst *sortlist(t_dblst *stack_a)
{
	t_dblst	*head;
	t_dblst	*index;
	int temp;

	head = stack_a;
	index = NULL;
	if (head == NULL)
		return (NULL);
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
