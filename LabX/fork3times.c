#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    for (int i = 0; i < 3; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            // Child process
            printf("Child process with PID: %d\n", getpid());
            // Exit to prevent further forking by child processes
            return 0;
        } else if (pid > 0) {
            // Parent process
            printf("Parent process with PID: %d created a child with PID: %d\n", getpid(), pid);
        } else {
            // Fork failed
            perror("fork");
            return 1;
        }
    }
    // Wait for all child processes to finish
    for (int i = 0; i < 3; i++) {
        wait(NULL);
    }
    return 0;
}
