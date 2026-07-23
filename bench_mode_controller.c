/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_mode_controller.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoinsk <schoinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 14:38:20 by schoinsk          #+#    #+#             */
/*   Updated: 2026/07/23 15:03:30 by schoinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_putfloat(float disorder)
{
	int	int_part;
	int	dec_part;

	if (disorder < 0)
	{
		ft_putchar_fd('-', 2);
		disorder = -disorder;
	}
	disorder += 0.005f;
	int_part = (int)disorder;
	dec_part = (int)((disorder - int_part) * 100);
	ft_putnbr_fd(int_part, 2);
	ft_putchar_fd('.', 2);
	if (dec_part < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(dec_part, 2);
}

static void	print_continue(t_data *data)
{
	ft_putstr_fd("\n[bench] sa: ", 2);
	ft_putnbr_fd(data->bench.sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(data->bench.sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(data->bench.ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(data->bench.pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(data->bench.pb, 2);
	ft_putstr_fd("\n[bench] ra: ", 2);
	ft_putnbr_fd(data->bench.ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(data->bench.rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(data->bench.rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(data->bench.rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(data->bench.rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(data->bench.rrr, 2);
	ft_putstr_fd("\n", 2);
}

void	print_bench(t_data *data, t_options *options)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putfloat(data->disorder);
	ft_putstr_fd("%\n", 2);
	ft_putstr_fd("[bench] strategy: ", 2);
	if (options->simple == 1)
		ft_putstr_fd("Simple / O(n2)\n", 2);
	else if (options->medium == 1)
		ft_putstr_fd("Medium / O(n√n)\n", 2);
	else if (options->complex == 1)
		ft_putstr_fd("Complex / O(n log n)\n", 2);
	else
	{
		ft_putstr_fd("Adaptive / ", 2);
		if (data->disorder < 20.00)
			ft_putstr_fd("O(n2)\n", 2);
		else if ((data->disorder >= 20.00) && (data->disorder < 50.00))
			ft_putstr_fd("O(n√n)\n", 2);
		else
			ft_putstr_fd("O(n log n)\n", 2);
	}
	ft_putstr_fd("[bench] total ops: ", 2);
	ft_putnbr_fd(data->bench.total_operations, 2);
	print_continue(data);
}
