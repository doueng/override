int main()
{
    int i; // 8c
    char b[0x64];

    i = 0;
    fgets(b, 0x64, stdin);
    i = 0;
    while (i < strlen(b))
    {
        // uppercase to lowercase alpha
        if (b[i] > 0x40 && b[i] <= 0x5a)
            b[i] = b[i] ^ 0x20;
        i++;
    }
	printf(b);
	exit(0);
}
