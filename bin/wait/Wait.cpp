#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <cstdlib>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <pid>" << std::endl;
        return 1;
    }

    // Convert the provided PID argument to an integer
    int pid = std::atoi(argv[1]);

    // Use waitpid to wait for the specified process to finish
    int status;
    int result = waitpid(pid, &status, 0);

    if (result == -1) {
        perror("waitpid");
        return 1;
    }

    if (WIFEXITED(status)) {
        int exit_status = WEXITSTATUS(status);
        std::cout << "Process " << pid << " has exited with status " << exit_status << std::endl;
    } else if (WIFSIGNALED(status)) {
        int term_signal = WTERMSIG(status);
        std::cout << "Process " << pid << " terminated by signal " << term_signal << std::endl;
    } else {
        std::cerr << "Process " << pid << " encountered an unknown status" << std::endl;
    }

    return 0;
}
