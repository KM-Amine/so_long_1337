/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:23:10 by mkhellou          #+#    #+#             */
/*   Updated: 2022/12/05 19:46:24 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
// int	main(void)
// {
// 	char **map;

// 	//argv maps
// 	//map too big
// 	file_name_checker("map.ber");
// 	map = read_map("map.ber");
// 	if (!map)
// 		exit(EXIT_FAILURE);
// 	if (!map_error_handling(map))
// 		exit(EXIT_FAILURE);
// 	return (0);
// }

int	destr(int keycode, void *vars)
{
	(void)keycode;
	(void)vars;
	exit(0);
	return (0);
}
//mlx_hook(mlx_win, 17,0, destr, mlx);

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int main(void)
{
	void	*mlx;
	void	*mlx_win;
	//void	*img;
	// int i = 0;
	// int j = 0;
	// int k = 0;
	// if(fork() == 0)
	// 	system("afplay /Users/mkhellou/Downloads/lifelike-126735.mp3");

		mlx = mlx_init();
		if (!mlx)
			exit(EXIT_FAILURE);
		mlx_win = mlx_new_window(mlx, 1920, 1080, "So_long");
		if (!mlx_win)
			exit(EXIT_FAILURE);
		//i = 0;
		// while(i < 1080)
		// {
		// 	j = 0;
		// 	while (j < 1920)
		// 	{
		// 		mlx_pixel_put(mlx,mlx_win,j,i,k);
		// 		k++;
		// 		j++;
		// 	}
		// 	i++;
		// }
		mlx_string_put(mlx,mlx_win,10,50,25555,"hello");
		mlx_loop(mlx);
}