/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 05:47:04 by amyburgh          #+#    #+#             */
/*   Updated: 2018/08/13 16:38:37 by amyburgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stddef.h>
# define WIN_X	1920
# define WIN_Y	1080
# define BD		10
# define IMG1_X	WIN_X
# define IMG1_Y	WIN_Y
# define IMG2_X	800
# define IMG2_Y	150

# define MCHECK(x) if (x) return (1)

# define COLOR_MSG "COLOR PICKER:"
# define ADJUST "HEIGHT ADJUST:"
# define RESET ">>> RESET <<<"
# define RAD(x) (x * M_PI / 180)

# define WHITE 0xffffff
# define BLACK 0x000000
# define RED 0xff0000
# define GREEN 0x00ff00
# define BLUE 0x0000ff
# define YELLOW 0xffff00
# define PINK 0xff00ff
# define AQUA 0x00ffff
# define GREY 0xc6c6c6

typedef struct	s_line
{
	int			i;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			d;
	int			d1;
	int			d2;
	int			color;
}				t_line;

typedef	struct	s_point
{
	double		x;
	double		y;
	double		z;
}				t_point;

typedef struct	s_circle
{
	int			x;
	int			y;
	int			r;
}				t_circle;

typedef	struct	s_calc
{
	int			i;
	double		x;
	double		y;
	double		z;
	double		cx;
	double		cy;
	double		cz;
	double		sx;
	double		sy;
	double		sz;
	double		dx;
	double		dy;
	double		dz;
}				t_calc;

typedef	struct	s_map
{
	char		*title;
	int			width;
	int			height;
	int			step;
	int			start_x;
	int			start_y;
	t_point		**tab;
}				t_map;

typedef	struct	s_cam
{
	double		ex;
	double		ey;
	double		ez;
	double		cx;
	double		cy;
	double		cz;
	double		ax;
	double		ay;
	double		az;
	double		adj;
	double		scale;
	double		n;
}				t_cam;

typedef	struct	s_mouse
{
	int			active;
	double		adj;
	int			button;
	int			x;
	int			y;
	int			oldx;
	int			oldy;
	int			color;
}				t_mouse;

typedef struct	s_image
{
	void		*ptr;
	int			bpp;
	int			size_line;
	char		*data;
	int			endian;
}				t_image;

typedef struct	s_image_m
{
	void		*ptr;
	int			width;
	int			height;
}				t_image_m;

typedef	struct	s_rt
{
	void		*mlx;
	void		*win;
	char		*data;
	int			*colors;
	t_map		*map;
	t_cam		*cam;
	t_mouse		*mouse;
	t_point		**buttons;
	t_image		*img1;
	t_image		*img2;
	t_image_m	*img_m;
	t_image_m	*img_a;
}				t_rt;

/*
** ----- main.c -----
*/
int				main(int argc, char **argv);
/*
** ----- input.c -----
*/
t_map			*read_file(int fd, char *title, t_map *map);
/*
** ----- validate.c -----
*/
size_t			validate_map(char *str);
size_t			map_width(char *str);
/*
** ----- window.c -----
*/
void			display_info(t_rt *root);
void			window_border(t_rt *root);
int				create_images(t_rt *root);
int				create_window(t_rt *root);
/*
** ----- initialize.c -----
*/
void			init_map(t_map *map);
void			init_cam(t_cam *cam);
void			init_mouse(t_mouse *mouse);
int				init_all(t_rt *root);
/*
** ----- render.c -----
*/
int				render(t_rt *root);
/*
** ----- hooks.c -----
*/
int				key_press(int key, t_rt *root);
int				mouse_press(int button, int x, int y, t_rt *root);
int				mouse_release(int button, int x, int y, t_rt *root);
int				mouse_motion(int x, int y, t_rt *root);
/*
** ----- draw_map.c -----
*/
void			draw_map(t_map *map, t_rt *root, int color);
void			zoom(t_rt *root, int button);
void			translate(t_rt *root);
/*
** ----- utilities.c -----
*/
void			ft_tabdel(void **tab, size_t rows);
/*
** ----- draw_line.c -----
*/
void			draw_line_img(t_image *img, t_point *p0,
				t_point *p1, int color);
/*
** ----- draw_circle.c -----
*/
void			draw_circle(t_image *img, t_circle *pt, int color);
/*
** ----- image.c -----
*/
void			clear_image(t_image *img, int n);
void			pixel_put_image(t_image *img, int x, int y, int color);
void			image_pallet(t_image *img, int *colors);
/*
** ----- pallet.c -----
*/
void			pixel_put_circle(t_image *img, t_line *p, int color);
void			color_select(t_rt *root, int x, int y);
/*
** ----- buttons.c -----
*/
void			rotation_select(t_cam *cam, t_mouse *mouse);
void			rotation_adj(t_cam *cam, t_mouse *mouse);
void			draw_control(t_rt *root);
void			perspective_calc(t_map *map, t_cam *cam, int i);
#endif
