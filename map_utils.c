

#include "includes/so_long.h"

char **read_map(char *file)
{
	char *str;
	int fd;
	int i;
	char **map;
	int j;

	i = 0;
	fd = open(file,O_RDONLY);
	str =get_next_line(fd);
	if (!str)
		return(0);
	while (str != NULL)
	{
		free(str);
		str = get_next_line(fd);
		i++;
	}
	close(fd);
	map = (char **)ft_calloc(i+1,sizeof(char*));
	if (!map)
		return(0);
	fd = open(file,O_RDONLY);
	j = 0;
	while (j < i)
	{
		str = get_next_line(fd);
		if (!str)
			return(0);
		map[j] = ft_strtrim(str,"\n");
		if (!map)
			return (0);
		free(str);
		j++;
	}
	close(fd);
	return (map);
}

void free_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char **map_copy(char **map)
{
	int i;
	int j;
	char **copy;
	
	i = 0;
	j = 0;
	while (map[i])
		i++;
	copy =(char **)ft_calloc(i+1,sizeof(char **));
	if (!copy)
		return(NULL);
	while (j < i)
	{
		copy[j] = ft_strdup(map[j]);
		if (!copy[j])
			return(NULL);
		j++;
	}
	return (copy);
}

void print_map(char **map)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (map[i])
		i++;
	while (j < i)
	{
		ft_printf("%s\n",map[j]);
		j++;
	}
}