/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:30:42 by mkhellou          #+#    #+#             */
/*   Updated: 2022/12/08 15:31:07 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void images_generator(image_info *img,void *mlx)
{
	img[0].ptr=mlx_xpm_file_to_image(mlx,"./images/0.xpm",&img[0].resolution.x,&img[0].resolution.y);
	img[1].ptr=mlx_xpm_file_to_image(mlx,"./images/1.xpm",&img[2].resolution.x,&img[2].resolution.y);
	img[2].ptr=mlx_xpm_file_to_image(mlx,"./images/C.xpm",&img[3].resolution.x,&img[3].resolution.y);
	img[3].ptr=mlx_xpm_file_to_image(mlx,"./images/E.xpm",&img[4].resolution.x,&img[4].resolution.y);
	img[4].ptr=mlx_xpm_file_to_image(mlx,"./images/P.xpm",&img[5].resolution.x,&img[5].resolution.y);	
}

void images_destroyer(image_info *img,void *mlx)
{
	mlx_destroy_image(mlx,img[0].ptr);
	mlx_destroy_image(mlx,img[1].ptr);
	mlx_destroy_image(mlx,img[2].ptr);
	mlx_destroy_image(mlx,img[3].ptr);
	mlx_destroy_image(mlx,img[4].ptr);
}

void simple_map_printer(void *mlx,void *mlx_win,image_info *img , map_info map)
{
	int i = 0;
	int j = 0;
	int index;
	while (i<map.resolution.y)
	{
		j = 0;
		while (j < map.resolution.x)
		{
			if (map.map[i][j] == '0')
				index = 0;
			else if (map.map[i][j] == '1')
				index = 1;
			else if (map.map[i][j] == 'E')
				index = 2;
			else if (map.map[i][j] == 'C')
				index = 3;
			else if (map.map[i][j] == 'P')
				index = 4;
			mlx_put_image_to_window(mlx,mlx_win,img[index].ptr,SPRITE_X*j,SPRITE_Y*i);
			j++;
		}
		i++;
	}
}