#include <stdio.h>
#include <string.h>
#include <crypt.h>

int try_dictionary(const char *target_hash, const char *dict_file, char *found_password) {
    FILE *file = fopen(dict_file, "r");

    if (!file) {
        printf("Error opening dictionary file!\n");
        return 0;
    }

    char word[256];

    while (fgets(word, sizeof(word), file)) {
        word[strcspn(word, "\n")] = 0;

        char *computed_hash = crypt(word, target_hash);

        if (strcmp(computed_hash, target_hash) == 0) {
            strcpy(found_password, word);
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

int try_pin(const char *target_hash, char *found_password) {
    char guess[5];

    for (int i = 0; i <= 9999; i++) {
        sprintf(guess, "%04d", i);

        char *computed_hash = crypt(guess, target_hash);

        if (strcmp(computed_hash, target_hash) == 0) {
            strcpy(found_password, guess);
            return 1;
        }
    }

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s shadow.txt dictionary.txt\n", argv[0]);
        return 1;
    }

    FILE *shadow = fopen(argv[1], "r");

    if (!shadow) {
        printf("Error opening shadow file!\n");
        return 1;
    }

    char line[512];

    printf("--- Results ---\n");

    while (fgets(line, sizeof(line), shadow)) {
        line[strcspn(line, "\n")] = 0;

        char line_copy[512];
        strcpy(line_copy, line);

        char *username = strtok(line_copy, ":");
        char *hash = strtok(NULL, ":");

        char found_password[256] = "";

        if (!username || !hash) {
            continue;
        }

        if (try_dictionary(hash, argv[2], found_password)) {
            printf("%s : %s (dictionary)\n", username, found_password);
        } else if (try_pin(hash, found_password)) {
            printf("%s : %s (brute-force)\n", username, found_password);
        } else {
            printf("%s : [NOT CRACKED]\n", username);
        }
    }

    fclose(shadow);

    return 0;
}