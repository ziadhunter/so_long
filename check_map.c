/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 21:33:25 by zfarouk           #+#    #+#             */
/*   Updated: 2025/02/12 14:12:46 by zfarouk          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void eror_exit(int i)
{
    if (i == 0)
        write(1, "Map not found\n", 14);
    else if (i == 1)
        write(1, "invalid extention of the file\n", 30);
    else if (i == 2)
        write(1, "empty file\n", 11);
    else if (i == 3)
        write(1, "map is not closed\n", 18);
    else if (i == 4)
        write(1, "invalid map\n", 12);
    else if (i == 5)
        write(1,"file not found\n", 15);
    else if (i == 6)
        write(1,"map is not rectangular\n", 23);
    exit(1);
}
int ft_strcmp(char *str, char *cmp, int len)
{
    int i;

    i = 0;
    while (i < len && str[i] && str[i] == cmp[i])
        i++;
    return (str[i] - cmp[i]);
}

void valide_name(char *file_name)
{
    if (ft_strlen(file_name) <=4)
        eror_exit(1);
    while (*file_name)
    {
        if (*file_name == '.')
        {
            if ((ft_strcmp(file_name, ".ber", 4)) == 0)
                return;
        }
        file_name++;
    }
    eror_exit(1);
}
int ft_strlen(char *str)
{
    int i;

	i = 0;

	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;

	int (i), (j);
	i = 0;
	j = 0;
	if (!s1)
	{
		new = malloc(sizeof(char) * (ft_strlen(s2) + 1));
		if (!new)
			return (NULL);
		while (s2[j])
			new[i++] = s2[j++];
		return (new[i] = '\0', free(s2), new);
	}
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (free(s1), free(s2), NULL);
	while (s1[i])
		new[j++] = s1[i++];
	i = 0;
	while (s2[i])
		new[j++] = s2[i++];
	new[j] = '\0';
	return (free(s1), free(s2), new);
}

void empty_line(char *s, char *text)
{
    if(s[0] == '\n')
    {
        free(s);
        free(text);
        eror_exit(4);
    }
}

char **is_rectangular(char *name, int i)
{
    char *text;
    char *line;
    int (len), (fd);
    char **lines;

    text = NULL;
    fd = open(name, O_RDONLY);
    if (fd == -1)
        eror_exit(5);
    while ((line = get_next_line(fd)) != NULL)
    {
        empty_line(line, text);
        text = ft_strjoin(text, line);
    }
    lines = ft_split(text, '\n');
    free(text);
    if (lines)
    {
        len = ft_strlen((lines)[i]);
        while (lines[i])
        {
            if (ft_strlen((lines)[i]) != len)
                return (free_double_string(lines), eror_exit(6), NULL);
            i++;
        }
    }
    return (lines);
}

void take_position(char c, int x, int y, t_map **map_info)
{
    if (c == 'E')
    {
            (*map_info)->e_position_x = x;
            (*map_info)->e_position_y = y;
            (*map_info)->exit++;
    }
    else if(c == 'P')
    {
            (*map_info)->p_position_x = x;
            (*map_info)->p_position_y = y;
            (*map_info)->player++;
    }
}

void invalid_path(char **lines, char **lines2, t_path *check, t_map *map_info)
{
    free_double_string(lines);
    free_double_string(lines2);
    free(check);
    free(map_info);
    write(1, "invalid path\n", 13);
    exit(1);
}

void map_component(char **lines, t_map **map_info)
{
    int (x), (y);

    (*map_info)->exit = 0;
    (*map_info)->player = 0;
    (*map_info)->collectible = 0;
    y = 0;
    while (lines[y])
    {
        x = 0;
        while (lines[y][x])
        {
            if (lines[y][x] == 'C')
                ((*map_info)->collectible)++;
            else if (lines[y][x] == 'E' || lines[y][x] == 'P')
                take_position(lines[y][x], x, y, map_info);
            x++;
        }
        y++;
    }
    if ((*map_info)->player != 1 || (*map_info)->exit != 1)
    {
        free_double_string(lines);
        free(*map_info);
        eror_exit(4);    
    }
}

char	*ft_strdup(char *s1)
{
	int		j;
	int		i;
	char	*p;

	i = ft_strlen(s1);
	p = malloc((i + 1) * sizeof(char));
	if (!p)
		return (NULL);
	j = 0;
	while (j < i)
	{
		p[j] = s1[j];
		j++;
	}
	p[j] = '\0';
	return (p);
}

char **duplicate(char **lines)
{
    int i;
    char **lines2;

    i = 0;
    while (lines[i])
        i++;
    lines2 = malloc(sizeof(char *) * (i + 1));
    i = 0;
    while (lines[i])
    {
        lines2[i] = ft_strdup(lines[i]);
        i++;
    }
    lines2[i] = NULL;
    return (lines2);
}

void check_map(char *file_name, t_map **map_info)
{
    char **lines;
    char **lines2;
    t_path *check;

    lines = NULL;
    if (!file_name)
        eror_exit(0);    
    valide_name(file_name);
    lines = is_rectangular(file_name, 0);
    if (lines == NULL)
        eror_exit(2);
    check_walls(lines);
    *map_info = malloc(sizeof(t_map));
    map_component(lines, map_info);
    lines2 = duplicate(lines);
    check = malloc(sizeof(t_path));
    check->C = 0;
    check->E = 0;
    flood_fill(lines2, (*map_info)->p_position_x, (*map_info)->p_position_y, check);
    if(check->C != (*map_info)->collectible || check->E != 1)
        invalid_path(lines, lines2, check, *map_info);
    free(check);
    free_double_string(lines2);
    (*map_info)->map = lines;
}

int main(int ac, char **av)
{
    t_map *map_info;

    if (ac == 2)
    {
        check_map(av[1], &map_info);
        printf("all good");
        free_double_string(map_info->map);
        free(map_info);
    }
    return (0);
}
