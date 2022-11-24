/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <shjoo820@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 21:48:50 by soojoo            #+#    #+#             */
/*   Updated: 2022/09/11 15:29:24 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	nb_powered;

	if (power < 0)
		return (0);
	if (nb == 0 && power == 0)
		return (1);
	nb_powered = 1;
	while (power)
	{
		nb_powered *= nb;
		power--;
	}
	return (nb_powered);
}
