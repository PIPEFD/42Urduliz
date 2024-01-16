/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:10:01 by codespace         #+#    #+#             */
/*   Updated: 2024/01/06 12:38:34 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static inline void zoom_on_cursor(t_fractal *data, int value, int x, int y )
{
    TYPE_Z toby[4];

    data->reiter = 0;
    x -=VP_WIDTH / 2 ;
    y -= VP_HEIGHT / 2;
    toby[0] = -x * data->step;
    toby[1] = -y * data->step;
    toby[2] = (data->x2 - data-> x1) / value;
    toby[3] = (data->y2 - data-> y1) / value;
    data -> x1 += toby[2];
    data -> x2 -= toby[2];
    data->step = (data->x2 - data->x1) /(VP_WIDTH - 1);
    toby[0] += x *data->step;
    toby[1] += y * data->step;
    data-> x1 -= toby[0]
    data-> x1 -= toby[0]
    data-> x1 -= toby[3] -toby[1];
    data-> x1 -= toby[3] + toby[1];
    data->changed  = 1
    
    
}


int deal_mouse (int mouse_code, int x,  int y, t_env *env)
{
    if (env->d.type % 2  ==  MANDEL && mouse_code == 1)
    {
        env->motion_on = 1;
        mouse_motion(x, y, env);
        env->motion_on = 0;
        if (env->d.type == MANDEL)
            set_julia(&env->d, JULIA);
        if (env->d.type == BURNING)
            set_julia(&env->d, MANDELBROT);
        if (env->d.type == KOCH)
            set_julia(&env->d, MANDELBROT);        
    }
    else if (mouse_code ==  5)
        zoom_on_cursor(&env->d, 25, x, y);
    else if (mouse coude == 4)
        zoom_on_cursor(&env->, -25, x, y);
    else if (DEBUG)
        ft_print_value("\n Mouse event",  mouse_code);
    return (0);
}

inline int mouse_motion(int x, int y, t_env *env)
{
    if (x !=  env ->old_x_mouse || y != env->old_y_mouse)
    {
        env->d.reiter = 0;
        env->old_x_mouse = x;
        env->d.c_r = env->d.x1 + x * env->d.step;
        env->d.c_i = env->d.y1 + y  * env->d.step;
        env->d.changed = 1;
    }
    return (0);
}