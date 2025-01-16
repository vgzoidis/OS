#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    FILE *file;
    pid_t pid;

    // Open the file for writing
    file = fopen("PIDs.txt", "w");
    if (file == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    // Fork the process
    pid = fork();
    if (pid == -1) {
        perror("fork");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process
        fprintf(file, "Child process PID: %d\n", getpid());
    } else {
        // Parent process
        fprintf(file, "Parent process PID: %d\n", getpid());
        wait(NULL); // Wait for the child process to finish
    }

    // Close the file
    fclose(file);

    return 0;
}
