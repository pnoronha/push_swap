/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 22:09:05 by pnoronha          #+#    #+#             */
/*   Updated: 2022/03/03 21:09:59 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_lst **head)
{
	t_lst	*temp;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	temp = (*head)->next;
	(*head)->next = (*head)->next->next;
	temp->next = *head;
	*head = temp;
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
