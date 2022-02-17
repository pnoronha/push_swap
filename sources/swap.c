/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 22:09:05 by pnoronha          #+#    #+#             */
/*   Updated: 2022/02/17 13:01:31 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_dblst **head)
{
	t_dblst *temp;
	int	int_swap;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	temp = *head;
	int_swap = temp->value;
	temp->value = temp->next->value;
	temp->next->value = int_swap;
}
