/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 01:35:00 by nbled             #+#    #+#             */
/*   Updated: 2022/09/20 01:35:16 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_pile	*ft_lstnew(int value, char *str)
{
	t_pile	*n;

	n = malloc(sizeof(t_pile));
	if (!n)
		return (NULL);
	n->value = value;
	n->str = str;
	n->prev = NULL;
	n->next = NULL;
	return (n);
}
