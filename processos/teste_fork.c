#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid;
    pid = fork();

    if (pid < 0) { //erro
        fprintf(stderr, "Fork falhou!\n");
        return 1;
    }
    else if (pid == 0) { //processo filho
        execlp("/bin/ls", "ls", NULL);
    }
    else { //processo pai
        wait(NULL);
        printf("Filho terminou!\n");
    }
    return 0;
}