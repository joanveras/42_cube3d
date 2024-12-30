#ifndef STRUCTS_H
# define STRUCTS_H

typedef enum e_hook_events
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
}	t_hook_events;

typedef struct s_img_data
{
	void	*img;
	int		width;
	int		height;
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
}	t_img_data;

typedef struct s_texture_data
{
	void	*tex;
	int		width;
	int		height;
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
}	t_texture_data;

typedef struct s_player
{
	double	x;
	double	y;
	double	viewDirX;
	double	viewDirY;
}	t_player;

typedef struct s_camera
{
	double	x;
	double	planeX;
	double	planeY;
}	t_camera;

typedef struct s_raycasting
{
	t_camera	camera;
	double		rayDirX;
	double		rayDirY;
	double		sideDistX;
	double		sideDistY;
	double		deltaDistX;
	double		deltaDistY;
	double		perpWallDist;
}	t_raycasting;

typedef struct s_step
{
	int	x;
	int	y;
}	t_step;

typedef struct s_map
{
	char	**map;
	int		x;
	int		y;
	t_step	step;
}	t_map;

typedef struct s_program
{
	void			*mlx;
	void			*mlx_win;
	t_img_data		image;
	t_texture_data	texture;
	t_player		player;
	t_raycasting	raycast;
	t_map			map;
}	t_program;

#endif