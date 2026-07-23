/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoinsk <schoinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 14:55:09 by schoinsk          #+#    #+#             */
/*   Updated: 2026/07/23 15:31:31 by schoinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Newton-Raphson
int	ft_sqrt(int number)
{
	long	x;
	long	next_x;

	if (number <= 0)
		return (0);
	x = number;
	next_x = (x + number / x) / 2;
	while (next_x < x)
	{
		x = next_x;
		next_x = (x + number / x) / 2;
	}
	return ((int)x);
}

void	bring_to_top_b(t_data *data, int position)
{
	int	stack_size;
	int	shifts;

	if (position <= 0)
		return;
	stack_size = data->b->size;
	if (position <= stack_size / 2)
	{
		shifts = position;
		while (shifts > 0)
		{
			do_operation(data, "rb");
			shifts--;
		}
	}
	else
	{
		shifts = stack_size - position;
		while (shifts > 0)
		{
			do_operation(data, "rrb");
			shifts--;
		}
	}
}
