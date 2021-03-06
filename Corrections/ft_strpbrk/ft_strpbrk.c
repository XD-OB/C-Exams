/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 10:05:42 by ishaimou          #+#    #+#             */
/*   Updated: 2019/02/03 10:06:04 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int		i;
	int		j;

	i = -1;	
	while (s1[++i]) {
		j = -1;
		while (s2[++j])
			if (s2[j] == s1[i])
				return ((char*)s1 + i);
	}
	return ((void*)0);
}
