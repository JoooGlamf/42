/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <shjoo820@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 04:01:57 by soojoo            #+#    #+#             */
/*   Updated: 2022/09/02 04:21:31 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	check;

	check = 1;
	while (*str != '\0')
	{
		if (*str < 'a' || *str > 'z')
		{
			check = 0;
			return (check);
		}
		str++;
	}
	return (check);
}
