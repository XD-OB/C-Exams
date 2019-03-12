/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 10:53:41 by ishaimou          #+#    #+#             */
/*   Updated: 2019/02/03 10:54:21 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	pgcd(int a, int b)
{
	int	pgcd;

	pgcd = (a < b) ? a : b;
	while (pgcd > 0 && (a % pgcd  != 0 || b % pgcd != 0))
			pgcd--;
	printf("%d", pgcd);
}

int		main(int argc, char *argv[])
{
	if (argc == 3)
		pgcd(atoi(argv[1]), atoi(argv[2]));
	printf("\n");
	return (0);
}
