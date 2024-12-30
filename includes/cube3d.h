#ifndef CUBE3D_H
# define CUBE3D_H

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

# include "structs.h"



// Allowed ?
#include <math.h>



# define ESC 65307

# define WINDOW_WIDTH 1024
# define WINDOW_HEIGHT 720

# define textureWidth 64
# define textureHeight 64

# define MOVE_SPEED 0.05
# define ROT_SPEED 0.05

#define W 'w'
#define S 's'
#define A 'a'
#define D 'd'

void	x11_connect(t_program *program);
void	clear_image(t_img_data *img, int color);
void	put_pixel(t_img_data *img, int x, int y, int color);

int		safe_exit(t_program *program);
int		raycasting(t_program *program);
int		handle_key_inputs(int keycode, t_program *program);
int		get_texel_color(t_texture_data *tex, int texX, int texY);

char	**open_map(char *path);

#endif