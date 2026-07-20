/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasiuda <jasiuda@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 17:11:56 by jasiuda           #+#    #+#             */
/*   Updated: 2026/07/20 18:58:27 by jasiuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(int *arr, int len)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[j] < arr[i])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	index_stack(t_stack *s)
{
	int		*arr;
	t_node	*current;
	int		i;
	int		j;

	arr = malloc(sizeof(int) * s->size);
	if (!arr)
		return ;
	current = s->top;
	i = 0;
	while (current)
	{
		arr[i] = current->value;
		i++;
		current = current->next;
	}
	sort(arr, s->size);
	current = s->top;
	while (current)
	{
		j = 0;
		while (j < s->size)
		{
			if (arr[j] == current->value)
			{
				current->index = j;
				break ;
			}
			j++;
		}
		current = current->next;
	}
	free(arr);
}
