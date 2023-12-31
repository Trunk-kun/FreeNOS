#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <Process.h>
#include <sys/wait.h>
#include <ProcessManager.h>
#include "Wait.h"

Wait::Wait(int argc, char **argv)
    : POSIXApplication(argc, argv)
{
    parser().setDescription("Suspend the execution until a process specified by pid argument has changed state or finished running");
    parser().registerPositional("PROCESS_ID", "Suspend execution until the given pid process changes state");
}

Wait::~Wait() {}

Wait::Result Wait::exec()
{
    ProcessID arg_id;
    int store_result, success;

    //Look for process with specified PID
    if ((arg_id = atoi(arguments().get("PROCESS_ID"))) <= 3) {
        ERROR("Invalid PID `" << arguments().get("PROCESS_ID") <<"`");
        return InvalidArgument;
    }

    //Found valid process, Wait
    success = waitpid(arg_id, &store_result, 0);

    if(!success)
    {
        ERROR("No process of ID " << arguments().get("PROCESS_ID") << " was found.");
        return TimedOut;
    }

    return Success;
}
