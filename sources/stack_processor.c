/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_processor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 01:28:49 by pnoronha          #+#    #+#             */
/*   Updated: 2022/02/15 02:41:20 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*fill_stack(t_data *data)
{
	t_stack	*new_node;
	int		i;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	i = data->number_count;
	while (i > 0)
	{
		new_node->value = ft_atoi(data->values[i]);
		new_node->next = data->stack_a;
		data->stack_a = new_node;
		i--;
	}
	return (data->stack_a);
}

void	stack_iter(t_stack *stack)
{
	t_stack	*temp;

	temp = (t_stack *)malloc(sizeof(t_stack));
	temp = stack;
	while (temp != NULL)
	{
		ft_putstr(ft_itoa(temp->value));
		temp = temp->next;
	}
}
