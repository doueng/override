int main()
{
    FILE   *fstream;
    size_t size;
    char user[96];
    char file[40];
    char password[96];

    bzero(a, 96);
    bzero(file, 40);
    bzero(c, 96);
    fstream = fopen("/home/users/level03/.pass", "r");
    if (fstream == NULL)
    {
        fwrite("ERROR: failed to open password file\n", 1, 0x24, stderr);
        exit(1);
    }
    size = fread(file, 1, 0x29, fstream);
    file[strcspn(file, "\n")] = 0;
    if (size != 0x29)
    {
        fwrite("ERROR: failed to open password file\n", 1, 0x24, stderr);
        fwrite("ERROR: failed to open password file\n", 1, 0x24, stderr);
        exit(1);
    }
    fclose(fstream);
    puts("===== [ Secure Access System v1.0 ] =====");
    puts("/***************************************\\");
    puts("| You must login to access this system. |");
    puts("\\**************************************/");
    printf("--[ Username: ");
    fgets(name, 0x64, stdin);
    name[strcspn(name, "\n")] = 0;
    printf("--[ Password: ");
    fgets(password, 0x64, stdin);
    password[strcspn(password, "\n")] = 0;
    puts("*****************************************");
    if (0 == strncmp(file, password, 0x29))
    {
        printf("Greetings, %s!\n", name);
        system("/bin/sh");
        return 0;
    }
    printf(name);
    puts(" does not have access!");
    exit(1);
}
