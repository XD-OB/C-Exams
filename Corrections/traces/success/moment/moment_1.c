/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moment.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 11:55:16 by ishaimou          #+#    #+#             */
/*   Updated: 2019/02/03 11:57:30 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*dup;
	int		i;

	i = 0;	
	dup = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_itoa(int nbr)
{
	int		i;
	int		count;
	int		size;
	int		tmp;
	char	*tab;

	i = 0;
	size = 1;
	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	if (nbr < 0)
		size++;
	tmp = nbr >= 0 ? nbr : -nbr;
	while ((tmp = tmp / 10) > 0)
		size++;
	tab = (char*)malloc(sizeof(char) * (size + 1));
	tab[size] = '\0';
	if (nbr < 0)
	{
		nbr = -nbr;
		tab[i] = '-';
		i++;
	}
	tmp = nbr;
	count = 1;
	while ((tmp = tmp / 10) > 0)
		count *= 10;
	while (i < size && count >= 10)
	{
		tab[i] = (nbr / count) + 48;
		nbr %= count; 
		count /= 10;
		i++;
	}
	tab[i] = (nbr / count) + 48;
	return (tab);
}

char	*ft_strcpy(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char	*ft_strcat(char *s1, const char *s2)
{
	int		i;
	int		j;

	i = 0;
	while (s1[i] != '\0')
		i++;
	j = 0;
	while (s2[j] != '\0')
	{
		s1[i + j] = s2[j];
		j++;
	}
	s1[i + j] = '\0';
	return (s1);
}

char	*ft_duration(unsigned int duration, char *msg, char *msg_s)
{
	char	*ret;
	char	*moment;

	ret = ft_itoa(duration);
	moment = (char*)malloc(sizeof(char) * (ft_strlen(ret) + 14));
	ft_strcpy(moment, ret);
	(duration == 1) ? ft_strcat(moment, msg) : ft_strcat(moment, msg_s);
	free(ret);
	return (moment);
}

char    *moment(unsigned int duration)
{
	char	*moment;

	if (duration < 60)
		moment = ft_duration(duration, " second ago.", " seconds ago.");

	else if (duration < 60 * 60 && duration >= 60)
	{
		duration /= 60;
		moment = ft_duration(duration, " minute ago.", " minutes ago.");
	}

	else if (duration < (60 * 60 * 24) && duration >= 60 * 60)
	{
		duration /= (60 * 60);
		moment = ft_duration(duration, " hour ago.", " hours ago.");
	}

	else if (duration < (60 * 60 * 24 * 30) && duration >= (60 * 60 * 24))
	{
		duration /= (60 * 60 * 24);
		moment = ft_duration(duration, " day ago.", " days ago.");
	}

	else
	{
		duration /= (60 * 60 * 24 * 30);
		moment = ft_duration(duration, " month ago.", " months ago.");
	}
	return (moment);
}
