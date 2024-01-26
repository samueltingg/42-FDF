/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:02:32 by sting             #+#    #+#             */
/*   Updated: 2024/01/26 11:51:56 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 800
# define MLX_ERROR 1


// Reference: https://github.com/izenynn/fdf/blob/main/inc/fdf.h

#ifdef __APPLE__  // Check if compiling on macOS
    // Code specific to macOS
    #  define KEY_DOWN 2
    #  define KEY_UP 3
    #  define MOUSE_DOWN 4
    #  define MOUSE_UP 5
    #  define MOUSE_MOVE 6
    #  define EXPOSE 12
    #  define DESTROY 17
#elif __linux__   // Check if compiling on Linux
    // Code specific to Linux
    #  define KEY_ESC 65307
    #  define KEY_UP 65362
    #  define KEY_DOWN 65364
    #  define KEY_LEFT 65361
    #  define KEY_RIGHT 65363
    #  define KEY_W 119
    #  define KEY_S 115
    #  define KEY_A 97
    #  define KEY_D 100
    #  define KEY_P 112
    #  define KEY_MINUS 45
    #  define KEY_PLUS 61
    #  define KEY_R 114
    #  define KEY_U 117
    #  define KEY_J 106
    #  define KEY_I 105
    #  define KEY_K 107
    #  define KEY_O 111
    #  define KEY_L 108
#else
    #error Unsupported operating system
#endif


#endif