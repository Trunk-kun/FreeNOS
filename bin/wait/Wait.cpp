#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <ProcessClient.h>
#include "Wait.h"

Wait::Wait(int argc, char **argv)
    : POSIXApplication(argc, argv)
{
    parser().setDescription("Suspend the execution of the thread until a child specified by pid argument has changed state");
    parser().registerPositional("PROCESS_ID", "Suspend execution until the given pid argument changes state");
}

Wait::~Wait(){}

Wait::Result Wait::exec()
{
    const ProcessClient process;
    ProcessID pid = (atoi(arguments().get("Process_ID")));

    ProcessClient::Info info;
    const ProcessClient::Result result = process.processInfo(pid, info);

    if (result == ProcessClient::Success) {
        waitpid(pid, 0, 0);
    } else {
        ERROR("No process of ID " << arguments().get("PROCESS_ID") << " is found.")
        return InvalidArgument;
    }

    return Success;
}
