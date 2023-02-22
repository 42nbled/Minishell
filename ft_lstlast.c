/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 02:51:46 by nbled             #+#    #+#             */
/*   Updated: 2022/09/04 02:51:50 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_pile	*ft_lstlast(t_pile *pile)
{
	if (pile)
		while (pile->next)
			pile = pile->next;
	return (pile);
}
