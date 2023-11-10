#include "sys/renice.h"
#include <Macros.h>
#include <stdio.h>
#include <unistd.h>
#include "Renice.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ProcessClient.h>

Renice::Renice(int argc, char **argv)
    :POSIXApplication(argc, argv)
{
    parser().setDescription("Changes the priority of a given process");
    parser().registerPositional("PROCESS_ID", "change the priority of a given process");
}

Renice::Result Renice::exec()
{
    // ToDo
}
