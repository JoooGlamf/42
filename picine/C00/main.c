/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:22:29 by sanghyun          #+#    #+#             */
/*   Updated: 2022/08/31 22:20:42 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./ex00/ft_putchar.c"
#include "./ex01/ft_print_alphabet.c"
#include "./ex02/ft_print_reverse_alphabet.c"
#include "./ex03/ft_print_numbers.c"
#include "./ex04/ft_is_negative.c"
#include "./ex05/ft_print_comb.c"
#include "./ex06/ft_print_comb2.c"
#include "./ex07/ft_putnbr.c"
#include "./ex08/ft_print_combn.c"

int main()
{
	printf("\n<0>\na\n");
   	ft_putchar('a');
	printf("\n<1>\nabcdefghijklmnopqrstuvwxyz\n");
	ft_print_alphabet();
	printf("\n<2>\nzyxwvutsrqponmlkjihgfedcba\n");
	ft_print_reverse_alphabet();
	printf("\n<3>\n0123456789\n");
	ft_print_numbers();
	printf("\n<4>\nNPNP\n");
	ft_is_negative(-1);
	ft_is_negative(0);
	ft_is_negative(-2147483648);
	ft_is_negative(3);
	printf("\n<5>\n");
	ft_print_comb();
	printf("\n<6>\n");
	ft_print_comb2();
	printf("\n<7>\n0-2147483648\n");
	ft_putnbr(0);
	ft_putnbr(-2147483648);
	printf("\n<8>\n");
	ft_print_combn(4);
	return 0;
}
