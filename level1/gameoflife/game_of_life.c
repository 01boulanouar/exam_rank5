/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_of_life.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 20:09:15 by moboulan          #+#    #+#             */
/*   Updated: 2025/08/27 21:59:18 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_of_life.h"

void free_board(char **board, int height)
{
    int h = 0;
    while (h < height)
    {
        free(board[h]);
        h++;
    }
    free(board);
}

void print_board(char **board, int width, int height)
{
    int h = 0;
    while (h < height)
    {
        int w = 0;
        while (w < width)
        {
            putchar(board[h][w]);
            w++;
        }
        putchar('\n');
        h++;
    }
}

char **create_board(int width, int height)
{
    char **board = malloc(sizeof(char *) * (height + 1));

    for (int h = 0; h < height; h++)    
    {
        board[h] = malloc(sizeof(char) * (width + 1));
        
        int w; 
        for (w = 0; w < width; w++)
            board[h][w] = ' ';
  
        board[h][w] = '\0';
    }

    return (board);
}

char **add_cells( int width, int height)
{
    char **board = create_board(width, height);
    int h = 0;
    int w = 0;
    int drawing = 0;
    char c;

    while (read(STDIN_FILENO, &c, 1) > 0)
    {
        if (c == 'x')
            drawing = !drawing;
        else if (c == 'w' && h > 0)
            h--;
        else if (c == 's' && h < height - 1)
            h++;    
        else if (c == 'd' && w < width - 1)
            w++;
        else if (c == 'a' && w > 0)
            w--;
    
        if (drawing)
            board[h][w] = '0';      
    }
        return (board);
}


int count_cells(char **board, int width, int height, int w, int h)
{
    int count = 0;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (i == 0 && j == 0)
                continue;

            int pos_h = h + i;
            int pos_w = w + j;

            if (0 <= pos_h && pos_h < height
                && 0 <= pos_w && pos_w < width
                && board[pos_h][pos_w] == '0')
                    count++;
        }
    }
    return (count);
}

char **update_board(char **board, int width, int height)
{
    char **new_board = create_board(width, height);

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            int cells = count_cells(board, width, height, w, h);

            int is_alive = (board[h][w] == '0');
            if (is_alive && (cells == 2 || cells == 3))
                new_board[h][w] = '0';
            else if (!is_alive && cells == 3)
                new_board[h][w] = '0';
        }
    }
    free_board(board, height);
    return (new_board);
}

void game_of_life(int width, int height, int iterations)
{
    char **board;
    board = add_cells(width, height);
    while(iterations)
    {
        board = update_board(board, width, height);
        iterations--;
    }
    print_board(board, width, height);
    free_board(board, height);
}
