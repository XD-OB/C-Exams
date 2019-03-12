/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 09:16:49 by ishaimou          #+#    #+#             */
/*   Updated: 2019/02/03 09:17:36 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_itoa_base(int value, int base);

int		main(int ac, char **av)
{
	char	*res;

	if (ac == 3)
	{
		res = ft_itoa_base(atoi(av[1]), atoi(av[2]));
		printf("%s\n", res);
	}
	return (0);
}
