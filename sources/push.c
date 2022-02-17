/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 12:26:57 by pnoronha          #+#    #+#             */
/*   Updated: 2022/02/17 13:53:27 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_empty(t_dblst **pusher, t_dblst **receiver)
{
	t_dblst	*temp;

	temp = *pusher;
	*receiver = temp;
	*pusher = temp->next;
	temp->next->prev = NULL;
	temp->next = NULL;
}

void	push_non_empty(t_dblst **pusher, t_dblst **receiver)
{
	t_dblst	*temp_push;
	t_dblst	*temp_rcv;

	temp_push = *pusher;
	temp_rcv = *receiver;
	*receiver = temp_push;
	*pusher = temp_push->next;
	temp_push->next->prev = NULL;
	temp_push->next = temp_rcv;
	temp_rcv->prev = temp_push;
}

void	push(t_dblst **pusher, t_dblst **receiver)
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
