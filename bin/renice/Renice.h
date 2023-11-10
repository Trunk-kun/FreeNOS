#ifndef __BIN_RENICE_RENICE_H
#define __BIN_RENICE_RENICE_H

#include <POSIXApplication.h>

class Renice : public POSIXApplication
{
    public:

    /*Constructor
    @param argc Argument count
    @param argv Argument values*/
    Renice(int argc, char **argv);

    /*Destructor*/
    virtual ~Renice();

    virtual Result exec();
};

#endif