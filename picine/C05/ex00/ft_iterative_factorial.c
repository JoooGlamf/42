/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <shjoo820@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:44:18 by soojoo            #+#    #+#             */
/*   Updated: 2022/09/11 14:45:51 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	facto;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	facto = 1;
	while (nb)
	{
		facto = facto * nb;
		nb--;
	}
	return (facto);
}
