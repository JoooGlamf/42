/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 20:15:29 by sanghyun          #+#    #+#             */
/*   Updated: 2022/08/31 23:41:29 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./ex00/ft_ft.c"
#include "./ex01/ft_ultimate_ft.c"
#include "./ex02/ft_swap.c"
#include "./ex03/ft_div_mod.c"
#include "./ex04/ft_ultimate_div_mod.c"
#include "./ex05/ft_putstr.c"
#include "./ex06/ft_strlen.c"
#include "./ex07/ft_rev_int_tab.c"
#include "./ex08/ft_sort_int_tab.c"

int main()
{	
	int *nbr;
	int *********nbr2;
	int *num1, *num2;
	
	int a=37, b=5, c=24, d=42, e, f, n, m;
	int *div, *mod;
	int tab[5]={1,2,3,4,5};
	int array[10] = {1, 5, 2, 3, 7, 6, 4, 10, 9, 8};
	char str[15] = "Hello World!";
	int *p1 = &f;
	int **p2 = &p1;
	int ***p3 = &p2;
	int ****p4 = &p3;
	int *****p5 = &p4;
	int ******p6 = &p5;
	int *******p7 = &p6;
	int ********p8 = &p7;
	int result;

	div = &m;
	mod = &n;
	nbr2 = &p8;
	num1 = &c;
	num2 = &d;
	nbr = &e;
	printf("\n<0>\n");
	ft_ft(nbr);
	printf("42\n%d", *nbr);
	printf("\n<1>\n");
	ft_ultimate_ft(nbr2);
	printf("42\n%d", *********nbr2);
	printf("\n<2>\n");
	ft_swap(num1, num2);
	printf("42, 24\n");
	printf("%d, %d", *num1, *num2);
	
	printf("\n<3>\n");
	printf("7, 2\n");
	ft_div_mod(a, b, div, mod);
	printf("%d, %d", *div, *mod);
	a=6;
	b=0;
	*div=0;
	*mod=0;
	printf("\n0, 0\n");
    ft_div_mod(a, b, div, mod);
    printf("%d, %d", *div, *mod);
	printf("\n<4>\n");
	*div=7;
	*mod=2;
	printf("3, 1\n");
	ft_ultimate_div_mod(div, mod);
	printf("%d, %d\n", *div, *mod);
	a=6;
    b=0;
    *div=0;
    *mod=0;
	printf("0, 0\n");
    ft_ultimate_div_mod(div, mod);
    printf("%d, %d", *div, *mod);
	
	printf("\n<5>\n");
	printf("Hello World!\n");
	ft_putstr(str);
	printf("\n<6>\n");
	result = ft_strlen(str);
	printf("12\n");
	printf("%d", result);
	printf("\n<7>\n");
	ft_rev_int_tab(tab, 5);
	printf("5 4 3 2 1\n");
	for(int i = 0 ; i < 5; i++)
	{
		printf("%d ", tab[i]);
	}
	printf("\n<8>\n");
	printf("1 2 3 4 5 6 7 8 9 10\n");
	ft_sort_int_tab(array, 10);
	for(int i = 0 ; i < 10; i++)
	{
		printf("%d ", array[i]);
	}
	return 0;
}
