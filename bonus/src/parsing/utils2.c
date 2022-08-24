/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 19:48:26 by aabdou            #+#    #+#             */
/*   Updated: 2022/08/24 18:13:49 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	loop_through_string(char *str)
{
	int	i;
	int	comma_count;

	comma_count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
			comma_count++;
		i++;
	}
	if (comma_count != 2)
		return (1);
	return (0);
}

void	check_comma(t_map_requirements *var, char *str)
{
	char	*tab;

	tab = ft_substr(str, 0, 1);
	if (ft_strncmp(tab, "C", 1) == 0 || ft_strncmp(tab, "F", 1) == 0)
	{
		if (loop_through_string(str) == 1)
		{
			printf("Error:\nwrong RGB format!\n");
			free_2d(var->map);
			free(tab);
			free_file_path(var);
			exit(EXIT_FAILURE);
		}
	}
	free(tab);
	return ;
}

char	*ft_get_map(char *str)
{
	int	i;
	int	requirements;

	i = -1;
	requirements = 0;
	while (str[++i] && requirements != 6)
	{
		if (str[i] == 'N' && str[i + 1] == 'O')
			requirements++;
		if (str[i] == 'S' && str[i + 1] == 'O')
			requirements++;
		if (str[i] == 'W' && str[i + 1] == 'E')
			requirements++;
		if (str[i] == 'E' && str[i + 1] == 'A')
			requirements++;
		if (str[i] == 'F' && str[i + 1] == ' ')
			requirements++;
		if (str[i] == 'C' && str[i + 1] == ' ')
			requirements++;
	}
	while (str[i] != '\n')
		i++;
	while (str[i] == '\n')
		i++;
	return (&str[i]);
}

int	inspect_map(char *str)
{
	char	*tab;
	int		i;
	int		var;

	tab = ft_get_map(str);
	i = 0;
	var = ft_strlen(tab);
	while (i < var)
	{
		if (tab[i] == '\n' && tab[i + 1] == '\n')
		{
			while (tab[i] == '\n' && tab[i])
				i++;
			if (tab[i] != '\0')
				return (1);
		}
		i++;
	}
	return (0);
}
