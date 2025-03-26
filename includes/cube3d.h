/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:51:52 by jveras            #+#    #+#             */
/*   Updated: 2025/03/26 19:20:20 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

# include "structs.h"

# include <math.h>

# define ESC 65307

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600

# define textureWidth 64
# define textureHeight 64

# define MOVE_SPEED 0.08
# define ROT_SPEED 0.05

# define TEXTURE_WEST 0
# define TEXTURE_EAST 1
# define TEXTURE_NORTH 2
# define TEXTURE_SOUTH 3

# define INVALID_PATH "Invalid Texture path\n"
# define INVALID_FORMAT "Invalid Color format\n"


/*
	File validations
*/
void	validate_map(t_program *program);
void	is_a_file(t_program *program, char *path);
void	check_directions( t_program *program, int *i );
void	check_file_extension( t_program *program, char *line );
void	error_message( t_program *program, const char *message );
void	check_path( t_program *program, char c1, char c2, char *line );
void	check_abbrev( t_program *program, char *line, int *dir_counter );

int		rgb_to_int(int *nums);
int		*check_colors(t_program *program, char **map, int *i);


/*
	Input Keys
*/
void	left(t_program *program, int keycode);
void	right(t_program *program, int keycode);
void	foward(t_program *program, int keycode);
void	backward(t_program *program, int keycode);

int		handle_key_inputs(int keycode, t_program *program);


/*
	Raycasting functios
*/
void	perform_dda(t_program *program, int *side);
void	calc_step_and_initial_side_dist(t_program *program);
void	calc_dist_of_perpendicular_ray(t_program *program, int side);
void	calc_where_the_wall_was_hit(t_program *program, int side, double *wallX);
void	calc_vertical_line_and_transform_image(t_program *program,
	int x, double wallX, int lineHeight, int side);
	
int		wall_casting(t_program *program);


/*
	Helper functions
*/
void	free_map(t_map *map);
void	load_img_data(t_img_data *image);
void	load_textures(t_program *program);
void	transform_c_f(t_program *program);
void	load_texture_data(t_texture_data *texture);
void	put_pixel(t_img_data *img, int x, int y, int color);
void	load_game_and_raycast_initial_info(t_program *program);
void	load_texture(void *mlx, t_texture_data *texture,char *path);
void	load_img(void *mlx, t_img_data *image, int width, int height);

int		get_texel_color(t_program *program, t_texture_data *tex,int texPosX, int texPosY);



void	x11_connect(t_program *program);

int		safe_exit(t_program *program);

char	**open_map(char *path);

#endif
