/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_processor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 01:28:49 by pnoronha          #+#    #+#             */
/*   Updated: 2022/02/17 11:43:16 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_dblst	*fill_stack(t_data *data)
{
	t_dblst	*head;
	t_dblst	*current;
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

t_dblst	*new_node(int value, t_dblst *prev)
{
	t_dblst	*new;

	new = (t_dblst *)malloc(sizeof(t_dblst));
	if (!new)
		return (NULL);
	new->prev = prev;
	new->value = value;
	new->next = NULL;
	return (new);
}

void	stack_iter(t_dblst **stack)
{
	t_dblst	*temp;

	temp = (t_dblst *)malloc(sizeof(t_dblst));
	temp = *stack;
	while (temp != NULL)
	{
		ft_putstr(ft_itoa(temp->value));
		ft_putstr(" ");
		temp = temp->next;
	}
	ft_putstr("\n");
	free(temp);
}

int	list_size(t_dblst *stack)
{
	t_dblst	*temp;
	int		count;

	temp = (t_dblst *)malloc(sizeof(t_dblst));
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
