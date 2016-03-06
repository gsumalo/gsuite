#include <cstdlib>
#include "kernels/io/naive_std.hpp"

int main(int argc, const char * argv[])
{
    int rv(EXIT_SUCCESS);

    try {
        kernels::io::NaiveStd primer;

        primer.run();
    } catch (...) {
        rv = EXIT_FAILURE;
    }

    return rv;
}
