/*
clear_stdin
get_unum
prog_timeout
decrypt
test
main
*/

void clear_stdin()
{
    char n;

    n = 0;
    while ('\n' != (n = getchar()))
        if (n == -1)
            break;
}

uint32_t get_unum()
{
    uint32_t unum;

    unum = 0;
    fflush(stdin);
    scanf("%u", unum);
    clear_stdin();
    return unum;
}

int prog_timeout()
{
    exit(1);
}

int decryt(uint32_t n)
{
    void    *p = 0;
    uint32_t a = 0x33617c7d; // 11
    uint32_t b = 0x7b66737e; // 15
    uint32_t c = 0x67667360; // 19
    uint32_t d = 0x757c7d51; // 1d
    uint32_t len = 0;
    int      i = 0
    char s[16];

    *(uint32_t*)s = a;
    *(uint32_t*)s+4 = b;
    *(uint32_t*)s+8 = c;
    *(uint32_t*)s+16 = d;

    len = 16; // len of a+b+c+d
    while (i < len)
    {
    }
}

int test(uint32_t n, uint32_t cmpn)
{
    uint32_t nn;

    nn = cmpn - n;
    if (nn <= 0x15)
    {
        nn = nn << 2;
        nn += 0x80489f0;
        decrypt(nn);
        // jmp to *nn
    }
}

int main()
{
    uint32_t n;

    srand(time(0));
    puts("***********************************");
    puts("*               level03         **");
    puts("***********************************");
    printf("Password:");
    scanf("%u", n);
    test(n, 0x1337d00d);
}
