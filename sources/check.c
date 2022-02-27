/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 02:20:52 by pnoronha          #+#    #+#             */
/*   Updated: 2022/02/27 02:38:55 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_sorted(t_lst *lst)
{
	t_lst	*temp;

	temp = (t_lst *)malloc(sizeof(t_lst));
	temp = lst;
	while (temp != NULL)
	{
		if (temp->index > temp->next->index)
			return (0);
		ft_putstr(" ");
		temp = temp->next;
	}
	ft_putstr("\n");
	free(temp);
	return (1);
}

