/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 17:26:39 by cphillip          #+#    #+#             */
/*   Updated: 2021/01/10 13:04:59 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"


void	print_byte_str(char *src)
{
	int i;

	i = 1;
	if (src)
	{
		while (src[i - 1])
		// while (i - 1 < max_len)
		{
			printf("%c", src[i - 1]);
			if (i % 4 == 0)
				printf(" ");
			if (i % 32 == 0)
				printf("\n");
			i++;
		}
	}
}

int	main(int ac, char **av)
{
	char	*byte_name;
	char 	*name;
	char	*n_comment;
	char	*byte_comment;

	byte_name = NULL;
	byte_comment = NULL;
	name = ft_strdup(*(av + 1));
	n_comment = ft_strdup(*(av + 2));


	name_to_byte(&byte_name, name);
	comment_to_byte(&byte_comment, n_comment);
	// free(name);
	// name = NULL;
	// free(byte_str);
	// byte_str = NULL;
	// printf("%s\n", name);
	printf("name: %s\n", *(av + 1));
	printf("ac: %d\n", ac);
	// print_byte_str(byte_name);
	print_byte_str(byte_comment);
	system("leaks asm");
	return (0);
}