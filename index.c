/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoinsk <schoinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 17:11:56 by jasiuda           #+#    #+#             */
/*   Updated: 2026/07/23 15:31:31 by schoinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void sort(int *arr, int len)
{
	int i;
	int j;
	int temp;

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

void index_stack(t_data *data)
{
	int *arr;
	t_node *current;
	int i;
	int j;

	arr = malloc(sizeof(int) * data->a->size);
	if (!arr)
		return;
	current = data->a->top;
	i = 0;
	while (current && (i < data->a->size))
	{
		arr[i] = current->value;
		i++;
		current = current->next;
	}
	sort(arr, data->a->size);
	current = data->a->top;
	while (current)
	{
		j = 0;
		while (j < data->a->size)
		{
			if (arr[j] == current->value)
			{
				current->index = j;
				break;
			}
			j++;
		}
		current = current->next;
	}
	free(arr);
}
