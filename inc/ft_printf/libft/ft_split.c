/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrainyk <mkrainyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:25:40 by mkrainyk          #+#    #+#             */
/*   Updated: 2025/02/04 14:46:32 by mkrainyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static int	ft_count(const char *s, char c);
// static char	*ft_fill_word(const char *s, int start, int end);
// static void	*ft_free(char **res, int count);
// static void	ft_initiate_vars(size_t *i, int *j, int *s_word);

// char	**ft_split(char const *s, char c)
// {
// 	char	**res;
// 	size_t	i;
// 	int		j;
// 	int		s_word;

// 	ft_initiate_vars(&i, &j, &s_word);
// 	res = ft_calloc(ft_count(s, c) + 1, sizeof(char *));
// 	if (!res)
// 		return (NULL);
// 	while (i <= ft_strlen(s))
// 	{
// 		if (s[i] != c && s_word < 0)
// 			s_word = i;
// 		else if ((s[i] == c || i == ft_strlen(s)) && s_word >= 0)
// 		{
// 			res[j] = ft_fill_word(s, s_word, i);
// 			if (!(res[j]))
// 				return (ft_free(res, j));
// 			s_word = -1;
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (res);
// }

// static void	ft_initiate_vars(size_t *i, int *j, int *s_word)
// {
// 	*i = 0;
// 	*j = 0;
// 	*s_word = -1;
// }

// static char	*ft_fill_word(const char *s, int start, int end)
// {
// 	char	*word;
// 	int		i;

// 	i = 0;
// 	word = malloc((end - start + 1) * sizeof(char));
// 	if (!word)
// 		return (NULL);
// 	while (start < end)
// 	{
// 		word[i] = s[start];
// 		i++;
// 		start++;
// 	}
// 	word[i] = '\0';
// 	return (word);
// }

// static void	*ft_free(char **res, int count)
// {
// 	int	i;

// 	i = 0;
// 	while (i < count)
// 	{
// 		free(res[i]);
// 		i++;
// 	}
// 	free(res);
// 	return (NULL);
// }

// static int	ft_count(const char *s, char c)
// {
// 	int	count;
// 	int	in_word;

// 	count = 0;
// 	in_word = 0;
// 	while (*s)
// 	{
// 		if (*s != c && !in_word)
// 		{
// 			in_word = 1;
// 			count++;
// 		}
// 		else if (*s == c)
// 			in_word = 0;
// 		s++;
// 	}
// 	return (count);
// }

static int    count_words(const char *str, char c)
{
    int    amount;
    int    flag;

    amount = 0;
    flag = 0;
    while (*str)
    {
        if (*str != c && flag == 0)
        {
            flag = 1;
            amount++;
        }
        else if (*str == c)
            flag = 0;
        str++;
    }
    return (amount);
}

static char    *check_word(const char *str, int start, int finish)
{
    char    *word;
    int        i;

    i = 0;
    word = malloc((finish - start + 1) * sizeof(char));
    while (start < finish)
        word[i++] = str[start++];
    word[i] = '\0';
    return (word);
}

char    **ft_split(char const *s, char c)
{
    size_t    i_str;
    size_t    i_arr;
    int        i_start_word;
    char    **res;

    res = malloc((count_words(s, c) + 1) * sizeof(char *));
    if (!s || !res)
        return (0);
    i_str = 0;
    i_arr = 0;
    i_start_word = -1;
    while (i_str <= ft_strlen(s))
    {
        if (s[i_str] != c && i_start_word < 0)
            i_start_word = i_str;
        else if ((s[i_str] == c || i_str == ft_strlen(s)) && i_start_word >= 0)
        {
            res[i_arr++] = check_word(s, i_start_word, i_str);
            i_start_word = -1;
        }
        i_str++;
    }
    res[i_arr] = 0;
    return (res);
}