/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_processor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 01:28:49 by pnoronha          #+#    #+#             */
/*   Updated: 2022/02/23 22:38:05 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_lst	*fill_stack(t_data *data)
{
	t_lst	*head;
	t_lst	*current;
	int		i;

	i = 0;
	head = new_node(ft_atoi(data->values[i++]), NULL);
	current = head;
	while (i < data->number_count)
	{
		current->next = new_node(ft_atoi(data->values[i]), current);
		current = current->next;
		i++;
	}
	return (head);
}

t_lst	*new_node(int value, t_lst *prev)
{
	t_lst	*new;

	new = (t_lst *)malloc(sizeof(t_lst));
	if (!new)
		return (NULL);
	new->prev = prev;
	new->value = value;
	new->next = NULL;
	return (new);
}

void	stack_iter(t_lst *stack)
{
	t_lst	*temp;

	temp = (t_lst *)malloc(sizeof(t_lst));
	temp = stack;
	while (temp != NULL)
	{
		ft_putstr(ft_itoa(temp->value));
		ft_putstr(" ");
		temp = temp->next;
	}
	ft_putstr("\n");
	free(temp);
}

int	list_size(t_lst *stack)
{
	t_lst	*temp;
	int		count;

	temp = (t_lst *)malloc(sizeof(t_lst));
	temp = stack;
	count = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		count++;
	}
	free(temp);
	return (count);
}
