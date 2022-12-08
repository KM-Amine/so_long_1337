/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:00:18 by mkhellou          #+#    #+#             */
/*   Updated: 2022/12/08 20:07:33 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void contamination(char **map, pos p,int *count,char *set)
{
	if (ft_strchr(set,map[p.y][p.x+1]) != 0)
	{
		*count = 1;
		map[p.y][p.x+1] = 'Z';
	}
	if (ft_strchr(set,map[p.y][p.x-1]) != 0)
	{
		*count = 1;
		map[p.y][p.x-1] = 'Z';
	}
	if (ft_strchr(set,map[p.y+1][p.x]) != 0)
	{
		*count = 1;
		map[p.y+1][p.x] = 'Z';
	}
	if (ft_strchr(set,map[p.y-1][p.x]) != 0)
	{
		*count = 1;
		map[p.y-1][p.x] = 'Z';	
	}
}

///////////////////

int exit_check(char **map,int i)
{
	char_cont c;
	pos p;
	int len;
	
	ft_bzero(&c,sizeof(char_cont));
	p.x = 0;
	while (map[p.x])
	{
		p.y = 0;
		len = ft_strlen(map[p.x]);
		while (p.y < len)
		{
			if (map[p.x][p.y]== 'E')
				c.e++;
			if (map[p.x][p.y]== 'P')
				c.p++;
			if (map[p.x][p.y]== 'C')
				c.c++;
			p.y++;
		}
		p.x++;
	}
	if (i == 1 && c.p == 0 && c.c == 0 && c.e == 0)
			return(1);
	else if (i == 0 && c.p == 0 && c.c == 0)
			return(1);
	return(0);
}

void valid_path(map_check *check,char **map,int b)
{
	pos p;
	int i;

	i=0;
	while (1)
	{
	i = 0;
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
					contamination(map,p,&i,"C0E");
				else
					contamination(map,p,&i,"C0");
			}
			p.x++;
		}
		p.y++;
	}
	if (i == 0)
		break;
	}
	if (exit_check(map,b) == 0 && b == 0)
		check->no_exit=-1;
	else if(exit_check(map,b) == 0 && b == 1)
		check->with_exit=-1;
}
//////////////////////////


void path_with_exit(map_check *check,char **map)
{
	pos p;
	int i;

	i=0;
	while (1)
	{
	i = 0;
	p.y = 0;
	while (map[p.y])
	{
		p.x = 0;
		while (map[p.y][p.x])
		{
			if (map[p.y][p.x] == 'P')
				map[p.y][p.x] = 'Z';
			if (map[p.y][p.x] == 'Z')
				contamination(map,p,&i,"C0E");
			p.x++;
		}
		p.y++;
	}
	if (i == 0)
		break;
	}
	if (exit_check(map,1) == 0)
		check->with_exit=-1;
}
