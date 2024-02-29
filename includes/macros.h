/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:02:32 by sting             #+#    #+#             */
/*   Updated: 2024/02/29 15:37:12 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# define WINDOW_WIDTH 1600
# define WINDOW_HEIGHT 900
# define MLX_ERROR 1
# define TRUE 1
# define FALSE 0
# define PI 3.14159

// EVENT CODES
#  define ON_KEYDOWN 2 // mac only :()
#  define ON_KEYUP 3
#  define ON_MOUSEDOWN 4
#  define ON_MOUSEUP 5
#  define ON_MOUSEMOVE 6
#  define ON_EXPOSE 12
#  define ON_DESTROY 17

// KEYCODES
#ifdef __APPLE__  // MacOS
    #  define KEY_ESC 53
    #  define KEY_UP 126
    #  define KEY_DOWN 125
    #  define KEY_LEFT 123
    #  define KEY_RIGHT 124
    #  define KEY_MINUS 27
    #  define KEY_PLUS 24
    #  define KEY_W 13
    #  define KEY_S 1
    #  define KEY_A 0
    #  define KEY_D 2
    #  define KEY_R 15
    #  define KEY_I 34
    #  define KEY_J 38
    #  define KEY_L 37
    #  define KEY_Z 6
    // Reference: https://github.com/izenynn/fdf/blob/main/inc/fdf.h
#elif __linux__
    #  define KEY_ESC 65307
    #  define KEY_UP 65362
    #  define KEY_DOWN 65364
    #  define KEY_LEFT 65361
    #  define KEY_RIGHT 65363
    #  define KEY_MINUS 45
    #  define KEY_PLUS 61
    #  define KEY_W 119
    #  define KEY_S 115
    #  define KEY_A 97
    #  define KEY_D 100
    #  define KEY_J 106
    #  define KEY_L 108
    #  define KEY_P 112
    #  define KEY_R 114
    #  define KEY_U 117
    #  define KEY_I 105
    #  define KEY_K 107
    #  define KEY_O 111
    #  define KEY_Z 122
    #  define KEY_MINUS 45
    #  define KEY_PLUS 61

#else
    #error Unsupported operating system
#endif

// COLORS
#define WHITE_PIXEL 0xFFFFFF
#define RED_PIXEL   0xFF0000
#define GREEN_PIXEL 0x00FF00
#define BLUE_PIXEL  0x0000FF
#define PURPLE_PIXEL 0x9900FF


#endif
