#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BYTES_PER_LINE 16

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    unsigned char buffer[BYTES_PER_LINE];
    size_t bytesRead;
    unsigned long offset = 0;

    while ((bytesRead = fread(buffer, 1, BYTES_PER_LINE, file)) > 0) {
        printf("%081x ", offset);

        for (size_t i = 0; i < BYTES_PER_LINE; i++) {
            if (i < bytesRead) {
                printf("%02x ", buffer[i]);
            } else {
                printf("  ");
            }
        }

        printf("|");

        for (size_t i = 0; i < bytesRead; i++) {
            if (isprint(buffer[i])) {
                printf("%c", buffer[i]);
            } else {
                printf(".");
            }
        }

        printf("|\n");

        offset += bytesRead;
    }

    fclose(file);
    return 0;
}