/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_animator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 09:55:06 by mkhellou          #+#    #+#             */
/*   Updated: 2022/12/11 10:25:00 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"



void images_generator(image_info *img,void *mlx)
{
	ft_bzero(img,sizeof(image_info));
	img[background].ptr[0]=mlx_xpm_file_to_image(mlx,"./images/-0.xpm",&img[0].resolution.x,&img[0].resolution.y);
	img[wall].ptr[0]=mlx_xpm_file_to_image(mlx,"./images/-1.xpm",&img[2].resolution.x,&img[2].resolution.y);
	img[collectibales].ptr[0]=mlx_xpm_file_to_image(mlx,"./images/-2.xpm",&img[4].resolution.x,&img[4].resolution.y);
	img[map_exit].ptr[0]=mlx_xpm_file_to_image(mlx,"./images/-3.xpm",&img[3].resolution.x,&img[3].resolution.y);
	img[player].ptr[0]=mlx_xpm_file_to_image(mlx,"./images/-4.xpm",&img[5].resolution.x,&img[5].resolution.y);
	img[player].ptr[1]=mlx_xpm_file_to_image(mlx,"./images/-3.xpm",&img[0].resolution.x,&img[0].resolution.y);
	img[player].ptr[2]=NULL;
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

void image_animation(int element,int frame_rate,image_info *img,void** image_set,int clock)
{
	static int count ;
	
	if (clock % frame_rate == 0)
	{
		if(img[element].ptr[count] != NULL)
		{
			image_set[element]=img[element].ptr[count];
			count++;
		}
		else
			count = 0;
	}
}

void image_modifier(image_info *img,void** image_set)
{
	static int clock;


	image_animation(player,5,img,image_set,clock);
	image_set[wall]=img[wall].ptr[0];
	image_set[collectibales]=img[collectibales].ptr[0];
	image_set[map_exit]=img[map_exit].ptr[0];
	image_set[background]=img[background].ptr[0];
	image_set[go]=img[go].ptr[0];
	clock++;
}
