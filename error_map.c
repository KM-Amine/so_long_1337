/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:43:06 by mkhellou          #+#    #+#             */
/*   Updated: 2022/12/05 16:46:52 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void error_exit_function(map_check *check)
{
	ft_printf("Error\n");
	ft_printf("Invalid map :\n");
	if (check->rectangular == -1)
		ft_printf("- map is not rectangular\n");
	if (check->stranger_characters == -1)
		ft_printf("- map has a stranger character\n");
	if (check->minimum_characters == -1)
		ft_printf("- map does not respect the number possible of coins , exit and starting point\n");
	if (check->closed == -1)
		ft_printf("- the map is not closed by walls\n");
	if (check->with_exit == -1)
		ft_printf("- the exit can't be reached\n");
	if (check->no_exit == -1)
		ft_printf("- the coins can't be reached\n");
	exit(EXIT_FAILURE);
}

void file_name_checker(char *str)
{
	int error;
	int fd;
	error = 0;
	fd = open(str,O_RDONLY);
	if (fd == -1)
		error = -1;
	if (ft_strnstr(str,".ber",ft_strlen(str)) == 0)
		error = -1;
	else if (*(ft_strrchr(str,'r')+1) != '\0')
	 	error = -1;
	else if (str[0] == '.')
		error = -1;
	if (error == -1)
	{
		ft_printf("Error\nInvalid file extention or unixisting file\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		ft_printf("Valid file name\n");
		close(fd);
	}
}