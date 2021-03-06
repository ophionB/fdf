/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-boc <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/07 15:13:27 by dvan-boc       #+#    #+#                */
/*   Updated: 2019/12/17 18:13:50 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Frees all the allocated nodes of s_lines
** @param lst
** @param size
*/

static void	free_lines(struct s_lines *lst, int size)
{
	struct s_lines	*temp;
	int				index;

	index = 0;
	while (index < size)
	{
		temp = lst;
		lst = lst->next;
		free(temp);
		index++;
	}
	free(lst);
}

/*
** Sorts the input into a 2D Pointer Array delimited by spaces.
** @param lst represents a linked-list cointaining a single line.
** @return A Pointer-to-Pointer Int Array
*/

static int	**sort_map(struct s_lines *lst, struct s_param *ptr, int y, int x)
{
	char			**split_line;
	int				**map;
	struct s_lines	*head;

	head = lst;
	map = malloc(sizeof(*map) * (ptr->map_height + 1));
	map[ptr->map_height] = NULL;
	while (y < ptr->map_height && lst->next != NULL)
	{
		split_line = ft_strsplit(lst->str, ' ');
		map[y] = malloc(sizeof(**map) * (ptr->map_width + 1));
		while (x < ptr->map_width)
		{
			map[y][x] = ft_atoi(split_line[x]);
			x++;
		}
		map[y][x] = -1;
		x = 0;
		y++;
		lst = lst->next;
		ft_free_array(split_line);
	}
	free_lines(head, y);
	return (map);
}

/*
** @param file represents the file name.
** @return sort_map returns an 2D int array.
** Stores every line into a linked list, to get sorted by sort_map.
** @var * head represents a pointer to the first element of the linkedlist.
*/

int			**ft_read_map(char *file, struct s_param *ptr)
{
	int				fd;
	char			*line;
	struct s_lines	*lst;
	struct s_lines	*head;
	char			**split;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("File not found.\n");
		exit(1);
	}
	lst = malloc(sizeof(*lst));
	head = lst;
	while (get_next_line(fd, &line))
	{
		lst->str = line;
		ptr->map_height++;
		lst->next = malloc(sizeof(*lst));
		lst = lst->next;
	}
	split = ft_strsplit(head->str, ' ');
	ptr->map_width = ft_2d_len(split);
	ft_free_array(split);
	return (sort_map(head, ptr, 0, 0));
}
