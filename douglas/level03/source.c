#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <string.h>

void decrypt(uint32_t key)
{
    char        *s = "Q}|u`sfg~sf{}|a3";
    uint32_t    len;
    int         i;

    len = strlen(s);
    i = 0;
    while (i < len)
    {
        s[i] ^= key;
        i++;
    }
    (0 == strcmp(s, "Congratulations!"))
        ? system("/bin/sh")
        : puts("\nInvalid Password");
}

void test(uint32_t n, uint32_t cmpn)
{
    if (cmpn - n <= 0x15)
        decrypt(cmpn - n);
}

int main()
{
    int n;

    srand(time(0));
    puts("***********************************");
    puts("*               level03         **");
    puts("***********************************");
    printf("Password:");
    scanf("%d", &n);
    test(n, 0x1337d00d);
    return (0);
}
