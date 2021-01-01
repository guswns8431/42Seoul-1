/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 22:10:20 by jinbekim          #+#    #+#             */
/*   Updated: 2021/01/01 22:18:36 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_strlen(char *s)
{
	int index;

	index = 0;
	while (s[index])
		index++;
	return (index);
}

char		*ft_strdup(char *s1)
{
	int		len;
	char	*c1;

	len = ft_strlen(s1);
	if (!(c1 = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	len = 0;
	while (s1[len])
	{
		c1[len] = s1[len];
		len++;
	}
	c1[len] = 0;
	return (c1);
}

int			has_newline(char *backup)
{
	int		i;

	i = 0;
	if (!backup)
		return (0);
	while (backup[i])
	{
		if (backup[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void		cut_with_newline(char **backup)
{
	int		i;

	i = 0;
	if (!backup)
		return ;
	while ((*backup)[i] != '\n')
		i++;
	(*backup)[i] = '\0';
	*backup = ft_strdup(&(*backup)[i + 1]);
}

char		*ft_strjoin_free(char *s1, char *s2)
{
	int		len1;
	int		len2;
	int		i;
	char	*arr;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(arr = malloc(len1 + len2 + 1)))
		return (0);
	while (s1[i])
	{
		arr[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		arr[len1 + i] = s2[i];
		i++;
	}
	arr[len1 + i] = 0;
	free(s1);
	return (arr);
}
