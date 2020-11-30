/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:07:46 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/30 16:16:48 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

size_t ft_strlen (const char* str);
char *ft_strcpy(char *dst, char const *src);
int		ft_strcmp(char const *s1, char const *s2);

void ft_strlen_test()
{
	printf("-------------------- FT_STRLEN --------------------\n");
	printf("1. Long string:\n");
	printf("My ft_strlen: %zu\n", ft_strlen("ffffffjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfj"));
	printf("Real strlen: %lu\n", strlen("ffffffjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfjfj"));
	printf("\n");

	printf("2. Short string:\n");
	printf("My ft_strlen: %zu\n", ft_strlen("f"));
	printf("Real strlen: %lu\n", strlen("f"));
	printf("\n");

	printf("2. Empty string:\n");
	printf("My ft_strlen: %zu\n", ft_strlen(""));
	printf("Real strlen: %lu\n", strlen(""));
	printf("\n");

}

void ft_strcpy_test()
{
	char str1[100] = "hello";
	char str2[100] = "";
	printf("-------------------- FT_STRCPY --------------------\n");
	printf("1. Src empty:\n");
	printf("My ft_strcpy: %s\n", ft_strcpy(str1, str2));
	printf("Real strcpy: %s\n", strcpy(str1, str2));
	printf("\n");

	printf("2. Dst empty:\n");
	printf("My ft_strcpy: %s\n", ft_strcpy(str2, str1));
	printf("Real strcpy: %s\n", strcpy(str2, str1));
	printf("\n");

	printf("3. Short str:\n");
	printf("My ft_strcpy: %s\n", ft_strcpy(str1, "lol"));
	printf("Real strcpy: %s\n", strcpy(str1, "lol"));
	printf("\n");

	printf("3. Long str:\n");
	printf("My ft_strcpy: %s\n", ft_strcpy(str1, "lolglglglglglggergergegegergrerglgglglglglglg"));
	printf("Real strcpy: %s\n", strcpy(str1, "lolglglglglglggergergegegergrerglgglglglglglg"));
	printf("\n");
}

void ft_strcmp_test()
{
	printf("-------------------- FT_STRCMP --------------------\n");
	printf("1. Test & Test\n");
	printf("My ft_strcmp: %d\n", ft_strcmp("test", "test"));
	printf("Real strcmp: %d\n", strcmp("test", "test"));
	printf("\n");

	printf("2. Test & Tests\n");
	printf("My ft_strcmp: %d\n", ft_strcmp("test", "tests"));
	printf("Real strcmp: %d\n", strcmp("test", "tests"));
	printf("\n");

	printf("3. Test & Test_\n");
	printf("My ft_strcmp: %d\n", ft_strcmp("test", "test "));
	printf("Real strcmp: %d\n", strcmp("test", "test "));
	printf("\n");

	printf("4. Test & Test with tab\n");
	printf("My ft_strcmp: %d\n", ft_strcmp("test", "test\t"));
	printf("Real strcmp: %d\n", strcmp("test", "test\t"));
	printf("\n");

	printf("4. Testing & Test\n");
	printf("My ft_strcmp: %d\n", ft_strcmp("testing", "test"));
	printf("Real strcmp: %d\n", strcmp("testing", "test"));
	printf("\n");

}

int main()
{
	//ft_strlen_test();
	//ft_strcpy_test();
	ft_strcmp_test();
}