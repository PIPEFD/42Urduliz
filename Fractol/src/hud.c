/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:34:14 by codespace         #+#    #+#             */
/*   Updated: 2024/01/06 09:56:56 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static inline void hud_mouse(t_env *env)
{
    mlx_string_put(env->mlx, env->win, 15, 10, C_UI, "Mouse -->");
    mlx_string_put(env->mlx, env->win, 95, 10, C_UI,
            (env->motion_on == 1) ? "ON" : "OFF");
}


static inline void hud_value(t_env *env, int value, char *str, int pos)
{
    char    *val;
    int      xv;
    int         yv;
    
    yv = 10 + pos * 20;;
    xv = 15 + ft_strlen(str) * 10;
    if (!(val=ft_itoa(value)))
        return;
    mlx_string_put(env->mlx, env->win, 15, yv, C_UI, str);
    mlx_string_put(env->mlx, env->win, xv, yv, C_UI, val);
}

static inline void hud_dvalue(t_env *env, double value, char *str, int pos)
{
    char    *val;
    int      xv;
    int         yv;
    
    yv = 10 + pos * 20;;
    xv = 15 + ft_strlen(str) * 10;
    if (!(val=ft_dtoa(value, DTOA_DSCP)))
        return;
    mlx_string_put(env->mlx, env->win, 15, yv, C_UI, str);
    mlx_string_put(env->mlx, env->win, xv, yv, C_UI, val);
}
static inline void hud_help(t_env *env)
{
    env->hud_cmd--;
    mlx_string_put(env->mlx, env->win, VP_WIDTH - 350, 10, C_UI, CMD_1);
    mlx_string_put(env->mlx, env->win, VP_WIDTH - 350, 30, C_UI, CMD_2);
    mlx_string_put(env->mlx, env->win, VP_WIDTH - 350, 50, C_UI, CMD_3);
    mlx_string_put(env->mlx, env->win, VP_WIDTH - 350, 70, C_UI, CMD_4);
    mlx_string_put(env->mlx, env->win, VP_WIDTH - 350, 90, C_UI, CMD_5);
    mlx_string_put(env->mlx, env->win, VP_WIDTH - 350, 110, C_UI, CMD_6);
    mlx_string_put(env->mlx, env->win, VP_WIDTH - 350, 130, C_UI, CMD_7);
    
}


void    show_hud(r_env *env, int time_frame)
{
    int local_ac;
    if (env->hud_cmd > 0)
        hud_help(env);
    if (env ->hud_on)
    {
        local_ac = env->argc
        hud_mouse(env)
        hud_value(env, env->d.type, "Fractal :", 1);
        hud_value(env, env->d.iter_max "Interation :", 2);
        hud_value(env, env->type_palette, "Palette : ", 3);
        hud_value(env, time_frame, "Time(ms) : ", 4);
        hud_dvalue(env,  env->d.c_r, "c_r" , 5);
        hud_dvalue(env, env->d.c.i, "c_i : ", 6);
        hud_dvalue(env,  env->d.x1, "X1: ", 8);
        hud_dvalue(env,  env->d.x2, "X2: ", 9);
        hud_dvalue(env,  env->d.y1, "Y1: ", 10);
        hud_dvalue(env,  env->d.y2, "Y2: ", 11);
        hud_dvalue(env,  env->d.step, "STEP: ", 12);
        while (--local_ac >= 0)
            hud_value (env, local_ac, env->argv[local_ac], 12 + local_ac);
        return ;
    }
    mlx_string_put(env->mlx, env->win, 15, VP_HEIGHT - 30, C_UI, UHELP);
}