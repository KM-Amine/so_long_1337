/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:09:49 by mkhellou          #+#    #+#             */
/*   Updated: 2022/12/08 15:31:38 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H 

# include "libft.h"
# include <fcntl.h>
# include <mlx.h>
#include "X.h"

#define WINDOW_X 2560
#define WINDOW_Y 1440

//osascript -e 'tell application "Finder" to get bounds of window of desktop'
// display resolution

# define SPRITE_X 64
# define SPRITE_Y 64

// music librrary in /usr/local/include
// or system("afplay /Users/mkhellou/Downloads/lifelike-126735.mp3");

typedef struct map_check
{
	int rectangular;
	int stranger_characters;
	int minimum_characters;
	int closed;
	int no_exit;
	int with_exit;
} map_check;

typedef struct char_cont
{
	int e;
	int c;
	int p;
} char_cont;
typedef struct pos
{
	int x;
	int y;
} pos;

typedef struct map_info
{
	char **map;
	pos resolution;
} map_info;

typedef struct image_info
{
	void *ptr;
	pos	resolution;
} image_info;

typedef struct map_images
{
	image_info F;
	image_info W;
	image_info C;
	image_info E;
	image_info P;
} map_images;


//utils for map
void free_map(char **map);
char **read_map(char *file);
char **map_copy(char **map);
void print_map(char **map);
void get_cordonate(char **map,pos *cordonates);


map_info map_checker(int av,char **ac);
void check_cordonates(char **map,pos *cordonates);

void images_generator(image_info *img,void *mlx);
void images_destroyer(image_info *img,void *mlx);
void simple_map_printer(void *mlx,void *mlx_win,image_info *img , map_info map);


void path_no_exit(map_check *check,char **map);
int map_error_handling(char **map);
char **map_copy(char **map);
void path_with_exit(map_check *check,char **map);
void error_exit_function(map_check *check);
void file_name_checker(char *str);
#endif