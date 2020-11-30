/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:07:46 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/30 13:07:46 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strlen (const char* str);

void ft_strlen_test()
{
	printf("-------------------- FT_STRLEN --------------------\n");
	printf("1. Long string:\n");
	printf("My ft_strlen: %d\n", ft_strlen("ffffffjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfj"));
	printf("Real strlen: %lu\n", strlen("ffffffjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfj"));
	printf("\n");

	printf("2. Short string:\n");
	printf("My ft_strlen: %d\n", ft_strlen("f"));
	printf("Real strlen: %lu\n", strlen("f"));
	printf("\n");

	printf("2. Empty string:\n");
	printf("My ft_strlen: %d\n", ft_strlen(""));
	printf("Real strlen: %lu\n", strlen(""));
	printf("\n");

}

int main()
{
	ft_strlen_test();
}