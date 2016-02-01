/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouloube <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 14:56:56 by aouloube          #+#    #+#             */
/*   Updated: 2016/02/01 18:26:01 by aouloube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "libft/includes/libft.h"
#include <math.h>


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
void	mlx_draw_point(t_mlx *mlx, int x, int y,int color, int offset)
{
	mlx_pixel_put(mlx->mlx, mlx->win, (x - y) * (offset), (y + x) * (offset / 2), color);
}

void	ft_fdf(t_mlx *mlx ,char **argv)
 {
	char	*line;
	char	**l2;
	int		fd;
	int		x;
	int		y;
	int		i;
	int		offset;
	int		d;

	offset = 30;
	fd = open(argv[1], O_RDONLY);
	y = 0;
	while (get_next_line(fd, &line))
	{
	 	l2 = ft_strsplit(line, ' ');
		x = offset / 2;
		i = 0;

		while(l2[i])
		{
			if (ft_atoi(l2[i]) == 10)
			{
				mlx_draw_point(mlx, x, y , 0X00BA3733, offset);
				if (ft_atoi(l2[i + 1]) == 10)
				{
					d = 1;
					while (d < offset)
					{
						mlx_pixel_put(mlx->mlx, mlx->win, ((x  - y) * offset) + d, ((y + x ) * ((offset) /  2) + (d / 2)), 0X00BA3733);
						mlx_pixel_put(mlx->mlx, mlx->win, ((x  - y) * offset) - d, ((y + x ) * ((offset) /  2) + (d / 2)), 0X00BA3733);
						d++;
					}
				}
						}
			else
			{
				mlx_draw_point(mlx, x, y , 0X00FFFFFF, offset);
				d = 1;
					while (d < offset)
					{
						mlx_pixel_put(mlx->mlx, mlx->win, ((x  - y) * offset) + d, ((y + x ) * ((offset) /  2) + (d / 2)), 0X00FFFFFF);
						mlx_pixel_put(mlx->mlx, mlx->win, ((x  - y) * offset) - d, ((y + x ) * ((offset) /  2) + (d / 2)),  0X00FFFFFF);
						d++;
					}

			}
			x++;
			i++;
		}

		y++;
		printf("[%s]\n", line);
	}

}

t_mlx	*ft_mlx_init()
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx *));
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, 1000, 1000, "FDF by Afxsoft");
	return (mlx);
}


int		main (int argc, char **argv)
{
	t_mlx	*mlx;
	
	mlx = ft_mlx_init();
	ft_fdf(mlx, argv);
	argc = 0;
	printf("Fuck tha police");
	mlx_key_hook(mlx->win, mlx_key_press, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
