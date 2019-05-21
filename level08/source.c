#include <stdio.h>

int log_wrapper(FILE *logfile, char *msg, char *arg1)
{
    char buff[0x110];

    // logfile  118
    // msg      120
    // arg1     128

    strcpy(buff, msg);
    snprintf(buff+strlen(buff), strlen(arg1), arg1);
    buff[strcspn(buff, "\n")] = 0;
    fprintf(logfile, "LOG: %s\n", buff);
    return 0;
}

int main(int argc, char *argv[])
{
    char backup_name[0x63];
    char c          // 71
    int  fd;        // 78
    FILE *file;     // 80
    FILE *logfile;   // 88

    printf("Usage: %s filename\n", argv[1]);
    if (0 != (logfile = fopen("./backups/.log", "w")))
    {
        printf("ERROR: Failed to open %s\n",  "./backups/.log");
        exit(1);
    }
    log_wrapper(logfile, "Starting back up: ", argv[1]);
    if (0 != (file = fopen(argv[1], "r")))
    {
        printf("ERROR: Failed to open %s\n", argv[1]);
        exit(1);
    }
    strncat(backup_name, argv[1], 0x63 - strlen(argv[1]));
    if (0 != (fd = open(backup_name, O_WRONLY|O_EXCL|O_CREAT, 0x1b0)))
    {
        printf("ERROR: Failed to open %s%s\n",  "./backups/", argv[1]);
        exit(1);
    }
    while (-1 != (c = fgetc(file)))
        write(fd, c, 1);
    log_wrapper(logfile, "Finished back up ", argv[1]);
    fclose(file);
    close(fd);
}
