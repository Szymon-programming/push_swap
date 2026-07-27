/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoinsk <schoinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 10:30:48 by jasiuda           #+#    #+#             */
/*   Updated: 2026/07/27 12:49:44 by schoinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack || !*stack)
		return ;
	current = (*stack)->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(*stack);
	*stack = NULL;
}

void	free_data(t_data *data, int **numbers)
{
	if (numbers && *numbers)
	{
		free(*numbers);
		*numbers = NULL;
	}
	if (!data)
		return ;
	free_stack(&data->a);
	free_stack(&data->b);
	ft_bzero(data, sizeof(t_data));
}

// void error_and_free(t_data *data, int **numbers, t_stack **stack)
// {

// }
