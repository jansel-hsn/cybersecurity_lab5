#include <stdio.h>
#include <string.h>
#include <crypt.h>

void dictionary_attack(const char *target_hash, const char *dict_file) {
    FILE *file = fopen(dict_file, "r");

    if (!file) {
        printf("Error opening dictionary file!\n");
        return;
    }

    char word[256];

    printf("--- Starting Dictionary Attack ---\n");

    while (fgets(word, sizeof(word), file)) {
        word[strcspn(word, "\n")] = 0;

        char *computed_hash = crypt(word, "$6$salt$");

        if (strcmp(computed_hash, target_hash) == 0) {
            printf("[SUCCESS] Password found in dictionary: %s\n", word);
            fclose(file);
            return;
        }
    }

    printf("[FAILED] Password not found in dictionary.\n");
    fclose(file);
}

int main() {
    char target_hash[200];

    strcpy(target_hash, crypt("football", "$6$salt$"));

    dictionary_attack(target_hash, "rockyou_mini.txt");

    return 0;
}