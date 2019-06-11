#include <stdio.h>
#include <stdint.h>
#include <string.h>

void clear_stdin()
{
    char c;

    c = 0;
    while (0xa != (c = getchar()))
    {
        if (c == -1)
            break ;
    }
}

uint32_t get_unum()
{
    uint32_t n;

    n = 0;
    fflush(stdout);
    scanf("%u", &n);
    clear_stdin();
    return n;
}

int store_number(char *buff)
{
    uint32_t index;
    uint32_t num;

    index = 0;
    num = 0;
    printf(" Number: ");
    num = get_unum();
    printf(" Index: ");
    index = get_unum();
    if ((index % 3 == 0) || 0xb7 == (num >> 0x18))
    {
        puts(" *** ERROR! ***");
        puts("   This index is reserved for wil!");
        puts(" *** ERROR! ***");
        return 1;
    }
    buff[index << 2] = num;
    return 0;
}

int read_number(char *buff)
{
    uint32_t index;

    printf(" Index: ");
    index = get_unum();
    index <<= 2;
    printf(" Number at data[%u] is %u\n", index, buff[index]);
    return 0;
}

int main(int argc, char *argv[])
{
    int ret; //1b4
    char in1[0x14]; //1b8
    /*int c; //1bc*/
    /*int d; //1c0*/
    /*int e; //1c4*/
    char    buff[0x64*4];   // 24
    char *prog_name;        // 1c
    char *arg1;             // 18

    (void)argc;
    prog_name = *argv;
    arg1 = argv[1];
    ret = 0;
        /*c = 0, d = 0, e = 0;*/
    bzero(buff, 0x64*4);
    memset(prog_name, 0, strlen(prog_name));
    memset(arg1, 0, strlen(arg1));
    puts("----------------------------------------------------\nWelcome to wil's crappy number storage service!\n----------------------------------------------------\n Commands:\n\tstore - store a number into the data storage\n\tread  - read a number from the data storage\n\tquit  - exit the program\n----------------------------------------------------\n\twil has reserved some storage :>\n----------------------------------------------------\n");
    while (1)
    {
        printf("Input command: ");
        ret = 1;
        fgets(in1, 0x14, stdin);
        if (0 == strncmp(in1, "store", 5))
            ret = store_number(buff);
        else if (0 == strncmp(in1, "read", 5))
            ret = read_number(buff);
        else if (0 == strncmp(in1, "quit", 4))
            return 0;
        if (ret != 0)
        {
            printf(" Failed to do %s command\n", in1);
            bzero(in1, 0x14);
        }
    }
}

