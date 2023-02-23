/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 02:51:46 by nbled             #+#    #+#             */
/*   Updated: 2022/09/04 02:51:50 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	t_pile	*start;
	t_pile	*tmp;
	char	**splited;
	char	*str;
	size_t	i;

	i = 0;
	while (1)
	{
		i = 1;
		str = readline(BLUE"minishell : "END);
		if (str[0] && quote_check(str) == 0)
		{
			splited = ft_split(str);
			start = ft_lstnew(0, splited[0]);
			while (i < ft_count_words(str))
			{
				tmp = ft_lstnew(i, splited[i]);
				ft_lstadd_back(&start, tmp);
				i++;
			}
			tmp = start;
			while (tmp->next)
			{
				printf("maillon "RED"%d = %s\n"END, tmp->value, tmp->str);
				tmp = tmp->next;
			}
			printf("maillon "RED"%d = %s\n"END, tmp->value, tmp->str);
			ft_lstclear(start);
		}
	}
}
