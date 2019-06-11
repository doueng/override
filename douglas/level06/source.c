#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ptrace.h>
#include <stdlib.h>
#include <stdint.h>

int auth(char *name, uint32_t serial)
{
    int         len;  // 0xc
    uint32_t    hash; // 0x10
    int         i;    // 0x14
    uint32_t    eax;
    uint32_t    edx;

    eax = 0, edx = 0;
    name[strcspn(name, "\n")] = 0;
    len = strnlen(name, 0x20);
    if (len > 5)
    {
        if (-1 == ptrace(0,0,1,0))
        {
            puts("\033[32m.---------------------------.");
            puts("\033[31m| !! TAMPERING DETECTED !!  |");
            puts("\033[32m.---------------------------.");
            return 1;
        }
        hash = (name[3] ^ 0x1337) + 0x5eeded;
        i = 0;
        while (i < len)
        {
            if (name[i] <= 0x1f)
                return 1;
            eax = name[i] ^ hash;
            edx = ((uint64_t)eax * 0x88233b2b) >> 32;
            eax -= edx;
            eax >>= 1;
            eax += edx;
            eax >>= 0xa;
            hash += (name[i] ^ hash) - (eax * 0x539);
            i++;
        }
        printf("serial == %u\n", hash);
        if (hash == serial)
            return 0;
    }
    return 1;
}

int main()
{
    char        name[0x21];
    uint32_t    serial;

    puts("***********************************");
    puts("*               level06           *");
    puts("***********************************");
    printf("-> Enter Login: ");
    fgets(name, 0x20, stdin);
    puts("***********************************");
    puts("***** NEW ACCOUNT DETECTED ********");
    puts("***********************************");
    printf("-> Enter Serial: ");
    scanf("%u", &serial);
    if (0 == auth(name, serial))
    {
        puts("Authenticated!");
        system("/bin/sh");
        return 0;
    }
    return 1;
}
