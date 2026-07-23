/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_check_continue.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoinsk <schoinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 14:01:50 by schoinsk          #+#    #+#             */
/*   Updated: 2026/07/23 15:31:31 by schoinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// aktywuje konkretną flagę w strukturze - wywoływane przez set_specific_flag
static void	activate_flag(int index, t_options *options)
{
	if (index == 0)
		options->simple = 1;
	else if (index == 1)
		options->medium = 1;
	else if (index == 2)
		options->complex = 1;
	else if (index == 3)
		options->adaptive = 1;
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*string1;
	unsigned char	*string2;

	i = 0;
	string1 = (unsigned char *)s1;
	string2 = (unsigned char *)s2;
	while (string1[i] != '\0' || string2[i] != '\0')
	{
		if (string1[i] == string2[i])
			i++;
		else
			return ((int)(string1[i] - string2[i]));
	}
	return (0);
}

// ustawia konkretną flagę w strukturze options na 1(odpowiednik true bo nie ma bool)
int	set_specific_flag(char *argv, t_options *options)
{
	char	*flags[4];
	int		i;

	flags[0] = "--simple";
	flags[1] = "--medium";
	flags[2] = "--complex";
	flags[3] = "--adaptive";
	if (ft_strcmp(argv, "--bench") == 0)
		return (options->bench = 1, 0);
	i = -1;
	while (++i < 4)
	{
		if (ft_strcmp(argv, flags[i]) == 0)
		{
			if (options->simple || options->medium || options->complex || options->adaptive)
				return (-1);
			activate_flag(i, options);
			return (0);
		}
	}
	return (-1);
}
