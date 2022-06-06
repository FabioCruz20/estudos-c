#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    int x=1;
    int a[3] = {1,1,1};
    pid = fork();

    if (pid < 0) { //erro
        fprintf(stderr, "Fork falhou!\n");
        return 1;
    }
    else if (pid == 0) { //processo filho
	    printf("Sou o filho (%d) - %d - %d \n", getpid(), x, a[0]); 
      x=2;
	    a[0]=2;
	    printf("Sou o filho (%d) - %d - %d \n", getpid(), x, a[0]); 
    }
    else { //processo pai
        wait(NULL);
        printf("Pai (%d): Filho (%d) terminou! %d - %d\n", getpid(), pid, x, a[0]);
    }
    return 0;
}