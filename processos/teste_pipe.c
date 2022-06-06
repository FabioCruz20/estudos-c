#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

//#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main(void)
{
	int fd[2];
	pid_t pid;
	//char write_msg[BUFFER_SIZE] ="Greetings";
	//char read_msg[BUFFER_SIZE];

	/*cria o pipe*/
	if (pipe(fd) == -1){
		fprintf(stderr, "Pipe Falhou!\n");
		return 1;
	}
	
	/*criação do filho*/
	pid = fork();

	if (pid < 0) {// erro
		fprintf(stderr, "Fork falhou!\n");
		return 1;
	}

	if (pid > 0) { // Pai
		//não preciso do READ END
		close(fd[READ_END]);
		
		//grava no pipe
		//write(fd[WRITE_END], write_msg, strlen(write_msg)+1);
		FILE * stream;
		stream = fdopen(fd[WRITE_END], "w");
		fprintf(stream, "Oi!!!\n");
		fprintf(stream, "Mensagem do processo Pai - pid %d\n", getpid());
		// fecha o WRITE END
		fclose(stream);
		close(fd[WRITE_END]);
	}
	else { // Filho
		//não preciso do WRITE END
		close(fd[WRITE_END]);
		
		//lê do pipe
		FILE * stream;
		char c;
		stream = fdopen(fd[READ_END], "r");
		while ((c = fgetc (stream)) != EOF)
      putchar (c);
		//read(fd[READ_END], read_msg, BUFFER_SIZE);
		//printf("string recebida: %s", read_msg);

		// fecha o READ END
		fclose(stream);
		close(fd[READ_END]);
	}
	return 0;
}