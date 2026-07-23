/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoinsk <schoinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 17:33:32 by schoinsk          #+#    #+#             */
/*   Updated: 2026/07/23 15:03:30 by schoinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(const t_stack *a)
{
	int		mistakes;
	int		total_pairs;
	t_node	*curr;
	t_node	*next_node;

	if (!a || a->size < 2)
		return (0.0f);
	mistakes = 0;
	total_pairs = 0;
	curr = a->top;
	while (curr)
	{
		next_node = curr->next;
		while (next_node)
		{
			total_pairs++;
			if (curr->value > next_node->value)
				mistakes++;
			next_node = next_node->next;
		}
		curr = curr->next;
	}
	return ((float)mistakes / (float)total_pairs * 100.0f);
}
