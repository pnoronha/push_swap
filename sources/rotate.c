/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:52:30 by pnoronha          #+#    #+#             */
/*   Updated: 2022/02/26 15:02:44 by pnoronha         ###   ########.fr       */
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

void	reverse_rotate(t_lst **head)
{
	t_lst	*rot;
	t_lst	*last;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	last = NULL;
	rot = *head;
	while (rot->next != NULL)
	{
		last = rot;
		rot = rot->next;
	}
	last->next = NULL;
	rot->next = *head;
	(*head) = rot;
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
