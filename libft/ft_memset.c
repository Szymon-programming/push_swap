/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoinsk <schoinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 10:24:26 by schoinsk          #+#    #+#             */
/*   Updated: 2026/07/27 17:18:50 by schoinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*temporary;

	temporary = (unsigned char *)s;
	while (n > 0)
	{
		*temporary = (unsigned char)c;
		temporary++;
		n--;
	}
	return (s);
}
