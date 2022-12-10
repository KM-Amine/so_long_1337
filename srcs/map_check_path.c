/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:00:18 by mkhellou          #+#    #+#             */
/*   Updated: 2022/12/10 13:39:24 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	contamination(char **map, pos p, int *count, char *set)
{
	if (ft_strchr(set, map[p.y][p.x + 1]) != 0)
	{
		*count = 1;
		map[p.y][p.x + 1] = 'Z';
	}
	if (ft_strchr(set, map[p.y][p.x - 1]) != 0)
	{
		*count = 1;
		map[p.y][p.x - 1] = 'Z';
	}
	if (ft_strchr(set, map[p.y + 1][p.x]) != 0)
	{
		*count = 1;
		map[p.y + 1][p.x] = 'Z';
	}
	if (ft_strchr(set, map[p.y - 1][p.x]) != 0)
	{
		*count = 1;
		map[p.y - 1][p.x] = 'Z';
	}
}

///////////////////

int	exit_check(char **map, int i)
{
	char_cont	c;
	pos			p;
	int			len;

	ft_bzero(&c, sizeof(char_cont));
	p.x = 0;
	while (map[p.x])
	{
		p.y = 0;
		len = ft_strlen(map[p.x]);
		while (p.y < len)
		{
			if (i == 1)
			{
				if (ft_strchr("EPC", map[p.x][p.y]) != 0)
					return (0);
			}
			else if (i == 0)
			{
				if (ft_strchr("PC", map[p.x][p.y]) != 0)
					return (0);
			}
			p.y++;
		}
		p.x++;
	}
	return (1);
}

void	valid_path(map_check *check, char **map, int b)
{
	pos		p;
	int		end_counter;

	end_counter = 0;
	while (1)
	{
		end_counter = 0;
		p.y = 0;
		while (map[p.y])
		{
			p.x = 0;
			while (map[p.y][p.x])
			{
				if (map[p.y][p.x] == 'P')
					map[p.y][p.x] = 'Z';
				if (map[p.y][p.x] == 'Z')
				{
					if (b == 1)
						contamination(map, p, &end_counter, "C0E");
					else
						contamination(map, p, &end_counter, "C0");
				}
				p.x++;
			}
			p.y++;
		}
		if (end_counter == 0)
			break ;
	}
	if (exit_check(map, b) == 0 && b == 0)
		check->no_exit = -1;
	else if (exit_check(map, b) == 0 && b == 1)
		check->with_exit = -1;
}

void valid_path_handler(map_check *check,char **map)
{
	char **copy1;
	char **copy2;
	map_check zero;

	ft_bzero(&zero,sizeof(map_check));
	copy1 = map_copy(map);
	if (!copy1)
	{
		free_map(map);
		exit(EXIT_FAILURE);
	}
	valid_path(check,copy1,0);
	copy2 = map_copy(copy1);
	if (!copy2)
	{
		free_map(map);
		free_map(copy1);
		exit(EXIT_FAILURE);
	}
	free_map(copy1);
	valid_path(check,copy2,1);
	free_map(copy2);
	if(ft_memcmp(check,&zero,sizeof(map_check)) != 0)
	{	
		free_map(map);
		error_exit_function(check);
	}
}