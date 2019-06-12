int main()
{
    char buff[0x20];

    puts("***********************************");
    puts("*            -Level00 -           *");
    puts("***********************************");
    printf("Password:");
    scanf("%d", buff);
    if ((int)buff == 0x149c)
    {
        puts("\nAuthenticated!");
        system("/bin/sh");
        return 0;
    }
    puts("\nInvalid Password!");
    return 1;
}
