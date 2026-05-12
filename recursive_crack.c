#include <stdio.h>
#include <string.h>
#include <crypt.h>

const char charset[] = "abcdefghijklmnopqrstuvwxyz0123456789";
const int charset_len = 36;

int is_found = 0;

void generate_recursive(char *current_guess, int position, int max_length, const char *target_hash) {
    if (is_found) return;

    if (position > 0) {
        current_guess[position] = '\0';

        char *computed = crypt(current_guess, "$6$salt$");

        if (strcmp(computed, target_hash) == 0) {
            printf("[SUCCESS] Password cracked: %s\n", current_guess);
            is_found = 1;
            return;
        }
    }

    if (position == max_length) return;

    for (int i = 0; i < charset_len; i++) {
        current_guess[position] = charset[i];
        generate_recursive(current_guess, position + 1, max_length, target_hash);
    }
}

int main() {
    char target_hash[200];
    char buffer[10];

    strcpy(target_hash, crypt("abc", "$6$salt$"));

    printf("--- Starting Recursive Brute-Force ---\n");

    generate_recursive(buffer, 0, 3, target_hash);

    if (!is_found) {
        printf("[FAILED] Password not found.\n");
    }

    return 0;
}