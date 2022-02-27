/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:52:30 by pnoronha          #+#    #+#             */
/*   Updated: 2022/02/26 10:43:01 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_lst **head)
{
	t_lst	*last;
	t_lst *first;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	last = *head;
	first = *head;
	while (last->next != NULL)
	{
		last = last->next;
	}
	*head = first->next;
	first->next = NULL;
	last->next = first;
	(*head)->prev = NULL;
}

void	ra(t_lst **a)
{
	rotate(a);
	ft_putstr("ra\n");
}

void	rb(t_lst **b)
{
	rotate(b);
	ft_putstr("rb\n");
}

void	rr(t_lst **a, t_lst **b)
{
	rotate(a);
	rotate(b);
	ft_putstr("rr\n");
}
