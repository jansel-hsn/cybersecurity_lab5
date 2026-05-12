#include <stdio.h>
#include <string.h>

int main() {
    char shadow_line[] = "bob:$6$xyz123$T5x/L.C8vB/O:19000:0:99999:7:::";

    char *username = strtok(shadow_line, ":");
    char *hash = strtok(NULL, ":");

    if (username && hash) {
        printf("Target User: %s\n", username);
        printf("Target Hash: %s\n", hash);
    } else {
        printf("Parsing error!\n");
    }

    return 0;
}