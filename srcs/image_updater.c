/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_updater.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:54:17 by mkhellou          #+#    #+#             */
/*   Updated: 2022/12/10 19:42:33 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int elment_counter(char **map,char c)
{
	int i;
	int j;
	int counter;

	counter = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (map[i][j] == c)
				counter++;
			j++;
		}
	i++;
	}
	return (counter);
}

void player_mouver(char **map,pos p,int x,int y)
{
	static int i;
	if (map[p.y+y][p.x+x] != '1' && map[p.y+y][p.x+x] != 'E')
	{
		i++;
		ft_printf("Player mouved : %d times\n",i);
		map[p.y][p.x] = '0';
		map[p.y+y][p.x+x] = 'P';
	}
}
void user_input(char **map,int keycode)
{
	pos p;
	get_cordonates(map,&p,'P');
	if (keycode  == D)
		player_mouver(map,p,1,0);
	else if (keycode  == A)
		player_mouver(map,p,-1,0);
	else if (keycode  == S)
		player_mouver(map,p,0,1);
	else if (keycode  == W)
		player_mouver(map,p,0,-1);
	else if (keycode  == ESC)
		exit(0);
}

void set_exit(char **map)
{
	pos p;
	get_cordonates(map,&p,'E');
	if (p.x == -1)
		return;
	map[p.x][p.y] = 'G';
}

void input_map_updater(all_data *data,int keycode)
{
	char **map;
	map = data->map.map;
	user_input(map,keycode);
	if (elment_counter(map,'C') == 0)
	{
		set_exit(map);
		if (elment_counter(map,'G') == 0)
		{
			ft_printf("You won");
			exit(0);
		}
	}
}

int key_press(int keycode, all_data *data)
{
	input_map_updater(data,keycode);
	// ft_printf("left");
	// if (keycode  == W)
	// ft_printf("up");
	// if (keycode  == S)
	// ft_printf("down");
	// if (keycode  == A)
	// ft_printf("right");
	return(0);
}