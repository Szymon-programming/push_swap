/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   force_sorting_method.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoinsk <schoinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 09:51:27 by schoinsk          #+#    #+#             */
/*   Updated: 2026/07/28 10:09:35 by schoinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_force_easy(t_data *data)
{
	t_node	*current;
	t_node	*bottom;

	current = data->a->top;
	bottom = data->a->bottom;
	if ((current->value > current->next->value) 
		&& (current->value > bottom->value))
	{	
		do_operation(data, "ra");
		current = data->a->top;
		if (current->value > current->next->value)
			do_operation(data, "sa");
	}
	else if ((current->value < current->next->value) 
		&& (current->next->value > bottom->value))
	{
		do_operation(data, "rra");
		current = data->a->top;
		if (current->value > current->next->value)
			do_operation(data, "sa");
	}
	else
		do_operation(data, "sa");
}
