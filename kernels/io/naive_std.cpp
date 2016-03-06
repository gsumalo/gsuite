/*
 * naive_std.cpp
 *
 *  Created on: 6 de mar. de 2016
 *      Author: jesus
 */

#include "naive_std.hpp"
#include <boost/filesystem/fstream.hpp>
#include <boost/filesystem/operations.hpp>

namespace kernels {
namespace io {

NaiveStd::NaiveStd()
    : file_(boost::filesystem::unique_path()), size_(0)
{
}

void NaiveStd::run()
{
    boost::filesystem::ofstream file(file_);

    char byte(0);
    for (uint64_t i(0); i < size_; ++i, ++byte) {
        file.write(&byte, sizeof(byte));
    }
}

}}
