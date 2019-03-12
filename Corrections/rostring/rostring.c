/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 09:02:33 by ishaimou          #+#    #+#             */
/*   Updated: 2019/02/04 09:05:42 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_blank(char c)
{
	return (c == 32 || c == 9);
}

void	rostring(char *str)
{
	int		i;
	int		len;
	
	i = 0;
	len = 0;
	while (str[i])
	{
		while (is_blank(str[i]))
			i++;
		if (str[i])
		{
			if (!len)
				while(str[i] && !is_blank(str[i++]))
					len++;
			else
			{
				while (str[i] && !is_blank(str[i]))
					write(1, &str[i++], 1);
				write(1, " ", 1);
			}
		}
	}
	i = 0;
	while (is_blank(str[i]))
		i++;
	while (len--)
		write(1, &str[i++], 1);
}

int		main(int argc, char *argv[])
{
	if (argc > 1 && *argv[1])
		rostring(argv[1]);
	write(1, "\n", 1);
	return (0);
}
