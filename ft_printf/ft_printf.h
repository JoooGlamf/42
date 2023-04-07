/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 22:28:28 by soojoo            #+#    #+#             */
/*   Updated: 2023/04/05 13:52:27 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<stdlib.h>
# include<unistd.h>
# include<stdarg.h>

int		ft_printf(const char *format, ...);
int		print_format(const char *format, va_list ap, int i);

int		print_char(char c);

int		print_str(char *str);

int		print_int(int num);
int		count_count(long long n);
char	*ft_itoa(int n);

int		print_int_unsigned(unsigned int num);
int		count_ucount(unsigned int n);
char	*ft_uitoa(unsigned int n);

int		print_hex(char xX, unsigned int num);
int		count_hex(unsigned int num);
char	*make_hex(char xX, unsigned int num);

int		print_pointer(void *pointer);
int		count_hex_pointer(int num);
char	*make_hex_pointer(char xX, int num);

int		print_percent(void);

#endif
