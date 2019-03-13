/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <obelouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 03:16:25 by obelouch          #+#    #+#             */
/*   Updated: 2019/01/29 03:17:06 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putchar(char c)
{
        write(1, &c, 1);
}

void    print_tab(int *tab)
{
        int     i;

        i = 0;
        while (i < 32)
        {
                ft_putchar(tab[i] + '0');
                i++;
                if (i % 8 == 0)
                        ft_putchar(' ');
        }
        ft_putchar('\n');
}

int     main(int ac, char **av)
{
        int     i;
        int     j;
        int     bits[32] = {0};

        if (ac == 1)
        {
                write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
                return (0);
        }
        i = 1;
        while (av[i])
        {
                if (av[i][0] == '-')
                {
                        j = 1;
                        while (av[i][j] && av[i][j] >= 'a' && av[i][j] <= 'z')
                        {
                                if (av[i][j] == 'h')
                                {
                                        write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
                                        return (0);
                                }
                                bits[6 + 'z' - av[i][j]] = 1;
                                j++;
                        }
                        if (av[i][j])
                        {
                                write(1, "Invalid Option\n", 15);
                                return (0);
                        }
                }
                i++;
        }
        print_tab(bits);
        return (0);
}
