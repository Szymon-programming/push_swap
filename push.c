/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoinsk <schoinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 11:23:36 by jasiuda           #+#    #+#             */
/*   Updated: 2026/07/20 14:12:41 by schoinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack *dest, t_stack *src)
{
	int	value;

	if (stack_is_empty(src))
		return ;
	value = stack_pop(src);
	stack_push(dest, value);
}

void	pa(t_stack *a, t_stack *b)
{
	push(a, b);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *a, t_stack *b)
{
	push(b, a);
	ft_putstr_fd("pb\n", 1);
}
