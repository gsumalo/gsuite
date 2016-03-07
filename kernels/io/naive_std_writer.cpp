/*
 * naive_std.cpp
 *
 *  Created on: 6 de mar. de 2016
 *      Author: jesus
 */

#include "naive_std_writer.hpp"
#include <memory>
#include <boost/filesystem/fstream.hpp>
#include <boost/filesystem/operations.hpp>

namespace kernels {
namespace io {

NaiveStdWriter::NaiveStdWriter()
    : file_(boost::filesystem::unique_path()), size_(0), buffer_size_(0)
{
}

NaiveStdWriter::~NaiveStdWriter()
{
    boost::filesystem::remove(file_);
}

void NaiveStdWriter::run()
{
    // Preparing the buffer
    std::unique_ptr<char[]> buffer;

    if (buffer_size_ > 0) {
        buffer.reset(new char[buffer_size_]);
    }

    // Preparing the file
    boost::filesystem::ofstream file;
    file.rdbuf()->pubsetbuf(buffer.get(), buffer_size_);
    file.exceptions(std::ios::badbit | std::ios::failbit);
    file.open(file_);

    // Real kernel code
    char byte(0);
    for (uint64_t i(0); i < size_; ++i, ++byte) {
        file.write(&byte, sizeof(byte));
    }

    file.close();
}

}}
