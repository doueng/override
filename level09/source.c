#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct info {
    size_t  size;
    char    name[0x28];
    char    msg[0x8c];
};

void secret_backdoor()
{
    char b[0x80];

    fgets(b, 0x80, stdin);
    system(b);
}

void set_msg(struct info *info)
{
    char b[0x400];

    bzero(b, 0x400);
    puts(">: Msg @Unix-Dude");
    printf(">>: ");
    fgets(b, 0x400, stdin);
    strncpy(info->msg, b, info->msg+0xb4);
}

void set_username(struct info *info)
{
    int     i;
    char    b[0x80];

    bzero(b, 0x80);
    puts(">: Enter your username");
    printf(">>: ");
    fgets(b, 0x80, stdin);
    i = 0;
    while (i <= 0x28 && b[i])
    {
        info->name[i] = b[i];
        i++;
    }
    printf(">: Welcome, %s", info->name);
}

void handle_msg()
{
    struct info info;

    bzero(info.name, 0x28);
    info.size = 0x8c;
    set_username(&info);
    set_msg(&info);
    puts(">: Msg sent!");
}

int main()
{
    puts("--------------------------------------------\n|   ~Welcome to l33t-m$n ~    v1337        |\n--------------------------------------------");
    handle_msg();
    return 0;
}
