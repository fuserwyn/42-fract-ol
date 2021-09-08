#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../mlx/mlx.h"

# define HEIGHT			400
# define WIDTH			700

# define RE_MIN			-2.0
# define RE_MAX			2.0
# define IM_MIN			-2.0
# define IM_MAX 		2.0
# define ITERATION		128

# define MANDELBROT		0
# define JULIA			1
# define MANDELBAR		2
# define COLOR			0xeafbcb

# define 	ERROR			-1

typedef struct s_complex
{
	double			re;
	double			im;
}					t_complex;

typedef struct s_data_image {
	void		*img;
	void		*win;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data_image;

typedef struct s_fractals
{
	double			re_min;
	double			re_max;
	double			im_min;
	double			im_max;
	double			calibration_re;
	double			calibration_im;
	t_complex		mandelbrot_c;
	int				name;
	int				color;
	int				max_iter;
	t_complex		julia_k;
	t_data_image	*data_image;
}	t_fractals;

typedef struct s_windows
{
	t_data_image	*data_image;
	void			*window;
	void			*mlx;

	t_fractals		*fractal;
}	t_windows;

void			ft_error(int error);
t_data_image	*generate_pixel(void *mlx);
t_windows		*generate_windows(int argc, char *argv[]);
void			draw_fractal(t_windows *window);
void			my_mlx_pixel_put(t_data_image *image_pixel,
					int x, int y, int color);
t_complex		init_complex(double re, double im);
double			julia(int *i, t_fractals *fractal);
double			mandelbrot(int *i, t_fractals *fractal);
int				keyboard(int key, t_windows *window);
int				zoomer(int button, int x, int y, t_windows *window);
int				closer(int keycode, t_windows *window);
double			fractal_name(int *i, t_fractals *fractal);
double			ft_pow(double x, double y);
int				ft_paint(double r, int i, t_fractals *fractal);
int				ft_strcmp(const char *s1, const char *s2);
void			select_fractal(t_fractals *fractal, int argc, char *argv[]);
void			shifter(int key, t_windows *window);
double			ft_atof(const char *str);
int				ft_strcmp(const char *s1, const char *s2);
t_fractals		*generate_fractal(int argc, char *argv[]);
double			mandelbar(int *i, t_fractals *fractal);
void			part_of_draw_fractal(t_windows *window, int x, int y);
void			hooks(t_windows *windows, char *argv[]);
void			string_navigation(t_windows *navigation);
int				mouse_hook(int x, int y, t_windows *window);
int				motion(int x, int y, t_windows *window);

#endif