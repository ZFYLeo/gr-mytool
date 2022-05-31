/* -*- c++ -*- */
/*
 * Copyright 2022 zfyleo.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_MYTOOL_TIME_ESTIMATE_H
#define INCLUDED_MYTOOL_TIME_ESTIMATE_H

#include <gnuradio/block.h>
#include <gnuradio/mytool/api.h>

namespace gr {
namespace mytool {

/*!
 * \brief <+description of block+>
 * \ingroup mytool
 *
 */
class MYTOOL_API time_estimate : virtual public gr::block
{
public:
    typedef std::shared_ptr<time_estimate> sptr;

    /*!
     * \brief Return a shared_ptr to a new instance of mytool::time_estimate.
     *
     * To avoid accidental use of raw pointers, mytool::time_estimate's
     * constructor is in a private implementation
     * class. mytool::time_estimate::make is the public interface for
     * creating new instances.
     */
    static sptr make(int display_level, std::string time_unit);
};

} // namespace mytool
} // namespace gr

#endif /* INCLUDED_MYTOOL_TIME_ESTIMATE_H */
