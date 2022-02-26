/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 23:01:22 by pnoronha          #+#    #+#             */
/*   Updated: 2022/02/26 19:15:24 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	small_sort(t_lst **a, t_lst **b, t_data *data);
void	sort_big(t_lst **a, t_lst **b, t_data *data);
void	sort_three(t_lst **a);
void	sort_five(t_lst **a, t_lst **b);

void	sorting(t_lst **stack_a, t_data *data)
{
	t_lst	*sorted;
	t_lst	*stack_b;

	if (!*stack_a || (*stack_a)->next == NULL)
		return ;
	sorted = (t_lst *)malloc(sizeof(t_lst));
	stack_b = (t_lst *)malloc(sizeof(t_lst));
	sorted = fill_stack(data);
	*stack_a = save_index(stack_a, sorted);
	free(sorted);
	stack_iter(*stack_a);
	if (data->number_count <= 5)
	{
		small_sort(stack_a, &stack_b, data);
	}
	else
		ft_putstr("big_sort \n");
	//sort_big(*stack_a, stack_b, data);
	stack_iter(*stack_a);
}

void	small_sort(t_lst **a, t_lst **b, t_data *data)
{
	if (data->number_count == 2)
		sa(a);
	else if (data->number_count == 3)
		sort_three(a);
	else
		sort_five(a, b);
	return ;
}

//void	sort_big(t_lst **a, t_lst **b, t_data *data)
//{
//
//}
//

void	sort_three(t_lst **a)
{
	if ((*a)->index == 1)
	{
		sa(a);
		ra(a);
	}
	else if ((*a)->index == 2)
	{
		if ((*a)->next->index == 1)
			sa(a);
		else
			rra(a);
	}
	else
	{
		if ((*a)->next->index == 1)
			ra(a);
		else
		{
			sa(a);
			rra(a);
		}
	}
}

void	sort_five(t_lst **a, t_lst **b)
{
	pb(a, b);
	pb(a, b);
	sort_three(a);
	while ((*b)->index > (*a)->index)
	{
		if ((*b)->index > (*a)->next->index)
		{
				pa(a, b);
				sa(a);
		}
	}

}
