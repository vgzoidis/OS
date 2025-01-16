#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];
    pid_t pid;
    char buffer[30];

    // Create the pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork the process
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process
        close(pipefd[1]); // Close the write end of the pipe
        read(pipefd[0], buffer, sizeof(buffer));
        printf("Child process received message: %s\n", buffer);
        close(pipefd[0]); // Close the read end of the pipe
    } else {
        // Parent process
        close(pipefd[0]); // Close the read end of the pipe
        const char *message = "Hello from parent!";
        write(pipefd[1], message, strlen(message) + 1);
        close(pipefd[1]); // Close the write end of the pipe
        wait(NULL); // Wait for the child process to finish
    }

    return 0;
}
