/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 12:26:57 by pnoronha          #+#    #+#             */
/*   Updated: 2022/03/01 11:08:26 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_empty(t_lst **pusher, t_lst **receiver)
{
	*receiver = *pusher;
	*pusher = (*pusher)->next;
	(*receiver)->next = NULL;
}

void	push_non_empty(t_lst **pusher, t_lst **receiver)
{
	t_lst	*temp;

	if ((*pusher)->next == NULL)
	{
		(*pusher)->next = *receiver;
		*receiver = *pusher;
		*pusher = NULL;
	}
	else
	{
		temp = *receiver;
		*receiver = *pusher;
		*pusher = (*pusher)->next;
		(*receiver)->next = temp;
	}
}

void	push(t_lst **pusher, t_lst **receiver)
{
	if (*pusher == NULL)
		return ;
	if (list_size(*receiver) == 0)
		push_empty(pusher, receiver);
	else
		push_non_empty(pusher, receiver);
}

void	pa(t_lst **a, t_lst **b)
{
	push(b, a);
	ft_putstr("pa\n");
}

void	pb(t_lst **a, t_lst **b)
{
	push(a, b);
	ft_putstr("pb\n");
}
