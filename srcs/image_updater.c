/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_updater.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:54:17 by mkhellou          #+#    #+#             */
/*   Updated: 2022/12/17 10:44:41 by mkhellou         ###   ########.fr       */
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
int key_press(int keycode, all_data *data)
{
	pos p;
	get_cordonates(data->map.map,&p,'P');
	if (keycode  == D)
	{
		data->keys[0][0]=1;
		data->keys[0][1]=0;
	}
	else if (keycode  == A)
	{
		data->keys[1][0]=1;
		data->keys[1][1]=0;
	}
	else if (keycode  == S)
		{
		data->keys[2][0]=1;
		data->keys[2][1]=0;
	}
	else if (keycode  == W)
	{
		data->keys[3][0]=1;
		data->keys[3][1]=0;
	}
	else if (keycode  == ESC)
	{
		data->keys[4][0]=1;
	}
	ft_printf("%d %d\n",data->keys[0][0],data->keys[0][1]);
	return (0);
}

int key_release(int keycode,all_data *data)
{
	pos p;
	get_cordonates(data->map.map,&p,'P');
	if (keycode  == D)
	{
		data->keys[0][0]=0;
		data->keys[0][1]=1;
	}
	else if (keycode  == A)
	{
		data->keys[1][0]=0;
		data->keys[1][1]=1;
	}
	else if (keycode  == S)
		{
		data->keys[2][0]=0;
		data->keys[2][1]=1;
	}
	else if (keycode  == W)
	{
		data->keys[3][0]=0;
		data->keys[3][1]=1;
	}
	ft_printf("%d %d\n",data->keys[0][0],data->keys[0][1]);
	return (0);
}

void set_exit(char **map)
{
	pos p;
	get_cordonates(map,&p,'E');
	if (p.x == -1)
		return;
	map[p.x][p.y] = 'G';
}

// void input_map_updater(all_data *data,int keycode)
// {
// 	char **map;
// 	map = data->map.map;
// 	//user_input(map,keycode);
// 	if (elment_counter(map,'C') == 0)
// 	{
// 		set_exit(map);
// 		if (elment_counter(map,'G') == 0)
// 		{
// 			ft_printf("You won");
// 			exit(0);
// 		}
// 	}
// }
// void map_modifier(all_data *data)
// {
// 	ft_printf("%d %d",data->keys[0][0],data->keys[0][1]);
// }
// int key_press(int keycode, all_data *data)
// {
	
// 	input_map_updater(data,keycode);

// 	return(0);
// }