/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 22:09:05 by pnoronha          #+#    #+#             */
/*   Updated: 2022/02/16 15:03:54 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_dblst **head)
{
	t_dblst *temp;
	int	int_swap;

	temp = *head;
	int_swap = temp->value;
	temp->value = temp->next->value;
	temp->next->value = int_swap;
}
