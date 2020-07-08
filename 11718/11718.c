#include <stdio.h>

int main(void)
{
    char input;

    while(input!=EOF) {
        input = fgetc(stdin);
        if (input==EOF)
            break;
        printf("%c", input);
    }

    return 0;
}