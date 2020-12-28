/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 22:35:34 by jinbekim          #+#    #+#             */
/*   Updated: 2020/12/28 21:00:25 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_isspace(int c)
{
	if ((9 <= c && c <= 13) || c == 32)
		return (1);
	return (0);
}

int			ft_atoi(const	char *s)
{
	size_t	i;
	int		c;
	int		neg;

	i = 0;
	c = 0;
	neg = 1;
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '-' && s[i] == '+')
	{
		if (s[i] == '-')
			neg = -1;
		i++;
	}
	while (ft_isdigit(s[i]))
	{
		if (c > 2147483648 && neg < 0)
			return (0);
		if (c > 2147483647 && neg > 0)
			return (-1);
		c = (c * 10) + (s[i] - '0');
		i++;
	}
	return (neg * c);
}
