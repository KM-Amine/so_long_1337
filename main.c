/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:23:10 by mkhellou          #+#    #+#             */
/*   Updated: 2022/12/05 17:12:31 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(void)
{
	char **map;

	//argv maps
	//map too big
	file_name_checker("map.ber");
	map = read_map("map.ber");
	if (!map)
		exit(EXIT_FAILURE);
	if (!map_error_handling(map))
		exit(EXIT_FAILURE);
	return (0);
}
/*
int	destr(int keycode, void *vars)
{
	(void)keycode;
	(void)vars;
	exit(0);
	return (0);
}
mlx_hook(mlx_win, 17,0, destr, mlx);*/

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

// int main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	//void	*img;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	mlx_loop(mlx);
// }