/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouloube <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 14:56:56 by aouloube          #+#    #+#             */
/*   Updated: 2016/02/08 18:32:17 by aouloube         ###   ########.fr       */
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
	char		**current_l;
	char		**next_l;
	int			offset;
	int			x;
	int			y;
}				t_mlx;

int		mlx_key_press(int keyword, void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx *)param;
	if (keyword == 53)
		exit(0);
	return (0);
}

void	mlx_draw_point(t_mlx *mlx, int x, int y,int color, int offset, int nb)
{
	mlx_pixel_put(mlx->mlx, mlx->win, (x - y) * (offset), (y + x) * (offset / 2) - (nb), color);
}

void	mlx_draw_line_x(t_mlx *mlx, int x, int y,int color, int offset, int nb, int d)
{
	mlx_pixel_put(mlx->mlx, mlx->win, (x - y) * (offset) + d, (y + x) * (offset / 2) + (d / 2) - (nb), color);
}

void	mlx_draw_line_y(t_mlx *mlx, int x, int y,int color, int offset, int nb, int d)
{
	mlx_pixel_put(mlx->mlx, mlx->win, (x - y) * (offset) - d, (y + x) * (offset / 2) + (d / 2) - (nb), color);
}

void	ft_fdf(t_mlx *mlx ,char **argv)
 {
	char	*line;
	char	**current_l;
	char	**next_l;
	int		fd;
	int		x;
	int		y;
	int		i;
	int		d;

	fd = open(argv[1], O_RDONLY);
	y = 0;
	current_l = NULL;
	next_l = NULL;
	if (get_next_line(fd, &line))
		next_l = ft_strsplit(line, ' ');
	else
		next_l = NULL;

	while (next_l)
	{
		if (next_l)
			current_l = next_l;
		if (get_next_line(fd, &line) > 0)
			next_l = ft_strsplit(line, ' ');
		else
			next_l = NULL;

		x = mlx->offset / 2;
		i = 0;

		while(current_l[i])
		{
			if (ft_atoi(current_l[i]) != 0)
			{
				mlx_draw_point(mlx, x, y , 0X00BA3733, mlx->offset, ft_atoi(current_l[i]));
					d = 1;
					while (d < mlx->offset)
					{
						if(ft_atoi(current_l[i + 1]) == 10)
							mlx_draw_line_x(mlx, x , y , 0X00BA3733, mlx->offset, ft_atoi(current_l[i]), d);
						if(next_l && ft_atoi(next_l[i]) == ft_atoi(current_l[i]))
							mlx_draw_line_y(mlx, x , y , 0X00BA3733, mlx->offset, ft_atoi(current_l[i]), d);
						d++;
					}
			}
			else
			{
				mlx_draw_point(mlx, x, y , 0X00FFFFFF, mlx->offset, ft_atoi(current_l[i]));
				
				
				d = 1;
				while (d < mlx->offset)
				{
					if(current_l[i + 1])
					{
						if(ft_atoi(current_l[i + 1]) == 10)
							mlx_pixel_put(mlx->mlx, mlx->win, (x - y) * (mlx->offset) + d, ((y + x ) * ((mlx->offset) / 2) + ft_atoi(current_l[i])), 0X00FFFFF);
						else
							mlx_draw_line_x(mlx, x , y , 0X00FFFFFF, mlx->offset, ft_atoi(current_l[i]), d);
					}
					if(next_l)
					{
						//if(ft_atoi(next_l[i]) == 10)
						//	mlx_pixel_put(mlx->mlx, mlx->win, (x - y) * (mlx->offset) - d, (y + x ) * ((mlx->offset) / 2) + ( ft_atoi(current_l[i]) / 2) - (ft_atoi(current_l[i])) , 0X00FFFFF);

						mlx_draw_line_y(mlx, x , y , 0X00FFFFFF, mlx->offset, ft_atoi(current_l[i]), d);
					}
					d++;
				}
			}
			x++;
			i++;
		}
		y++;
	}
}

t_mlx	*ft_mlx_init()
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx *));
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, 2000, 2000, "FDF by Afxsoft");
	mlx->offset = 40;
	return (mlx);
}


int		main (int argc, char **argv)
{
	t_mlx	*mlx;
	
	mlx = ft_mlx_init();
	ft_fdf(mlx, argv);
	printf("Fuck tha police");
	argc = 0;
	printf("Fuck tha police");
	mlx_key_hook(mlx->win, mlx_key_press, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
