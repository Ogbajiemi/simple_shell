#include <unistd.h>
#include "shell.h"

#define BUFFER_SIZE 1024

char* custom_getline() {
    static char buffer[BUFFER_SIZE];
    static size_t buffer_pos = 0;
    static ssize_t buffer_size = 0;

    char* line = NULL;
    size_t line_size = 0;

    while (1) {
        if (buffer_pos >= buffer_size) {
            buffer_size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
            buffer_pos = 0;

            if (buffer_size <= 0) {
                if (line_size > 0)
                    break;

                return NULL;
            }
        }

        char c = buffer[buffer_pos++];
        if (c == '\n')
            break;

        line = realloc(line, line_size + 1);
        line[line_size++] = c;
    }

    if (line_size > 0) {
        line = realloc(line, line_size + 1);
        line[line_size] = '\0';
    }

    return line;
}
