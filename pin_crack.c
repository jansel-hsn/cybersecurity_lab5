#include <stdio.h>
#include <string.h>
#include <crypt.h>

void crack_pin(const char *target_hash) {

    char guess[5];

    printf("--- Starting PIN Brute-Force ---\n");

    for (int i = 0; i <= 9999; i++) {

        sprintf(guess, "%04d", i);

        char *computed_hash = crypt(guess, "$6$salt$");

        if (strcmp(computed_hash, target_hash) == 0) {

            printf("[SUCCESS] Password is: %s\n", guess);
            return;
        }
    }

    printf("[FAILED] Password is not a 4-digit PIN.\n");
}

int main() {

    char target_hash[200];

    strcpy(target_hash, crypt("1234", "$6$salt$"));

    crack_pin(target_hash);

    return 0;
}