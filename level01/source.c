char a_user_name[0x100];

int verify_user_name()
{
    return strncmp("dat_wil", a_user_name, 7);
}

int verify_user_pass(pass)
{
    return strncmp("admin", pass, 5);
}

int main()
{
    int  ret;
    char buff[0x40];

    memset(buff, 0, 0x40);
    puts("********* ADMIN LOGIN PROMPT *********");
    ret = 0;
    printf("Enter Username: ");
    fgets(a_user_name, 0x100, stdin);
    ret = verify_user_name();
    if (ret != 0)
    {
        puts("nope, incorrect username...\n");
        return 1;
    }
    puts("Enter Password: ");
    fgets(buff, 0x64, stdin);
    verify_user_pass(buff);
    if (ret != 0)
    {
        puts("nope, incorrect password...\n");
        return 1;
    }
    return 0;
}
