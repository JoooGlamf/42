/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <shjoo820@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 22:16:11 by soojoo            #+#    #+#             */
/*   Updated: 2022/09/02 04:22:02 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	check;

	check = 1;
	while (*str != '\0')
	{
		if (*str < 'A' || *str > 'Z')
		{
			check = 0;
			return (check);
		}
		str++;
	}
	return (check);
}
