/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 21:21:04 by dbonilla          #+#    #+#             */
/*   Updated: 2023/12/17 18:23:59 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <math.h>

#define WIDTH 1920
#define HEIGHT 1080

typedef struct s_complex
{
    double real;
    double imag;
} t_complex;

void draw_pixel(void *mlx_ptr, void *win_ptr, int x, int y, int color)
{
    mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
}

float fast_inverse_sqrt(float x)
{
    float xhalf = 0.5f * x;
    int i = *(int *)&x;        // interpret float as int
    i = 0x5f3759df - (i >> 1); // initial guess for Newton's method
    x = *(float *)&i;          // convert new bits into float
    x = x * (1.5f - xhalf * x * x); // One round of Newton's method
    return x;
}

int mandelbrot(t_complex c, int max_iter)
{
    t_complex z = {0, 0};
    int iter = 0;

    while (iter < max_iter && (z.real * z.real + z.imag * z.imag) < 4)
    {
        double temp = z.real * z.real - z.imag * z.imag + c.real;
        z.imag = 2 * z.real * z.imag + c.imag;
        z.real = temp;
        iter++;
    }

    return iter;
}

void draw_mandelbrot(void *mlx_ptr, void *win_ptr)
{
    int max_iter = 100; // Puedes ajustar esto según tus necesidades
    double zoom = 0.004;
    t_complex offset = {-2, -1.5};

    for (int x = 0; x < WIDTH; x++)
    {
        for (int y = 0; y < HEIGHT; y++)
        {
            t_complex c = {offset.real + x * zoom, offset.imag + y * zoom};
            int color = mandelbrot(c, max_iter);

            // Puedes ajustar la lógica de color según tus preferencias
            int r = (color % 256) << 16;
            int g = (color % 256) << 8;
            int b = (color % 256);
            draw_pixel(mlx_ptr, win_ptr, x, y, r | g | b);
        }
    }
}

int main()
{
    void *mlx_ptr = mlx_init();
    void *win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "Mandelbrot Set");

    draw_mandelbrot(mlx_ptr, win_ptr);

    mlx_loop(mlx_ptr);

    return 0;
}

/*
int main(void)
{
	void	*mlx;
	void *mlx_win;
	t_data	img;	
	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	// img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	//my_pixel_put(&img, 5, 5, 0x00FF0000);
	my_pixel_put(&img, 4, 5, 0x002D2926);
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
*/