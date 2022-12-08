/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:00:18 by mkhellou          #+#    #+#             */
/*   Updated: 2022/12/05 13:15:54 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

///////////////////
int no_exit_check(char **map)
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
	if (c.p == 0 && c.c == 0)
		return(1);
	return(0);
}

void contamination_no_exit(char **map, pos p,int *count)
{
	if (map[p.y][p.x+1] == 'C' || map[p.y][p.x+1] == '0' )
	{
		*count = 1;
		map[p.y][p.x+1] = 'Z';
	}
	if (map[p.y][p.x-1] == 'C' || map[p.y][p.x-1] == '0' )
	{
		*count = 1;
		map[p.y][p.x-1] = 'Z';
	}
	if (map[p.y+1][p.x] == 'C' || map[p.y+1][p.x] == '0' )
	{
		*count = 1;
		map[p.y+1][p.x] = 'Z';
	}
	if (map[p.y-1][p.x] == 'C' || map[p.y-1][p.x] == '0' )
	{
		*count = 1;
		map[p.y-1][p.x] = 'Z';	
	}
}

void path_no_exit(map_check *check,char **map)
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
				contamination_no_exit(map,p,&i);
			p.x++;
		}
		p.y++;
	}
	if (i == 0)
		break;
	}
	if (no_exit_check(map) == 0)
		check->no_exit=-1;
}
//////////////////////////
void contamination_with_exit(char **map, pos p,int *count)
{
	if (map[p.y][p.x+1] == 'C' || map[p.y][p.x+1] == '0' || map[p.y][p.x+1] == 'E' )
	{
		*count = 1;
		map[p.y][p.x+1] = 'Z';
	}
	if (map[p.y][p.x-1] == 'C' || map[p.y][p.x-1] == '0' || map[p.y][p.x-1] == 'E')
	{
		*count = 1;
		map[p.y][p.x-1] = 'Z';
	}
	if (map[p.y+1][p.x] == 'C' || map[p.y+1][p.x] == '0' || map[p.y+1][p.x] == 'E')
	{
		*count = 1;
		map[p.y+1][p.x] = 'Z';
	}
	if (map[p.y-1][p.x] == 'C' || map[p.y-1][p.x] == '0' || map[p.y-1][p.x] == 'E')
	{
		*count = 1;
		map[p.y-1][p.x] = 'Z';	
	}
}

int with_exit_check(char **map)
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
	if (c.p == 0 && c.c == 0 && c.e == 0)
		return(1);
	return(0);
}

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
				contamination_with_exit(map,p,&i);
			p.x++;
		}
		p.y++;
	}
	if (i == 0)
		break;
	}
	if (with_exit_check(map) == 0)
		check->with_exit=-1;
}
