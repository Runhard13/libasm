/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:07:46 by cdrennan          #+#    #+#             */
/*   Updated: 2020/11/30 23:22:04 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>

size_t		ft_strlen (const char* str);
char		*ft_strcpy(char *dst, char const *src);
int			ft_strcmp(char const *s1, char const *s2);
ssize_t		ft_write(int fd, void const *buf, size_t nbyte);
ssize_t		ft_read(int fd, void *buf, size_t count);
char		*ft_strdup(const char *s);

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

void ft_write_test()
{
	int a;
	int b;
	int fd;

	ft_write(1, "-------------------- FT_WRITE --------------------\n", 51);
	ft_write(1, "Hello, this written with my ft_write function\n", 46);
	ft_write(1, "\n",1 );

	ft_write(1, "Check invalid write:\n", 21);
	a = ft_write(-1, "ef", 2);
	b = write(-1, "ef", 2);
	printf("My ft_write return: %d and errno: %d\n", a, errno);
	printf("Real write return: %d and errno: %d\n", b, errno);
	printf("\n");

	fd = open("test_write.txt", O_CREAT | O_WRONLY | O_TRUNC, 0666);
	ft_write(fd, "This is my ft_write test\n", 25);
	write(fd, "This was written by real write function\n", 39 );
	close(fd);

}

void ft_read_test()
{
	char str[100] = "";
	int fd;
	int a;
	int b;

	fd = open("./Makefile", O_RDONLY);
	printf("-------------------- FT_READ --------------------\n");
	printf("Bytes read: %zd\n", ft_read(fd, str, 10));
	printf("Bytes read: %zd\n", ft_read(fd, str, 50));
	printf("Bytes read: %zd\n", ft_read(fd, str, 100));
	printf("\n");

	printf("Check invalid read:\n");
	fd = -1;
	a = read(fd, str, 10);
	b = ft_read(fd, str, 10);
	printf("My ft_read return value: %d and errno: %d\n", b, errno);
	printf("Real read return value: %d and errno: %d\n", a, errno);
	printf("\n");


}

void ft_strdup_test()
{
	printf("-------------------- FT_STRDUP --------------------\n");
	printf("1. Short string dup\n");
	char *src;
	src = "Hello";
	char *dst_my = ft_strdup(src);
	char *dst_real = strdup(src);
	printf("My ft_strdup: %s\n", dst_my);
	printf("Real strdup: %s\n", dst_real);
	free(dst_my);
	free(dst_real);
	printf("\n");

	printf("2. s == empty\n");
	src = "";
	dst_my = ft_strdup(src);
	dst_real = strdup(src);
	printf("My ft_strdup: %s\n", dst_my);
	printf("Real strdup: %s\n", dst_real);
	free(dst_my);
	free(dst_real);
	printf("\n");

	printf("3. Long string dup\n");
	src = "wwrgeewfergegegrergergergergergerergergerggegrergg";
	dst_my = ft_strdup(src);
	dst_real = strdup(src);
	printf("My ft_strdup: %s\n", dst_my);
	printf("Real strdup: %s\n", dst_real);
	free(dst_my);
	free(dst_real);
	printf("\n");

}


int main()
{
	ft_write_test();
	ft_read_test();
	ft_strlen_test();
	ft_strcpy_test();
	ft_strcmp_test();
	ft_strdup_test();
}