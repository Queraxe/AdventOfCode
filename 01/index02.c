#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Hilfsfunktion für den Absolutbetrag bei long long
long long llabs_custom(long long n)
{
    return n < 0 ? -n : n;
}

int main(void)
{
    FILE *file = fopen("01/input.txt", "r");
    if (file == NULL)
    {
        perror("Datei konnte nicht geöffnet werden");
        return 1;
    }

    long long dial = 100000000000LL + 50;
    long long counter = 0;

    char line[256];
    while (fgets(line, sizeof(line), file) != NULL)
    {
        char parameter = line[0];

        int rotation = atoi(&line[1]);

        long long old_dial = dial;

        if (parameter == 'R')
        {
            dial += rotation;

            long long old_block = old_dial / 100;
            long long new_block = dial / 100;
            counter += (new_block - old_block);
        }
        else
        {
            dial -= rotation;

            long long old_block = (old_dial - 1) / 100;
            long long new_block = (dial - 1) / 100;
            counter += (old_block - new_block);
        }
    }

    printf("Dezimal-Passwort: %lld\n", counter);
    printf("Hex-Passwort: 0x%llX\n", counter);

    fclose(file);

    return 0;
}