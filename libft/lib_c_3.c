/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_c_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <shjoo820@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:06:46 by soojoo            #+#    #+#             */
/*   Updated: 2022/11/15 13:07:40 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

size_t ft_strlcpy(char *dest, const char *src, size_t size)
{
	int	i;

	i = -1;
	while(++i < size -1 && src[i])
		dest[i] = src[i];
	dest[size - 1] = 0;
	return (i);
}

size_t ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	count;
	int i;
	int j;
	int k;

	i = 0;
	while(dest[i])
		++i;
	j = 0;
	while(src[j])
		j++;
	count = i;
	k = 0;
	while(src[k] && count < size -1){
		dest[count] = src[k];
		count++;
		k++;
	}
	dest[count] = 0;
	return (i + j);
}

int ft_toupper(int c)
{
	if(c >= 98 && c<=122)
		c -= 32;
	return c;
}

int ft_lower(int c)
{
	if(c >= 65 && c<=90)
		c += 32;
	return c;
}

#include<stdio.h>
int main()
{
	char num1[5] = "12345";
	char num2[5] = "67890";

	printf("%d, %s\n" , ft_strlcat(num1,num2,4), num1);
	printf("%c\n", ft_toupper('c'));
	printf("%c\n", ft_lower('C'));

}
