#include <cstdlib>

#include "kernels/io/naive_std_writer.hpp"

int main(int argc, const char * argv[])
{
    int rv(EXIT_SUCCESS);

    try {
        kernels::io::NaiveStdWriter primer;

        primer.run();
    } catch (...) {
        rv = EXIT_FAILURE;
    }

    return rv;
}
