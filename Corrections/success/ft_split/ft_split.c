/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 09:04:09 by ishaimou          #+#    #+#             */
/*   Updated: 2019/02/03 09:04:47 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_blank(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

int		wcount(char *str)
{
	int		i;
	int		count;
	int		flag;

	i = 0;
	count = 0;
	flag = 0;
	while (str[i])
	{
		if (!is_blank(str[i]) && flag == 0)
		{
			count++;
			flag = 1;
		}
		if (is_blank(str[i]) && flag == 1)
			flag = 0;
		i++;
	}
	return (count);
}

void	wposition(char *str, int *p)
{
	while (str[*p])
	{
		if (!is_blank(str[*p]))
			return ;
		(*p)++;
	}
}

int		wsize(char *str, int p)
{
	int		i;
	
	i = p;
	while (str[i] && !is_blank(str[i]))
		i++;
	return (i - p);
}

char	**ft_split(char *str)
{
	char	**tab;
	int		p;
	int		i;
	int		j;
	int		nb;
	int		size;

	i = 0;
	p = 0;
	nb = wcount(str);
	tab = (char**)malloc(sizeof(char*) * (nb + 1));
	tab[nb] = NULL;
	while (i < nb)
	{
		j = 0;
		wposition(str, &p);
		size = wsize(str, p);
		tab[i] = (char*)malloc(sizeof(char) * (size + 1));
		while (j < size)
			tab[i][j++] = str[p++];
		tab[i][j] = '\0';
		i++;
	}
	return (tab);
}
