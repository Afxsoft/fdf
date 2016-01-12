/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouloube <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 14:56:56 by aouloube          #+#    #+#             */
/*   Updated: 2016/01/12 18:57:18 by aouloube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "libft/includes/libft.h"


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
	y = 200;
	while (get_next_line(fd, &line))
	{
	 	l2 = ft_strsplit(line, ' ');
		x = 50;
		i = 0;

		while(l2[i])
		{
			if (ft_atoi(l2[i]) == 10)
			{
				mlx_pixel_put(mlx->mlx, mlx->win, x, y, 0X00BA3733);
				if (ft_atoi(l2[i + 1]) == 10)
				{
					d  = 50;
					while (d--)
					{
						mlx_pixel_put(mlx->mlx, mlx->win, x + d, y, 0X00BA3733);
						mlx_pixel_put(mlx->mlx, mlx->win, x , y + d, 0X00BA3733);
					}
				}
				d = 50;
				while (d--)
				{
					mlx_pixel_put(mlx->mlx, mlx->win, x , y + d, 0X00BA3733);
				}
			
			}
			else
			{
				mlx_pixel_put(mlx->mlx, mlx->win, x, y, 0X00FFFFFF);
			
			d  = 50;
			while (d--)
			{
				mlx_pixel_put(mlx->mlx, mlx->win, x + d, y, 0X00FFFFFF);
				mlx_pixel_put(mlx->mlx, mlx->win, x , y + d, 0X00FFFFFF);
			}}
			x+= 50;
			i++;
		}

		y+=50;
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
