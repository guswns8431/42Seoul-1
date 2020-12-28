/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 20:04:12 by jinbekim          #+#    #+#             */
/*   Updated: 2020/12/28 20:04:24 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}
