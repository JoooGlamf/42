/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <shjoo820@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 20:35:38 by soojoo            #+#    #+#             */
/*   Updated: 2022/09/07 16:45:36 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	m_m_h(unsigned char *addr_char, unsigned char *address);
void	m_v_h(unsigned char *addr_char, unsigned char *values);
void	p_v(void *a, unsigned char *a_c, unsigned char *v, unsigned int s);
void	p_c(void *a, unsigned char *a_c, unsigned int s);

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	address[16];
	unsigned char	values[32];
	unsigned char	*addr_char;

	addr_char = (unsigned char *)addr;
	while (addr_char < (unsigned char *)addr + size)
	{
		m_m_h(addr_char, address);
		m_v_h(addr_char, values);
		p_v(addr, addr_char, values, size);
		p_c(addr, addr_char, size);
		write(1, "\n", 1);
		addr_char += 16;
	}
	return (addr);
}

void	m_m_h(unsigned char *addr_char, unsigned char *address)
{
	unsigned long long	addr_int;
	int					mod;
	unsigned int		i;

	addr_int = (unsigned long long)addr_char;
	i = 0;
	while (i < 16)
	{
		mod = addr_int % 16;
		if (mod < 10)
			address[15 - i] = '0' + mod;
		else
			address[15 - i] = 'a' + mod - 10;
		i++;
		addr_int /= 16;
	}
	write(1, address, 16);
	write(1, ": ", 2);
}

void	m_v_h(unsigned char *a_c, unsigned char *v)
{
	int	i;
	int	mod;

	i = 0;
	while (i < 16)
	{
		mod = a_c[i] / 16;
		if (mod < 10)
			v[i * 2] = mod + '0';
		else
			v[i * 2] = mod + 'a' - 10;
		mod = a_c[i] % 16;
		if (mod < 10)
			v[i * 2 + 1] = mod + '0';
		else
			v[i * 2 + 1] = mod + 'a' - 10;
		i++;
	}
}

void	p_v(void *a, unsigned char *a_c, unsigned char *v, unsigned int s)
{
	int	i;

	i = -1;
	if ((unsigned char *)a + s - a_c >= 16)
	{
		while (++i < 32)
		{
			write(1, v + i, 1);
			if (i % 4 == 3)
				write(1, " ", 1);
		}
	}
	while (++i < ((unsigned char *)a + s - a_c) % 16 * 2)
	{
		write(1, v + i, 1);
		if (i % 4 == 3)
			write(1, " ", 1);
	}
	while (++i - 1 < 32)
	{
		write(1, " ", 1);
		if (i % 4 == 3)
			write(1, " ", 1);
	}
}

void	p_c(void *a, unsigned char *a_c, unsigned int s)
{
	unsigned int	i;

	i = 0;
	while (i < 16 && a_c + i < (unsigned char *)a + s)
	{
		if (a_c[i] >= 32 && a_c[i] <= 126)
			write(1, a_c + i, 1);
		else
			write(1, ".", 1);
		i++;
	}
}
