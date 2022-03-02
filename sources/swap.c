/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 22:09:05 by pnoronha          #+#    #+#             */
/*   Updated: 2022/03/02 14:56:52 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_lst **head)
{
	t_lst	*temp;
	int		int_swap;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	temp = *head;
	int_swap = temp->value;
	temp->value = temp->next->value;
	temp->next->value = int_swap;
	int_swap = temp->index;
	temp->index = temp->next->index;
	temp->next->index = int_swap;
}

void	sa(t_lst **a)
{
	swap(a);
	ft_putstr("sa\n");
}

void	sb(t_lst **b)
{
	swap(b);
	ft_putstr("sb\n");
}

void	ss(t_lst **a, t_lst **b)
{
	swap(a);
	swap(b);
	ft_putstr("ss\n");
}
