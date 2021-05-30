/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   examine_sort_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 18:07:28 by jinbekim          #+#    #+#             */
/*   Updated: 2021/05/30 20:24:16 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	examine_sort(t_list *astack)
{
	int	count;

	count = 1;
	if (!astack)
		return (0);
	while (astack->next)
	{
		if (astack->rank + 1 != astack->next->rank)
			break ;
		astack = astack->next;
		count++;
	}
	return (count);
}
