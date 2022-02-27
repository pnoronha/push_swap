/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rrotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 01:46:07 by pnoronha          #+#    #+#             */
/*   Updated: 2022/02/26 10:43:14 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	rra(t_lst **a)
{
	reverse_rotate(a);
	ft_putstr("rra\n");
}

void	rrb(t_lst **b)
{
	reverse_rotate(b);
	ft_putstr("rrb\n");
}

void	rrr(t_lst **a, t_lst **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putstr("rrr\n");
}
