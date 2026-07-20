/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoinsk <schoinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 12:01:33 by jasiuda           #+#    #+#             */
/*   Updated: 2026/07/20 17:17:20 by schoinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft/libft.h"
# include <limits.h>

typedef struct s_options
{
	int	simple;
	int	medium;
	int	complex;
	int	adaptive;
	int	bench;
}	t_options;

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
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

//funkcje parsera
int		init_and_check(int argc, char *argv[], t_options *options);
int		set_specific_flag(char *argv, t_options *options);
int		ft_strcmp(const char *s1, const char *s2);
int		is_flag(char *str);
int		check_flags(int argc, char *argv[], t_options *options);
int		*parser(int argc, char *argv[], int n);
int		*get_parsed_numbers(int argc, char *argv[], int i);
void	exit_error(void);
int		stack_operations_controller(int *numbers, int size, t_options options);

#endif