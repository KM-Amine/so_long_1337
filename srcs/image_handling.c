/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:30:42 by mkhellou          #+#    #+#             */
/*   Updated: 2022/12/10 18:34:18 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"



void images_generator(image_info *img,void *mlx)
{
	img[background].ptr=mlx_xpm_file_to_image(mlx,"./images/-0.xpm",&img[0].resolution.x,&img[0].resolution.y);
	img[wall].ptr=mlx_xpm_file_to_image(mlx,"./images/-1.xpm",&img[2].resolution.x,&img[2].resolution.y);
	img[collectibales].ptr=mlx_xpm_file_to_image(mlx,"./images/-2.xpm",&img[4].resolution.x,&img[4].resolution.y);
	img[map_exit].ptr=mlx_xpm_file_to_image(mlx,"./images/-3.xpm",&img[3].resolution.x,&img[3].resolution.y);
	img[player].ptr=mlx_xpm_file_to_image(mlx,"./images/-4.xpm",&img[5].resolution.x,&img[5].resolution.y);
	img[go].ptr=mlx_xpm_file_to_image(mlx,"./images/-4.xpm",&img[5].resolution.x,&img[5].resolution.y);
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

void simple_map_printer(void *mlx,void *mlx_win,image_info *img , map_info map)
{
	int i = 0;
	int j = 0;
	int index;
	char *set="01ECPG";
	while (i<map.resolution.y)
	{
		j = 0;
		while (j < map.resolution.x)
		{
			index = ft_strchr(set,map.map[i][j])-set;
			mlx_put_image_to_window(mlx,mlx_win,img[index].ptr,SPRITE_X*j,SPRITE_Y*i);
			j++;
		}
		i++;
	}
}