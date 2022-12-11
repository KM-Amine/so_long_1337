/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:30:42 by mkhellou          #+#    #+#             */
/*   Updated: 2022/12/11 09:50:59 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"



void images_generator(image_info *img,void *mlx)
{
	img[background].ptr[0]=mlx_xpm_file_to_image(mlx,"./images/-0.xpm",&img[0].resolution.x,&img[0].resolution.y);
	img[wall].ptr[0]=mlx_xpm_file_to_image(mlx,"./images/-1.xpm",&img[2].resolution.x,&img[2].resolution.y);
	img[collectibales].ptr[0]=mlx_xpm_file_to_image(mlx,"./images/-2.xpm",&img[4].resolution.x,&img[4].resolution.y);
	img[map_exit].ptr[0]=mlx_xpm_file_to_image(mlx,"./images/-3.xpm",&img[3].resolution.x,&img[3].resolution.y);
	img[player].ptr[0]=mlx_xpm_file_to_image(mlx,"./images/-4.xpm",&img[5].resolution.x,&img[5].resolution.y);
	img[player].ptr[1]=mlx_xpm_file_to_image(mlx,"./images/-3.xpm",&img[0].resolution.x,&img[0].resolution.y);
	img[go].ptr[0]=mlx_xpm_file_to_image(mlx,"./images/-4.xpm",&img[5].resolution.x,&img[5].resolution.y);
}
void images_destroyer(image_info *img,void *mlx)
{
	int i;
	
	i = 0;
	while (i<4)
	{
		mlx_destroy_image(mlx,img[i].ptr);
	}
}

void image_modifier(image_info *img,void** image_set)
{
	static int i;
	static int count ;


	if (i % 5 == 0)
	{
		if (count == 0)
		{
			image_set[player]=img[player].ptr[0];
			count = 1;
		}
		else if (count == 1)
		{
			image_set[player]=img[player].ptr[1];
			count = 0;
		}
	}
	image_set[wall]=img[wall].ptr[0];
	image_set[collectibales]=img[collectibales].ptr[0];
	image_set[map_exit]=img[map_exit].ptr[0];
	image_set[background]=img[background].ptr[0];
	image_set[go]=img[go].ptr[0];
	i++;
}


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