/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:22:24 by soojoo            #+#    #+#             */
/*   Updated: 2022/08/30 15:16:23 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void);

void	ft_print_reverse_alphabet(void)
{
	char	r_alphabet;

	r_alphabet = 'z';
	while (r_alphabet >= 'a')
	{
		write(1, &r_alphabet, 1);
		r_alphabet--;
	}
}
