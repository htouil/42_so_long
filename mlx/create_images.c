/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:32:10 by htouil            #+#    #+#             */
/*   Updated: 2023/04/24 20:32:12 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_floor_onmap(t_axe *axe, int i, int j)
{
	int		x;
	int		y;

	x = 32;
	y = 32;
	axe->win.mlx_img = mlx_xpm_file_to_image(axe->win.mlx, FLOOR_PATH, &x, &y);
	if (!axe->win.mlx_img)
	{
		write (1, "Error\nThe xpm file is invalid!\n", 31);
		exit (1);
	}
	mlx_put_image_to_window(axe->win.mlx, axe->win.mlx_win, axe->win.mlx_img,
		i * x, j * y);
	mlx_destroy_image(axe->win.mlx, axe->win.mlx_img);
}

void	put_wall_onmap(t_axe *axe, int i, int j)
{
	int		x;
	int		y;

	x = 32;
	y = 32;
	axe->win.mlx_img = mlx_xpm_file_to_image(axe->win.mlx, WALL_PATH, &x, &y);
	if (!axe->win.mlx_img)
	{
		write (1, "Error\nThe xpm file is invalid!\n", 31);
		exit (1);
	}
	mlx_put_image_to_window(axe->win.mlx, axe->win.mlx_win, axe->win.mlx_img,
		i * x, j * y);
	mlx_destroy_image(axe->win.mlx, axe->win.mlx_img);
}

void	put_collectible_onmap(t_axe *axe, int i, int j)
{
	int		x;
	int		y;

	x = 32;
	y = 32;
	axe->win.mlx_img = mlx_xpm_file_to_image(axe->win.mlx, COLECT_PATH, &x, &y);
	if (!axe->win.mlx_img)
	{
		write (1, "Error\nThe xpm file is invalid!\n", 31);
		exit (1);
	}
	mlx_put_image_to_window(axe->win.mlx, axe->win.mlx_win, axe->win.mlx_img,
		i * x, j * y);
	mlx_destroy_image(axe->win.mlx, axe->win.mlx_img);
}

void	put_player_onmap(t_axe *axe, int i, int j)
{
	int		x;
	int		y;

	x = 32;
	y = 32;
	axe->win.mlx_img = mlx_xpm_file_to_image(axe->win.mlx, PLAYER_PATH, &x, &y);
	if (!axe->win.mlx_img)
	{
		write (1, "Error\nThe xpm file is invalid!\n", 31);
		exit (1);
	}
	mlx_put_image_to_window(axe->win.mlx, axe->win.mlx_win, axe->win.mlx_img,
		i * x, j * y);
	mlx_destroy_image(axe->win.mlx, axe->win.mlx_img);
}

void	put_exit_onmap(t_axe *axe, int i, int j)
{
	int		x;
	int		y;

	x = 32;
	y = 32;
	axe->win.mlx_img = mlx_xpm_file_to_image(axe->win.mlx, EXIT_PATH, &x, &y);
	if (!axe->win.mlx_img)
	{
		write (1, "Error\nThe xpm file is invalid!\n", 31);
		exit (1);
	}
	mlx_put_image_to_window(axe->win.mlx, axe->win.mlx_win, axe->win.mlx_img,
		i * x, j * y);
	mlx_destroy_image(axe->win.mlx, axe->win.mlx_img);
}
