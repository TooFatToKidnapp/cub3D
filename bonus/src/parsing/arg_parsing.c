/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:53:27 by aabdou            #+#    #+#             */
/*   Updated: 2022/08/21 16:44:17 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	open_file(int *fd, char *file_name)
{
	*fd = open(file_name, O_RDWR);
	if (*fd < 0)
	{
		ft_putendl_fd("Error:\ncant open file!", 2);
		exit(EXIT_FAILURE);
	}
	return ;
}

void	check_file_type(char *path, char *ext)
{
	char	*dot_pos;
	int		i;

	i = 0;
	dot_pos = ft_strrchr(path, '.');
	if (dot_pos == NULL || ft_strlen(dot_pos) != 4)
	{
		ft_putendl_fd("Error:\nWrong file type!", 2);
		exit(EXIT_FAILURE);
	}
	while (dot_pos[i] != '\0')
	{
		if (dot_pos[i] != ext[i])
		{
			ft_putendl_fd("Error:\nWrong file type!", 2);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return ;
}

void	check_argument(int ac, char **av, int *fd)
{
	if (ac != 2)
	{
		ft_putendl_fd("Error:\nwrong number of arguments!", 2);
		exit(EXIT_FAILURE);
	}
	check_file_type(av[1], ".cub");
	open_file(fd, av[1]);
	return ;
}
