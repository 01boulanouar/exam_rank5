/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_of_life.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 20:08:05 by moboulan          #+#    #+#             */
/*   Updated: 2025/08/27 21:48:18 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_OF_LIFE_H

# define GAME_OF_LIFE_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void game_of_life(int width, int height, int iterations);

# endif