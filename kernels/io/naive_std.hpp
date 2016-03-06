/*
 * naive_std.hpp
 *
 *  Created on: 6 de mar. de 2016
 *      Author: jesus
 */

#ifndef KERNELS_IO_NAIVE_STD_HPP_
#define KERNELS_IO_NAIVE_STD_HPP_

#include <cstdint>
#include <boost/filesystem/path.hpp>

namespace kernels {
namespace io {

class NaiveStd
{
public:
    NaiveStd();
    NaiveStd(const NaiveStd &) = delete;
    NaiveStd(NaiveStd &&) = default;

    NaiveStd & operator=(const NaiveStd &) = delete;
    NaiveStd & operator=(NaiveStd &&) = default;

    void run();

private:
    boost::filesystem::path file_;
    uint64_t size_;
};

}}

#endif /* KERNELS_IO_NAIVE_STD_HPP_ */
