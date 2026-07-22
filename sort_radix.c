/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoinsk <schoinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 10:53:30 by jasiuda           #+#    #+#             */
/*   Updated: 2026/07/22 15:41:10 by schoinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int size)
{
	int	max_bits;

	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	return (max_bits);
}

//będzie prototyp t_data *data i będzie działał na do_operation(data, operation)
//przez to, że zakładamy zliczanie konkretnych operacji, na co wymyśliłem
//ten sposób, tak że zamiast np. pb będzie do_operation(data, "pb");
void	radix_sort(t_data *data)
{
	int	i;
	int	max_bits;
	int	bit;
	int	size;

	size = data->a->size;
	max_bits = get_max_bits(size);
	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if (((data->a->top->index >> bit) & 1) == 1)
				do_operation(data, "ra");
			else
				do_operation(data, "pb");
			i++;
		}
		while (data->b->size > 0)
			do_operation(data, "pa");
		bit++;
	}
}
