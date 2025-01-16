#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>

void signal_handler(int sig) {
    printf("Child process received signal: %d\n", sig);
}

int main() {
    pid_t pid;

    // Fork the process
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process
        signal(SIGUSR1, signal_handler);
        printf("Child process %d waiting for signal...\n", getpid());
        pause(); // Wait for a signal
    } else {
        // Parent process
        sleep(1); // Give the child process time to set up the signal handler
        printf("Parent process sending signal to child process with PID: %d\n", pid);
        kill(pid, SIGUSR1);
        wait(NULL); // Wait for the child process to finish
    }

    return 0;
}
