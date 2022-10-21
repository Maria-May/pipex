/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaryn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:31:02 by mdaryn            #+#    #+#             */
/*   Updated: 2021/10/19 18:31:06 by mdaryn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static unsigned int	ft_num_of_strs(char const *s, char c)
{
	unsigned int	i;
	unsigned int	num_strs;

	i = 0;
	num_strs = 0;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if ((s[i] != c && s[i] != '\0') && (s[i + 1] == c || s[i + 1] == '\0'))
			num_strs++;
		i++;
	}
	return (num_strs);
}

static char	**ft_clear(char **arr)
{
	unsigned int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static char	**ft_fill(char const *s, char c, unsigned int num_strs, char **arr)
{
	unsigned int		i;
	unsigned int		j;
	unsigned int		word_len;

	i = 0;
	j = 0;
	word_len = 0;
	while (i < num_strs)
	{
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j] != '\0')
		{
			word_len++;
			j++;
		}
		arr[i] = ft_substr(s, j - word_len, word_len);
		word_len = 0;
		if (!arr[i])
			ft_clear(arr);
		j++;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char				**arr;
	unsigned int		num_strs;

	if (!s)
		return (NULL);
	num_strs = ft_num_of_strs(s, c);
	arr = (char **)malloc(sizeof(char *) * (num_strs + 1));
	if (!arr)
		return (NULL);
	arr = ft_fill(s, c, num_strs, arr);
	return (arr);
}
