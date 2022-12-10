#include "../includes/so_long.h"

void rectangular_map(map_check *check, char **map)
{
	int i;
	int invalid;

	i = 0;
	invalid = 0;
	while (map[i+1] != NULL)
	{
		if(ft_strlen(map[i]) != ft_strlen(map[i+1]))
		{
			invalid = -1;
			break;
		}
		i++;
	}
	if (invalid == -1)
		check->rectangular = -1;
}

void stranger_characters(map_check *check, char **map)
{
	pos p;
	
	p.x = 0;
	while (map[p.x])
	{
		p.y = ft_strlen(map[p.x])-1;
		while (p.y>=0)
		{
			if(ft_strchr("01CEP",map[p.x][p.y]) == 0)
			{
				check->stranger_characters = -1;
				break;
			}
			p.y--;
		}
		p.x++;
	}	
}

void minimum_characters(map_check *check, char **map)
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
	if (c.e != 1 || c.p != 1 || c.c == 0)
		check->minimum_characters= -1; 
}

void closed_map(map_check *check, char **map)
{
	int i;
	int j;
	int len;

	i = 0;
	while (map[0][i])
	{
		if(map[0][i] != '1')
			check->closed=-1;
		i++;
	}
	j = 0;
	while (map[j])
		j++;
	j--;
	i=0;
	while (map[j][i])
	{
		if(map[j][i] != '1')
			check->closed=-1;
		i++;
	}
	i = 0;
	while (map[i])
	{
		if(map[i][0] != '1')
			check->closed=-1;
		i++;
	}
	len = ft_strlen(map[0]) - 1;
	i = 0;
	while (map[i])
	{
		if(map[i][len] != '1')
			check->closed=-1;
		i++;
	}
}

void map_structure(map_check *check,char **map)
{
	map_check zero;

	ft_bzero(&zero,sizeof(map_check));
	rectangular_map(check, map);
	stranger_characters(check, map);
	minimum_characters(check, map);
	closed_map(check, map);
	if(ft_memcmp(check,&zero,sizeof(map_check)) != 0)
	{
		free_map(map);
		error_exit_function(check);
	}
}


