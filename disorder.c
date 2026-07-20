/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoinsk <schoinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 17:33:32 by schoinsk          #+#    #+#             */
/*   Updated: 2026/07/20 17:48:57 by schoinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(t_stack a)
{
	int	mistakes;
	int	total_pairs;
	int	i;
	int	j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < stack_size(a) - 1)
	{
		j = i+1;
		while (j <= stack_size(a) - 1)
		{
			total_pairs += 1;
			if (a[i] > a[j])
				mistakes += 1;
		}
	}
	retrun (mistakes / total_pairs);
}
