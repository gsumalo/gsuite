/*
 * naive_std.hpp
 *
 *  Created on: 6 de mar. de 2016
 *      Author: jesus
 */

#ifndef KERNELS_IO_NAIVE_STD_WRITER_HPP_
#define KERNELS_IO_NAIVE_STD_WRITER_HPP_

#include <cstdint>
#include <boost/filesystem/path.hpp>

namespace kernels {
namespace io {

class NaiveStdWriter
{
public:
    NaiveStdWriter();
    NaiveStdWriter(const NaiveStdWriter &) = delete;
    NaiveStdWriter(NaiveStdWriter &&) = default;

    NaiveStdWriter & operator=(const NaiveStdWriter &) = delete;
    NaiveStdWriter & operator=(NaiveStdWriter &&) = default;

    void run();

private:
    boost::filesystem::path file_;
    uint64_t size_;
};

}}

#endif /* KERNELS_IO_NAIVE_STD_WRITER_HPP_ */