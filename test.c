/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouloube <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 15:08:16 by aouloube          #+#    #+#             */
/*   Updated: 2016/01/06 15:15:58 by aouloube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
int		main(int argc, char **argv)
{
	void *mlx;
	void *win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 420, 420, "42");
	sleep(5);
	return (0);
}
