/* -*- c++ -*- */
/*
 * Copyright 2022 zfyleo.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_MYTOOL_TIME_ESTIMATE_IMPL_H
#define INCLUDED_MYTOOL_TIME_ESTIMATE_IMPL_H

#include <gnuradio/mytool/time_estimate.h>

namespace gr {
namespace mytool {

class time_estimate_impl : public time_estimate
{
private:
    // Nothing to declare in this block.
    int d_display_level;
    std::string d_time_unit;
    std::clock_t d_start=-1;
    std::clock_t d_end;
    int d_count_per_second = 1000000;

    void record_start_time(const pmt::pmt_t& msg);
    void record_end_time(const pmt::pmt_t& msg);

public:
    time_estimate_impl(int display_level, std::string time_unit);
    ~time_estimate_impl();

};

} // namespace mytool
} // namespace gr

#endif /* INCLUDED_MYTOOL_TIME_ESTIMATE_IMPL_H */
