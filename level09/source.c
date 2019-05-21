void secret_backdoor()
{
    char b[0x80];

    fgets(b, 0x80, stdin);
    system(b);
}

void set_msg(char *arg)
{
    char b[0x400];

    bzero(b, 0x400);
    puts(">: Msg @Unix-Dude");
    printf(">>: ");
    strncpy(arg, b, fgets(b, 0x400, stdin));

}

void set_username()
{
    int     i;
    char    b[0x80];

    puts(">: Enter your username");
    printf(">>: ");
    fgets(b, 0x80, stdin);
    i = 0;
    while (i < 0x28)
    {
        i++;
    }
    printf(">: Welcome, %s", %b);
}

void handle_msg()
{
    int     n;
    char    name[0x28];
    char    msg[0x8c];

    bzero(b, 0x28);
    n = 0x8c;
    set_username(name);
    set_msg(msg);
    puts(">: Msg sent!");
}

int main()
{
    puts("--------------------------------------------\n|   ~Welcome to l33t-m$n ~    v1337        |\n--------------------------------------------");
    handle_msg();
    return 0;
}
