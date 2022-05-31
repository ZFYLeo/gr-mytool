/* -*- c++ -*- */
/*
 * Copyright 2022 zfyleo.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "time_estimate_impl.h"
#include <gnuradio/io_signature.h>
#include <time.h>
namespace gr {
namespace mytool {


using input_type = float;
using output_type = float;
  time_estimate::sptr time_estimate::make(int display_level, std::string time_unit)
  {
    return gnuradio::make_block_sptr<time_estimate_impl>(display_level,time_unit);
  }


/*
 * The private constructor
 */
  time_estimate_impl::time_estimate_impl(int display_level, std::string time_unit)
  : gr::block("time_estimate",
              gr::io_signature::make(0,0,0),
              gr::io_signature::make(0,0,0)),
  d_display_level(display_level),
  d_time_unit(time_unit)
  {
    if(d_time_unit.compare("s") == 0)
    {
      d_count_per_second = 1000000;
    }
    else if(d_time_unit.compare("ms") == 0)
    {
      d_count_per_second = 1000;
    }
    else if(d_time_unit.compare("us") == 0)
    {
      d_count_per_second = 1;
    }
    message_port_register_in(pmt::mp("time_start"));
    message_port_register_in(pmt::mp("time_end"));
    set_msg_handler(pmt::mp("time_start"),
      [this](const pmt::pmt_t& msg){record_start_time(msg);});
    set_msg_handler(pmt::mp("time_end"),
      [this](const pmt::pmt_t& msg){record_end_time(msg);});
  }

  void
  time_estimate_impl::record_start_time(const pmt::pmt_t& msg)
  {
    if(d_start==-1)
    {
      d_start = std::clock();
    }
  }

  void
  time_estimate_impl::record_end_time(const pmt::pmt_t& msg)
  {
    if(d_start!=-1)
    {
      d_end = std::clock();
      std::cout<<"block::time_estimate: time used-> "<<(double)(d_end-d_start)/d_count_per_second<<" "<<d_time_unit<<std::endl;
      d_start = -1;
    }
  }

  /*
   * Our virtual destructor.
   */
  time_estimate_impl::~time_estimate_impl() {}

} /* namespace mytool */
} /* namespace gr */
