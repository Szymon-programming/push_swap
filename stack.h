/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasiuda <jasiuda@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 12:01:33 by jasiuda           #+#    #+#             */
/*   Updated: 2026/07/20 11:13:09 by jasiuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

t_stack	*stack_new(void);
void	stack_push(t_stack *s, int value);
int		stack_pop(t_stack *s);
int		stack_size(const t_stack *s);
int		stack_is_empty(const t_stack *s);
int		stack_peek(const t_stack *s);
int		stack_is_sorted(const t_stack *s);
void	stack_clear(t_stack *s);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
