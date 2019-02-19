/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 10:30:44 by ishaimou          #+#    #+#             */
/*   Updated: 2019/02/03 10:31:44 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	fprime(int	nbr)
{
	int		i;

	i = 1;
	if (nbr == 1)
		printf("1");
	while (++i <= nbr)
	{
		if (nbr % i == 0)
		{
			nbr /= i;
			printf("%d", i);
			if (nbr > 1)
				printf("*");
			i--;
		}
	}
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
		fprime(atoi(argv[1]));
	printf("\n");	
	return (0);
}
