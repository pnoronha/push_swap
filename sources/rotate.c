/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:52:30 by pnoronha          #+#    #+#             */
/*   Updated: 2022/02/17 13:30:26 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_dblst **head)
{
	t_dblst	*last;
	t_dblst *first;

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

void	reverse_rotate(t_dblst **head)
{
	t_dblst	*rot;
	t_dblst	*last;

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
	ft_putstr("TESTE\n");
	rot->next = *head;
	(*head) = rot;
	(*head)->prev = NULL;
}

