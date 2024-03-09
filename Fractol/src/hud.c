/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipefd <pipefd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:34:14 by codespace         #+#    #+#             */
/*   Updated: 2024/03/07 17:28:52 by pipefd           ###   ########.fr       */
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
    mlx_string_put(env->mlx, env->win, WIDTH - 350, 10, C_UI, CMD_1);
    mlx_string_put(env->mlx, env->win, WIDTH - 350, 30, C_UI, CMD_2);
    mlx_string_put(env->mlx, env->win, WIDTH - 350, 50, C_UI, CMD_3);
    mlx_string_put(env->mlx, env->win, WIDTH - 350, 70, C_UI, CMD_4);
    mlx_string_put(env->mlx, env->win, WIDTH - 350, 90, C_UI, CMD_5);
    mlx_string_put(env->mlx, env->win, WIDTH - 350, 110, C_UI, CMD_6);
    mlx_string_put(env->mlx, env->win, WIDTH - 350, 130, C_UI, CMD_7);
    
}


