/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_c_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <shjoo820@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:12:56 by soojoo            #+#    #+#             */
/*   Updated: 2022/11/10 13:14:27 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	isalpha(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else if (c >= 'a' && <= 'z')
		return (2);
	else
		return (0);
}

int	isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	isalnum(int c)
{
	if (isalpha(c) || isdigit(c))
		return (1);
	else
		return (0);
}

int	isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

int	isprint(int c)
{
	if (isascii(c) && c >= '32' && c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
