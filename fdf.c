/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouloube <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 14:56:56 by aouloube          #+#    #+#             */
/*   Updated: 2016/01/12 16:21:23 by aouloube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "libft.h"


typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
}				t_mlx;

int		mlx_key_press(int keyword, void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx *)param;
	if (keyword == 53)
		exit(0);
	return (0);
}
int		main (int argc, char **argv)
{
	t_mlx	*mlx;
	char	*line;
	int		fd;
	argc = 0;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		printf("[%s]\n", line);
	}
	mlx = (t_mlx *)malloc(sizeof(t_mlx *));
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, 1000, 1000, "FDF by Afxsoft");
	argv[0] = "fapfap";
	argc = 0;
	mlx_pixel_put(mlx->mlx, mlx->win, 200, 200, 0X00FFFFF);
	printf("Fuck tha police");
	mlx_key_hook(mlx->win, mlx_key_press, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
