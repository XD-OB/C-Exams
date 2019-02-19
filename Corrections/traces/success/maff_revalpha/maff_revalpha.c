/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maff_revalpha.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 08:02:20 by ishaimou          #+#    #+#             */
/*   Updated: 2019/02/05 08:05:17 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

int		main(void)
{
	//write(1, "zYxWvUtSrQpOnMlKjIhGfEdCbA\n", 27);
	
	int		c;

	c = 'z';
	while (c >= 'a')
	{
		(c % 2 == 0) ? ft_putchar(c) : ft_putchar(c - 32);
		c--;
	}
	ft_putchar('\n');
	return (0);
}
