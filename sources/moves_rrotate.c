/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rrotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 01:46:07 by pnoronha          #+#    #+#             */
/*   Updated: 2022/02/26 15:03:34 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
