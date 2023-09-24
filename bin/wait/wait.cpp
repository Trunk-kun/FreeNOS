#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <pid>\n", argv[0]);
        return 1;
    }

    pid_t pid = atoi(argv[1]);
    int status;

    // Wait for the specified process to finish
    if (waitpid(pid, &status, 0) == -1) {
        perror("waitpid");
        return 1;
    }

    // Check if the process exited normally or due to a signal
    if (WIFEXITED(status)) {
        printf("Process %d has exited with status %d\n", pid, WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)) {
        printf("Process %d was terminated by signal %d\n", pid, WTERMSIG(status));
    } else {
        printf("Process %d has an unknown exit status\n", pid);
    }

    return 0;
}
