/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouloube <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 14:56:56 by aouloube          #+#    #+#             */
/*   Updated: 2016/02/04 17:59:43 by aouloube         ###   ########.fr       */
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

void	mlx_draw_line(t_mlx *mlx, int x, int y,int color, int offset, int nb, int d)
{
	mlx_pixel_put(mlx->mlx, mlx->win, (x - y) * (offset) + d, (y + x) * (offset / 2) + (d / 2) - (nb), color);
	mlx_pixel_put(mlx->mlx, mlx->win, (x - y) * (offset) - d, (y + x) * (offset / 2) + (d / 2) - (nb), color);
}

void	ft_fdf(t_mlx *mlx ,char **argv)
 {
	char	*line;
	char	**l2;
	int		fd;
	int		x;
	int		y;
	int		i;
	int		d;

	fd = open(argv[1], O_RDONLY);
	y = 0;

	while (get_next_line(fd, &line))
	{
		//mlx->current_l = (!mlx->current_l) ? ft_strsplit(line, ' ') : mlx->next_l;
		mlx->current_l = ft_strsplit(line, ' ');
		l2 = mlx->current_l;
		//if(get_next_line(fd, &line))
		//{
			//mlx->next_l = ft_strsplit(line, ' ');
		//}
		x = mlx->offset / 2;
		i = 0;

		while(l2[i])
		{
			if (ft_atoi(l2[i]) != 0)
			{
				mlx_draw_point(mlx, x, y , 0X00BA3733, mlx->offset, ft_atoi(l2[i]));
				if (ft_atoi(l2[i + 1]) == 10)
				{
					d = 1;
					while (d < mlx->offset)
					{
						mlx_draw_line(mlx, x , y , 0X00BA3733, mlx->offset, ft_atoi(l2[i]), d);
						d++;
					}
				}
			}
			else
			{
				mlx_draw_point(mlx, x, y , 0X00FFFFFF, mlx->offset, ft_atoi(l2[i]));
				
				if(ft_strstr(l2[i + 1], "\0"))
				{
					d = 1;
					while (d < mlx->offset)
					{
						mlx_draw_line(mlx, x , y , 0X00FFFFFF, mlx->offset, ft_atoi(l2[i]), d);
						d++;
					}
				}
			}
			x++;
			i++;
		}
		y++;
	}
	mlx->current_l = NULL;
	//mlx->next_l = NULL;
}

t_mlx	*ft_mlx_init()
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx *));
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, 1000, 1000, "FDF by Afxsoft");
	mlx->offset = 30;
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
