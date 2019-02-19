/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moment.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 11:55:16 by ishaimou          #+#    #+#             */
/*   Updated: 2019/02/08 12:33:24 by ishaimou         ###   ########.fr       */
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

char	*ft_itoa(int nbr)
{
	char	*result;
	long	tmp;
	int		size;
	int		sign;

	sign = (nbr < 0) ? 1 : 0;
	size = sign ? 2 : 1;
	tmp = (nbr < 0) ? -(long)nbr : nbr;
	while (tmp /= 10)
		size++;
	if (!(result = (char*)malloc(sizeof(char) * (size + 1))))
			return (result);
	result[size] = '\0';
	if (sign)
		result[0] = '-';
	tmp = (nbr < 0) ? -(long)nbr : nbr;
	while (--size >= sign)
	{
		result[size] = (tmp % 10) + 48;
		tmp /= 10;
	}
	return (result);
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
