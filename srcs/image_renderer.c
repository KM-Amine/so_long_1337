/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_renderer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:30:42 by mkhellou          #+#    #+#             */
/*   Updated: 2022/12/11 14:58:59 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void set_map_data(char **map,char c,char *set)
{
	int i;
	int j;
	
	i = 0;
	while (map[i])
	{
		j = 0; 
		while (map[i][j])
		{
			if (ft_strchr(set,map[i][j]))
				map[i][j] = c;
			j++;
		}	
	i++;
	}
}

void first_layer(char *set,void **image_set , map_info map,void *mlx,void *mlx_win)
{
	char **copy;
	int i;
	int j;
	int index;

	copy = map_copy(map.map);
	set_map_data(copy,'0',"CP");
	i = 0;
	while (copy[i])
	{
		j = 0;
		while (copy[i][j])
		{
			index = ft_strchr(set,copy[i][j])-set;
			mlx_put_image_to_window(mlx,mlx_win,image_set[index],SPRITE_X*j,SPRITE_Y*i);
			j++;
		}
		i++;
	}
	free_map(copy);
}
void second_layer(char *set,void **image_set , map_info map,void *mlx,void *mlx_win)
{
	char **copy;
	int i;
	int j;
	int index;

	copy = map_copy(map.map);
	i = 0;
	while (copy[i])
	{
		j = 0;
		while (copy[i][j])
		{
			if (ft_strchr("CP",copy[i][j]))
			{
				index = ft_strchr(set,copy[i][j])-set;
				mlx_put_image_to_window(mlx,mlx_win,image_set[index],SPRITE_X*j,SPRITE_Y*i);
			}
			j++;
		}
		i++;
	}
	free_map(copy);
}

void simple_map_printer(void *mlx,void *mlx_win,void **image_set , map_info map)
{
	char *set="01ECPG";
	

	first_layer(set,image_set,map,mlx,mlx_win);
	second_layer(set,image_set,map,mlx,mlx_win);
}