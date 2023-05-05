/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manumart <manumart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:38:27 by manumart          #+#    #+#             */
/*   Updated: 2023/05/05 20:40:40 by manumart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *x)
{
	int	i;

	i = 0;
	if (!x)
		return (0);
	while (x[i] && x[i] != '\n')
		i++;
	if (x[i] == '\n')
		i++;
	return (i);
}

int	ft_clear(char *str)
{
	int	i;
	int	j;
	int	nl_true;

	i = 0;
	j = 0;
	nl_true = 0;
	while (str[i])
	{
		if (nl_true)
			str[j++] = str[i];
		if (str[i] == '\n')
			nl_true = 1;
		str[i++] = '\0';
	}
	return (nl_true);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*prt;

	i = 0;
	j = 0;
	prt = malloc(ft_strlen(s1)+ ft_strlen(s2) + 1);
	if (!prt)
		return (NULL);
	while (s1 && s1[i])
	{
		prt[i] = s1[i];
		i++;
	}
	free(s1);
	while (s2[j])
	{
		prt[i++] = s2[j];
		if (s2[j++] == '\n')
			break ;
	}
	prt[i] = '\0';
	return (prt);
}
