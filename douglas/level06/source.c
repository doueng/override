#include <string.h>
#include <stdio.h>
#include <sys/ptrace.h>
#include <stdlib.h>
#include <stdint.h>

int auth(char *name, uint32_t serial)
{
    int         len;  // 0xc
    uint32_t    hash; // 0x10
    int         i;    // 0x14

    uint32_t    eax;
    uint32_t    ecx;
    uint32_t    edx;
    uint64_t    edxeax;
    int64_t     iedxeax;

    eax, edx, edxeax, iedxeax = 0;
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
            eax = name[i];
            ecx = eax ^ hash;
            edx = 0x88233b2b;
            eax = ecx;
            edxeax = (uint64_t)eax * (uint64_t)edx;
            edx = edxeax >> 32;
            eax = ecx;
            eax = ecx;
            eax -= edx;
            eax >>= 1;
            eax += edx;
            eax >>= 0xa;
            iedxeax = (int64_t)eax * (int64_t)0x539;
            eax = iedxeax & 0x00000000ffffffff;
            edx = ecx;
            edx -= eax;
            eax = edx;
            hash += eax;
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
