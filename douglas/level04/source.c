int main()
{
    int pid;        // ac
    int syscall;    // a8
    int *stat_loc;  // b0
    char b[0x80];   // 1c

    pid = fork();
    bzero(b, 0x80);
    syscall = 0;
    *stat_loc = 0;
    if (pid == 0)
    {
        prctl(PR_SET_PDEATHSIG, SIGHUP);
        ptrace(PTRACE_TRACEME,0,0,0);
        puts("Give me some shellcode, k");
        gets(b);
    }
    else
    {
        while (syscall != 0xb)
        {
            wait(stat_loc);
            if (!WTERMSIG(*stat_loc) || !WIFSTOPPED(*stat_loc))
            {
                puts("child is exiting...");
                return 0;
            }
            syscall = ptrace(PTRACE_PEEKUSR, pid, 0x2c, 0);
        }
        puts("no exec() for you");
        kill(pid, 9);
    }
    return 0;
}
