#include <cstdlib>
#include <iostream>
#include <boost/program_options.hpp>
#include "kernels/io/naive_std_writer.hpp"

int main(int argc, const char * argv[])
{
    int rv(EXIT_SUCCESS);

    const std::string HELP_COMMAND{"help"};

    try {
        boost::program_options::options_description commands_spec("Allowed options");
        commands_spec.add_options()
                (HELP_COMMAND.c_str(), "Show this help");

        boost::program_options::variables_map vm;
        boost::program_options::store(boost::program_options::parse_command_line(argc, argv, commands_spec), vm);
        boost::program_options::notify(vm);

        if (vm.count(HELP_COMMAND)) {
            std::cout << commands_spec << std::endl;
        } else {
            kernels::io::NaiveStdWriter primer;

            primer.run();
        }
    } catch (...) {
        rv = EXIT_FAILURE;
    }

    return rv;
}
