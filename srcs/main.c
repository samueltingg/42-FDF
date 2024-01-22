/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:00:19 by sting             #+#    #+#             */
/*   Updated: 2024/01/22 15:58:04 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/fdf.h"

// void parsing(int fd)
// {
//     int y;
// }

int main(int argc, char **argv)
{
    int fd;

    if (argc < 2)
    {
        ft_putstr_fd("Usage : ./fdf <filename>\n", 2);
        return (1);
    }
    fd = open((const char *)argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }
}