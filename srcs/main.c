/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:23:10 by mkhellou          #+#    #+#             */
/*   Updated: 2022/12/10 19:44:27 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int key_press(int keycode, all_data *data);



int	render_frame(all_data *data)
{
	static int i;

	if (i % 300 == 0)
	simple_map_printer(data->mlx.mlx,data->mlx.mlx_win,data->img,data->map);
	// else if (i % 301 == 0)
	//  	mlx_clear_window(data->mlx.mlx,data->mlx.mlx_win);
	i++;
	return (0);
}

int destroy(void *param)
{
	(void)param;
	exit(0);
}
int	main(int av,char **ac)
{
	map_info map;
	mlx_info mlx;
	image_info img[6]; 
	all_data data;

	map=map_checker(av,ac);
	mlx.mlx = mlx_init();	
	mlx.mlx_win = mlx_new_window(mlx.mlx,map.resolution.x * SPRITE_X,map.resolution.y * SPRITE_Y ,"so_long");
	images_generator(img,mlx.mlx);
	data = (all_data){map,mlx,img};
	// player is on top of coin 


	mlx_hook(mlx.mlx_win, KeyPress, 1L<<0, key_press, &data);
	mlx_hook(mlx.mlx_win, DestroyNotify, 1L<<0, destroy, NULL);


	mlx_loop_hook(mlx.mlx,render_frame,&data);
	mlx_loop(mlx.mlx);
	free_map(map.map);
	images_destroyer(img,mlx.mlx);
	mlx_destroy_window(mlx.mlx,mlx.mlx);
	free(data.mlx.mlx);
	return (0);
}

