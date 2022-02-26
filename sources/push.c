/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 12:26:57 by pnoronha          #+#    #+#             */
/*   Updated: 2022/02/26 19:14:45 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_empty(t_lst **pusher, t_lst **receiver)
{
	t_lst	*temp;

	temp = *pusher;
	*receiver = temp;
	*pusher = temp->next;
	temp->next->prev = NULL;
	temp->next = NULL;
}

void	push_non_empty(t_lst **pusher, t_lst **receiver)
{
	t_lst	*temp_push;
	t_lst	*temp_rcv;

	temp_push = *pusher;
	temp_rcv = *receiver;
	*receiver = temp_push;
	*pusher = temp_push->next;
	temp_push->next->prev = NULL;
	temp_push->next = temp_rcv;
	temp_rcv->prev = temp_push;
}

void	push(t_lst **pusher, t_lst **receiver)
{
	if (*pusher == NULL || (*pusher)->next == NULL)
		return ;
	if (list_size(*receiver) == 0)
	{
		push_empty(&*pusher, &*receiver);
	}
	else
	{
		push_non_empty(&*pusher, &*receiver);
	}
}

void	pa(t_lst **a, t_lst **b)
{
	push(a, b);
	ft_putstr("pa\n");
}

void	pb(t_lst **a, t_lst **b)
{
	push(b, a);
	ft_putstr("pb\n");
}
