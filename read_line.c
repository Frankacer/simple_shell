#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * read_line - read user input from stdin using getline
 * @cmd_buff: pointer to a buffer for storing user input
 * Return: returns number of char read on success, -1 on failure.
 */
ssize_t read_line(char **cmd_buff) {
    ssize_t read_chars;
    size_t buffer_size = 0;

    read_chars = getline(cmd_buff, &buffer_size, stdin);

    if (read_chars == -1)
        return read_chars;    
    else if ((*cmd_buff)[read_chars - 1] == '\n')
    {
        (*cmd_buff)[read_chars - 1] = '\0';
        read_chars--;
    }

    return read_chars;
}
