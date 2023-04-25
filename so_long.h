/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:25:24 by htouil            #+#    #+#             */
/*   Updated: 2023/04/24 19:25:25 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//libraries
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>

//gnl buffer size:
# define BUFFER_SIZE 100

//texture paths:
# define FLOOR_PATH "./textures/floor_black_cobalt.xpm"
# define WALL_PATH "textures/wall_hell_eye.xpm"
# define COLECT_PATH "textures/item_flying_skull.xpm"
# define PLAYER_PATH "textures/player_sphinx.xpm"
# define EXIT_PATH "textures/door_hell.xpm"

//keycodes:
# define MU 13
# define MD 1
# define MR 2
# define ML 0
# define ESC 53

//structures:
typedef struct s_win
{
	void	*mlx;
	void	*mlx_win;
	void	*mlx_img;
	int		len;
	int		wid;
}		t_win;

typedef struct s_axe
{
	int		rows;
	int		columns;
	char	**matrix;
	int		e_x;
	int		e_y;
	int		check_c;
	int		check_e;
	int		check_p;
	int		mv_count;
	t_win	win;
}			t_axe;

//get_next_line functions:
char	*get_next_line(int fd);
char	*ft_strjoin(char *str1, char *str2);
int		ft_strlen(char *str);
int		ft_strchr_nl(char *searched);

//libft functions:
char	*ft_itoa(int n);
char	**ft_split(char *s, char c);

//so_long functions:
void	get_map_matrix(int fd, t_axe *axe);
int		check_map_extension(char *str);
int		check_double_nl(char *map_str);
int		check_map_frame1(t_axe *axe);
int		check_map_frame2(t_axe *axe);
int		check_map_content(t_axe *axe);
int		check_map_collectibles(t_axe *axe);
int		check_map_player(t_axe *axe);
int		check_map_exit(t_axe *axe);
int		check_tmp_collectibles(char **tmp, t_axe *axe);
int		check_tmp_exit(char **tmp, t_axe *axe);
int		check_map_path1(t_axe *axe);
void	free_tmp(char **tmp, t_axe *axe);
void	display_map_errors0(char *arg);
void	display_map_errors1(t_axe *axe);
void	display_map_errors2(t_axe *axe);
void	display_moves(t_axe *axe);

//mlx functions:
void	put_floor_onmap(t_axe *axe, int i, int j);
void	put_wall_onmap(t_axe *axe, int i, int j);
void	put_collectible_onmap(t_axe *axe, int i, int j);
void	put_player_onmap(t_axe *axe, int i, int j);
void	put_exit_onmap(t_axe *axe, int i, int j);
void	put_images_onmap(t_axe *axe);
void	move_right(t_axe *axe);
void	move_down(t_axe *axe);
void	move_left(t_axe *axe);
void	move_up(t_axe *axe);
int		put_keycode(int key, t_axe *axe);
int		destroy_game(t_axe *axe);

#endif
