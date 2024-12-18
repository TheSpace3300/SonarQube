#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input>\n", argv[0]);
        return 1;
    }

    FILE *secret = fopen("/challenge/app-systeme/ch5/.passwd", "rt");
    if (!secret) {
        perror("Failed to open file");
        return 1;
    }

    char buffer[32];
    if (!fgets(buffer, sizeof(buffer), secret)) {
        perror("Failed to read file");
        fclose(secret);
        return 1;
    }

    fclose(secret);

    printf("User input: %s\n", argv[1]);

    return 0;
}
