/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoinsk <schoinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 16:19:28 by schoinsk          #+#    #+#             */
/*   Updated: 2026/07/23 15:03:30 by schoinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_sort(t_data *data)
{
	if (data->disorder < 20.00)
		selection_sort_with_index(data);
	else if ((data->disorder >= 20.00) && (data->disorder < 50.00))
		chank_sort(data);
	else
		radix_sort(data);
}
