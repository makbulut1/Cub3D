/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:23:56 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/27 20:15:30 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	wordsize(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s != 0)
	{
		if (*s == c)
			s++;
		else
		{
			i++;
			while (*s != '\0' && *s != c)
				s++;
		}	
	}
	return (i);
}

static char	**ft_free(char **s, size_t index)
{
	while (s[index] != 0 && index >= 0)
	{
		free(s[index]);
		s[index] = NULL;
		index--;
	}
	free(s);
	s = NULL;
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**word;
	size_t	index;
	size_t	size;

	word = (char **)malloc(sizeof(char *) * (wordsize(s, c) + 1));
	if (!word || !s)
		return (NULL);
	index = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			size = 0;
			while (*(s + size) && *(s + size) != c)
			size++;
			word[index++] = ft_substr(s, 0, size);
			if (index < wordsize(s, c) && !(word))
				return (ft_free(word, index));
			s += size;
		}
	}
	word[index] = 0;
	return (word);
}

/*
int main()
{
    char str[100] = "elma,armut,karpuz";
    char **p = ft_split(str, ',');
    printf("%s\n", p[0]);
}
*/