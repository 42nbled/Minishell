/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 02:50:07 by frgojard          #+#    #+#             */
/*   Updated: 2023/01/04 18:59:42 by frgojard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	isasep(const char c)
{
	if (c == 39)
		return (1);
	if (c == 34)
		return (1);
	if (c == '<')
		return (1);
	if (c == '>')
		return (1);
	if (c == '|')
		return (1);
	return (0);
}

size_t	ft_count_words(const char *s)
{
	size_t	words;
	int		quote;
	int		i;

	i = 0;
	quote = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] && s[i] == ' ')
			i++;
		if (s[i] && s[i] != ' ')
		{
			words++;
			if (s[i] == 39)
			{
				i++;
				while (s[i] && s[i] != 39)
					i++;
				i++;
			}
			else if (s[i] == 34)
			{
				i++;
				while (s[i] && s[i] != 34)
					i++;
				i++;
			}
			else if (isasep(s[i]))
			{
				i++;
				if (s[i] && s[i - 1] && s[i] == '<' && s[i - 1] == '<')
					i++;
				if (s[i] && s[i - 1] && s[i] == '>' && s[i - 1] == '>')
					i++;
			}
			else
				while (s[i] && s[i] != ' ' && !isasep(s[i]))
					i++;
		}
	}
	return (words);
}

size_t	ft_str_len(char const *s)
{
	int	i;

	i = 0;
	if (s[i] == 39)
	{
		i++;
		while(s[i] && s[i] != 39)
			i++;
		i++;
	}
	else if (s[i] == 34)
	{
		i++;
		while(s[i] && s[i] != 34)
			i++;
		i++;
	}
	else if (isasep(s[i]))
	{
		i++;
		if (s[i] && s[i - 1] && s[i] == '<' && s[i - 1] == '<')
			i++;
		if (s[i] && s[i - 1] && s[i] == '>' && s[i - 1] == '>')
			i++;
	}
	else
		while (s[i] && s[i] != ' ' && !isasep(s[i]))
			i++;
	return (i);
}

char	**ft_split(const char *s)
{
	char	**tab;
	int		size;
	size_t	i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	size = ft_count_words(s);
	tab = malloc(sizeof(char *) * (size + 1));
	if (!tab)
		return (NULL);
	while (i < ft_count_words(s))
	{
		while (s[j] && s[j] == ' ')
			j++;
		tab[i] = malloc(ft_str_len(s + j) + 1);
		k = 0;

		if (s[j] == 39)
		{
			j++;
			while (s[j] && s[j] != 39)
				tab[i][k++] = s[j++];
			j++;
		}
		else if (s[j] == 34)
		{
			j++;
			while (s[j] && s[j] != 34)
				tab[i][k++] = s[j++];
			j++;
		}
		else if (isasep(s[j]))
		{
			tab[i][k++] = s[j++];
			if (s[j] && s[j - 1] && s[j] == '<' && s[j - 1] == '<')
				tab[i][k++] = s[j++];
			if (s[j] && s[j - 1] && s[j] == '>' && s[j - 1] == '>')
				tab[i][k++] = s[j++];
		}
		else
			while (s[j] && s[j] != ' ' && !isasep(s[j]))
				tab[i][k++] = s[j++];
		tab[i][k] = '\0';
		i++;
	}
	tab[i] = NULL;
	return (tab);
}