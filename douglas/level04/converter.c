#include <string.h>
#include <stdio.h>

void main()
{
    char    b[100];
    int     new_line;

    printf("Input string: ");
    bzero(b, 100);
    scanf("%99s", b);
    new_line = 0;
    for (int i=strlen(b)-1; i>=0; i--)
    {
        if (new_line % 4 == 0)
            printf("\n0x");
        printf("%x", b[i]);
        new_line++;
    }
    puts("");
}
