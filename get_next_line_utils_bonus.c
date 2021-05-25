/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:56:12 by seuan             #+#    #+#             */
/*   Updated: 2021/05/25 16:25:28 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t		ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;
	size_t	j;

	i = 0;
	while (dest[i] != '\0' && i < size)
		i++;
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	j = 0;
	while (src[j] != '\0' && (i + j + 1) < size)
	{
		dest[i + j] = src[j];
		j++;
	}
	if (i < size)
		dest[i + j] = '\0';
	return (i + src_len);
}

char		*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	size;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if ((s1 == NULL) || (s2 == NULL))
		return (!(s1) ? ft_strdup(s2) : ft_strdup(s1));
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char *)malloc(size + 1)))
		return (NULL);
	str[0] = '\0';
	ft_strlcat(str, s1, ft_strlen(s1) + 1);
	free(s1);
	ft_strlcat(str, s2, ft_strlen(str) + ft_strlen(s2) + 1);
	return (str);
}

char		*ft_strdup(char *src)
{
	int		len;
	int		i;
	char	*tmp;

	len = ft_strlen(src);
	if (!(tmp = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		tmp[i] = src[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

int			ft_strchr(char *s, int c)
{
	int		i;

	if (s == NULL)
		return (-1);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
