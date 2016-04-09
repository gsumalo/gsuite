#include <chrono>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <boost/program_options.hpp>
#include "kernels/io/naive_std_writer.hpp"

int main(int argc, const char * argv[])
{
    int rv{EXIT_SUCCESS};

    const std::string HELP_COMMAND{"help"};
    const std::string KERNEL_COMMAND{"kernel"};
    const std::string KERNEL_IO_NAIVESTDWRITER_SELECTION{"io.naivestdwriter"};
    const std::string KERNEL_IO_NAIVESTDWRITER_SIZE_OPTION{"io.naivestdwriter.size"};
    const std::string KERNEL_IO_NAIVESTDWRITER_BUFFERSIZE_OPTION{"io.naivestdwriter.buffersize"};

    try {
        boost::program_options::options_description commands_spec{"Allowed options"};

        std::string kernel_selection;
        boost::program_options::options_description generic_spec{"Generic commands"};
        generic_spec.add_options()
                (HELP_COMMAND.c_str(), "Show this help")
                (KERNEL_COMMAND.c_str(), boost::program_options::value<std::string>(&kernel_selection),
                        ("Kernel selection (" + KERNEL_IO_NAIVESTDWRITER_SELECTION + ")").c_str());

        uint64_t size, buffer_size;
        boost::program_options::options_description kernels_spec{"Available kernels"};
        kernels_spec.add_options()
                (KERNEL_IO_NAIVESTDWRITER_SIZE_OPTION.c_str(),
                        boost::program_options::value<uint64_t>(&size)->default_value(0), "Size of the generated file");
        kernels_spec.add_options()
                (KERNEL_IO_NAIVESTDWRITER_BUFFERSIZE_OPTION.c_str(),
                        boost::program_options::value<uint64_t>(&buffer_size)->default_value(0), "Size of the buffer");

        commands_spec.add(generic_spec).add(kernels_spec);

        boost::program_options::variables_map vm;
        boost::program_options::store(boost::program_options::parse_command_line(argc, argv, commands_spec), vm);
        boost::program_options::notify(vm);

        if (vm.count(HELP_COMMAND)) {
            std::cout << commands_spec << std::endl;
        } else if (vm.count(KERNEL_COMMAND)) {
            if (kernel_selection == KERNEL_IO_NAIVESTDWRITER_SELECTION) {
                if (vm.count(KERNEL_IO_NAIVESTDWRITER_SIZE_OPTION)
                        && vm.count(KERNEL_IO_NAIVESTDWRITER_BUFFERSIZE_OPTION)) {
                    kernels::io::NaiveStdWriter primer{size, buffer_size};

                    const auto start_time(std::chrono::high_resolution_clock::now());
                    primer.run();
                    const auto stop_time(std::chrono::high_resolution_clock::now());
                    const auto elapsed_time(stop_time - start_time);


                    // split into hours, minutes, seconds, and milliseconds
                    const auto hh(std::chrono::duration_cast<std::chrono::hours>(elapsed_time));
                    const auto mm(std::chrono::duration_cast<std::chrono::minutes>(elapsed_time % std::chrono::hours(1)));
                    const auto ss(std::chrono::duration_cast<std::chrono::seconds>(elapsed_time % std::chrono::minutes(1)));
                    const auto msec(std::chrono::duration_cast<std::chrono::milliseconds>(elapsed_time % std::chrono::seconds(1)));

                    std::cout << std::setfill('0') << std::setw(2) << hh.count() << ":" << std::setw(2) << mm.count()
                            << ":" << std::setw(2) << ss.count() << "." << std::setw(3) << msec.count() << std::endl;
                } else {
                    throw std::runtime_error("Missing arguments");
                }
            } else {
                throw std::runtime_error("Unknown kernel: " + kernel_selection);
            }
        } else {
            throw std::runtime_error("No kernel specification was found.");
        }
    } catch (const std::exception & e) {
        std::cerr << "Exception found: " << e.what() << std::endl;
        rv = EXIT_FAILURE;
    } catch (...) {
        std::cerr << "Unknown exception was thrown" << std::endl;
        rv = EXIT_FAILURE;
    }

    return rv;
}
