#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
    FILE *file = fopen("01/input.txt", "r"); 
    if (file == NULL) {
        perror("Datei konnte nicht geöffnet werden");
        return 1;
    }

    int dial = 50;
    int counter = 0;

    char line[256];
    while (fgets(line, sizeof(line), file) != NULL) {
        char parameter = line[0];
        

        int rotation = atoi(memmove(line, line + 1, strlen(line)));


        if (parameter == 'L')
            dial = (dial - rotation) % 100;
        else
            dial = (dial + rotation) % 100;

        if (dial == 0)
            counter++;
        
    }

    
    printf("%i", counter);

    fclose(file);
    
    return 0;
}