/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoinsk <schoinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 17:11:56 by jasiuda           #+#    #+#             */
/*   Updated: 2026/07/27 16:40:23 by schoinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_stack(t_stack *s)
{
	t_node	*current;
	t_node	*compered;

	current = s->top;
	while (current)
	{
		current->index = 0;
		compered = s->top;
		while (compered)
		{
			if (compered->value < current->value)
				current->index++;
			compered = compered->next;
		}
		current = current->next;
	}
}
