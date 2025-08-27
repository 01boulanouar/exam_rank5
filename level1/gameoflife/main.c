/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 20:05:41 by moboulan          #+#    #+#             */
/*   Updated: 2025/08/27 21:48:43 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_of_life.h"

int main(int argc, char **argv)
{

    if (argc == 4)
        game_of_life(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
    return (0);
}